/**
	* \file WdbeMVector_vecs.cpp
	* database access for table TblWdbeMVector (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWdbeMVector::VecVBasetype
 ******************************************************************************/

uint TblWdbeMVector::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ixlin") return IXLIN;
	if (s == "tixlin") return TIXLIN;
	if (s == "tixor") return TIXOR;

	return(0);
};

string TblWdbeMVector::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == IXLIN) return("ixlin");
	if (ix == TIXLIN) return("tixlin");
	if (ix == TIXOR) return("tixor");

	return("");
};

string TblWdbeMVector::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == IXLIN) return("uint index linear");
		if (ix == TIXLIN) return("utinyint index linear");
		if (ix == TIXOR) return("utinyint index multi-choice");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMVector::VecVBasetype::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class TblWdbeMVector::VecVHkTbl
 ******************************************************************************/

uint TblWdbeMVector::VecVHkTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "cmd") return CMD;
	if (s == "ctr") return CTR;
	if (s == "fsm") return FSM;
	if (s == "sig") return SIG;
	if (s == "unt") return UNT;

	return(0);
};

string TblWdbeMVector::VecVHkTbl::getSref(
			const uint ix
		) {
	if (ix == CMD) return("cmd");
	if (ix == CTR) return("ctr");
	if (ix == FSM) return("fsm");
	if (ix == SIG) return("sig");
	if (ix == UNT) return("unt");

	return("");
};

string TblWdbeMVector::VecVHkTbl::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == CMD) return("command");
		if (ix == CTR) return("controller");
		if (ix == FSM) return("finite state machine");
		if (ix == SIG) return("signal");
		if (ix == UNT) return("unit");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMVector::VecVHkTbl::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 5; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};
