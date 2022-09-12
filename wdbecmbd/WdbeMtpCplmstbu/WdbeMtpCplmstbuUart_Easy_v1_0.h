/**
	* \file WdbeMtpCplmstbuUart_Easy_v1_0.h
	* Wdbe operation processor - connect UART controllers and timeout (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 7 Jun 2022
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTBUUART_EASY_V1_0_H
#define WDBEMTPCPLMSTBUUART_EASY_V1_0_H

#include "WdbeMtpCplmstbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmstbuUart_Easy_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmstbu* dpchinv);
	// IP cust --- INSERT
};

#endif
