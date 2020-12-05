/**
	* \file WdbeMPerson_vecs.cpp
	* database access for table TblWdbeMPerson (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWdbeMPerson::VecVSex
 ******************************************************************************/

uint TblWdbeMPerson::VecVSex::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "f") return F;
	if (s == "m") return M;

	return(0);
};

string TblWdbeMPerson::VecVSex::getSref(
			const uint ix
		) {
	if (ix == F) return("f");
	if (ix == M) return("m");

	return("");
};

string TblWdbeMPerson::VecVSex::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == F) return("female");
		if (ix == M) return("male");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMPerson::VecVSex::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class TblWdbeMPerson::VecWDerivate
 ******************************************************************************/

uint TblWdbeMPerson::VecWDerivate::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "usr") ix |= USR;
	};

	return(ix);
};

void TblWdbeMPerson::VecWDerivate::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*USR); i *= 2) if (ix & i) ics.insert(i);
};

string TblWdbeMPerson::VecWDerivate::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & USR) ss.push_back("usr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblWdbeMPerson::VecWDerivate::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == USR) return("user");
		return(getSrefs(ix));
	};

	return("");
};

void TblWdbeMPerson::VecWDerivate::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= USR; i *= 2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixWdbeVLocale));
};

