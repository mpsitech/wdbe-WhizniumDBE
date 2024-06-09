/**
	* \file WdbeMtpCplmstbuSpram_efnx_v1_0.cpp
	* Wdbe operation processor - connect buffer primitives (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Apr 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuSpram_efnx_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuSpram_efnx_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuSpram_efnx_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	// stripped down copy from WdbeMtpCplmstbuDpram_efnx_v1_0

	ubigint ref;

	ListWdbeMModule mdls;
	WdbeMModule* mdl = NULL;

	string suffix;
	unsigned int i, j;

	string range;

	string s;
	size_t ptr;

	bool a_sig;

	dbswdbe->tblwdbemmodule->loadRstBySQL("SELECT * FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref LIKE 'ram_%'", false, mdls);
	a_sig = dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMSignal WHERE refIxVTbl = " + to_string(VecWdbeVMSignalRefTbl::MDL) + " AND refUref = " + to_string(refWdbeMModule) + " AND sref = 'a_sig'", ref);

	for (unsigned int m = 0; m < mdls.nodes.size(); m++) {
		mdl = mdls.nodes[m];

		suffix = mdl->sref.substr(3);

		i = 0;
		j = 0;

		ptr = suffix.find("i");
		if (ptr != string::npos) i = atoi(suffix.substr(ptr + 1).c_str());

		ptr = suffix.find("j");
		if (ptr != string::npos) j = atoi(suffix.substr(ptr + 1).c_str());

		Wdbe::setPrtDfv(dbswdbe, mdl->ref, "RST", "reset");

		Wdbe::setPrtCpr(dbswdbe, mdl->ref, "RCLK", "clk");

		Wdbe::setPrtCsi(dbswdbe, mdl->ref, "RE", "RE_i" + to_string(i));

		if (a_sig) Wdbe::setPrtCsi(dbswdbe, mdl->ref, "RADDR", "a_sig[0..9]");
		else Wdbe::setPrtCpr(dbswdbe, mdl->ref, "RADDR", "a[0..9]");

		Wdbe::setPrtDfv(dbswdbe, mdl->ref, "RADDREN", "1");

		Wdbe::setPrtCsi(dbswdbe, mdl->ref, "RDATA", "drd" + suffix);

		Wdbe::setPrtCpr(dbswdbe, mdl->ref, "WCLK", "clk");
		Wdbe::setPrtDfv(dbswdbe, mdl->ref, "WCLKE", "1");

		Wdbe::setPrtCsi(dbswdbe, mdl->ref, "WE", "WE_i" + to_string(i));

		if (a_sig) Wdbe::setPrtCsi(dbswdbe, mdl->ref, "WADDR", "a_sig[0..9]");
		else Wdbe::setPrtCpr(dbswdbe, mdl->ref, "WADDR", "a[0..9]");

		Wdbe::setPrtDfv(dbswdbe, mdl->ref, "WADDREN", "1");

		range = "[" + to_string(8*j) + ".." + to_string(8*(j+1)-1) + "]";
		Wdbe::setPrtCpr(dbswdbe, mdl->ref, "WDATA", "dwr" + range);
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
