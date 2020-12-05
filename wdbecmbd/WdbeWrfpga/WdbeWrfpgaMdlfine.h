/**
	* \file WdbeWrfpgaMdlfine.h
	* Wdbe operation processor - write in-detail VHDL code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEWRFPGAMDLFINE_H
#define WDBEWRFPGAMDLFINE_H

#include "WdbeWrfpga.h"

// IP include.cust --- INSERT

namespace WdbeWrfpgaMdlfine {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrfpgaMdlfine* dpchinv);
	// IP cust --- IBEGIN

	void writeMdlVhd(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMModule* mdl);
	void writeMdlVhd_reset(std::fstream& outfile, const Sbecore::ubigint refWdbeMProcess, ListWdbeMSignal& sigs, ListWdbeMVariable& vars, const bool syncNotAsync, const unsigned int il);

	std::string expandCond(const std::string& Cond, const std::string& Prcsref, std::set<std::string>& srefsSlprtsigs, std::set<std::string>& srefsSlvars, const unsigned int maxlen, const unsigned int indent);
	std::string expandCond_getTknstr(const std::string& sin, std::vector<unsigned int>& tkns, std::vector<unsigned int>& ptrsTkns, const unsigned int ix);
	void expandCond_checkBreak(std::string& sout, unsigned int& ptr, const unsigned int maxlen, const unsigned int indent);
	// IP cust --- IEND
};

#endif



