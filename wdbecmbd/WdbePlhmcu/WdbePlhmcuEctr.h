/**
	* \file WdbePlhmcuEctr.h
	* Wdbe operation processor - fill type-specific placeholders (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBEPLHMCUECTR_H
#define WDBEPLHMCUECTR_H

#include "WdbePlhmcu.h"

// IP include.cust --- INSERT

namespace WdbePlhmcuEctr {

	DpchRetWdbePlhmcuEctr* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbePlhmcuEctr* dpchinv);
	// IP cust --- INSERT
};

#endif
