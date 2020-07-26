/**
	* \file VecWdbeVOpengtype.cpp
	* vector VecWdbeVOpengtype (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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
		if (ix == WDBEOPD1) return("wdbeopd1 with WdbeModbsc/WdbeModdet/WdbePlhfpga/WdbePlhmcu/WdbePrcfile/WdbePrctree/WdbeWrdev/WdbeWrfpga/WdbeWrmcu");
		if (ix == WDBEOPD2) return("wdbeopd2 with WdbeMtpModbscbu/WdbeMtpModbsctd/WdbeMtpModdet/WdbeMtpPlhfpga/WdbeMtpPlhmcu/WdbeMtpWrfpga/WdbeMtpWrmcu");
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

