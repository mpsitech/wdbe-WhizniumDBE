/**
	* \file WdbeWrmcuBase.h
	* Wdbe operation processor - write C code basics (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEWRMCUBASE_H
#define WDBEWRMCUBASE_H

#include "WdbeWrmcu.h"

// IP include.cust --- INSERT

namespace WdbeWrmcuBase {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrmcuBase* dpchinv);
	// IP cust --- IBEGIN

	void writeUntH(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMUnit* unt, ListWdbeMModule& mdls);
	void writeUntExeC(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMUnit* unt, ListWdbeMModule& mdls);

	void fillIcsMdc(std::vector<Sbecore::uint>& icsMdc);
	// IP cust --- IEND
};

#endif


