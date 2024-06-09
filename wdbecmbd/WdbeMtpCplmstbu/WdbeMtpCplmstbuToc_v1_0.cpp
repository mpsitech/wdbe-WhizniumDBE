/**
	* \file WdbeMtpCplmstbuToc_v1_0.cpp
	* Wdbe operation processor - connect memory (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 7 Feb 2024
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuToc_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuToc_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuToc_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref, refC;

	uint mdlNum;

	ubigint refPrcOp;

	mdlNum = 1;

	refPrcOp = dbswdbe->tblwdbemprocess->insertNewRec(NULL, refWdbeMModule, 0, "op", "mclk", "reset", true, "", false, "main operation");

	if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'reg'", ref)) {
		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqClearAll", false, "sl", 1, "", "", "", "0", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "ackClearAll", false, "sl", 1, "", "", "", "", false, 0, "");

		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqSetOne", false, "sl", 1, "", "", "", "0", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "ackSetOne", false, "sl", 1, "", "", "", "", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "setOneIx", false, "slvdn", 16, "", "", "", "0", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "setOneOne", false, "sl", 1, "", "", "", "0", false, 0, "");

		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqGetOne", false, "sl", 1, "", "", "", "0", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "ackGetOne", false, "sl", 1, "", "", "", "", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "getOneIx", false, "slvdn", 16, "", "", "", "0", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "getOneOne", false, "sl", 1, "", "", "", "", false, 0, "");

		refC = dbswdbe->tblwdbecsignal->getNewRef();
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "reqFindFirstOne", false, "sl", 1, "", "", "", "0", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "ackFindFirstOne", false, "sl", 1, "", "", "", "", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "findFirstOneIx1", false, "slvdn", 16, "", "", "", "0", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "findFirstOneIxFirstOne", false, "slvdn", 16, "", "", "", "", false, 0, "");

		Wdbe::setGenDfv(dbswdbe, ref, "clearOneNotZero", "true");

		Wdbe::setPrtCpr(dbswdbe, ref, "reset", "reset");
		Wdbe::setPrtCpr(dbswdbe, ref, "mclk", "mclk");

		Wdbe::setPrtCsi(dbswdbe, ref, "reqClearAll", "reqClearAll");
		Wdbe::setPrtCsi(dbswdbe, ref, "ackClearAll", "ackClearAll");

		Wdbe::setPrtCsi(dbswdbe, ref, "reqSetOne", "reqSetOne");
		Wdbe::setPrtCsi(dbswdbe, ref, "ackSetOne", "ackSetOne");
		Wdbe::setPrtCsi(dbswdbe, ref, "setOneIx", "setOneIx");
		Wdbe::setPrtCsi(dbswdbe, ref, "setOneOne", "setOneOne");

		Wdbe::setPrtCsi(dbswdbe, ref, "reqGetOne", "reqGetOne");
		Wdbe::setPrtCsi(dbswdbe, ref, "ackGetOne", "ackGetOne");
		Wdbe::setPrtCsi(dbswdbe, ref, "getOneIx", "getOneIx");
		Wdbe::setPrtCsi(dbswdbe, ref, "getOneOne", "getOneOne");

		Wdbe::setPrtCsi(dbswdbe, ref, "reqFindFirstOne", "reqFindFirstOne");
		Wdbe::setPrtCsi(dbswdbe, ref, "ackFindFirstOne", "ackFindFirstOne");
		Wdbe::setPrtDfv(dbswdbe, ref, "findFirstOneIx0", "0");
		Wdbe::setPrtCsi(dbswdbe, ref, "findFirstOneIx1", "findFirstOneIx1");
		Wdbe::setPrtCsi(dbswdbe, ref, "findFirstOneIxFirstOne", "findFirstOneIxFirstOne");

		Wdbe::setPrtDfv(dbswdbe, ref, "enMemB", "0");

		Wdbe::setPrtDfv(dbswdbe, ref, "aMemB", "0");
	};

	if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'map'", ref)) {
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "enMap", false, "sl", 1, "", "", "", "0", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "weMap", false, "slvdn", 1, "", "", "", "0", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "aMap", false, "slvdn", 14, "", "", "", "", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "drdMap", false, "slvdn", 16, "", "", "", "", false, 0, "");
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "dwrMap", false, "slvdn", 16, "", "", "", "", false, 0, "");

		Wdbe::setPrtCpr(dbswdbe, ref, "clkA", "mclk");

		Wdbe::setPrtCsi(dbswdbe, ref, "enA", "enMap");
		Wdbe::setPrtCsi(dbswdbe, ref, "weA", "weMap");

		Wdbe::setPrtCsi(dbswdbe, ref, "addrA", "aMap");
		Wdbe::setPrtCsi(dbswdbe, ref, "doutA", "drdMap");
		Wdbe::setPrtCsi(dbswdbe, ref, "dinA", "dwrMap");
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
