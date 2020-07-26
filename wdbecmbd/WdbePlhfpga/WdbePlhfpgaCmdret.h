/**
	* \file WdbePlhfpgaCmdret.h
	* Wdbe operation processor - fill type-specific placeholders (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
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

