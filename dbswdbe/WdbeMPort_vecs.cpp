/**
	* \file WdbeMPort_vecs.cpp
	* database access for table TblWdbeMPort (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWdbeMPort::VecVDir
 ******************************************************************************/

uint TblWdbeMPort::VecVDir::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "in") return IN;
	if (s == "inout") return INOUT;
	if (s == "out") return OUT;

	return(0);
};

string TblWdbeMPort::VecVDir::getSref(
			const uint ix
		) {
	if (ix == IN) return("in");
	if (ix == INOUT) return("inout");
	if (ix == OUT) return("out");

	return("");
};

string TblWdbeMPort::VecVDir::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == IN) return("input");
		if (ix == INOUT) return("input/output");
		if (ix == OUT) return("output");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMPort::VecVDir::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class TblWdbeMPort::VecVMdlCat
 ******************************************************************************/

uint TblWdbeMPort::VecVMdlCat::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "reset") return RESET;
	if (s == "clk") return CLK;
	if (s == "rtewrp") return RTEWRP;
	if (s == "rtetop") return RTETOP;
	if (s == "cmdbus") return CMDBUS;
	if (s == "imb") return IMB;
	if (s == "rtesup") return RTESUP;
	if (s == "rtepin") return RTEPIN;
	if (s == "dbg") return DBG;

	return(0);
};

string TblWdbeMPort::VecVMdlCat::getSref(
			const uint ix
		) {
	if (ix == RESET) return("reset");
	if (ix == CLK) return("clk");
	if (ix == RTEWRP) return("rtewrp");
	if (ix == RTETOP) return("rtetop");
	if (ix == CMDBUS) return("cmdbus");
	if (ix == IMB) return("imb");
	if (ix == RTESUP) return("rtesup");
	if (ix == RTEPIN) return("rtepin");
	if (ix == DBG) return("dbg");

	return("");
};

string TblWdbeMPort::VecVMdlCat::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == RESET) return("global reset");
		if (ix == CLK) return("clock");
		if (ix == RTEWRP) return("route to wrapper signal");
		if (ix == RTETOP) return("route to top module signal");
		if (ix == CMDBUS) return("command bus");
		if (ix == IMB) return("inter-module buffer");
		if (ix == RTESUP) return("route to super module");
		if (ix == RTEPIN) return("route to pin");
		if (ix == DBG) return("debug");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMPort::VecVMdlCat::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 9; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};
