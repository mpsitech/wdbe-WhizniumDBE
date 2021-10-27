/**
	* \file WdbeGenfstEhostif.h
	* Wdbe operation processor - add command wiring (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEGENFSTEHOSTIF_H
#define WDBEGENFSTEHOSTIF_H

#include "WdbeGenfst.h"

// IP include.cust --- INSERT

namespace WdbeGenfstEhostif {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeGenfstEhostif* dpchinv);
	// IP cust --- INSERT
};

#endif
