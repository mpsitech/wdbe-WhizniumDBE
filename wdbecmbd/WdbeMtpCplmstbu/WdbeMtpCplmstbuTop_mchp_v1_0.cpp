/**
	* \file WdbeMtpCplmstbuTop_mchp_v1_0.cpp
	* Wdbe operation processor - connect clock primitives (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 21 Oct 2021
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuTop_mchp_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuTop_mchp_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuTop_mchp_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref = 0;
	uint mdlNum = 1;

	ubigint refCLKBUF, refINBUF_DIFF, refCcc;

	refCLKBUF = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'clkbufExtclk'", refCLKBUF);
	refINBUF_DIFF = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'inbuf_diffExtclk'", refINBUF_DIFF);
	refCcc = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'cccMclk'", refCcc);

	if (refCcc == 0) {
		if (refCLKBUF != 0) {
			ref = refCLKBUF;

			Wdbe::setPrtCpi(dbswdbe, refCLKBUF, "PAD", "extclk");
			Wdbe::setPrtCsi(dbswdbe, refCLKBUF, "Y", "mclk");

		} else if (refINBUF_DIFF != 0) {
			ref = refINBUF_DIFF;

			Wdbe::setPrtCpi(dbswdbe, refINBUF_DIFF, "PADP", "extclkp");
			Wdbe::setPrtCpi(dbswdbe, refINBUF_DIFF, "PADN", "extclkn");
			Wdbe::setPrtCsi(dbswdbe, refINBUF_DIFF, "Y", "mclk");
		};

	} else {
		ref = refCcc;

		if (refINBUF_DIFF == 0) {
			Wdbe::setPrtDfv(dbswdbe, refCcc, "PLL_POWERDOWN_N_0", "0");
			Wdbe::setPrtCpi(dbswdbe, refCcc, "REF_CLK_0", "extclk");
			Wdbe::setPrtCsi(dbswdbe, refCcc, "OUT0_FABCLK_0", "mclk");

		} else {
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::CLK, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refINBUF_DIFF, 0, "extclk", false, "sl", 1, "", "", "", "0", false, 0, "");

			Wdbe::setPrtCpi(dbswdbe, refINBUF_DIFF, "PADP", "extclkp");
			Wdbe::setPrtCpi(dbswdbe, refINBUF_DIFF, "PADN", "extclkn");
			Wdbe::setPrtCsi(dbswdbe, refINBUF_DIFF, "Y", "extclk");

			Wdbe::setPrtDfv(dbswdbe, refCcc, "PLL_POWERDOWN_N_0", "0");
			Wdbe::setPrtCsi(dbswdbe, refCcc, "REF_CLK_0", "extclk");
			Wdbe::setPrtCsi(dbswdbe, refCcc, "OUT0_FABCLK_0", "mclk");
		};
	};

	dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "mclk", false, "sl", 1, "", "", "", "0", false, 0, "");
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
