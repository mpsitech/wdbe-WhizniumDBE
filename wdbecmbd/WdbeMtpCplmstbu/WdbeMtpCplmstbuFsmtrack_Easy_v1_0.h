/**
	* \file WdbeMtpCplmstbuFsmtrack_Easy_v1_0.h
	* Wdbe operation processor - add capture/trigger ports, fill vectors and connect buffers (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTBUFSMTRACK_EASY_V1_0_H
#define WDBEMTPCPLMSTBUFSMTRACK_EASY_V1_0_H

#include "WdbeMtpCplmstbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmstbuFsmtrack_Easy_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmstbu* dpchinv);
	// IP cust --- INSERT
};

#endif
