/**
	* \file WdbeMtpCplmstbuI2c_Easy_v1_0.cpp
	* Wdbe operation processor - connect I2C master (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jan 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuI2c_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuI2c_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuI2c_Easy_v1_0::run(
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

		refPrcOp = dbswdbe->tblwdbemprocess->insertNewRec(NULL, refWdbeMModule, 0, "op", "mclk", "reset", true, "", false, "main operation");

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'rxtx'", ref)) {
			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqRxtx", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "ackRxtx", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "dneRxtx", false, "sl", 1, "", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "devaddr", false, "slvdn", 8, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "r16Not8", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "d16Not8", false, "sl", 1, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "readNotWrite", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "readAradNotArd", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "writeAdNotArd", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "regaddr", false, "slvdn", 16, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "rxtxSend", false, "slvdn", 16, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "rxtxRecv", false, "slvdn", 16, "", "", "", "0", false, 0, "");

			Wdbe::setGenSrc(dbswdbe, ref, "fMclk", "fMclk");

			Wdbe::setGenSrc(dbswdbe, ref, "clkFastNotStd", "clkFastNotStd");
			Wdbe::setGenSrc(dbswdbe, ref, "clkFastplusNotFast", "clkFastplusNotFast");

			Wdbe::setPrtCpr(dbswdbe, ref, "reset", "reset");

			Wdbe::setPrtCpr(dbswdbe, ref, "mclk", "mclk");

			Wdbe::setPrtCsi(dbswdbe, ref, "req", "reqRxtx");
			Wdbe::setPrtCsi(dbswdbe, ref, "ack", "ackRxtx");
			Wdbe::setPrtCsi(dbswdbe, ref, "dne", "dneRxtx");

			Wdbe::setPrtCsi(dbswdbe, ref, "devaddr", "devaddr");

			Wdbe::setPrtCsi(dbswdbe, ref, "r16Not8", "r16Not8");
			Wdbe::setPrtCsi(dbswdbe, ref, "d16Not8", "d16Not8");

			Wdbe::setPrtCsi(dbswdbe, ref, "readNotWrite", "readNotWrite");
			Wdbe::setPrtCsi(dbswdbe, ref, "readAradNotArd", "readAradNotArd");
			Wdbe::setPrtCsi(dbswdbe, ref, "writeAdNotArd", "writeAdNotArd");
			Wdbe::setPrtCsi(dbswdbe, ref, "regaddr", "regaddr");

			Wdbe::setPrtCsi(dbswdbe, ref, "send", "rxtxSend");
			Wdbe::setPrtCsi(dbswdbe, ref, "recv", "rxtxRecv");

			Wdbe::setPrtCpr(dbswdbe, ref, "scl", "scl");

			refC = 0; dbswdbe->loadRefBySQL("SELECT refWdbeCPort FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(ref) + " AND sref = 'sda_in'", refC);
			if (refC) {
				Wdbe::setPrtCpr(dbswdbe, ref, "sda_in", "sda_in");
				Wdbe::setPrtCpr(dbswdbe, ref, "sda_out", "sda_out");
				Wdbe::setPrtCpr(dbswdbe, ref, "sda_dir", "sda_dir");

				dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'sda'");

			} else {
				Wdbe::setPrtCpr(dbswdbe, ref, "sda", "sda");

				refC = 0; dbswdbe->loadRefBySQL("SELECT refWdbeCPort FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'sda_in'", refC);
				if (refC != 0) dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE refWdbeCPort = " + to_string(refC));
			};
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
