/**
	* \file SqkWdbeMtpPlhfpga.cpp
	* squawk generation for operation pack WdbeMtpPlhfpga (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "SqkWdbeMtpPlhfpga.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWdbeMtpPlhfpga
 ******************************************************************************/

string SqkWdbeMtpPlhfpga::getSquawk(
			DbsWdbe* dbswdbe
			, DpchInvWdbeMtpPlhfpga* dpchinv
		) {
	// example: "fill module template-specific FPGA code placeholders for module 'icm2-cmdinv (cmdinv_v1_0 command invocation buffer)'"
	return("fill module template-specific FPGA code placeholders for module '" + StubWdbe::getStubMdlStd(dbswdbe, dpchinv->refWdbeMModule) + "'"); // IP getSquawk --- RLINE
};



