/**
	* \file WdbeWrdevBase.h
	* Wdbe operation processor - write device access library C++ code basics (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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


