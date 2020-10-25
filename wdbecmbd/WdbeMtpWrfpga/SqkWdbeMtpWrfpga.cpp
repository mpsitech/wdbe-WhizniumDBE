/**
	* \file SqkWdbeMtpWrfpga.cpp
	* squawk generation for operation pack WdbeMtpWrfpga (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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


