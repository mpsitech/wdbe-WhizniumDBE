/**
	* \file WdbeMtpModdetSpifwd_v1_0.h
	* Wdbe operation processor - add command process handshake (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMTPMODDETSPIFWD_V1_0_H
#define WDBEMTPMODDETSPIFWD_V1_0_H

#include "WdbeMtpModdet.h"

// IP include.cust --- INSERT

namespace WdbeMtpModdetSpifwd_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpModdet* dpchinv);
	// IP cust --- INSERT
};

#endif

