/**
	* \file WdbeModdetUnt.h
	* Wdbe operation processor - fill standard vectors (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMODDETUNT_H
#define WDBEMODDETUNT_H

#include "WdbeModdet.h"

// IP include.cust --- INSERT

namespace WdbeModdetUnt {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModdetUnt* dpchinv);
	// IP cust --- INSERT
};

#endif



