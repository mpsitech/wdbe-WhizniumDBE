/**
	* \file WdbePrctree.h
	* Wdbe operation pack global code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEPRCTREE_H
#define WDBEPRCTREE_H

#include "WdbePrctree_blks.h"

// IP include.cust --- IBEGIN
#include <sys/types.h>
#include <dirent.h>
// IP include.cust --- IEND

namespace WdbePrctree {

	// IP cust --- IBEGIN
	namespace Ipformat {
		const unsigned int GNR = 0;
		const unsigned int XML = 1;
		const unsigned int SQL = 2;
		const unsigned int MSH = 3;
		const unsigned int CSS = 4;

		unsigned int get(const std::string& path, bool& ip);
		void getPrefixInfixPostfix(const unsigned int fmt, std::string& prefix, std::string& infix, std::string& postfix);
	};

	namespace Iptype {
		const unsigned int INVALID = 0;
		const unsigned int ABOVE = 1;
		const unsigned int KEEP = 2;
		const unsigned int INSERT = 3;
		const unsigned int AFFIRM = 4;
		const unsigned int REMOVE = 5;
		const unsigned int LINE = 6;
		const unsigned int BEGIN = 7;
		const unsigned int END = 8;
		const unsigned int ILINE = 9;
		const unsigned int IBEGIN = 10;
		const unsigned int IEND = 11;
		const unsigned int RLINE = 12;
		const unsigned int RBEGIN = 13;
		const unsigned int REND = 14;

		unsigned int get(std::string s);
	};

	class Ip {

	public:
		Ip(const std::string& tag = "", const unsigned int type = 0, const unsigned int lineno = 0, const unsigned int il = 0, const size_t ptr0 = 0);

	public:
		std::string tag;
		unsigned int type;
		unsigned int lineno;
		unsigned int il;
		size_t ptr0;

		Ip* par;

		std::vector<std::string> content;
	};

	bool parseFile(const std::string& path, std::fstream& logfile, const bool log, std::vector<Ip*>& ips, unsigned int& fmt);
	void readFileContent(const std::string& path, std::vector<Ip*>& ips, bool& hasIpAbove, bool& hasIpKeep, std::map<std::string,unsigned int>& icsIpsAffirm, std::map<std::string,unsigned int>& icsIpsRemove, std::map<std::string,unsigned int>& icsIpsIline, std::map<std::string,unsigned int>& icsIpsIbegin, std::map<std::string,unsigned int>& icsIpsRline, std::map<std::string,unsigned int>& icsIpsRbegin);
	// IP cust --- IEND
};

#endif



