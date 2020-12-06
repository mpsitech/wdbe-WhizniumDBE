/**
	* \file WdbeWrfpgaHostif.h
	* Wdbe operation processor - write template-specific VHDL code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEWRFPGAHOSTIF_H
#define WDBEWRFPGAHOSTIF_H

#include "WdbeWrfpga.h"

// IP include.cust --- INSERT

namespace WdbeWrfpgaHostif {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrfpgaHostif* dpchinv);
	// IP cust --- IBEGIN

	void writeMdlVhd(DbsWdbe* dbswdbe, std::fstream& outfile, const std::string& Prjshort, const std::string& Untsref, WdbeMModule* mdl);

	Sbecore::usmallint getImbwavllen(DbsWdbe* dbswdbe, WdbeMModule* hostif, const std::string& Imbsigsref);
	// IP cust --- IEND
};

#endif
