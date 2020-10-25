/**
	* \file WdbeMtpModdetTop_v1_0.h
	* Wdbe operation processor - add reset and master clock (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMTPMODDETTOP_V1_0_H
#define WDBEMTPMODDETTOP_V1_0_H

#include "WdbeMtpModdet.h"

// IP include.cust --- INSERT

namespace WdbeMtpModdetTop_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpModdet* dpchinv);
	// IP cust --- INSERT
};

#endif

