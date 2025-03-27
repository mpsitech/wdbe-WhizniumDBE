/**
	* \file DlgWdbeVerNew.cpp
	* API code for job DlgWdbeVerNew (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "DlgWdbeVerNew.h"

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

bool DlgWdbeVerNew::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWdbeVerNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWdbeVerNew";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
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

DlgWdbeVerNew::StatApp::StatApp(
			const string& shortMenu
		) :
			Block()
			, shortMenu(shortMenu)
		{
	mask = {SHORTMENU};
};

bool DlgWdbeVerNew::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgWdbeVerNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgWdbeVerNew";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgWdbeVerNew::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgWdbeVerNew::StatApp::diff(
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

bool DlgWdbeVerNew::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWdbeVerNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWdbeVerNew";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCreActive", ButCreActive)) add(BUTCREACTIVE);
	};

	return basefound;
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

DlgWdbeVerNew::Tag::Tag(
			const string& Cpt
			, const string& DetCptPrj
			, const string& DetCptBvr
			, const string& DetCptVni
			, const string& DetCptCmt
			, const string& ButCnc
			, const string& ButCre
		) :
			Block()
			, Cpt(Cpt)
			, DetCptPrj(DetCptPrj)
			, DetCptBvr(DetCptBvr)
			, DetCptVni(DetCptVni)
			, DetCptCmt(DetCptCmt)
			, ButCnc(ButCnc)
			, ButCre(ButCre)
		{
	mask = {CPT, DETCPTPRJ, DETCPTBVR, DETCPTVNI, DETCPTCMT, BUTCNC, BUTCRE};
};

bool DlgWdbeVerNew::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbeVerNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbeVerNew";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptPrj", DetCptPrj)) add(DETCPTPRJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptBvr", DetCptBvr)) add(DETCPTBVR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptVni", DetCptVni)) add(DETCPTVNI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptCmt", DetCptCmt)) add(DETCPTCMT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButCnc", ButCnc)) add(BUTCNC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButCre", ButCre)) add(BUTCRE);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbeVerNew::DpchAppData
 ******************************************************************************/

DlgWdbeVerNew::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBEVERNEWDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string DlgWdbeVerNew::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeVerNew::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWdbeVerNewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeVerNew::DpchAppDo
 ******************************************************************************/

DlgWdbeVerNew::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBEVERNEWDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string DlgWdbeVerNew::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeVerNew::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWdbeVerNewDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeVerNew::DpchEngData
 ******************************************************************************/

DlgWdbeVerNew::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGDLGWDBEVERNEWDATA)
		{
	feedFDetPupBvr.tag = "FeedFDetPupBvr";
	feedFDetPupPrj.tag = "FeedFDetPupPrj";
	feedFDetRbuVni.tag = "FeedFDetRbuVni";
	feedFSge.tag = "FeedFSge";
};

string DlgWdbeVerNew::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
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

void DlgWdbeVerNew::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgWdbeVerNewData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFDetPupBvr.readXML(docctx, basexpath, true)) add(FEEDFDETPUPBVR);
		if (feedFDetPupPrj.readXML(docctx, basexpath, true)) add(FEEDFDETPUPPRJ);
		if (feedFDetRbuVni.readXML(docctx, basexpath, true)) add(FEEDFDETRBUVNI);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFDetPupBvr.clear();
		feedFDetPupPrj.clear();
		feedFDetRbuVni.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
