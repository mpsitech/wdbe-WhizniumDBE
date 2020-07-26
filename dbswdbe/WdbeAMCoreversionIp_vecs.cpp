/**
	* \file WdbeAMCoreversionIp_vecs.cpp
	* database access for table TblWdbeAMCoreversionIp (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWdbeAMCoreversionIp::VecVTagtype
 ******************************************************************************/

uint TblWdbeAMCoreversionIp::VecVTagtype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ins") return INS;
	if (s == "rmv") return RMV;
	if (s == "repl") return REPL;

	return(0);
};

string TblWdbeAMCoreversionIp::VecVTagtype::getSref(
			const uint ix
		) {
	if (ix == INS) return("ins");
	if (ix == RMV) return("rmv");
	if (ix == REPL) return("repl");

	return("");
};

string TblWdbeAMCoreversionIp::VecVTagtype::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == INS) return("ibegin/iend");
		if (ix == RMV) return("remove");
		if (ix == REPL) return("rbegin/rend");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeAMCoreversionIp::VecVTagtype::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

