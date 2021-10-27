/**
	* \file WdbeMtpCplmstbuSpbram_v1_0.cpp
	* Wdbe operation processor - adapt internal wiring (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuSpbram_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuSpbram_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuSpbram_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	unsigned int wD;
	string range;

	ubigint refPrtCEn;
	ubigint refPrtCDrd;

	ListWdbeMModule mdls;
	WdbeMModule* mdl = NULL;

	string suffix;

	string s;

	Wdbe::getMpa(dbswdbe, refWdbeMModule, "d9NotD8", s);
	if (s == "true") wD = 9; else wD = 8;
	if (wD == 9) range = "[0..7]";

	dbswdbe->tblwdbemmodule->loadRstBySQL("SELECT * FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref LIKE 'bram%' ORDER BY hkNum ASC", false, mdls);

	if (mdls.nodes.size() > 1) {
		refPrtCEn = dbswdbe->tblwdbecsignal->getNewRef();
		refPrtCDrd = dbswdbe->tblwdbecsignal->getNewRef();
	};

	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];

		suffix = mdl->sref.substr(4);

		if (mdls.nodes.size() > 1) {
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refPrtCDrd, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdls.nodes.size() + (i+1), VecWdbeVMSignalMgeTbl::VOID, 0, 0, "drd" + suffix, false, "slvdn", wD, "", "", "", "0", false, 0, "");
			Wdbe::setPrtCsi(dbswdbe, mdl->ref, "DO", "drd" + suffix + range);

			if (wD == 9) Wdbe::setPrtCsi(dbswdbe, mdl->ref, "DOP", "drd" + suffix + "[8..8]");

		} else {
			Wdbe::setPrtCpr(dbswdbe, mdl->ref, "DO", "drd" + range);
			if (wD == 9) Wdbe::setPrtCpr(dbswdbe, mdl->ref, "DOP", "drd[8..8]");
		};

		if (mdls.nodes.size() > 1) {
			Wdbe::setPrtCpr(dbswdbe, mdl->ref, "ADDR", "a[0..10]");
		} else {
			Wdbe::setPrtCpr(dbswdbe, mdl->ref, "ADDR", "a");
		};

		Wdbe::setPrtCpr(dbswdbe, mdl->ref, "CLK", "clk");

		Wdbe::setPrtCpr(dbswdbe, mdl->ref, "DI", "dwr" + range);

		if (wD == 8) Wdbe::setPrtDfv(dbswdbe, mdl->ref, "DIP", "0");
		else Wdbe::setPrtCpr(dbswdbe, mdl->ref, "DIP", "dwr[8..8]");

		if (mdls.nodes.size() > 1) {
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refPrtCEn, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, i+1, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "en" + suffix, false, "sl", 1, "", "", "", "0", false, 0, "");
			Wdbe::setPrtCsi(dbswdbe, mdl->ref, "EN", "en" + suffix);
		} else {
			Wdbe::setPrtCpr(dbswdbe, mdl->ref, "EN", "en");
		};

		Wdbe::setPrtDfv(dbswdbe, mdl->ref, "SSR", "0");
		Wdbe::setPrtCpr(dbswdbe, mdl->ref, "WE", "we");
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
