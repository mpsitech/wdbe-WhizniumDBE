/**
	* \file PnlWdbePplDetail.cpp
	* API code for job PnlWdbePplDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#include "PnlWdbePplDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbePplDetail::VecVDo
 ******************************************************************************/

uint PnlWdbePplDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "buthsmviewclick") return BUTHSMVIEWCLICK;
	if (s == "butclkviewclick") return BUTCLKVIEWCLICK;
	if (s == "butclgviewclick") return BUTCLGVIEWCLICK;
	if (s == "butasrviewclick") return BUTASRVIEWCLICK;

	return(0);
};

string PnlWdbePplDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTHSMVIEWCLICK) return("ButHsmViewClick");
	if (ix == BUTCLKVIEWCLICK) return("ButClkViewClick");
	if (ix == BUTCLGVIEWCLICK) return("ButClgViewClick");
	if (ix == BUTASRVIEWCLICK) return("ButAsrViewClick");

	return("");
};

/******************************************************************************
 class PnlWdbePplDetail::ContIac
 ******************************************************************************/

PnlWdbePplDetail::ContIac::ContIac(
			const string& TxfClk
			, const string& TxfClg
			, const string& TxfAsr
			, const string& TxfDpt
			, const string& TxfCmt
		) :
			Block()
		{
	this->TxfClk = TxfClk;
	this->TxfClg = TxfClg;
	this->TxfAsr = TxfAsr;
	this->TxfDpt = TxfDpt;
	this->TxfCmt = TxfCmt;

	mask = {TXFCLK, TXFCLG, TXFASR, TXFDPT, TXFCMT};
};

bool PnlWdbePplDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbePplDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbePplDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfClk", TxfClk)) add(TXFCLK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfClg", TxfClg)) add(TXFCLG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAsr", TxfAsr)) add(TXFASR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDpt", TxfDpt)) add(TXFDPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWdbePplDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbePplDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbePplDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfClk", TxfClk);
		writeStringAttr(wr, itemtag, "sref", "TxfClg", TxfClg);
		writeStringAttr(wr, itemtag, "sref", "TxfAsr", TxfAsr);
		writeStringAttr(wr, itemtag, "sref", "TxfDpt", TxfDpt);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbePplDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfClk == comp->TxfClk) insert(items, TXFCLK);
	if (TxfClg == comp->TxfClg) insert(items, TXFCLG);
	if (TxfAsr == comp->TxfAsr) insert(items, TXFASR);
	if (TxfDpt == comp->TxfDpt) insert(items, TXFDPT);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWdbePplDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFCLK, TXFCLG, TXFASR, TXFDPT, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePplDetail::ContInf
 ******************************************************************************/

PnlWdbePplDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtHsm
			, const string& TxtClk
			, const string& TxtClg
			, const string& TxtAsr
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtHsm = TxtHsm;
	this->TxtClk = TxtClk;
	this->TxtClg = TxtClg;
	this->TxtAsr = TxtAsr;

	mask = {TXTSRF, TXTHSM, TXTCLK, TXTCLG, TXTASR};
};

bool PnlWdbePplDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbePplDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbePplDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtHsm", TxtHsm)) add(TXTHSM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtClk", TxtClk)) add(TXTCLK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtClg", TxtClg)) add(TXTCLG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtAsr", TxtAsr)) add(TXTASR);
	};

	return basefound;
};

set<uint> PnlWdbePplDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtHsm == comp->TxtHsm) insert(items, TXTHSM);
	if (TxtClk == comp->TxtClk) insert(items, TXTCLK);
	if (TxtClg == comp->TxtClg) insert(items, TXTCLG);
	if (TxtAsr == comp->TxtAsr) insert(items, TXTASR);

	return(items);
};

set<uint> PnlWdbePplDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTHSM, TXTCLK, TXTCLG, TXTASR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePplDetail::StatApp
 ******************************************************************************/

PnlWdbePplDetail::StatApp::StatApp(
			const uint ixWdbeVExpstate
			, const bool TxtClkAlt
			, const bool TxtClgAlt
			, const bool TxtAsrAlt
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->TxtClkAlt = TxtClkAlt;
	this->TxtClgAlt = TxtClgAlt;
	this->TxtAsrAlt = TxtAsrAlt;

	mask = {IXWDBEVEXPSTATE, TXTCLKALT, TXTCLGALT, TXTASRALT};
};

bool PnlWdbePplDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbePplDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbePplDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtClkAlt", TxtClkAlt)) add(TXTCLKALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtClgAlt", TxtClgAlt)) add(TXTCLGALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtAsrAlt", TxtAsrAlt)) add(TXTASRALT);
	};

	return basefound;
};

set<uint> PnlWdbePplDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (TxtClkAlt == comp->TxtClkAlt) insert(items, TXTCLKALT);
	if (TxtClgAlt == comp->TxtClgAlt) insert(items, TXTCLGALT);
	if (TxtAsrAlt == comp->TxtAsrAlt) insert(items, TXTASRALT);

	return(items);
};

set<uint> PnlWdbePplDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, TXTCLKALT, TXTCLGALT, TXTASRALT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePplDetail::StatShr
 ******************************************************************************/

PnlWdbePplDetail::StatShr::StatShr(
			const bool TxfClkValid
			, const bool TxfClgValid
			, const bool TxfAsrValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxtHsmActive
			, const bool ButHsmViewAvail
			, const bool ButHsmViewActive
			, const bool TxtClkActive
			, const bool ButClkViewAvail
			, const bool TxtClgActive
			, const bool ButClgViewAvail
			, const bool TxtAsrActive
			, const bool ButAsrViewAvail
			, const bool TxfDptActive
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->TxfClkValid = TxfClkValid;
	this->TxfClgValid = TxfClgValid;
	this->TxfAsrValid = TxfAsrValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxtHsmActive = TxtHsmActive;
	this->ButHsmViewAvail = ButHsmViewAvail;
	this->ButHsmViewActive = ButHsmViewActive;
	this->TxtClkActive = TxtClkActive;
	this->ButClkViewAvail = ButClkViewAvail;
	this->TxtClgActive = TxtClgActive;
	this->ButClgViewAvail = ButClgViewAvail;
	this->TxtAsrActive = TxtAsrActive;
	this->ButAsrViewAvail = ButAsrViewAvail;
	this->TxfDptActive = TxfDptActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {TXFCLKVALID, TXFCLGVALID, TXFASRVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTHSMACTIVE, BUTHSMVIEWAVAIL, BUTHSMVIEWACTIVE, TXTCLKACTIVE, BUTCLKVIEWAVAIL, TXTCLGACTIVE, BUTCLGVIEWAVAIL, TXTASRACTIVE, BUTASRVIEWAVAIL, TXFDPTACTIVE, TXFCMTACTIVE};
};

bool PnlWdbePplDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbePplDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbePplDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfClkValid", TxfClkValid)) add(TXFCLKVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfClgValid", TxfClgValid)) add(TXFCLGVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAsrValid", TxfAsrValid)) add(TXFASRVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtHsmActive", TxtHsmActive)) add(TXTHSMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButHsmViewAvail", ButHsmViewAvail)) add(BUTHSMVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButHsmViewActive", ButHsmViewActive)) add(BUTHSMVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtClkActive", TxtClkActive)) add(TXTCLKACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButClkViewAvail", ButClkViewAvail)) add(BUTCLKVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtClgActive", TxtClgActive)) add(TXTCLGACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButClgViewAvail", ButClgViewAvail)) add(BUTCLGVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtAsrActive", TxtAsrActive)) add(TXTASRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButAsrViewAvail", ButAsrViewAvail)) add(BUTASRVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfDptActive", TxfDptActive)) add(TXFDPTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbePplDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfClkValid == comp->TxfClkValid) insert(items, TXFCLKVALID);
	if (TxfClgValid == comp->TxfClgValid) insert(items, TXFCLGVALID);
	if (TxfAsrValid == comp->TxfAsrValid) insert(items, TXFASRVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxtHsmActive == comp->TxtHsmActive) insert(items, TXTHSMACTIVE);
	if (ButHsmViewAvail == comp->ButHsmViewAvail) insert(items, BUTHSMVIEWAVAIL);
	if (ButHsmViewActive == comp->ButHsmViewActive) insert(items, BUTHSMVIEWACTIVE);
	if (TxtClkActive == comp->TxtClkActive) insert(items, TXTCLKACTIVE);
	if (ButClkViewAvail == comp->ButClkViewAvail) insert(items, BUTCLKVIEWAVAIL);
	if (TxtClgActive == comp->TxtClgActive) insert(items, TXTCLGACTIVE);
	if (ButClgViewAvail == comp->ButClgViewAvail) insert(items, BUTCLGVIEWAVAIL);
	if (TxtAsrActive == comp->TxtAsrActive) insert(items, TXTASRACTIVE);
	if (ButAsrViewAvail == comp->ButAsrViewAvail) insert(items, BUTASRVIEWAVAIL);
	if (TxfDptActive == comp->TxfDptActive) insert(items, TXFDPTACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWdbePplDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFCLKVALID, TXFCLGVALID, TXFASRVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTHSMACTIVE, BUTHSMVIEWAVAIL, BUTHSMVIEWACTIVE, TXTCLKACTIVE, BUTCLKVIEWAVAIL, TXTCLGACTIVE, BUTCLGVIEWAVAIL, TXTASRACTIVE, BUTASRVIEWAVAIL, TXFDPTACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePplDetail::Tag
 ******************************************************************************/

PnlWdbePplDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptHsm
			, const string& CptClk
			, const string& CptClg
			, const string& CptAsr
			, const string& CptDpt
			, const string& CptCmt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptHsm = CptHsm;
	this->CptClk = CptClk;
	this->CptClg = CptClg;
	this->CptAsr = CptAsr;
	this->CptDpt = CptDpt;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTSRF, CPTHSM, CPTCLK, CPTCLG, CPTASR, CPTDPT, CPTCMT};
};

bool PnlWdbePplDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbePplDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbePplDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptHsm", CptHsm)) add(CPTHSM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptClk", CptClk)) add(CPTCLK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptClg", CptClg)) add(CPTCLG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAsr", CptAsr)) add(CPTASR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDpt", CptDpt)) add(CPTDPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbePplDetail::DpchAppData
 ******************************************************************************/

PnlWdbePplDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPPLDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbePplDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePplDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbePplDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePplDetail::DpchAppDo
 ******************************************************************************/

PnlWdbePplDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPPLDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbePplDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePplDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbePplDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePplDetail::DpchEngData
 ******************************************************************************/

PnlWdbePplDetail::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEPPLDETAILDATA)
		{
};

string PnlWdbePplDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePplDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbePplDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
