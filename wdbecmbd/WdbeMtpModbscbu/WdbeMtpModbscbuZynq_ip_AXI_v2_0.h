/**
	* \file WdbeMtpModbscbuZynq_ip_AXI_v2_0.h
	* Wdbe operation processor - add pin substitute signals (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMTPMODBSCBUZYNQ_IP_AXI_V2_0_H
#define WDBEMTPMODBSCBUZYNQ_IP_AXI_V2_0_H

#include "WdbeMtpModbscbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpModbscbuZynq_ip_AXI_v2_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpModbscbu* dpchinv);
	// IP cust --- INSERT
};

#endif

