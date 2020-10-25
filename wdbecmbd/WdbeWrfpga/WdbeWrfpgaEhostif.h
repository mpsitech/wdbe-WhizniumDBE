/**
	* \file WdbeWrfpgaEhostif.h
	* Wdbe operation processor - write template-specific VHDL code (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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


