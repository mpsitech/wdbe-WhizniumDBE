/**
	* \file WdbeMtpCplmstbuCsi2_hard_mipi_rx_efnx_v1_3.cpp
	* Wdbe operation processor - adapt port widths (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 19 Jun 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuCsi2_hard_mipi_rx_efnx_v1_3.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuCsi2_hard_mipi_rx_efnx_v1_3
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuCsi2_hard_mipi_rx_efnx_v1_3::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string s;
	int nLane;
	
	nLane = 4;
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "nLane", s)) nLane = atoi(s.c_str());

	Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "RxClkEsc", nLane);
	Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "RxErrEsc", nLane);
	Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "RxErrControl", nLane);
	Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "RxErrSotSyncHS", nLane);
	Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "RxUlpsEsc", nLane);
	Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "RxUlpsActiveNot", nLane);
	Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "RxSkewCalHS", nLane);
	Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "RxStopState", nLane);
	Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "RxSyncHS", nLane);
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
