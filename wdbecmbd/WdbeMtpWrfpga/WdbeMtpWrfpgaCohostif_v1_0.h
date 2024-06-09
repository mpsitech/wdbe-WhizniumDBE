/**
	* \file WdbeMtpWrfpgaCohostif_v1_0.h
	* Wdbe operation processor -  (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 3 Apr 2023
  */
// IP header --- ABOVE

#ifndef WDBEMTPWRFPGACOHOSTIF_V1_0_H
#define WDBEMTPWRFPGACOHOSTIF_V1_0_H

#include "WdbeMtpWrfpga.h"

// IP include.cust --- INSERT

namespace WdbeMtpWrfpgaCohostif_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpWrfpga* dpchinv);
	// IP cust --- INSERT
};

#endif
