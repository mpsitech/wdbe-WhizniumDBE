/**
	* \file WdbePrcfileConcat.h
	* Wdbe operation processor - concatenate text from multiple input files into output file (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEPRCFILECONCAT_H
#define WDBEPRCFILECONCAT_H

#include "WdbePrcfile.h"

// IP include.cust --- INSERT

namespace WdbePrcfileConcat {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbePrcfileConcat* dpchinv);
	// IP cust --- INSERT
};

#endif

