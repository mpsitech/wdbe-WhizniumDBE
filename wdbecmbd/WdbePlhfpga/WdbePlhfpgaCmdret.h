/**
	* \file WdbePlhfpgaCmdret.h
	* Wdbe operation processor - fill type-specific placeholders (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEPLHFPGACMDRET_H
#define WDBEPLHFPGACMDRET_H

#include "WdbePlhfpga.h"

// IP include.cust --- INSERT

namespace WdbePlhfpgaCmdret {

	DpchRetWdbePlhfpgaCmdret* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbePlhfpgaCmdret* dpchinv);
	// IP cust --- INSERT
};

#endif

