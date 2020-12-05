/**
	* \file WdbeWrdevBase.h
	* Wdbe operation processor - write device access library C++ code basics (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEWRDEVBASE_H
#define WDBEWRDEVBASE_H

#include "WdbeWrdev.h"

// IP include.cust --- INSERT

namespace WdbeWrdevBase {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrdevBase* dpchinv);
	// IP cust --- IBEGIN
	void writeDevH(DbsWdbe* dbswdbe, std::fstream& outfile, const Sbecore::ubigint refWdbeMVersion, const std::string& Prjshort, const bool Easy);
	// IP cust --- IEND
};

#endif



