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
	ListWdbeMSignal sigs;
	WdbeMSignal* sig = NULL;

	// --- impl.rst.asyncrst
	outfile << "-- IP impl.rst.asyncrst --- RBEGIN" << endl;
	outfile << "\t\t\tstateRst <= stateRstReset;" << endl;
	outfile << endl;

	outfile << "\t\t\ti := 0;" << endl;
	outfile << "-- IP impl.rst.asyncrst --- REND" << endl;

	// --- impl.rst.reset.ext
	outfile << "-- IP impl.rst.reset.ext --- IBEGIN" << endl;
	outfile << "\t\t\t\ti := i + 1;" << endl;
	outfile << "-- IP impl.rst.reset.ext --- IEND" << endl;

	// --- impl.rst.run
	dbswdbe->tblwdbemsignal->loadRstBySQL("SELECT * FROM TblWdbeMSignal WHERE refWdbeCSignal = 0 AND ixVBasetype = " + to_string(VecWdbeVMSignalBasetype::HSHK) + " AND refIxVTbl = "
				+ to_string(VecWdbeVMSignalRefTbl::MDL) + " AND refUref = " + to_string(mdl->ref) + " AND sref LIKE 'req%' ORDER BY refNum ASC", false, sigs);

	outfile << "-- IP impl.rst.run --- IBEGIN" << endl;
	if (sigs.nodes.size() > 0) {
		outfile << "\t\t\t\tif";
		for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
			sig = sigs.nodes[i];

			if (i != 0) outfile << " or";
			outfile << " " << sig->sref << "='1'";
		};
		outfile << " then" << endl;

		outfile << "\t\t\t\t\ti := 0;" << endl;
		outfile << "\t\t\t\t\tstateRst <= stateRstReset;" << endl;
		outfile << "\t\t\t\tend if;" << endl;
	};
	outfile << "-- IP impl.rst.run --- IEND" << endl;
};
// IP cust --- IEND
