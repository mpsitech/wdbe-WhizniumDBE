/**
	* \file WdbeWrfpgaBase.h
	* Wdbe operation processor - write VHDL/UCF/XDC code basics (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEWRFPGABASE_H
#define WDBEWRFPGABASE_H

#include "WdbeWrfpga.h"

// IP include.cust --- INSERT

namespace WdbeWrfpgaBase {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrfpgaBase* dpchinv);
	// IP cust --- IBEGIN

	void writeUntUcf(DbsWdbe* dbswdbe, std::fstream& outfile, std::set<std::string>& srefsTopprts, ListWdbeMBank& bnks);
	void writeUntPdc(DbsWdbe* dbswdbe, std::fstream& outfile, ListWdbeMPort& topprts, ListWdbeMBank& bnks);
	void writeUntXdc(DbsWdbe* dbswdbe, std::fstream& outfile, const Sbecore::ubigint refWdbeMUnit, std::set<std::string>& srefsTopprts, ListWdbeMBank& bnks);
	void writeUntVhd(DbsWdbe* dbswdbe, std::fstream& outfile, const std::string& Prjshort, const std::string& Untsref, WdbeMUnit* unt);
	// IP cust --- IEND
};

#endif
