/**
	* \file WdbeMtpGenfstHostif_Easy_v1_0.h
	* Wdbe operation processor - add process (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2024
  */
// IP header --- ABOVE

#ifndef WDBEMTPGENFSTHOSTIF_EASY_V1_0_H
#define WDBEMTPGENFSTHOSTIF_EASY_V1_0_H

#include "WdbeMtpGenfst.h"

// IP include.cust --- INSERT

namespace WdbeMtpGenfstHostif_Easy_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpGenfst* dpchinv);
	// IP cust --- INSERT
};

#endif
