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

string SqkWdbeCplmst::getSquawkCtrEctrHostifEhostif(
			DbsWdbe* dbswdbe
			, DpchInvWdbeCplmstCtrEctrHostifEhostif* dpchinv
		) {
	// example: "add controller for module 'dcx3-pmmu (controller)'"
	return(""); // IP getSquawkCtrEctrHostifEhostif --- LINE
};

string SqkWdbeCplmst::getSquawkImbuf(
			DbsWdbe* dbswdbe
			, DpchInvWdbeCplmstImbuf* dpchinv
		) {
	// example: "add parameters for module 'icm2-acq-buf (dpbram_v1_0)'"
	return(""); // IP getSquawkImbuf --- LINE
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
