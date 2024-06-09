/**
	* \file WdbeMtpCplmstbuXfft_xlnx_v9_1.cpp
	* Wdbe operation processor - adapt port widths (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Oct 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuXfft_xlnx_v9_1.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuXfft_xlnx_v9_1
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuXfft_xlnx_v9_1::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string s;

	int wD;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wD", s)) {
		wD = 2 * atoi(s.c_str());

		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "s_axis_data_tdata", wD);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "m_axis_data_tdata", wD);
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
