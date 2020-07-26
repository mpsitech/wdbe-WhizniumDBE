/**
	* \file WdbeModdetWiring.h
	* Wdbe operation processor - add hierarchical wiring (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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


