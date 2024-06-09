/**
	* \file WdbeWrmcuCtr.h
	* Wdbe operation processor - write type-specific C code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 13 May 2023
  */
// IP header --- ABOVE

#ifndef WDBEWRMCUCTR_H
#define WDBEWRMCUCTR_H

#include "WdbeWrmcu.h"

// IP include.cust --- INSERT

namespace WdbeWrmcuCtr {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrmcuCtr* dpchinv);
	// IP cust --- INSERT
};

#endif
