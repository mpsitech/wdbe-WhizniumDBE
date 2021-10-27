/**
	* \file WdbeGenfstEctr.h
	* Wdbe operation processor - add vector constants and FSM debug ports (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEGENFSTECTR_H
#define WDBEGENFSTECTR_H

#include "WdbeGenfst.h"

// IP include.cust --- INSERT

namespace WdbeGenfstEctr {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeGenfstEctr* dpchinv);
	// IP cust --- INSERT
};

#endif
