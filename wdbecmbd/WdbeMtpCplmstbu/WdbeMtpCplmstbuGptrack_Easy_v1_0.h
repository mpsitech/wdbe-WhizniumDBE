/**
	* \file WdbeMtpCplmstbuGptrack_Easy_v1_0.h
	* Wdbe operation processor - add capture/trigger ports, fill vectors and connect buffer (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 17 Oct 2023
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTBUGPTRACK_EASY_V1_0_H
#define WDBEMTPCPLMSTBUGPTRACK_EASY_V1_0_H

#include "WdbeMtpCplmstbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmstbuGptrack_Easy_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmstbu* dpchinv);
	// IP cust --- INSERT
};

#endif
