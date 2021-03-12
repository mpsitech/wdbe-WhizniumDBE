/**
	* \file PnlWdbeNavPre_blks.cpp
	* job handler for job PnlWdbeNavPre (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeNavPre::VecVDo
 ******************************************************************************/

uint PnlWdbeNavPre::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butcvrremoveclick") return BUTCVRREMOVECLICK;
	if (s == "butuntremoveclick") return BUTUNTREMOVECLICK;
	if (s == "butverremoveclick") return BUTVERREMOVECLICK;

	return(0);
};

string PnlWdbeNavPre::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTCVRREMOVECLICK) return("ButCvrRemoveClick");
	if (ix == BUTUNTREMOVECLICK) return("ButUntRemoveClick");
	if (ix == BUTVERREMOVECLICK) return("ButVerRemoveClick");

	return("");
};

/******************************************************************************
 class PnlWdbeNavPre::ContInf
 ******************************************************************************/

PnlWdbeNavPre::ContInf::ContInf(
			const string& TxtCvr
			, const string& TxtUnt
			, const string& TxtVer
		) :
			Block()
		{
	this->TxtCvr = TxtCvr;
	this->TxtUnt = TxtUnt;
	this->TxtVer = TxtVer;

	mask = {TXTCVR, TXTUNT, TXTVER};
};

void PnlWdbeNavPre::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeNavPre";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtCvr"] = TxtCvr;
	me["TxtUnt"] = TxtUnt;
	me["TxtVer"] = TxtVer;
};

void PnlWdbeNavPre::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeNavPre";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbeNavPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtCvr", TxtCvr);
		writeStringAttr(wr, itemtag, "sref", "TxtUnt", TxtUnt);
		writeStringAttr(wr, itemtag, "sref", "TxtVer", TxtVer);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavPre::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtCvr == comp->TxtCvr) insert(items, TXTCVR);
	if (TxtUnt == comp->TxtUnt) insert(items, TXTUNT);
	if (TxtVer == comp->TxtVer) insert(items, TXTVER);

	return(items);
};

set<uint> PnlWdbeNavPre::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTCVR, TXTUNT, TXTVER};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavPre::StatShr
 ******************************************************************************/

PnlWdbeNavPre::StatShr::StatShr(
			const bool TxtCvrAvail
			, const bool TxtUntAvail
			, const bool TxtVerAvail
		) :
			Block()
		{
	this->TxtCvrAvail = TxtCvrAvail;
	this->TxtUntAvail = TxtUntAvail;
	this->TxtVerAvail = TxtVerAvail;

	mask = {TXTCVRAVAIL, TXTUNTAVAIL, TXTVERAVAIL};
};

void PnlWdbeNavPre::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeNavPre";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtCvrAvail"] = TxtCvrAvail;
	me["TxtUntAvail"] = TxtUntAvail;
	me["TxtVerAvail"] = TxtVerAvail;
};

void PnlWdbeNavPre::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeNavPre";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeNavPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxtCvrAvail", TxtCvrAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtUntAvail", TxtUntAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtVerAvail", TxtVerAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavPre::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxtCvrAvail == comp->TxtCvrAvail) insert(items, TXTCVRAVAIL);
	if (TxtUntAvail == comp->TxtUntAvail) insert(items, TXTUNTAVAIL);
	if (TxtVerAvail == comp->TxtVerAvail) insert(items, TXTVERAVAIL);

	return(items);
};

set<uint> PnlWdbeNavPre::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTCVRAVAIL, TXTUNTAVAIL, TXTVERAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavPre::Tag
 ******************************************************************************/

void PnlWdbeNavPre::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbeNavPre";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["CptCvr"] = "core version";
		me["CptUnt"] = "unit";
		me["CptVer"] = "version";
	};
};

void PnlWdbeNavPre::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeNavPre";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeNavPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptCvr", "core version");
			writeStringAttr(wr, itemtag, "sref", "CptUnt", "unit");
			writeStringAttr(wr, itemtag, "sref", "CptVer", "version");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavPre::DpchAppDo
 ******************************************************************************/

PnlWdbeNavPre::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVPREDO)
		{
	ixVDo = 0;
};

string PnlWdbeNavPre::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavPre::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWdbeNavPreDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWdbeNavPre::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeNavPreDo");
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
 class PnlWdbeNavPre::DpchEngData
 ******************************************************************************/

PnlWdbeNavPre::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBENAVPREDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeNavPre::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavPre::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeNavPre::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbeNavPreData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void PnlWdbeNavPre::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeNavPreData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
