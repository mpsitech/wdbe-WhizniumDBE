/**
	* \file WdbeModdetUnt.h
	* Wdbe operation processor - fill standard vectors (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMODDETUNT_H
#define WDBEMODDETUNT_H

#include "WdbeModdet.h"

// IP include.cust --- INSERT

namespace WdbeModdetUnt {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModdetUnt* dpchinv);
	// IP cust --- INSERT
};

#endif

