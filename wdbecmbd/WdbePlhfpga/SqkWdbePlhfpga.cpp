/**
	* \file SqkWdbePlhfpga.cpp
	* squawk generation for operation pack WdbePlhfpga (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "SqkWdbePlhfpga.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWdbePlhfpga
 ******************************************************************************/

string SqkWdbePlhfpga::getSquawkCmdinv(
			DbsWdbe* dbswdbe
			, DpchInvWdbePlhfpgaCmdinv* dpchinv
		) {
	// example: "fill type-specific placeholders for module 'icm2-cmdinv (cmdinv_v1_0 command invocation buffer)'"
	return(""); // IP getSquawkCmdinv --- LINE
};

string SqkWdbePlhfpga::getSquawkCmdret(
			DbsWdbe* dbswdbe
			, DpchInvWdbePlhfpgaCmdret* dpchinv
		) {
	// example: "fill type-specific placeholders for module 'dcx3-cmdret (cmdret_v1_0 command return buffer)'"
	return(""); // IP getSquawkCmdret --- LINE
};

string SqkWdbePlhfpga::getSquawkEhostif(
			DbsWdbe* dbswdbe
			, DpchInvWdbePlhfpgaEhostif* dpchinv
		) {
	// example: "fill type-specific placeholders for module 'icm2-hostif (uarthostif_Easy_v1_0 easy model host interface)'"
	return(""); // IP getSquawkEhostif --- LINE
};

string SqkWdbePlhfpga::getSquawkFwdctr(
			DbsWdbe* dbswdbe
			, DpchInvWdbePlhfpgaFwdctr* dpchinv
		) {
	// example: "fill type-specific placeholders for module 'dcx3-qcdif (fwdctr_v1_0 forwarding controller)'"
	return(""); // IP getSquawkFwdctr --- LINE
};

