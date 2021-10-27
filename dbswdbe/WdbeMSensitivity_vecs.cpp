/**
	* \file WdbeMSensitivity_vecs.cpp
	* database access for table TblWdbeMSensitivity (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWdbeMSensitivity::VecVRefTbl
 ******************************************************************************/

uint TblWdbeMSensitivity::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "mdl") return MDL;
	if (s == "prc") return PRC;

	return(0);
};

string TblWdbeMSensitivity::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == MDL) return("mdl");
	if (ix == PRC) return("prc");

	return("");
};

string TblWdbeMSensitivity::VecVRefTbl::getTitle(
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

void TblWdbeMSensitivity::VecVRefTbl::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class TblWdbeMSensitivity::VecVSrcTbl
 ******************************************************************************/

uint TblWdbeMSensitivity::VecVSrcTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "int") return INT;
	if (s == "prt") return PRT;
	if (s == "sig") return SIG;

	return(0);
};

string TblWdbeMSensitivity::VecVSrcTbl::getSref(
			const uint ix
		) {
	if (ix == INT) return("int");
	if (ix == PRT) return("prt");
	if (ix == SIG) return("sig");

	return("");
};

string TblWdbeMSensitivity::VecVSrcTbl::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == INT) return("interrupt");
		if (ix == PRT) return("port");
		if (ix == SIG) return("signal");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMSensitivity::VecVSrcTbl::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};
