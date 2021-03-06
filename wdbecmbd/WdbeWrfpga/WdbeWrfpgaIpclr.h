/**
	* \file WdbeWrfpgaIpclr.h
	* Wdbe operation processor - write VHDL code to clear unused specific insertion points (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEWRFPGAIPCLR_H
#define WDBEWRFPGAIPCLR_H

#include "WdbeWrfpga.h"

// IP include.cust --- INSERT

namespace WdbeWrfpgaIpclr {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrfpgaIpclr* dpchinv);
	// IP cust --- IBEGIN

	void writeMdlVhd(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMModule* mdl);
	// IP cust --- IEND
};

#endif
