/**
	* \file VecWdbeVOpengtype.cpp
	* vector VecWdbeVOpengtype (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "VecWdbeVOpengtype.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWdbeVOpengtype
 ******************************************************************************/

uint VecWdbeVOpengtype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "wdbeopd1") return WDBEOPD1;
	if (s == "wdbeopd2") return WDBEOPD2;

	return(0);
};

string VecWdbeVOpengtype::getSref(
			const uint ix
		) {
	if (ix == WDBEOPD1) return("wdbeopd1");
	if (ix == WDBEOPD2) return("wdbeopd2");

	return("");
};

string VecWdbeVOpengtype::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == WDBEOPD1) return("wdbeopd1 with WdbeCplmst/WdbeGen/WdbeGenfst/WdbePlhfpga/WdbePlhmcu/WdbePrcfile/WdbePrctree/WdbeWrdev/WdbeWrfpga/WdbeWrmcu/WdbeWrterm");
		if (ix == WDBEOPD2) return("wdbeopd2 with WdbeMtpCplmstbu/WdbeMtpCplmsttd/WdbeMtpGenfst/WdbeMtpPlhfpga/WdbeMtpPlhmcu/WdbeMtpWrfpga/WdbeMtpWrmcu");
		return(getSref(ix));
	};

	return("");
};

void VecWdbeVOpengtype::appendToFeed(
			const uint ix
			, const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix, ixWdbeVLocale));
};

void VecWdbeVOpengtype::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};
