/**
	* \file WdbeMtpGenfstSpifwd_v1_0.h
	* Wdbe operation processor - add command process handshake (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEMTPGENFSTSPIFWD_V1_0_H
#define WDBEMTPGENFSTSPIFWD_V1_0_H

#include "WdbeMtpGenfst.h"

// IP include.cust --- INSERT

namespace WdbeMtpGenfstSpifwd_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpGenfst* dpchinv);
	// IP cust --- INSERT
};

#endif
