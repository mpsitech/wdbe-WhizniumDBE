/**
	* \file WdbeCplmstImbuf.h
	* Wdbe operation processor - add parameters (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBECPLMSTIMBUF_H
#define WDBECPLMSTIMBUF_H

#include "WdbeCplmst.h"

// IP include.cust --- INSERT

namespace WdbeCplmstImbuf {

	DpchRetWdbeCplmstImbuf* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeCplmstImbuf* dpchinv);
	// IP cust --- INSERT
};

#endif
