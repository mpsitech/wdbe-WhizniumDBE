/**
	* \file WdbeMtpModbscbuZynq_ip_AXI_v2_0.cpp
	* Wdbe operation processor - add pin substitute signals (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpModbscbuZynq_ip_AXI_v2_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModbscbu;

/******************************************************************************
 namespace WdbeMtpModbscbuZynq_ip_AXI_v2_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModbscbuZynq_ip_AXI_v2_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModbscbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref, refC;

	WdbeMModule* mdl = NULL;
	uint mdlNum;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		mdlNum = 1;

		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::PSB, refC, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "rdyTx", false, "sl", 1, "", "", "", "0", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::PSB, refC, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "enTx", false, "sl", 1, "", "", "", "0", false, 0, "");

		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::PSB, refC, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "tx", false, "slvdn", 32, "", "", "", "0", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::PSB, refC, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "strbTx", false, "sl", 1, "", "", "", "0", false, 0, "");

		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::PSB, refC, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "rdyRx", false, "sl", 1, "", "", "", "0", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::PSB, refC, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "enRx", false, "sl", 1, "", "", "", "0", false, 0, "");

		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::PSB, refC, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "rx", false, "slvdn", 32, "", "", "", "0", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::PSB, refC, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "strbRx", false, "sl", 1, "", "", "", "0", false, 0, "");
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
