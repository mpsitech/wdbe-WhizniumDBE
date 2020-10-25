/**
	* \file WdbeWrdevBase.cpp
	* Wdbe operation processor - write device access library C++ code basics (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeWrdevBase.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrdev;

/******************************************************************************
 namespace WdbeWrdevBase
 ******************************************************************************/

DpchRetWdbe* WdbeWrdevBase::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrdevBase* dpchinv
		) {
	ubigint refWdbeMVersion = dpchinv->refWdbeMVersion;
	string folder = dpchinv->folder;
	string Prjshort = dpchinv->Prjshort;
	bool Easy = dpchinv->Easy;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream outfile;

	string s;

	// DevXxxx.h
	s = xchg->tmppath + "/" + folder + "/Dev" + Prjshort + ".h.ip";
	outfile.open(s.c_str(), ios::out);
	writeDevH(dbswdbe, outfile, refWdbeMVersion, Prjshort, Easy);
	outfile.close();
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeWrdevBase::writeDevH(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const ubigint refWdbeMVersion
			, const string& Prjshort
			, const bool Easy
		) {
	ListWdbeMSystem syss;
	WdbeMSystem* sys = NULL;

	ListWdbeMUnit unts;
	WdbeMUnit* unt = NULL;

	// --- include.syss
	outfile << "// IP include.syss --- IBEGIN" << endl;
	if (!Easy) {
		dbswdbe->tblwdbemsystem->loadRstByVer(refWdbeMVersion, false, syss);

		for (unsigned int i = 0; i < syss.nodes.size(); i++) {
			sys = syss.nodes[i];
			outfile << "#include \"" << sys->sref << ".h\"" << endl;
		};
	};
	outfile << "// IP include.syss --- IEND" << endl;

	// --- include.unts
	outfile << "// IP include.unts --- IBEGIN" << endl;
	if (Easy) {
		dbswdbe->tblwdbemunit->loadRstBySQL("SELECT * FROM TblWdbeMUnit WHERE refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND refUref = " + to_string(refWdbeMVersion) + " AND Easy = 1 ORDER BY sref ASC", false, unts);

		for (unsigned int i = 0; i < unts.nodes.size(); i++) {
			unt = unts.nodes[i];
			outfile << "#include \"" << unt->Fullsref << ".h\"" << endl;
		};
	};
	outfile << "// IP include.unts --- IEND" << endl;
};
// IP cust --- IEND


