/**
	* \file WdbeWrfpgaAux.h
	* Wdbe operation processor - write auxiliary VHDL code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 30 May 2023
  */
// IP header --- ABOVE

#ifndef WDBEWRFPGAAUX_H
#define WDBEWRFPGAAUX_H

#include "WdbeWrfpga.h"

// IP include.cust --- INSERT

namespace WdbeWrfpgaAux {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrfpgaAux* dpchinv);
	// IP cust --- IBEGIN

	void writeCdcVhd(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMCdc* cdc);
	void writeCdcVhd_impl(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMCdc* cdc, const Sbecore::uint ixVDir, ListWdbeRMCdcMSignal& crss);

	void writeIpclrVhd(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMModule* mdl);
	// IP cust --- IEND
};

#endif
