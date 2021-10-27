/**
	* \file WdbeGenfstPpl.h
	* Wdbe operation processor - add FSM's and signals (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEGENFSTPPL_H
#define WDBEGENFSTPPL_H

#include "WdbeGenfst.h"

// IP include.cust --- INSERT

namespace WdbeGenfstPpl {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeGenfstPpl* dpchinv);
	// IP cust --- INSERT
};

#endif
