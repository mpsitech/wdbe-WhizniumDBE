/**
	* \file RootWdbe.cpp
	* API code for job RootWdbe (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "RootWdbe.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class RootWdbe::VecVSge
 ******************************************************************************/

uint RootWdbe::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "sync") return SYNC;

	return(0);
};

string RootWdbe::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == SYNC) return("sync");

	return("");
};

/******************************************************************************
 class RootWdbe::DpchAppLogin
 ******************************************************************************/

RootWdbe::DpchAppLogin::DpchAppLogin(
			const string& scrJref
			, const string& username
			, const string& password
			, const bool m2mNotReg
			, const bool chksuspsess
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPROOTWDBELOGIN, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, USERNAME, PASSWORD, M2MNOTREG, CHKSUSPSESS};
	else this->mask = mask;

	this->username = username;
	this->password = password;
	this->m2mNotReg = m2mNotReg;
	this->chksuspsess = chksuspsess;
};

string RootWdbe::DpchAppLogin::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(USERNAME)) ss.push_back("username");
	if (has(PASSWORD)) ss.push_back("password");
	if (has(M2MNOTREG)) ss.push_back("m2mNotReg");
	if (has(CHKSUSPSESS)) ss.push_back("chksuspsess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void RootWdbe::DpchAppLogin::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppRootWdbeLogin");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(USERNAME)) writeString(wr, "username", username);
		if (has(PASSWORD)) writeString(wr, "password", password);
		if (has(M2MNOTREG)) writeBool(wr, "m2mNotReg", m2mNotReg);
		if (has(CHKSUSPSESS)) writeBool(wr, "chksuspsess", chksuspsess);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class RootWdbe::DpchEngData
 ******************************************************************************/

RootWdbe::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGROOTWDBEDATA)
		{
	feedFEnsSps.tag = "FeedFEnsSps";
};

string RootWdbe::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(FEEDFENSSPS)) ss.push_back("feedFEnsSps");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void RootWdbe::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngRootWdbeData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (feedFEnsSps.readXML(docctx, basexpath, true)) add(FEEDFENSSPS);
	} else {
		feedFEnsSps.clear();
	};
};

