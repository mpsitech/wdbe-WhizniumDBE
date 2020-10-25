/**
	* \file WdbePlhfpgaEhostif.h
	* Wdbe operation processor - fill type-specific placeholders (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEPLHFPGAEHOSTIF_H
#define WDBEPLHFPGAEHOSTIF_H

#include "WdbePlhfpga.h"

// IP include.cust --- INSERT

namespace WdbePlhfpgaEhostif {

	DpchRetWdbePlhfpgaEhostif* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbePlhfpgaEhostif* dpchinv);
	// IP cust --- INSERT
};

#endif

