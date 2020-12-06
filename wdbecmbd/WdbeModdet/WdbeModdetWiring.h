/**
	* \file WdbeModdetWiring.h
	* Wdbe operation processor - add hierarchical wiring (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMODDETWIRING_H
#define WDBEMODDETWIRING_H

#include "WdbeModdet.h"

// IP include.cust --- INSERT

namespace WdbeModdetWiring {

	DpchRetWdbeModdetWiring* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModdetWiring* dpchinv);
	// IP cust --- IBEGIN

	void appendError(const std::string& tmppath, std::string& logfile, std::fstream& logfi, const std::string& err);
	// IP cust --- IEND
};

#endif
