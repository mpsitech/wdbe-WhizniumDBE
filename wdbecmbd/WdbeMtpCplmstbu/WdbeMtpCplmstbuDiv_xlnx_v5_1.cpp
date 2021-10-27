/**
	* \file WdbeMtpCplmstbuDiv_xlnx_v5_1.cpp
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

#include "WdbeMtpCplmstbuDiv_xlnx_v5_1.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuDiv_xlnx_v5_1
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuDiv_xlnx_v5_1::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string wDvd, wDvs;

	int axiwDvd, axiwDvs;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wDvd", wDvd) && Wdbe::getMpa(dbswdbe, refWdbeMModule, "wDvs", wDvs)) {
		axiwDvd = 8 * ceil(atof(wDvd.c_str())/8.0);
		axiwDvs = 8 * ceil(atof(wDvs.c_str())/8.0);

		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "s_axis_dividend_tdata", axiwDvd);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "s_axis_divisor_tdata", axiwDvs);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "m_axis_dout_tdata", axiwDvd+axiwDvs);
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
