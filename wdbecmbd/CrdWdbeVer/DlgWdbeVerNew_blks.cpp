/**
	* \file DlgWdbeVerNew_blks.cpp
	* job handler for job DlgWdbeVerNew (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWdbeVerNew::VecVDo
 ******************************************************************************/

uint DlgWdbeVerNew::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butcncclick") return BUTCNCCLICK;
	if (s == "butcreclick") return BUTCRECLICK;

	return(0);
};

string DlgWdbeVerNew::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTCNCCLICK) return("ButCncClick");
	if (ix == BUTCRECLICK) return("ButCreClick");

	return("");
};

/******************************************************************************
 class DlgWdbeVerNew::VecVSge
 ******************************************************************************/

uint DlgWdbeVerNew::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "create") return CREATE;
	if (s == "done") return DONE;

	return(0);
};

string DlgWdbeVerNew::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == CREATE) return("create");
	if (ix == DONE) return("done");

	return("");
};

void DlgWdbeVerNew::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgWdbeVerNew::VecVVni
 ******************************************************************************/

uint DlgWdbeVerNew::VecVVni::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "maj") return MAJ;
	if (s == "min") return MIN;
	if (s == "sub") return SUB;
	if (s == "void") return VOID;

	return(0);
};

string DlgWdbeVerNew::VecVVni::getSref(
			const uint ix
		) {
	if (ix == MAJ) return("maj");
	if (ix == MIN) return("min");
	if (ix == SUB) return("sub");
	if (ix == VOID) return("void");

	return("");
};

string DlgWdbeVerNew::VecVVni::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == MAJ) return("major");
		if (ix == MIN) return("minor");
		if (ix == SUB) return("sub");
		if (ix == VOID) return("none");
		return(getSref(ix));
	};

	return("");
};

void DlgWdbeVerNew::VecVVni::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class DlgWdbeVerNew::ContIac
 ******************************************************************************/

DlgWdbeVerNew::ContIac::ContIac(
			const uint numFDetPupPrj
			, const uint numFDetPupBvr
			, const uint numFDetRbuVni
			, const string& DetTxfCmt
		) :
			Block()
			, numFDetPupPrj(numFDetPupPrj)
			, numFDetPupBvr(numFDetPupBvr)
			, numFDetRbuVni(numFDetRbuVni)
			, DetTxfCmt(DetTxfCmt)
		{
	mask = {NUMFDETPUPPRJ, NUMFDETPUPBVR, NUMFDETRBUVNI, DETTXFCMT};
};

bool DlgWdbeVerNew::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacDlgWdbeVerNew"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFDetPupPrj")) {numFDetPupPrj = me["numFDetPupPrj"].asUInt(); add(NUMFDETPUPPRJ);};
		if (me.isMember("numFDetPupBvr")) {numFDetPupBvr = me["numFDetPupBvr"].asUInt(); add(NUMFDETPUPBVR);};
		if (me.isMember("numFDetRbuVni")) {numFDetRbuVni = me["numFDetRbuVni"].asUInt(); add(NUMFDETRBUVNI);};
		if (me.isMember("DetTxfCmt")) {DetTxfCmt = me["DetTxfCmt"].asString(); add(DETTXFCMT);};
	};

	return basefound;
};

bool DlgWdbeVerNew::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWdbeVerNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWdbeVerNew";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetPupPrj", numFDetPupPrj)) add(NUMFDETPUPPRJ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetPupBvr", numFDetPupBvr)) add(NUMFDETPUPBVR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetRbuVni", numFDetRbuVni)) add(NUMFDETRBUVNI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxfCmt", DetTxfCmt)) add(DETTXFCMT);
	};

	return basefound;
};

void DlgWdbeVerNew::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWdbeVerNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFDetPupPrj"] = (Json::Value::UInt) numFDetPupPrj;
	me["numFDetPupBvr"] = (Json::Value::UInt) numFDetPupBvr;
	me["numFDetRbuVni"] = (Json::Value::UInt) numFDetRbuVni;
	me["DetTxfCmt"] = DetTxfCmt;
};

void DlgWdbeVerNew::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWdbeVerNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWdbeVerNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDetPupPrj", numFDetPupPrj);
		writeUintAttr(wr, itemtag, "sref", "numFDetPupBvr", numFDetPupBvr);
		writeUintAttr(wr, itemtag, "sref", "numFDetRbuVni", numFDetRbuVni);
		writeStringAttr(wr, itemtag, "sref", "DetTxfCmt", DetTxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeVerNew::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDetPupPrj == comp->numFDetPupPrj) insert(items, NUMFDETPUPPRJ);
	if (numFDetPupBvr == comp->numFDetPupBvr) insert(items, NUMFDETPUPBVR);
	if (numFDetRbuVni == comp->numFDetRbuVni) insert(items, NUMFDETRBUVNI);
	if (DetTxfCmt == comp->DetTxfCmt) insert(items, DETTXFCMT);

	return(items);
};

set<uint> DlgWdbeVerNew::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFDETPUPPRJ, NUMFDETPUPBVR, NUMFDETRBUVNI, DETTXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeVerNew::ContInf
 ******************************************************************************/

DlgWdbeVerNew::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
			, numFSge(numFSge)
		{
	mask = {NUMFSGE};
};

void DlgWdbeVerNew::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeVerNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = (Json::Value::UInt) numFSge;
};

void DlgWdbeVerNew::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeVerNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWdbeVerNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeVerNew::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWdbeVerNew::ContInf::diff(
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
 class DlgWdbeVerNew::StatApp
 ******************************************************************************/

void DlgWdbeVerNew::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWdbeVerNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["shortMenu"] = shortMenu;
};

void DlgWdbeVerNew::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWdbeVerNew";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWdbeVerNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeVerNew::StatShr
 ******************************************************************************/

DlgWdbeVerNew::StatShr::StatShr(
			const bool ButCreActive
		) :
			Block()
			, ButCreActive(ButCreActive)
		{
	mask = {BUTCREACTIVE};
};

void DlgWdbeVerNew::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeVerNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButCreActive"] = ButCreActive;
};

void DlgWdbeVerNew::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeVerNew";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeVerNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButCreActive", ButCreActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeVerNew::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButCreActive == comp->ButCreActive) insert(items, BUTCREACTIVE);

	return(items);
};

set<uint> DlgWdbeVerNew::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTCREACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeVerNew::Tag
 ******************************************************************************/

void DlgWdbeVerNew::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeVerNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["Cpt"] = "Create new version";
		me["DetCptPrj"] = "Project";
		me["DetCptBvr"] = "Base version";
		me["DetCptVni"] = "Version number increment";
		me["DetCptCmt"] = "Comment";
	};
	me["ButCnc"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::CANCEL, ixWdbeVLocale));
	me["ButCre"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::CREATE, ixWdbeVLocale));
};

void DlgWdbeVerNew::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeVerNew";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeVerNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Create new version");
			writeStringAttr(wr, itemtag, "sref", "DetCptPrj", "Project");
			writeStringAttr(wr, itemtag, "sref", "DetCptBvr", "Base version");
			writeStringAttr(wr, itemtag, "sref", "DetCptVni", "Version number increment");
			writeStringAttr(wr, itemtag, "sref", "DetCptCmt", "Comment");
		};
		writeStringAttr(wr, itemtag, "sref", "ButCnc", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::CANCEL, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButCre", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::CREATE, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeVerNew::DpchAppData
 ******************************************************************************/

DlgWdbeVerNew::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBEVERNEWDATA)
		{
};

string DlgWdbeVerNew::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeVerNew::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppDlgWdbeVerNewData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void DlgWdbeVerNew::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWdbeVerNewData");
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
 class DlgWdbeVerNew::DpchAppDo
 ******************************************************************************/

DlgWdbeVerNew::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBEVERNEWDO)
		{
	ixVDo = 0;
};

string DlgWdbeVerNew::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeVerNew::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppDlgWdbeVerNewDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void DlgWdbeVerNew::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWdbeVerNewDo");
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
 class DlgWdbeVerNew::DpchEngData
 ******************************************************************************/

DlgWdbeVerNew::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFDetPupBvr
			, Feed* feedFDetPupPrj
			, Feed* feedFDetRbuVni
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGDLGWDBEVERNEWDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFDETPUPBVR, FEEDFDETPUPPRJ, FEEDFDETRBUVNI, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFDETPUPBVR) && feedFDetPupBvr) this->feedFDetPupBvr = *feedFDetPupBvr;
	if (find(this->mask, FEEDFDETPUPPRJ) && feedFDetPupPrj) this->feedFDetPupPrj = *feedFDetPupPrj;
	if (find(this->mask, FEEDFDETRBUVNI) && feedFDetRbuVni) this->feedFDetRbuVni = *feedFDetRbuVni;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string DlgWdbeVerNew::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFDETPUPBVR)) ss.push_back("feedFDetPupBvr");
	if (has(FEEDFDETPUPPRJ)) ss.push_back("feedFDetPupPrj");
	if (has(FEEDFDETRBUVNI)) ss.push_back("feedFDetRbuVni");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeVerNew::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFDETPUPBVR)) {feedFDetPupBvr = src->feedFDetPupBvr; add(FEEDFDETPUPBVR);};
	if (src->has(FEEDFDETPUPPRJ)) {feedFDetPupPrj = src->feedFDetPupPrj; add(FEEDFDETPUPPRJ);};
	if (src->has(FEEDFDETRBUVNI)) {feedFDetRbuVni = src->feedFDetRbuVni; add(FEEDFDETRBUVNI);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void DlgWdbeVerNew::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngDlgWdbeVerNewData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFDETPUPBVR)) feedFDetPupBvr.writeJSON(me);
	if (has(FEEDFDETPUPPRJ)) feedFDetPupPrj.writeJSON(me);
	if (has(FEEDFDETRBUVNI)) feedFDetRbuVni.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void DlgWdbeVerNew::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWdbeVerNewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFDETPUPBVR)) feedFDetPupBvr.writeXML(wr);
		if (has(FEEDFDETPUPPRJ)) feedFDetPupPrj.writeXML(wr);
		if (has(FEEDFDETRBUVNI)) feedFDetRbuVni.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
