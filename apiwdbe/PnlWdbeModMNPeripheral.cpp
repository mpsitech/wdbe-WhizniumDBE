/**
	* \file PnlWdbeModMNPeripheral.cpp
	* API code for job PnlWdbeModMNPeripheral (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 13 Oct 2021
	*/
// IP header --- ABOVE

#include "PnlWdbeModMNPeripheral.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeModMNPeripheral::VecVDo
 ******************************************************************************/

uint PnlWdbeModMNPeripheral::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butviewclick") return BUTVIEWCLICK;
	if (s == "butaddclick") return BUTADDCLICK;
	if (s == "butsubclick") return BUTSUBCLICK;
	if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlWdbeModMNPeripheral::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTVIEWCLICK) return("ButViewClick");
	if (ix == BUTADDCLICK) return("ButAddClick");
	if (ix == BUTSUBCLICK) return("ButSubClick");
	if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlWdbeModMNPeripheral::ContInf
 ******************************************************************************/

PnlWdbeModMNPeripheral::ContInf::ContInf(
			const uint numFCsiQst
		) :
			Block()
		{
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

bool PnlWdbeModMNPeripheral::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeModMNPeripheral");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeModMNPeripheral";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFCsiQst", numFCsiQst)) add(NUMFCSIQST);
	};

	return basefound;
};

set<uint> PnlWdbeModMNPeripheral::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlWdbeModMNPeripheral::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFCSIQST};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeModMNPeripheral::StatApp
 ******************************************************************************/

PnlWdbeModMNPeripheral::StatApp::StatApp(
			const uint ixWdbeVExpstate
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;

	mask = {IXWDBEVEXPSTATE};
};

bool PnlWdbeModMNPeripheral::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeModMNPeripheral");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeModMNPeripheral";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWdbeModMNPeripheral::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);

	return(items);
};

set<uint> PnlWdbeModMNPeripheral::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeModMNPeripheral::StatShr
 ******************************************************************************/

PnlWdbeModMNPeripheral::StatShr::StatShr(
			const bool ButViewAvail
			, const bool ButViewActive
			, const bool ButAddAvail
			, const bool ButSubAvail
			, const bool ButSubActive
		) :
			Block()
		{
	this->ButViewAvail = ButViewAvail;
	this->ButViewActive = ButViewActive;
	this->ButAddAvail = ButAddAvail;
	this->ButSubAvail = ButSubAvail;
	this->ButSubActive = ButSubActive;

	mask = {BUTVIEWAVAIL, BUTVIEWACTIVE, BUTADDAVAIL, BUTSUBAVAIL, BUTSUBACTIVE};
};

bool PnlWdbeModMNPeripheral::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeModMNPeripheral");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeModMNPeripheral";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButViewAvail", ButViewAvail)) add(BUTVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButViewActive", ButViewActive)) add(BUTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButAddAvail", ButAddAvail)) add(BUTADDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSubAvail", ButSubAvail)) add(BUTSUBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSubActive", ButSubActive)) add(BUTSUBACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbeModMNPeripheral::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButViewAvail == comp->ButViewAvail) insert(items, BUTVIEWAVAIL);
	if (ButViewActive == comp->ButViewActive) insert(items, BUTVIEWACTIVE);
	if (ButAddAvail == comp->ButAddAvail) insert(items, BUTADDAVAIL);
	if (ButSubAvail == comp->ButSubAvail) insert(items, BUTSUBAVAIL);
	if (ButSubActive == comp->ButSubActive) insert(items, BUTSUBACTIVE);

	return(items);
};

set<uint> PnlWdbeModMNPeripheral::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTVIEWAVAIL, BUTVIEWACTIVE, BUTADDAVAIL, BUTSUBAVAIL, BUTSUBACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeModMNPeripheral::StgIac
 ******************************************************************************/

PnlWdbeModMNPeripheral::StgIac::StgIac(
			const uint TcoMrefWidth
		) :
			Block()
		{
	this->TcoMrefWidth = TcoMrefWidth;

	mask = {TCOMREFWIDTH};
};

bool PnlWdbeModMNPeripheral::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacWdbeModMNPeripheral");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacWdbeModMNPeripheral";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoMrefWidth", TcoMrefWidth)) add(TCOMREFWIDTH);
	};

	return basefound;
};

void PnlWdbeModMNPeripheral::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacWdbeModMNPeripheral";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacWdbeModMNPeripheral";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoMrefWidth", TcoMrefWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeModMNPeripheral::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoMrefWidth == comp->TcoMrefWidth) insert(items, TCOMREFWIDTH);

	return(items);
};

set<uint> PnlWdbeModMNPeripheral::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOMREFWIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeModMNPeripheral::Tag
 ******************************************************************************/

PnlWdbeModMNPeripheral::Tag::Tag(
			const string& Cpt
			, const string& TxtRecord1
			, const string& TxtRecord2
			, const string& Trs
			, const string& TxtShowing1
			, const string& TxtShowing2
			, const string& TcoMref
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->TxtRecord1 = TxtRecord1;
	this->TxtRecord2 = TxtRecord2;
	this->Trs = Trs;
	this->TxtShowing1 = TxtShowing1;
	this->TxtShowing2 = TxtShowing2;
	this->TcoMref = TcoMref;

	mask = {CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOMREF};
};

bool PnlWdbeModMNPeripheral::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeModMNPeripheral");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeModMNPeripheral";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtRecord1", TxtRecord1)) add(TXTRECORD1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtRecord2", TxtRecord2)) add(TXTRECORD2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Trs", Trs)) add(TRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing1", TxtShowing1)) add(TXTSHOWING1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing2", TxtShowing2)) add(TXTSHOWING2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoMref", TcoMref)) add(TCOMREF);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeModMNPeripheral::DpchAppData
 ******************************************************************************/

PnlWdbeModMNPeripheral::DpchAppData::DpchAppData(
			const string& scrJref
			, StgIac* stgiac
			, QryWdbeModMNPeripheral::StgIac* stgiacqry
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEMODMNPERIPHERALDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, STGIAC, STGIACQRY};
	else this->mask = mask;

		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
		if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlWdbeModMNPeripheral::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeModMNPeripheral::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeModMNPeripheralData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeModMNPeripheral::DpchAppDo
 ******************************************************************************/

PnlWdbeModMNPeripheral::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEMODMNPERIPHERALDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbeModMNPeripheral::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeModMNPeripheral::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeModMNPeripheralDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeModMNPeripheral::DpchEngData
 ******************************************************************************/

PnlWdbeModMNPeripheral::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEMODMNPERIPHERALDATA)
		{
	feedFCsiQst.tag = "FeedFCsiQst";
};

string PnlWdbeModMNPeripheral::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFCSIQST)) ss.push_back("feedFCsiQst");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(TAG)) ss.push_back("tag");
	if (has(RST)) ss.push_back("rst");
	if (has(STATAPPQRY)) ss.push_back("statappqry");
	if (has(STATSHRQRY)) ss.push_back("statshrqry");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeModMNPeripheral::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeModMNPeripheralData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFCsiQst.readXML(docctx, basexpath, true)) add(FEEDFCSIQST);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (rst.readXML(docctx, basexpath, true)) add(RST);
		if (statappqry.readXML(docctx, basexpath, true)) add(STATAPPQRY);
		if (statshrqry.readXML(docctx, basexpath, true)) add(STATSHRQRY);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		continf = ContInf();
		feedFCsiQst.clear();
		statapp = StatApp();
		statshr = StatShr();
		stgiac = StgIac();
		tag = Tag();
		rst.clear();
		statappqry = QryWdbeModMNPeripheral::StatApp();
		statshrqry = QryWdbeModMNPeripheral::StatShr();
		stgiacqry = QryWdbeModMNPeripheral::StgIac();
	};
};
