/**
	* \file WdbeWrfpgaBase.h
	* Wdbe operation processor - write VHDL/UCF/XDC code basics (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEWRFPGABASE_H
#define WDBEWRFPGABASE_H

#include "WdbeWrfpga.h"

// IP include.cust --- INSERT

namespace WdbeWrfpgaBase {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrfpgaBase* dpchinv);
	// IP cust --- IBEGIN

	void writeUntUcf(DbsWdbe* dbswdbe, std::fstream& outfile, std::set<std::string>& srefsTopprts, ListWdbeMBank& bnks);
	void writeUntXdc(DbsWdbe* dbswdbe, std::fstream& outfile, const Sbecore::ubigint refWdbeMUnit, std::set<std::string>& srefsTopprts, ListWdbeMBank& bnks, const bool zynqNotFpga);
	void writeUntVhd(DbsWdbe* dbswdbe, std::fstream& outfile, const std::string& Prjshort, const std::string& Untsref, WdbeMUnit* unt);
	// IP cust --- IEND
};

#endif


