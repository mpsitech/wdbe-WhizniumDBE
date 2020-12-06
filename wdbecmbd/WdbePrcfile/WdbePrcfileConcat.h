/**
	* \file WdbePrcfileConcat.h
	* Wdbe operation processor - concatenate text from multiple input files into output file (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEPRCFILECONCAT_H
#define WDBEPRCFILECONCAT_H

#include "WdbePrcfile.h"

// IP include.cust --- INSERT

namespace WdbePrcfileConcat {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbePrcfileConcat* dpchinv);
	// IP cust --- INSERT
};

#endif
