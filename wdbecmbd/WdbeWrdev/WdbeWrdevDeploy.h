/**
	* \file WdbeWrdevDeploy.h
	* Wdbe operation processor - write device access library deployment scripts (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEWRDEVDEPLOY_H
#define WDBEWRDEVDEPLOY_H

#include "WdbeWrdev.h"

// IP include.cust --- INSERT

namespace WdbeWrdevDeploy {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrdevDeploy* dpchinv);
	// IP cust --- IBEGIN

	void writeChkoutSh(std::fstream& outfile, const std::string& Prjshort, const bool Easy, ListWdbeMUnit& unts);
	void writeMakefile(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMRelease* rls, std::vector<Sbecore::ubigint>& hrefsMch, ListWdbeMUnit& unts, std::set<std::string>& incpaths);
	// IP cust --- IEND
};

#endif
