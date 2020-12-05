/**
	* \file WdbeWrfpgaMdlraw.h
	* Wdbe operation processor - write raw VHDL code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEWRFPGAMDLRAW_H
#define WDBEWRFPGAMDLRAW_H

#include "WdbeWrfpga.h"

// IP include.cust --- INSERT

namespace WdbeWrfpgaMdlraw {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrfpgaMdlraw* dpchinv);
	// IP cust --- IBEGIN

	void writeMdlVhd(DbsWdbe* dbswdbe, std::fstream& outfile, const std::string& Prjshort, const std::string& Untsref, WdbeMModule* mdl);

	void getHdltypeLibs(DbsWdbe* dbswdbe, const Sbecore::ubigint refUnt, std::set<std::string>& srefsLibmdls, std::map<std::string,std::string>& srefsLibs);
	void fillIcsMdc(std::vector<Sbecore::uint>& icsMdc);
	// IP cust --- IEND
};

#endif



