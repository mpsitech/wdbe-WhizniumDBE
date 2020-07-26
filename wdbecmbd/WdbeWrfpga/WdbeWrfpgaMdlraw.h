/**
	* \file WdbeWrfpgaMdlraw.h
	* Wdbe operation processor - write raw VHDL code (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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


