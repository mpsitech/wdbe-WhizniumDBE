/**
	* \file WdbeMUnit_vecs.cpp
	* database access for table TblWdbeMUnit (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWdbeMUnit::VecVBasetype
 ******************************************************************************/

uint TblWdbeMUnit::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "fpga") return FPGA;
	if (s == "mcu") return MCU;
	if (s == "oth") return OTH;

	return(0);
};

string TblWdbeMUnit::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == FPGA) return("fpga");
	if (ix == MCU) return("mcu");
	if (ix == OTH) return("oth");

	return("");
};

string TblWdbeMUnit::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == FPGA) return("FPGA-based");
		if (ix == MCU) return("microcontroller-based");
		if (ix == OTH) return("other");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMUnit::VecVBasetype::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class TblWdbeMUnit::VecVRefTbl
 ******************************************************************************/

uint TblWdbeMUnit::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "fam") return FAM;
	if (s == "ver") return VER;

	return(0);
};

string TblWdbeMUnit::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == FAM) return("fam");
	if (ix == VER) return("ver");

	return("");
};

string TblWdbeMUnit::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == VOID) return("void");
		if (ix == FAM) return("product family");
		if (ix == VER) return("version");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMUnit::VecVRefTbl::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class TblWdbeMUnit::VecWSubset
 ******************************************************************************/

uint TblWdbeMUnit::VecWSubset::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sbswdbebmunitsil") ix |= SBSWDBEBMUNITSIL;
		else if (ss[i] == "sbswdbebmunituni") ix |= SBSWDBEBMUNITUNI;
	};

	return(ix);
};

void TblWdbeMUnit::VecWSubset::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SBSWDBEBMUNITUNI); i *= 2) if (ix & i) ics.insert(i);
};

string TblWdbeMUnit::VecWSubset::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SBSWDBEBMUNITSIL) ss.push_back("SbsWdbeBMUnitSil");
	if (ix & SBSWDBEBMUNITUNI) ss.push_back("SbsWdbeBMUnitUni");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblWdbeMUnit::VecWSubset::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == SBSWDBEBMUNITSIL) return("silicon device");
		if (ix == SBSWDBEBMUNITUNI) return("unit");
		return(getSrefs(ix));
	};

	return("");
};

