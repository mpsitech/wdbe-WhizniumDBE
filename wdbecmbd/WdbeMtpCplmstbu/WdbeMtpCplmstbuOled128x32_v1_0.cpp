/**
	* \file WdbeMtpCplmstbuOled128x32_v1_0.cpp
	* Wdbe operation processor - connect SPI interface (implementation)
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

#include "WdbeMtpCplmstbuOled128x32_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuOled128x32_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuOled128x32_v1_0::run(
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

	ubigint refPrcOp;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		mdlNum = 1;

		refPrcOp = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "op", "mclk", "reset", true, "", false, "main operation");

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'spi'", ref)) {
			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqSpi", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "ackSpi", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "dneSpi", false, "sl", 1, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "spilen", false, "slvdn", 17, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "spisend", false, "slvdn", 8, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "strbSpisend", false, "sl", 1, "", "", "", "0", false, 0, "");

			Wdbe::setGenSrc(dbswdbe, ref, "fMclk", "fMclk");

			Wdbe::setGenDfv(dbswdbe, ref, "fSclk", "5000000");

			Wdbe::setPrtCpr(dbswdbe, ref, "sclk", "sclk");
			Wdbe::setPrtCpr(dbswdbe, ref, "mosi", "mosi");
			Wdbe::setPrtDfv(dbswdbe, ref, "miso", "0");

			Wdbe::setPrtCsi(dbswdbe, ref, "reset", "reset");

			Wdbe::setPrtCsi(dbswdbe, ref, "mclk", "mclk");

			Wdbe::setPrtCsi(dbswdbe, ref, "req", "reqSpi");
			Wdbe::setPrtCsi(dbswdbe, ref, "ack", "ackSpi");
			Wdbe::setPrtCsi(dbswdbe, ref, "dne", "dneSpi");

			Wdbe::setPrtCsi(dbswdbe, ref, "len", "spilen");

			Wdbe::setPrtCsi(dbswdbe, ref, "send", "spisend");
			Wdbe::setPrtCsi(dbswdbe, ref, "strbSend", "strbSpisend");
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
