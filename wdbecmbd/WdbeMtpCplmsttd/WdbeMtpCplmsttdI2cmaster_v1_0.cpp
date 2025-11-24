/**
	* \file WdbeMtpCplmsttdI2cmaster_v1_0.cpp
	* Wdbe operation processor - infer tristate primitives (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 23 Nov 2025
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmsttdI2cmaster_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmsttd;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmsttdI2cmaster_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmsttdI2cmaster_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmsttd* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	bool threeNotInout;

	string srefKVendor;

	string srefTplIobuf;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		Wdbe::getMpa(dbswdbe, refWdbeMModule, "threeNotInout", s);
		threeNotInout = (s == "true");

		if (!threeNotInout) {
			srefKVendor = Wdbe::getUntVendor(dbswdbe, mdl->hkUref);

			if (srefKVendor == "lttc") srefTplIobuf = "BB";
			else if (srefKVendor == "mchp") srefTplIobuf = "BIBUF";
			else if (srefKVendor == "xlnx") srefTplIobuf = "IOBUF";

			if (srefTplIobuf != "") {
				dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum + 1, refWdbeMModule, Wdbe::getRefMtp(dbswdbe, srefTplIobuf), 0, 0, StrMod::lc(srefTplIobuf) + "Scl", "", "", "");
				dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum + 1, refWdbeMModule, Wdbe::getRefMtp(dbswdbe, srefTplIobuf), 0, 0, StrMod::lc(srefTplIobuf) + "Sda", "", "", "");
			};
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
