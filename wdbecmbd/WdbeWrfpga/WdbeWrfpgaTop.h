/**
	* \file WdbeWrfpgaTop.h
	* Wdbe operation processor - write type-specific VHDL code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 16 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBEWRFPGATOP_H
#define WDBEWRFPGATOP_H

#include "WdbeWrfpga.h"

// IP include.cust --- INSERT

namespace WdbeWrfpgaTop {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrfpgaTop* dpchinv);
	// IP cust --- IBEGIN

	void writeMdlVhd(DbsWdbe* dbswdbe, std::fstream& outfile, const std::string& Prjshort, const std::string& Untsref, WdbeMModule* mdl);
	// IP cust --- IEND
};

#endif
