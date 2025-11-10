/**
	* \file WdbeMtpCplmstbuAximmcohostif_Easy_v1_0.cpp
	* Wdbe operation processor - adapt port widths (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 3 Mar 2025
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuAximmcohostif_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuAximmcohostif_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuAximmcohostif_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string s;

	int wA, wD;

	wA = 32;
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wA", s)) wA = atoi(s.c_str());

	Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "AXIL_araddr", wA);
	Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "AXIL_awaddr", wA);

	wD = 32;
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wD", s)) wD = atoi(s.c_str());

	Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "AXIL_rdata", wD);
	Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "AXIL_wdata", wD);
	Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "AXIL_wstrb", wD/8);
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
