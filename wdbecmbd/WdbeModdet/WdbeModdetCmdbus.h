/**
	* \file WdbeModdetCmdbus.h
	* Wdbe operation processor - add command bus wiring (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMODDETCMDBUS_H
#define WDBEMODDETCMDBUS_H

#include "WdbeModdet.h"

// IP include.cust --- INSERT

namespace WdbeModdetCmdbus {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModdetCmdbus* dpchinv);
	// IP cust --- INSERT
};

#endif

