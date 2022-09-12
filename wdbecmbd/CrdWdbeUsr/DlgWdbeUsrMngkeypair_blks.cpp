/**
	* \file DlgWdbeUsrMngkeypair_blks.cpp
	* job handler for job DlgWdbeUsrMngkeypair (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWdbeUsrMngkeypair::VecVDo
 ******************************************************************************/

uint DlgWdbeUsrMngkeypair::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "detbutdelclick") return DETBUTDELCLICK;
	if (s == "detbutgenclick") return DETBUTGENCLICK;
	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWdbeUsrMngkeypair::VecVDo::getSref(
			const uint ix
		) {
	if (ix == DETBUTDELCLICK) return("DetButDelClick");
	if (ix == DETBUTGENCLICK) return("DetButGenClick");
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWdbeUsrMngkeypair::VecVSge
 ******************************************************************************/

uint DlgWdbeUsrMngkeypair::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "nf") return NF;
	if (s == "found") return FOUND;

	return(0);
};

string DlgWdbeUsrMngkeypair::VecVSge::getSref(
			const uint ix
		) {
	if (ix == NF) return("nf");
	if (ix == FOUND) return("found");

	return("");
};

void DlgWdbeUsrMngkeypair::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgWdbeUsrMngkeypair::ContInf
 ******************************************************************************/

DlgWdbeUsrMngkeypair::ContInf::ContInf(
			const uint numFSge
			, const string& DetTxtSte
			, const string& DetDld
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->DetTxtSte = DetTxtSte;
	this->DetDld = DetDld;

	mask = {NUMFSGE, DETTXTSTE, DETDLD};
};

void DlgWdbeUsrMngkeypair::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeUsrMngkeypair";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = numFSge;
	me["DetTxtSte"] = DetTxtSte;
	me["DetDld"] = DetDld;
};

void DlgWdbeUsrMngkeypair::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeUsrMngkeypair";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWdbeUsrMngkeypair";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "DetTxtSte", DetTxtSte);
		writeStringAttr(wr, itemtag, "sref", "DetDld", DetDld);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeUsrMngkeypair::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (DetTxtSte == comp->DetTxtSte) insert(items, DETTXTSTE);
	if (DetDld == comp->DetDld) insert(items, DETDLD);

	return(items);
};

set<uint> DlgWdbeUsrMngkeypair::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, DETTXTSTE, DETDLD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeUsrMngkeypair::StatApp
 ******************************************************************************/

void DlgWdbeUsrMngkeypair::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWdbeUsrMngkeypair";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["shortMenu"] = shortMenu;
};

void DlgWdbeUsrMngkeypair::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWdbeUsrMngkeypair";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWdbeUsrMngkeypair";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeUsrMngkeypair::StatShr
 ******************************************************************************/

DlgWdbeUsrMngkeypair::StatShr::StatShr(
			const bool DetButDelAvail
			, const bool DetButGenAvail
			, const bool DetDldActive
		) :
			Block()
		{
	this->DetButDelAvail = DetButDelAvail;
	this->DetButGenAvail = DetButGenAvail;
	this->DetDldActive = DetDldActive;

	mask = {DETBUTDELAVAIL, DETBUTGENAVAIL, DETDLDACTIVE};
};

void DlgWdbeUsrMngkeypair::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeUsrMngkeypair";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["DetButDelAvail"] = DetButDelAvail;
	me["DetButGenAvail"] = DetButGenAvail;
	me["DetDldActive"] = DetDldActive;
};

void DlgWdbeUsrMngkeypair::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeUsrMngkeypair";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeUsrMngkeypair";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "DetButDelAvail", DetButDelAvail);
		writeBoolAttr(wr, itemtag, "sref", "DetButGenAvail", DetButGenAvail);
		writeBoolAttr(wr, itemtag, "sref", "DetDldActive", DetDldActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeUsrMngkeypair::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (DetButDelAvail == comp->DetButDelAvail) insert(items, DETBUTDELAVAIL);
	if (DetButGenAvail == comp->DetButGenAvail) insert(items, DETBUTGENAVAIL);
	if (DetDldActive == comp->DetDldActive) insert(items, DETDLDACTIVE);

	return(items);
};

set<uint> DlgWdbeUsrMngkeypair::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DETBUTDELAVAIL, DETBUTGENAVAIL, DETDLDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeUsrMngkeypair::Tag
 ******************************************************************************/

void DlgWdbeUsrMngkeypair::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeUsrMngkeypair";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["Cpt"] = "Manage SSH key pair";
		me["DetCptSte"] = "State";
		me["DetButDel"] = "Delete";
		me["DetButGen"] = "Generate";
		me["DetDld"] = "Download public key";
	};
	me["ButDne"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DONE, ixWdbeVLocale));
};

void DlgWdbeUsrMngkeypair::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeUsrMngkeypair";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeUsrMngkeypair";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Manage SSH key pair");
			writeStringAttr(wr, itemtag, "sref", "DetCptSte", "State");
			writeStringAttr(wr, itemtag, "sref", "DetButDel", "Delete");
			writeStringAttr(wr, itemtag, "sref", "DetButGen", "Generate");
			writeStringAttr(wr, itemtag, "sref", "DetDld", "Download public key");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DONE, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeUsrMngkeypair::DpchAppDo
 ******************************************************************************/

DlgWdbeUsrMngkeypair::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBEUSRMNGKEYPAIRDO)
		{
	ixVDo = 0;
};

string DlgWdbeUsrMngkeypair::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeUsrMngkeypair::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppDlgWdbeUsrMngkeypairDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void DlgWdbeUsrMngkeypair::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWdbeUsrMngkeypairDo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDo", "", srefIxVDo)) {
			ixVDo = VecVDo::getIx(srefIxVDo);
			add(IXVDO);
		};
	} else {
	};
};

/******************************************************************************
 class DlgWdbeUsrMngkeypair::DpchEngData
 ******************************************************************************/

DlgWdbeUsrMngkeypair::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGDLGWDBEUSRMNGKEYPAIRDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string DlgWdbeUsrMngkeypair::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeUsrMngkeypair::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void DlgWdbeUsrMngkeypair::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngDlgWdbeUsrMngkeypairData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void DlgWdbeUsrMngkeypair::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWdbeUsrMngkeypairData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
