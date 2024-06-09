/**
	* \file DlgWdbeCvrNew_blks.cpp
	* job handler for job DlgWdbeCvrNew (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWdbeCvrNew::VecVDo
 ******************************************************************************/

uint DlgWdbeCvrNew::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butcncclick") return BUTCNCCLICK;
	if (s == "butcreclick") return BUTCRECLICK;

	return(0);
};

string DlgWdbeCvrNew::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTCNCCLICK) return("ButCncClick");
	if (ix == BUTCRECLICK) return("ButCreClick");

	return("");
};

/******************************************************************************
 class DlgWdbeCvrNew::VecVSge
 ******************************************************************************/

uint DlgWdbeCvrNew::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "create") return CREATE;
	if (s == "done") return DONE;

	return(0);
};

string DlgWdbeCvrNew::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == CREATE) return("create");
	if (ix == DONE) return("done");

	return("");
};

void DlgWdbeCvrNew::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgWdbeCvrNew::VecVVni
 ******************************************************************************/

uint DlgWdbeCvrNew::VecVVni::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "maj") return MAJ;
	if (s == "min") return MIN;
	if (s == "sub") return SUB;

	return(0);
};

string DlgWdbeCvrNew::VecVVni::getSref(
			const uint ix
		) {
	if (ix == MAJ) return("maj");
	if (ix == MIN) return("min");
	if (ix == SUB) return("sub");

	return("");
};

string DlgWdbeCvrNew::VecVVni::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == MAJ) return("major");
		if (ix == MIN) return("minor");
		if (ix == SUB) return("sub");
		return(getSref(ix));
	};

	return("");
};

void DlgWdbeCvrNew::VecVVni::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class DlgWdbeCvrNew::ContIac
 ******************************************************************************/

DlgWdbeCvrNew::ContIac::ContIac(
			const uint numFDetPupCpr
			, const uint numFDetPupBcv
			, const uint numFDetRbuVni
		) :
			Block()
		{
	this->numFDetPupCpr = numFDetPupCpr;
	this->numFDetPupBcv = numFDetPupBcv;
	this->numFDetRbuVni = numFDetRbuVni;

	mask = {NUMFDETPUPCPR, NUMFDETPUPBCV, NUMFDETRBUVNI};
};

bool DlgWdbeCvrNew::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacDlgWdbeCvrNew"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFDetPupCpr")) {numFDetPupCpr = me["numFDetPupCpr"].asUInt(); add(NUMFDETPUPCPR);};
		if (me.isMember("numFDetPupBcv")) {numFDetPupBcv = me["numFDetPupBcv"].asUInt(); add(NUMFDETPUPBCV);};
		if (me.isMember("numFDetRbuVni")) {numFDetRbuVni = me["numFDetRbuVni"].asUInt(); add(NUMFDETRBUVNI);};
	};

	return basefound;
};

bool DlgWdbeCvrNew::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWdbeCvrNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWdbeCvrNew";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetPupCpr", numFDetPupCpr)) add(NUMFDETPUPCPR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetPupBcv", numFDetPupBcv)) add(NUMFDETPUPBCV);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetRbuVni", numFDetRbuVni)) add(NUMFDETRBUVNI);
	};

	return basefound;
};

void DlgWdbeCvrNew::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWdbeCvrNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFDetPupCpr"] = (Json::Value::UInt) numFDetPupCpr;
	me["numFDetPupBcv"] = (Json::Value::UInt) numFDetPupBcv;
	me["numFDetRbuVni"] = (Json::Value::UInt) numFDetRbuVni;
};

void DlgWdbeCvrNew::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWdbeCvrNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWdbeCvrNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDetPupCpr", numFDetPupCpr);
		writeUintAttr(wr, itemtag, "sref", "numFDetPupBcv", numFDetPupBcv);
		writeUintAttr(wr, itemtag, "sref", "numFDetRbuVni", numFDetRbuVni);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeCvrNew::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDetPupCpr == comp->numFDetPupCpr) insert(items, NUMFDETPUPCPR);
	if (numFDetPupBcv == comp->numFDetPupBcv) insert(items, NUMFDETPUPBCV);
	if (numFDetRbuVni == comp->numFDetRbuVni) insert(items, NUMFDETRBUVNI);

	return(items);
};

set<uint> DlgWdbeCvrNew::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFDETPUPCPR, NUMFDETPUPBCV, NUMFDETRBUVNI};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeCvrNew::ContInf
 ******************************************************************************/

DlgWdbeCvrNew::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

void DlgWdbeCvrNew::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeCvrNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = (Json::Value::UInt) numFSge;
};

void DlgWdbeCvrNew::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeCvrNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWdbeCvrNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeCvrNew::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWdbeCvrNew::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeCvrNew::StatApp
 ******************************************************************************/

void DlgWdbeCvrNew::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWdbeCvrNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["shortMenu"] = shortMenu;
};

void DlgWdbeCvrNew::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWdbeCvrNew";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWdbeCvrNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeCvrNew::StatShr
 ******************************************************************************/

DlgWdbeCvrNew::StatShr::StatShr(
			const bool ButCncActive
			, const bool ButCreActive
		) :
			Block()
		{
	this->ButCncActive = ButCncActive;
	this->ButCreActive = ButCreActive;

	mask = {BUTCNCACTIVE, BUTCREACTIVE};
};

void DlgWdbeCvrNew::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeCvrNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButCncActive"] = ButCncActive;
	me["ButCreActive"] = ButCreActive;
};

void DlgWdbeCvrNew::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeCvrNew";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeCvrNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButCncActive", ButCncActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCreActive", ButCreActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeCvrNew::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButCncActive == comp->ButCncActive) insert(items, BUTCNCACTIVE);
	if (ButCreActive == comp->ButCreActive) insert(items, BUTCREACTIVE);

	return(items);
};

set<uint> DlgWdbeCvrNew::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTCNCACTIVE, BUTCREACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeCvrNew::Tag
 ******************************************************************************/

void DlgWdbeCvrNew::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeCvrNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["Cpt"] = "Create new core version";
		me["DetCptCpr"] = "Core project";
		me["DetCptBcv"] = "Base core version";
		me["DetCptVni"] = "Version number increment";
	};
	me["ButCnc"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::CANCEL, ixWdbeVLocale));
	me["ButCre"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::CREATE, ixWdbeVLocale));
};

void DlgWdbeCvrNew::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeCvrNew";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeCvrNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Create new core version");
			writeStringAttr(wr, itemtag, "sref", "DetCptCpr", "Core project");
			writeStringAttr(wr, itemtag, "sref", "DetCptBcv", "Base core version");
			writeStringAttr(wr, itemtag, "sref", "DetCptVni", "Version number increment");
		};
		writeStringAttr(wr, itemtag, "sref", "ButCnc", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::CANCEL, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButCre", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::CREATE, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeCvrNew::DpchAppData
 ******************************************************************************/

DlgWdbeCvrNew::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBECVRNEWDATA)
		{
};

string DlgWdbeCvrNew::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeCvrNew::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppDlgWdbeCvrNewData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void DlgWdbeCvrNew::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWdbeCvrNewData");
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
 class DlgWdbeCvrNew::DpchAppDo
 ******************************************************************************/

DlgWdbeCvrNew::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBECVRNEWDO)
		{
	ixVDo = 0;
};

string DlgWdbeCvrNew::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeCvrNew::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppDlgWdbeCvrNewDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void DlgWdbeCvrNew::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWdbeCvrNewDo");
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
 class DlgWdbeCvrNew::DpchEngData
 ******************************************************************************/

DlgWdbeCvrNew::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFDetPupBcv
			, Feed* feedFDetPupCpr
			, Feed* feedFDetRbuVni
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGDLGWDBECVRNEWDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFDETPUPBCV, FEEDFDETPUPCPR, FEEDFDETRBUVNI, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFDETPUPBCV) && feedFDetPupBcv) this->feedFDetPupBcv = *feedFDetPupBcv;
	if (find(this->mask, FEEDFDETPUPCPR) && feedFDetPupCpr) this->feedFDetPupCpr = *feedFDetPupCpr;
	if (find(this->mask, FEEDFDETRBUVNI) && feedFDetRbuVni) this->feedFDetRbuVni = *feedFDetRbuVni;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string DlgWdbeCvrNew::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFDETPUPBCV)) ss.push_back("feedFDetPupBcv");
	if (has(FEEDFDETPUPCPR)) ss.push_back("feedFDetPupCpr");
	if (has(FEEDFDETRBUVNI)) ss.push_back("feedFDetRbuVni");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeCvrNew::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFDETPUPBCV)) {feedFDetPupBcv = src->feedFDetPupBcv; add(FEEDFDETPUPBCV);};
	if (src->has(FEEDFDETPUPCPR)) {feedFDetPupCpr = src->feedFDetPupCpr; add(FEEDFDETPUPCPR);};
	if (src->has(FEEDFDETRBUVNI)) {feedFDetRbuVni = src->feedFDetRbuVni; add(FEEDFDETRBUVNI);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void DlgWdbeCvrNew::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngDlgWdbeCvrNewData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFDETPUPBCV)) feedFDetPupBcv.writeJSON(me);
	if (has(FEEDFDETPUPCPR)) feedFDetPupCpr.writeJSON(me);
	if (has(FEEDFDETRBUVNI)) feedFDetRbuVni.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void DlgWdbeCvrNew::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWdbeCvrNewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFDETPUPBCV)) feedFDetPupBcv.writeXML(wr);
		if (has(FEEDFDETPUPCPR)) feedFDetPupCpr.writeXML(wr);
		if (has(FEEDFDETRBUVNI)) feedFDetRbuVni.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
