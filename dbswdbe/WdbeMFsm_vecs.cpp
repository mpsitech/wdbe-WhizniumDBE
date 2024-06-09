/**
	* \file WdbeMFsm_vecs.cpp
	* database access for table TblWdbeMFsm (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 May 2023
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWdbeMFsm::VecVDbgtaptype
 ******************************************************************************/

uint TblWdbeMFsm::VecVDbgtaptype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "lin") return LIN;
	if (s == "clust") return CLUST;

	return(0);
};

string TblWdbeMFsm::VecVDbgtaptype::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == LIN) return("lin");
	if (ix == CLUST) return("clust");

	return("");
};

string TblWdbeMFsm::VecVDbgtaptype::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == LIN) return("linear");
		if (ix == CLUST) return("clustered");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMFsm::VecVDbgtaptype::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};
