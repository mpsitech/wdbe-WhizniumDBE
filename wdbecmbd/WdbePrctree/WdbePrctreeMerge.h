/**
	* \file WdbePrctreeMerge.h
	* Wdbe operation processor - merge extract file tree into template file tree (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEPRCTREEMERGE_H
#define WDBEPRCTREEMERGE_H

#include "WdbePrctree.h"

// IP include.cust --- INSERT

namespace WdbePrctreeMerge {

	DpchRetWdbePrctreeMerge* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbePrctreeMerge* dpchinv);
	// IP cust --- IBEGIN

	bool scanFolder(const std::string& tmppath, const std::string& tplroot, const std::string& tplsub, const std::string& extfolder, const bool notrace, const bool skipmultvoid, std::fstream& logfi);
	void invscanFolder(const std::string& tmppath, const std::string& tplfolder, const std::string& extroot, const std::string& extsub);
	bool scanFile(const std::string& tmppath, const std::string& tplfile, const std::string& extfile, const bool notrace, const bool skipmultvoid, std::fstream& logfi);

	void writeTmpfile(const std::string& tmppath, std::fstream& tmpfi, const std::string& tplfile, const std::string& extfile, const std::vector<WdbePrctree::Ip*>& ips, const std::vector<WdbePrctree::Ip*>& extips, const bool hasExtipAbove, std::map<std::string,unsigned int>& icsExtipsAffirm, std::map<std::string,unsigned int>& icsExtipsRemove, std::map<std::string,unsigned int>& icsExtipsIline, std::map<std::string,unsigned int>& icsExtipsIbegin, std::map<std::string,unsigned int>& icsExtipsRline, std::map<std::string,unsigned int>& icsExtipsRbegin, const bool notrace, const bool skipmultvoid);
	void writeTmpfile_line(std::fstream& tmpfi, const std::string& line, unsigned int& newlinecnt, const bool skipmultvoid);
	// IP cust --- IEND
};

#endif
