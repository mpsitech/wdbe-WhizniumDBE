/**
	* \file CrdWdbeCvr.cpp
	* API code for job CrdWdbeCvr (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "CrdWdbeCvr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWdbeCvr::VecVDo
 ******************************************************************************/

uint CrdWdbeCvr::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitcrdnewclick") return MITCRDNEWCLICK;
	if (s == "mitcrdibsclick") return MITCRDIBSCLICK;
	if (s == "mitcrdidsclick") return MITCRDIDSCLICK;
	if (s == "mitcrdwcoclick") return MITCRDWCOCLICK;

	return(0);
};

string CrdWdbeCvr::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITCRDNEWCLICK) return("MitCrdNewClick");
	if (ix == MITCRDIBSCLICK) return("MitCrdIbsClick");
	if (ix == MITCRDIDSCLICK) return("MitCrdIdsClick");
	if (ix == MITCRDWCOCLICK) return("MitCrdWcoClick");

	return("");
};

/******************************************************************************
 class CrdWdbeCvr::VecVSge
 ******************************************************************************/

uint CrdWdbeCvr::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwdbeabt") return ALRWDBEABT;

	return(0);
};

string CrdWdbeCvr::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWDBEABT) return("alrwdbeabt");

	return("");
};

/******************************************************************************
 class CrdWdbeCvr::ContInf
 ******************************************************************************/

CrdWdbeCvr::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdCvr
		) :
			Block()
			, numFSge(numFSge)
			, MrlAppHlp(MrlAppHlp)
			, MtxCrdCvr(MtxCrdCvr)
		{
	mask = {NUMFSGE, MRLAPPHLP, MTXCRDCVR};
};

bool CrdWdbeCvr::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeCvr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeCvr";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxCrdCvr", MtxCrdCvr)) add(MTXCRDCVR);
	};

	return basefound;
};

set<uint> CrdWdbeCvr::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxCrdCvr == comp->MtxCrdCvr) insert(items, MTXCRDCVR);

	return(items);
};

set<uint> CrdWdbeCvr::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDCVR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWdbeCvr::StatApp
 ******************************************************************************/

CrdWdbeCvr::StatApp::StatApp(
			const uint ixWdbeVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) :
			Block()
			, ixWdbeVReqitmode(ixWdbeVReqitmode)
			, latency(latency)
			, shortMenu(shortMenu)
			, widthMenu(widthMenu)
			, initdoneHeadbar(initdoneHeadbar)
			, initdoneList(initdoneList)
			, initdoneRec(initdoneRec)
		{
	mask = {IXWDBEVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC};
};

bool CrdWdbeCvr::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeCvr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeCvr";

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

set<uint> CrdWdbeCvr::StatApp::comm(
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

set<uint> CrdWdbeCvr::StatApp::diff(
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
 class CrdWdbeCvr::StatShr
 ******************************************************************************/

CrdWdbeCvr::StatShr::StatShr(
			const string& scrJrefDlgbsccd
			, const string& scrJrefDlgdetcd
			, const string& scrJrefDlgnew
			, const string& scrJrefDlgwrite
			, const string& scrJrefHeadbar
			, const string& scrJrefList
			, const string& scrJrefRec
			, const bool MspCrd1Avail
			, const bool MitCrdNewAvail
			, const bool MitCrdIbsAvail
			, const bool MitCrdIbsActive
			, const bool MitCrdIdsAvail
			, const bool MitCrdIdsActive
			, const bool MspCrd2Avail
			, const bool MitCrdWcoAvail
			, const bool MitCrdWcoActive
		) :
			Block()
			, scrJrefDlgbsccd(scrJrefDlgbsccd)
			, scrJrefDlgdetcd(scrJrefDlgdetcd)
			, scrJrefDlgnew(scrJrefDlgnew)
			, scrJrefDlgwrite(scrJrefDlgwrite)
			, scrJrefHeadbar(scrJrefHeadbar)
			, scrJrefList(scrJrefList)
			, scrJrefRec(scrJrefRec)
			, MspCrd1Avail(MspCrd1Avail)
			, MitCrdNewAvail(MitCrdNewAvail)
			, MitCrdIbsAvail(MitCrdIbsAvail)
			, MitCrdIbsActive(MitCrdIbsActive)
			, MitCrdIdsAvail(MitCrdIdsAvail)
			, MitCrdIdsActive(MitCrdIdsActive)
			, MspCrd2Avail(MspCrd2Avail)
			, MitCrdWcoAvail(MitCrdWcoAvail)
			, MitCrdWcoActive(MitCrdWcoActive)
		{
	mask = {SCRJREFDLGBSCCD, SCRJREFDLGDETCD, SCRJREFDLGNEW, SCRJREFDLGWRITE, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDIBSAVAIL, MITCRDIBSACTIVE, MITCRDIDSAVAIL, MITCRDIDSACTIVE, MSPCRD2AVAIL, MITCRDWCOAVAIL, MITCRDWCOACTIVE};
};

bool CrdWdbeCvr::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeCvr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeCvr";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgbsccd", scrJrefDlgbsccd)) add(SCRJREFDLGBSCCD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgdetcd", scrJrefDlgdetcd)) add(SCRJREFDLGDETCD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgnew", scrJrefDlgnew)) add(SCRJREFDLGNEW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgwrite", scrJrefDlgwrite)) add(SCRJREFDLGWRITE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefList", scrJrefList)) add(SCRJREFLIST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRec", scrJrefRec)) add(SCRJREFREC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", MspCrd1Avail)) add(MSPCRD1AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdNewAvail", MitCrdNewAvail)) add(MITCRDNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIbsAvail", MitCrdIbsAvail)) add(MITCRDIBSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIbsActive", MitCrdIbsActive)) add(MITCRDIBSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIdsAvail", MitCrdIdsAvail)) add(MITCRDIDSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIdsActive", MitCrdIdsActive)) add(MITCRDIDSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd2Avail", MspCrd2Avail)) add(MSPCRD2AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdWcoAvail", MitCrdWcoAvail)) add(MITCRDWCOAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdWcoActive", MitCrdWcoActive)) add(MITCRDWCOACTIVE);
	};

	return basefound;
};

set<uint> CrdWdbeCvr::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefDlgbsccd == comp->scrJrefDlgbsccd) insert(items, SCRJREFDLGBSCCD);
	if (scrJrefDlgdetcd == comp->scrJrefDlgdetcd) insert(items, SCRJREFDLGDETCD);
	if (scrJrefDlgnew == comp->scrJrefDlgnew) insert(items, SCRJREFDLGNEW);
	if (scrJrefDlgwrite == comp->scrJrefDlgwrite) insert(items, SCRJREFDLGWRITE);
	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);
	if (scrJrefList == comp->scrJrefList) insert(items, SCRJREFLIST);
	if (scrJrefRec == comp->scrJrefRec) insert(items, SCRJREFREC);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdNewAvail == comp->MitCrdNewAvail) insert(items, MITCRDNEWAVAIL);
	if (MitCrdIbsAvail == comp->MitCrdIbsAvail) insert(items, MITCRDIBSAVAIL);
	if (MitCrdIbsActive == comp->MitCrdIbsActive) insert(items, MITCRDIBSACTIVE);
	if (MitCrdIdsAvail == comp->MitCrdIdsAvail) insert(items, MITCRDIDSAVAIL);
	if (MitCrdIdsActive == comp->MitCrdIdsActive) insert(items, MITCRDIDSACTIVE);
	if (MspCrd2Avail == comp->MspCrd2Avail) insert(items, MSPCRD2AVAIL);
	if (MitCrdWcoAvail == comp->MitCrdWcoAvail) insert(items, MITCRDWCOAVAIL);
	if (MitCrdWcoActive == comp->MitCrdWcoActive) insert(items, MITCRDWCOACTIVE);

	return(items);
};

set<uint> CrdWdbeCvr::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFDLGBSCCD, SCRJREFDLGDETCD, SCRJREFDLGNEW, SCRJREFDLGWRITE, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDIBSAVAIL, MITCRDIBSACTIVE, MITCRDIDSAVAIL, MITCRDIDSACTIVE, MSPCRD2AVAIL, MITCRDWCOAVAIL, MITCRDWCOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWdbeCvr::Tag
 ******************************************************************************/

CrdWdbeCvr::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
			, const string& MitCrdNew
			, const string& MitCrdIbs
			, const string& MitCrdIds
			, const string& MitCrdWco
		) :
			Block()
			, MitAppAbt(MitAppAbt)
			, MrlAppHlp(MrlAppHlp)
			, MitCrdNew(MitCrdNew)
			, MitCrdIbs(MitCrdIbs)
			, MitCrdIds(MitCrdIds)
			, MitCrdWco(MitCrdWco)
		{
	mask = {MITAPPABT, MRLAPPHLP, MITCRDNEW, MITCRDIBS, MITCRDIDS, MITCRDWCO};
};

bool CrdWdbeCvr::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeCvr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeCvr";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdNew", MitCrdNew)) add(MITCRDNEW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdIbs", MitCrdIbs)) add(MITCRDIBS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdIds", MitCrdIds)) add(MITCRDIDS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdWco", MitCrdWco)) add(MITCRDWCO);
	};

	return basefound;
};

/******************************************************************************
 class CrdWdbeCvr::DpchAppDo
 ******************************************************************************/

CrdWdbeCvr::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBECVRDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string CrdWdbeCvr::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWdbeCvr::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeCvrDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWdbeCvr::DpchEngData
 ******************************************************************************/

CrdWdbeCvr::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBECVRDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string CrdWdbeCvr::DpchEngData::getSrefsMask() {
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

void CrdWdbeCvr::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeCvrData");
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
