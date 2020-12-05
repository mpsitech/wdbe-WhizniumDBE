/**
	* \file CrdWdbeRls.cpp
	* API code for job CrdWdbeRls (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "CrdWdbeRls.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWdbeRls::VecVDo
 ******************************************************************************/

uint CrdWdbeRls::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitcrdnewclick") return MITCRDNEWCLICK;
	if (s == "mitcrdsrtclick") return MITCRDSRTCLICK;
	if (s == "mitcrdcrtclick") return MITCRDCRTCLICK;
	if (s == "mitcrdfrtclick") return MITCRDFRTCLICK;
	if (s == "mitcrdwcoclick") return MITCRDWCOCLICK;

	return(0);
};

string CrdWdbeRls::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITCRDNEWCLICK) return("MitCrdNewClick");
	if (ix == MITCRDSRTCLICK) return("MitCrdSrtClick");
	if (ix == MITCRDCRTCLICK) return("MitCrdCrtClick");
	if (ix == MITCRDFRTCLICK) return("MitCrdFrtClick");
	if (ix == MITCRDWCOCLICK) return("MitCrdWcoClick");

	return("");
};

/******************************************************************************
 class CrdWdbeRls::VecVSge
 ******************************************************************************/

uint CrdWdbeRls::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwdbeabt") return ALRWDBEABT;

	return(0);
};

string CrdWdbeRls::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWDBEABT) return("alrwdbeabt");

	return("");
};

/******************************************************************************
 class CrdWdbeRls::ContInf
 ******************************************************************************/

CrdWdbeRls::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdRls
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxCrdRls = MtxCrdRls;

	mask = {NUMFSGE, MRLAPPHLP, MTXCRDRLS};
};

bool CrdWdbeRls::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeRls");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeRls";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxCrdRls", MtxCrdRls)) add(MTXCRDRLS);
	};

	return basefound;
};

set<uint> CrdWdbeRls::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxCrdRls == comp->MtxCrdRls) insert(items, MTXCRDRLS);

	return(items);
};

set<uint> CrdWdbeRls::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDRLS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWdbeRls::StatApp
 ******************************************************************************/

CrdWdbeRls::StatApp::StatApp(
			const uint ixWdbeVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) :
			Block()
		{
	this->ixWdbeVReqitmode = ixWdbeVReqitmode;
	this->latency = latency;
	this->shortMenu = shortMenu;
	this->widthMenu = widthMenu;
	this->initdoneHeadbar = initdoneHeadbar;
	this->initdoneList = initdoneList;
	this->initdoneRec = initdoneRec;

	mask = {IXWDBEVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC};
};

bool CrdWdbeRls::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeRls");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeRls";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVReqitmode", srefIxWdbeVReqitmode)) {
			ixWdbeVReqitmode = VecWdbeVReqitmode::getIx(srefIxWdbeVReqitmode);
			add(IXWDBEVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneList", initdoneList)) add(INITDONELIST);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRec", initdoneRec)) add(INITDONEREC);
	};

	return basefound;
};

set<uint> CrdWdbeRls::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVReqitmode == comp->ixWdbeVReqitmode) insert(items, IXWDBEVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);
	if (initdoneList == comp->initdoneList) insert(items, INITDONELIST);
	if (initdoneRec == comp->initdoneRec) insert(items, INITDONEREC);

	return(items);
};

set<uint> CrdWdbeRls::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWdbeRls::StatShr
 ******************************************************************************/

CrdWdbeRls::StatShr::StatShr(
			const string& scrJrefDlgfinreptr
			, const string& scrJrefDlgnew
			, const string& scrJrefDlgstareptr
			, const string& scrJrefDlgwrite
			, const string& scrJrefHeadbar
			, const string& scrJrefList
			, const string& scrJrefRec
			, const bool MspCrd1Avail
			, const bool MitCrdNewAvail
			, const bool MitCrdSrtAvail
			, const bool MitCrdSrtActive
			, const bool MitCrdCrtAvail
			, const bool MitCrdCrtActive
			, const bool MitCrdFrtAvail
			, const bool MitCrdFrtActive
			, const bool MitCrdWcoAvail
			, const bool MitCrdWcoActive
		) :
			Block()
		{
	this->scrJrefDlgfinreptr = scrJrefDlgfinreptr;
	this->scrJrefDlgnew = scrJrefDlgnew;
	this->scrJrefDlgstareptr = scrJrefDlgstareptr;
	this->scrJrefDlgwrite = scrJrefDlgwrite;
	this->scrJrefHeadbar = scrJrefHeadbar;
	this->scrJrefList = scrJrefList;
	this->scrJrefRec = scrJrefRec;
	this->MspCrd1Avail = MspCrd1Avail;
	this->MitCrdNewAvail = MitCrdNewAvail;
	this->MitCrdSrtAvail = MitCrdSrtAvail;
	this->MitCrdSrtActive = MitCrdSrtActive;
	this->MitCrdCrtAvail = MitCrdCrtAvail;
	this->MitCrdCrtActive = MitCrdCrtActive;
	this->MitCrdFrtAvail = MitCrdFrtAvail;
	this->MitCrdFrtActive = MitCrdFrtActive;
	this->MitCrdWcoAvail = MitCrdWcoAvail;
	this->MitCrdWcoActive = MitCrdWcoActive;

	mask = {SCRJREFDLGFINREPTR, SCRJREFDLGNEW, SCRJREFDLGSTAREPTR, SCRJREFDLGWRITE, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDSRTAVAIL, MITCRDSRTACTIVE, MITCRDCRTAVAIL, MITCRDCRTACTIVE, MITCRDFRTAVAIL, MITCRDFRTACTIVE, MITCRDWCOAVAIL, MITCRDWCOACTIVE};
};

bool CrdWdbeRls::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeRls");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeRls";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgfinreptr", scrJrefDlgfinreptr)) add(SCRJREFDLGFINREPTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgnew", scrJrefDlgnew)) add(SCRJREFDLGNEW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgstareptr", scrJrefDlgstareptr)) add(SCRJREFDLGSTAREPTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgwrite", scrJrefDlgwrite)) add(SCRJREFDLGWRITE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefList", scrJrefList)) add(SCRJREFLIST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRec", scrJrefRec)) add(SCRJREFREC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", MspCrd1Avail)) add(MSPCRD1AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdNewAvail", MitCrdNewAvail)) add(MITCRDNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSrtAvail", MitCrdSrtAvail)) add(MITCRDSRTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSrtActive", MitCrdSrtActive)) add(MITCRDSRTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCrtAvail", MitCrdCrtAvail)) add(MITCRDCRTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCrtActive", MitCrdCrtActive)) add(MITCRDCRTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdFrtAvail", MitCrdFrtAvail)) add(MITCRDFRTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdFrtActive", MitCrdFrtActive)) add(MITCRDFRTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdWcoAvail", MitCrdWcoAvail)) add(MITCRDWCOAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdWcoActive", MitCrdWcoActive)) add(MITCRDWCOACTIVE);
	};

	return basefound;
};

set<uint> CrdWdbeRls::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefDlgfinreptr == comp->scrJrefDlgfinreptr) insert(items, SCRJREFDLGFINREPTR);
	if (scrJrefDlgnew == comp->scrJrefDlgnew) insert(items, SCRJREFDLGNEW);
	if (scrJrefDlgstareptr == comp->scrJrefDlgstareptr) insert(items, SCRJREFDLGSTAREPTR);
	if (scrJrefDlgwrite == comp->scrJrefDlgwrite) insert(items, SCRJREFDLGWRITE);
	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);
	if (scrJrefList == comp->scrJrefList) insert(items, SCRJREFLIST);
	if (scrJrefRec == comp->scrJrefRec) insert(items, SCRJREFREC);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdNewAvail == comp->MitCrdNewAvail) insert(items, MITCRDNEWAVAIL);
	if (MitCrdSrtAvail == comp->MitCrdSrtAvail) insert(items, MITCRDSRTAVAIL);
	if (MitCrdSrtActive == comp->MitCrdSrtActive) insert(items, MITCRDSRTACTIVE);
	if (MitCrdCrtAvail == comp->MitCrdCrtAvail) insert(items, MITCRDCRTAVAIL);
	if (MitCrdCrtActive == comp->MitCrdCrtActive) insert(items, MITCRDCRTACTIVE);
	if (MitCrdFrtAvail == comp->MitCrdFrtAvail) insert(items, MITCRDFRTAVAIL);
	if (MitCrdFrtActive == comp->MitCrdFrtActive) insert(items, MITCRDFRTACTIVE);
	if (MitCrdWcoAvail == comp->MitCrdWcoAvail) insert(items, MITCRDWCOAVAIL);
	if (MitCrdWcoActive == comp->MitCrdWcoActive) insert(items, MITCRDWCOACTIVE);

	return(items);
};

set<uint> CrdWdbeRls::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFDLGFINREPTR, SCRJREFDLGNEW, SCRJREFDLGSTAREPTR, SCRJREFDLGWRITE, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDSRTAVAIL, MITCRDSRTACTIVE, MITCRDCRTAVAIL, MITCRDCRTACTIVE, MITCRDFRTAVAIL, MITCRDFRTACTIVE, MITCRDWCOAVAIL, MITCRDWCOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWdbeRls::Tag
 ******************************************************************************/

CrdWdbeRls::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
			, const string& MitCrdNew
			, const string& MitCrdSrt
			, const string& MitCrdCrt
			, const string& MitCrdFrt
			, const string& MitCrdWco
		) :
			Block()
		{
	this->MitAppAbt = MitAppAbt;
	this->MrlAppHlp = MrlAppHlp;
	this->MitCrdNew = MitCrdNew;
	this->MitCrdSrt = MitCrdSrt;
	this->MitCrdCrt = MitCrdCrt;
	this->MitCrdFrt = MitCrdFrt;
	this->MitCrdWco = MitCrdWco;

	mask = {MITAPPABT, MRLAPPHLP, MITCRDNEW, MITCRDSRT, MITCRDCRT, MITCRDFRT, MITCRDWCO};
};

bool CrdWdbeRls::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeRls");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeRls";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdNew", MitCrdNew)) add(MITCRDNEW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdSrt", MitCrdSrt)) add(MITCRDSRT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdCrt", MitCrdCrt)) add(MITCRDCRT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdFrt", MitCrdFrt)) add(MITCRDFRT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdWco", MitCrdWco)) add(MITCRDWCO);
	};

	return basefound;
};

/******************************************************************************
 class CrdWdbeRls::DpchAppDo
 ******************************************************************************/

CrdWdbeRls::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBERLSDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string CrdWdbeRls::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWdbeRls::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeRlsDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWdbeRls::DpchEngData
 ******************************************************************************/

CrdWdbeRls::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBERLSDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string CrdWdbeRls::DpchEngData::getSrefsMask() {
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

void CrdWdbeRls::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeRlsData");
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

