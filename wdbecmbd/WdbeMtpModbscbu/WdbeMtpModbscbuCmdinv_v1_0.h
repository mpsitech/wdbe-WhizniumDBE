/**
	* \file WdbeMtpModbscbuCmdinv_v1_0.h
	* Wdbe operation processor - connect buffer (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMTPMODBSCBUCMDINV_V1_0_H
#define WDBEMTPMODBSCBUCMDINV_V1_0_H

#include "WdbeMtpModbscbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpModbscbuCmdinv_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpModbscbu* dpchinv);
	// IP cust --- INSERT
};

#endif

