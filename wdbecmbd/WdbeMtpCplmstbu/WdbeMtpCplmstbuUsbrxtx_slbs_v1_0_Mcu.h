/**
	* \file WdbeMtpCplmstbuUsbrxtx_slbs_v1_0_Mcu.h
	* Wdbe operation processor - add handshake with managing module (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 4 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTBUUSBRXTX_SLBS_V1_0_MCU_H
#define WDBEMTPCPLMSTBUUSBRXTX_SLBS_V1_0_MCU_H

#include "WdbeMtpCplmstbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmstbuUsbrxtx_slbs_v1_0_Mcu {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmstbu* dpchinv);
	// IP cust --- INSERT
};

#endif
