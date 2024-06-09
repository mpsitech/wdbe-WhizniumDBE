/**
	* \file WdbeMtpGenfstUsbhostif_Easy_v2_0_Mcu.h
	* Wdbe operation processor - add process and sensitivity (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 19 Jun 2023
  */
// IP header --- ABOVE

#ifndef WDBEMTPGENFSTUSBHOSTIF_EASY_V2_0_MCU_H
#define WDBEMTPGENFSTUSBHOSTIF_EASY_V2_0_MCU_H

#include "WdbeMtpGenfst.h"

// IP include.cust --- INSERT

namespace WdbeMtpGenfstUsbhostif_Easy_v2_0_Mcu {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpGenfst* dpchinv);
	// IP cust --- INSERT
};

#endif
