/**
	* \file WdbeMtpModbscbuSub_v12_0.cpp
	* Wdbe operation processor - adapt port widths (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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


