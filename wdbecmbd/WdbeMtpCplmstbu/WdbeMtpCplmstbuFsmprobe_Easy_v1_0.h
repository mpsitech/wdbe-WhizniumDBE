/**
	* \file WdbeMtpCplmstbuFsmprobe_Easy_v1_0.h
	* Wdbe operation processor - add capture ports and fill vector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTBUFSMPROBE_EASY_V1_0_H
#define WDBEMTPCPLMSTBUFSMPROBE_EASY_V1_0_H

#include "WdbeMtpCplmstbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmstbuFsmprobe_Easy_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmstbu* dpchinv);
	// IP cust --- INSERT
};

#endif
