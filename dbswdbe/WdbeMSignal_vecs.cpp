/**
	* \file WdbeMSignal_vecs.cpp
	* database access for table TblWdbeMSignal (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWdbeMSignal::VecVBasetype
 ******************************************************************************/

uint TblWdbeMSignal::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "clk") return CLK;
	if (s == "hshk") return HSHK;
	if (s == "oprt") return OPRT;
	if (s == "ioprt") return IOPRT;
	if (s == "strb") return STRB;
	if (s == "oth") return OTH;

	return(0);
};

string TblWdbeMSignal::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == CLK) return("clk");
	if (ix == HSHK) return("hshk");
	if (ix == OPRT) return("oprt");
	if (ix == IOPRT) return("ioprt");
	if (ix == STRB) return("strb");
	if (ix == OTH) return("oth");

	return("");
};

string TblWdbeMSignal::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == CLK) return("clock");
		if (ix == HSHK) return("handshake");
		if (ix == OPRT) return("output port driver");
		if (ix == IOPRT) return("input/output port driver");
		if (ix == STRB) return("strobe");
		if (ix == OTH) return("other");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMSignal::VecVBasetype::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 6; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class TblWdbeMSignal::VecVMgeTbl
 ******************************************************************************/

uint TblWdbeMSignal::VecVMgeTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "mdl") return MDL;
	if (s == "prc") return PRC;

	return(0);
};

string TblWdbeMSignal::VecVMgeTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == MDL) return("mdl");
	if (ix == PRC) return("prc");

	return("");
};

string TblWdbeMSignal::VecVMgeTbl::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == MDL) return("sub-module");
		if (ix == PRC) return("process");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMSignal::VecVMgeTbl::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class TblWdbeMSignal::VecVRefTbl
 ******************************************************************************/

uint TblWdbeMSignal::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "mdl") return MDL;
	if (s == "unt") return UNT;

	return(0);
};

string TblWdbeMSignal::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == MDL) return("mdl");
	if (ix == UNT) return("unt");

	return("");
};

string TblWdbeMSignal::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == MDL) return("module");
		if (ix == UNT) return("unit");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMSignal::VecVRefTbl::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};
