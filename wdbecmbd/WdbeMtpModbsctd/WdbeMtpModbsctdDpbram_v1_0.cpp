/**
	* \file WdbeMtpModbsctdDpbram_v1_0.cpp
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

#include "WdbeMtpModbsctdDpbram_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModbsctd;

/******************************************************************************
 namespace WdbeMtpModbsctdDpbram_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModbsctdDpbram_v1_0::run(
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

	string dir, rwa, rwb;
	string Defval;

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

					for (unsigned int i = 1; i < N; i++)
								dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum+i+1, mdl->ref, submdl->tplRefWdbeMModule, 0, 0, "bram" + to_string(i), "");

					// adapt port widths
					Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "aA", w);
					Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "aB", w);

					delete submdl;
				};
			};
		};

		Wdbe::getMpa(dbswdbe, refWdbeMModule, "d9NotD8", d9NotD8);
		if (d9NotD8 == "true") {
			// adapt data port widths
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "drdA", 9);
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "dwrA", 9);

			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "drdB", 9);
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "dwrB", 9);
		};

		// set port default values according to dir/rwa/rwb parameters
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "dir", dir)) {
			Wdbe::getMpa(dbswdbe, refWdbeMModule, "rwa", rwa);
			if (rwa != "true") rwa = "false";

			Wdbe::getMpa(dbswdbe, refWdbeMModule, "rwb", rwb);
			if (rwb != "true") rwb = "false";

			// weA
			if (dir == "atob") Defval = "1"; else Defval = "0";
			if (rwa == "false") Wdbe::setPrtDfv(dbswdbe, refWdbeMModule, "weA", Defval);
		
			// dwrA
			if ((dir == "btoa") && (rwa == "false")) Wdbe::setPrtDfv(dbswdbe, refWdbeMModule, "dwrA", "0");

			// weB
			if (dir == "atob") Defval = "0"; else Defval = "1";
			if (rwb == "false") Wdbe::setPrtDfv(dbswdbe, refWdbeMModule, "weB", Defval);

			// dwrB
			if ((dir == "atob") && (rwb == "false")) Wdbe::setPrtDfv(dbswdbe, refWdbeMModule, "dwrB", "0");
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT



