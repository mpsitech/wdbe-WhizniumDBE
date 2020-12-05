/**
	* \file WdbeWrmcuMdlfine.h
	* Wdbe operation processor - write in-detail C code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEWRMCUMDLFINE_H
#define WDBEWRMCUMDLFINE_H

#include "WdbeWrmcu.h"

// IP include.cust --- INSERT

namespace WdbeWrmcuMdlfine {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrmcuMdlfine* dpchinv);
	// IP cust --- IBEGIN

  void writeMdlC(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMModule* mdl);
	// IP cust --- IEND
};

#endif



