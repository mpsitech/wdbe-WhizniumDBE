/**
	* \file WdbeMtpCplmstbuI2c_Easy_v1_0.h
	* Wdbe operation processor - connect I2C master (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jan 2023
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTBUI2C_EASY_V1_0_H
#define WDBEMTPCPLMSTBUI2C_EASY_V1_0_H

#include "WdbeMtpCplmstbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmstbuI2c_Easy_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmstbu* dpchinv);
	// IP cust --- INSERT
};

#endif
