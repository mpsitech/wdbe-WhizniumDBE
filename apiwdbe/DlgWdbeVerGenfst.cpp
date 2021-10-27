/**
	* \file DlgWdbeVerGenfst.cpp
	* API code for job DlgWdbeVerGenfst (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#include "DlgWdbeVerGenfst.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWdbeVerGenfst::VecVDo
 ******************************************************************************/

uint DlgWdbeVerGenfst::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "gfsbutrunclick") return GFSBUTRUNCLICK;
	if (s == "gfsbutstoclick") return GFSBUTSTOCLICK;
	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWdbeVerGenfst::VecVDo::getSref(
			const uint ix
		) {
	if (ix == GFSBUTRUNCLICK) return("GfsButRunClick");
	if (ix == GFSBUTSTOCLICK) return("GfsButStoClick");
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWdbeVerGenfst::VecVSge
 ******************************************************************************/

uint DlgWdbeVerGenfst::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "genfst") return GENFST;
	if (s == "genmtp") return GENMTP;
	if (s == "done") return DONE;

	return(0);
};

string DlgWdbeVerGenfst::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == GENFST) return("genfst");
	if (ix == GENMTP) return("genmtp");
	if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgWdbeVerGenfst::ContInf
 ******************************************************************************/

DlgWdbeVerGenfst::ContInf::ContInf(
			const uint numFSge
			, const string& GfsTxtPrg
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->GfsTxtPrg = GfsTxtPrg;

	mask = {NUMFSGE, GFSTXTPRG};
};

bool DlgWdbeVerGenfst::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWdbeVerGenfst");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWdbeVerGenfst";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "GfsTxtPrg", GfsTxtPrg)) add(GFSTXTPRG);
	};

	return basefound;
};

set<uint> DlgWdbeVerGenfst::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (GfsTxtPrg == comp->GfsTxtPrg) insert(items, GFSTXTPRG);

	return(items);
};

set<uint> DlgWdbeVerGenfst::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, GFSTXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeVerGenfst::StatApp
 ******************************************************************************/

DlgWdbeVerGenfst::StatApp::StatApp(
			const string& shortMenu
		) :
			Block()
		{
	this->shortMenu = shortMenu;

	mask = {SHORTMENU};
};

bool DlgWdbeVerGenfst::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgWdbeVerGenfst");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgWdbeVerGenfst";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgWdbeVerGenfst::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgWdbeVerGenfst::StatApp::diff(
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
 class DlgWdbeVerGenfst::StatShr
 ******************************************************************************/

DlgWdbeVerGenfst::StatShr::StatShr(
			const bool GfsButRunActive
			, const bool GfsButStoActive
			, const bool ButDneActive
		) :
			Block()
		{
	this->GfsButRunActive = GfsButRunActive;
	this->GfsButStoActive = GfsButStoActive;
	this->ButDneActive = ButDneActive;

	mask = {GFSBUTRUNACTIVE, GFSBUTSTOACTIVE, BUTDNEACTIVE};
};

bool DlgWdbeVerGenfst::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWdbeVerGenfst");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWdbeVerGenfst";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "GfsButRunActive", GfsButRunActive)) add(GFSBUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "GfsButStoActive", GfsButStoActive)) add(GFSBUTSTOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDneActive", ButDneActive)) add(BUTDNEACTIVE);
	};

	return basefound;
};

set<uint> DlgWdbeVerGenfst::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (GfsButRunActive == comp->GfsButRunActive) insert(items, GFSBUTRUNACTIVE);
	if (GfsButStoActive == comp->GfsButStoActive) insert(items, GFSBUTSTOACTIVE);
	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgWdbeVerGenfst::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {GFSBUTRUNACTIVE, GFSBUTSTOACTIVE, BUTDNEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeVerGenfst::Tag
 ******************************************************************************/

DlgWdbeVerGenfst::Tag::Tag(
			const string& Cpt
			, const string& GfsCptPrg
			, const string& GfsButRun
			, const string& GfsButSto
			, const string& ButDne
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->GfsCptPrg = GfsCptPrg;
	this->GfsButRun = GfsButRun;
	this->GfsButSto = GfsButSto;
	this->ButDne = ButDne;

	mask = {CPT, GFSCPTPRG, GFSBUTRUN, GFSBUTSTO, BUTDNE};
};

bool DlgWdbeVerGenfst::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbeVerGenfst");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbeVerGenfst";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "GfsCptPrg", GfsCptPrg)) add(GFSCPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "GfsButRun", GfsButRun)) add(GFSBUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "GfsButSto", GfsButSto)) add(GFSBUTSTO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbeVerGenfst::DpchAppDo
 ******************************************************************************/

DlgWdbeVerGenfst::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBEVERGENFSTDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string DlgWdbeVerGenfst::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeVerGenfst::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWdbeVerGenfstDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeVerGenfst::DpchEngData
 ******************************************************************************/

DlgWdbeVerGenfst::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGDLGWDBEVERGENFSTDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string DlgWdbeVerGenfst::DpchEngData::getSrefsMask() {
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

void DlgWdbeVerGenfst::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgWdbeVerGenfstData");
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
