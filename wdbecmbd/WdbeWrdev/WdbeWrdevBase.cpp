/**
	* \file WdbeWrdevBase.cpp
	* Wdbe operation processor - write device access library C++ code basics (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

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

// IP ns.cust --- INSERT

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
	ListWdbeMUnit unts;
	WdbeMUnit* unt = NULL;

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
