/**
	* \file WdbeCplmstUnt.h
	* Wdbe operation processor - add standard vectors (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBECPLMSTUNT_H
#define WDBECPLMSTUNT_H

#include "WdbeCplmst.h"

// IP include.cust --- INSERT

namespace WdbeCplmstUnt {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeCplmstUnt* dpchinv);
	// IP cust --- INSERT
};

#endif
