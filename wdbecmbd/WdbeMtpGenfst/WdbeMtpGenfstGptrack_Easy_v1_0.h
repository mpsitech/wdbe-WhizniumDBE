/**
	* \file WdbeMtpGenfstGptrack_Easy_v1_0.h
	* Wdbe operation processor - add clock domain crossing (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 17 Oct 2023
  */
// IP header --- ABOVE

#ifndef WDBEMTPGENFSTGPTRACK_EASY_V1_0_H
#define WDBEMTPGENFSTGPTRACK_EASY_V1_0_H

#include "WdbeMtpGenfst.h"

// IP include.cust --- INSERT

namespace WdbeMtpGenfstGptrack_Easy_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpGenfst* dpchinv);
	// IP cust --- INSERT
};

#endif
