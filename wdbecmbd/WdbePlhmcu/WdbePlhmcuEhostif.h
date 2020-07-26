/**
	* \file WdbePlhmcuEhostif.h
	* Wdbe operation processor - fill type-specific placeholders (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEPLHMCUEHOSTIF_H
#define WDBEPLHMCUEHOSTIF_H

#include "WdbePlhmcu.h"

// IP include.cust --- INSERT

namespace WdbePlhmcuEhostif {

	DpchRetWdbePlhmcuEhostif* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbePlhmcuEhostif* dpchinv);
	// IP cust --- INSERT
};

#endif

