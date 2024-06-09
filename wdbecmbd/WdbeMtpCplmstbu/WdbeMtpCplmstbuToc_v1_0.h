/**
	* \file WdbeMtpCplmstbuToc_v1_0.h
	* Wdbe operation processor - connect memory (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 7 Feb 2024
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTBUTOC_V1_0_H
#define WDBEMTPCPLMSTBUTOC_V1_0_H

#include "WdbeMtpCplmstbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmstbuToc_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmstbu* dpchinv);
	// IP cust --- INSERT
};

#endif
