/**
	* \file RootWdbe_blks.cpp
	* job handler for job RootWdbe (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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

void RootWdbe::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class RootWdbe::DpchAppLogin
 ******************************************************************************/

RootWdbe::DpchAppLogin::DpchAppLogin() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPROOTWDBELOGIN)
		{
	m2mNotReg = false;
	chksuspsess = false;
};

string RootWdbe::DpchAppLogin::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(USERNAME)) ss.push_back("username");
	if (has(PASSWORD)) ss.push_back("password");
	if (has(M2MNOTREG)) ss.push_back("m2mNotReg");
	if (has(CHKSUSPSESS)) ss.push_back("chksuspsess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void RootWdbe::DpchAppLogin::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppRootWdbeLogin"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("username")) {username = me["username"].asString(); add(USERNAME);};
		if (me.isMember("password")) {password = me["password"].asString(); add(PASSWORD);};
		if (me.isMember("m2mNotReg")) {m2mNotReg = me["m2mNotReg"].asBool(); add(M2MNOTREG);};
		if (me.isMember("chksuspsess")) {chksuspsess = me["chksuspsess"].asBool(); add(CHKSUSPSESS);};
	} else {
	};
};

void RootWdbe::DpchAppLogin::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppRootWdbeLogin");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "username", "", username)) add(USERNAME);
		if (extractStringUclc(docctx, basexpath, "password", "", password)) add(PASSWORD);
		if (extractBoolUclc(docctx, basexpath, "m2mNotReg", "", m2mNotReg)) add(M2MNOTREG);
		if (extractBoolUclc(docctx, basexpath, "chksuspsess", "", chksuspsess)) add(CHKSUSPSESS);
	} else {
	};
};

/******************************************************************************
 class RootWdbe::DpchEngData
 ******************************************************************************/

RootWdbe::DpchEngData::DpchEngData(
			const ubigint jref
			, Feed* feedFEnsSps
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGROOTWDBEDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, FEEDFENSSPS};
	else this->mask = mask;

	if (find(this->mask, FEEDFENSSPS) && feedFEnsSps) this->feedFEnsSps = *feedFEnsSps;
};

string RootWdbe::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(FEEDFENSSPS)) ss.push_back("feedFEnsSps");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void RootWdbe::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(FEEDFENSSPS)) {feedFEnsSps = src->feedFEnsSps; add(FEEDFENSSPS);};
};

void RootWdbe::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngRootWdbeData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(FEEDFENSSPS)) feedFEnsSps.writeJSON(me);
};

void RootWdbe::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngRootWdbeData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(FEEDFENSSPS)) feedFEnsSps.writeXML(wr);
	xmlTextWriterEndElement(wr);
};
