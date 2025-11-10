/**
	* \file WdbeMtpGenfstTkclksrc_v1_0.cpp
	* Wdbe operation processor - add command process handshake (implementation)
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

#include "WdbeMtpGenfstTkclksrc_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpGenfst;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpGenfstTkclksrc_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpGenfstTkclksrc_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpGenfst* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint refC;

	WdbeMModule* mdl = NULL;
	uint mdlNum;

	WdbeMCommand* cmdSetTkst = NULL;

	ubigint refPrcCmd, refPrcOp;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		if (dbswdbe->tblwdbemcommand->loadRecBySQL("SELECT * FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR) + " AND refUref = " + to_string(mdl->refWdbeMController) + " AND sref = 'setTkst'", &cmdSetTkst)) {
			// set up state machines to be identified by WrfpgaMdlfine
			refPrcCmd = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "cmd", "mclk", "reset", true, "", false, "command execution");
			refPrcOp = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "op", "mclk", "reset", true, "", false, "main operation");

			// handshake signals
			mdlNum = Wdbe::getNextSigRefNum(dbswdbe, VecWdbeVMSignalRefTbl::MDL, mdl->ref);

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			cmdSetTkst->ivrRefWdbeMSignal = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "reqCmdToOpInvSetTkst", false, "sl", 1, "", "", "", "0", 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "ackCmdToOpInvSetTkst", false, "sl", 1, "", "", "", "0", 0, "");

			dbswdbe->tblwdbemcommand->updateRec(cmdSetTkst);

			delete cmdSetTkst;
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
