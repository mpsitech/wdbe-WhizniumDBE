/**
	* \file WdbeMtpCplmsttdSpbram_v1_0.cpp
	* Wdbe operation processor - infer buffer (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 19 Oct 2025
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmsttdSpbram_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmsttd;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmsttdSpbram_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmsttdSpbram_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmsttd* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	string size, w;

	ubigint refMtp, refSubmdl;

	string srefKVendor;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "size", size))
			if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "w", w)) {
				srefKVendor = Wdbe::getUntVendor(dbswdbe, mdl->hkUref);

				refMtp = 0;

				if (srefKVendor == "efnx") refMtp = Wdbe::getRefMtp(dbswdbe, "spbram_efnx_v6_1");
				else if (srefKVendor == "lttc") refMtp = Wdbe::getRefMtp(dbswdbe, "spebram_lttc_v1_4");
				else if (srefKVendor == "mchp") refMtp = Wdbe::getRefMtp(dbswdbe, "tpsram_mchp_v1_1_108");
				else if (srefKVendor == "xlnx") refMtp = Wdbe::getRefMtp(dbswdbe, "spbram_xlnx_v8_4");

				if (refMtp != 0) {
					refSubmdl = dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::OTH, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum + 1, mdl->ref, refMtp, 0, 0, "mnfcore", "", "", "");

					Wdbe::setMpa(dbswdbe, refSubmdl, "size", size);
					Wdbe::setMpa(dbswdbe, refSubmdl, "w", w);
				};
			};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
