/**
	* \file WdbeWrfpgaTop.cpp
	* Wdbe operation processor - write type-specific VHDL code (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 16 Oct 2021
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeWrfpgaTop.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeWrfpgaTop
 ******************************************************************************/

DpchRetWdbe* WdbeWrfpgaTop::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrfpgaTop* dpchinv
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

		// xxxx/Top.vhd
		s = xchg->tmppath + "/" + folder + "/" + Compsref + ".vhd.ip";
		outfile.open(s.c_str(), ios::out);
		writeMdlVhd(dbswdbe, outfile, Prjshort, Untsref, mdl);
		outfile.close();

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeWrfpgaTop::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const string& Prjshort
			, const string& Untsref
			, WdbeMModule* mdl
		) {
	unsigned int NClk;

	vector<string> clks;

	vector<string> ss;
	string s;

	ListWdbeMSignal sigs;
	WdbeMSignal* sig = NULL;

	string reqRequest;

	NClk = 1;
	clks.resize(NClk, "mclk");

	if (Wdbe::getMpa(dbswdbe, mdl->ref, "clks", s)) {
		StrMod::stringToVector(s, ss);

		if (ss.size() > 1) {
			NClk = ss.size();
			clks.resize(NClk, "mclk");
		};

		for (unsigned int i = 0; i < NClk; i++) clks[i] = ss[i];
	};

	dbswdbe->tblwdbemsignal->loadRstBySQL("SELECT * FROM TblWdbeMSignal WHERE ixVBasetype = " + to_string(VecWdbeVMSignalBasetype::HSHK) + " AND refIxVTbl = " + to_string(VecWdbeVMSignalRefTbl::MDL)
				+ " AND refUref = " + to_string(mdl->ref) + " AND sref LIKE 'reqReset%' ORDER BY sref ASC", false, sigs);

	for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
		sig = sigs.nodes[i];

		if (i != 0) reqRequest += " or ";
		reqRequest += sig->sref + "='1'";
	};

	for (unsigned int i = 0; i < NClk; i++) {
		if (i != 0) {
			// --- impl.xxxclk.ext
			outfile << "\t\t\t-- IP impl." << clks[i] << ".ext --- IBEGIN" << endl;
			outfile << "\t\t\tif reset_to_" << clks[i] << "m1=reset_to_" << clks[i] << "m2 then" << endl;
			outfile << "\t\t\t\treset_" << clks[i] << " <= reset_to_" << clks[i] << "m2;" << endl;
			outfile << "\t\t\tend if;" << endl;
			outfile << "\t\t\treset_to_" << clks[i] << "m1 <= reset;" << endl;
			outfile << "\t\t\treset_to_" << clks[i] << "m2 <= reset_to_" << clks[i] << "m1;" << endl;
			outfile << "\t\t\t-- IP impl." << clks[i] << ".ext --- IEND" << endl;
		};

		// --- impl.xxxclk.reset.done
		outfile << "\t\t\t\t\t";
		if (i != 0) outfile << "\t";
		outfile << "reset";
		if (i != 0) outfile << StrMod::cap(clks[i]);
		outfile << " <= '0'; -- IP impl." << clks[i] << ".reset.done --- ILINE" << endl;

		// --- impl.xxxclk.reset.inc
		outfile << "\t\t\t\t\ti := i + 1; -- IP impl." << clks[i] << ".reset.inc --- ILINE" << endl;

		if (i == 0) {
			// --- impl.xxxclk.run
			outfile << "\t\t\t\t-- IP impl." << clks[i] << ".run --- IBEGIN" << endl;
			if (reqRequest != "") {
				outfile << "\t\t\t\tif " << reqRequest << " then" << endl;
				outfile << "\t\t\t\t\treset <= '1';" << endl;
				outfile << endl;

				outfile << "\t\t\t\t\ti := 0;" << endl;
				outfile << endl;

				outfile << "\t\t\t\t\tstate" << StrMod::cap(clks[i]) << " <= state" << StrMod::cap(clks[i]) << "Reset;" << endl;
				outfile << "\t\t\t\tend if;" << endl;
			};
			outfile << "\t\t\t\t-- IP impl." << clks[i] << ".run --- IEND" << endl;

		} else {
			// --- impl.xxxclk.run.reset
			outfile << "\t\t\t\t\t-- IP impl." << clks[i] << ".run.reset --- IBEGIN" << endl;
			outfile << "\t\t\t\t\treset" << StrMod::cap(clks[i]) << " <= '1';" << endl;
			outfile << endl;

			outfile << "\t\t\t\t\ti := 0;" << endl;
			outfile << "\t\t\t\t\t-- IP impl." << clks[i] << ".run.reset --- IEND" << endl;
		};
	};
};
// IP cust --- IEND
