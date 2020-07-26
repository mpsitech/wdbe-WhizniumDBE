/**
	* \file WdbeMtpModbscbuSub_v12_0.h
	* Wdbe operation processor - adapt port widths (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMTPMODBSCBUSUB_V12_0_H
#define WDBEMTPMODBSCBUSUB_V12_0_H

#include "WdbeMtpModbscbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpModbscbuSub_v12_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpModbscbu* dpchinv);
	// IP cust --- INSERT
};

#endif

