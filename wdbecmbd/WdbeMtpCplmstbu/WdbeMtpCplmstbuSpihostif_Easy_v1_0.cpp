/**
	* \file WdbeMtpCplmstbuSpihostif_Easy_v1_0.cpp
	* Wdbe operation processor - connect SPI interface, CRC and timeout (implementation)
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

#include "WdbeMtpCplmstbuSpihostif_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuSpihostif_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuSpihostif_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	// copy from WdbeMtpModbscbuSpihostif_v1_0 plus timeout2

	ubigint ref, refC;

	WdbeMModule* mdl = NULL;
	uint mdlNum;

	ubigint refPrcOp;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		mdlNum = 1;

		refPrcOp = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "op", "mclk", "reset", true, "", false, "main operation");

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'crc'", ref)) {
			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqCrc", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "ackCrc", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "dneCrc", false, "sl", 1, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "crccaptNotFin", false, "sl", 1, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "crcd", false, "slvdn", 8, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::STRB, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "strbCrcd", false, "sl", 1, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "crc", false, "slvdn", 16, "", "", "", "0", false, 0, "");

			Wdbe::setPrtCpr(dbswdbe, ref, "reset", "reset");

			Wdbe::setPrtCpr(dbswdbe, ref, "mclk", "mclk");

			Wdbe::setPrtCsi(dbswdbe, ref, "req", "reqCrc");
			Wdbe::setPrtCsi(dbswdbe, ref, "ack", "ackCrc");
			Wdbe::setPrtCsi(dbswdbe, ref, "dne", "dneCrc");

			Wdbe::setPrtCsi(dbswdbe, ref, "captNotFin", "crccaptNotFin");

			Wdbe::setPrtCsi(dbswdbe, ref, "d", "crcd");
			Wdbe::setPrtCsi(dbswdbe, ref, "strbD", "strbCrcd");

			Wdbe::setPrtCsi(dbswdbe, ref, "crc", "crc");
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'spi'", ref)) {
			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqSpi", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "ackSpi", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "dneSpi", false, "sl", 1, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "spilen", false, "slvdn", 17, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "spisend", false, "slvdn", 8, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "strbSpisend", false, "sl", 1, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "spirecv", false, "slvdn", 8, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "strbSpirecv", false, "sl", 1, "", "", "", "0", false, 0, "");

			Wdbe::setPrtCpr(dbswdbe, ref, "nss", "nss");
			Wdbe::setPrtCpr(dbswdbe, ref, "sclk", "sclk");
			Wdbe::setPrtCpr(dbswdbe, ref, "mosi", "mosi");
			Wdbe::setPrtCpr(dbswdbe, ref, "miso", "miso");

			Wdbe::setPrtCpr(dbswdbe, ref, "reset", "reset");

			Wdbe::setPrtCpr(dbswdbe, ref, "mclk", "mclk");

			Wdbe::setPrtCsi(dbswdbe, ref, "req", "reqSpi");
			Wdbe::setPrtCsi(dbswdbe, ref, "ack", "ackSpi");
			Wdbe::setPrtCsi(dbswdbe, ref, "dne", "dneSpi");

			Wdbe::setPrtCsi(dbswdbe, ref, "len", "spilen");

			Wdbe::setPrtCsi(dbswdbe, ref, "send", "spisend");
			Wdbe::setPrtCsi(dbswdbe, ref, "strbSend", "strbSpisend");

			Wdbe::setPrtCsi(dbswdbe, ref, "recv", "spirecv");
			Wdbe::setPrtCsi(dbswdbe, ref, "strbRecv", "strbSpirecv");
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
