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

	wD = 128;
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "wD", s)) wD = atoi(s.c_str());

	rdflex = false;
	rdgear = false;

	NRd = 1;
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "NRd", s)) NRd = atoi(s.c_str());

	flexNBeatRds.resize(NRd, false);
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "flexNBeatRds", s)) {
		StrMod::stringToVector(s, ss);
		if (ss.size() == NRd)
			for (unsigned int i = 0; i < NRd; i++)
				if (ss[i] == "true") {
					flexNBeatRds[i] = true;
					rdflex = true;
				};
	};

	NBeatRd = 16;
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "NBeatRd", s)) NBeatRd = atoi(s.c_str());

	wDRds.resize(NRd, wD);
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "wDRds", s)) {
		StrMod::stringToVector(s, ss);

		if (ss.size() == NRd) {
			for (unsigned int i = 0; i < NRd; i++) {
				wDRds[i] = atoi(ss[i].c_str());
				if (wDRds[i] != wD) rdgear = true;
			};
		};
	};

	clkRds.resize(NRd, memclk);
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "clkRds", s)) {
		StrMod::stringToVector(s, ss);
		if (ss.size() == NRd) clkRds = ss;
		for (unsigned int i = 0; i < clkRds.size(); i++)
			if (clkRds[i] == "memclk") clkRds[i] = "";
			else clkRds[i] = "_" + clkRds[i];
	};

	ratioClkRds.resize(NRd, 1.0);
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "ratioClkRds", s)) {
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
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "NWr", s)) NWr = atoi(s.c_str());

	flexNBeatWrs.resize(NWr, false);
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "flexNBeatWrs", s)) {
		StrMod::stringToVector(s, ss);
		if (ss.size() == NWr)
			for (unsigned int i = 0; i < NWr; i++)
				if (ss[i] == "true") {
					flexNBeatWrs[i] = true;
					wrflex = true;
				};
	};

	NBeatWr = 16;
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "NBeatWr", s)) NBeatWr = atoi(s.c_str());

	wDWrs.resize(NWr, wD);
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "wDWrs", s)) {
		StrMod::stringToVector(s, ss);

		if (ss.size() == NWr) {
			for (unsigned int i = 0; i < NWr; i++) {
				wDWrs[i] = atoi(ss[i].c_str());
				if (wDWrs[i] != wD) wrgear = true;
			};
		};
	};

	clkWrs.resize(NWr, memclk);
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "clkWrs", s)) {
		StrMod::stringToVector(s, ss);
		if (ss.size() == NWr) clkWrs = ss;
		for (unsigned int i = 0; i < clkWrs.size(); i++)
			if (clkWrs[i] == "memclk") clkWrs[i] = "";
			else clkWrs[i] = "_" + clkWrs[i];
	};

	ratioClkWrs.resize(NWr, 1.0);
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "ratioClkWrs", s)) {
		StrMod::stringToVector(s, ss);
		if (ss.size() == NWr) for (unsigned int i = 0; i < NWr; i++) ratioClkWrs[i] = atof(ss[i].c_str());
	};

	if (wrgear) {
		for (unsigned int i = 0; i < NWr; i++) flexNBeatWrs[i] = false;
		wrflex = false;
	};

	///
	unsigned int w;

	bool first;

	if (NRd > 0) {
		// - read

		mutexsref = "";
		for (unsigned int i = 0; i < NRd; i++) mutexsref += string(1, (char) (0x61+i));
		mutexsref += "Rd";

		// --- impl.read.wiring.cust
		outfile << "-- IP impl.read.wiring.cust --- RBEGIN" << endl;

		outfile << "\tddrAXI_araddr <= ";
		for (unsigned int i = 0; i < NRd; i++) {
			outfile << "\"" << aConst << "\" & " << getChsref(false, i, false) << "AXI_araddr";
			if (wDRds[i] != wD) outfile << "_sig";
			w = log2(wD/8);
			if (!flexNBeatRds[i]) w += log2(NBeatRd);
			outfile << " & \"" << string(w, '0') << "\" when rdmutex=mutex" << string(1, (char) (0x41+i)) << endl;
			outfile << "\t\t\t\telse ";
		};
		outfile << "(others => '0');" << endl;
		outfile << endl;

		if (rdflex) {
			outfile << "\tddrAXI_arlen <= ";
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
			if (NBeatRd == 4) outfile << "03";
			else if (NBeatRd == 8) outfile << "07";
			else if (NBeatRd == 16) outfile << "0F";
			else if (NBeatRd == 32) outfile << "1F";
			else if (NBeatRd == 64) outfile << "3F";
			else if (NBeatRd == 128) outfile << "7F";
			else if (NBeatRd == 256) outfile << "FF";
			outfile << "\"; -- burst length of " << NBeatRd << endl;
			outfile << endl;
		};

		outfile << "\tddrAXI_arvalid <= ";
		for (unsigned int i = 0; i < NRd; i++) {
			outfile << getChsref(false, i, false) << "AXI_arvalid";
			if (wDRds[i] != wD) outfile << "_sig";
			outfile << " when rdmutex=mutex" << string(1, (char) (0x41+i)) << endl;
			outfile << "\t\t\t\telse ";
		};
		outfile << "'0';" << endl;
		outfile << endl;

		outfile << "\tddrAXI_rready <= ";
		for (unsigned int i = 0; i < NRd; i++) {
			outfile << getChsref(false, i, false) << "AXI_rready";
			if (wDRds[i] != wD) outfile << "_sig";
			outfile << " when rdid(ixRdidEgr)=mutex" << string(1, (char) (0x41+i)) << endl;
			outfile << "\t\t\t\telse ";
		};
		outfile << "'0';" << endl;
		outfile << endl;

		outfile << "-- IP impl.read.wiring.cust --- REND" << endl;

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

		// --- impl.write.wiring.cust
		outfile << "-- IP impl.write.wiring.cust --- RBEGIN" << endl;

		outfile << "\tddrAXI_awaddr <= ";
		for (unsigned int i = 0; i < NWr; i++) {
			outfile << "\"" << aConst << "\" & " << getChsref(true, i, false) << "AXI_awaddr";
			if (wDWrs[i] != wD) outfile << "_sig";
			w = log2(wD/8);
			if (!flexNBeatWrs[i]) w += log2(NBeatWr);
			outfile << " & \"" << string(w, '0') << "\" when wrmutex=mutex" << string(1, (char) (0x41+i)) << endl;
			outfile << "\t\t\t\telse ";
		};
		outfile << "(others => '0');" << endl;
		outfile << endl;

		if (wrflex) {
			outfile << "\tddrAXI_awlen <= ";
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
			if (NBeatWr == 4) outfile << "03";
			else if (NBeatWr == 8) outfile << "07";
			else if (NBeatWr == 16) outfile << "0F";
			else if (NBeatWr == 32) outfile << "1F";
			else if (NBeatWr == 64) outfile << "3F";
			else if (NBeatWr == 128) outfile << "7F";
			else if (NBeatWr == 256) outfile << "FF";
			outfile << "\"; -- burst length of " << NBeatWr << endl;
			outfile << endl;
		};

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

		outfile << "\tddrAXI_wlast <= ";
		for (unsigned int i = 0; i < NWr; i++) {
			outfile << getChsref(true, i, false) << "AXI_wlast";
			if (wDWrs[i] != wD) outfile << "_sig";
			outfile << " when wrmutex=mutex" << string(1, (char) (0x41+i)) << endl;
			outfile << "\t\t\t\telse ";
		};
		outfile << "'1';" << endl;
		outfile << endl;

		outfile << "\tddrAXI_wvalid <= ";
		for (unsigned int i = 0; i < NWr; i++) {
			outfile << getChsref(true, i, false) << "AXI_wvalid";
			if (wDWrs[i] != wD) outfile << "_sig";
			outfile << " when wrmutex=mutex" << string(1, (char) (0x41+i)) << endl;
			outfile << "\t\t\t\telse ";
		};
		outfile << "'0';" << endl;
		outfile << endl;

		outfile << "-- IP impl.write.wiring.cust --- REND" << endl;

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
		outfile << "\t\t\tstate" << StrMod::cap(chsref) << "GearIgr <= state" << StrMod::cap(chsref) << "GearIgrInit;" << endl;
		outfile << "\t\t\t" << chsref << "AXI_araddr_sig <= (others => '0');" << endl;
		outfile << "\t\t\t" << chsref << "AXI_araddr_sig <= (others => '0');" << endl;
		outfile << "\t\t\t" << chsref << "Full <= false;" << endl;
		outfile << "\t\t\tfor i in 0 to NBeatRd-1 loop" << endl;
		outfile << "\t\t\t\t" << chsref << "Buf(i) <= (others => '0');" << endl;
		outfile << "\t\t\tend loop;" << endl;
		outfile << "-- IP impl." << chsref << "GearIgr.asyncrst --- REND" << endl;

		// --- impl.rdXGearIgr.ext
		outfile << "-- IP impl." << chsref << "GearIgr.ext --- IBEGIN" << endl;
		outfile << "\t\t\tif not " << chsref << "Ready" << clkRds[i] << " and " << chsref << "Full then" << endl;
		outfile << "\t\t\t\t" << chsref << "Full <= false;" << endl;
		outfile << "\t\t\tend if;" << endl;
		outfile << "-- IP impl." << chsref << "GearIgr.ext --- IEND" << endl;

		// --- impl.rdXGearIgr.syncrst
		outfile << "-- IP impl." << chsref << "GearIgr.syncrst --- RBEGIN" << endl;
		outfile << "\t\t\t\t" << chsref << "AXI_araddr_sig <= (others => '0');" << endl;
		outfile << "\t\t\t\t" << chsref << "AXI_araddr_sig <= (others => '0');" << endl;
		outfile << "\t\t\t\t" << chsref << "Full <= false;" << endl;
		outfile << "\t\t\t\tfor i in 0 to NBeatRd-1 loop" << endl;
		outfile << "\t\t\t\t\t" << chsref << "Buf(i) <= (others => '0');" << endl;
		outfile << "\t\t\t\tend loop;" << endl;
		outfile << "-- IP impl." << chsref << "GearIgr.syncrst --- REND" << endl;

		// --- impl.rdXGearIgr.idle
		outfile << "\t\t\t\t\t" << chsref << "AXI_araddr_sig <= " << chsref << "A; -- IP impl." << chsref << "GearIgr.idle --- ILINE" << endl;

		// --- impl.rdXGearIgr.addr
		outfile << "\t\t\t\t\ti := 0; -- IP impl." << chsref << "GearIgr.addr --- ILINE" << endl;

		// --- impl.rdXGearIgr.xfer.copy
		outfile << "\t\t\t\t\t" << chsref << "Buf(i) <= " << chsref << "AXI_rdata_sig; -- IP impl." << chsref << "GearIgr.xfer.copy --- ILINE" << endl;

		// --- impl.rdXGearIgr.xfer.done
		outfile << "\t\t\t\t\t\t" << chsref << "Full <= true; -- IP impl." << chsref << "GearIgr.xfer.done --- ILINE" << endl;
		outfile << endl;

		// --- impl.rdXGearIgr.xfer.inc
		outfile << "\t\t\t\t\t\ti := i + 1; -- IP impl." << chsref << "GearIgr.xfer.inc --- ILINE" << endl;
		outfile << endl;

		// - rdXGearEgr

		// --- impl.rdXGearEgr.addr
		outfile << "-- IP impl." << chsref << "GearEgr.addr --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t" << chsref << "A <= " << chsref << "AXI_araddr;" << endl;
		outfile << "\t\t\t\t\t" << chsref << "Ready <= true;" << endl;
		outfile << "-- IP impl." << chsref << "GearEgr.addr --- IEND" << endl;

		// --- impl.rdXGearEgr.waitFull.done
		outfile << "-- IP impl." << chsref << "GearEgr.waitFull.done --- IBEGIN" << endl;
		outfile << "\t\t\t\t\ti := 0;" << endl;
		outfile << "\t\t\t\t\tj := 0;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\t" << chsref << "AXI_rdata_oprt <= " << chsref << "Buf(i)(" << chsref << "WD-1 downto 0);" << endl;
		outfile << "\t\t\t\t\t" << chsref << "AXI_rlast_oprt <= '0';" << endl;
		outfile << "-- IP impl." << chsref << "GearEgr.waitFull.done --- IEND" << endl;

		// --- impl.rdXGearEgr.xfer.beatDone
		outfile << "\t\t\t\t\t\tj := 0; -- IP impl." << chsref << "GearEgr.xfer.beatDone --- ILINE" << endl;

		// --- impl.rdXGearEgr.xfer.burstDone
		outfile << "\t\t\t\t\t\t\t" << chsref << "Ready <= false; -- IP impl." << chsref << "GearEgr.xfer.burstDone --- ILINE" << endl;

		// --- impl.rdXGearEgr.xfer.nextBeat
		outfile << "-- IP impl." << chsref << "GearEgr.xfer.nextBeat --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t\t\ti := i + 1;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\t\t\t" << chsref << "AXI_rdata_oprt <= " << chsref << "Buf(i)(" << chsref << "WD*(j+1)-1 downto " << chsref << "WD*j);" << endl;
		outfile << "-- IP impl." << chsref << "GearEgr.xfer.nextBeat --- IEND" << endl;

		// --- impl.rdXGearEgr.xfer.nextWord
		outfile << "-- IP impl." << chsref << "GearEgr.xfer.nextWord --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t\tj := j + 1;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\t\t" << chsref << "AXI_rdata_oprt <= " << chsref << "Buf(i)(" << chsref << "WD*(j+1)-1 downto " << chsref << "WD*j);" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\t\tif i=NBeatRd-1 and j=jmax then" << endl;
		outfile << "\t\t\t\t\t\t\t" << chsref << "AXI_rlast_oprt <= '1';" << endl;
		outfile << "\t\t\t\t\t\tend if;" << endl;
		outfile << "-- IP impl." << chsref << "GearEgr.xfer.nextWord --- IEND" << endl;
	};

	for (unsigned int i = 0; i < NWr; i++) if (wDWrs[i] != wD) {
		chsref = getChsref(true, i, false);

		// - wrXGearIgr

		// --- impl.wrXGearIgr.asyncrst
		outfile << "-- IP impl." << chsref << "GearIgr.asyncrst --- RBEGIN" << endl;
		outfile << "\t\t\tstate" << StrMod::cap(chsref) << "GearIgr <= state" << StrMod::cap(chsref) << "GearIgrInit;" << endl;
		outfile << "\t\t\t" << chsref << "FillBNotA <= true;" << endl;
		outfile << "\t\t\t" << chsref << "FullA <= false;" << endl;
		outfile << "\t\t\t" << chsref << "FullB <= false;" << endl;
		outfile << "\t\t\t" << chsref << "Aa <= (others => '0');" << endl;
		outfile << "\t\t\tfor i in 0 to NBeatWr-1 loop" << endl;
		outfile << "\t\t\t\t" << chsref << "Abuf(i) <= (others => '0');" << endl;
		outfile << "\t\t\tend loop;" << endl;
		outfile << "\t\t\t" << chsref << "Ba <= (others => '0');" << endl;
		outfile << "\t\t\tfor i in 0 to NBeatWr-1 loop" << endl;
		outfile << "\t\t\t\t" << chsref << "Bbuf(i) <= (others => '0');" << endl;
		outfile << "\t\t\tend loop;" << endl;
		outfile << "-- IP impl." << chsref << "GearIgr.asyncrst --- REND" << endl;

		// --- impl.wrXGearIgr.ext
		outfile << "-- IP impl." << chsref << "GearIgr.ext --- IBEGIN" << endl;
		outfile << "\t\t\tif not " << chsref << "FillBNotA and " << chsref << "FullB and " << chsref << "DoneB" << clkWrs[i] << " then" << endl;
		outfile << "\t\t\t\t" << chsref << "FullB <= false;" << endl;
		outfile << "\t\t\tend if;" << endl;
		outfile << endl;

		outfile << "\t\t\tif " << chsref << "FillBNotA and " << chsref << "FullA and " << chsref << "DoneA" << clkWrs[i] << " then" << endl;
		outfile << "\t\t\t\t" << chsref << "FullA <= false;" << endl;
		outfile << "\t\t\tend if;" << endl;
		outfile << "-- IP impl." << chsref << "GearIgr.ext --- IEND" << endl;

		// --- impl.wrXGearIgr.syncrst
		outfile << "-- IP impl." << chsref << "GearIgr.syncrst --- RBEGIN" << endl;
		outfile << "\t\t\t\t" << chsref << "FillBNotA <= true;" << endl;
		outfile << "\t\t\t\t" << chsref << "FullA <= false;" << endl;
		outfile << "\t\t\t\t" << chsref << "FullB <= false;" << endl;
		outfile << "\t\t\t\t" << chsref << "Aa <= (others => '0');" << endl;
		outfile << "\t\t\t\tfor i in 0 to NBeatWr-1 loop" << endl;
		outfile << "\t\t\t\t\t" << chsref << "Abuf(i) <= (others => '0');" << endl;
		outfile << "\t\t\t\tend loop;" << endl;
		outfile << "\t\t\t\t" << chsref << "Ba <= (others => '0');" << endl;
		outfile << "\t\t\t\tfor i in 0 to NBeatWr-1 loop" << endl;
		outfile << "\t\t\t\t\t" << chsref << "Bbuf(i) <= (others => '0');" << endl;
		outfile << "\t\t\t\tend loop;" << endl;
		outfile << "-- IP impl." << chsref << "GearIgr.syncrst --- REND" << endl;

		// --- impl.wrXGearIgr.addr
		outfile << "-- IP impl." << chsref << "GearIgr.addr --- IBEGIN" << endl;
		outfile << "\t\t\t\t\tif not " << chsref << "FillBNotA then" << endl;
		outfile << "\t\t\t\t\t\t" << chsref << "Aa <= " << chsref << "AXI_awaddr;" << endl;
		outfile << "\t\t\t\t\telse" << endl;
		outfile << "\t\t\t\t\t\t" << chsref << "Ba <= " << chsref << "AXI_awaddr;" << endl;
		outfile << "\t\t\t\t\tend if;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\ti := 0;" << endl;
		outfile << "\t\t\t\t\tj := 0;" << endl;
		outfile << "-- IP impl." << chsref << "GearIgr.addr --- IEND" << endl;

		// --- impl.wrXGearIgr.xfer
		outfile << "-- IP impl." << chsref << "GearIgr.xfer --- IBEGIN" << endl;
		outfile << "\t\t\t\t\tif not " << chsref << "FillBNotA then" << endl;
		outfile << "\t\t\t\t\t\t" << chsref << "Abuf(i)(" << chsref << "WD*(j+1)-1 downto " << chsref << "WD*j) <= " << chsref << "AXI_wdata;" << endl;
		outfile << "\t\t\t\t\telse" << endl;
		outfile << "\t\t\t\t\t\t" << chsref << "Bbuf(i)(" << chsref << "WD*(j+1)-1 downto " << chsref << "WD*j) <= " << chsref << "AXI_wdata;" << endl;
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
		outfile << "\t\t\tif " << chsref << "FillBNotA" << clkWrs[i] << " and not " << chsref << "FullA" << clkWrs[i] << " and " << chsref << "DoneA then" << endl;
		outfile << "\t\t\t\t" << chsref << "DoneA <= false;" << endl;
		outfile << "\t\t\tend if;" << endl;
		outfile << endl;

		outfile << "\t\t\tif not " << chsref << "FillBNotA" << clkWrs[i] << " and not " << chsref << "FullB" << clkWrs[i] << " and " << chsref << "DoneB then" << endl;
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

		outfile << "\t\t\t\t\tif " << chsref << "FillBNotA" << clkWrs[i] << " then" << endl;
		outfile << "\t\t\t\t\t\t" << chsref << "AXI_wdata_sig <= " << chsref << "Abuf(0);" << endl;
		outfile << "\t\t\t\t\telse" << endl;
		outfile << "\t\t\t\t\t\t" << chsref << "AXI_wdata_sig <= " << chsref << "Bbuf(0);" << endl;
		outfile << "\t\t\t\t\tend if;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\ti := 0;" << endl;
		outfile << "-- IP impl." << chsref << "GearEgr.addr --- IEND" << endl;

		// --- impl.wrXGearEgr.xfer.done
		outfile << "-- IP impl." << chsref << "GearEgr.xfer.done --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t\tif " << chsref << "FillBNotA" << clkWrs[i] << " then" << endl;
		outfile << "\t\t\t\t\t\t\t" << chsref << "DoneA <= true;" << endl;
		outfile << "\t\t\t\t\t\telse" << endl;
		outfile << "\t\t\t\t\t\t\t" << chsref << "DoneB <= true;" << endl;
		outfile << "\t\t\t\t\t\tend if;" << endl;
		outfile << "-- IP impl." << chsref << "GearEgr.xfer.done --- IEND" << endl;

		// --- impl.wrXGearEgr.xfer.next
		outfile << "-- IP impl." << chsref << "GearEgr.xfer.next --- IBEGIN" << endl;
		outfile << "\t\t\t\t\t\ti := i + 1;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\t\tif " << chsref << "FillBNotA" << clkWrs[i] << " then" << endl;
		outfile << "\t\t\t\t\t\t\t" << chsref << "AXI_wdata_sig <= " << chsref << "Abuf(i);" << endl;
		outfile << "\t\t\t\t\t\telse" << endl;
		outfile << "\t\t\t\t\t\t\t" << chsref << "AXI_wdata_sig <= " << chsref << "Bbuf(i);" << endl;
		outfile << "\t\t\t\t\t\tend if;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\t\tif i=NBeatWr-1 then" << endl;
		outfile << "\t\t\t\t\t\t\t" << chsref << "AXI_wlast_sig <= '1';" << endl;
		outfile << "\t\t\t\t\t\tend if;" << endl;
		outfile << "-- IP impl." << chsref << "GearEgr.xfer.next --- IEND" << endl;
	};

	// --- impl.oth.cust
	outfile << "-- IP impl.oth.cust --- IBEGIN" << endl;
	if (NRd == 0) {
		outfile << "\tddrAXI_arid <= (others => '0');" << endl;
		outfile << "\tddrAXI_araddr <= (others => '0');" << endl;
		outfile << "\tddrAXI_arburst <= (others => '0');" << endl;
		outfile << "\tddrAXI_arcache <= (others => '0');" << endl;
		outfile << "\tddrAXI_arlen <= (others => '0');" << endl;
		outfile << "\tddrAXI_arlock <= (others => '0');" << endl;
		outfile << "\tddrAXI_arprot <= (others => '0');" << endl;
		outfile << "\tddrAXI_arqos <= (others => '0');" << endl;
		outfile << "\tddrAXI_arregion <= (others => '0');" << endl;
		outfile << "\tddrAXI_arsize <= (others => '0');" << endl;
		outfile << "\tddrAXI_arvalid <= '0';" << endl;
		outfile << endl;

		outfile << "\tddrAXI_rready <= '0';" << endl;

	} else if (NWr == 0) {
		outfile << "\tddrAXI_awid <= (others => '0');" << endl;
		outfile << "\tddrAXI_awaddr <= (others => '0');" << endl;
		outfile << "\tddrAXI_awburst <= (others => '0');" << endl;
		outfile << "\tddrAXI_awcache <= (others => '0');" << endl;
		outfile << "\tddrAXI_awlen <= (others => '0');" << endl;
		outfile << "\tddrAXI_awlock <= (others => '0');" << endl;
		outfile << "\tddrAXI_awprot <= (others => '0');" << endl;
		outfile << "\tddrAXI_awqos <= (others => '0');" << endl;
		outfile << "\tddrAXI_awregion <= (others => '0');" << endl;
		outfile << "\tddrAXI_awsize <= (others => '0');" << endl;
		outfile << "\tddrAXI_awvalid <= '0';" << endl;
		outfile << endl;

		outfile << "\tddrAXI_wdata <= (others => '0');" << endl;
		outfile << "\tddrAXI_wlast <= '1';" << endl;
		outfile << "\tddrAXI_wstrb <= (others => '0');" << endl;
		outfile << "\tddrAXI_wvalid <= '0';" << endl;
		outfile << endl;

		outfile << "\tddrAXI_bready <= '0';" << endl;
	};
	outfile << "-- IP impl.oth.cust --- IEND" << endl;
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
