/**
	* \file WdbeWrdevSys.h
	* Wdbe operation processor - write C++ code for system (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEWRDEVSYS_H
#define WDBEWRDEVSYS_H

#include "WdbeWrdev.h"

// IP include.cust --- INSERT

namespace WdbeWrdevSys {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrdevSys* dpchinv);
	// IP cust --- IBEGIN

	void writeSysH(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMSystem* sys, ListWdbeMUnit& unts, ListWdbeMVector& vecs);
	void writeSysvecsCpp(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMSystem* sys, ListWdbeMVector& vecs);
	void writeSysCpp(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMSystem* sys, ListWdbeMTarget& trgs, ListWdbeMUnit& unts, std::map<Sbecore::ubigint,unsigned int>& icsTrgunts, std::vector<bool>& hasvecbufs, std::vector<bool>& hasvecctrs, std::vector<bool>& hasveccmds, std::vector<bool>& hasvecerrs, ListWdbeMVector& vecs);

	void expandTrgRte(DbsWdbe* dbswdbe, ListWdbeMTarget& trgs, const unsigned int ixTrg, ListWdbeMUnit& unts, std::vector<std::string>& srefsTrgs, std::vector<std::string>& srefsFwdctrs, std::vector<std::string>& fullsrefsFwdctrs, std::vector<std::string>& srefsRdbufs, std::vector<std::string>& srefsWrbufs);
	void getTrgSubtrgs(ListWdbeMTarget& trgs, const unsigned int ixTrg, std::set<unsigned int>& icsSubtrgs);
	// IP cust --- IEND
};

#endif



