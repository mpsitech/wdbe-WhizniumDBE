/**
	* \file WdbeMtpCplmstbuTop_mchp_v1_0.h
	* Wdbe operation processor - connect clock primitives (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 21 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTBUTOP_MCHP_V1_0_H
#define WDBEMTPCPLMSTBUTOP_MCHP_V1_0_H

#include "WdbeMtpCplmstbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmstbuTop_mchp_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmstbu* dpchinv);
	// IP cust --- INSERT
};

#endif
