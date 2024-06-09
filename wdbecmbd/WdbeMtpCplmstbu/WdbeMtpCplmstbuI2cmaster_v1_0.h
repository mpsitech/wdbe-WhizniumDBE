/**
	* \file WdbeMtpCplmstbuI2cmaster_v1_0.h
	* Wdbe operation processor - connect tri-state buffer primitive (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 31 Dec 2022
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTBUI2CMASTER_V1_0_H
#define WDBEMTPCPLMSTBUI2CMASTER_V1_0_H

#include "WdbeMtpCplmstbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmstbuI2cmaster_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmstbu* dpchinv);
	// IP cust --- INSERT
};

#endif
