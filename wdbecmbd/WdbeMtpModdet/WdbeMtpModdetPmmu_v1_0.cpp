/**
	* \file WdbeMtpModdetPmmu_v1_0.cpp
	* Wdbe operation processor - add command process handshake (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpModdetPmmu_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModdet;

/******************************************************************************
 namespace WdbeMtpModdetPmmu_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModdetPmmu_v1_0::run(
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

	WdbeMCommand* cmdAlloc = NULL;
	WdbeMCommand* cmdFree = NULL;
	WdbeMCommand* cmdReadOutbuf0 = NULL;
	WdbeMCommand* cmdWriteInbuf0 = NULL;
	WdbeMError* errInvalid = NULL;

	ubigint refPrcCmd, refPrcInbuf0, refPrcOutbuf0;
	ubigint refPrcOp;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		dbswdbe->tblwdbemcommand->loadRecBySQL("SELECT * FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR) + " AND refUref = " + to_string(mdl->refWdbeMController) + " AND sref = 'alloc'", &cmdAlloc);
		dbswdbe->tblwdbemcommand->loadRecBySQL("SELECT * FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR) + " AND refUref = " + to_string(mdl->refWdbeMController) + " AND sref = 'free'", &cmdFree);
		dbswdbe->tblwdbemcommand->loadRecBySQL("SELECT * FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR) + " AND refUref = " + to_string(mdl->refWdbeMController) + " AND sref = 'readOutbuf0'", &cmdReadOutbuf0);
		dbswdbe->tblwdbemcommand->loadRecBySQL("SELECT * FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR) + " AND refUref = " + to_string(mdl->refWdbeMController) + " AND sref = 'writeInbuf0'", &cmdWriteInbuf0);
		dbswdbe->tblwdbemerror->loadRecBySQL("SELECT * FROM TblWdbeMError WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR) + " AND refUref = " + to_string(mdl->refWdbeMController) + " AND sref = 'invalid'", &errInvalid);

		if (cmdAlloc && cmdFree && cmdReadOutbuf0 && cmdWriteInbuf0 && errInvalid) {
			// set up state machines to be identified by WrfpgaMdlfine
			refPrcCmd = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "cmd", "mclk", "reset", true, "", false, "command execution");
			refPrcInbuf0 = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "inbuf0", "mclk", "reset", true, "", false, "inbuf0 and writeInbuf0 command management");
			refPrcOutbuf0 = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "outbuf0", "mclk", "reset", true, "", false, "outbuf0 and readOutbuf0 command management");

			dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMProcess WHERE refWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'op'", refPrcOp);

			// handshake signals
			dbswdbe->loadUintBySQL("SELECT mdlNum FROM TblWdbeMSignal WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " ORDER BY mdlNum DESC LIMIT 1 OFFSET 0", mdlNum);
			mdlNum++;

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			cmdAlloc->ivrRefWdbeMSignal = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "reqCmdToOpInvAlloc", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "ackCmdToOpInvAlloc", false, "sl", 1, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			cmdFree->ivrRefWdbeMSignal = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "reqCmdToOpInvFree", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "ackCmdToOpInvFree", false, "sl", 1, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			cmdReadOutbuf0->ivrRefWdbeMSignal = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "reqCmdToOutbuf0Inv", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOutbuf0, 0, "ackCmdToOutbuf0Inv", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOutbuf0, 0, "dnyCmdToOutbuf0Inv", false, "sl", 1, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			cmdReadOutbuf0->rvrRefWdbeMSignal = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "reqCmdToOutbuf0Rev", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOutbuf0, 0, "ackCmdToOutbuf0Rev", false, "sl", 1, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			cmdWriteInbuf0->ivrRefWdbeMSignal = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "reqCmdToInbuf0Inv", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcInbuf0, 0, "ackCmdToInbuf0Inv", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcInbuf0, 0, "dnyCmdToInbuf0Inv", false, "sl", 1, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			cmdWriteInbuf0->rvrRefWdbeMSignal = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "reqCmdToInbuf0Rev", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcInbuf0, 0, "ackCmdToInbuf0Rev", false, "sl", 1, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			cmdWriteInbuf0->rerRefWdbeMSignal = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcInbuf0, 0, "reqInbuf0ToCmdRet", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "ackInbuf0ToCmdRet", false, "sl", 1, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			cmdReadOutbuf0->rerRefWdbeMSignal = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOutbuf0, 0, "reqOutbuf0ToCmdRet", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "ackOutbuf0ToCmdRet", false, "sl", 1, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcInbuf0, 0, "reqInbuf0ToCmdErrInvalid", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOutbuf0, 0, "reqOutbuf0ToCmdErrInvalid", false, "sl", 1, "", "", "", "0", false, 0, "");
			errInvalid->traRefWdbeMSignal = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "ackCmdErrInvalid", false, "sl", 1, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemcommand->updateRec(cmdAlloc);
			dbswdbe->tblwdbemcommand->updateRec(cmdFree);
			dbswdbe->tblwdbemcommand->updateRec(cmdReadOutbuf0);
			dbswdbe->tblwdbemcommand->updateRec(cmdWriteInbuf0);
			dbswdbe->tblwdbemerror->updateRec(errInvalid);
		};

		if (cmdAlloc) delete cmdAlloc;
		if (cmdFree) delete cmdFree;
		if (cmdReadOutbuf0) delete cmdReadOutbuf0;
		if (cmdWriteInbuf0) delete cmdWriteInbuf0;
		if (errInvalid) delete errInvalid;

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT


