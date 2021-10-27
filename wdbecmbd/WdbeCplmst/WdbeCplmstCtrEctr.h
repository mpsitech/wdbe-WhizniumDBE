/**
	* \file WdbeCplmstCtrEctr.h
	* Wdbe operation processor - add controller (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBECPLMSTCTRECTR_H
#define WDBECPLMSTCTRECTR_H

#include "WdbeCplmst.h"

// IP include.cust --- INSERT

namespace WdbeCplmstCtrEctr {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeCplmstCtrEctr* dpchinv);
	// IP cust --- INSERT
};

#endif
