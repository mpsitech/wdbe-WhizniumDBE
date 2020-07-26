/**
	* \file WdbeMtpModbscbuDiv_v3_0.cpp
	* Wdbe operation processor - adapt port widths (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpModbscbuDiv_v3_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModbscbu;

/******************************************************************************
 namespace WdbeMtpModbscbuDiv_v3_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModbscbuDiv_v3_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModbscbu* dpchinv
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


