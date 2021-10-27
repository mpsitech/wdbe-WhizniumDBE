/**
	* \file WdbeMtpCplmstbuPmmu_v1_0.h
	* Wdbe operation processor - connect buffers, fill slot vector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTBUPMMU_V1_0_H
#define WDBEMTPCPLMSTBUPMMU_V1_0_H

#include "WdbeMtpCplmstbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmstbuPmmu_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmstbu* dpchinv);
	// IP cust --- INSERT
};

#endif
