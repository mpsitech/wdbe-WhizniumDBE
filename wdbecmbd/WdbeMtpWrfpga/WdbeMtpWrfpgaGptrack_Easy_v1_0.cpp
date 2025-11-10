/**
	* \file WdbeMtpWrfpgaGptrack_Easy_v1_0.cpp
	* Wdbe operation processor -  (implementation)
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

#include "WdbeMtpWrfpgaGptrack_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpWrfpgaGptrack_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaGptrack_Easy_v1_0::run(
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

		// xxxx/Fsmtrack.vhd
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
void WdbeMtpWrfpgaGptrack_Easy_v1_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	bool hascdc;

	string cross;

	string capts; // ex. tkclksrc.op;camif.stream.cdc (.cdc optional)
	string trigs; // ex. strbFrame.cdc;ackXyz (.cdc optional)

	string sref;
	bool hasrng;
	utinyint from, to;
	string ix;

	vector<string> ss, ss2;
	string s;

	unsigned int w;

	bool first;

	Wdbe::getMpa(dbswdbe, mdl->ref, "trkclk", s);
	hascdc = (s != "mclk");
	if (hascdc) cross = "_" + s;

	// --- sigs.cdc*
	if (hascdc) outfile << "-- IP sigs.cdc --- AFFIRM" << endl;
	else outfile << "-- IP sigs.cdc --- REMOVE" << endl;

	// --- impl.sample.capt
	outfile << "-- IP impl.sample.capt --- IBEGIN" << endl;
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "capts", capts)) StrMod::stringToVector(capts, ss, ';');

	s = "";
	w = 0;

	for (unsigned int i = 0; i < ss.size(); i++) {
		Wdbe::getRange(ss[i], sref, hasrng, from, to, ix);

		if (i != 0) s = " & " + s;
		s = sref + s;

		if (!hasrng) w++;
		else w += (to-from+1);
	};

	if (w != 15) {
		if (ss.size() != 0) s = " & " + s;
		s = "\"" + string(15-w, '0') + "\"" + s;
	};

	outfile << "\t\t\tcapt <= " << s << ";" << endl;

	outfile << "-- IP impl.sample.capt --- IEND" << endl;

	// --- impl.sample.start
	ss.clear();
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "trigs", trigs)) StrMod::stringToVector(trigs, ss, ';');

	outfile << "-- IP impl.sample.start --- IBEGIN" << endl;

	for (unsigned int i = 0; i < ss.size(); i++) {
		StrMod::stringToVector(ss[i], ss2, '.');

		if (ss2.size() >= 1) {
			outfile << "\t\t\t\twhen tixVTrigger" << StrMod::cap(ss2[0]) << " =>" << endl;
			outfile << "\t\t\t\t\tstart <= " << ss2[0];
			if (ss2.size() >= 2) if (ss2[1] == "cdc") outfile << cross;
			outfile << ";" << endl;
		};
	};

	outfile << "-- IP impl.sample.start --- IEND" << endl;

	// --- impl.sample.stop
	outfile << "-- IP impl.sample.stop --- IBEGIN" << endl;

	for (unsigned int i = 0; i < ss.size(); i++) {
		StrMod::stringToVector(ss[i], ss2, '.');

		if (ss2.size() >= 1) {
			outfile << "\t\t\t\twhen tixVTrigger" << StrMod::cap(ss2[0]) << " =>" << endl;
			outfile << "\t\t\t\t\tstop <= " << ss2[0];
			if (ss2.size() >= 2) if (ss2[1] == "cdc") outfile << cross;
			outfile << ";" << endl;
		};
	};

	outfile << "-- IP impl.sample.stop --- IEND" << endl;

	// --- impl.cdc*
	if (hascdc) outfile << "-- IP impl.cdc --- AFFIRM" << endl;
	else outfile << "-- IP impl.cdc --- REMOVE" << endl;
};
// IP cust --- IEND
