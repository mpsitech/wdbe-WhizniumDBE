/**
	* \file WdbeGenfstTop.h
	* Wdbe operation processor - add reset process (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 16 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBEGENFSTTOP_H
#define WDBEGENFSTTOP_H

#include "WdbeGenfst.h"

// IP include.cust --- INSERT

namespace WdbeGenfstTop {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeGenfstTop* dpchinv);
	// IP cust --- INSERT
};

#endif
