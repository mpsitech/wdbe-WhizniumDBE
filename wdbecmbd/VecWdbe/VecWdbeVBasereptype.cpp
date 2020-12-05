/**
	* \file VecWdbeVBasereptype.cpp
	* vector VecWdbeVBasereptype (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "VecWdbeVBasereptype.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWdbeVBasereptype
 ******************************************************************************/

uint VecWdbeVBasereptype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "prjgit") return PRJGIT;
	if (s == "custgit") return CUSTGIT;
	if (s == "uld") return ULD;

	return(0);
};

string VecWdbeVBasereptype::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == PRJGIT) return("prjgit");
	if (ix == CUSTGIT) return("custgit");
	if (ix == ULD) return("uld");

	return("");
};

string VecWdbeVBasereptype::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == VOID) return("empty");
		if (ix == PRJGIT) return("project Git");
		if (ix == CUSTGIT) return("custom Git");
		if (ix == ULD) return("upload");
		return(getSref(ix));
	};

	return("");
};

void VecWdbeVBasereptype::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};



