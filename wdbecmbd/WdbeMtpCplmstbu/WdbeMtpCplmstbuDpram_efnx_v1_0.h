/**
	* \file WdbeMtpCplmstbuDpram_efnx_v1_0.h
	* Wdbe operation processor - adapt internal wiring (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Apr 2023
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTBUDPRAM_EFNX_V1_0_H
#define WDBEMTPCPLMSTBUDPRAM_EFNX_V1_0_H

#include "WdbeMtpCplmstbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmstbuDpram_efnx_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmstbu* dpchinv);
	// IP cust --- INSERT
};

#endif
