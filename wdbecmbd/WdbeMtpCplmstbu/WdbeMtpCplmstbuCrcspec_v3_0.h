/**
	* \file WdbeMtpCplmstbuCrcspec_v3_0.h
	* Wdbe operation processor - adapt port widths (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 3 Apr 2023
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTBUCRCSPEC_V3_0_H
#define WDBEMTPCPLMSTBUCRCSPEC_V3_0_H

#include "WdbeMtpCplmstbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmstbuCrcspec_v3_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmstbu* dpchinv);
	// IP cust --- INSERT
};

#endif
