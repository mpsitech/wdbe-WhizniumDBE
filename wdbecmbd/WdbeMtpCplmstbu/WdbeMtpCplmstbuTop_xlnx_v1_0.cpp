/**
	* \file WdbeMtpCplmstbuTop_xlnx_v1_0.cpp
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

#include "WdbeMtpCplmstbuTop_xlnx_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuTop_xlnx_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuTop_xlnx_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref = 0;
	uint mdlNum = 1;

	ubigint refBUFG, refIBUFGDS, refMmcm, refIBUFDS;

	refBUFG = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'bufgExtclk'", refBUFG);
	refIBUFGDS = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'ibufgdsExtclk'", refIBUFGDS);
	refMmcm = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'mmcmMclk'", refMmcm);
	refIBUFDS = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'ibufdsExtclk'", refIBUFDS);


	if (refMmcm == 0) {
		if (refBUFG != 0) {
			ref = refBUFG;

			Wdbe::setPrtCpi(dbswdbe, refBUFG, "I", "extclk");
			Wdbe::setPrtCsi(dbswdbe, refBUFG, "O", "mclk");

		} else if (refIBUFGDS != 0) {
			ref = refIBUFGDS;

			Wdbe::setPrtCpi(dbswdbe, refIBUFGDS, "I", "extclkp");
			Wdbe::setPrtCpi(dbswdbe, refIBUFGDS, "IB", "extclkn");
			Wdbe::setPrtCsi(dbswdbe, refIBUFGDS, "O", "mclk");
		};

	} else {
		ref = refMmcm;

		if (refIBUFDS == 0) {
			Wdbe::setPrtDfv(dbswdbe, refMmcm, "reset", "0");
			Wdbe::setPrtCpi(dbswdbe, refMmcm, "clk_in1", "extclk");
			Wdbe::setPrtCsi(dbswdbe, refMmcm, "clk_out1", "mclk");

		} else {
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::CLK, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refIBUFDS, 0, "extclk", false, "sl", 1, "", "", "", "0", false, 0, "");

			Wdbe::setPrtCpi(dbswdbe, refIBUFDS, "I", "extclkp");
			Wdbe::setPrtCpi(dbswdbe, refIBUFDS, "IB", "extclkn");
			Wdbe::setPrtCsi(dbswdbe, refIBUFDS, "O", "extclk");

			Wdbe::setPrtDfv(dbswdbe, refMmcm, "reset", "0");
			Wdbe::setPrtCsi(dbswdbe, refMmcm, "clk_in1", "extclk");
			Wdbe::setPrtCsi(dbswdbe, refMmcm, "clk_out1", "mclk");
		};
	};

	dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "mclk", false, "sl", 1, "", "", "", "0", false, 0, "");
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
