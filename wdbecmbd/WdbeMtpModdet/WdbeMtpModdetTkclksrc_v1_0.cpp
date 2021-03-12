/**
	* \file WdbeMtpModdetTkclksrc_v1_0.cpp
	* Wdbe operation processor - add command process handshake (implementation)
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

#include "WdbeMtpModdetTkclksrc_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModdet;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpModdetTkclksrc_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModdetTkclksrc_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModdet* dpchinv
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
			dbswdbe->loadUintBySQL("SELECT mdlNum FROM TblWdbeMSignal WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " ORDER BY mdlNum DESC LIMIT 1 OFFSET 0", mdlNum);
			mdlNum++;

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			cmdSetTkst->ivrRefWdbeMSignal = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "reqCmdToOpInvSetTkst", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "ackCmdToOpInvSetTkst", false, "sl", 1, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemcommand->updateRec(cmdSetTkst);

			delete cmdSetTkst;
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
