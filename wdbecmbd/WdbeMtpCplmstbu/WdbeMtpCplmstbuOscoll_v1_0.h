/**
	* \file WdbeMtpCplmstbuOscoll_v1_0.h
	* Wdbe operation processor - connect inter-module buffer (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 May 2025
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTBUOSCOLL_V1_0_H
#define WDBEMTPCPLMSTBUOSCOLL_V1_0_H

#include "WdbeMtpCplmstbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmstbuOscoll_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmstbu* dpchinv);
	// IP cust --- INSERT
};

#endif
