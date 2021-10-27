/**
	* \file SqkWdbeCplmst.cpp
	* squawk generation for operation pack WdbeCplmst (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "SqkWdbeCplmst.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWdbeCplmst
 ******************************************************************************/

string SqkWdbeCplmst::getSquawkCtrEctr(
			DbsWdbe* dbswdbe
			, DpchInvWdbeCplmstCtrEctr* dpchinv
		) {
	// example: "add controller for module 'dcx3-pmmu (controller)'"
	return(""); // IP getSquawkCtrEctr --- LINE
};

string SqkWdbeCplmst::getSquawkFwdctr(
			DbsWdbe* dbswdbe
			, DpchInvWdbeCplmstFwdctr* dpchinv
		) {
	// example: "add read and write buffers and commands for module 'dcx3-qcdif (spifwd_v1_0 forwarding controller)'"
	return(""); // IP getSquawkFwdctr --- LINE
};

string SqkWdbeCplmst::getSquawkImbuf(
			DbsWdbe* dbswdbe
			, DpchInvWdbeCplmstImbuf* dpchinv
		) {
	// example: "add parameters for module 'icm2-acq-buf (dpbram_v1_0)'"
	return(""); // IP getSquawkImbuf --- LINE
};

string SqkWdbeCplmst::getSquawkSys(
			DbsWdbe* dbswdbe
			, DpchInvWdbeCplmstSys* dpchinv
		) {
	// example: "add standard vectors for version 'ICARUSDetectorHardwareControl 0.1.0'"
	return(""); // IP getSquawkSys --- LINE
};

string SqkWdbeCplmst::getSquawkTplcpy(
			DbsWdbe* dbswdbe
			, DpchInvWdbeCplmstTplcpy* dpchinv
		) {
	// example: "copy parameters, subs, generics and ports from template for module 'icm2-acq-buf (bpbram_v1_0)'"
	return(""); // IP getSquawkTplcpy --- LINE
};

string SqkWdbeCplmst::getSquawkUnt(
			DbsWdbe* dbswdbe
			, DpchInvWdbeCplmstUnt* dpchinv
		) {
	// example: "add standard vectors for unit 'icacam2'"
	return(""); // IP getSquawkUnt --- LINE
};
