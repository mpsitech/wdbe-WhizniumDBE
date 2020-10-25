/**
	* \file WdbeMtpModbscbuMult_v12_0.h
	* Wdbe operation processor - adapt port widths (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMTPMODBSCBUMULT_V12_0_H
#define WDBEMTPMODBSCBUMULT_V12_0_H

#include "WdbeMtpModbscbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpModbscbuMult_v12_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpModbscbu* dpchinv);
	// IP cust --- INSERT
};

#endif

