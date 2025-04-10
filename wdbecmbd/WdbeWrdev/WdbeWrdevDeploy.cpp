/**
	* \file WdbeWrdevDeploy.cpp
	* Wdbe operation processor - write device access library deployment scripts (implementation)
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

#include "WdbeWrdevDeploy.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrdev;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeWrdevDeploy
 ******************************************************************************/

DpchRetWdbe* WdbeWrdevDeploy::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrdevDeploy* dpchinv
		) {
	ubigint refWdbeMRelease = dpchinv->refWdbeMRelease;
	string folder = dpchinv->folder;
	bool Easy = dpchinv->Easy;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	vector<ubigint> refs;
	ubigint ref;

	WdbeMRelease* rls = NULL;

	vector<ubigint> hrefsMch;

	ListWdbeMUnit unts;

	set<string> incpaths;

	string Prjshort;

	fstream outfile;

	string s;

	if (dbswdbe->tblwdbemrelease->loadRecByRef(refWdbeMRelease, &rls)) {
		dbswdbe->tblwdbemmachine->loadHrefsup(rls->refWdbeMMachine, hrefsMch);

		if (Easy) {
			dbswdbe->tblwdbemunit->loadRstBySQL("SELECT TblWdbeMUnit.* FROM TblWdbeMComponent, TblWdbeMUnit WHERE TblWdbeMUnit.refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER)
						+ " AND TblWdbeMUnit.refUref = TblWdbeMComponent.refWdbeMVersion AND TblWdbeMComponent.ref = " + to_string(rls->refWdbeMComponent) + " AND TblWdbeMUnit.Easy = 1 ORDER BY TblWdbeMUnit.sref ASC", false, unts);
		} else {
			dbswdbe->tblwdbemunit->loadRstBySQL("SELECT TblWdbeMUnit.* FROM TblWdbeMComponent, TblWdbeMUnit WHERE TblWdbeMUnit.refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER)
						+ " AND TblWdbeMUnit.refUref = TblWdbeMComponent.refWdbeMVersion AND TblWdbeMComponent.ref = " + to_string(rls->refWdbeMComponent) + " ORDER BY TblWdbeMUnit.sref ASC", false, unts);
		};

		// libraries
		Wdbe::addLibBySref(dbswdbe, "dbecore", rls->refWdbeMMachine, hrefsMch, incpaths);

		dbswdbe->tblwdbermcomponentmlibrary->loadLibsByCmp(rls->refWdbeMComponent, false, refs);
		for (unsigned int i = 0; i < refs.size(); i++) Wdbe::addLibByRef(dbswdbe, refs[i], rls->refWdbeMMachine, hrefsMch, incpaths);

		dbswdbe->loadRefBySQL("SELECT refWdbeMVersion FROM TblWdbeMComponent WHERE ref = " + to_string(rls->refWdbeMComponent), ref);
		Prjshort = Wdbe::getPrjshort(dbswdbe, ref);

		// checkout.sh
		s = xchg->tmppath + "/" + folder + "/checkout.sh.ip";
		outfile.open(s.c_str(), ios::out);
		writeChkoutSh(outfile, Prjshort, Easy, unts);
		outfile.close();

		// Makefile
		s = xchg->tmppath + "/" + folder + "/Makefile.ip";
		outfile.open(s.c_str(), ios::out);
		writeMakefile(dbswdbe, outfile, rls, hrefsMch, unts, incpaths);
		outfile.close();

		delete rls;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeWrdevDeploy::writeChkoutSh(
			fstream& outfile
			, const string& Prjshort
			, const bool Easy
			, ListWdbeMUnit& unts
		) {
	WdbeMUnit* unt = NULL;

	string folder;

	// --- untsCopy
	if (Easy) folder = "ezdev" + StrMod::lc(Prjshort);
	else folder = "dev" + StrMod::lc(Prjshort);

	outfile << "# IP untsCopy --- IBEGIN" << endl;

	for (unsigned int i = 0; i < unts.nodes.size(); i++) {
		unt = unts.nodes[i];

		outfile << "cp ../../" << folder << "/" << unt->Fullsref << "/*.h $BUILDROOT/" << folder << "/" << endl;
		outfile << "cp ../../" << folder << "/" << unt->Fullsref << "/*.cpp $BUILDROOT/" << folder << "/" << endl;
		outfile << endl;
	};

	outfile << "# IP untsCopy --- IEND" << endl;
};

void WdbeWrdevDeploy::writeMakefile(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMRelease* rls
			, vector<ubigint>& hrefsMch
			, ListWdbeMUnit& unts
			, set<string>& incpaths
		) {
	WdbeMUnit* unt = NULL;

	ListWdbeMController ctrs;
	WdbeMController* ctr = NULL;

	string sysroot, inceq;

	bool dynlib = StrMod::srefInSrefs(rls->srefsKOption, "dynlib");

	string s;

	Wdbe::getMchpar(dbswdbe, rls->refWdbeMMachine, hrefsMch, "sysroot", sysroot);
	if (sysroot != "") inceq = "=";

	// --- tools
	outfile << "# IP tools --- IBEGIN" << endl;
	Wdbe::getMchmkf(dbswdbe, rls->refWdbeMMachine, hrefsMch, "cpp", s);
	outfile << "CPP = " << s << endl;

	outfile << "CPPFLAGS =";
	if (sysroot != "") outfile << " --sysroot=" << sysroot;

	if (Wdbe::getMchmkf(dbswdbe, rls->refWdbeMMachine, hrefsMch, "cppflags", s)) outfile << " " << s;
	if (dynlib) outfile << " -fPIC";
	outfile << endl;
	outfile << endl;

	Wdbe::getMchmkf(dbswdbe, rls->refWdbeMMachine, hrefsMch, "statlib", s);
	outfile << "STATLIB = " << s << endl;

	Wdbe::getMchmkf(dbswdbe, rls->refWdbeMMachine, hrefsMch, "statlibflags", s);
	outfile << "STATLIBFLAGS = " << s << endl;

	if (dynlib) {
		outfile << endl;

		Wdbe::getMchmkf(dbswdbe, rls->refWdbeMMachine, hrefsMch, "dynlib", s);
		outfile << "DYNLIB = " << s << endl;

		outfile << "DYNLIBFLAGS =";
		if (sysroot != "") outfile << " --sysroot=" << sysroot;
		if (Wdbe::getMchmkf(dbswdbe, rls->refWdbeMMachine, hrefsMch, "dynlibflags", s)) outfile << " " << s;
		outfile << endl;

		Wdbe::getMchmkf(dbswdbe, rls->refWdbeMMachine, hrefsMch, "dynlibext", s);
		outfile << "DYNLIBEXT = " << s << endl;
	};
	outfile << "# IP tools --- IEND" << endl;

	// --- incpath.libspec
	outfile << "# IP incpath.libspec --- IBEGIN" << endl;
	outfile << "INCPATH +=";
	for (auto it = incpaths.begin(); it != incpaths.end(); it++) outfile << " -I" << inceq << (*it);
	outfile << endl;
	outfile << "# IP incpath.libspec --- IEND" << endl;

	// --- incpath.mchspec
	outfile << "# IP incpath.mchspec --- IBEGIN" << endl;
	if (Wdbe::getMchmkf(dbswdbe, rls->refWdbeMMachine, hrefsMch, "incpath", s)) outfile << "INCPATH += " << Wdbe::pathToPathstr(s, false, inceq) << endl;
	outfile << "# IP incpath.mchspec --- IEND" << endl;

	// --- objs
	outfile << "# IP objs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < unts.nodes.size(); i++) {
		unt = unts.nodes[i];

		outfile << "OBJS += " << unt->Fullsref << ".o " << unt->Fullsref << "_vecs.o";

		dbswdbe->tblwdbemcontroller->loadRstBySQL("SELECT TblWdbeMController.* FROM TblWdbeMController, TblWdbeMModule WHERE TblWdbeMController.refWdbeMModule = TblWdbeMModule.ref AND TblWdbeMModule.hkIxVTbl = "
					+ to_string(VecWdbeVMModuleHkTbl::UNT) + " AND TblWdbeMModule.hkUref = " + to_string(unt->ref) + " ORDER BY TblWdbeMModule.sref ASC", false, ctrs);

		for (unsigned int j = 0; j < ctrs.nodes.size(); j++) {
			ctr = ctrs.nodes[j];
			outfile << " " << ctr->Fullsref << ".o";
		};

		outfile << endl;
	};
	outfile << "# IP objs --- IEND" << endl;

	// --- mkdynlib*
	if (dynlib) outfile << "# IP mkdynlib --- AFFIRM" << endl;
	else outfile << "# IP mkdynlib --- REMOVE" << endl;

	// --- instdynlib*
	if (dynlib) outfile << "# IP instdynlib --- AFFIRM" << endl;
	else outfile << "# IP instdynlib --- REMOVE" << endl;
};
// IP cust --- IEND
