/**
	* \file WdbePrctree.h
	* Wdbe operation pack global code (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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
		const unsigned int TXT = 0;
		const unsigned int XML = 1;
		const unsigned int CJS = 2;
		const unsigned int SQL = 3;
		const unsigned int MSH = 4;
		const unsigned int CSS = 5;

		unsigned int get(const std::string& path, bool& ip);
		void getPrefixInfixPostfix(const unsigned int fmt, std::string& prefix, std::string& infix, std::string& postfix);
	};

	namespace Iptype {
		const unsigned int INVALID = 0;
		const unsigned int KEEP = 1;
		const unsigned int INSERT = 2;
		const unsigned int AFFIRM = 3;
		const unsigned int REMOVE = 4;
		const unsigned int LINE = 5;
		const unsigned int BEGIN = 6;
		const unsigned int END = 7;
		const unsigned int ILINE = 8;
		const unsigned int IBEGIN = 9;
		const unsigned int IEND = 10;
		const unsigned int RLINE = 11;
		const unsigned int RBEGIN = 12;
		const unsigned int REND = 13;

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

	public:
		void write(std::fstream& outfile, const unsigned int fmt);
	};

	bool parseFile(const std::string& path, std::fstream& logfile, const bool log, std::vector<Ip*>& ips, unsigned int& fmt);
	void readFileContent(const std::string& path, std::vector<Ip*>& ips, std::map<std::string,unsigned int>& icsIpsAffirm, std::map<std::string,unsigned int>& icsIpsRemove, std::map<std::string,unsigned int>& icsIpsIline, std::map<std::string,unsigned int>& icsIpsIbegin, std::map<std::string,unsigned int>& icsIpsRline, std::map<std::string,unsigned int>& icsIpsRbegin);
	// IP cust --- IEND
};

#endif


