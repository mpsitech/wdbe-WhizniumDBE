/**
	* \file WdbeMtpCplmstbuSelectio_xlnx_v5_1_mipirx.cpp
	* Wdbe operation processor - adapt port widths (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 21 Dec 2021
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuSelectio_xlnx_v5_1_mipirx.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuSelectio_xlnx_v5_1_mipirx
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuSelectio_xlnx_v5_1_mipirx::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string nLane_s;

	int nLane;

	ubigint refC;
	uint mdlNum;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "nLane", nLane_s)) {
		nLane = atoi(nLane_s.c_str());

		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "data_in_from_pins_p", nLane);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "data_in_from_pins_n", nLane);

		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "data_in_to_device", nLane * 8);
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
