/**
	* \file WdbeMtpModbscbuSpifwd_v1_0.cpp
	* Wdbe operation processor - connect buffers, SPI interface, CRC and timeout (implementation)
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

#include "WdbeMtpModbscbuSpifwd_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModbscbu;

/******************************************************************************
 namespace WdbeMtpModbscbuSpifwd_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModbscbuSpifwd_v1_0::run(
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

	ubigint refPrcOp;
	ubigint refPrcRdbufB, refPrcRead;
	ubigint refPrcWrbufB, refPrcWrite;

	string size;
	utinyint w;

	string s;
	size_t ptr;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		mdlNum = 1;

		refPrcOp = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "op", "mclk", "reset", true, "", false, "main operation");

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'rdbuf'", ref)) {
			refPrcRdbufB = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "rdbufB", "mclk", "reset", true, "", false, "rdbuf outward/hostif-facing operation");
			refPrcRead = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "read", "mclk", "reset", true, "", false, "read command");

			if (dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeMImbuf WHERE refWdbeMModule = " + to_string(ref), s)) {
				// ex. qcdifToHostif -> RdbufToHostif
				s = StrMod::cap(s);
				ptr = s.find("To");
				if (ptr != string::npos) s = s.substr(ptr);
				s = "Rdbuf" + s;

				w = 11;
				if (Wdbe::getMpa(dbswdbe, ref, "sizeRdbuf", size)) w = Wdbe::valToWidth(1024*atoi(size.c_str())-1);

				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcRead, 0, "enRdbuf", false, "sl", 1, "", "", "", "0", false, 0, "");

				refC = dbswdbe->tblwdbecsignal->getNewRef();
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcRead, 0, "aRdbuf_vec", false, "slvdn", w, "", "", "", "0", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "dRdbuf", false, "slvdn", 8, "", "", "", "0", false, 0, "");

				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcRdbufB, 0, "enRdbufB", false, "sl", 1, "", "", "", "0", false, 0, "");

				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcRdbufB, 0, "aRdbufB_vec", false, "slvdn", w, "", "", "", "0", false, 0, "");

				Wdbe::setPrtCsi(dbswdbe, ref, "clkA", "mclk");

				Wdbe::setPrtCsi(dbswdbe, ref, "enA", "enRdbuf");

				Wdbe::setPrtCsi(dbswdbe, ref, "aA", "aRdbuf_vec");
				Wdbe::setPrtCsi(dbswdbe, ref, "dwrA", "dRdbuf");

				Wdbe::setPrtCsi(dbswdbe, ref, "clkB", "mclk");

				Wdbe::setPrtCsi(dbswdbe, ref, "enB", "enRdbufB");

				Wdbe::setPrtCsi(dbswdbe, ref, "aB", "aRdbufB_vec");
				Wdbe::setPrtCpr(dbswdbe, ref, "drdB", "d" + s);
			};
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'wrbuf'", ref)) {
			refPrcWrbufB = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "wrbufB", "mclk", "reset", true, "", false, "wrbuf outward/hostif-facing operation");
			refPrcWrite = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "write", "mclk", "reset", true, "", false, "write command");

			if (dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeMImbuf WHERE refWdbeMModule = " + to_string(ref), s)) {
				// ex. hostifToQcdif -> WrbufFromHostif
				s = StrMod::cap(s);
				ptr = s.find("To");
				if (ptr != string::npos) s = "From" + s.substr(0, ptr);
				s = "Wrbuf" + s;

				w = 11;
				if (Wdbe::getMpa(dbswdbe, ref, "sizeWrbuf", size)) w = Wdbe::valToWidth(1024*atoi(size.c_str())-1);

				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcWrite, 0, "enWrbuf", false, "sl", 1, "", "", "", "0", false, 0, "");

				refC = dbswdbe->tblwdbecsignal->getNewRef();
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcWrite, 0, "aWrbuf_vec", false, "slvdn", w, "", "", "", "0", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "dWrbuf", false, "slvdn", 8, "", "", "", "0", false, 0, "");

				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcWrbufB, 0, "enWrbufB", false, "sl", 1, "", "", "", "0", false, 0, "");

				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcWrbufB, 0, "aWrbufB_vec", false, "slvdn", w, "", "", "", "0", false, 0, "");

				Wdbe::setPrtCsi(dbswdbe, ref, "clkA", "mclk");

				Wdbe::setPrtCsi(dbswdbe, ref, "enA", "enWrbuf");

				Wdbe::setPrtCsi(dbswdbe, ref, "aA", "aWrbuf_vec");
				Wdbe::setPrtCsi(dbswdbe, ref, "drdA", "dWrbuf");

				Wdbe::setPrtCsi(dbswdbe, ref, "clkB", "mclk");

				Wdbe::setPrtCsi(dbswdbe, ref, "enB", "enWrbufB");

				Wdbe::setPrtCsi(dbswdbe, ref, "aB", "aWrbufB_vec");
				Wdbe::setPrtCpr(dbswdbe, ref, "dwrB", "d" + s);
			};
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'crc'", ref)) {
			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqCrc", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "ackCrc", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "dneCrc", false, "sl", 1, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "crccaptNotFin", false, "sl", 1, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "crcd", false, "slvdn", 8, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::STRB, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "strbCrcd", false, "sl", 1, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "crc", false, "slvdn", 16, "", "", "", "0", false, 0, "");

			Wdbe::setGenSrc(dbswdbe, ref, "poly", "crcpoly");

			Wdbe::setPrtCsi(dbswdbe, ref, "reset", "reset");

			Wdbe::setPrtCsi(dbswdbe, ref, "mclk", "mclk");

			Wdbe::setPrtCpr(dbswdbe, ref, "fastclk", "fastclk");

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
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqSpi", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "ackSpi", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "dneSpi", false, "sl", 1, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "spilen", false, "slvdn", 17, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "spisend", false, "slvdn", 8, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "strbSpisend", false, "sl", 1, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "spirecv", false, "slvdn", 8, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "strbSpirecv", false, "sl", 1, "", "", "", "0", false, 0, "");

			Wdbe::setGenSrc(dbswdbe, ref, "fMclk", "fMclk");

			Wdbe::setGenSrc(dbswdbe, ref, "nssByteNotXfer", "nssByteNotXfer");

			Wdbe::setGenSrc(dbswdbe, ref, "fSclk", "fSclk");
			Wdbe::setGenSrc(dbswdbe, ref, "Nstop", "Nstop");

			Wdbe::setPrtCpr(dbswdbe, ref, "nss", "nss");
			Wdbe::setPrtCpr(dbswdbe, ref, "sclk", "sclk");
			Wdbe::setPrtCpr(dbswdbe, ref, "mosi", "mosi");
			Wdbe::setPrtCpr(dbswdbe, ref, "miso", "miso");

			Wdbe::setPrtCsi(dbswdbe, ref, "reset", "reset");

			Wdbe::setPrtCsi(dbswdbe, ref, "mclk", "mclk");

			Wdbe::setPrtCsi(dbswdbe, ref, "req", "reqSpi");
			Wdbe::setPrtCsi(dbswdbe, ref, "ack", "ackSpi");
			Wdbe::setPrtCsi(dbswdbe, ref, "dne", "dneSpi");

			Wdbe::setPrtCsi(dbswdbe, ref, "len", "spilen");

			Wdbe::setPrtCsi(dbswdbe, ref, "send", "spisend");
			Wdbe::setPrtCsi(dbswdbe, ref, "strbSend", "strbSpisend");

			Wdbe::setPrtCsi(dbswdbe, ref, "recv", "spirecv");
			Wdbe::setPrtCsi(dbswdbe, ref, "strbRecv", "strbSpirecv");
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'wakeup'", ref)) {
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "wurestart", false, "sl", 1, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "wakeup", false, "sl", 1, "", "", "", "0", false, 0, "");

			Wdbe::setGenSrc(dbswdbe, ref, "twait", "dtPing");

			Wdbe::setPrtCsi(dbswdbe, ref, "reset", "reset");

			Wdbe::setPrtCsi(dbswdbe, ref, "mclk", "mclk");

			Wdbe::setPrtCsi(dbswdbe, ref, "tkclk", "tkclk");

			Wdbe::setPrtCsi(dbswdbe, ref, "restart", "wurestart");
			Wdbe::setPrtCsi(dbswdbe, ref, "timeout", "wakeup");
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
