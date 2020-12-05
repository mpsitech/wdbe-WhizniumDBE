/**
	* \file WdbeWrfpgaEhostif.h
	* Wdbe operation processor - write template-specific VHDL code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEWRFPGAEHOSTIF_H
#define WDBEWRFPGAEHOSTIF_H

#include "WdbeWrfpga.h"

// IP include.cust --- INSERT

namespace WdbeWrfpgaEhostif {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrfpgaEhostif* dpchinv);
	// IP cust --- IBEGIN
	
	void writeMdlVhd(DbsWdbe* dbswdbe, std::fstream& outfile, const std::string& Prjshort, const std::string& Untsref, WdbeMModule* mdl);
	// IP cust --- IEND
};

#endif



