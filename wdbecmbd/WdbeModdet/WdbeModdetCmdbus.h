/**
	* \file WdbeModdetCmdbus.h
	* Wdbe operation processor - add command bus wiring (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMODDETCMDBUS_H
#define WDBEMODDETCMDBUS_H

#include "WdbeModdet.h"

// IP include.cust --- INSERT

namespace WdbeModdetCmdbus {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModdetCmdbus* dpchinv);
	// IP cust --- INSERT
};

#endif
