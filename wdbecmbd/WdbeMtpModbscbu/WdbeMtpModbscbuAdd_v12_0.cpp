/**
	* \file WdbeMtpModbscbuAdd_v12_0.cpp
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

#include "WdbeMtpModbscbuAdd_v12_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModbscbu;

/******************************************************************************
 namespace WdbeMtpModbscbuAdd_v12_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModbscbuAdd_v12_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModbscbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string wSmda, wSmdb, wSum;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wSmda", wSmda)) Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "a", atoi(wSmda.c_str()));
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wSmdb", wSmdb)) Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "b", atoi(wSmdb.c_str()));
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wSum", wSum)) Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "s", atoi(wSum.c_str()));
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT


