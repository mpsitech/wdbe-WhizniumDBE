/**
	* \file WdbePrctreeExtract.h
	* Wdbe operation processor - extract from file tree into extract file tree (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEPRCTREEEXTRACT_H
#define WDBEPRCTREEEXTRACT_H

#include "WdbePrctree.h"

// IP include.cust --- INSERT

namespace WdbePrctreeExtract {

	DpchRetWdbePrctreeExtract* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbePrctreeExtract* dpchinv);
	// IP cust --- IBEGIN

	bool scanFolder(const std::string& tmppath, const std::string& infolder, const std::string& extfolder, std::fstream& logfi);
	bool scanFile(const std::string& tmppath, const std::string& infile, const std::string& extfile, std::fstream& logfi);
	void writeExtfile(const std::string& tmppath, const std::string& extfile, const std::vector<WdbePrctree::Ip*>& ips);
	// IP cust --- IEND
};

#endif



