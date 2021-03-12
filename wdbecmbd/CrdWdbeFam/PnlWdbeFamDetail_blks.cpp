/**
	* \file PnlWdbeFamDetail_blks.cpp
	* job handler for job PnlWdbeFamDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeFamDetail::VecVDo
 ******************************************************************************/

uint PnlWdbeFamDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butvndeditclick") return BUTVNDEDITCLICK;

	return(0);
};

string PnlWdbeFamDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTVNDEDITCLICK) return("ButVndEditClick");

	return("");
};

/******************************************************************************
 class PnlWdbeFamDetail::ContIac
 ******************************************************************************/

PnlWdbeFamDetail::ContIac::ContIac(
			const uint numFPupVnd
			, const string& TxfVnd
			, const string& TxfTit
			, const string& TxfCmt
		) :
			Block()
		{
	this->numFPupVnd = numFPupVnd;
	this->TxfVnd = TxfVnd;
	this->TxfTit = TxfTit;
	this->TxfCmt = TxfCmt;

	mask = {NUMFPUPVND, TXFVND, TXFTIT, TXFCMT};
};

bool PnlWdbeFamDetail::ContIac::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["ContIacWdbeFamDetail"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFPupVnd")) {numFPupVnd = me["numFPupVnd"].asUInt(); add(NUMFPUPVND);};
		if (me.isMember("TxfVnd")) {TxfVnd = me["TxfVnd"].asString(); add(TXFVND);};
		if (me.isMember("TxfTit")) {TxfTit = me["TxfTit"].asString(); add(TXFTIT);};
		if (me.isMember("TxfCmt")) {TxfCmt = me["TxfCmt"].asString(); add(TXFCMT);};
	};

	return basefound;
};

bool PnlWdbeFamDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeFamDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeFamDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupVnd", numFPupVnd)) add(NUMFPUPVND);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfVnd", TxfVnd)) add(TXFVND);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWdbeFamDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeFamDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFPupVnd"] = numFPupVnd;
	me["TxfVnd"] = TxfVnd;
	me["TxfTit"] = TxfTit;
	me["TxfCmt"] = TxfCmt;
};

void PnlWdbeFamDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeFamDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeFamDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupVnd", numFPupVnd);
		writeStringAttr(wr, itemtag, "sref", "TxfVnd", TxfVnd);
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeFamDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupVnd == comp->numFPupVnd) insert(items, NUMFPUPVND);
	if (TxfVnd == comp->TxfVnd) insert(items, TXFVND);
	if (TxfTit == comp->TxfTit) insert(items, TXFTIT);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWdbeFamDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPVND, TXFVND, TXFTIT, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeFamDetail::StatApp
 ******************************************************************************/

void PnlWdbeFamDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWdbeVExpstate
			, const bool PupVndAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeFamDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
	me["PupVndAlt"] = PupVndAlt;
};

void PnlWdbeFamDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
			, const bool PupVndAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeFamDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeFamDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "PupVndAlt", PupVndAlt);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeFamDetail::StatShr
 ******************************************************************************/

PnlWdbeFamDetail::StatShr::StatShr(
			const bool TxfVndValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool PupVndActive
			, const bool ButVndEditAvail
			, const bool TxfTitActive
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->TxfVndValid = TxfVndValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->PupVndActive = PupVndActive;
	this->ButVndEditAvail = ButVndEditAvail;
	this->TxfTitActive = TxfTitActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {TXFVNDVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, PUPVNDACTIVE, BUTVNDEDITAVAIL, TXFTITACTIVE, TXFCMTACTIVE};
};

void PnlWdbeFamDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeFamDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfVndValid"] = TxfVndValid;
	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["PupVndActive"] = PupVndActive;
	me["ButVndEditAvail"] = ButVndEditAvail;
	me["TxfTitActive"] = TxfTitActive;
	me["TxfCmtActive"] = TxfCmtActive;
};

void PnlWdbeFamDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeFamDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeFamDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfVndValid", TxfVndValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "PupVndActive", PupVndActive);
		writeBoolAttr(wr, itemtag, "sref", "ButVndEditAvail", ButVndEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfTitActive", TxfTitActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeFamDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfVndValid == comp->TxfVndValid) insert(items, TXFVNDVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (PupVndActive == comp->PupVndActive) insert(items, PUPVNDACTIVE);
	if (ButVndEditAvail == comp->ButVndEditAvail) insert(items, BUTVNDEDITAVAIL);
	if (TxfTitActive == comp->TxfTitActive) insert(items, TXFTITACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWdbeFamDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFVNDVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, PUPVNDACTIVE, BUTVNDEDITAVAIL, TXFTITACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeFamDetail::Tag
 ******************************************************************************/

void PnlWdbeFamDetail::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbeFamDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["CptVnd"] = "vendor";
		me["CptTit"] = "name";
		me["CptCmt"] = "comment";
	};
	me["Cpt"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale));
};

void PnlWdbeFamDetail::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeFamDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeFamDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptVnd", "vendor");
			writeStringAttr(wr, itemtag, "sref", "CptTit", "name");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeFamDetail::DpchAppData
 ******************************************************************************/

PnlWdbeFamDetail::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEFAMDETAILDATA)
		{
};

string PnlWdbeFamDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeFamDetail::DpchAppData::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWdbeFamDetailData"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWdbeFamDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeFamDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

/******************************************************************************
 class PnlWdbeFamDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeFamDetail::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEFAMDETAILDO)
		{
	ixVDo = 0;
};

string PnlWdbeFamDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeFamDetail::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWdbeFamDetailDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWdbeFamDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeFamDetailDo");
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
 class PnlWdbeFamDetail::DpchEngData
 ******************************************************************************/

PnlWdbeFamDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFPupVnd
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEFAMDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFPUPVND, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFPUPVND) && feedFPupVnd) this->feedFPupVnd = *feedFPupVnd;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeFamDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFPUPVND)) ss.push_back("feedFPupVnd");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeFamDetail::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFPUPVND)) {feedFPupVnd = src->feedFPupVnd; add(FEEDFPUPVND);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeFamDetail::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbeFamDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(FEEDFPUPVND)) feedFPupVnd.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void PnlWdbeFamDetail::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeFamDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFPUPVND)) feedFPupVnd.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
