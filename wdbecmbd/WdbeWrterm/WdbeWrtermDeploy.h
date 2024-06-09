/**
	* \file WdbeWrtermDeploy.h
	* Wdbe operation processor - write interactive terminal deployment scripts (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

#ifndef WDBEWRTERMDEPLOY_H
#define WDBEWRTERMDEPLOY_H

#include "WdbeWrterm.h"

// IP include.cust --- INSERT

namespace WdbeWrtermDeploy {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrtermDeploy* dpchinv);
	// IP cust --- IBEGIN

	void writeMakefile(DbsWdbe* dbswdbe, std::fstream& outfile, const std::string& sysroot, const std::string& inclibeq, WdbeMRelease* rls, std::vector<Sbecore::ubigint>& hrefsMch, std::set<std::string>& cppflags, std::set<std::string>& linkflags, std::set<std::string>& incpaths, std::set<std::string>& libpaths, std::vector<std::string>& libss);
	// IP cust --- IEND
};

#endif
