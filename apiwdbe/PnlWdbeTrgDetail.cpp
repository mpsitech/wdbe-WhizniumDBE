/**
	* \file PnlWdbeTrgDetail.cpp
	* API code for job PnlWdbeTrgDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWdbeTrgDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeTrgDetail::VecVDo
 ******************************************************************************/

uint PnlWdbeTrgDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butsysviewclick") return BUTSYSVIEWCLICK;
	if (s == "butuntviewclick") return BUTUNTVIEWCLICK;

	return(0);
};

string PnlWdbeTrgDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTSYSVIEWCLICK) return("ButSysViewClick");
	if (ix == BUTUNTVIEWCLICK) return("ButUntViewClick");

	return("");
};

/******************************************************************************
 class PnlWdbeTrgDetail::ContIac
 ******************************************************************************/

PnlWdbeTrgDetail::ContIac::ContIac(
			const uint numFLstRte
			, const string& TxfRte
			, const string& TxfCmt
		) :
			Block()
		{
	this->numFLstRte = numFLstRte;
	this->TxfRte = TxfRte;
	this->TxfCmt = TxfCmt;

	mask = {NUMFLSTRTE, TXFRTE, TXFCMT};
};

bool PnlWdbeTrgDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeTrgDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeTrgDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstRte", numFLstRte)) add(NUMFLSTRTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfRte", TxfRte)) add(TXFRTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWdbeTrgDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeTrgDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeTrgDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstRte", numFLstRte);
		writeStringAttr(wr, itemtag, "sref", "TxfRte", TxfRte);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeTrgDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstRte == comp->numFLstRte) insert(items, NUMFLSTRTE);
	if (TxfRte == comp->TxfRte) insert(items, TXFRTE);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWdbeTrgDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTRTE, TXFRTE, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeTrgDetail::ContInf
 ******************************************************************************/

PnlWdbeTrgDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtSys
			, const string& TxtUnt
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtSys = TxtSys;
	this->TxtUnt = TxtUnt;

	mask = {TXTSRF, TXTSYS, TXTUNT};
};

bool PnlWdbeTrgDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeTrgDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeTrgDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSys", TxtSys)) add(TXTSYS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtUnt", TxtUnt)) add(TXTUNT);
	};

	return basefound;
};

set<uint> PnlWdbeTrgDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtSys == comp->TxtSys) insert(items, TXTSYS);
	if (TxtUnt == comp->TxtUnt) insert(items, TXTUNT);

	return(items);
};

set<uint> PnlWdbeTrgDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTSYS, TXTUNT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeTrgDetail::StatApp
 ******************************************************************************/

PnlWdbeTrgDetail::StatApp::StatApp(
			const uint ixWdbeVExpstate
			, const bool LstRteAlt
			, const uint LstRteNumFirstdisp
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->LstRteAlt = LstRteAlt;
	this->LstRteNumFirstdisp = LstRteNumFirstdisp;

	mask = {IXWDBEVEXPSTATE, LSTRTEALT, LSTRTENUMFIRSTDISP};
};

bool PnlWdbeTrgDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeTrgDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeTrgDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRteAlt", LstRteAlt)) add(LSTRTEALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRteNumFirstdisp", LstRteNumFirstdisp)) add(LSTRTENUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWdbeTrgDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (LstRteAlt == comp->LstRteAlt) insert(items, LSTRTEALT);
	if (LstRteNumFirstdisp == comp->LstRteNumFirstdisp) insert(items, LSTRTENUMFIRSTDISP);

	return(items);
};

set<uint> PnlWdbeTrgDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, LSTRTEALT, LSTRTENUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeTrgDetail::StatShr
 ******************************************************************************/

PnlWdbeTrgDetail::StatShr::StatShr(
			const bool TxfRteValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxtSysActive
			, const bool ButSysViewAvail
			, const bool ButSysViewActive
			, const bool TxtUntActive
			, const bool ButUntViewAvail
			, const bool ButUntViewActive
			, const bool LstRteActive
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->TxfRteValid = TxfRteValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxtSysActive = TxtSysActive;
	this->ButSysViewAvail = ButSysViewAvail;
	this->ButSysViewActive = ButSysViewActive;
	this->TxtUntActive = TxtUntActive;
	this->ButUntViewAvail = ButUntViewAvail;
	this->ButUntViewActive = ButUntViewActive;
	this->LstRteActive = LstRteActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {TXFRTEVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTSYSACTIVE, BUTSYSVIEWAVAIL, BUTSYSVIEWACTIVE, TXTUNTACTIVE, BUTUNTVIEWAVAIL, BUTUNTVIEWACTIVE, LSTRTEACTIVE, TXFCMTACTIVE};
};

bool PnlWdbeTrgDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeTrgDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeTrgDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfRteValid", TxfRteValid)) add(TXFRTEVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSysActive", TxtSysActive)) add(TXTSYSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSysViewAvail", ButSysViewAvail)) add(BUTSYSVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSysViewActive", ButSysViewActive)) add(BUTSYSVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtUntActive", TxtUntActive)) add(TXTUNTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUntViewAvail", ButUntViewAvail)) add(BUTUNTVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUntViewActive", ButUntViewActive)) add(BUTUNTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRteActive", LstRteActive)) add(LSTRTEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbeTrgDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfRteValid == comp->TxfRteValid) insert(items, TXFRTEVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxtSysActive == comp->TxtSysActive) insert(items, TXTSYSACTIVE);
	if (ButSysViewAvail == comp->ButSysViewAvail) insert(items, BUTSYSVIEWAVAIL);
	if (ButSysViewActive == comp->ButSysViewActive) insert(items, BUTSYSVIEWACTIVE);
	if (TxtUntActive == comp->TxtUntActive) insert(items, TXTUNTACTIVE);
	if (ButUntViewAvail == comp->ButUntViewAvail) insert(items, BUTUNTVIEWAVAIL);
	if (ButUntViewActive == comp->ButUntViewActive) insert(items, BUTUNTVIEWACTIVE);
	if (LstRteActive == comp->LstRteActive) insert(items, LSTRTEACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWdbeTrgDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFRTEVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTSYSACTIVE, BUTSYSVIEWAVAIL, BUTSYSVIEWACTIVE, TXTUNTACTIVE, BUTUNTVIEWAVAIL, BUTUNTVIEWACTIVE, LSTRTEACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeTrgDetail::Tag
 ******************************************************************************/

PnlWdbeTrgDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptSys
			, const string& CptUnt
			, const string& CptRte
			, const string& CptCmt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptSys = CptSys;
	this->CptUnt = CptUnt;
	this->CptRte = CptRte;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTSRF, CPTSYS, CPTUNT, CPTRTE, CPTCMT};
};

bool PnlWdbeTrgDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeTrgDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeTrgDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSys", CptSys)) add(CPTSYS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUnt", CptUnt)) add(CPTUNT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptRte", CptRte)) add(CPTRTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeTrgDetail::DpchAppData
 ******************************************************************************/

PnlWdbeTrgDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBETRGDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbeTrgDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeTrgDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeTrgDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeTrgDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeTrgDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBETRGDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbeTrgDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeTrgDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeTrgDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeTrgDetail::DpchEngData
 ******************************************************************************/

PnlWdbeTrgDetail::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBETRGDETAILDATA)
		{
	feedFLstRte.tag = "FeedFLstRte";
};

string PnlWdbeTrgDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTRTE)) ss.push_back("feedFLstRte");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeTrgDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeTrgDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstRte.readXML(docctx, basexpath, true)) add(FEEDFLSTRTE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstRte.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
