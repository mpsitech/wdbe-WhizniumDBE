/**
	* \file WdbeMtpWrfpgaFsmtrack_Easy_v1_0.cpp
	* Wdbe operation processor -  (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpWrfpgaFsmtrack_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpWrfpgaFsmtrack_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaFsmtrack_Easy_v1_0::run(
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
void WdbeMtpWrfpgaFsmtrack_Easy_v1_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	bool hascdc;

	string cross;

	string capts; // ex. tkclksrc.op;camif.stream.cdc (.cdc optional)
	string trigs; // ex. strbFrame.strb.cdc;ackXyz.falling (choice of rising/falling/strb; .cdc optional)

	vector<string> ss, ss2;
	string s;

	bool first;

	Wdbe::getMpa(dbswdbe, mdl->ref, "trkclk", s);
	hascdc = (s != "mclk");
	if (hascdc) cross = "_" + s;

	// --- sigs.cdc*
	if (hascdc) outfile << "-- IP sigs.cdc --- AFFIRM" << endl;
	else outfile << "-- IP sigs.cdc --- REMOVE" << endl;

	// --- impl.op.state
	outfile << "-- IP impl.op.state --- IBEGIN" << endl;
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "capts", capts)) StrMod::stringToVector(capts, ss, ';');

	outfile << "\tstate <=";

	first = true;

	for (unsigned int i = 0; i < ss.size(); i++) {
		StrMod::stringToVector(ss[i], ss2, '.');

		if (ss2.size() >= 2) {
			if (first) first = false;
			else  outfile << "\t\t\t\telse";

			outfile << " " << ss2[0] << "State" << StrMod::cap(ss2[1]);
			if (ss2.size() == 3) if (ss2[2] == "cdc") outfile << cross;
			outfile << " when tixVSource" << cross << "=tixVSource" << StrMod::cap(ss2[0]) << StrMod::cap(ss2[1]) << endl;
		}
	};

	if (!first) outfile << "\t\t\t\telse";
	outfile << " (others => '1');" << endl;

	outfile << "-- IP impl.op.state --- IEND" << endl;

	// --- impl.op.start
	ss.clear();
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "trigs", trigs)) StrMod::stringToVector(trigs, ss, ';');

	outfile << "-- IP impl.op.start --- IBEGIN" << endl;

	outfile << "\tstart <=";

	first = true;

	for (unsigned int i = 0; i < ss.size(); i++) {
		StrMod::stringToVector(ss[i], ss2, '.');

		if (ss2.size() >= 2) {
			if (first) first = false;
			else outfile << "\t\t\t\telse";

			if (ss2[1] == "falling") outfile << " not";
			outfile << " " << ss2[0];
			if (ss2.size() == 3) if (ss2[2] == "cdc") outfile << cross;
			outfile << " when staTixVTrigger" << cross << "=tixVTrigger" << StrMod::cap(ss2[0]) << endl;
		};
	};

	if (!first) outfile << "\t\t\t\telse";
	outfile << " '0';" << endl;

	outfile << "-- IP impl.op.start --- IEND" << endl;

	// --- impl.op.stop
	outfile << "-- IP impl.op.stop --- IBEGIN" << endl;

	outfile << "\tstop <=";

	first = true;

	for (unsigned int i = 0; i < ss.size(); i++) {
		StrMod::stringToVector(ss[i], ss2, '.');

		if (ss2.size() >= 2) {
			if (first) first = false;
			else outfile << "\t\t\t\telse";

			if (ss2[1] == "falling") outfile << " not";
			outfile << " " << ss2[0];
			if (ss2.size() == 3) if (ss2[2] == "cdc") outfile << cross;
			outfile << " when stoTixVTrigger" << cross << "=tixVTrigger" << StrMod::cap(ss2[0]) << endl;
		};
	};

	if (!first) outfile << "\t\t\t\telse";
	outfile << " '0';" << endl;

	outfile << "-- IP impl.op.stop --- IEND" << endl;

	// --- impl.cdc*
	if (hascdc) outfile << "-- IP impl.cdc --- AFFIRM" << endl;
	else outfile << "-- IP impl.cdc --- REMOVE" << endl;
};
// IP cust --- IEND
