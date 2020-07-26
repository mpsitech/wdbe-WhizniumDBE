/**
	* \file WdbeMtpModbscbuDotmx2x16_v1_0.h
	* Wdbe operation processor - connect SPI interface (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMTPMODBSCBUDOTMX2X16_V1_0_H
#define WDBEMTPMODBSCBUDOTMX2X16_V1_0_H

#include "WdbeMtpModbscbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpModbscbuDotmx2x16_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpModbscbu* dpchinv);
	// IP cust --- INSERT
};

#endif

