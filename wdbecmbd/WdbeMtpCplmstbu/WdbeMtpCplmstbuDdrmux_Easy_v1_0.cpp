/**
	* \file WdbeMtpCplmstbuDdrmux_Easy_v1_0.cpp
	* Wdbe operation processor - adapt port widths, connect PHY (implementation)
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

#include "WdbeMtpCplmstbuDdrmux_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuDdrmux_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuDdrmux_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	bool phyNotAxi;
	unsigned int wAPhy, wDPhy;
	bool memclkIntNotExt;
	int fMemclk;
	unsigned int wA, wAConst;
	string aConst;
	unsigned int NBeat;
	unsigned int wD;

	unsigned int NRd;
	vector<bool> flexNBeatRds;
	vector<unsigned int> wDRds;
	vector<string> clkRds;
	vector<double> ratioClkRds;

	unsigned int NWr;
	vector<bool> flexNBeatWrs;
	vector<unsigned int> wDWrs;
	vector<string> clkWrs;
	vector<double> ratioClkWrs;

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

		memclkIntNotExt = false;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "memclkIntNotExt", s)) memclkIntNotExt = (s == "true");

		fMemclk = 333000;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "fMemclk", s)) fMemclk = atoi(s.c_str());

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

		flexNBeatRds.resize(NRd, false);
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "flexNBeatRds", s)) {
			StrMod::stringToVector(s, ss);
			if (ss.size() == NRd) for (unsigned int i = 0; i < NRd; i++) flexNBeatRds[i] = (ss[i] == "true");
		};

		wDRds.resize(NRd, wD);
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wDRds", s)) {
			StrMod::stringToVector(s, ss);
			if (ss.size() == NRd) for (unsigned int i = 0; i < NRd; i++) wDRds[i] = atoi(ss[i].c_str());
		};

		clkRds.resize(NRd, "memclk");
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

		flexNBeatWrs.resize(NWr, false);
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "flexNBeatWrs", s)) {
			StrMod::stringToVector(s, ss);
			if (ss.size() == NWr) for (unsigned int i = 0; i < NWr; i++) flexNBeatWrs[i] = (ss[i] == "true");
		};

		wDWrs.resize(NWr, wD);
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wDWrs", s)) {
			StrMod::stringToVector(s, ss);
			if (ss.size() == NWr) for (unsigned int i = 0; i < NWr; i++) wDWrs[i] = atoi(ss[i].c_str());
		};

		clkWrs.resize(NWr, "memclk");
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "clkWrs", s)) {
			StrMod::stringToVector(s, ss);
			if (ss.size() == NWr) clkWrs = ss;
		};

		ratioClkWrs.resize(NWr, 1.0);
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "ratioClkWrs", s)) {
			StrMod::stringToVector(s, ss);
			if (ss.size() == NWr) for (unsigned int i = 0; i < NWr; i++) ratioClkWrs[i] = atof(ss[i].c_str());
		};

		///
		ubigint ref, refC;

		string chsref;

		uint mdlNum;
		uint refNum;

		unsigned int w;

		mdlNum = Wdbe::getNextPrtMdlNum(dbswdbe, refWdbeMModule);
		dbswdbe->tblwdbemport->insertNewRec(NULL, 0, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RESET, "resetMemclk", (memclkIntNotExt) ? VecWdbeVMPortDir::OUT : VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "", "");
		dbswdbe->tblwdbemport->insertNewRec(NULL, 0, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::CLK, "memclk", (memclkIntNotExt) ? VecWdbeVMPortDir::OUT : VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "", "");

		if (dbswdbe->loadRefBySQL("SELECT refWdbeCPort FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'ddrAXI_araddr'", refC)) {
			if (!phyNotAxi) Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "ddrAXI_araddr", wA);
			else dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE refWdbeCPort = " + to_string(refC));
		};
		if (dbswdbe->loadRefBySQL("SELECT refWdbeCPort FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'ddrAXI_rdata'", refC)) {
			if (!phyNotAxi) Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "ddrAXI_rdata", wD);
			else dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE refWdbeCPort = " + to_string(refC));
		};
		if (dbswdbe->loadRefBySQL("SELECT refWdbeCPort FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'ddrAXI_awaddr'", refC)) {
			if (!phyNotAxi) Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "ddrAXI_awaddr", wA);
			else dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE refWdbeCPort = " + to_string(refC));
		};
		if (dbswdbe->loadRefBySQL("SELECT refWdbeCPort FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'ddrAXI_wdata'", refC)) {
			if (!phyNotAxi) {
				Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "ddrAXI_wdata", wD);
				Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "ddrAXI_wstrb", wD/8);
			} else dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE refWdbeCPort = " + to_string(refC));
		};
		if (dbswdbe->loadRefBySQL("SELECT refWdbeCPort FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'ddrAXI_bready'", refC)) {
			if (phyNotAxi) dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE refWdbeCPort = " + to_string(refC));
		};

		for (unsigned int i = 0; i < NRd; i++) {
			chsref = getChsref(false, i, false);

			refC = dbswdbe->tblwdbecport->getNewRef();
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, "req" + StrMod::cap(chsref), VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "", "");
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, "ack" + StrMod::cap(chsref), VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "", "");

			refC = dbswdbe->tblwdbecport->getNewRef();
			w = wA-wAConst-log2(wDRds[i]/8);
			if (!flexNBeatRds[i]) w -= log2(NBeat);
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, chsref + "AXI_araddr", VecWdbeVMPortDir::IN, "slvdn", w, "", "", "", "", "", "");
			if (flexNBeatRds[i]) dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, chsref + "AXI_arlen", VecWdbeVMPortDir::IN, "slvdn", 8, "", "", "", "", "", "");
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, chsref + "AXI_arready", VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "", "");
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, chsref + "AXI_arvalid", VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "", "");
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, chsref + "AXI_rdata", VecWdbeVMPortDir::OUT, "slvdn", wDRds[i], "", "", "", "", "", "");
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, chsref + "AXI_rlast", VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "", "");
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, chsref + "AXI_rready", VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "", "");
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, chsref + "AXI_rresp", VecWdbeVMPortDir::OUT, "slvdn", 2, "", "", "", "", "", "");
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, chsref + "AXI_rvalid", VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "", "");
		};

		for (unsigned int i = 0; i < NWr; i++) {
			chsref = getChsref(true, i, false);

			refC = dbswdbe->tblwdbecport->getNewRef();
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, "req" + StrMod::cap(chsref), VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "", "");
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, "ack" + StrMod::cap(chsref), VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "", "");

			refC = dbswdbe->tblwdbecport->getNewRef();
			w = wA-wAConst-log2(wDWrs[i]/8);
			if (!flexNBeatWrs[i]) w -= log2(NBeat);
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, chsref + "AXI_awaddr", VecWdbeVMPortDir::IN, "slvdn", w, "", "", "", "", "", "");
			if (flexNBeatWrs[i]) dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, chsref + "AXI_awlen", VecWdbeVMPortDir::IN, "slvdn", 8, "", "", "", "", "", "");
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, chsref + "AXI_awready", VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "", "");
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, chsref + "AXI_awvalid", VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "", "");
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, chsref + "AXI_wdata", VecWdbeVMPortDir::IN, "slvdn", wDWrs[i], "", "", "", "", "", "");
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, chsref + "AXI_wlast", VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "", "");
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, chsref + "AXI_wready", VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "", "");
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, chsref + "AXI_wvalid", VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "", "");
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, chsref + "AXI_bready", VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "", "");
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, chsref + "AXI_bresp", VecWdbeVMPortDir::OUT, "slvdn", 2, "", "", "", "", "", "");
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, chsref + "AXI_bvalid", VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "", "");
		};

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR) + " AND refUref = " + to_string(mdl->refWdbeMController) + " AND sref = 'getStats'", ref)) {
			refNum = 1;

			for (unsigned int i = 0; i < NRd; i++) dbswdbe->tblwdbeamcommandretpar->insertNewRec(NULL, ref, refNum++, "N" + getChsref(false, i, true), VecWdbeVPartype::UINT32, 0, 0, "");
			for (unsigned int i = 0; i < NWr; i++) dbswdbe->tblwdbeamcommandretpar->insertNewRec(NULL, ref, refNum++, "N" + getChsref(true, i, true), VecWdbeVPartype::UINT32, 0, 0, "");
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
string WdbeMtpCplmstbuDdrmux_Easy_v1_0::getChsref(
			const bool wrNotRd
			, const unsigned int i
			, const bool capNotUncap
		) {
	string s;

	s = string(1, ((char) (0x41 + i)));
	if (!wrNotRd) s = "rd" + s;
	else s = "wr" + s;

	if (capNotUncap) s = StrMod::cap(s);

	return s;
};
// IP cust --- IEND
