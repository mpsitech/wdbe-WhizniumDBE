/**
	* \file WdbePrcfileIexconv.h
	* Wdbe operation processor - convert text import input file into output file (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEPRCFILEIEXCONV_H
#define WDBEPRCFILEIEXCONV_H

#include "WdbePrcfile.h"

// IP include.cust --- INSERT

namespace WdbePrcfileIexconv {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbePrcfileIexconv* dpchinv);
	// IP cust --- IBEGIN
	void runIconv(const std::string& infile, const std::string& outfile);
	void convert(std::ifstream& txtfile, std::ofstream& iexfile);

	std::string unicodeToHexcode(unsigned int unicode);
	void strISO8859(std::string& s);

	void strRequote(std::string& s);
	// IP cust --- IEND
};

#endif


