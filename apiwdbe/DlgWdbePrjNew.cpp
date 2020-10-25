/**
	* \file DlgWdbePrjNew.cpp
	* API code for job DlgWdbePrjNew (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "DlgWdbePrjNew.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWdbePrjNew::VecVDo
 ******************************************************************************/

uint DlgWdbePrjNew::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "detbutautclick") return DETBUTAUTCLICK;
	if (s == "butcncclick") return BUTCNCCLICK;
	if (s == "butcreclick") return BUTCRECLICK;

	return(0);
};

string DlgWdbePrjNew::VecVDo::getSref(
			const uint ix
		) {
	if (ix == DETBUTAUTCLICK) return("DetButAutClick");
	if (ix == BUTCNCCLICK) return("ButCncClick");
	if (ix == BUTCRECLICK) return("ButCreClick");

	return("");
};

/******************************************************************************
 class DlgWdbePrjNew::VecVSge
 ******************************************************************************/

uint DlgWdbePrjNew::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alraer") return ALRAER;
	if (s == "auth") return AUTH;
	if (s == "autdone") return AUTDONE;
	if (s == "create") return CREATE;
	if (s == "sync") return SYNC;
	if (s == "done") return DONE;

	return(0);
};

string DlgWdbePrjNew::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRAER) return("alraer");
	if (ix == AUTH) return("auth");
	if (ix == AUTDONE) return("autdone");
	if (ix == CREATE) return("create");
	if (ix == SYNC) return("sync");
	if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgWdbePrjNew::ContIac
 ******************************************************************************/

DlgWdbePrjNew::ContIac::ContIac(
			const string& DetTxfSho
			, const string& DetTxfTit
		) :
			Block()
		{
	this->DetTxfSho = DetTxfSho;
	this->DetTxfTit = DetTxfTit;

	mask = {DETTXFSHO, DETTXFTIT};
};

bool DlgWdbePrjNew::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWdbePrjNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWdbePrjNew";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxfSho", DetTxfSho)) add(DETTXFSHO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxfTit", DetTxfTit)) add(DETTXFTIT);
	};

	return basefound;
};

void DlgWdbePrjNew::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWdbePrjNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWdbePrjNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "DetTxfSho", DetTxfSho);
		writeStringAttr(wr, itemtag, "sref", "DetTxfTit", DetTxfTit);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbePrjNew::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (DetTxfSho == comp->DetTxfSho) insert(items, DETTXFSHO);
	if (DetTxfTit == comp->DetTxfTit) insert(items, DETTXFTIT);

	return(items);
};

set<uint> DlgWdbePrjNew::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DETTXFSHO, DETTXFTIT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbePrjNew::ContInf
 ******************************************************************************/

DlgWdbePrjNew::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

bool DlgWdbePrjNew::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWdbePrjNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWdbePrjNew";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> DlgWdbePrjNew::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWdbePrjNew::ContInf::diff(
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
 class DlgWdbePrjNew::StatApp
 ******************************************************************************/

DlgWdbePrjNew::StatApp::StatApp(
			const string& shortMenu
		) :
			Block()
		{
	this->shortMenu = shortMenu;

	mask = {SHORTMENU};
};

bool DlgWdbePrjNew::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgWdbePrjNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgWdbePrjNew";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgWdbePrjNew::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgWdbePrjNew::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SHORTMENU};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbePrjNew::StatShr
 ******************************************************************************/

DlgWdbePrjNew::StatShr::StatShr(
			const bool DetButAutActive
			, const bool ButCncActive
			, const bool ButCreActive
		) :
			Block()
		{
	this->DetButAutActive = DetButAutActive;
	this->ButCncActive = ButCncActive;
	this->ButCreActive = ButCreActive;

	mask = {DETBUTAUTACTIVE, BUTCNCACTIVE, BUTCREACTIVE};
};

bool DlgWdbePrjNew::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWdbePrjNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWdbePrjNew";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DetButAutActive", DetButAutActive)) add(DETBUTAUTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCncActive", ButCncActive)) add(BUTCNCACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCreActive", ButCreActive)) add(BUTCREACTIVE);
	};

	return basefound;
};

set<uint> DlgWdbePrjNew::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (DetButAutActive == comp->DetButAutActive) insert(items, DETBUTAUTACTIVE);
	if (ButCncActive == comp->ButCncActive) insert(items, BUTCNCACTIVE);
	if (ButCreActive == comp->ButCreActive) insert(items, BUTCREACTIVE);

	return(items);
};

set<uint> DlgWdbePrjNew::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DETBUTAUTACTIVE, BUTCNCACTIVE, BUTCREACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbePrjNew::Tag
 ******************************************************************************/

DlgWdbePrjNew::Tag::Tag(
			const string& Cpt
			, const string& DetCptSho
			, const string& DetCptTit
			, const string& DetButAut
			, const string& ButCnc
			, const string& ButCre
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->DetCptSho = DetCptSho;
	this->DetCptTit = DetCptTit;
	this->DetButAut = DetButAut;
	this->ButCnc = ButCnc;
	this->ButCre = ButCre;

	mask = {CPT, DETCPTSHO, DETCPTTIT, DETBUTAUT, BUTCNC, BUTCRE};
};

bool DlgWdbePrjNew::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbePrjNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbePrjNew";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptSho", DetCptSho)) add(DETCPTSHO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptTit", DetCptTit)) add(DETCPTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetButAut", DetButAut)) add(DETBUTAUT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButCnc", ButCnc)) add(BUTCNC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButCre", ButCre)) add(BUTCRE);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbePrjNew::DpchAppData
 ******************************************************************************/

DlgWdbePrjNew::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBEPRJNEWDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string DlgWdbePrjNew::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbePrjNew::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWdbePrjNewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbePrjNew::DpchAppDo
 ******************************************************************************/

DlgWdbePrjNew::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBEPRJNEWDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string DlgWdbePrjNew::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbePrjNew::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWdbePrjNewDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbePrjNew::DpchEngData
 ******************************************************************************/

DlgWdbePrjNew::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGDLGWDBEPRJNEWDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string DlgWdbePrjNew::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbePrjNew::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgWdbePrjNewData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

