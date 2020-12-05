/**
	* \file SqkWdbeMtpWrfpga.cpp
	* squawk generation for operation pack WdbeMtpWrfpga (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "SqkWdbeMtpWrfpga.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWdbeMtpWrfpga
 ******************************************************************************/

string SqkWdbeMtpWrfpga::getSquawk(
			DbsWdbe* dbswdbe
			, DpchInvWdbeMtpWrfpga* dpchinv
		) {
	// example: "write module template-specific FPGA code for module 'icm2-cmdinv (cmdinv_v1_0 command invocation buffer)'"
	return("write module template-specific FPGA code for module '" + StubWdbe::getStubMdlStd(dbswdbe, dpchinv->refWdbeMModule) + "'"); // IP getSquawk --- RLINE
};



