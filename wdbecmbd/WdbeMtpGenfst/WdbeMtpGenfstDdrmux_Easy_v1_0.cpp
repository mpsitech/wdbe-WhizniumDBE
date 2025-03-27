/**
	* \file WdbeMtpGenfstDdrmux_Easy_v1_0.cpp
	* Wdbe operation processor - add A/B buffers, processes and clock domain crossing (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Oct 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpGenfstDdrmux_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpGenfst;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpGenfstDdrmux_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpGenfstDdrmux_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpGenfst* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref, refC;

	WdbeMModule* mdl = NULL;

	WdbeMProcess* prc = NULL;
	ubigint refPrc;

	ubigint refPrcRdWrFirst = 0;
	ubigint refPrcGearFirst = 0;

	bool phyNotAxi;
	unsigned int wAPhy, wDPhy;

	string resetMemclk;
	string memclk;

	bool memclkIntNotExt;
	double ratioMemclk;

	unsigned int wA, wAConst;
	string aConst;
	unsigned int NBeat;
	unsigned int wD;

	unsigned int NRd;
	vector<unsigned int> wDRds;
	vector<string> clkRds;
	vector<double> ratioClkRds;

	unsigned int NWr;
	vector<unsigned int> wDWrs;
	vector<string> clkWrs;
	vector<double> ratioClkWrs;

	ubigint refFstInit, refFstIdle, refFstLocked;
	ubigint refFstCollectA, refFstCollectB;
	ubigint refFstAddr, refFstXfer;
	ubigint refFstWaitFull, refFstDone;
	ubigint refFstResp, refFstFull;

	string mutexsref;
	string chsref;

	vector<string> ss;
	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		phyNotAxi = false;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "phyNotAxi", s)) phyNotAxi = (s == "true");

		wAPhy = 20;
		wDPhy = 16;
		if (phyNotAxi) {
			if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wAPhy", s)) wAPhy = atoi(s.c_str());
			if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wDPhy", s)) wDPhy = atoi(s.c_str());
		};

		resetMemclk = "reset";
		memclk = "memclk";
		Wdbe::getMpa(dbswdbe, refWdbeMModule, "memclk", memclk);
		if (memclk != "mclk") resetMemclk += StrMod::cap(memclk);

		memclkIntNotExt = false;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "memclkIntNotExt", s)) memclkIntNotExt = (s == "true");

		ratioMemclk = 1.0;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "ratioMemclk", s)) ratioMemclk = atof(s.c_str());

		wA = 32;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wA", s)) wA = atoi(s.c_str());

		wAConst = 10;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wAConst", s)) wAConst = atoi(s.c_str());

		aConst = "0000000000";
		Wdbe::getMpa(dbswdbe, refWdbeMModule, "aConst", aConst);

		NBeat = 16;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "NBeat", s)) NBeat = atoi(s.c_str());

		wD = 128;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wD", s)) wD = atoi(s.c_str());

		NRd = 1;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "NRd", s)) NRd = atoi(s.c_str());

		wDRds.resize(NRd, wD);
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wDRds", s)) {
			StrMod::stringToVector(s, ss);
			if (ss.size() == NRd) for (unsigned int i = 0; i < NRd; i++) wDRds[i] = atoi(ss[i].c_str());
		};

		clkRds.resize(NRd, memclk);
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "clkRds", s)) {
			StrMod::stringToVector(s, ss);
			if (ss.size() == NRd) clkRds = ss;
		};

		ratioClkRds.resize(NRd, 1.0);
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "ratioClkRds", s)) {
			StrMod::stringToVector(s, ss);
			if (ss.size() == NRd) for (unsigned int i = 0; i < NRd; i++) ratioClkRds[i] = atof(ss[i].c_str());
		};

		NWr = 1;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "NWr", s)) NWr = atoi(s.c_str());

		wDWrs.resize(NWr, wD);
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wDWrs", s)) {
			StrMod::stringToVector(s, ss);
			if (ss.size() == NWr) for (unsigned int i = 0; i < NWr; i++) wDWrs[i] = atoi(ss[i].c_str());
		};

		clkWrs.resize(NWr, memclk);
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "clkWrs", s)) {
			StrMod::stringToVector(s, ss);
			if (ss.size() == NWr) clkWrs = ss;
		};

		ratioClkWrs.resize(NWr, 1.0);
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "ratioClkWrs", s)) {
			StrMod::stringToVector(s, ss);
			if (ss.size() == NWr) for (unsigned int i = 0; i < NWr; i++) ratioClkWrs[i] = atof(ss[i].c_str());
		};

		ListWdbeMPort prts;
		map<string,ubigint> refsPrts; // by sref

		ubigint refSig;
		uint refNumSig;

		uint refNumVar;

		ubigint refCdcMclk;

		WdbeAVKeylistKey* klsAkey = NULL;
		WdbeJAVKeylistKey* kakJ = NULL;

		string sref;

		dbswdbe->tblwdbemport->loadRstByMdl(refWdbeMModule, false, prts);
		for (unsigned int i = 0; i < prts.nodes.size(); i++) refsPrts[prts.nodes[i]->sref] = prts.nodes[i]->ref;

		refNumSig = Wdbe::getNextSigRefNum(dbswdbe, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule);

		// CDC memclk <-> mclk
		refCdcMclk = 0;
		if (memclk != "mclk") refCdcMclk = dbswdbe->tblwdbemcdc->insertNewRec(NULL, refWdbeMModule, memclk, resetMemclk, "mclk", "reset", ratioMemclk);

		if (NRd > 0) {
			// - read (custom wiring)
			mutexsref = "";
			for (unsigned int i = 0; i < NRd; i++) mutexsref += string(1, (char) (0x61+i));
			mutexsref += "Rd";

			dbswdbe->tblwdbemprocess->insertNewRec(&prc, refWdbeMModule, 0, "read", memclk, resetMemclk, false, "state(init)", true, "read access negotiation");
			if (refPrcRdWrFirst == 0) refPrcRdWrFirst = prc->ref;

			prc->refWdbeMFsm = dbswdbe->tblwdbemfsm->insertNewRec(NULL, prc->ref, VecWdbeVMFsmDbgtaptype::VOID);
			dbswdbe->tblwdbemprocess->updateRec(prc);

			// rdid_t
			dbswdbe->tblwdbeavkeylistkey->insertNewRec(&klsAkey, VecWdbeVKeylist::KLSTWDBEKHDLTYPE, 2, VecWdbeVMaintable::TBLWDBEMPROCESS, prc->ref, true, "rdid_t", "", "", 0, "", "");
			dbswdbe->tblwdbejavkeylistkey->insertNewRec(&kakJ, klsAkey->ref, VecWdbeVLocale::ENUS, "array (0 to 31) of mutex_t", "(others => mutexIdle)");

			klsAkey->refJ = kakJ->ref;
			klsAkey->Title = kakJ->Title;
			klsAkey->Comment = kakJ->Comment;
			dbswdbe->tblwdbeavkeylistkey->updateRec(klsAkey);

			delete kakJ;
			delete klsAkey;

			refFstInit = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 1, "init", false, "");
			refFstIdle = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 2, "idle", false, "");
			refFstLocked = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 3, "locked", true, "");

			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstInit, 1, refFstIdle, "", "syncrst", "", "", "", "", "", "");
			for (unsigned int i = 0; i < NRd; i++) {
				s = "req" + getChsref(false, i, true);
				if (wDRds[i] != wD) s += "_sig";
				s += "='1'";

				if (NRd > 1) {
					s += " and (";

					for (unsigned int j = 0; j < NRd; j++) {
						if ((j + 1) < NRd) s += "(";

						if (j > 0) s += " or ";
						s += mutexsref + "=" + to_string((i+j)%NRd);
						for (unsigned int k = j + 1; k < NRd; k++) {
							unsigned int ksh = (i+k)%NRd;

							s += " and req" + getChsref(false, ksh, true);
							if (wDRds[ksh] != wD) s += "_sig";
							s += "='0'";
						};

						if ((j + 1) < NRd) s += ")";
					};

					s += ")";
				};

				s += " and rdid(ixRdid)=mutexIdle";

				dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstIdle, i + 1, refFstLocked, s, "start" + string(1, (char) (0x41+i)), "", "", "", "", "", "");
			};
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstLocked, 1, refFstIdle, "ddrAXI_arready and ddrAXI_arvalid_sig", "unlock", "", "", "", "", "", "");

			// signals
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "NRd", true, "nat", 0, "", "", "", to_string(NRd), false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, mutexsref, false, "nat", 0, "NRd", "", "", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ackRd", false, "sl", 1, "", "", "", "", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			for (unsigned int i = 0; i < NRd; i++) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ack" + getChsref(false, i, true) + "_sig", false, "sl", 1, "", "", "", "", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_arlen", false, "slvdn", 8, "", "", "", "", false, refsPrts["ddrAXI_arlen"], "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_arvalid", false, "sl", 1, "", "", "", "", false, refsPrts["ddrAXI_arvalid"], "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_rready", false, "sl", 1, "", "", "", "", false, refsPrts["ddrAXI_rready"], "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "rdmutex", false, "mutex_t", 0, "", "", "", "mutexIdle", false, 0, "");

			refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::STRB, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "strbRdlock", false, "sl", 1, "", "", "", "0", false, 0, "");
			if (refCdcMclk != 0) dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdcMclk, refSig, VecWdbeVRMCdcMSignalDir::FTS);

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "rdid", false, "rdid_t", 0, "", "", "", "(others => mutexIdle)", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ixRdid", false, "nat", 0, "0..31", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ixRdidEgr", false, "nat", 0, "0..31", "", "", "0", false, 0, "");

			for (unsigned int i = 0; i < NRd; i++) if (wDRds[i] != wD) {
				// TBD: most likely, these aren't required and can be replaced by ddrAXI_r* directly
				chsref = getChsref(false, i, false);

				refC = dbswdbe->tblwdbecsignal->getNewRef();
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_rdata_sig", false, "slvdn", wD, "", "", "", "", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_rlast_sig", false, "sl", 1, "", "", "", "", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_rresp_sig", false, "slvdn", 2, "", "", "", "", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_rvalid_sig", false, "sl", 1, "", "", "", "", false, 0, "");
			};

			delete prc;
		};

		if (NWr > 0) {
			// - write (custom wiring)
			mutexsref = "";
			for (unsigned int i = 0; i < NWr; i++) mutexsref += string(1, (char) (0x61+i));
			mutexsref += "Wr";

			dbswdbe->tblwdbemprocess->insertNewRec(&prc, refWdbeMModule, 0, "write", memclk, resetMemclk, false, "state(init)", true, "write access negotiation");
			if (refPrcRdWrFirst == 0) refPrcRdWrFirst = prc->ref;

			prc->refWdbeMFsm = dbswdbe->tblwdbemfsm->insertNewRec(NULL, prc->ref, VecWdbeVMFsmDbgtaptype::VOID);
			dbswdbe->tblwdbemprocess->updateRec(prc);

			refFstInit = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 1, "init", false, "");
			refFstIdle = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 2, "idle", false, "");
			refFstLocked = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, 3, "locked", true, "");

			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstInit, 1, refFstIdle, "", "syncrst", "", "", "", "", "", "");
			for (unsigned int i = 0; i < NWr; i++) {
				s = "req" + getChsref(true, i, true);
				if (wDWrs[i] != wD) s += "_sig";
				s += "='1'";

				if (NWr > 1) {
					s += " and (";

					for (unsigned int j = 0; j < NWr; j++) {
						if ((j + 1) < NWr) s += "(";

						if (j > 0) s += " or ";
						s += mutexsref + "=" + to_string((i+j)%NWr);
						for (unsigned int k = j + 1; k < NWr; k++) {
							unsigned int ksh = (i+k)%NWr;

							s += " and req" + getChsref(true, ksh, true);
							if (wDWrs[ksh] != wD) s += "_sig";
							s += "='0'";
						};

						if ((j + 1) < NWr) s += ")";
					};

					s += ")";
				};

				s += " and wrid(ixWrid)='0'";

				dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstIdle, i + 1, refFstLocked, s, "start" + string(1, (char) (0x41+i)), "", "", "", "", "", "");
			};
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstLocked, 1, refFstIdle, "ddrAXI_wready and ddrAXI_wvalid_sig and ddrAXI_wlast_sig", "unlock", "", "", "", "", "", "");

			// signals
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "NWr", true, "nat", 0, "", "", "", to_string(NWr), false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, mutexsref, false, "nat", 0, "NWr", "", "", "0", false, 0, "");
	
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ackWr", false, "sl", 1, "", "", "", "", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			for (unsigned int i = 0; i < NWr; i++) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ack" + getChsref(true, i, true) + "_sig", false, "sl", 1, "", "", "", "", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_awlen", false, "slvdn", 8, "", "", "", "", false, refsPrts["ddrAXI_awlen"], "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_wvalid", false, "sl", 1, "", "", "", "", false, refsPrts["ddrAXI_wvalid"], "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_wlast", false, "sl", 1, "", "", "", "", false, refsPrts["ddrAXI_wlast"], "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_bready", false, "sl", 1, "", "", "", "", false, refsPrts["ddrAXI_bready"], "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "wrmutex", false, "mutex_t", 0, "", "", "", "mutexIdle", false, 0, "");

			refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::STRB, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "strbWrlock", false, "sl", 1, "", "", "", "0", false, 0, "");
			if (refCdcMclk != 0) dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdcMclk, refSig, VecWdbeVRMCdcMSignalDir::FTS);

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "wrid", false, "slvdn", 32, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ixWrid", false, "nat", 0, "0..31", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ixWridIgr", false, "nat", 0, "0..31", "", "", "0", false, 0, "");

			for (unsigned int i = 0; i < NWr; i++) if (wDWrs[i] != wD) {
				// TBD: most likely, these aren't required and can be replaced by ddrAXI_r* directly (in )
				chsref = getChsref(true, i, false);

				refC = dbswdbe->tblwdbecsignal->getNewRef();
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_awready_sig", false, "sl", 1, "", "", "", "", false, 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_wready_sig", false, "sl", 1, "", "", "", "", false, 0, "");
			};

			delete prc;
		};

		if (refPrcRdWrFirst != 0) {
			// mutex_t
			s = "(mutexIdle";
			for (unsigned int i = 0; (i < NRd) || (i < NWr); i++) s += ", mutex" + string(1, (char) (0x41+i));
			s += ")";

			dbswdbe->tblwdbeavkeylistkey->insertNewRec(&klsAkey, VecWdbeVKeylist::KLSTWDBEKHDLTYPE, 1, VecWdbeVMaintable::TBLWDBEMPROCESS, refPrcRdWrFirst, true, "mutex_t", "", "", 0, "", "");
			dbswdbe->tblwdbejavkeylistkey->insertNewRec(&kakJ, klsAkey->ref, VecWdbeVLocale::ENUS, s, "mutexIdle");

			klsAkey->refJ = kakJ->ref;
			klsAkey->Title = kakJ->Title;
			klsAkey->Comment = kakJ->Comment;
			dbswdbe->tblwdbeavkeylistkey->updateRec(klsAkey);

			delete kakJ;
			delete klsAkey;
		};

		// - stats (auto-generated wiring)
		dbswdbe->tblwdbemprocess->insertNewRec(&prc, refWdbeMModule, 0, "stats", "mclk", "reset", false, "", true, "accumulate statistics");
		prc->refWdbeMFsm = dbswdbe->tblwdbemfsm->insertNewRec(NULL, prc->ref, VecWdbeVMFsmDbgtaptype::VOID);
		dbswdbe->tblwdbemprocess->updateRec(prc);

		refC = dbswdbe->tblwdbecfsmstate->getNewRef();
		refFstCollectA = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, 1, "collectA", false, "");
		refFstCollectB = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, 2, "collectB", false, "");

		dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstCollectA, 1, refFstCollectB, "tkclk", "collectA", "", "", "", "", "", "");
		dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstCollectB, 1, refFstCollectA, "!tkclk", "inc", "", "", "", "", "", "");

		// signals
		refC = dbswdbe->tblwdbecsignal->getNewRef();
		for (unsigned int i = 0; i < NRd; i++) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "N" + getChsref(false, i, true), false, "slvdn", 32, "", "", "", "0", false, refsPrts["getStatsN" + getChsref(false, i, true)], "");
		for (unsigned int i = 0; i < NWr; i++) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "N" + getChsref(true, i, true), false, "slvdn", 32, "", "", "", "0", false, refsPrts["getStatsN" + getChsref(true, i, true)], "");
		
		// variables
		refNumVar = 1;

		refC = dbswdbe->tblwdbecvariable->getNewRef();
		dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, refNumVar++, "imax", true, false, "nat", 0, "", "", "10000", false, "1 s");
		dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, refNumVar++, "i", false, false, "nat", 0, "0..imax", "", "0", false, "");

		refC = dbswdbe->tblwdbecvariable->getNewRef();
		for (unsigned int i = 0; i < NRd; i++) dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, refNumVar++, "N" + getChsref(false, i, true) + "_collect", false, false, "slvdn", 32, "", "", "0", false, "");
		for (unsigned int i = 0; i < NWr; i++) dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, refNumVar++, "N" + getChsref(true, i, true) + "_collect", false, false, "slvdn", 32, "", "", "0", false, "");

		delete prc;

		for (unsigned int i = 0; i < NRd; i++) if (wDRds[i] != wD) {
			// - rdXGearIgr (auto-generated wiring)
			chsref = getChsref(false, i, false);

			dbswdbe->tblwdbemprocess->insertNewRec(&prc, refWdbeMModule, 0, chsref + "GearIgr", clkRds[i], "reset" + StrMod::cap(clkRds[i]), false, "", true, chsref + " geared ingress operation");
			if (refPrcGearFirst == 0) refPrcGearFirst = prc->ref;

			prc->refWdbeMFsm = dbswdbe->tblwdbemfsm->insertNewRec(NULL, prc->ref, VecWdbeVMFsmDbgtaptype::VOID);
			dbswdbe->tblwdbemprocess->updateRec(prc);

			refFstIdle = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 1, "idle", false, "");
			refFstAddr = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 2, "addr", false, "");
			refFstXfer = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 3, "xfer", true, "");

			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstIdle, 1, refFstAddr, "rdAReady_cross and not rdAFull", "idle", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstAddr, 1, refFstXfer, "rdAAXI_awredy_sig", "addr", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstXfer, 1, refFstIdle, "i=imax-1 or rdAAXI_rlast_sig", "done", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstXfer, 2, refFstXfer, "else", "inc", "", "", "", "", "", "");

			// signals
			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_araddr_sig", false, "slvdn", wA-wAConst-log2(NBeat)-log2(wD/8), "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_arvalid_sig", false, "sl", 1, "", "state(addr)", "1", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_rready_sig", false, "sl", 1, "", "state(xfer)", "1", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "req" + StrMod::cap(chsref) + "_sig", false, "sl", 1, "", "state(addr;xfer)", "1", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "Full", false, "_bool", 0, "", "", "", "false", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "Buf", false, "burstbuf_t", 0, "", "", "", "", false, 0, "");

			// variables
			dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, 1, "i", false, false, "nat", 0, "0..NBeat-1", "", "0", false, "");

			delete prc;

			// - rdXGearEgr (auto-generated wiring)
			dbswdbe->tblwdbemprocess->insertNewRec(&prc, refWdbeMModule, 0, chsref + "GearEgr", memclk, resetMemclk, false, "", false, chsref + " geared egress operation");

			prc->refWdbeMFsm = dbswdbe->tblwdbemfsm->insertNewRec(NULL, prc->ref, VecWdbeVMFsmDbgtaptype::VOID);
			dbswdbe->tblwdbemprocess->updateRec(prc);

			refFstIdle = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 1, "idle", false, "");
			refFstWaitFull = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 2, "waitFull", false, "");
			refFstXfer = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 3, "xfer", false, "");
			refFstDone = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 4, "done", false, "");

			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstIdle, 1, refFstWaitFull, "rdAAXI_rwvalid", "start", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstWaitFull, 1, refFstXfer, "rdAFull_cross", "waitFull", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstXfer, 1, refFstDone, "rdAAXI_rready_sig", "", "j=jmax", "beatDone", "i=NBeat-1", "burstDone", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstXfer, 2, refFstXfer, "rdAAXI_rready_sig", "", "j=jmax", "beatDone", "else", "nextBeat", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstXfer, 3, refFstXfer, "rdAAXI_rready_sig", "", "else", "nextWord", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstDone, 1, refFstIdle, "not rdAFull_cross", "", "", "", "", "", "", "");

			// signals
			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_arready_oprt", false, "sl", 1, "", "state(idle)", "1", "0", false, refsPrts[chsref + "AXI_arready"], "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_rdata_oprt", false, "slvdn", wDRds[i], "", "", "", "0", false, refsPrts[chsref + "AXI_rdata"], "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_rlast_oprt", false, "sl", 1, "", "", "", "0", false, refsPrts[chsref + "AXI_rlast"], "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_rvalid_oprt", false, "sl", 1, "", "state(xfer)", "1", "0", false, refsPrts[chsref + "AXI_rvalid"], "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "Ready", false, "_bool", 0, "", "", "", "true", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "A", false, "slvdn", wDRds[i], "", "", "", "0", false, 0, "");

			// variables
			refNumVar = 1;

			dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, refNumVar++, "i", false, false, "nat", 0, "0..NBeat-1", "", "0", false, "");

			refC = dbswdbe->tblwdbecvariable->getNewRef();
			s = to_string(wD) + "/" + to_string(wDRds[i]) + "-1";
			dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, refNumVar++, "jmax", true, false, "nat", 0, "", "", s, false, "");
			dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, refNumVar++, "j", false, false, "nat", 0, "0..jmax", "", "0", false, "");

			delete prc;
		};

		for (unsigned int i = 0; i < NWr; i++) if (wDWrs[i] != wD) {
			// - wrXGearIgr (auto-generated wiring)
			chsref = getChsref(true, i, false);

			dbswdbe->tblwdbemprocess->insertNewRec(&prc, refWdbeMModule, 0, chsref + "GearIgr", memclk, resetMemclk, false, "", true, chsref + " geared ingress operation");
			if (refPrcGearFirst == 0) refPrcGearFirst = prc->ref;

			prc->refWdbeMFsm = dbswdbe->tblwdbemfsm->insertNewRec(NULL, prc->ref, VecWdbeVMFsmDbgtaptype::VOID);
			dbswdbe->tblwdbemprocess->updateRec(prc);

			refFstIdle = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 1, "idle", false, "");
			refFstXfer = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 2, "xfer", false, "");
			refFstResp = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 3, "resp", false, "");
			refFstFull = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 4, "full", false, "");

			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstIdle, 1, refFstXfer, "wrAAXI_awvalid", "start", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstXfer, 1, refFstResp, "wrAAXI_wvalid", "xfer", "j=jmax", "beatDone", "i=imax-1", "burstDone", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstXfer, 2, refFstXfer, "wrAAXI_wvalid", "xfer", "j=jmax", "beatDone", "else", "nextBeat", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstXfer, 3, refFstXfer, "wrAAXI_wvalid", "xfer", "else", "nextWord", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstResp, 1, refFstFull, "", "", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstFull, 1, refFstIdle, "(not wrAFillBNotA and not wrAFullA) or (wrAFillBNotA and not wrAFullB)", "", "", "", "", "", "", "");

			// signals
			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_awready_oprt", false, "sl", 1, "", "state(idle)", "1", "0", false, refsPrts[chsref + "AXI_awready"], "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_wready_oprt", false, "sl", 1, "", "state(xfer)", "1", "0", false, refsPrts[chsref + "AXI_wready"], "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "FillBNotA", false, "_bool", 0, "", "", "", "false", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "FullA", false, "_bool", 0, "", "", "", "false", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "FullB", false, "_bool", 0, "", "", "", "false", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "Aa", false, "slvdn", wA-wAConst-log2(NBeat)-log2(wD/8), "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "Abuf", false, "burstbuf_t", 0, "", "", "", "", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "Ba", false, "slvdn", wA-wAConst-log2(NBeat)-log2(wD/8), "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "Bbuf", false, "burstbuf_t", 0, "", "", "", "", false, 0, "");

			// variables
			refNumVar = 1;

			dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, refNumVar++, "i", false, false, "nat", 0, "0..NBeat-1", "", "0", false, "");

			refC = dbswdbe->tblwdbecvariable->getNewRef();
			s = to_string(wD) + "/" + to_string(wDWrs[i]) + "-1";
			dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, refNumVar++, "jmax", true, false, "nat", 0, "", "", s, false, "");
			dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, refNumVar++, "j", false, false, "nat", 0, "0..jmax", "", "0", false, "");

			delete prc;

			// - wrXGearEgr (auto-generated wiring)
			dbswdbe->tblwdbemprocess->insertNewRec(&prc, refWdbeMModule, 0, chsref + "GearEgr", clkWrs[i], "reset" + StrMod::cap(clkWrs[i]), false, "", true, chsref + " geared egress operation");

			prc->refWdbeMFsm = dbswdbe->tblwdbemfsm->insertNewRec(NULL, prc->ref, VecWdbeVMFsmDbgtaptype::VOID);
			dbswdbe->tblwdbemprocess->updateRec(prc);

			refFstIdle = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 1, "idle", false, "");
			refFstAddr = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 2, "addr", false, "");
			refFstXfer = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 3, "xfer", false, "");
			refFstResp = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 4, "resp", false, "");

			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstIdle, 1, refFstAddr, "wrAFillBNotA_cross and wrAFullA_cross not wrADoneA", "startA", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstIdle, 2, refFstAddr, "not wrAFillBNotA_cross and wrAFullB_cross and not wrADoneB", "startB", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstAddr, 1, refFstXfer, "wrAAXI_awready_sig", "addr", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstXfer, 1, refFstResp, "wrAAXI_wready_sig", "", "i=imax-1", "done", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstXfer, 2, refFstXfer, "wrAAXI_wready_sig", "", "else", "next", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstResp, 1, refFstIdle, "", "", "", "", "", "", "", "");

			// signals
			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_awaddr_sig", false, "slvdn", wA-wAConst-log2(NBeat)-log2(wD/8), "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_awvalid_sig", false, "sl", 1, "", "state(addr)", "1", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_wdata_sig", false, "slvdn", wD, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_wlast_sig", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_wvalid_sig", false, "sl", 1, "", "state(xfer)", "1", "0", false, 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "req" + StrMod::cap(chsref) + "_sig", false, "sl", 1, "", "state(addr;xfer)", "1", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "DoneA", false, "_bool", 0, "", "", "", "false", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "DoneB", false, "_bool", 0, "", "", "", "false", false, 0, "");

			// variables
			dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, 1, "i", false, false, "nat", 0, "0..NBeat-1", "", "0", false, "");

			delete prc;
		};

		if (refPrcGearFirst != 0) {
			// burstbuf_t
			dbswdbe->tblwdbeavkeylistkey->insertNewRec(&klsAkey, VecWdbeVKeylist::KLSTWDBEKHDLTYPE, 1, VecWdbeVMaintable::TBLWDBEMPROCESS, refPrcGearFirst, true, "burstbuf_t", "", "", 0, "", "");
			dbswdbe->tblwdbejavkeylistkey->insertNewRec(&kakJ, klsAkey->ref, VecWdbeVLocale::ENUS, "array 0 to NBeat-1 of std_logic_vector(wD-1 downto 0)", "");

			klsAkey->refJ = kakJ->ref;
			klsAkey->Title = kakJ->Title;
			klsAkey->Comment = kakJ->Comment;
			dbswdbe->tblwdbeavkeylistkey->updateRec(klsAkey);

			delete kakJ;
			delete klsAkey;
		};

		// TBD: CDC memclk <-> clkRds/clkWrs

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
string WdbeMtpGenfstDdrmux_Easy_v1_0::getChsref(
			const bool wrNotRd
			, const unsigned int i
			, const bool capNotUncap
		) {
	// exact copy from WdbeMtpCplmstbuDdrmux_Easy_v1_0.cpp
	string s;

	s = string(1, ((char) (0x41 + i)));
	if (!wrNotRd) s = "rd" + s;
	else s = "wr" + s;

	if (capNotUncap) s = StrMod::cap(s);

	return s;
};
// IP cust --- IEND
