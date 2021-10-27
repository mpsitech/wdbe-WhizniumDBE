/**
	* \file WdbeGenfstImbuf.h
	* Wdbe operation processor - add inter-module buffer wiring (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEGENFSTIMBUF_H
#define WDBEGENFSTIMBUF_H

#include "WdbeGenfst.h"

// IP include.cust --- INSERT

namespace WdbeGenfstImbuf {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeGenfstImbuf* dpchinv);
	// IP cust --- INSERT
};

#endif
