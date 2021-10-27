/**
	* \file WdbeMVersion_vecs.cpp
	* database access for table TblWdbeMVersion (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWdbeMVersion::VecVState
 ******************************************************************************/

uint TblWdbeMVersion::VecVState::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "newcre") return NEWCRE;
	if (s == "newimp") return NEWIMP;
	if (s == "dsnmdlstr") return DSNMDLSTR;
	if (s == "dsncmdset") return DSNCMDSET;
	if (s == "dsndflalg") return DSNDFLALG;
	if (s == "dsngenfst") return DSNGENFST;
	if (s == "dsncustfst") return DSNCUSTFST;
	if (s == "ready") return READY;
	if (s == "abandon") return ABANDON;

	return(0);
};

string TblWdbeMVersion::VecVState::getSref(
			const uint ix
		) {
	if (ix == NEWCRE) return("newcre");
	if (ix == NEWIMP) return("newimp");
	if (ix == DSNMDLSTR) return("dsnmdlstr");
	if (ix == DSNCMDSET) return("dsncmdset");
	if (ix == DSNDFLALG) return("dsndflalg");
	if (ix == DSNGENFST) return("dsngenfst");
	if (ix == DSNCUSTFST) return("dsncustfst");
	if (ix == READY) return("ready");
	if (ix == ABANDON) return("abandon");

	return("");
};

string TblWdbeMVersion::VecVState::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == NEWCRE) return("newly created");
		if (ix == NEWIMP) return("newly imported");
		if (ix == DSNMDLSTR) return("design phase, modular structure imported");
		if (ix == DSNCMDSET) return("design phase, command set imported");
		if (ix == DSNDFLALG) return("design phase, data flows and algorithms imported");
		if (ix == DSNGENFST) return("design phase, fine structure generated");
		if (ix == DSNCUSTFST) return("design phase, custom fine structure applied");
		if (ix == READY) return("build-ready");
		if (ix == ABANDON) return("abandonned");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMVersion::VecVState::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 9; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};
