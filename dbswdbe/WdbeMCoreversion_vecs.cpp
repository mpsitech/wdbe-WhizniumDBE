/**
	* \file WdbeMCoreversion_vecs.cpp
	* database access for table TblWdbeMCoreversion (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWdbeMCoreversion::VecVState
 ******************************************************************************/

uint TblWdbeMCoreversion::VecVState::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dev") return DEV;
	if (s == "prod") return PROD;
	if (s == "abandon") return ABANDON;

	return(0);
};

string TblWdbeMCoreversion::VecVState::getSref(
			const uint ix
		) {
	if (ix == DEV) return("dev");
	if (ix == PROD) return("prod");
	if (ix == ABANDON) return("abandon");

	return("");
};

string TblWdbeMCoreversion::VecVState::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == DEV) return("development");
		if (ix == PROD) return("production");
		if (ix == ABANDON) return("abandonned");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMCoreversion::VecVState::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class TblWdbeMCoreversion::VecWSpectype
 ******************************************************************************/

uint TblWdbeMCoreversion::VecWSpectype::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "mbsctd") ix |= MBSCTD;
		else if (ss[i] == "mbscbu") ix |= MBSCBU;
		else if (ss[i] == "mdet") ix |= MDET;
		else if (ss[i] == "tplfil") ix |= TPLFIL;
		else if (ss[i] == "plh") ix |= PLH;
		else if (ss[i] == "ip") ix |= IP;
	};

	return(ix);
};

void TblWdbeMCoreversion::VecWSpectype::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IP); i *= 2) if (ix & i) ics.insert(i);
};

string TblWdbeMCoreversion::VecWSpectype::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & MBSCTD) ss.push_back("mbsctd");
	if (ix & MBSCBU) ss.push_back("mbscbu");
	if (ix & MDET) ss.push_back("mdet");
	if (ix & TPLFIL) ss.push_back("tplfil");
	if (ix & PLH) ss.push_back("plh");
	if (ix & IP) ss.push_back("ip");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblWdbeMCoreversion::VecWSpectype::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == MBSCTD) return("mod. of basic descr. on top-down");
		if (ix == MBSCBU) return("mod. of basic descr. on bottom-up");
		if (ix == MDET) return("mod. of detailed descr.");
		if (ix == TPLFIL) return("template file");
		if (ix == PLH) return("placeholders");
		if (ix == IP) return("insertion points");
		return(getSrefs(ix));
	};

	return("");
};

void TblWdbeMCoreversion::VecWSpectype::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= IP; i *= 2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixWdbeVLocale));
};

