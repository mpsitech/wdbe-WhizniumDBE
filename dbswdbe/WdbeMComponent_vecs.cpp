/**
	* \file WdbeMComponent_vecs.cpp
	* database access for table TblWdbeMComponent (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWdbeMComponent::VecVBasetype
 ******************************************************************************/

uint TblWdbeMComponent::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dev") return DEV;
	if (s == "ezdev") return EZDEV;
	if (s == "fpga") return FPGA;
	if (s == "mcu") return MCU;
	if (s == "term") return TERM;

	return(0);
};

string TblWdbeMComponent::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == DEV) return("dev");
	if (ix == EZDEV) return("ezdev");
	if (ix == FPGA) return("fpga");
	if (ix == MCU) return("mcu");
	if (ix == TERM) return("term");

	return("");
};

string TblWdbeMComponent::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == DEV) return("device access library");
		if (ix == EZDEV) return("easy model device access library");
		if (ix == FPGA) return("FPGA code");
		if (ix == MCU) return("MCU code");
		if (ix == TERM) return("interactive terminal");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMComponent::VecVBasetype::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 5; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};
