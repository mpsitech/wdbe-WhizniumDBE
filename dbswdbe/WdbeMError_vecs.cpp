/**
	* \file WdbeMError_vecs.cpp
	* database access for table TblWdbeMError (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWdbeMError::VecVRefTbl
 ******************************************************************************/

uint TblWdbeMError::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ctr") return CTR;
	if (s == "unt") return UNT;

	return(0);
};

string TblWdbeMError::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == CTR) return("ctr");
	if (ix == UNT) return("unt");

	return("");
};

string TblWdbeMError::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == CTR) return("controller");
		if (ix == UNT) return("unit");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMError::VecVRefTbl::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};
