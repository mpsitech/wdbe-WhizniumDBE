/**
	* \file WdbeMVariable_vecs.cpp
	* database access for table TblWdbeMVariable (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWdbeMVariable::VecVRefTbl
 ******************************************************************************/

uint TblWdbeMVariable::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "mdl") return MDL;
	if (s == "prc") return PRC;

	return(0);
};

string TblWdbeMVariable::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == MDL) return("mdl");
	if (ix == PRC) return("prc");

	return("");
};

string TblWdbeMVariable::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == MDL) return("module");
		if (ix == PRC) return("process");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMVariable::VecVRefTbl::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};
