/**
	* \file WdbeWrmcuMdlraw.h
	* Wdbe operation processor - write raw C code (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEWRMCUMDLRAW_H
#define WDBEWRMCUMDLRAW_H

#include "WdbeWrmcu.h"

// IP include.cust --- INSERT

namespace WdbeWrmcuMdlraw {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrmcuMdlraw* dpchinv);
	// IP cust --- IBEGIN

  void writeMdlH(DbsWdbe* dbswdbe, std::fstream& outfile, const std::string& Prjshort, const std::string& Untsref, WdbeMModule* mdl, ListWdbeMProcess& prcs);
  void writeMdlC(DbsWdbe* dbswdbe, std::fstream& outfile, const std::string& Prjshort, const std::string& Untsref, const std::string& Compsref, WdbeMModule* mdl, ListWdbeMProcess& prcs);
	// IP cust --- IEND
};

#endif


