/**
	* \file WdbeMtpCplmsttdDpbram_v1_0.cpp
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

#include "WdbeMtpCplmsttdDpbram_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmsttd;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmsttdDpbram_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmsttdDpbram_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmsttd* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	string size, wA, wB;

	ubigint refMtp, refSubmdl;

	string srefKVendor;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "size", size))
			if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wA", wA))
				if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wB", wB)) {
					srefKVendor = Wdbe::getUntVendor(dbswdbe, mdl->hkUref);

					refMtp = 0;

					if (srefKVendor == "efnx") refMtp = Wdbe::getRefMtp(dbswdbe, "dpbram_efnx_v6_1");
					else if (srefKVendor == "lttc") refMtp = Wdbe::getRefMtp(dbswdbe, "dpebram_lttc_v1_2");
					else if (srefKVendor == "mchp") refMtp = Wdbe::getRefMtp(dbswdbe, "dpsram_mchp_v1_1_110");
					else if (srefKVendor == "xlnx") refMtp = Wdbe::getRefMtp(dbswdbe, "dpbram_xlnx_v8_4");

					if (refMtp != 0) {
						refSubmdl = dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::OTH, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum + 1, mdl->ref, refMtp, 0, 0, "mnfcore", "", "", "");

						Wdbe::setMpa(dbswdbe, refSubmdl, "size", size);
						Wdbe::setMpa(dbswdbe, refSubmdl, "wA", wA);
						Wdbe::setMpa(dbswdbe, refSubmdl, "wB", wB);
					};
				};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
