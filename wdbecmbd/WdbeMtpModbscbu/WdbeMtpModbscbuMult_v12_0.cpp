/**
	* \file WdbeMtpModbscbuMult_v12_0.cpp
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

#include "WdbeMtpModbscbuMult_v12_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModbscbu;

// IP ns.cust --- INSERT

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
