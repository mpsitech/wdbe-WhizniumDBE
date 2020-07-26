/**
	* \file WdbeMtpWrfpgaTkclksrc_v1_0.cpp
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

#include "WdbeMtpWrfpgaTkclksrc_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

/******************************************************************************
 namespace WdbeMtpWrfpgaTkclksrc_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaTkclksrc_v1_0::run(
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

		// xxxx/Tkclksrc.vhd
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
void WdbeMtpWrfpgaTkclksrc_v1_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	// --- impl.cmd.prepRetGetTkst
	outfile << "-- IP impl.cmd.prepRetGetTkst --- IBEGIN" << endl;
	outfile << "\t\t\t\tcmdbuf(ixCmdbufRetGetTkstTkst) <= tkst(31 downto 24);" << endl;
	outfile << "\t\t\t\tcmdbuf(ixCmdbufRetGetTkstTkst+1) <= tkst(23 downto 16);" << endl;
	outfile << "\t\t\t\tcmdbuf(ixCmdbufRetGetTkstTkst+2) <= tkst(15 downto 8);" << endl;
	outfile << "\t\t\t\tcmdbuf(ixCmdbufRetGetTkstTkst+3) <= tkst(7 downto 0);" << endl;
	outfile << "-- IP impl.cmd.prepRetGetTkst --- IEND" << endl;
};
// IP cust --- IEND


