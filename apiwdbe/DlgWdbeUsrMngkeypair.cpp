/**
	* \file DlgWdbeUsrMngkeypair.cpp
	* API code for job DlgWdbeUsrMngkeypair (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "DlgWdbeUsrMngkeypair.h"

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

bool DlgWdbeUsrMngkeypair::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWdbeUsrMngkeypair");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWdbeUsrMngkeypair";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxtSte", DetTxtSte)) add(DETTXTSTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetDld", DetDld)) add(DETDLD);
	};

	return basefound;
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

DlgWdbeUsrMngkeypair::StatApp::StatApp(
			const string& shortMenu
		) :
			Block()
		{
	this->shortMenu = shortMenu;

	mask = {SHORTMENU};
};

bool DlgWdbeUsrMngkeypair::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgWdbeUsrMngkeypair");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgWdbeUsrMngkeypair";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgWdbeUsrMngkeypair::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgWdbeUsrMngkeypair::StatApp::diff(
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

bool DlgWdbeUsrMngkeypair::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWdbeUsrMngkeypair");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWdbeUsrMngkeypair";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DetButDelAvail", DetButDelAvail)) add(DETBUTDELAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DetButGenAvail", DetButGenAvail)) add(DETBUTGENAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DetDldActive", DetDldActive)) add(DETDLDACTIVE);
	};

	return basefound;
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

DlgWdbeUsrMngkeypair::Tag::Tag(
			const string& Cpt
			, const string& DetCptSte
			, const string& DetButDel
			, const string& DetButGen
			, const string& DetDld
			, const string& ButDne
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->DetCptSte = DetCptSte;
	this->DetButDel = DetButDel;
	this->DetButGen = DetButGen;
	this->DetDld = DetDld;
	this->ButDne = ButDne;

	mask = {CPT, DETCPTSTE, DETBUTDEL, DETBUTGEN, DETDLD, BUTDNE};
};

bool DlgWdbeUsrMngkeypair::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbeUsrMngkeypair");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbeUsrMngkeypair";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptSte", DetCptSte)) add(DETCPTSTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetButDel", DetButDel)) add(DETBUTDEL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetButGen", DetButGen)) add(DETBUTGEN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetDld", DetDld)) add(DETDLD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbeUsrMngkeypair::DpchAppDo
 ******************************************************************************/

DlgWdbeUsrMngkeypair::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBEUSRMNGKEYPAIRDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string DlgWdbeUsrMngkeypair::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeUsrMngkeypair::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWdbeUsrMngkeypairDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeUsrMngkeypair::DpchEngData
 ******************************************************************************/

DlgWdbeUsrMngkeypair::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGDLGWDBEUSRMNGKEYPAIRDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string DlgWdbeUsrMngkeypair::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeUsrMngkeypair::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgWdbeUsrMngkeypairData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

