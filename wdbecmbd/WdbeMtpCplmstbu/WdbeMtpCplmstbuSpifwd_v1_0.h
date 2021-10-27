/**
	* \file WdbeMtpCplmstbuSpifwd_v1_0.h
	* Wdbe operation processor - connect buffers, SPI interface, CRC and timeout (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTBUSPIFWD_V1_0_H
#define WDBEMTPCPLMSTBUSPIFWD_V1_0_H

#include "WdbeMtpCplmstbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmstbuSpifwd_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmstbu* dpchinv);
	// IP cust --- INSERT
};

#endif
