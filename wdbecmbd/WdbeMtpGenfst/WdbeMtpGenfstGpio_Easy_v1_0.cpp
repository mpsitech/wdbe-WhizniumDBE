/**
	* \file WdbeMtpGenfstGpio_Easy_v1_0.cpp
	* Wdbe operation processor - add process, signals and command handshake (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 17 Oct 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpGenfstGpio_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpGenfst;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpGenfstGpio_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpGenfstGpio_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpGenfst* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	unsigned int w = 32;
	bool threeNotInout = false;
	bool bidirNotUnidir = false;
	bool inNotOut = false;

	bool cmdConfig, cmdGet, cmdSet;

	string srefIobuf;

	ubigint ref, refC;

	uint mdlNum;

	WdbeMProcess* prc = NULL;

	ubigint refFstInit, refFstInv, refFstRun;

	ubigint refPrtAckInvConfig = 0;
	ubigint refPrtGetBits = 0;
	ubigint refPrtAckInvSet = 0;

	ubigint refPrtBitsOut = 0;
	ubigint refPrtBitsTri = 0;

	string Syncrst, Comb, Onval, Cond1;

	string s;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "w", s)) w = atoi(s.c_str());
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "threeNotInout", s)) threeNotInout = (s == "true");
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "bidirNotUnidir", s)) bidirNotUnidir = (s == "true");
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "inNotOut", s)) inNotOut = (s == "true");

	cmdConfig = bidirNotUnidir;
	cmdGet = !(!bidirNotUnidir && !inNotOut);
	cmdSet = !(!bidirNotUnidir && inNotOut);

	if (dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " ORDER BY ref ASC LIMIT 1 OFFSET 0", srefIobuf)) srefIobuf = srefIobuf.substr(0, srefIobuf.length() - 1);

	// - ports
	mdlNum = Wdbe::getNextPrtMdlNum(dbswdbe, refWdbeMModule);

	dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'ackInvConfig'", refPrtAckInvConfig);
	dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'getBits'", refPrtGetBits);
	dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'ackInvSet'", refPrtAckInvSet);

	dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'bits_out'", refPrtBitsOut);
	dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'bits_tri'", refPrtBitsTri);

	// - main operation FSM
	Syncrst = "state(init)";
	if (cmdConfig || cmdSet) {
		Syncrst += " or (state(!inv) and ";

		if (cmdConfig && cmdSet) Syncrst += "(reqInvConfig or reqInvSet)";
		else if (cmdConfig) Syncrst += "reqInvConfig";
		else Syncrst += "reqInvSet";

		Syncrst += ")";
	};
	dbswdbe->tblwdbemprocess->insertNewRec(&prc, refWdbeMModule, 0, "op", "mclk", "reset", false, Syncrst, false, "main operation");

	prc->refWdbeMFsm = dbswdbe->tblwdbemfsm->insertNewRec(NULL, prc->ref, VecWdbeVMFsmDbgtaptype::VOID);
	dbswdbe->tblwdbemprocess->updateRec(prc);

	refFstInit = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 1, "init", false, "");
	if (cmdConfig || cmdSet) refFstInv = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 2, "inv", false, "");
	refFstRun = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 3, "run", false, "");

	if (cmdConfig || cmdSet) {
		if (cmdConfig) dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstInit, 1, refFstInv, "reqInvConfig", "invConfig", "", "", "", "", "", "");
		if (cmdSet) dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstInit, 2, refFstInv, "reqInvSet", "invSet", "", "", "", "", "", "");
		dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstInit, 3, refFstRun, "else", "syncrst", "", "", "", "", "", "");

	} else dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstInit, 1, refFstRun, "", "syncrst", "", "", "", "", "", "");

	if (cmdConfig || cmdSet) {
		Cond1 = "";
		if (cmdConfig) Cond1 = "(!reqInvConfig and ackInvConfig_sig)";
		if (cmdConfig && cmdSet) Cond1 += " or ";
		if (cmdSet) Cond1 += "(!reqInvSet and ackInvSet_sig)";

		dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstInv, 1, refFstRun, Cond1, "inv", "", "", "", "", "", "");
	};

	// - signals
	mdlNum = 1;

	dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "w", true, "nat", 0, "", "", "", to_string(w), 0, "");

	refC = dbswdbe->tblwdbecsignal->getNewRef();
	if (cmdConfig) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ackInvConfig", false, "sl", 1, "", "", "", "0", refPrtAckInvConfig, "");
	if (cmdSet) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ackInvSet", false, "sl", 1, "", "", "", "0", refPrtAckInvSet, "");

	if (cmdGet) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "getBits", false, "slvdn", w, "", "", "", "0", refPrtGetBits, "");

	refC = dbswdbe->tblwdbecsignal->getNewRef();

	if (!(!bidirNotUnidir && inNotOut)) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "bitsOut_sig", false, "slvdn", w, "", "", "", "0", refPrtBitsOut, "");
	if (bidirNotUnidir) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "bitsDir_sig", false, "slvdn", w, "", "", "", "0", refPrtBitsTri, "");

	if (!(!bidirNotUnidir && !inNotOut)) {
		if (!threeNotInout) {
			Comb = "";
			Onval = "";
		} else {
			Comb = "*";
			Onval = "bits_in";
		};
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "bitsIn_sig", false, "slvdn", w, "", Comb, Onval, "", 0, "");
	};

	delete prc;
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
