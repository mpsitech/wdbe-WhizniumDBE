/**
	* \file VecWdbeVIop.cpp
	* vector VecWdbeVIop (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "VecWdbeVIop.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWdbeVIop
 ******************************************************************************/

uint VecWdbeVIop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ins") return INS;
	if (s == "retr") return RETR;
	if (s == "retrins") return RETRINS;
	if (s == "retrupd") return RETRUPD;
	if (s == "retrupdins") return RETRUPDINS;
	if (s == "rmv") return RMV;

	return(0);
};

string VecWdbeVIop::getSref(
			const uint ix
		) {
	if (ix == INS) return("ins");
	if (ix == RETR) return("retr");
	if (ix == RETRINS) return("retrins");
	if (ix == RETRUPD) return("retrupd");
	if (ix == RETRUPDINS) return("retrupdins");
	if (ix == RMV) return("rmv");

	return("");
};

string VecWdbeVIop::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == INS) return("insert");
		if (ix == RETR) return("retrieve");
		if (ix == RETRINS) return("retrieve, else insert");
		if (ix == RETRUPD) return("retrieve and update");
		if (ix == RETRUPDINS) return("retrieve and update, else insert");
		if (ix == RMV) return("remove");
		return(getSref(ix));
	};

	return("");
};

void VecWdbeVIop::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 6; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};



