/**
	* \file WdbeWrtermMain.h
	* Wdbe operation processor - write interactive terminal executable code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

#ifndef WDBEWRTERMMAIN_H
#define WDBEWRTERMMAIN_H

#include "WdbeWrterm.h"

// IP include.cust --- INSERT

namespace WdbeWrtermMain {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrtermMain* dpchinv);
	// IP cust --- IBEGIN

	void writeExeCpp(std::fstream& outfile, const std::string& Prjshort, ListWdbeMUnit& unts);
	// IP cust --- IEND
};

#endif
