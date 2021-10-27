/**
	* \file WdbeGenTest.h
	* Wdbe operation processor - generate test infrastructure (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 23 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBEGENTEST_H
#define WDBEGENTEST_H

#include "WdbeGen.h"

// IP include.cust --- INSERT

namespace WdbeGenTest {

	DpchRetWdbeGenTest* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeGenTest* dpchinv);
	// IP cust --- INSERT
};

#endif
