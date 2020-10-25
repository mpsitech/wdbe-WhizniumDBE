/**
	* \file WdbePrctreeExtract.h
	* Wdbe operation processor - extract from file tree into extract file tree (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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


