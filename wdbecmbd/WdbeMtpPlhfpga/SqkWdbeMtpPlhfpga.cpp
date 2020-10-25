/**
	* \file SqkWdbeMtpPlhfpga.cpp
	* squawk generation for operation pack WdbeMtpPlhfpga (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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


