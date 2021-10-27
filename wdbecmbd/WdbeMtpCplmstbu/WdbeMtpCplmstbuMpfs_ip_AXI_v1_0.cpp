/**
	* \file WdbeMtpCplmstbuMpfs_ip_AXI_v1_0.cpp
	* Wdbe operation processor - add pin substitute signals (implementation)
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

#include "WdbeMtpCplmstbuMpfs_ip_AXI_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuMpfs_ip_AXI_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuMpfs_ip_AXI_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN

	// exact copy from WdbeMtpCplmstbuZynq_ip_AXI_v2_0

	ubigint ref, refC;

	WdbeMModule* mdl = NULL;
	uint mdlNum;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		mdlNum = 1;

		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::PSB, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "rdyTx", false, "sl", 1, "", "", "", "0", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::PSB, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "enTx", false, "sl", 1, "", "", "", "0", false, 0, "");

		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::PSB, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "tx", false, "slvdn", 32, "", "", "", "0", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::PSB, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "strbTx", false, "sl", 1, "", "", "", "0", false, 0, "");

		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::PSB, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "rdyRx", false, "sl", 1, "", "", "", "0", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::PSB, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "enRx", false, "sl", 1, "", "", "", "0", false, 0, "");

		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::PSB, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "rx", false, "slvdn", 32, "", "", "", "0", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::PSB, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "strbRx", false, "sl", 1, "", "", "", "0", false, 0, "");
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
