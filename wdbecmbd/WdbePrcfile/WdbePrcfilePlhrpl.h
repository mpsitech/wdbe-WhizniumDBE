/**
	* \file WdbePrcfilePlhrpl.h
	* Wdbe operation processor - replace placeholders in template file and write into output file (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEPRCFILEPLHRPL_H
#define WDBEPRCFILEPLHRPL_H

#include "WdbePrcfile.h"

// IP include.cust --- INSERT

namespace WdbePrcfilePlhrpl {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbePrcfilePlhrpl* dpchinv);
	// IP cust --- INSERT
};

#endif

