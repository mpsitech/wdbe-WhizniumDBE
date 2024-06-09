/**
	* \file WdbeMtpCplmstbuCmult_xlnx_v6_0.cpp
	* Wdbe operation processor - adapt port widths (implementation)
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

#include "WdbeMtpCplmstbuCmult_xlnx_v6_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuCmult_xlnx_v6_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuCmult_xlnx_v6_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string s;

	int w;

	string wFcta, wFctb, wProd;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wFcta", s)) {
		w = atoi(s.c_str());
		if ((w%8) != 0) w = 8 * (w/8 + 1);

		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "s_axis_a_tdata", 2 * w);
	};
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wFctb", s)) {
		w = atoi(s.c_str());
		if ((w%8) != 0) w = 8 * (w/8 + 1);

		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "s_axis_b_tdata", 2 * w);
	};
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wProd", s)) {
		w = atoi(s.c_str());
		if ((w%8) != 0) w = 8 * (w/8 + 1);

		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "m_axis_dout_tdata", 2 * w);
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
