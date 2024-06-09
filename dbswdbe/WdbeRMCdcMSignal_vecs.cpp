/**
	* \file WdbeRMCdcMSignal_vecs.cpp
	* database access for table TblWdbeRMCdcMSignal (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWdbeRMCdcMSignal::VecVDir
 ******************************************************************************/

uint TblWdbeRMCdcMSignal::VecVDir::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "fts") return FTS;
	if (s == "stf") return STF;

	return(0);
};

string TblWdbeRMCdcMSignal::VecVDir::getSref(
			const uint ix
		) {
	if (ix == FTS) return("fts");
	if (ix == STF) return("stf");

	return("");
};

string TblWdbeRMCdcMSignal::VecVDir::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == FTS) return("fast to slow");
		if (ix == STF) return("slow to fast");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeRMCdcMSignal::VecVDir::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};
