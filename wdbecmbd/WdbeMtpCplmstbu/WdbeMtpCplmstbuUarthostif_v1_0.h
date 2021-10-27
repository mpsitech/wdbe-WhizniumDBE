/**
	* \file WdbeMtpCplmstbuUarthostif_v1_0.h
	* Wdbe operation processor - connect UART controllers, CRC and timeout (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTBUUARTHOSTIF_V1_0_H
#define WDBEMTPCPLMSTBUUARTHOSTIF_V1_0_H

#include "WdbeMtpCplmstbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmstbuUarthostif_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmstbu* dpchinv);
	// IP cust --- INSERT
};

#endif
