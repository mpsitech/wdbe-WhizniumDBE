/**
	* \file WdbeMtpModbscbuSub_v12_0.cpp
	* Wdbe operation processor - adapt port widths (implementation)
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

#include "WdbeMtpModbscbuSub_v12_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModbscbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpModbscbuSub_v12_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModbscbuSub_v12_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModbscbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string wMnd, wSbd, wDiff;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wMnd", wMnd)) Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "a", atoi(wMnd.c_str()));
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wSbd", wSbd)) Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "b", atoi(wSbd.c_str()));
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wDiff", wDiff)) Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "s", atoi(wDiff.c_str()));
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
