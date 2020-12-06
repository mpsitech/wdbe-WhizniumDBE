/**
	* \file WdbeModbscUnt.h
	* Wdbe operation processor - add standard vectors (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMODBSCUNT_H
#define WDBEMODBSCUNT_H

#include "WdbeModbsc.h"

// IP include.cust --- INSERT

namespace WdbeModbscUnt {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModbscUnt* dpchinv);
	// IP cust --- INSERT
};

#endif
