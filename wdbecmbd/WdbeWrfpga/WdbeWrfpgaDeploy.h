/**
	* \file WdbeWrfpgaDeploy.h
	* Wdbe operation processor - write FPGA code deployment scripts (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

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
