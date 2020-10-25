/**
	* \file WdbeMCommand_vecs.cpp
	* database access for table TblWdbeMCommand (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWdbeMCommand::VecVRefTbl
 ******************************************************************************/

uint TblWdbeMCommand::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ctr") return CTR;
	if (s == "unt") return UNT;

	return(0);
};

string TblWdbeMCommand::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == CTR) return("ctr");
	if (ix == UNT) return("unt");

	return("");
};

string TblWdbeMCommand::VecVRefTbl::getTitle(
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

void TblWdbeMCommand::VecVRefTbl::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class TblWdbeMCommand::VecVRettype
 ******************************************************************************/

uint TblWdbeMCommand::VecVRettype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "statsng") return STATSNG;
	if (s == "immsng") return IMMSNG;
	if (s == "dfrsng") return DFRSNG;
	if (s == "mult") return MULT;

	return(0);
};

string TblWdbeMCommand::VecVRettype::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == STATSNG) return("statsng");
	if (ix == IMMSNG) return("immsng");
	if (ix == DFRSNG) return("dfrsng");
	if (ix == MULT) return("mult");

	return("");
};

string TblWdbeMCommand::VecVRettype::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == STATSNG) return("static single");
		if (ix == IMMSNG) return("immediate single");
		if (ix == DFRSNG) return("deferred single");
		if (ix == MULT) return("multiple");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMCommand::VecVRettype::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 5; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

