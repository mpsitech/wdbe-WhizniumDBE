/**
	* \file WdbeWrfpgaDeploy.h
	* Wdbe operation processor - write FPGA code deployment scripts (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEWRFPGADEPLOY_H
#define WDBEWRFPGADEPLOY_H

#include "WdbeWrfpga.h"

// IP include.cust --- INSERT

namespace WdbeWrfpgaDeploy {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrfpgaDeploy* dpchinv);
	// IP cust --- IBEGIN

	void writeChkoutSh(DbsWdbe* dbswdbe, std::fstream& outfile, ListWdbeMUnit& unts);
	// IP cust --- IEND
};

#endif


