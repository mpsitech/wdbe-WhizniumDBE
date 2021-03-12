/**
	* \file WdbeMtpModbscbuDsp48_v3_0_aPlusDPlusC.cpp
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

#include "WdbeMtpModbscbuDsp48_v3_0_aPlusDPlusC.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModbscbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpModbscbuDsp48_v3_0_aPlusDPlusC
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModbscbuDsp48_v3_0_aPlusDPlusC::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModbscbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string wSmda, wSmdc, wSmdd, wSum;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wSmda", wSmda)) Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "a", atoi(wSmda.c_str()));
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wSmdc", wSmdc)) Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "c", atoi(wSmdc.c_str()));
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wSmdd", wSmdd)) Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "d", atoi(wSmdd.c_str()));
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wSum", wSum)) Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "p", atoi(wSum.c_str()));
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
