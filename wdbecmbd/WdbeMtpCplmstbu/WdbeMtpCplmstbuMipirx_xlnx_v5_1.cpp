/**
	* \file WdbeMtpCplmstbuMipirx_xlnx_v5_1.cpp
	* Wdbe operation processor - adapt port configuration and widths (implementation)
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

#include "WdbeMtpCplmstbuMipirx_xlnx_v5_1.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuMipirx_xlnx_v5_1
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuMipirx_xlnx_v5_1::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string iotype = "comb";
	int nLane = 4;

	ubigint refC;

	string s;

	Wdbe::getMpa(dbswdbe, refWdbeMModule, "iotype", iotype);
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "nLane", s)) nLane = atoi(s.c_str());

	if (iotype == "comb") {
		refC = 0; dbswdbe->loadRefBySQL("SELECT refWdbeCPort FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'mipi_phy_if_clk_hs_n'", refC);
		if (refC != 0) dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE refWdbeCPort = " + to_string(refC));

		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "mipi_phy_if_data_n", nLane);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "mipi_phy_if_data_p", nLane);

	} else {
		refC = 0; dbswdbe->loadRefBySQL("SELECT refWdbeCPort FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'mipi_phy_if_clk_n'", refC);
		if (refC != 0) dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE refWdbeCPort = " + to_string(refC));

		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "mipi_phy_if_data_hs_n", nLane);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "mipi_phy_if_data_hs_p", nLane);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "mipi_phy_if_data_lp_n", nLane);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "mipi_phy_if_data_lp_p", nLane);
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
