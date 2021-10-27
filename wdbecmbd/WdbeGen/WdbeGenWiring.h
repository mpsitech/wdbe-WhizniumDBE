/**
	* \file WdbeGenWiring.h
	* Wdbe operation processor - generate wiring (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEGENWIRING_H
#define WDBEGENWIRING_H

#include "WdbeGen.h"

// IP include.cust --- INSERT

namespace WdbeGenWiring {

	DpchRetWdbeGenWiring* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeGenWiring* dpchinv);
	// IP cust --- INSERT
};

#endif
