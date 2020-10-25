/**
	* \file VecWdbeVQrystate.cpp
	* vector VecWdbeVQrystate (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "VecWdbeVQrystate.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWdbeVQrystate
 ******************************************************************************/

uint VecWdbeVQrystate::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "mnr") return MNR;
	if (s == "ood") return OOD;
	if (s == "slm") return SLM;
	if (s == "utd") return UTD;

	return(0);
};

string VecWdbeVQrystate::getSref(
			const uint ix
		) {
	if (ix == MNR) return("mnr");
	if (ix == OOD) return("ood");
	if (ix == SLM) return("slm");
	if (ix == UTD) return("utd");

	return("");
};

string VecWdbeVQrystate::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == MNR) return("might need refresh");
		if (ix == OOD) return("out of date");
		if (ix == SLM) return("slightly modified");
		if (ix == UTD) return("up to date");
		return(getSref(ix));
	};

	return("");
};

void VecWdbeVQrystate::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

