/**
	* \file WdbeWrmcuMdlfine.h
	* Wdbe operation processor - write in-detail C code (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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


