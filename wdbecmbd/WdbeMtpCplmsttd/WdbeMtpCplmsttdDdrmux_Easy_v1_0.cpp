/**
	* \file WdbeMtpCplmsttdDdrmux_Easy_v1_0.cpp
	* Wdbe operation processor - infer PHY (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Oct 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmsttdDdrmux_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmsttd;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmsttdDdrmux_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmsttdDdrmux_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmsttd* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	string srefKVendor;

	ubigint refMtp;

	bool phyNotAxi;

	bool memclkIntNotExt;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		srefKVendor = Wdbe::getUntVendor(dbswdbe, mdl->hkUref);

		phyNotAxi = false;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "phyNotAxi", s)) phyNotAxi = (s == "true");

		if (phyNotAxi) {
			refMtp = 0;
			if (srefKVendor == "xlnx") refMtp = Wdbe::getRefMtp(dbswdbe, "mig_xlnx_v4_2_ddr");

			if (refMtp != 0) {
				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

				dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::OTH, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum + 1, mdl->ref, refMtp, 0, 0, "phy", "", "", "");
			};
		};

		memclkIntNotExt = false;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "memclkIntNotExt", s)) memclkIntNotExt = (s == "true");

		if (memclkIntNotExt) {
			refMtp = 0;
			if (srefKVendor == "xlnx") refMtp = Wdbe::getRefMtp(dbswdbe, "mmcm_xlnx_v5_4");

			if (refMtp != 0) {
				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

				dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::OTH, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum + 1, mdl->ref, refMtp, 0, 0, "mmcmMemclk", "", "", "");
			};
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
