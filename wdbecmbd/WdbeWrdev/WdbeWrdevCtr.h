/**
	* \file WdbeWrdevCtr.h
	* Wdbe operation processor - write C++ code for controller (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEWRDEVCTR_H
#define WDBEWRDEVCTR_H

#include "WdbeWrdev.h"

// IP include.cust --- INSERT

namespace WdbeWrdevCtr {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrdevCtr* dpchinv);
	// IP cust --- IBEGIN

	void writeCtrH(DbsWdbe* dbswdbe, std::fstream& outfile, const bool Easy, WdbeMController* ctr, ListWdbeMVector& vecs, ListWdbeMCommand& cmds, ListWdbeMError& errs);
	void writeCtrCpp(DbsWdbe* dbswdbe, std::fstream& outfile, const bool Easy, WdbeMController* ctr, const Sbecore::utinyint tixCtr, const std::string& srefCtr, ListWdbeMVector& vecs, ListWdbeMCommand& cmds, ListWdbeMError& errs);
	// IP cust --- IEND
};

#endif



