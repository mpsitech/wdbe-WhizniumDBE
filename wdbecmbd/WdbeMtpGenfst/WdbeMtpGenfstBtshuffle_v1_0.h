/**
	* \file WdbeMtpGenfstBtshuffle_v1_0.h
	* Wdbe operation processor - add process and signals (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 May 2025
  */
// IP header --- ABOVE

#ifndef WDBEMTPGENFSTBTSHUFFLE_V1_0_H
#define WDBEMTPGENFSTBTSHUFFLE_V1_0_H

#include "WdbeMtpGenfst.h"

// IP include.cust --- INSERT

namespace WdbeMtpGenfstBtshuffle_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpGenfst* dpchinv);
	// IP cust --- INSERT
};

#endif
