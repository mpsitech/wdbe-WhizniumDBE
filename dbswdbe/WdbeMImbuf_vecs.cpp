/**
	* \file WdbeMImbuf_vecs.cpp
	* database access for table TblWdbeMImbuf (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWdbeMImbuf::VecVDir
 ******************************************************************************/

uint TblWdbeMImbuf::VecVDir::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "in") return IN;
	if (s == "out") return OUT;

	return(0);
};

string TblWdbeMImbuf::VecVDir::getSref(
			const uint ix
		) {
	if (ix == IN) return("in");
	if (ix == OUT) return("out");

	return("");
};

string TblWdbeMImbuf::VecVDir::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == IN) return("input");
		if (ix == OUT) return("output");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMImbuf::VecVDir::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

