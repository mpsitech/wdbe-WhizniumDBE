/**
	* \file WdbeWrdevCtr.h
	* Wdbe operation processor - write C++ code for controller (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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


