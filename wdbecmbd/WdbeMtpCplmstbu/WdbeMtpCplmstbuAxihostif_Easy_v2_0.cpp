/**
	* \file WdbeMtpCplmstbuAxihostif_Easy_v2_0.cpp
	* Wdbe operation processor - connect AXI controllers, CRC and timeout (implementation)
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

#include "WdbeMtpCplmstbuAxihostif_Easy_v2_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuAxihostif_Easy_v2_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuAxihostif_Easy_v2_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	// copy from WdbeMtpModbscbuAxihostif_v1_0 plus timeout2, then WdbeMtpModbscbuAxihostif_Easy_v1_0 plus rdy / adapted bus widths

	ubigint ref, refC;

	WdbeMModule* mdl = NULL;
	uint mdlNum;

	ubigint refPrcOp;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		mdlNum = 1;

		refPrcOp = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "op", "mclk", "reset", true, "", false, "main operation");

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'rx'", ref)) {
			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqArx", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "ackArx", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "dneArx", false, "sl", 1, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "arxlen", false, "slvdn", 22, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "arxd", false, "slvdn", 32, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::STRB, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "strbArxd", false, "sl", 1, "", "", "", "0", false, 0, "");

			Wdbe::setPrtCpr(dbswdbe, ref, "rdyRx", "rdyRx");
			Wdbe::setPrtCpr(dbswdbe, ref, "enRx", "enRx");

			Wdbe::setPrtCpr(dbswdbe, ref, "rx", "rx");
			Wdbe::setPrtCpr(dbswdbe, ref, "strbRx", "strbRx");

			Wdbe::setPrtCpr(dbswdbe, ref, "reset", "reset");

			Wdbe::setPrtCpr(dbswdbe, ref, "mclk", "mclk");

			Wdbe::setPrtCsi(dbswdbe, ref, "req", "reqArx");
			Wdbe::setPrtCsi(dbswdbe, ref, "ack", "ackArx");
			Wdbe::setPrtCsi(dbswdbe, ref, "dne", "dneArx");

			Wdbe::setPrtCsi(dbswdbe, ref, "len", "arxlen");

			Wdbe::setPrtCsi(dbswdbe, ref, "d", "arxd");
			Wdbe::setPrtCsi(dbswdbe, ref, "strbD", "strbArxd");
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'tx'", ref)) {
			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqAtx", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "ackAtx", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "dneAtx", false, "sl", 1, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "atxlen", false, "slvdn", 22, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "atxd", false, "slvdn", 32, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::STRB, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "strbAtxd", false, "sl", 1, "", "", "", "0", false, 0, "");

			Wdbe::setPrtCpr(dbswdbe, ref, "rdyTx", "rdyTx");
			Wdbe::setPrtCpr(dbswdbe, ref, "enTx", "enTx");

			Wdbe::setPrtCpr(dbswdbe, ref, "tx", "tx");
			Wdbe::setPrtCpr(dbswdbe, ref, "strbTx", "strbTx");

			Wdbe::setPrtCpr(dbswdbe, ref, "reset", "reset");

			Wdbe::setPrtCpr(dbswdbe, ref, "mclk", "mclk");

			Wdbe::setPrtCsi(dbswdbe, ref, "req", "reqAtx");
			Wdbe::setPrtCsi(dbswdbe, ref, "ack", "ackAtx");
			Wdbe::setPrtCsi(dbswdbe, ref, "dne", "dneAtx");

			Wdbe::setPrtCsi(dbswdbe, ref, "len", "atxlen");

			Wdbe::setPrtCsi(dbswdbe, ref, "d", "atxd");
			Wdbe::setPrtCsi(dbswdbe, ref, "strbD", "strbAtxd");
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'crc'", ref)) {
			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqCrc", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "ackCrc", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "dneCrc", false, "sl", 1, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "crccaptNotFin", false, "sl", 1, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "crcd", false, "slvdn", 32, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "lsbCrcd", false, "slvdn", 2, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::STRB, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "strbCrcd", false, "sl", 1, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "crc", false, "slvdn", 16, "", "", "", "0", false, 0, "");

			Wdbe::setPrtCpr(dbswdbe, ref, "reset", "reset");

			Wdbe::setPrtCpr(dbswdbe, ref, "mclk", "mclk");

			Wdbe::setPrtCsi(dbswdbe, ref, "req", "reqCrc");
			Wdbe::setPrtCsi(dbswdbe, ref, "ack", "ackCrc");
			Wdbe::setPrtCsi(dbswdbe, ref, "dne", "dneCrc");

			Wdbe::setPrtCsi(dbswdbe, ref, "captNotFin", "crccaptNotFin");

			Wdbe::setPrtCsi(dbswdbe, ref, "d", "crcd");
			Wdbe::setPrtCsi(dbswdbe, ref, "lsbD", "lsbCrcd");

			Wdbe::setPrtCsi(dbswdbe, ref, "strbD", "strbCrcd");

			Wdbe::setPrtCsi(dbswdbe, ref, "crc", "crc");
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'timeout'", ref)) {
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "torestart", false, "sl", 1, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "timeout", false, "sl", 1, "", "", "", "0", false, 0, "");

			Wdbe::setGenDfv(dbswdbe, ref, "twait", "100");

			Wdbe::setPrtCpr(dbswdbe, ref, "reset", "reset");

			Wdbe::setPrtCpr(dbswdbe, ref, "mclk", "mclk");
			Wdbe::setPrtCpr(dbswdbe, ref, "tkclk", "tkclk");

			Wdbe::setPrtCsi(dbswdbe, ref, "restart", "torestart");
			Wdbe::setPrtCsi(dbswdbe, ref, "timeout", "timeout");
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'timeout2'", ref)) {
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "timeout2", false, "sl", 1, "", "", "", "0", false, 0, "");

			Wdbe::setGenDfv(dbswdbe, ref, "twait", "1000");

			Wdbe::setPrtCpr(dbswdbe, ref, "reset", "reset");

			Wdbe::setPrtCpr(dbswdbe, ref, "mclk", "mclk");
			Wdbe::setPrtCpr(dbswdbe, ref, "tkclk", "tkclk");

			Wdbe::setPrtCsi(dbswdbe, ref, "restart", "torestart");
			Wdbe::setPrtCsi(dbswdbe, ref, "timeout", "timeout2");
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
