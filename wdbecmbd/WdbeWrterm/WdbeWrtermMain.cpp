/**
	* \file WdbeWrtermMain.cpp
	* Wdbe operation processor - write interactive terminal executable code (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeWrtermMain.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrterm;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeWrtermMain
 ******************************************************************************/

DpchRetWdbe* WdbeWrtermMain::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrtermMain* dpchinv
		) {
	ubigint refWdbeMRelease = dpchinv->refWdbeMRelease;
	string folder = dpchinv->folder;
	string Prjshort = dpchinv->Prjshort;
	bool Easy = dpchinv->Easy;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMRelease* rls = NULL;

	ListWdbeMUnit unts;

	fstream outfile;

	string s;

	if (dbswdbe->tblwdbemrelease->loadRecByRef(refWdbeMRelease, &rls)) {
		dbswdbe->tblwdbemunit->loadRstBySQL("SELECT TblWdbeMUnit.* FROM TblWdbeMComponent, TblWdbeMUnit WHERE TblWdbeMUnit.refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER)
					+ " AND TblWdbeMUnit.refUref = TblWdbeMComponent.refWdbeMVersion AND TblWdbeMComponent.ref = " + to_string(rls->refWdbeMComponent) + " AND TblWdbeMUnit.Easy = 1 ORDER BY TblWdbeMUnit.sref ASC", false, unts);

		// Xxxxterm_exe.cpp
		s = xchg->tmppath + "/" + folder + "/" + Prjshort + "term_exe.cpp.ip";
		outfile.open(s.c_str(), ios::out);
		writeExeCpp(outfile, Prjshort, unts);
		outfile.close();

		delete rls;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeWrtermMain::writeExeCpp(
			fstream& outfile
			, const string& Prjshort
			, ListWdbeMUnit& unts
		) {
	WdbeMUnit* unt = NULL;

	// --- unts*
	outfile << "// IP unts --- IBEGIN" << endl;
	outfile << "\tmap<string, size_t> unts = {";
	for (unsigned int i = 0; i < unts.nodes.size(); i++) {
		unt = unts.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << "{\"" << unt->sref << "\", 0}";
	};
	outfile << "}; // IP unts --- LINE" << endl;
	outfile << "// IP unts --- IEND" << endl;

	// --- usage1
	outfile << "// IP usage1 --- IBEGIN" << endl;
	outfile << "\t\tif (untshort == \"\") cout << \"\\tusage: './" << Prjshort << "term <unit ";
	for (unsigned int i = 0; i < unts.nodes.size(); i++) {
		unt = unts.nodes[i];

		if (i != 0) outfile << "|";
		outfile << unt->sref;
	};
	outfile << "> <unit arg 1> ... <unit arg N>'\" << endl;" << endl;
	outfile << "// IP usage1 --- IEND" << endl;

	// --- usage2*
	outfile << "// IP usage2 --- IBEGIN" << endl;
	outfile << "\t\t\t// IP usage2 --- BEGIN" << endl;
	for (unsigned int i = 0; i < unts.nodes.size(); i++) {
		unt = unts.nodes[i];

		outfile << "\t\t\t";
		if (i != 0) outfile << "else ";
		outfile << "if (untshort == \"" << unt->sref << "\") cout << \"\";" << endl;
	};
	outfile << "\t\t\t// IP usage2 --- END" << endl;
	outfile << "// IP usage2 --- IEND" << endl;

	// --- constr
	outfile << "// IP constr --- IBEGIN" << endl;
	for (unsigned int i = 0; i < unts.nodes.size(); i++) {
		unt = unts.nodes[i];

		outfile << "\t";
		if (i != 0) outfile << "else ";
		outfile << "if (untshort == \"" << unt->sref << "\") {hw = new " << unt->Fullsref << "(); untsref = \"" << unt->Fullsref << "\";}";
		if ((i+1) == unts.nodes.size()) outfile << ";";
		outfile << endl;
	};
	outfile << "// IP constr --- IEND" << endl;

	// --- init*
	outfile << "// IP init --- IBEGIN" << endl;
	outfile << "\t\t\t\t\t\t// IP init --- BEGIN" << endl;
	for (unsigned int i = 0; i < unts.nodes.size(); i++) {
		unt = unts.nodes[i];

		outfile << "\t\t\t\t\t\t";
		if (i != 0) outfile << "else ";
		outfile << "if (untshort == \"" << unt->sref << "\") ((" << unt->Fullsref << "*) hw)->init();" << endl;
	};
	outfile << "\t\t\t\t\t\t// IP init --- END" << endl;
	outfile << "// IP init --- IEND" << endl;

	// --- term
	outfile << "// IP term --- IBEGIN" << endl;
	for (unsigned int i = 0; i < unts.nodes.size(); i++) {
		unt = unts.nodes[i];

		outfile << "\t\t\t\t\t\t";
		if (i != 0) outfile << "else ";
		outfile << "if (untshort == \"" << unt->sref << "\") ((" << unt->Fullsref << "*) hw)->term();" << endl;
	};
	outfile << "// IP term --- IEND" << endl;
};
// IP cust --- IEND
