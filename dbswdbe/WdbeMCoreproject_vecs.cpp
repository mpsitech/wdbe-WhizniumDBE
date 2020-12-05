/**
	* \file WdbeMCoreproject_vecs.cpp
	* database access for table TblWdbeMCoreproject (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWdbeMCoreproject::VecVBasetype
 ******************************************************************************/

uint TblWdbeMCoreproject::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "custip") return CUSTIP;
	if (s == "mnfip") return MNFIP;

	return(0);
};

string TblWdbeMCoreproject::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == CUSTIP) return("custip");
	if (ix == MNFIP) return("mnfip");

	return("");
};

string TblWdbeMCoreproject::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == CUSTIP) return("custom IP");
		if (ix == MNFIP) return("manufacturer IP");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMCoreproject::VecVBasetype::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

