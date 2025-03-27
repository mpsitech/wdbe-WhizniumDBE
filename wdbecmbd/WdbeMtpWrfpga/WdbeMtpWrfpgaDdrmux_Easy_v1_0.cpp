/**
	* \file WdbeMtpWrfpgaDdrmux_Easy_v1_0.cpp
	* Wdbe operation processor -  (implementation)
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

#include "WdbeMtpWrfpgaDdrmux_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpWrfpgaDdrmux_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaDdrmux_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpWrfpga* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;
	string folder = dpchinv->folder;
	string Prjshort = dpchinv->Prjshort;
	string Untsref = dpchinv->Untsref;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	string Compsref;

	fstream outfile;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		Compsref = StrMod::cap(Wdbe::getCompsref(dbswdbe, mdl));

		// xxxx/Ddrmux.vhd
		s = xchg->tmppath + "/" + folder + "/" + Compsref + ".vhd.ip";
		outfile.open(s.c_str(), ios::out);
		writeMdlVhd(dbswdbe, outfile, mdl);
		outfile.close();

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeMtpWrfpgaDdrmux_Easy_v1_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	bool phyNotAxi;
	unsigned int wAPhy, wDPhy;

	string memclk;
	bool memclkIntNotExt;
	double ratioMemclk;

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

	string mutexsref;
	string chsref;

	vector<string> ss;
	string s;

	phyNotAxi = false;
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "phyNotAxi", s)) phyNotAxi = (s == "true");

	wAPhy = 20;
	wDPhy = 16;
	if (phyNotAxi) {
		if (Wdbe::getMpa(dbswdbe, mdl->ref, "wAPhy", s)) wAPhy = atoi(s.c_str());
		if (Wdbe::getMpa(dbswdbe, mdl->ref, "wDPhy", s)) wDPhy = atoi(s.c_str());
	};

	memclk = "memclk";
	Wdbe::getMpa(dbswdbe, mdl->ref, "memclk", memclk);

	memclkIntNotExt = false;
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "memclkIntNotExt", s)) memclkIntNotExt = (s == "true");

	ratioMemclk = 1.0;
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "ratioMemclk", s)) ratioMemclk = atof(s.c_str());

	wA = 32;
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "wA", s)) wA = atoi(s.c_str());

	wAConst = 10;
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "wAConst", s)) wAConst = atoi(s.c_str());

	aConst = "0000000000";
	Wdbe::getMpa(dbswdbe, mdl->ref, "aConst", aConst);

	NBeat = 16;
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "NBeat", s)) NBeat = atoi(s.c_str());

	wD = 128;
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "wD", s)) wD = atoi(s.c_str());

	NRd = 1;
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "NRd", s)) NRd = atoi(s.c_str());

	flexNBeatRds.resize(NRd, false);
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "flexNBeatRds", s)) {
		StrMod::stringToVector(s, ss);
		if (ss.size() == NRd) for (unsigned int i = 0; i < NRd; i++) flexNBeatRds[i] = (ss[i] == "true");
	};

	wDRds.resize(NRd, wD);
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "wDRds", s)) {
		StrMod::stringToVector(s, ss);
		if (ss.size() == NRd) for (unsigned int i = 0; i < NRd; i++) wDRds[i] = atoi(ss[i].c_str());
	};

	clkRds.resize(NRd, memclk);
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "clkRds", s)) {
		StrMod::stringToVector(s, ss);
		if (ss.size() == NRd) clkRds = ss;
	};

	ratioClkRds.resize(NRd, 1.0);
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "ratioClkRds", s)) {
		StrMod::stringToVector(s, ss);
		if (ss.size() == NRd) for (unsigned int i = 0; i < NRd; i++) ratioClkRds[i] = atof(ss[i].c_str());
	};

	NWr = 1;
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "NWr", s)) NWr = atoi(s.c_str());

	flexNBeatWrs.resize(NWr, false);
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "flexNBeatWrs", s)) {
		StrMod::stringToVector(s, ss);
		if (ss.size() == NWr) for (unsigned int i = 0; i < NWr; i++) flexNBeatWrs[i] = (ss[i] == "true");
	};

	wDWrs.resize(NWr, wD);
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "wDWrs", s)) {
		StrMod::stringToVector(s, ss);
		if (ss.size() == NWr) for (unsigned int i = 0; i < NWr; i++) wDWrs[i] = atoi(ss[i].c_str());
	};

	clkWrs.resize(NWr, memclk);
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "clkWrs", s)) {
		StrMod::stringToVector(s, ss);
		if (ss.size() == NWr) clkWrs = ss;
	};

	ratioClkWrs.resize(NWr, 1.0);
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "ratioClkWrs", s)) {
		StrMod::stringToVector(s, ss);
		if (ss.size() == NWr) for (unsigned int i = 0; i < NWr; i++) ratioClkWrs[i] = atof(ss[i].c_str());
	};

	///
	unsigned int w;

	bool first;

	if (NRd > 0) {
		// - read

		mutexsref = "";
		for (unsigned int i = 0; i < NRd; i++) mutexsref += string(1, (char) (0x61+i));
		mutexsref += "Rd";

		// --- impl.read.wiring
		outfile << "-- IP impl.read.wiring --- RBEGIN" << endl;

		outfile << "\tddrAXI_arid <= (others => '0');" << endl;
		outfile << endl;

		outfile << "\tddrAXI_araddr <= ";
		for (unsigned int i = 0; i < NRd; i++) {
			outfile << "\"" << aConst << "\" & " << getChsref(false, i, false) << "AXI_araddr";
			if (wDRds[i] != wD) outfile << "_sig";
			w = log2(wD/8);
			if (!flexNBeatRds[i]) w += log2(NBeat);
			outfile << " & \"" << string(w, '0') << "\" when rdmutex=mutex" << string(1, (char) (0x41+i)) << endl;
			outfile << "\t\t\t\telse ";
		};
		outfile << "(others => '0');" << endl;
		outfile << endl;

		outfile << "\tddrAXI_arburst <= \"01\"; -- INCR burst type" << endl;
		outfile << "\tddrAXI_arcache <= \"0000\"; -- device non-bufferable memory type" << endl;
		outfile << endl;

		outfile << "\tddrAXI_arlen <= ddrAXI_arlen_sig;" << endl;
		outfile << "\tddrAXI_arlen_sig <= ";
		first = true;
		for (unsigned int i = 0; i < NRd; i++) {
			if (flexNBeatRds[i]) {
				if (first) first = false;
				else outfile << "\t\t\t\telse ";
				outfile << getChsref(false, i, false) << "AXI_arlen when rdmutex=mutex" << string(1, (char) (0x41+i)) << endl;
				first = false;
			};
		};
		if (!first) outfile << "\t\t\t\telse ";
		outfile << "x\"";
		if (NBeat == 4) outfile << "03";
		else if (NBeat == 8) outfile << "07";
		else if (NBeat == 16) outfile << "0F";
		else if (NBeat == 32) outfile << "1F";
		else if (NBeat == 64) outfile << "3F";
		else if (NBeat == 128) outfile << "7F";
		else if (NBeat == 256) outfile << "FF";
		outfile << "\"; -- burst length of " << NBeat << endl;
		outfile << endl;

		outfile << "\tddrAXI_arlock <= \"0\"; -- normal access as opposed to exclusive access" << endl;
		outfile << "\tddrAXI_arprot <= \"010\"; -- unprivileged, non-secure data access" << endl;
		outfile << "\tddrAXI_arqos <= \"1101\"; -- not participating in QoS scheme" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < NRd; i++) {
			outfile << "\t" << getChsref(false, i, false) << "AXI_arready";
			if (wDRds[i] != wD) outfile << "_sig";
			outfile << " <= ddrAXI_arready when rdmutex=mutex" << string(1, (char) (0x41+i)) << " else '0';" << endl;
		};
		outfile << endl;

		outfile << "\tddrAXI_arregion <= \"0000\"; -- region feature not used" << endl;
		outfile << "\tddrAXI_arsize <= \"";
		if (wD == 32) outfile << "010";
		else if (wD == 64) outfile << "011";
		else if (wD == 128) outfile << "100";
		else if (wD == 256) outfile << "101";
		else if (wD == 512) outfile << "110";
		outfile << "\"; -- " << wD << "-bit wide transfers" << endl;
		outfile << endl;

		outfile << "\tddrAXI_arvalid <= ddrAXI_arvalid_sig;" << endl;
		outfile << "\tddrAXI_arvalid_sig <= ";
		for (unsigned int i = 0; i < NRd; i++) {
			outfile << getChsref(false, i, false) << "AXI_arvalid";
			if (wDRds[i] != wD) outfile << "_sig";
			outfile << " when rdmutex=mutex" << string(1, (char) (0x41+i)) << endl;
			outfile << "\t\t\t\telse ";
		};
		outfile << "'0';" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < NRd; i++) {
			outfile << "\t" << getChsref(false, i, false) << "AXI_rdata";
			if (wDRds[i] != wD) outfile << "_sig";
			outfile << " <= ddrAXI_rdata;" << endl;
		};
		outfile << endl;

		for (unsigned int i = 0; i < NRd; i++) {
			outfile << "\t" << getChsref(false, i, false) << "AXI_rlast";
			if (wDRds[i] != wD) outfile << "_sig";
			outfile << " <= ddrAXI_rlast;" << endl;
		};
		outfile << endl;

		outfile << "\tddrAXI_rready <= ddrAXI_rready_sig;" << endl;
		outfile << "\tddrAXI_rready_sig <= ";
		for (unsigned int i = 0; i < NRd; i++) {
			outfile << getChsref(false, i, false) << "AXI_rready";
			if (wDRds[i] != wD) outfile << "_sig";
			outfile << " when rdid(ixRdidEgr)=mutex" << string(1, (char) (0x41+i)) << endl;
			outfile << "\t\t\t\telse ";
		};
		outfile << "'0';" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < NRd; i++) {
			outfile << "\t" << getChsref(false, i, false) << "AXI_rresp";
			if (wDRds[i] != wD) outfile << "_sig";
			outfile << " <= ddrAXI_rresp;" << endl;
		};
		outfile << endl;

		for (unsigned int i = 0; i < NRd; i++) {
			outfile << "\t" << getChsref(false, i, false) << "AXI_rvalid";
			if (wDRds[i] != wD) outfile << "_sig";
			outfile << " <= ddrAXI_rvalid when rdid(ixRdidEgr)=mutex" << string(1, (char) (0x41+i)) << " else '0';" << endl;
		};
		outfile << endl;

		outfile << "\tackRd <= '1' when stateRead=stateReadLocked else '0';" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < NRd; i++) outfile << "\tack" << getChsref(false, i, true) << " <= ackRd when rdmutex=mutex" << string(1, (char) (0x41+i)) << " else '0';" << endl;
		outfile << endl;
		outfile << "-- IP impl.read.wiring --- REND" << endl;

		// --- impl.read.ext
		outfile << "\t\t\t-- IP impl.read.ext --- IBEGIN" << endl;
		outfile << "\t\t\tif ddrAXI_rready_sig='1' and ddrAXI_rvalid='1' and ddrAXI_rlast='1' then" << endl;
		outfile << "\t\t\t\trdid(ixRdidEgr) <= mutexIdle;" << endl;
		outfile << endl;

		outfile << "\t\t\t\tif ixRdidEgr=31 then" << endl;
		outfile << "\t\t\t\t\tixRdidEgr <= 0;" << endl;
		outfile << "\t\t\t\telse" << endl;
		outfile << "\t\t\t\t\tixRdidEgr <= ixRdidEgr + 1;" << endl;
		outfile << "\t\t\t\tend if;" << endl;
		outfile << "\t\t\tend if;" << endl;
		outfile << "\t\t\t-- IP impl.read.ext --- IEND" << endl;

		// --- impl.read.idle.start*
		for (unsigned int i = 0; i < NRd; i++) {
			outfile << "-- IP impl.read.idle.start" << string(1, (char) (0x41+i)) << " --- IBEGIN" << endl;
			outfile << "\t\t\t\t\t" << mutexsref << " <= " << i << ";" << endl;
			outfile << "\t\t\t\t\trdmutex <= mutex" << string(1, (char) (0x41+i)) << ";" << endl;
			outfile << endl;

			outfile << "\t\t\t\t\tstrbRdlock <= '1';" << endl;
			outfile << endl;

			outfile << "\t\t\t\t\trdid(ixRdid) <= mutex" << string(1, (char) (0x41+i)) << ";" << endl;
			outfile << "-- IP impl.read.idle.start" << string(1, (char) (0x41+i)) << " --- IEND" << endl;
		};

		// --- impl.read.idle.lock
		outfile << "\t\t\t\tstrbRdlock <= '0'; -- IP impl.read.locked.ext --- ILINE" << endl;

		// --- impl.read.locked.unlock
		outfile << "\t\t\t\t\t-- IP impl.read.locked.unlock --- IBEGIN" << endl;
		outfile << "\t\t\t\t\trdmutex <= mutexIdle;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\tif ixRdid=31 then" << endl;
		outfile << "\t\t\t\t\t\tixRdid <= 0;" << endl;
		outfile << "\t\t\t\t\telse" << endl;
		outfile << "\t\t\t\t\t\tixRdid <= ixRdid + 1;" << endl;
		outfile << "\t\t\t\t\tend if;" << endl;
		outfile << "\t\t\t\t\t-- IP impl.read.locked.unlock --- IEND" << endl;
	};

	if (NWr > 0) {
		// - write
		mutexsref = "";
		for (unsigned int i = 0; i < NWr; i++) mutexsref += string(1, (char) (0x61+i));
		mutexsref += "Wr";

		// --- impl.write.wiring
		outfile << "-- IP impl.write.wiring --- RBEGIN" << endl;

		outfile << "\tddrAXI_awid <= (others => '0');" << endl;
		outfile << endl;

		outfile << "\tddrAXI_awaddr <= ";
		for (unsigned int i = 0; i < NWr; i++) {
			outfile << "\"" << aConst << "\" & " << getChsref(true, i, false) << "AXI_awaddr";
			if (wDWrs[i] != wD) outfile << "_sig";
			w = log2(wD/8);
			if (!flexNBeatWrs[i]) w += log2(NBeat);
			outfile << " & \"" << string(w, '0') << "\" when wrmutex=mutex" << string(1, (char) (0x41+i)) << endl;
			outfile << "\t\t\t\telse ";
		};
		outfile << "(others => '0');" << endl;
		outfile << endl;

		outfile << "\tddrAXI_awburst <= \"01\"; -- INCR burst type" << endl;
		outfile << "\tddrAXI_awcache <= \"0000\"; -- device non-bufferable memory type" << endl;
		outfile << endl;

		outfile << "\tddrAXI_awlen <= ddrAXI_awlen_sig;" << endl;
		outfile << "\tddrAXI_awlen_sig <= ";
		first = true;
		for (unsigned int i = 0; i < NWr; i++) {
			if (flexNBeatWrs[i]) {
				if (first) first = false;
				else outfile << "\t\t\t\telse ";
				outfile << getChsref(true, i, false) << "AXI_awlen when wrmutex=mutex" << string(1, (char) (0x41+i)) << endl;
				first = false;
			};
		};
		if (!first) outfile << "\t\t\t\telse ";
		outfile << "x\"";
		if (NBeat == 4) outfile << "03";
		else if (NBeat == 8) outfile << "07";
		else if (NBeat == 16) outfile << "0F";
		else if (NBeat == 32) outfile << "1F";
		else if (NBeat == 64) outfile << "3F";
		else if (NBeat == 128) outfile << "7F";
		else if (NBeat == 256) outfile << "FF";
		outfile << "\"; -- burst length of " << NBeat << endl;
		outfile << endl;

		outfile << "\tddrAXI_awlock <= \"0\"; -- normal access as opposed to exclusive access" << endl;
		outfile << "\tddrAXI_awprot <= \"010\"; -- unprivileged, non-secure data access" << endl;
		outfile << "\tddrAXI_awqos <= \"1101\"; -- not participating in QoS scheme" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < NWr; i++) {
			outfile << "\t" << getChsref(true, i, false) << "AXI_awready";
			if (wDWrs[i] != wD) outfile << "_sig";
			outfile << " <= ddrAXI_awready when wrmutex=mutex" << string(1, (char) (0x41+i)) << " else '0';" << endl;
		};
		outfile << endl;

		outfile << "\tddrAXI_awregion <= \"0000\"; -- region feature not used" << endl;
		outfile << "\tddrAXI_awsize <= \"";
		if (wD == 32) outfile << "010";
		else if (wD == 64) outfile << "011";
		else if (wD == 128) outfile << "100";
		else if (wD == 256) outfile << "101";
		else if (wD == 512) outfile << "110";
		outfile << "\"; -- " << wD << "-bit wide transfers" << endl;
		outfile << endl;

		outfile << "\tddrAXI_awvalid <= ";
		for (unsigned int i = 0; i < NWr; i++) {
			outfile << getChsref(true, i, false) << "AXI_awvalid";
			if (wDWrs[i] != wD) outfile << "_sig";
			outfile << " when wrmutex=mutex" << string(1, (char) (0x41+i)) << endl;
			outfile << "\t\t\t\telse ";
		};
		outfile << "'0';" << endl;
		outfile << endl;

		outfile << "\tddrAXI_wdata <= ";
		for (unsigned int i = 0; i < NWr; i++) {
			outfile << getChsref(true, i, false) << "AXI_wdata";
			if (wDWrs[i] != wD) outfile << "_sig";
			outfile << " when wrmutex=mutex" << string(1, (char) (0x41+i)) << endl;
			outfile << "\t\t\t\telse ";
		};
		outfile << "(others => '0');" << endl;
		outfile << endl;

		outfile << "\tddrAXI_wlast <= ddrAXI_wlast_sig;" << endl;
		outfile << "\tddrAXI_wlast_sig <= ";
		for (unsigned int i = 0; i < NWr; i++) {
			outfile << getChsref(true, i, false) << "AXI_wlast";
			if (wDWrs[i] != wD) outfile << "_sig";
			outfile << " when wrmutex=mutex" << string(1, (char) (0x41+i)) << endl;
			outfile << "\t\t\t\telse ";
		};
		outfile << "'1';" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < NWr; i++) {
			outfile << "\t" << getChsref(true, i, false) << "AXI_wready";
			if (wDWrs[i] != wD) outfile << "_sig";
			outfile << " <= ddrAXI_wready when wrmutex=mutex" << string(1, (char) (0x41+i)) << " else '0';" << endl;
		};
		outfile << endl;

		outfile << "\tddrAXI_wstrb <= (others => '1'); -- all bytes for each transfer" << endl;
		outfile << endl;

		outfile << "\tddrAXI_wvalid <= ddrAXI_wvalid_sig;" << endl;
		outfile << "\tddrAXI_wvalid_sig <= ";
		for (unsigned int i = 0; i < NWr; i++) {
			outfile << getChsref(true, i, false) << "AXI_wvalid";
			if (wDWrs[i] != wD) outfile << "_sig";
			outfile << " when wrmutex=mutex" << string(1, (char) (0x41+i)) << endl;
			outfile << "\t\t\t\telse ";
		};
		outfile << "'0';" << endl;
		outfile << endl;

		outfile << "\tddrAXI_bready <= ddrAXI_bready_sig;" << endl;
		outfile << endl;

		outfile << "\tackWr <= '1' when stateWrite=stateWriteLocked else '0';" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < NWr; i++) outfile << "\tack" << getChsref(true, i, true) << " <= ackWr when wrmutex=mutex" << string(1, (char) (0x41+i)) << " else '0';" << endl;
		outfile << endl;
		outfile << "-- IP impl.write.wiring --- REND" << endl;

		// --- impl.write.ext
		outfile << "-- IP impl.write.ext --- IBEGIN" << endl;
		outfile << "\t\t\tif ddrAXI_bvalid='1' then" << endl;
		outfile << "\t\t\t\twrid(ixWridIgr) <= '0';" << endl;
		outfile << endl;

		outfile << "\t\t\t\tif ixWridIgr=31 then" << endl;
		outfile << "\t\t\t\t\tixWridIgr <= 0;" << endl;
		outfile << "\t\t\t\telse" << endl;
		outfile << "\t\t\t\t\tixWridIgr <= ixWridIgr + 1;" << endl;
		outfile << "\t\t\t\tend if;" << endl;
		outfile << "\t\t\tend if;" << endl;
		outfile << endl;

		outfile << "\t\t\tif unsigned(wrid)=0 then -- one clock late" << endl;
		outfile << "\t\t\t\tddrAXI_bready_sig <= '0';" << endl;
		outfile << "\t\t\telse" << endl;
		outfile << "\t\t\t\tddrAXI_bready_sig <= '1';" << endl;
		outfile << "\t\t\tend if;" << endl;
		outfile << "-- IP impl.write.ext --- IEND" << endl;

		// --- impl.write.idle.start*
		for (unsigned int i = 0; i < NWr; i++) {
			outfile << "-- IP impl.write.idle.start" << string(1, (char) (0x41+i)) << " --- IBEGIN" << endl;
			outfile << "\t\t\t\t\t" << mutexsref << " <= " << i << ";" << endl;
			outfile << "\t\t\t\t\twrmutex <= mutex" << string(1, (char) (0x41+i)) << ";" << endl;
			outfile << endl;

			outfile << "\t\t\t\t\tstrbWrlock <= '1';" << endl;
			outfile << endl;

			outfile << "\t\t\t\t\twrid(ixWrid) <= '1';" << endl;
			outfile << "-- IP impl.write.idle.start" << string(1, (char) (0x41+i)) << " --- IEND" << endl;
		};

		// --- impl.write.locked.ext
		outfile << "\t\t\t\tstrbWrlock <= '0'; -- IP impl.write.locked.ext --- ILINE" << endl;

		// --- impl.write.locked.unlock
		outfile << "-- IP impl.write.locked.unlock --- IBEGIN" << endl;
		outfile << "\t\t\t\t\twrmutex <= mutexIdle;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\tif ixWrid=31 then" << endl;
		outfile << "\t\t\t\t\t\tixWrid <= 0;" << endl;
		outfile << "\t\t\t\t\telse" << endl;
		outfile << "\t\t\t\t\t\tixWrid <= ixWrid + 1;" << endl;
		outfile << "\t\t\t\t\tend if;" << endl;
		outfile << "-- IP impl.write.locked.unlock --- IEND" << endl;

	};

	// - stats

	// --- impl.stats.ext
	outfile << "-- IP impl.stats.ext --- IBEGIN" << endl;

	if (NRd > 0) {
		outfile << "\t\t\tif strbRdlock";
		if (memclk != "mclk") outfile << "_mclk";
		outfile << "='1' then" << endl;

		outfile << "\t\t\t\tcase rdmutex is" << endl;
		for (unsigned int i = 0; i < NRd; i++) {
			outfile << "\t\t\t\t\twhen mutex" << string(1, (char) (0x41+i)) << " =>" << endl;
			outfile << "\t\t\t\t\t\tN" << getChsref(false, i, true) << "_collect := std_logic_vector(unsigned(N" << getChsref(false, i, true) << "_collect) + unsigned(ddrAXI_arlen_sig) + 1);" << endl;
		};
		outfile << "\t\t\t\t\twhen others =>" << endl;
		outfile << "\t\t\t\tend case;" << endl;
		outfile << "\t\t\tend if;" << endl;
	};

	if ((NRd > 0) && (NWr > 0)) outfile << endl;

	if (NWr > 0) {
		outfile << "\t\t\tif strbWrlock";
		if (memclk != "mclk") outfile << "_mclk";
		outfile << "='1' then" << endl;

		outfile << "\t\t\t\tcase wrmutex is" << endl;
		for (unsigned int i = 0; i < NWr; i++) {
			outfile << "\t\t\t\t\twhen mutex" << string(1, (char) (0x41+i)) << " =>" << endl;
			outfile << "\t\t\t\t\t\tN" << getChsref(true, i, true) << "_collect := std_logic_vector(unsigned(N" << getChsref(true, i, true) << "_collect) + unsigned(ddrAXI_awlen_sig) + 1);" << endl;
		};
		outfile << "\t\t\t\t\twhen others =>" << endl;
		outfile << "\t\t\t\tend case;" << endl;
		outfile << "\t\t\tend if;" << endl;
	};

	outfile << "-- IP impl.stats.ext --- IEND" << endl;

	// --- impl.stats.collectA
	outfile << "-- IP impl.stats.collectA --- IBEGIN" << endl;
	outfile << "\t\t\t\t\tif i=imax then" << endl;
	outfile << "\t\t\t\t\t\ti := 0;" << endl;

	for (unsigned int i = 0; i < NRd; i++) {
		outfile << endl;
		outfile << "\t\t\t\t\t\tN" << getChsref(false, i, true) << " <= N" << getChsref(false, i, true) << "_collect;" << endl;
		outfile << "\t\t\t\t\t\tN" << getChsref(false, i, true) << "_collect := (others => '0');" << endl;
	};
	for (unsigned int i = 0; i < NWr; i++) {
		outfile << endl;
		outfile << "\t\t\t\t\t\tN" << getChsref(true, i, true) << " <= N" << getChsref(true, i, true) << "_collect;" << endl;
		outfile << "\t\t\t\t\t\tN" << getChsref(true, i, true) << "_collect := (others => '0');" << endl;
	};

	outfile << "\t\t\t\t\tend if;" << endl;
	outfile << "-- IP impl.stats.collectA --- IEND" << endl;

	// --- impl.stats.collectB.inc
	outfile << "\t\t\t\t\ti := i + 1; -- IP impl.stats.collectB.inc --- ILINE" << endl;

	for (unsigned int i = 0; i < NRd; i++) if (wDRds[i] != wD) {
		chsref = getChsref(false, i, false);

		// - rdXGearIgr

		// --- impl.rdXGearIgr.asyncrst
		outfile << "-- IP impl." << chsref << "GearIgr.asyncrst --- RBEGIN" << endl;
		outfile << "\t\t\t" << chsref << "AXI_araddr_sig <= (others => '0');" << endl;
		outfile << endl;

		outfile << "\t\t\t" << chsref << "Full <= false;" << endl;
		outfile << endl;

		outfile << "\t\t\tfor i in 0 to NBeat-1 loop" << endl;
		outfile << "\t\t\t\t" << chsref << "Buf(i) <= (others => '0');" << endl;
		outfile << "\t\t\tend loop;" << endl;
		outfile << "-- IP impl." << chsref << "GearIgr.asyncrst --- REND" << endl;

		// --- impl.rdXGearIgr.ext
		outfile << "-- IP impl." << chsref << "GearIgr.ext --- IBEGIN" << endl;
		outfile << "\t\t\tif not " << chsref << "Ready_" << clkRds[i] << " and " << chsref << "Full then" << endl;
		outfile << "\t\t\t\t" << chsref << "Full <= false;" << endl;
		outfile << "\t\t\tend if;" << endl;
		outfile << "-- IP impl." << chsref << "GearIgr.ext --- IEND" << endl;

		// --- impl.rdXGearIgr.idle
		outfile << "\t\t\t\t\t" << chsref << "AXI_araddr_sig <= " << chsref << "A; -- IP impl." << chsref << "GearIgr.idle --- ILINE" << endl;

		// --- impl.rdXGearIgr.addr
		outfile << "\t\t\t\t\ti := 0; -- IP impl." << chsref << "GearIgr.addr --- ILINE" << endl;

		// --- impl.rdXGearIgr.xfer.ext
		outfile << "-- IP impl." << chsref << "GearIgr.xfer.ext --- IBEGIN" << endl;
		outfile << "\t\t\t\tif " << chsref << "AXI_rvalid_sig='1' then" << endl;
		outfile << "\t\t\t\t\t" << chsref << "Buf(i) <= " << chsref << "AXI_rdata_sig;" << endl;
		outfile << "\t\t\t\tend if;" << endl;
		outfile << "-- IP impl." << chsref << "GearIgr.xfer.ext --- IEND" << endl;

		outfile << "\t\t\t\t\t" << chsref << "Full <= true; -- IP impl." << chsref << "GearIgr.xfer.done --- ILINE" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\ti := i + 1; -- IP impl." << chsref << "GearIgr.xfer.inc --- ILINE" << endl;
		outfile << endl;

		// - rdXGearEgr

		// --- impl.rdXGearEgr.idle.start
		outfile << "-- IP impl." << chsref << "GearEgr.idle.start --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t" << chsref << "A <= " << chsref << "AXI_araddr;" << endl;
		outfile << "\t\t\t\t\t" << chsref << "Ready <= true;" << endl;
		outfile << "-- IP impl." << chsref << "GearEgr.idle.start --- IEND" << endl;

		// --- impl.rdXGearEgr.waitFull
		outfile << "-- IP impl." << chsref << "GearEgr.waitFull --- IBEGIN" << endl;
		outfile << "\t\t\t\t\ti := 0;" << endl;
		outfile << "\t\t\t\t\tj := 0;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\t" << chsref << "AXI_rdata_oprt <= " << chsref << "Buf(i)(" << wDRds[i] << "*(j+1)-1 downto " << wDRds[i] << "*j);" << endl;
		outfile << "\t\t\t\t\t" << chsref << "AXI_rlast_oprt <= '0';" << endl;
		outfile << "-- IP impl." << chsref << "GearEgr.waitFull --- IEND" << endl;

		// --- impl.rdXGearEgr.xfer.beatDone
		outfile << "\t\t\t\t\t\tj := 0; -- IP impl." << chsref << "GearEgr.xfer.beatDone --- ILINE" << endl;

		// --- impl.rdXGearEgr.xfer.burstDone
		outfile << "\t\t\t\t\t\t\t" << chsref << "Ready <= false; -- IP impl." << chsref << "GearEgr.xfer.burstDone --- ILINE" << endl;

		// --- impl.rdXGearEgr.xfer.nextBeat
		outfile << "-- IP impl." << chsref << "GearEgr.xfer.nextBeat --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t\t\ti := i + 1;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\t\t\trdAAXI_rdata_oprt <= rdABuf(i)(" << wDRds[i] << "*(j+1)-1 downto " << wDRds[i] << "*j);" << endl;
		outfile << "-- IP impl." << chsref << "GearEgr.xfer.nextBeat --- IEND" << endl;

		// --- impl.rdXGearEgr.xfer.nextWord
		outfile << "-- IP impl." << chsref << "GearEgr.xfer.nextWord --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t\tj := j + 1;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\t\t" << chsref << "AXI_rdata_oprt <= " << chsref << "Buf(i)(" << wDRds[i] << "*(j+1)-1 downto " << wDRds[i] << "*j);" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\t\tif i=NBeat-1 and j=jmax then" << endl;
		outfile << "\t\t\t\t\t\t\t" << chsref << "AXI_rlast_oprt <= '1';" << endl;
		outfile << "\t\t\t\t\t\tend if;" << endl;
		outfile << "-- IP impl." << chsref << "GearEgr.xfer.nextWord --- IEND" << endl;
	};

	for (unsigned int i = 0; i < NWr; i++) if (wDWrs[i] != wD) {
		chsref = getChsref(true, i, false);

		// - wrXGearIgr

		// --- impl.wrXGearIgr.asyncrst
		outfile << "-- IP impl." << chsref << "GearIgr.asyncrst --- RBEGIN" << endl;
		outfile << "\t\t\t" << chsref << "FillBNotA <= true;" << endl;
		outfile << endl;

		outfile << "\t\t\t" << chsref << "FullA <= false;" << endl;
		outfile << "\t\t\t" << chsref << "FullB <= false;" << endl;
		outfile << endl;

		outfile << "\t\t\t" << chsref << "Aa <= (others => '0');" << endl;
		outfile << "\t\t\tfor i in 0 to NBeat-1 loop" << endl;
		outfile << "\t\t\t\t" << chsref << "Abuf(i) <= (others => '0');" << endl;
		outfile << "\t\t\tend loop;" << endl;
		outfile << endl;

		outfile << "\t\t\t" << chsref << "Ba <= (others => '0');" << endl;
		outfile << "\t\t\tfor i in 0 to NBeat-1 loop" << endl;
		outfile << "\t\t\t\t" << chsref << "Bbuf(i) <= (others => '0');" << endl;
		outfile << "\t\t\tend loop;" << endl;
		outfile << "-- IP impl." << chsref << "GearIgr.asyncrst --- REND" << endl;

		// --- impl.wrXGearIgr.ext
		outfile << "-- IP impl." << chsref << "GearIgr.ext --- RBEGIN" << endl;
		outfile << "\t\t\tif not " << chsref << "FillBNotA and " << chsref << "FullB and " << chsref << "DoneB_" << clkWrs[i] << " then" << endl;
		outfile << "\t\t\t\t" << chsref << "FullB <= false;" << endl;
		outfile << "\t\t\tend if;" << endl;
		outfile << endl;

		outfile << "\t\t\tif " << chsref << "FillBNotA and " << chsref << "FullA and " << chsref << "DoneA_" << clkWrs[i] << " then" << endl;
		outfile << "\t\t\t\t" << chsref << "FullA <= false;" << endl;
		outfile << "\t\t\tend if;" << endl;
		outfile << "-- IP impl." << chsref << "GearIgr.ext --- REND" << endl;

		// --- impl.wrXGearIgr.idle.start
		outfile << "-- IP impl." << chsref << "GearIgr.idle.start --- IBEGIN" << endl;
		outfile << "\t\t\t\t\tif not " << chsref << "FillBNotA then" << endl;
		outfile << "\t\t\t\t\t\t" << chsref << "Aa <= " << chsref << "AXI_awaddr;" << endl;
		outfile << "\t\t\t\t\telse" << endl;
		outfile << "\t\t\t\t\t\t" << chsref << "Ba <= " << chsref << "AXI_awaddr;" << endl;
		outfile << "\t\t\t\t\tend if;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\ti := 0;" << endl;
		outfile << "\t\t\t\t\tj := 0;" << endl;
		outfile << "-- IP impl." << chsref << "GearIgr.idle.start --- IEND" << endl;

		// --- impl.wrXGearIgr.xfer
		outfile << "-- IP impl." << chsref << "GearIgr.xfer --- IBEGIN" << endl;
		outfile << "\t\t\t\t\tif not " << chsref << "FillBNotA then" << endl;
		outfile << "\t\t\t\t\t\t" << chsref << "Abuf(i)(" << wDWrs[i] << "*(j+1)-1 downto " << wDWrs[i] << "*j) <= " << chsref << "AXI_wdata;" << endl;
		outfile << "\t\t\t\t\telse" << endl;
		outfile << "\t\t\t\t\t\t" << chsref << "Bbuf(i)(" << wDWrs[i] << "*(j+1)-1 downto " << wDWrs[i] << "*j) <= " << chsref << "AXI_wdata;" << endl;
		outfile << "\t\t\t\t\tend if;" << endl;
		outfile << "-- IP impl." << chsref << "GearIgr.xfer --- IEND" << endl;

		// --- impl.wrXGearIgr.xfer.beatDone
		outfile << "\t\t\t\t\t\tj := 0; -- IP impl." << chsref << "GearIgr.xfer.beatDone --- ILINE" << endl;

		// --- impl.wrXGearIgr.xfer.burstDone
		outfile << "-- IP impl." << chsref << "GearIgr.xfer.burstDone --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t\t\tif not " << chsref << "FillBNotA then" << endl;
		outfile << "\t\t\t\t\t\t\t\t" << chsref << "FullA <= true;" << endl;
		outfile << "\t\t\t\t\t\t\telse" << endl;
		outfile << "\t\t\t\t\t\t\t\t" << chsref << "FullB <= true;" << endl;
		outfile << "\t\t\t\t\t\t\tend if;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\t\t\t" << chsref << "FillBNotA <= not " << chsref << "FillBNotA;" << endl;
		outfile << "-- IP impl." << chsref << "GearIgr.xfer.burstDone --- IEND" << endl;

		// --- impl.wrXGearIgr.xfer.nextBeat
		outfile << "\t\t\t\t\t\t\ti := i + 1; -- IP impl." << chsref << "GearIgr.xfer.nextBeat --- ILINE" << endl;

		// --- impl.wrXGearIgr.xfer.nextWord
		outfile << "\t\t\t\t\t\tj := j + 1; -- IP impl." << chsref << "GearIgr.xfer.nextWord --- ILINE" << endl;

		// - wrXGearEgr

		// --- impl.wrXGearEgr.ext
		outfile << "-- IP impl." << chsref << "GearEgr.ext --- IBEGIN" << endl;
		outfile << "\t\t\tif " << chsref << "FillBNotA_" << clkWrs[i] << " and not " << chsref << "FullA_" << clkWrs[i] << " and " << chsref << "DoneA then" << endl;
		outfile << "\t\t\t\t" << chsref << "DoneA <= false;" << endl;
		outfile << "\t\t\tend if;" << endl;
		outfile << endl;

		outfile << "\t\t\tif not " << chsref << "FillBNotA_" << clkWrs[i] << " and not " << chsref << "FullB_" << clkWrs[i] << " and " << chsref << "DoneB then" << endl;
		outfile << "\t\t\t\t" << chsref << "DoneB <= false;" << endl;
		outfile << "\t\t\tend if;" << endl;
		outfile << "-- IP impl." << chsref << "GearEgr.ext --- IEND" << endl;

		// --- impl.wrXGearEgr.idle.startA
		outfile << "\t\t\t\t\t" << chsref << "AXI_awaddr_sig <= " << chsref << "Aa; -- IP impl." << chsref << "GearEgr.idle.startA --- ILINE" << endl;

		// --- impl.wrXGearEgr.idle.startB
		outfile << "\t\t\t\t\t" << chsref << "AXI_awaddr_sig <= " << chsref << "Ba; -- IP impl." << chsref << "GearEgr.idle.startB --- ILINE" << endl;

		// --- impl.wrXGearEgr.addr
		outfile << "-- IP impl." << chsref << "GearEgr.addr --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t" << chsref << "AXI_wlast_sig <= '0';" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\tif " << chsref << "FillBNotA_" << clkWrs[i] << " then" << endl;
		outfile << "\t\t\t\t\t\t" << chsref << "AXI_wdata_sig <= " << chsref << "Abuf(i);" << endl;
		outfile << "\t\t\t\t\telse" << endl;
		outfile << "\t\t\t\t\t\t" << chsref << "AXI_wdata_sig <= " << chsref << "Bbuf(i);" << endl;
		outfile << "\t\t\t\t\tend if;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\ti := 0;" << endl;
		outfile << "-- IP impl." << chsref << "GearEgr.addr --- IEND" << endl;

		// --- impl.wrXGearEgr.xfer.done
		outfile << "-- IP impl." << chsref << "GearEgr.xfer.done --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t\tif " << chsref << "FillBNotA_" << clkWrs[i] << " then" << endl;
		outfile << "\t\t\t\t\t\t\t" << chsref << "DoneA <= true;" << endl;
		outfile << "\t\t\t\t\t\telse" << endl;
		outfile << "\t\t\t\t\t\t\t" << chsref << "DoneB <= true;" << endl;
		outfile << "\t\t\t\t\t\tend if;" << endl;
		outfile << "-- IP impl." << chsref << "GearEgr.xfer.done --- IEND" << endl;

		// --- impl.wrXGearEgr.xfer.next
		outfile << "-- IP impl." << chsref << "GearEgr.xfer.next --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t\ti := i + 1;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\t\tif " << chsref << "FillBNotA_" << clkWrs[i] << " then" << endl;
		outfile << "\t\t\t\t\t\t\t" << chsref << "AXI_wdata_sig <= " << chsref << "Abuf(i);" << endl;
		outfile << "\t\t\t\t\t\telse" << endl;
		outfile << "\t\t\t\t\t\t\t" << chsref << "AXI_wdata_sig <= " << chsref << "Bbuf(i);" << endl;
		outfile << "\t\t\t\t\t\tend if;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\t\tif i=imax-1 then" << endl;
		outfile << "\t\t\t\t\t\t\t" << chsref << "AXI_wlast_sig <= '1';" << endl;
		outfile << "\t\t\t\t\t\tend if;" << endl;
		outfile << "-- IP impl." << chsref << "GearEgr.xfer.next --- IEND" << endl;
	};
};

string WdbeMtpWrfpgaDdrmux_Easy_v1_0::getChsref(
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
