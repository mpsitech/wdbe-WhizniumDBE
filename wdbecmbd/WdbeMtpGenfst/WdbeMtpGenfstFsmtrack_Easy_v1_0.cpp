/**
	* \file WdbeMtpGenfstFsmtrack_Easy_v1_0.cpp
	* Wdbe operation processor - add clock domain crossing (implementation)
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

#include "WdbeMtpGenfstFsmtrack_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpGenfst;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpGenfstFsmtrack_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpGenfstFsmtrack_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpGenfst* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint refCdc, refSig;

	uint mdlNum;

	uint ixVDir;

	string resetTrkclk, trkclk;
	double ratioTrkclk;

	string trigs;

	vector<string> ss, ss2;
	string s;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "trkclk", trkclk)) if (trkclk != "mclk") if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "ratioTrkclk", s)) {
		resetTrkclk = "reset" + StrMod::cap(trkclk);
		ratioTrkclk = atof(s.c_str());

		if (ratioTrkclk >= 1.0) refCdc = dbswdbe->tblwdbemcdc->insertNewRec(NULL, refWdbeMModule, trkclk, resetTrkclk, "mclk", "reset", ratioTrkclk);
		else refCdc = dbswdbe->tblwdbemcdc->insertNewRec(NULL, refWdbeMModule, "mclk", "reset", trkclk, resetTrkclk, 1.0/ratioTrkclk);

		mdlNum = Wdbe::getNextSigRefNum(dbswdbe, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule);

		// - mclk to trkclk
		if (ratioTrkclk >= 1.0) ixVDir = VecWdbeVRMCdcMSignalDir::STF;
		else ixVDir = VecWdbeVRMCdcMSignalDir::FTS;

		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "enCntbufB_sig", false, "sl", 1, "", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);
		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "aCntbufB", false, "nat", 0, "0..255", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);

		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "tixVCapture", false, "slvdn", 8, "", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);
		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "staTixVTrigger", false, "slvdn", 8, "", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);
		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "stoTixVTrigger", false, "slvdn", 8, "", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);

		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::STRB, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "strbStart", false, "sl", 1, "", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);
		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::STRB, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "strbStop", false, "sl", 1, "", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);

		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "reqFstoccbufBToFirstClear", false, "sl", 1, "", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);
		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "reqOpClear", false, "sl", 1, "", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);
		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "reqSeqbufBToSeqClear", false, "sl", 1, "", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);

		// triggers based on port inputs: signals defined here will not exist but the CDC code will capture the corresponding port all the same
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "trigs", trigs)) {
			StrMod::stringToVector(trigs, ss, ';');

			for (unsigned int i = 0; i < ss.size(); i++) {
				StrMod::stringToVector(ss[i], ss2, '.');

				if (ss2.size() == 2) if (ss2[1] == "cdc") {
					refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, ss2[0], false, "sl", 1, "", "", "", "", 0, "");
					dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);
				};
			};
		};

		// - trkclk to mclk
		if (ratioTrkclk >= 1.0) ixVDir = VecWdbeVRMCdcMSignalDir::FTS;
		else ixVDir = VecWdbeVRMCdcMSignalDir::STF;

		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "rdyCount", false, "sl", 1, "", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);
		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "dneCount", false, "sl", 1, "", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);

		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "rdyFirst", false, "sl", 1, "", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);
		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "dneFirst", false, "sl", 1, "", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);

		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "rdySeq", false, "sl", 1, "", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);
		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "dneSeq", false, "sl", 1, "", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);
		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "TCapt", false, "slvdn", 32, "", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);
		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "ptr0Seqbuf", false, "nat", 0, "0..sizeSeqbuf/4-1", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);

		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "drdCntbufB", false, "slvdn", 32, "", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);

		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "start", false, "sl", 1, "", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);
		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "stop", false, "sl", 1, "", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);

		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "ackFstoccbufBToFirstClear", false, "sl", 1, "", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);
		refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "ackSeqbufBToSeqClear", false, "sl", 1, "", "", "", "", 0, "");
		dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdc, refSig, ixVDir);
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
