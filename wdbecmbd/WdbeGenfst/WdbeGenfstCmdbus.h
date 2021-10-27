/**
	* \file WdbeGenfstCmdbus.h
	* Wdbe operation processor - add command bus wiring (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEGENFSTCMDBUS_H
#define WDBEGENFSTCMDBUS_H

#include "WdbeGenfst.h"

// IP include.cust --- INSERT

namespace WdbeGenfstCmdbus {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeGenfstCmdbus* dpchinv);
	// IP cust --- INSERT
};

#endif
