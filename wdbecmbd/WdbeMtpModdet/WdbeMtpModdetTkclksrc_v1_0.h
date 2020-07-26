/**
	* \file WdbeMtpModdetTkclksrc_v1_0.h
	* Wdbe operation processor - add command process handshake (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMTPMODDETTKCLKSRC_V1_0_H
#define WDBEMTPMODDETTKCLKSRC_V1_0_H

#include "WdbeMtpModdet.h"

// IP include.cust --- INSERT

namespace WdbeMtpModdetTkclksrc_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpModdet* dpchinv);
	// IP cust --- INSERT
};

#endif

