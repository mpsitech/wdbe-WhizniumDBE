/**
	* \file WdbeCplmstFwdctr.h
	* Wdbe operation processor - add read and write buffers and commands (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBECPLMSTFWDCTR_H
#define WDBECPLMSTFWDCTR_H

#include "WdbeCplmst.h"

// IP include.cust --- INSERT

namespace WdbeCplmstFwdctr {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeCplmstFwdctr* dpchinv);
	// IP cust --- INSERT
};

#endif
