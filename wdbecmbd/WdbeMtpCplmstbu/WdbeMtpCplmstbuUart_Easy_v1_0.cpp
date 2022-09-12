/**
	* \file WdbeMtpCplmstbuUart_Easy_v1_0.cpp
	* Wdbe operation processor - connect UART controllers and timeout (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 7 Jun 2022
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuUart_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuUart_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuUart_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref, refC;

	WdbeMModule* mdl = NULL;
	uint mdlNum;

	ubigint refPrcOp, refPrcXfer;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		mdlNum = 1;

		refPrcOp = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "op", "mclk", "reset", true, "", false, "main operation");
		refPrcXfer = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "xfer", "mclk", "reset", true, "", false, "transfer operation");

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'timeout'", ref)) {
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcXfer, 0, "torestart", false, "sl", 1, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "timeout", false, "sl", 1, "", "", "", "0", false, 0, "");

			Wdbe::setGenSrc(dbswdbe, ref, "twait", "toRx");

			Wdbe::setPrtCpr(dbswdbe, ref, "reset", "reset");

			Wdbe::setPrtCpr(dbswdbe, ref, "mclk", "mclk");
			Wdbe::setPrtCpr(dbswdbe, ref, "tkclk", "tkclk");

			Wdbe::setPrtCsi(dbswdbe, ref, "restart", "torestart");
			Wdbe::setPrtCsi(dbswdbe, ref, "timeout", "timeout");
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'rx'", ref)) {
			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcXfer, 0, "reqUrx", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "ackUrx", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "dneUrx", false, "sl", 1, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "urxlen", false, "slvdn", 17, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "urxd", false, "slvdn", 8, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "strbUrxd", false, "sl", 1, "", "", "", "0", false, 0, "");

			Wdbe::setGenSrc(dbswdbe, ref, "fMclk", "fMclk");
			Wdbe::setGenSrc(dbswdbe, ref, "fSclk", "fSclk");

			Wdbe::setPrtCpr(dbswdbe, ref, "rxd", "rxd");

			Wdbe::setPrtCpr(dbswdbe, ref, "reset", "reset");

			Wdbe::setPrtCpr(dbswdbe, ref, "mclk", "mclk");

			Wdbe::setPrtCsi(dbswdbe, ref, "req", "reqUrx");
			Wdbe::setPrtCsi(dbswdbe, ref, "ack", "ackUrx");
			Wdbe::setPrtCsi(dbswdbe, ref, "dne", "dneUrx");

			Wdbe::setPrtCsi(dbswdbe, ref, "len", "urxlen");

			Wdbe::setPrtCsi(dbswdbe, ref, "d", "urxd");
			Wdbe::setPrtCsi(dbswdbe, ref, "strbD", "strbUrxd");

			Wdbe::setPrtDfv(dbswdbe, ref, "burst", "0");
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'tx'", ref)) {
			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcXfer, 0, "reqUtx", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "ackUtx", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "dneUtx", false, "sl", 1, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "utxlen", false, "slvdn", 17, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcXfer, 0, "utxd", false, "slvdn", 8, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "strbUtxd", false, "sl", 1, "", "", "", "0", false, 0, "");

			Wdbe::setGenSrc(dbswdbe, ref, "fMclk", "fMclk");
			Wdbe::setGenSrc(dbswdbe, ref, "fSclk", "fSclk");

			Wdbe::setPrtCpr(dbswdbe, ref, "txd", "txd");

			Wdbe::setPrtCpr(dbswdbe, ref, "reset", "reset");

			Wdbe::setPrtCpr(dbswdbe, ref, "mclk", "mclk");

			Wdbe::setPrtCsi(dbswdbe, ref, "req", "reqUtx");
			Wdbe::setPrtCsi(dbswdbe, ref, "ack", "ackUtx");
			Wdbe::setPrtCsi(dbswdbe, ref, "dne", "dneUtx");

			Wdbe::setPrtCsi(dbswdbe, ref, "len", "utxlen");

			Wdbe::setPrtCsi(dbswdbe, ref, "d", "utxd");
			Wdbe::setPrtCsi(dbswdbe, ref, "strbD", "strbUtxd");
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
