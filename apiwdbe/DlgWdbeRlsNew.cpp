/**
	* \file DlgWdbeRlsNew.cpp
	* API code for job DlgWdbeRlsNew (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "DlgWdbeRlsNew.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWdbeRlsNew::VecVDo
 ******************************************************************************/

uint DlgWdbeRlsNew::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butcncclick") return BUTCNCCLICK;
	if (s == "butcreclick") return BUTCRECLICK;

	return(0);
};

string DlgWdbeRlsNew::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTCNCCLICK) return("ButCncClick");
	if (ix == BUTCRECLICK) return("ButCreClick");

	return("");
};

/******************************************************************************
 class DlgWdbeRlsNew::VecVSge
 ******************************************************************************/

uint DlgWdbeRlsNew::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "create") return CREATE;
	if (s == "done") return DONE;

	return(0);
};

string DlgWdbeRlsNew::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == CREATE) return("create");
	if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgWdbeRlsNew::ContIac
 ******************************************************************************/

DlgWdbeRlsNew::ContIac::ContIac(
			const uint numFDetPupTyp
			, const uint numFDetPupMch
			, const string& DetTxfSrf
		) :
			Block()
		{
	this->numFDetPupTyp = numFDetPupTyp;
	this->numFDetPupMch = numFDetPupMch;
	this->DetTxfSrf = DetTxfSrf;

	mask = {NUMFDETPUPTYP, NUMFDETPUPMCH, DETTXFSRF};
};

bool DlgWdbeRlsNew::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWdbeRlsNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWdbeRlsNew";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetPupTyp", numFDetPupTyp)) add(NUMFDETPUPTYP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetPupMch", numFDetPupMch)) add(NUMFDETPUPMCH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxfSrf", DetTxfSrf)) add(DETTXFSRF);
	};

	return basefound;
};

void DlgWdbeRlsNew::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWdbeRlsNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWdbeRlsNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDetPupTyp", numFDetPupTyp);
		writeUintAttr(wr, itemtag, "sref", "numFDetPupMch", numFDetPupMch);
		writeStringAttr(wr, itemtag, "sref", "DetTxfSrf", DetTxfSrf);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsNew::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDetPupTyp == comp->numFDetPupTyp) insert(items, NUMFDETPUPTYP);
	if (numFDetPupMch == comp->numFDetPupMch) insert(items, NUMFDETPUPMCH);
	if (DetTxfSrf == comp->DetTxfSrf) insert(items, DETTXFSRF);

	return(items);
};

set<uint> DlgWdbeRlsNew::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFDETPUPTYP, NUMFDETPUPMCH, DETTXFSRF};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeRlsNew::ContInf
 ******************************************************************************/

DlgWdbeRlsNew::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

bool DlgWdbeRlsNew::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWdbeRlsNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWdbeRlsNew";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> DlgWdbeRlsNew::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWdbeRlsNew::ContInf::diff(
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
 class DlgWdbeRlsNew::StatApp
 ******************************************************************************/

DlgWdbeRlsNew::StatApp::StatApp(
			const string& shortMenu
		) :
			Block()
		{
	this->shortMenu = shortMenu;

	mask = {SHORTMENU};
};

bool DlgWdbeRlsNew::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgWdbeRlsNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgWdbeRlsNew";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgWdbeRlsNew::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgWdbeRlsNew::StatApp::diff(
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
 class DlgWdbeRlsNew::StatShr
 ******************************************************************************/

DlgWdbeRlsNew::StatShr::StatShr(
			const bool ButCncActive
			, const bool ButCreActive
		) :
			Block()
		{
	this->ButCncActive = ButCncActive;
	this->ButCreActive = ButCreActive;

	mask = {BUTCNCACTIVE, BUTCREACTIVE};
};

bool DlgWdbeRlsNew::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWdbeRlsNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWdbeRlsNew";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCncActive", ButCncActive)) add(BUTCNCACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCreActive", ButCreActive)) add(BUTCREACTIVE);
	};

	return basefound;
};

set<uint> DlgWdbeRlsNew::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButCncActive == comp->ButCncActive) insert(items, BUTCNCACTIVE);
	if (ButCreActive == comp->ButCreActive) insert(items, BUTCREACTIVE);

	return(items);
};

set<uint> DlgWdbeRlsNew::StatShr::diff(
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
 class DlgWdbeRlsNew::Tag
 ******************************************************************************/

DlgWdbeRlsNew::Tag::Tag(
			const string& Cpt
			, const string& DetCptTyp
			, const string& DetCptMch
			, const string& DetCptSrf
			, const string& ButCnc
			, const string& ButCre
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->DetCptTyp = DetCptTyp;
	this->DetCptMch = DetCptMch;
	this->DetCptSrf = DetCptSrf;
	this->ButCnc = ButCnc;
	this->ButCre = ButCre;

	mask = {CPT, DETCPTTYP, DETCPTMCH, DETCPTSRF, BUTCNC, BUTCRE};
};

bool DlgWdbeRlsNew::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbeRlsNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbeRlsNew";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptTyp", DetCptTyp)) add(DETCPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptMch", DetCptMch)) add(DETCPTMCH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptSrf", DetCptSrf)) add(DETCPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButCnc", ButCnc)) add(BUTCNC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButCre", ButCre)) add(BUTCRE);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbeRlsNew::DpchAppData
 ******************************************************************************/

DlgWdbeRlsNew::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBERLSNEWDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string DlgWdbeRlsNew::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeRlsNew::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWdbeRlsNewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsNew::DpchAppDo
 ******************************************************************************/

DlgWdbeRlsNew::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBERLSNEWDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string DlgWdbeRlsNew::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeRlsNew::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWdbeRlsNewDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsNew::DpchEngData
 ******************************************************************************/

DlgWdbeRlsNew::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGDLGWDBERLSNEWDATA)
		{
	feedFDetPupMch.tag = "FeedFDetPupMch";
	feedFDetPupTyp.tag = "FeedFDetPupTyp";
	feedFSge.tag = "FeedFSge";
};

string DlgWdbeRlsNew::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFDETPUPMCH)) ss.push_back("feedFDetPupMch");
	if (has(FEEDFDETPUPTYP)) ss.push_back("feedFDetPupTyp");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeRlsNew::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgWdbeRlsNewData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFDetPupMch.readXML(docctx, basexpath, true)) add(FEEDFDETPUPMCH);
		if (feedFDetPupTyp.readXML(docctx, basexpath, true)) add(FEEDFDETPUPTYP);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFDetPupMch.clear();
		feedFDetPupTyp.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

