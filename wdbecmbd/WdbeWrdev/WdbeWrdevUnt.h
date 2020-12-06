/**
	* \file WdbeWrdevUnt.h
	* Wdbe operation processor - write C++ code for unit (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEWRDEVUNT_H
#define WDBEWRDEVUNT_H

#include "WdbeWrdev.h"

// IP include.cust --- INSERT

namespace WdbeWrdevUnt {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrdevUnt* dpchinv);
	// IP cust --- IBEGIN

	void writeUntH(DbsWdbe* dbswdbe, std::fstream& outfile, const bool Easy, WdbeMUnit* unt, const std::string& srefroot, ListWdbeMController& ctrs, ListWdbeMImbuf& imbs, ListWdbeMCommand& cmds, ListWdbeMError& errs, const Sbecore::ubigint refHostif, const Sbecore::uint ixImbCmdinv, const Sbecore::uint ixImbCmdret, const bool hasvecbuf, const bool hasvecctr, const bool hasveccmd, const bool hasvecerr, const bool hasspeccmd);
	void writeUntCpp(DbsWdbe* dbswdbe, std::fstream& outfile, const bool Easy, WdbeMUnit* unt, const std::string& srefroot, ListWdbeMController& ctrs, ListWdbeMImbuf& imbs, ListWdbeMCommand& cmds, ListWdbeMError& err, const Sbecore::ubigint refHostif, const Sbecore::uint ixImbCmdinv, const Sbecore::uint ixImbCmdret, const bool hasvecbuf, const bool hasvecctr, const bool hasveccmd, const bool hasvecerr);

	void writeUntvecsH(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMUnit* unt, ListWdbeMVector& vecs);
	void writeUntvecsCpp(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMUnit* unt, ListWdbeMVector& vecs);
	// IP cust --- IEND
};

#endif
