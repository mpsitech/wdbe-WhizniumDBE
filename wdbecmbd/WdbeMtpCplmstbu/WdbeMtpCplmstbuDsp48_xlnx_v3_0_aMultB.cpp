/**
	* \file WdbeMtpCplmstbuDsp48_xlnx_v3_0_aMultB.cpp
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

#include "WdbeMtpCplmstbuDsp48_xlnx_v3_0_aMultB.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuDsp48_xlnx_v3_0_aMultB
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuDsp48_xlnx_v3_0_aMultB::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
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
