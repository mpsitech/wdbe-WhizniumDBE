/**
	* \file DlgWdbeNavMnglic_blks.cpp
	* job handler for job DlgWdbeNavMnglic (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWdbeNavMnglic::VecVDo
 ******************************************************************************/

uint DlgWdbeNavMnglic::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "detbutscnclick") return DETBUTSCNCLICK;
	if (s == "detbutsdcclick") return DETBUTSDCCLICK;
	if (s == "detbutactclick") return DETBUTACTCLICK;
	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWdbeNavMnglic::VecVDo::getSref(
			const uint ix
		) {
	if (ix == DETBUTSCNCLICK) return("DetButScnClick");
	if (ix == DETBUTSDCCLICK) return("DetButSdcClick");
	if (ix == DETBUTACTCLICK) return("DetButActClick");
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWdbeNavMnglic::VecVSge
 ******************************************************************************/

uint DlgWdbeNavMnglic::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "ready") return READY;

	return(0);
};

string DlgWdbeNavMnglic::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == READY) return("ready");

	return("");
};

void DlgWdbeNavMnglic::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgWdbeNavMnglic::ContIac
 ******************************************************************************/

DlgWdbeNavMnglic::ContIac::ContIac(
			const uint numFDetPupFis
			, const bool DetChkFis
			, const uint numFDetLstLcs
		) :
			Block()
			, numFDetPupFis(numFDetPupFis)
			, DetChkFis(DetChkFis)
			, numFDetLstLcs(numFDetLstLcs)
		{
	mask = {NUMFDETPUPFIS, DETCHKFIS, NUMFDETLSTLCS};
};

bool DlgWdbeNavMnglic::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacDlgWdbeNavMnglic"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFDetPupFis")) {numFDetPupFis = me["numFDetPupFis"].asUInt(); add(NUMFDETPUPFIS);};
		if (me.isMember("DetChkFis")) {DetChkFis = me["DetChkFis"].asBool(); add(DETCHKFIS);};
		if (me.isMember("numFDetLstLcs")) {numFDetLstLcs = me["numFDetLstLcs"].asUInt(); add(NUMFDETLSTLCS);};
	};

	return basefound;
};

bool DlgWdbeNavMnglic::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWdbeNavMnglic");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWdbeNavMnglic";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetPupFis", numFDetPupFis)) add(NUMFDETPUPFIS);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetChkFis", DetChkFis)) add(DETCHKFIS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetLstLcs", numFDetLstLcs)) add(NUMFDETLSTLCS);
	};

	return basefound;
};

void DlgWdbeNavMnglic::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWdbeNavMnglic";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFDetPupFis"] = (Json::Value::UInt) numFDetPupFis;
	me["DetChkFis"] = DetChkFis;
	me["numFDetLstLcs"] = (Json::Value::UInt) numFDetLstLcs;
};

void DlgWdbeNavMnglic::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWdbeNavMnglic";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWdbeNavMnglic";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDetPupFis", numFDetPupFis);
		writeBoolAttr(wr, itemtag, "sref", "DetChkFis", DetChkFis);
		writeUintAttr(wr, itemtag, "sref", "numFDetLstLcs", numFDetLstLcs);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeNavMnglic::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDetPupFis == comp->numFDetPupFis) insert(items, NUMFDETPUPFIS);
	if (DetChkFis == comp->DetChkFis) insert(items, DETCHKFIS);
	if (numFDetLstLcs == comp->numFDetLstLcs) insert(items, NUMFDETLSTLCS);

	return(items);
};

set<uint> DlgWdbeNavMnglic::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFDETPUPFIS, DETCHKFIS, NUMFDETLSTLCS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeNavMnglic::ContInf
 ******************************************************************************/

DlgWdbeNavMnglic::ContInf::ContInf(
			const uint numFSge
			, const string& DetTxtSip
			, const string& DetTxtScp
			, const string& DetTxtLsr
			, const string& DetTxtLar
			, const string& DetTxtLst
			, const string& DetTxtLex
		) :
			Block()
			, numFSge(numFSge)
			, DetTxtSip(DetTxtSip)
			, DetTxtScp(DetTxtScp)
			, DetTxtLsr(DetTxtLsr)
			, DetTxtLar(DetTxtLar)
			, DetTxtLst(DetTxtLst)
			, DetTxtLex(DetTxtLex)
		{
	mask = {NUMFSGE, DETTXTSIP, DETTXTSCP, DETTXTLSR, DETTXTLAR, DETTXTLST, DETTXTLEX};
};

void DlgWdbeNavMnglic::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeNavMnglic";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = (Json::Value::UInt) numFSge;
	me["DetTxtSip"] = DetTxtSip;
	me["DetTxtScp"] = DetTxtScp;
	me["DetTxtLsr"] = DetTxtLsr;
	me["DetTxtLar"] = DetTxtLar;
	me["DetTxtLst"] = DetTxtLst;
	me["DetTxtLex"] = DetTxtLex;
};

void DlgWdbeNavMnglic::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeNavMnglic";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWdbeNavMnglic";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "DetTxtSip", DetTxtSip);
		writeStringAttr(wr, itemtag, "sref", "DetTxtScp", DetTxtScp);
		writeStringAttr(wr, itemtag, "sref", "DetTxtLsr", DetTxtLsr);
		writeStringAttr(wr, itemtag, "sref", "DetTxtLar", DetTxtLar);
		writeStringAttr(wr, itemtag, "sref", "DetTxtLst", DetTxtLst);
		writeStringAttr(wr, itemtag, "sref", "DetTxtLex", DetTxtLex);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeNavMnglic::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (DetTxtSip == comp->DetTxtSip) insert(items, DETTXTSIP);
	if (DetTxtScp == comp->DetTxtScp) insert(items, DETTXTSCP);
	if (DetTxtLsr == comp->DetTxtLsr) insert(items, DETTXTLSR);
	if (DetTxtLar == comp->DetTxtLar) insert(items, DETTXTLAR);
	if (DetTxtLst == comp->DetTxtLst) insert(items, DETTXTLST);
	if (DetTxtLex == comp->DetTxtLex) insert(items, DETTXTLEX);

	return(items);
};

set<uint> DlgWdbeNavMnglic::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, DETTXTSIP, DETTXTSCP, DETTXTLSR, DETTXTLAR, DETTXTLST, DETTXTLEX};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeNavMnglic::StatApp
 ******************************************************************************/

void DlgWdbeNavMnglic::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const string& shortMenu
			, const uint DetLstLcsNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWdbeNavMnglic";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["shortMenu"] = shortMenu;
	me["DetLstLcsNumFirstdisp"] = (Json::Value::UInt) DetLstLcsNumFirstdisp;
};

void DlgWdbeNavMnglic::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const string& shortMenu
			, const uint DetLstLcsNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWdbeNavMnglic";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWdbeNavMnglic";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "DetLstLcsNumFirstdisp", DetLstLcsNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeNavMnglic::StatShr
 ******************************************************************************/

DlgWdbeNavMnglic::StatShr::StatShr(
			const bool DetButActActive
		) :
			Block()
			, DetButActActive(DetButActActive)
		{
	mask = {DETBUTACTACTIVE};
};

void DlgWdbeNavMnglic::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeNavMnglic";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["DetButActActive"] = DetButActActive;
};

void DlgWdbeNavMnglic::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeNavMnglic";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeNavMnglic";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "DetButActActive", DetButActActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeNavMnglic::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (DetButActActive == comp->DetButActActive) insert(items, DETBUTACTACTIVE);

	return(items);
};

set<uint> DlgWdbeNavMnglic::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DETBUTACTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeNavMnglic::Tag
 ******************************************************************************/

void DlgWdbeNavMnglic::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeNavMnglic";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["Cpt"] = "Manage licenses";
		me["DetHdgSrv"] = "Licensing server";
		me["DetCptSip"] = "IP address";
		me["DetCptScp"] = "Certificate path";
		me["DetButScn"] = "Connect";
		me["DetButSdc"] = "Disconnect";
		me["DetCptFis"] = "Filter by state";
		me["DetCptLcs"] = "Licenses";
		me["DetButAct"] = "Activate";
		me["DetHdgLic"] = "License";
		me["DetCptLsr"] = "Identifier";
		me["DetCptLar"] = "Article";
		me["DetCptLst"] = "State";
		me["DetCptLex"] = "Expiry";
	};
	me["ButDne"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DONE, ixWdbeVLocale));
};

void DlgWdbeNavMnglic::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeNavMnglic";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeNavMnglic";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Manage licenses");
			writeStringAttr(wr, itemtag, "sref", "DetHdgSrv", "Licensing server");
			writeStringAttr(wr, itemtag, "sref", "DetCptSip", "IP address");
			writeStringAttr(wr, itemtag, "sref", "DetCptScp", "Certificate path");
			writeStringAttr(wr, itemtag, "sref", "DetButScn", "Connect");
			writeStringAttr(wr, itemtag, "sref", "DetButSdc", "Disconnect");
			writeStringAttr(wr, itemtag, "sref", "DetCptFis", "Filter by state");
			writeStringAttr(wr, itemtag, "sref", "DetCptLcs", "Licenses");
			writeStringAttr(wr, itemtag, "sref", "DetButAct", "Activate");
			writeStringAttr(wr, itemtag, "sref", "DetHdgLic", "License");
			writeStringAttr(wr, itemtag, "sref", "DetCptLsr", "Identifier");
			writeStringAttr(wr, itemtag, "sref", "DetCptLar", "Article");
			writeStringAttr(wr, itemtag, "sref", "DetCptLst", "State");
			writeStringAttr(wr, itemtag, "sref", "DetCptLex", "Expiry");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DONE, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeNavMnglic::DpchAppData
 ******************************************************************************/

DlgWdbeNavMnglic::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBENAVMNGLICDATA)
		{
};

string DlgWdbeNavMnglic::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeNavMnglic::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppDlgWdbeNavMnglicData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void DlgWdbeNavMnglic::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWdbeNavMnglicData");
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
 class DlgWdbeNavMnglic::DpchAppDo
 ******************************************************************************/

DlgWdbeNavMnglic::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBENAVMNGLICDO)
		{
	ixVDo = 0;
};

string DlgWdbeNavMnglic::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeNavMnglic::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppDlgWdbeNavMnglicDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void DlgWdbeNavMnglic::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWdbeNavMnglicDo");
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
 class DlgWdbeNavMnglic::DpchEngData
 ******************************************************************************/

DlgWdbeNavMnglic::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFDetLstLcs
			, Feed* feedFDetPupFis
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGDLGWDBENAVMNGLICDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFDETLSTLCS, FEEDFDETPUPFIS, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFDETLSTLCS) && feedFDetLstLcs) this->feedFDetLstLcs = *feedFDetLstLcs;
	if (find(this->mask, FEEDFDETPUPFIS) && feedFDetPupFis) this->feedFDetPupFis = *feedFDetPupFis;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string DlgWdbeNavMnglic::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFDETLSTLCS)) ss.push_back("feedFDetLstLcs");
	if (has(FEEDFDETPUPFIS)) ss.push_back("feedFDetPupFis");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeNavMnglic::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFDETLSTLCS)) {feedFDetLstLcs = src->feedFDetLstLcs; add(FEEDFDETLSTLCS);};
	if (src->has(FEEDFDETPUPFIS)) {feedFDetPupFis = src->feedFDetPupFis; add(FEEDFDETPUPFIS);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void DlgWdbeNavMnglic::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngDlgWdbeNavMnglicData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFDETLSTLCS)) feedFDetLstLcs.writeJSON(me);
	if (has(FEEDFDETPUPFIS)) feedFDetPupFis.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void DlgWdbeNavMnglic::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWdbeNavMnglicData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFDETLSTLCS)) feedFDetLstLcs.writeXML(wr);
		if (has(FEEDFDETPUPFIS)) feedFDetPupFis.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
