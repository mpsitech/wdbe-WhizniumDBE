/**
	* \file WdbeMtpModdetSpifwd_v1_0.cpp
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

#include "WdbeMtpModdetSpifwd_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModdet;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpModdetSpifwd_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModdetSpifwd_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModdet* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref, refC;

	WdbeMModule* mdl = NULL;
	uint mdlNum;

	WdbeMProcess* prc = NULL;

	uint fsmNum;

	ubigint refFstInit, refFstEmpty, refFstLock, refFstFullA, refFstSendC, refFstPrepFwderrA, refFstPrepFwderrB, refFstToCmdbufA, refFstToCmdbufB, refFstFromCmdbufA, refFstFromCmdbufB;

	bool hasrdbuf, haswrbuf;

	WdbeMCommand* cmdReset = NULL;
	WdbeMCommand* cmdRead = NULL;
	WdbeMCommand* cmdWrite = NULL;

	WdbeMError* errBufxfer = NULL;

	ubigint refPrcCmd;
	ubigint refPrcOp, refPrcRdbufB, refPrcRead, refPrcWrbufB, refPrcWrite;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		hasrdbuf = dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'rdbuf'", ref);
		haswrbuf = dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'wrbuf'", ref);

		dbswdbe->tblwdbemcommand->loadRecBySQL("SELECT * FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR) + " AND refUref = " + to_string(mdl->refWdbeMController) + " AND sref = 'reset'", &cmdReset);
		if (hasrdbuf) dbswdbe->tblwdbemcommand->loadRecBySQL("SELECT * FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR) + " AND refUref = " + to_string(mdl->refWdbeMController) + " AND sref = 'read'", &cmdRead);
		if (haswrbuf) dbswdbe->tblwdbemcommand->loadRecBySQL("SELECT * FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR) + " AND refUref = " + to_string(mdl->refWdbeMController) + " AND sref = 'write'", &cmdWrite);

		if (hasrdbuf || haswrbuf) dbswdbe->tblwdbemerror->loadRecBySQL("SELECT * FROM TblWdbeMError WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR) + " AND refUref = " + to_string(mdl->refWdbeMController) + " AND sref = 'bufxfer'", &errBufxfer);

		if (cmdReset && ((hasrdbuf && cmdRead) || !hasrdbuf) && ((haswrbuf && cmdWrite) || !haswrbuf) && (((hasrdbuf || haswrbuf) && errBufxfer) || (!hasrdbuf && !haswrbuf))) {
			// set up command state machine
			refPrcCmd = dbswdbe->tblwdbemprocess->insertNewRec(&prc, mdl->ref, 0, "cmd", "mclk", "reset", true, "", false, "command execution");

			prc->refWdbeMFsm = dbswdbe->tblwdbemfsm->insertNewRec(NULL, prc->ref);
			dbswdbe->tblwdbemprocess->updateRec(prc);

			fsmNum = 1;

			refFstInit = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, fsmNum++, "init", false, "");

			refFstEmpty = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, fsmNum++, "empty", false, "");

			refFstLock = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, fsmNum++, "lock", false, "");

			refFstFullA = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, fsmNum++, "fullA", false, "");

			refFstSendC = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, fsmNum++, "sendC", false, "");

			refC = dbswdbe->tblwdbecfsmstate->getNewRef();
			refFstPrepFwderrA = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "prepFwderrA", false, "");
			refFstPrepFwderrB = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "prepFwderrB", false, "");

			refC = dbswdbe->tblwdbecfsmstate->getNewRef();
			refFstToCmdbufA = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "toCmdbufA", false, "");
			refFstToCmdbufB = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "toCmdbufB", false, "");

			refC = dbswdbe->tblwdbecfsmstate->getNewRef();
			refFstFromCmdbufA = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "fromCmdbufA", false, "");
			refFstFromCmdbufB = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "fromCmdbufB", false, "");

			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstEmpty, 1, refFstLock, "reqOpToCmdLock", "unrdy", "", "", "", "", "", ""); // will be modified by ModdetCtrFwdctr

			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstLock, 1, refFstInit, "!reqOpToCmdLock and lenCmdbuf=0", "", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstLock, 2, refFstToCmdbufB, "reqOpToCmdToCmdbuf", "toCmdbuf", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstLock, 3, refFstFromCmdbufB, "reqOpToCmdFromCmdbuf", "fromCmdbuf", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstLock, 4, refFstPrepFwderrA, "reqOpToCmdFwderr", "fwderr", "", "", "", "", "", "");

			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstSendC, 1, refFstInit, "nowr", "", "reqOpToCmdFwderr and cmdbuf(ixCmdbufAction)=tixDbeVActionFwderr", "ackOpToCmdFwderr", "", "", "", ""); // will be modified by ModdetCtrFwdctr

			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstPrepFwderrA, 1, refFstFullA, "j=4", "last", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstPrepFwderrA, 2, refFstPrepFwderrB, "else", "load", "", "", "", "", "", "");

			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstPrepFwderrB, 2, refFstPrepFwderrA, "", "store", "", "", "", "", "", "");

			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstToCmdbufA, 1, refFstLock, "!reqOpToCmdToCmdbuf", "reset", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstToCmdbufA, 2, refFstFullA, "dneOpToCmdToCmdbuf", "", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstToCmdbufA, 3, refFstToCmdbufB, "!strbDToCmdbuf", "", "", "", "", "", "", "");

			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstToCmdbufB, 1, refFstToCmdbufA, "strbDToCmdbuf", "toCmdbufB", "", "", "", "", "", "");

			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstFromCmdbufA, 1, refFstLock, "!reqOpToCmdFromCmdbuf", "", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstFromCmdbufA, 2, refFstInit, "dneOpToCmdFromCmdbuf", "", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstFromCmdbufA, 3, refFstFromCmdbufB, "!strbDFromCmdbuf", "out", "", "", "", "", "", "");

			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstFromCmdbufB, 1, refFstFromCmdbufA, "strbDFromCmdbuf", "fromCmdbufB", "", "", "", "", "", "");

			delete prc;

			// retrieve processes
			dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMProcess WHERE refWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'op'", refPrcOp);
			if (hasrdbuf) {
				dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMProcess WHERE refWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'rdbufB'", refPrcRdbufB);
				dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMProcess WHERE refWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'read'", refPrcRead);
			};
			if (haswrbuf) {
				dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMProcess WHERE refWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'wrbufB'", refPrcWrbufB);
				dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMProcess WHERE refWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'write'", refPrcWrite);
			};

			// cmdbuf external access
			mdlNum = 1;

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "lenCmdbuf", false, "nat", 0, "0..sizeCmdbuf", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "dFromCmdbuf", false, "slvdn", 8, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::STRB, 0, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "strbDFromCmdbuf", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::STRB, 0, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "strbDToCmdbuf", false, "sl", 1, "", "", "", "0", false, 0, "");


			// handshake signals
			if (hasrdbuf || haswrbuf) {
				refC = dbswdbe->tblwdbecsignal->getNewRef();
				cmdReset->ivrRefWdbeMSignal = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "reqCmdInvReset", false, "sl", 1, "", "", "", "0", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "ackCmdToOpInvReset", false, "sl", 1, "", "", "", "0", false, 0, "");
				if (hasrdbuf) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcRead, 0, "ackCmdToReadInvReset", false, "sl", 1, "", "", "", "0", false, 0, "");
				if (haswrbuf) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcWrite, 0, "ackCmdToWriteInvReset", false, "sl", 1, "", "", "", "0", false, 0, "");
			} else {
				refC = dbswdbe->tblwdbecsignal->getNewRef();
				cmdReset->ivrRefWdbeMSignal = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "reqCmdToOpInvReset", false, "sl", 1, "", "", "", "0", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "ackCmdToOpInvReset", false, "sl", 1, "", "", "", "0", false, 0, "");
			};
			dbswdbe->tblwdbemcommand->updateRec(cmdReset);

			if (hasrdbuf) {
				refC = dbswdbe->tblwdbecsignal->getNewRef();
				cmdRead->ivrRefWdbeMSignal = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "reqCmdToReadInv", false, "sl", 1, "", "", "", "0", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcRead, 0, "ackCmdToReadInv", false, "sl", 1, "", "", "", "0", false, 0, "");

				refC = dbswdbe->tblwdbecsignal->getNewRef();
				cmdRead->rvrRefWdbeMSignal = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "reqCmdToReadRev", false, "sl", 1, "", "", "", "0", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcRead, 0, "ackCmdToReadRev", false, "sl", 1, "", "", "", "0", false, 0, "");
			};

			if (haswrbuf) {
				refC = dbswdbe->tblwdbecsignal->getNewRef();
				cmdWrite->ivrRefWdbeMSignal = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "reqCmdToWriteInv", false, "sl", 1, "", "", "", "0", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcWrite, 0, "ackCmdToWriteInv", false, "sl", 1, "", "", "", "0", false, 0, "");

				refC = dbswdbe->tblwdbecsignal->getNewRef();
				cmdWrite->rvrRefWdbeMSignal = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "reqCmdToWriteRev", false, "sl", 1, "", "", "", "0", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcWrite, 0, "ackCmdToWriteRev", false, "sl", 1, "", "", "", "0", false, 0, "");
			};

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqOpToCmdLock", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "ackOpToCmdLock", false, "sl", 1, "", "state(lock)", "1", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "dnyOpToCmdLock", false, "sl", 1, "", "state(waitLockA..C)", "1", "0", true, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqOpToCmdToCmdbuf", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "ackOpToCmdToCmdbuf", false, "sl", 1, "", "state(toCmdbufA..B)", "1", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "dneOpToCmdToCmdbuf", false, "sl", 1, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqOpToCmdFromCmdbuf", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "ackOpToCmdFromCmdbuf", false, "sl", 1, "", "state(fromCmdbufA..B)", "1", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "dneOpToCmdFromCmdbuf", false, "sl", 1, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqOpToCmdFwderr", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "ackOpToCmdFwderr", false, "sl", 1, "", "", "", "0", false, 0, "");

			if (hasrdbuf) {
				refC = dbswdbe->tblwdbecsignal->getNewRef();
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqOpToReadErr", false, "sl", 1, "", "", "", "0", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcRead, 0, "ackOpToReadErr", false, "sl", 1, "", "", "", "0", false, 0, "");

				refC = dbswdbe->tblwdbecsignal->getNewRef();
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcRdbufB, 0, "reqRdbufBToReadDone", false, "sl", 1, "", "", "", "0", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcRead, 0, "ackRdbufBToReadDone", false, "sl", 1, "", "", "", "0", false, 0, "");

				refC = dbswdbe->tblwdbecsignal->getNewRef();
				cmdRead->rerRefWdbeMSignal = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcRead, 0, "reqReadToCmdRet", false, "sl", 1, "", "", "", "0", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "ackReadToCmdRet", false, "sl", 1, "", "", "", "0", false, 0, "");

				dbswdbe->tblwdbemcommand->updateRec(cmdRead);
			};

			if (haswrbuf) {
				refC = dbswdbe->tblwdbecsignal->getNewRef();
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqOpToWriteErr", false, "sl", 1, "", "", "", "0", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcWrite, 0, "ackOpToWriteErr", false, "sl", 1, "", "", "", "0", false, 0, "");

				refC = dbswdbe->tblwdbecsignal->getNewRef();
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcWrbufB, 0, "reqWrbufBToWriteDone", false, "sl", 1, "", "", "", "0", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcWrite, 0, "ackWrbufBToWriteDone", false, "sl", 1, "", "", "", "0", false, 0, "");

				refC = dbswdbe->tblwdbecsignal->getNewRef();
				cmdWrite->rerRefWdbeMSignal = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcWrite, 0, "reqWriteToCmdRet", false, "sl", 1, "", "", "", "0", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "ackWriteToCmdRet", false, "sl", 1, "", "", "", "0", false, 0, "");

				dbswdbe->tblwdbemcommand->updateRec(cmdWrite);
			};

			if (hasrdbuf || haswrbuf) {
				refC = dbswdbe->tblwdbecsignal->getNewRef();
				if (hasrdbuf) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcRead, 0, "reqReadToCmdErrBufxfer", false, "sl", 1, "", "state(errA)", "1", "0", false, 0, "");
				if (haswrbuf) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcWrite, 0, "reqWriteToCmdErrBufxfer", false, "sl", 1, "", "state(errA)", "1", "0", false, 0, "");
				errBufxfer->traRefWdbeMSignal = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcCmd, 0, "ackCmdErrBufxfer", false, "sl", 1, "", "", "", "0", false, 0, "");

				dbswdbe->tblwdbemerror->updateRec(errBufxfer);
			};
		};

		if (cmdReset) delete cmdReset;
		if (cmdRead) delete cmdRead;
		if (cmdWrite) delete cmdWrite;

		if (errBufxfer) delete errBufxfer;

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
