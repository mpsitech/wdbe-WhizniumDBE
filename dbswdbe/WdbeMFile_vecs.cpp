/**
	* \file WdbeMFile_vecs.cpp
	* database access for table TblWdbeMFile (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWdbeMFile::VecVRefTbl
 ******************************************************************************/

uint TblWdbeMFile::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "mtp") return MTP;
	if (s == "ver") return VER;

	return(0);
};

string TblWdbeMFile::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == MTP) return("mtp");
	if (ix == VER) return("ver");

	return("");
};

string TblWdbeMFile::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == MTP) return("module template");
		if (ix == VER) return("version");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMFile::VecVRefTbl::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};
