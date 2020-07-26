/**
	* \file WdbeMtpWrfpgaTop_v1_0.cpp
	* Wdbe operation processor -  (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpWrfpgaTop_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

/******************************************************************************
 namespace WdbeMtpWrfpgaTop_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaTop_v1_0::run(
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

		// xxxx/Xxxx.vhd
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
void WdbeMtpWrfpgaTop_v1_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	ubigint ref;

	bool hasReqReset;

	string fExtclk, fMclk;

	// --- sigs.mclk.cust
	outfile << "\t-- IP sigs.mclk.cust --- IBEGIN" << endl;
	outfile << "\t-- IP sigs.mclk.cust --- IEND" << endl;

	// --- sigs.rst.cust
	outfile << "\t-- IP sigs.rst.cust --- IBEGIN" << endl;
	outfile << "\t-- IP sigs.rst.cust --- IEND" << endl;

	// --- impl.rst.rising*
	hasReqReset = dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMSignal WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'reqReset'", ref);

	outfile << "\t-- IP impl.rst.rising --- RBEGIN" << endl;
	
	if (hasReqReset) outfile << "\tprocess (reqReset, mclk)" << endl;
	else outfile << "\tprocess (mclk)" << endl;

	outfile << "\t\tvariable i: natural range 0 to 16 := 0;" << endl;
	outfile << "\tbegin" << endl;

	if (hasReqReset) {
		outfile << "\t\tif reqReset='1' then" << endl;
		outfile << "\t\t\ti := 0;" << endl;
		outfile << "\t\t\tstateRst <= stateRstReset;" << endl;
		outfile << "\t\telsif rising_edge(mclk) then" << endl;
	} else {
		outfile << "\t\tif rising_edge(mclk) then" << endl;
	};

	outfile << "\t\t\tif stateRst=stateRstReset then" << endl;
	outfile << "\t\t\t\ti := i + 1;" << endl;
	outfile << "\t\t\t\tif i=16 then" << endl;
	outfile << "\t\t\t\t\ti := 0;" << endl;
	outfile << "\t\t\t\t\tstateRst <= stateRstRun;" << endl;
	outfile << "\t\t\t\tend if;" << endl;
	outfile << "\t\t\tend if;" << endl;
	outfile << "\t\tend if;" << endl;
	outfile << "\tend process;" << endl;

	outfile << "\t-- IP impl.rst.rising --- REND" << endl;

	// --- impl.rst.falling*
	outfile << "\t-- IP impl.rst.falling --- RBEGIN" << endl;
	outfile << "\t-- IP impl.rst.falling --- REND" << endl;
};
// IP cust --- IEND


