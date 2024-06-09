/**
	* \file WdbeWrtermDeploy.cpp
	* Wdbe operation processor - write interactive terminal deployment scripts (implementation)
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

#include "WdbeWrtermDeploy.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrterm;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeWrtermDeploy
 ******************************************************************************/

DpchRetWdbe* WdbeWrtermDeploy::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrtermDeploy* dpchinv
		) {
	ubigint refWdbeMRelease = dpchinv->refWdbeMRelease;
	string folder = dpchinv->folder;
	bool Easy = dpchinv->Easy;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	vector<ubigint> refs;

	WdbeMRelease* rls = NULL;

	vector<ubigint> hrefsMch;

	string sysroot, inclibeq;

	set<string> cppflags;
	set<string> linkflags;
	set<string> incpaths;
	set<string> libpaths;
	vector<string> libss;

	fstream outfile;

	string s;

	if (dbswdbe->tblwdbemrelease->loadRecByRef(refWdbeMRelease, &rls)) {
		dbswdbe->tblwdbemmachine->loadHrefsup(rls->refWdbeMMachine, hrefsMch);

		if (Wdbe::getMchpar(dbswdbe, rls->refWdbeMMachine, hrefsMch, "sysroot", sysroot)) inclibeq = "=";

		// libraries
		Wdbe::addLibBySref(dbswdbe, "dbecore", rls->refWdbeMMachine, hrefsMch, cppflags, linkflags, incpaths, libpaths, libss, 0);

		dbswdbe->tblwdbermcomponentmlibrary->loadLibsByCmp(rls->refWdbeMComponent, false, refs);
		for (unsigned int i = 0; i < refs.size(); i++) Wdbe::addLibByRef(dbswdbe, refs[i], rls->refWdbeMMachine, hrefsMch, cppflags, linkflags, incpaths, libpaths, libss, 0);

		Wdbe::trimLibss(libss);

		// Makefile
		s = xchg->tmppath + "/" + folder + "/Makefile.ip";
		outfile.open(s.c_str(), ios::out);
		writeMakefile(dbswdbe, outfile, sysroot, inclibeq, rls, hrefsMch, cppflags, linkflags, incpaths, libpaths, libss);
		outfile.close();

		delete rls;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeWrtermDeploy::writeMakefile(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const string& sysroot
			, const string& inclibeq
			, WdbeMRelease* rls
			, vector<ubigint>& hrefsMch
			, set<string>& cppflags
			, set<string>& linkflags
			, set<string>& incpaths
			, set<string>& libpaths
			, vector<string>& libss
		) {
	bool statNotDyn = StrMod::srefInSrefs(rls->srefsKOption, "linkstat");
	bool stripdbg = StrMod::srefInSrefs(rls->srefsKOption, "stripdbg");

	string s;

	// --- tools
	outfile << "# IP tools --- IBEGIN" << endl;
	Wdbe::getMchmkf(dbswdbe, rls->refWdbeMMachine, hrefsMch, "cpp", s);
	outfile << "CPP = " << s << endl;

	outfile << "CPPFLAGS =";
	if (sysroot != "") outfile << " --sysroot=" << sysroot;

	if (Wdbe::getMchmkf(dbswdbe, rls->refWdbeMMachine, hrefsMch, "cppflags", s)) outfile << " " << s;
	for (auto it = cppflags.begin(); it != cppflags.end(); it++) outfile << " " << (*it);
	outfile << endl;
	outfile << endl;

	Wdbe::getMchmkf(dbswdbe, rls->refWdbeMMachine, hrefsMch, "link", s);
	outfile << "LINK = " << s << endl;

	outfile << "LINKFLAGS =";
	if (sysroot != "") outfile << " --sysroot=" << sysroot;
	if (Wdbe::getMchmkf(dbswdbe, rls->refWdbeMMachine, hrefsMch, "linkflags", s)) outfile << " " << s;
	if (stripdbg) outfile << " -s";
	for (auto it = linkflags.begin(); it != linkflags.end(); it++) outfile << " " << (*it);
	outfile << endl;
	outfile << "# IP tools --- IEND" << endl;

	// --- incpath.libspec
	outfile << "# IP incpath.libspec --- IBEGIN" << endl;
	outfile << "INCPATH +=";
	for (auto it = incpaths.begin(); it != incpaths.end(); it++) outfile << " -I" << inclibeq << (*it);
	outfile << endl;
	outfile << "# IP incpath.libspec --- IEND" << endl;

	// --- incpath.mchspec
	outfile << "# IP incpath.mchspec --- IBEGIN" << endl;
	if (Wdbe::getMchmkf(dbswdbe, rls->refWdbeMMachine, hrefsMch, "incpath", s)) outfile << "INCPATH += " << Wdbe::pathToPathstr(s, false, inclibeq) << endl;
	outfile << "# IP incpath.mchspec --- IEND" << endl;

	// --- libpath.libspec
	outfile << "# IP libpath.libspec --- IBEGIN" << endl;
	outfile << "LIBPATH +=";
	for (auto it = libpaths.begin(); it != libpaths.end(); it++) outfile << " -L" << inclibeq << (*it);
	outfile << endl;
	outfile << "# IP libpath.libspec --- IEND" << endl;

	// --- libpath.mchspec
	outfile << "# IP libpath.mchspec --- IBEGIN" << endl;
	if (Wdbe::getMchmkf(dbswdbe, rls->refWdbeMMachine, hrefsMch, "libpath", s)) outfile << "LIBPATH += " << Wdbe::pathToPathstr(s, true, inclibeq) << endl;
	outfile << "# IP libpath.mchspec --- IEND" << endl;

	// --- libs.prjspec*, libs.statprjspec*
	if (statNotDyn) {
		outfile << "# IP libs.prjspec --- REMOVE" << endl;
		outfile << "# IP libs.statprjspec --- AFFIRM" << endl;
	} else {
		outfile << "# IP libs.prjspec --- AFFIRM" << endl;
		outfile << "# IP libs.statprjspec --- REMOVE" << endl;
	};

	// --- libs.libspec
	outfile << "# IP libs.libspec --- IBEGIN" << endl;
	for (unsigned int i = 0; i < libss.size(); i++) outfile << "LIBS += " << Wdbe::libsToLibstr(libss[i], statNotDyn) << endl;
	outfile << "# IP libs.libspec --- IEND" << endl;

	// --- libs.mchspec
	outfile << "# IP libs.mchspec --- IBEGIN" << endl;
	if (Wdbe::getMchmkf(dbswdbe, rls->refWdbeMMachine, hrefsMch, "libs", s)) outfile << "LIBS += " << Wdbe::libsToLibstr(s, statNotDyn) << endl;
	outfile << "# IP libs.mchspec --- IEND" << endl;
};
// IP cust --- IEND
