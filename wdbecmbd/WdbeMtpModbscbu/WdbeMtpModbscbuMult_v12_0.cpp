/**
	* \file WdbeMtpModbscbuMult_v12_0.cpp
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

#include "WdbeMtpModbscbuMult_v12_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModbscbu;

/******************************************************************************
 namespace WdbeMtpModbscbuMult_v12_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModbscbuMult_v12_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModbscbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string wFcta, wFctb, wProd;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wFcta", wFcta)) Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "a", atoi(wFcta.c_str()));
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wFctb", wFctb)) Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "b", atoi(wFctb.c_str()));
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wProd", wProd)) Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "p", atoi(wProd.c_str()));
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT


