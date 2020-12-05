/**
	* \file WdbeMtpModdetPmmu_v1_0.h
	* Wdbe operation processor - add command process handshake (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMTPMODDETPMMU_V1_0_H
#define WDBEMTPMODDETPMMU_V1_0_H

#include "WdbeMtpModdet.h"

// IP include.cust --- INSERT

namespace WdbeMtpModdetPmmu_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpModdet* dpchinv);
	// IP cust --- INSERT
};

#endif



