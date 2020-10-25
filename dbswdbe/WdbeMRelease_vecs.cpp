/**
	* \file WdbeMRelease_vecs.cpp
	* database access for table TblWdbeMRelease (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWdbeMRelease::VecVBasetype
 ******************************************************************************/

uint TblWdbeMRelease::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dev") return DEV;
	if (s == "ezdev") return EZDEV;
	if (s == "fpga") return FPGA;
	if (s == "mcu") return MCU;

	return(0);
};

string TblWdbeMRelease::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == DEV) return("dev");
	if (ix == EZDEV) return("ezdev");
	if (ix == FPGA) return("fpga");
	if (ix == MCU) return("mcu");

	return("");
};

string TblWdbeMRelease::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == DEV) return("device access library");
		if (ix == EZDEV) return("easy model device access library");
		if (ix == FPGA) return("FPGA code");
		if (ix == MCU) return("MCU code");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMRelease::VecVBasetype::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

