/**
	* \file WdbeMtpCplmstbuDiv_xlnx_v3_0.cpp
	* Wdbe operation processor - adapt port widths (implementation)
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

#include "WdbeMtpCplmstbuDiv_xlnx_v3_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuDiv_xlnx_v3_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuDiv_xlnx_v3_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string wDvd, wDvs;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wDvd", wDvd)) {
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "dividend", atoi(wDvd.c_str()));
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "quotient", atoi(wDvd.c_str()));
	};

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wDvs", wDvs)) {
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "divisor", atoi(wDvs.c_str()));
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "fractional", atoi(wDvs.c_str()));
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
