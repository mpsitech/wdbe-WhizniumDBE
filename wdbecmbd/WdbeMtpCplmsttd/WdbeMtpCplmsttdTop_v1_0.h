/**
	* \file WdbeMtpCplmsttdTop_v1_0.h
	* Wdbe operation processor - infer clock primitives and adapt ports (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Apr 2023
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTTDTOP_V1_0_H
#define WDBEMTPCPLMSTTDTOP_V1_0_H

#include "WdbeMtpCplmsttd.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmsttdTop_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmsttd* dpchinv);
	// IP cust --- INSERT
};

#endif
