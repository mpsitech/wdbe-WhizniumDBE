/**
	* \file WdbeMImbuf_vecs.cpp
	* database access for table TblWdbeMImbuf (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWdbeMImbuf::VecVRotype
 ******************************************************************************/

uint TblWdbeMImbuf::VecVRotype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "sngatmt") return SNGATMT;
	if (s == "multatmt") return MULTATMT;
	if (s == "strm") return STRM;

	return(0);
};

string TblWdbeMImbuf::VecVRotype::getSref(
			const uint ix
		) {
	if (ix == SNGATMT) return("sngatmt");
	if (ix == MULTATMT) return("multatmt");
	if (ix == STRM) return("strm");

	return("");
};

string TblWdbeMImbuf::VecVRotype::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == SNGATMT) return("single attempt");
		if (ix == MULTATMT) return("multiple attempt");
		if (ix == STRM) return("stream");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMImbuf::VecVRotype::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};
