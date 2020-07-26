/**
	* \file WdbePlhfpgaFwdctr.h
	* Wdbe operation processor - fill type-specific placeholders (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEPLHFPGAFWDCTR_H
#define WDBEPLHFPGAFWDCTR_H

#include "WdbePlhfpga.h"

// IP include.cust --- INSERT

namespace WdbePlhfpgaFwdctr {

	DpchRetWdbePlhfpgaFwdctr* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbePlhfpgaFwdctr* dpchinv);
	// IP cust --- INSERT
};

#endif

