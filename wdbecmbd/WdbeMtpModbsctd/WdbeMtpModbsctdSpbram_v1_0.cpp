/**
	* \file WdbeMtpModbsctdSpbram_v1_0.cpp
	* Wdbe operation processor - infer BRAM primitives and adapt port widths (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpModbsctdSpbram_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModbsctd;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpModbsctdSpbram_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModbsctdSpbram_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModbsctd* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	WdbeMModule* submdl = NULL;

	string size;
	unsigned int N;
	usmallint w;

	string d9NotD8;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "size", size)) {
			N = atoi(size.c_str()) / 2;
			w = Wdbe::valToWidth(N*2048-1);

			if (N > 1) {
				if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'bram'", &submdl)) {
					// rename single default sub
					submdl->sref = "bram0";
					dbswdbe->tblwdbemmodule->updateRec(submdl);

					// infer additional BRAM primitives
					dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + " + to_string(N-1) + " WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(submdl->hkNum));

					for (unsigned int i=1;i<N;i++)
								dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum+i+1, mdl->ref, submdl->tplRefWdbeMModule, 0, 0, "bram" + to_string(i), "");

					// adapt port width
					Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "a", w);

					delete submdl;
				};
			};
		};

		Wdbe::getMpa(dbswdbe, refWdbeMModule, "d9NotD8", d9NotD8);
		if (d9NotD8 == "true") {
			// adapt data port widths
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "drd", 9);
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "dwr", 9);
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
