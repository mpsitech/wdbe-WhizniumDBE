/**
	* \file WdbeMtpCplmsttdGpio_Easy_v1_0.h
	* Wdbe operation processor - infer tristate primitives and adapt commands (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 23 Nov 2025
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTTDGPIO_EASY_V1_0_H
#define WDBEMTPCPLMSTTDGPIO_EASY_V1_0_H

#include "WdbeMtpCplmsttd.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmsttdGpio_Easy_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmsttd* dpchinv);
	// IP cust --- INSERT
};

#endif
