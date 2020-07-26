/**
	* \file WdbeWrdevDeploy.h
	* Wdbe operation processor - write device access library deployment scripts (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEWRDEVDEPLOY_H
#define WDBEWRDEVDEPLOY_H

#include "WdbeWrdev.h"

// IP include.cust --- INSERT

namespace WdbeWrdevDeploy {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrdevDeploy* dpchinv);
	// IP cust --- IBEGIN

	void writeChkoutSh(std::fstream& outfile, const std::string& Prjshort, const bool Easy, ListWdbeMUnit& unts);
	void writeMakefile(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMRelease* rls, ListWdbeMSystem& syss, ListWdbeMUnit& unts, std::set<std::string>& incpaths);

	void addLibBySref(DbsWdbe* dbswdbe, const std::string& srefLib, const Sbecore::ubigint refMch, std::set<std::string>& incpaths);
	void addLibByRef(DbsWdbe* dbswdbe, const Sbecore::ubigint refLib, const Sbecore::ubigint refMch, std::set<std::string>& incpaths);
	std::string pathToPathstr(const std::string& path, const std::string& inceq);
	// IP cust --- IEND
};

#endif


