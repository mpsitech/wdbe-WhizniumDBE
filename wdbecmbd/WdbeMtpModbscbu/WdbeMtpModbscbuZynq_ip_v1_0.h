/**
	* \file WdbeMtpModbscbuZynq_ip_v1_0.h
	* Wdbe operation processor - connect AXI bus functionality (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMTPMODBSCBUZYNQ_IP_V1_0_H
#define WDBEMTPMODBSCBUZYNQ_IP_V1_0_H

#include "WdbeMtpModbscbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpModbscbuZynq_ip_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpModbscbu* dpchinv);
	// IP cust --- INSERT
};

#endif

