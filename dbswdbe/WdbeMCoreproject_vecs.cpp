/**
	* \file WdbeMCoreproject_vecs.cpp
	* database access for table TblWdbeMCoreproject (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

