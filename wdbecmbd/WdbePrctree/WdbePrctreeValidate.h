/**
	* \file WdbePrctreeValidate.h
	* Wdbe operation processor - validate file tree (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEPRCTREEVALIDATE_H
#define WDBEPRCTREEVALIDATE_H

#include "WdbePrctree.h"

// IP include.cust --- INSERT

namespace WdbePrctreeValidate {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbe* dpchinv);
	// IP cust --- INSERT
};

#endif

