/**
	* \file WdbeMtpCplmstbuSmartreg_v1_0.cpp
	* Wdbe operation processor - connect memory (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 7 Feb 2024
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuSmartreg_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuSmartreg_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuSmartreg_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref;

	uint mdlNum;

	ubigint refPrcOp;

	mdlNum = 1;

	refPrcOp = dbswdbe->tblwdbemprocess->insertNewRec(NULL, refWdbeMModule, 0, "op", "mclk", "reset", true, "", false, "main operation");

	if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'mem'", ref)) {
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "enMem", false, "sl", 1, "", "", "", "0", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "weMem", false, "slvdn", 1, "", "", "", "0", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "aMem", false, "slvdn", 10, "", "", "", "", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "drdMem", false, "slvdn", 16, "", "", "", "", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "dwrMem", false, "slvdn", 16, "", "", "", "", false, 0, "");

		Wdbe::setPrtCpr(dbswdbe, ref, "clkA", "mclk");
		Wdbe::setPrtCsi(dbswdbe, ref, "enA", "enMem");
		Wdbe::setPrtCsi(dbswdbe, ref, "weA", "weMem");
		Wdbe::setPrtCsi(dbswdbe, ref, "addrA", "aMem");
		Wdbe::setPrtCsi(dbswdbe, ref, "doutA", "drdMem");
		Wdbe::setPrtCsi(dbswdbe, ref, "dinA", "dwrMem");

		Wdbe::setPrtCpr(dbswdbe, ref, "clkB", "mclk");
		Wdbe::setPrtCpr(dbswdbe, ref, "enB", "enMemB");
		Wdbe::setPrtCpr(dbswdbe, ref, "addrB", "aMemB");
		Wdbe::setPrtCpr(dbswdbe, ref, "doutB", "drdMemB");
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
