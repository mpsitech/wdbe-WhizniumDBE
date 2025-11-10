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
	ubigint refPrcRdGearFirst = 0;
	ubigint refPrcWrGearFirst = 0;

	bool phyNotAxi;
	unsigned int wAPhy, wDPhy;

	string resetMemclk;
	string memclk;

	bool memclkIntNotExt;
	double ratioMemclk;

	unsigned int wA, wAConst;
	string aConst;
	unsigned int wD;

	unsigned int NRd;
	vector<bool> flexNBeatRds;
	unsigned int NBeatRd;
	vector<unsigned int> wDRds;
	vector<string> clkRds;
	vector<double> ratioClkRds;
	bool rdflex, rdgear;

	unsigned int NWr;
	vector<bool> flexNBeatWrs;
	unsigned int NBeatWr;
	vector<unsigned int> wDWrs;
	vector<string> clkWrs;
	vector<double> ratioClkWrs;
	bool wrflex, wrgear;

	ubigint refFstInit, refFstIdle, refFstLocked;
	ubigint refFstCollectA, refFstCollectB;
	ubigint refFstAddr, refFstXfer;
	ubigint refFstWaitFull, refFstFull;

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

		wD = 128;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wD", s)) wD = atoi(s.c_str());

		rdflex = false;
		rdgear = false;

		NRd = 1;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "NRd", s)) NRd = atoi(s.c_str());

		flexNBeatRds.resize(NRd, false);
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "flexNBeatRds", s)) {
			StrMod::stringToVector(s, ss);
			if (ss.size() == NRd)
				for (unsigned int i = 0; i < NRd; i++)
					if (ss[i] == "true") {
						flexNBeatRds[i] = true;
						rdflex = true;
					};
		};

		NBeatRd = 16;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "NBeatRd", s)) NBeatRd = atoi(s.c_str());

		wDRds.resize(NRd, wD);
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wDRds", s)) {
			StrMod::stringToVector(s, ss);

			if (ss.size() == NRd) {
				for (unsigned int i = 0; i < NRd; i++) {
					wDRds[i] = atoi(ss[i].c_str());
					if (wDRds[i] != wD) rdgear = true;
				};
			};
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

		if (rdgear) {
			for (unsigned int i = 0; i < NRd; i++) flexNBeatRds[i] = false;
			rdflex = false;
		};

		wrflex = false;
		wrgear = false;

		NWr = 1;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "NWr", s)) NWr = atoi(s.c_str());

		flexNBeatWrs.resize(NWr, false);
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "flexNBeatWrs", s)) {
			StrMod::stringToVector(s, ss);
			if (ss.size() == NWr)
			for (unsigned int i = 0; i < NWr; i++)
				if (ss[i] == "true") {
					flexNBeatWrs[i] = true;
					wrflex = true;
				};
		};

		NBeatWr = 16;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "NBeatWr", s)) NBeatWr = atoi(s.c_str());

		wDWrs.resize(NWr, wD);
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wDWrs", s)) {
			StrMod::stringToVector(s, ss);

			if (ss.size() == NWr) {
				for (unsigned int i = 0; i < NWr; i++) {
					wDWrs[i] = atoi(ss[i].c_str());
					if (wDWrs[i] != wD) wrgear = true;
				};
			};
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

		if (wrgear) {
			for (unsigned int i = 0; i < NWr; i++) flexNBeatWrs[i] = false;
			wrflex = false;
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

		// global constants
		if (rdgear || wrgear) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "wD", true, "nat", 0, "", "", "", to_string(wD), 0, "");
	
		refC = dbswdbe->tblwdbecsignal->getNewRef();
		if (!rdflex) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "NBeatRd", true, "nat", 0, "", "", "", to_string(NBeatRd), 0, "");
		if (!wrflex) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "NBeatWr", true, "nat", 0, "", "", "", to_string(NBeatWr), 0, "");

		if (NRd > 0) {
			// -- read (custom wiring)
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
						if (j > 0) s += " or ";

						if ((j + 1) < NRd) s += "(";

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

			// - signals
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "NRd", true, "nat", 0, "", "", "", to_string(NRd), 0, "");

			// ar
			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_arid", false, "slvdn", 6, "", "*", "0", "", refsPrts["ddrAXI_arid"], "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_araddr", false, "slvdn", wA, "", "*", "", "", refsPrts["ddrAXI_araddr"], "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_arburst", false, "slvdn", 2, "", "*", "01", "", refsPrts["ddrAXI_arburst"], "INCR burst type");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_arcache", false, "slvdn", 4, "", "*", "0000", "", refsPrts["ddrAXI_arcache"], "device non-bufferable memory type");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_arlen_sig", false, "slvdn", 8, "", "*", (rdflex) ? "" : "std_logic_vector(to_unsigned(NBeatRd - 1, 8))", "", refsPrts["ddrAXI_arlen"], "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_arlock", false, "slvdn", 1, "", "*", "0", "", refsPrts["ddrAXI_arlock"], "non-exclusive access");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_arprot", false, "slvdn", 3, "", "*", "010", "", refsPrts["ddrAXI_arprot"], "unprivileged, non-secure data access");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_arqos", false, "slvdn", 4, "", "*", "1101", "", refsPrts["ddrAXI_arqos"], "not participating in QoS scheme");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_arregion", false, "slvdn", 4, "", "*", "0000", "", refsPrts["ddrAXI_arregion"], "region feature not used");

			s = "000";
			if (wD == 32) s = "010";
			else if (wD == 64) s = "011";
			else if (wD == 128) s = "100";
			else if (wD == 256) s = "101";
			else if (wD == 512) s = "110";
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_arsize", false, "slvdn", 3, "", "*", s, "", refsPrts["ddrAXI_arsize"], to_string(wD) + "-bit wide transfers");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_arvalid_sig", false, "sl", 1, "", "*", "", "", refsPrts["ddrAXI_arvalid"], "");

			// r
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_rready_sig", false, "sl", 1, "", "*", "", "", refsPrts["ddrAXI_rready"], "");

			// mux
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, mutexsref, false, "nat", 0, "NRd", "", "", "0", 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ackRd", false, "sl", 1, "", "state(locked)", "1", "0", 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			for (unsigned int i = 0; i < NRd; i++)
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, (wDRds[i] != wD) ? VecWdbeVMSignalBasetype::OTH : VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++,
							VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ack" + getChsref(false, i, true) + ((wDRds[i] != wD) ? "_sig" : ""), false, "sl", 1, "", "rdmutex=mutex" + string(1, (char) (0x41+i)), "ackRd", "0",
							(wDRds[i] != wD) ? 0 : refsPrts["ack" + getChsref(false, i, true)], "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "rdmutex", false, "mutex_t", 0, "", "", "", "mutexIdle", 0, "");

			refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::STRB, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "strbRdlock", false, "sl", 1, "", "", "", "0", 0, "");
			if (refCdcMclk != 0) dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdcMclk, refSig, VecWdbeVRMCdcMSignalDir::FTS);

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "rdid", false, "rdid_t", 0, "", "", "", "(others => mutexIdle)", 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ixRdid", false, "nat", 0, "0..31", "", "", "0", 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ixRdidEgr", false, "nat", 0, "0..31", "", "", "0", 0, "");

			// per read channel
			for (unsigned int i = 0; i < NRd; i++) if (wDRds[i] != wD) {
				chsref = getChsref(false, i, false);

				refC = dbswdbe->tblwdbecsignal->getNewRef();
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_arready_sig", false, "sl", 1, "", "rdmutex=mutex" + string(1, (char) (0x41+i)), "ddrAXI_arready", "0", 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_rdata_sig", false, "slvdn", wD, "", "*", "ddrAXI_rdata", "0", 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_rlast_sig", false, "sl", 1, "", "*", "ddrAXI_rlast", "1", 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_rvalid_sig", false, "sl", 1, "", "rdmutex=mutex" + string(1, (char) (0x41+i)), "ddrAXI_rvalid", "0", 0, "");
			};

			delete prc;
		};

		if (NWr > 0) {
			// -- write (custom wiring)
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
						if (j > 0) s += " or ";

						if ((j + 1) < NWr) s += "(";

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

			// - signals
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "NWr", true, "nat", 0, "", "", "", to_string(NWr), 0, "");

			// aw
			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_awid", false, "slvdn", 6, "", "*", "0", "", refsPrts["ddrAXI_awid"], "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_awaddr", false, "slvdn", wA, "", "*", "", "", refsPrts["ddrAXI_awaddr"], "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_awburst", false, "slvdn", 2, "", "*", "01", "", refsPrts["ddrAXI_awburst"], "INCR burst type");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_awcache", false, "slvdn", 4, "", "*", "0000", "", refsPrts["ddrAXI_awcache"], "device non-bufferable memory type");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_awlen_sig", false, "slvdn", 8, "", "*", (wrflex) ? "" : "std_logic_vector(to_unsigned(NBeatWr - 1, 8))", "", refsPrts["ddrAXI_awlen"], "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_awlock", false, "slvdn", 1, "", "*", "0", "", refsPrts["ddrAXI_awlock"], "non-exclusive access");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_awprot", false, "slvdn", 3, "", "*", "010", "", refsPrts["ddrAXI_awprot"], "unprivileged, non-secure data access");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_awqos", false, "slvdn", 4, "", "*", "1101", "", refsPrts["ddrAXI_awqos"], "not participating in QoS scheme");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_awregion", false, "slvdn", 4, "", "*", "0000", "", refsPrts["ddrAXI_awregion"], "region feature not used");

			s = "000";
			if (wD == 32) s = "010";
			else if (wD == 64) s = "011";
			else if (wD == 128) s = "100";
			else if (wD == 256) s = "101";
			else if (wD == 512) s = "110";
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_awsize", false, "slvdn", 3, "", "*", s, "", refsPrts["ddrAXI_awsize"], to_string(wD) + "-bit wide transfers");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_awvalid", false, "sl", 1, "", "*", "", "", refsPrts["ddrAXI_awvalid"], "");

			// w
			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_wdata", false, "slvdn", wD, "", "*", "", "", refsPrts["ddrAXI_wdata"], "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_wlast_sig", false, "sl", 1, "", "*", "", "", refsPrts["ddrAXI_wlast"], "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_wstrb", false, "slvdn", wD/8, "", "*", string(wD/8, '1'), "", refsPrts["ddrAXI_wstrb"], "no sparse tranfsers");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_wvalid_sig", false, "sl", 1, "", "*", "", "", refsPrts["ddrAXI_wvalid"], "");

			// b
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ddrAXI_bready", false, "sl", 1, "", "", "", "0", refsPrts["ddrAXI_bready"], "");

			// mux
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, mutexsref, false, "nat", 0, "NWr", "", "", "0", 0, "");
	
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ackWr", false, "sl", 1, "", "state(locked)", "1", "0", 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			for (unsigned int i = 0; i < NWr; i++)
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, (wDWrs[i] != wD) ? VecWdbeVMSignalBasetype::OTH : VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++,
							VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ack" + getChsref(true, i, true) + ((wDWrs[i] != wD) ? "_sig" : ""), false, "sl", 1, "", "wrmutex=mutex" + string(1, (char) (0x41+i)), "ackWr", "0",
							(wDWrs[i] != wD) ? 0 : refsPrts["ack" + getChsref(true, i, true)], "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "wrmutex", false, "mutex_t", 0, "", "", "", "mutexIdle", 0, "");

			refSig = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::STRB, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "strbWrlock", false, "sl", 1, "", "", "", "0", 0, "");
			if (refCdcMclk != 0) dbswdbe->tblwdbermcdcmsignal->insertNewRec(NULL, refCdcMclk, refSig, VecWdbeVRMCdcMSignalDir::FTS);

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "wrid", false, "slvdn", 32, "", "", "", "0", 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ixWrid", false, "nat", 0, "0..31", "", "", "0", 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ixWridIgr", false, "nat", 0, "0..31", "", "", "0", 0, "");

			// per write channel
			for (unsigned int i = 0; i < NWr; i++) if (wDWrs[i] != wD) {
				chsref = getChsref(true, i, false);

				refC = dbswdbe->tblwdbecsignal->getNewRef();
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_awready_sig", false, "sl", 1, "", "wrmutex=mutex" + string(1, (char) (0x41+i)), "ddrAXI_awready", "0", 0, "");
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_wready_sig", false, "sl", 1, "", "wrmutex=mutex" + string(1, (char) (0x41+i)), "ddrAXI_wready", "0", 0, "");
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
		for (unsigned int i = 0; i < NRd; i++) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "N" + getChsref(false, i, true), false, "slvdn", 32, "", "", "", "0", refsPrts["getStatsN" + getChsref(false, i, true)], "");
		for (unsigned int i = 0; i < NWr; i++) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "N" + getChsref(true, i, true), false, "slvdn", 32, "", "", "", "0", refsPrts["getStatsN" + getChsref(true, i, true)], "");
		
		// variables
		refNumVar = 1;

		refC = dbswdbe->tblwdbecvariable->getNewRef();
		dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, refNumVar++, "imax", true, false, "nat", 0, "", "", "10000", "1 s");
		dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, refNumVar++, "i", false, false, "nat", 0, "0..imax", "", "0", "");

		refC = dbswdbe->tblwdbecvariable->getNewRef();
		for (unsigned int i = 0; i < NRd; i++) dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, refNumVar++, "N" + getChsref(false, i, true) + "_collect", false, false, "slvdn", 32, "", "", "0", "");
		for (unsigned int i = 0; i < NWr; i++) dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, refNumVar++, "N" + getChsref(true, i, true) + "_collect", false, false, "slvdn", 32, "", "", "0", "");

		delete prc;

		for (unsigned int i = 0; i < NRd; i++) if (wDRds[i] != wD) {
			// - rdXGearIgr (auto-generated wiring)
			chsref = getChsref(false, i, false);

			dbswdbe->tblwdbemprocess->insertNewRec(&prc, refWdbeMModule, 0, chsref + "GearIgr", clkRds[i], "reset" + StrMod::cap(clkRds[i]), false, "state(init)", true, chsref + " geared ingress operation");
			if (refPrcRdGearFirst == 0) refPrcRdGearFirst = prc->ref;

			prc->refWdbeMFsm = dbswdbe->tblwdbemfsm->insertNewRec(NULL, prc->ref, VecWdbeVMFsmDbgtaptype::VOID);
			dbswdbe->tblwdbemprocess->updateRec(prc);

			refFstInit = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 1, "init", false, "");
			refFstIdle = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 2, "idle", false, "");
			refFstAddr = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 3, "addr", false, "");
			refFstXfer = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 4, "xfer", false, "");

			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstInit, 1, refFstIdle, "", "", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstIdle, 1, refFstAddr, chsref + "Ready and not " + chsref + "Full", "idle", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstAddr, 1, refFstXfer, chsref + "AXI_arready_sig", "addr", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstXfer, 1, refFstIdle, chsref + "AXI_rvalid_sig", "copy", "i=NBeatRd-1 or " + chsref + "AXI_rlast_sig", "done", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstXfer, 2, refFstXfer, chsref + "AXI_rvalid_sig", "copy", "else", "inc", "", "", "", "");

			// signals
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "req" + StrMod::cap(chsref) + "_sig", false, "sl", 1, "", "state(addr;xfer)", "1", "0", 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_araddr_sig", false, "slvdn", wA-wAConst-log2(NBeatRd)-log2(wD/8), "", "", "", "0", 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_arvalid_sig", false, "sl", 1, "", "state(addr)", "1", "0", 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_rready_sig", false, "sl", 1, "", "state(xfer)", "1", "0", 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "Full", false, "_bool", 0, "", "", "", "false", 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "Buf", false, "rdbuf_t", 0, "", "", "", "", 0, "");

			// variables
			dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, 1, "i", false, false, "nat", 0, "0..NBeatRd-1", "", "0", "");

			delete prc;

			// - rdXGearEgr (auto-generated wiring)
			dbswdbe->tblwdbemprocess->insertNewRec(&prc, refWdbeMModule, 0, chsref + "GearEgr", memclk, resetMemclk, false, "state(init)", false, chsref + " geared egress operation");

			prc->refWdbeMFsm = dbswdbe->tblwdbemfsm->insertNewRec(NULL, prc->ref, VecWdbeVMFsmDbgtaptype::VOID);
			dbswdbe->tblwdbemprocess->updateRec(prc);

			refFstInit = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 1, "init", false, "");
			refFstIdle = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 2, "idle", false, "");
			refFstAddr = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 3, "addr", false, "");
			refFstWaitFull = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 4, "waitFull", false, "");
			refFstXfer = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 5, "xfer", false, "");

			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstInit, 1, refFstIdle, "", "", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstIdle, 1, refFstAddr, "req" + StrMod::cap(chsref) + "='1' and not " + chsref + "Full", "", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstAddr, 1, refFstWaitFull, chsref + "AXI_arvalid", "addr", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstWaitFull, 1, refFstXfer, "rdAFull", "done", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstXfer, 1, refFstIdle, "rdAAXI_rready", "", "j=jmax", "beatDone", "i=NBeatRd-1", "burstDone", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstXfer, 2, refFstXfer, "rdAAXI_rready", "", "j=jmax", "beatDone", "else", "nextBeat", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstXfer, 3, refFstXfer, "rdAAXI_rready", "", "else", "nextWord", "", "", "", "");

			// signals
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "WD", true, "nat", 0, "", "", "", to_string(wDRds[i]), 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ack" + StrMod::cap(chsref), false, "sl", 1, "", "state(addr;waitFull;xfer)", "1", "0", refsPrts["ack" + StrMod::cap(chsref)], "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_arready", false, "sl", 1, "", "state(addr)", "1", "0", refsPrts[chsref + "AXI_arready"], "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_rdata_oprt", false, "slvdn", 0, chsref + "WD", "", "", "0", refsPrts[chsref + "AXI_rdata"], "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_rlast_oprt", false, "sl", 1, "", "", "", "1", refsPrts[chsref + "AXI_rlast"], "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_rvalid", false, "sl", 1, "", "state(xfer)", "1", "0", refsPrts[chsref + "AXI_rvalid"], "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "Ready", false, "_bool", 0, "", "", "", "true", 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "A", false, "slvdn", wA-wAConst-log2(NBeatRd)-log2(wD/8), "", "", "", "0", 0, "");

			// variables
			refNumVar = 1;

			dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, refNumVar++, "i", false, false, "nat", 0, "0..NBeatRd-1", "", "0", "");

			refC = dbswdbe->tblwdbecvariable->getNewRef();
			dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, refNumVar++, "jmax", true, false, "nat", 0, "", "", "wD/" + chsref + "WD-1", "");
			dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, refNumVar++, "j", false, false, "nat", 0, "0..jmax", "", "0", "");

			delete prc;
		};

		if (refPrcRdGearFirst != 0) {
			// rdbuf_t
			dbswdbe->tblwdbeavkeylistkey->insertNewRec(&klsAkey, VecWdbeVKeylist::KLSTWDBEKHDLTYPE, 1, VecWdbeVMaintable::TBLWDBEMPROCESS, refPrcRdGearFirst, true, "rdbuf_t", "", "", 0, "", "");
			dbswdbe->tblwdbejavkeylistkey->insertNewRec(&kakJ, klsAkey->ref, VecWdbeVLocale::ENUS, "array (0 to NBeatRd-1) of std_logic_vector(wD-1 downto 0)", "");

			klsAkey->refJ = kakJ->ref;
			klsAkey->Title = kakJ->Title;
			klsAkey->Comment = kakJ->Comment;
			dbswdbe->tblwdbeavkeylistkey->updateRec(klsAkey);

			delete kakJ;
			delete klsAkey;
		};

		for (unsigned int i = 0; i < NWr; i++) if (wDWrs[i] != wD) {
			// - wrXGearIgr (auto-generated wiring)
			chsref = getChsref(true, i, false);

			dbswdbe->tblwdbemprocess->insertNewRec(&prc, refWdbeMModule, 0, chsref + "GearIgr", clkRds[i], "reset" + StrMod::cap(clkWrs[i]), false, "state(init)", true, chsref + " geared ingress operation");
			if (refPrcWrGearFirst == 0) refPrcWrGearFirst = prc->ref;

			prc->refWdbeMFsm = dbswdbe->tblwdbemfsm->insertNewRec(NULL, prc->ref, VecWdbeVMFsmDbgtaptype::VOID);
			dbswdbe->tblwdbemprocess->updateRec(prc);

			refFstInit = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 1, "init", false, "");
			refFstIdle = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 2, "idle", false, "");
			refFstAddr = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 3, "addr", false, "");
			refFstXfer = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 4, "xfer", false, "");

			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstInit, 1, refFstIdle, "", "", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstIdle, 1, refFstAddr, "req" + StrMod::cap(chsref) + "='1' and ((not " + chsref + "FillBNotA and not " + chsref + "FullA) or (" + chsref + "FillBNotA and not " + chsref + "FullB))", "", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstAddr, 1, refFstXfer, chsref + "AXI_awvalid", "addr", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstXfer, 1, refFstIdle, chsref + "AXI_wvalid", "xfer", "j=jmax", "beatDone", "i=NBeatWr-1", "burstDone", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstXfer, 2, refFstXfer, chsref + "AXI_wvalid", "xfer", "j=jmax", "beatDone", "else", "nextBeat", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstXfer, 3, refFstXfer, chsref + "AXI_wvalid", "xfer", "else", "nextWord", "", "", "", "");

			// signals
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ack" + StrMod::cap(chsref), false, "sl", 1, "", "state(addr;xfer)", "1", "0", refsPrts["ack" + StrMod::cap(chsref)], "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_awready", false, "sl", 1, "", "state(addr)", "1", "0", refsPrts[chsref + "AXI_awready"], "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_wready", false, "sl", 1, "", "state(xfer)", "1", "0", refsPrts[chsref + "AXI_wready"], "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "FillBNotA", false, "_bool", 0, "", "", "", "false", 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "FullA", false, "_bool", 0, "", "", "", "false", 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "FullB", false, "_bool", 0, "", "", "", "false", 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "Aa", false, "slvdn", wA-wAConst-log2(NBeatWr)-log2(wD/8), "", "", "", "0", 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "Abuf", false, "wrbuf_t", 0, "", "", "", "", 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "Ba", false, "slvdn", wA-wAConst-log2(NBeatWr)-log2(wD/8), "", "", "", "0", 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "Bbuf", false, "wrbuf_t", 0, "", "", "", "", 0, "");

			// variables
			refNumVar = 1;

			dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, refNumVar++, "i", false, false, "nat", 0, "0..NBeatWr-1", "", "0", "");

			refC = dbswdbe->tblwdbecvariable->getNewRef();
			dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, refNumVar++, "jmax", true, false, "nat", 0, "", "", "wD/" + chsref + "WD-1", "");
			dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, refNumVar++, "j", false, false, "nat", 0, "0..jmax", "", "0", "");

			delete prc;

			// - wrXGearEgr (auto-generated wiring)
			dbswdbe->tblwdbemprocess->insertNewRec(&prc, refWdbeMModule, 0, chsref + "GearEgr", clkWrs[i], "reset" + StrMod::cap(clkWrs[i]), false, "state(init)", true, chsref + " geared egress operation");

			prc->refWdbeMFsm = dbswdbe->tblwdbemfsm->insertNewRec(NULL, prc->ref, VecWdbeVMFsmDbgtaptype::VOID);
			dbswdbe->tblwdbemprocess->updateRec(prc);

			refFstInit = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 1, "init", false, "");
			refFstIdle = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 2, "idle", false, "");
			refFstAddr = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 3, "addr", false, "");
			refFstXfer = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, 4, "xfer", false, "");

			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstInit, 1, refFstIdle, "", "", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstIdle, 1, refFstAddr, chsref + "FillBNotA and " + chsref + "FullA and not " + chsref + "DoneA", "startA", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstIdle, 2, refFstAddr, "not " + chsref + "FillBNotA and " + chsref + "FullB and not " + chsref + "DoneB", "startB", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstAddr, 1, refFstXfer, "wrAAXI_awready_sig", "addr", "", "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstXfer, 1, refFstIdle, "wrAAXI_wready_sig", "", "i=NBeatWr-1", "done", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstXfer, 2, refFstXfer, "wrAAXI_wready_sig", "", "else", "next", "", "", "", "");

			// signals
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "WD", true, "nat", 0, "", "", "", to_string(wDWrs[i]), 0, "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "req" + StrMod::cap(chsref) + "_sig", false, "sl", 1, "", "state(addr;xfer)", "1", "0", 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_awaddr_sig", false, "slvdn", wA-wAConst-log2(NBeatWr)-log2(wD/8), "", "", "", "0", 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_awvalid_sig", false, "sl", 1, "", "state(addr)", "1", "0", 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_wdata_sig", false, "slvdn", wD, "", "", "", "0", 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_wlast_sig", false, "sl", 1, "", "", "", "0", 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "AXI_wvalid_sig", false, "sl", 1, "", "state(xfer)", "1", "0", 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "DoneA", false, "_bool", 0, "", "", "", "false", 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, chsref + "DoneB", false, "_bool", 0, "", "", "", "false", 0, "");

			// variables
			dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, 1, "i", false, false, "nat", 0, "0..NBeatWr-1", "", "0", "");

			delete prc;
		};

		if (refPrcWrGearFirst != 0) {
			// wrbuf_t
			dbswdbe->tblwdbeavkeylistkey->insertNewRec(&klsAkey, VecWdbeVKeylist::KLSTWDBEKHDLTYPE, 1, VecWdbeVMaintable::TBLWDBEMPROCESS, refPrcWrGearFirst, true, "wrbuf_t", "", "", 0, "", "");
			dbswdbe->tblwdbejavkeylistkey->insertNewRec(&kakJ, klsAkey->ref, VecWdbeVLocale::ENUS, "array (0 to NBeatWr-1) of std_logic_vector(wD-1 downto 0)", "");

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
