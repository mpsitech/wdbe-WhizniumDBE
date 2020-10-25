/**
	* \file WdbeModbscUnt.h
	* Wdbe operation processor - add standard vectors (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMODBSCUNT_H
#define WDBEMODBSCUNT_H

#include "WdbeModbsc.h"

// IP include.cust --- INSERT

namespace WdbeModbscUnt {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModbscUnt* dpchinv);
	// IP cust --- INSERT
};

#endif

