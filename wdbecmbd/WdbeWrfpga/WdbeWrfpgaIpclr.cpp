/**
	* \file WdbeWrfpgaIpclr.cpp
	* Wdbe operation processor - write VHDL code to clear unused specific insertion points (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeWrfpgaIpclr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrfpga;

/******************************************************************************
 namespace WdbeWrfpgaIpclr
 ******************************************************************************/

DpchRetWdbe* WdbeWrfpgaIpclr::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrfpgaIpclr* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	string Compsref;

	fstream outfile;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		Compsref = StrMod::cap(Wdbe::getCompsref(dbswdbe, mdl));

		// xxxx/Xxxxx.vhd
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
void WdbeWrfpgaIpclr::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	ListWdbeMProcess prcs;
	WdbeMProcess* prc = NULL;

	dbswdbe->tblwdbemprocess->loadRstBySQL("SELECT * FROM TblWdbeMProcess WHERE refWdbeMModule = " + to_string(mdl->ref) + " ORDER BY sref ASC", false, prcs);

	// -- by processes
	for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
		prc = prcs.nodes[i];

		outfile << "\t-- IP sigs." << prc->sref << ".typspec --- IBEGIN" << endl;
		outfile << "\t-- IP sigs." << prc->sref << ".typspec --- IEND" << endl;

		outfile << "\t-- IP sigs." << prc->sref << ".tplspec --- IBEGIN" << endl;
		outfile << "\t-- IP sigs." << prc->sref << ".tplspec --- IEND" << endl;
	};

	// --- sigs.oth.typspec
	outfile << "\t-- IP sigs.oth.typspec --- IBEGIN" << endl;
	outfile << "\t-- IP sigs.oth.typspec --- IEND" << endl;

	// --- sigs.oth.tplspec
	outfile << "\t-- IP sigs.oth.tplspec --- IBEGIN" << endl;
	outfile << "\t-- IP sigs.oth.tplspec --- IEND" << endl;

	// --- impl.oth.typspec
	outfile << "\t-- IP impl.oth.typspec --- IBEGIN" << endl;
	outfile << "\t-- IP impl.oth.typspec --- IEND" << endl;

	// --- impl.oth.tplspec
	outfile << "\t-- IP impl.oth.tplspec --- IBEGIN" << endl;
	outfile << "\t-- IP impl.oth.tplspec --- IEND" << endl;
};
// IP cust --- IEND


