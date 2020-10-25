/**
	* \file WdbePlhfpgaCmdinv.h
	* Wdbe operation processor - fill type-specific placeholders (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEPLHFPGACMDINV_H
#define WDBEPLHFPGACMDINV_H

#include "WdbePlhfpga.h"

// IP include.cust --- INSERT

namespace WdbePlhfpgaCmdinv {

	DpchRetWdbePlhfpgaCmdinv* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbePlhfpgaCmdinv* dpchinv);
	// IP cust --- INSERT
};

#endif

