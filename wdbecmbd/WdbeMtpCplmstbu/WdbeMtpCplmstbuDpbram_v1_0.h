/**
	* \file WdbeMtpCplmstbuDpbram_v1_0.h
	* Wdbe operation processor - adapt port widths, connect buffer (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 19 Oct 2025
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTBUDPBRAM_V1_0_H
#define WDBEMTPCPLMSTBUDPBRAM_V1_0_H

#include "WdbeMtpCplmstbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmstbuDpbram_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmstbu* dpchinv);
	// IP cust --- INSERT
};

#endif
