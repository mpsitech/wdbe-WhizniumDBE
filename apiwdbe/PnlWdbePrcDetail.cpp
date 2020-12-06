/**
	* \file PnlWdbePrcDetail.cpp
	* API code for job PnlWdbePrcDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWdbePrcDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbePrcDetail::VecVDo
 ******************************************************************************/

uint PnlWdbePrcDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butmdlviewclick") return BUTMDLVIEWCLICK;
	if (s == "butclkviewclick") return BUTCLKVIEWCLICK;
	if (s == "butasrviewclick") return BUTASRVIEWCLICK;
	if (s == "butfsmnewclick") return BUTFSMNEWCLICK;
	if (s == "butfsmdeleteclick") return BUTFSMDELETECLICK;

	return(0);
};

string PnlWdbePrcDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTMDLVIEWCLICK) return("ButMdlViewClick");
	if (ix == BUTCLKVIEWCLICK) return("ButClkViewClick");
	if (ix == BUTASRVIEWCLICK) return("ButAsrViewClick");
	if (ix == BUTFSMNEWCLICK) return("ButFsmNewClick");
	if (ix == BUTFSMDELETECLICK) return("ButFsmDeleteClick");

	return("");
};

/******************************************************************************
 class PnlWdbePrcDetail::ContIac
 ******************************************************************************/

PnlWdbePrcDetail::ContIac::ContIac(
			const string& TxfClk
			, const string& TxfAsr
			, const bool ChkFal
			, const string& TxfSnr
			, const bool ChkEip
			, const string& TxfCmt
		) :
			Block()
		{
	this->TxfClk = TxfClk;
	this->TxfAsr = TxfAsr;
	this->ChkFal = ChkFal;
	this->TxfSnr = TxfSnr;
	this->ChkEip = ChkEip;
	this->TxfCmt = TxfCmt;

	mask = {TXFCLK, TXFASR, CHKFAL, TXFSNR, CHKEIP, TXFCMT};
};

bool PnlWdbePrcDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbePrcDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbePrcDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfClk", TxfClk)) add(TXFCLK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAsr", TxfAsr)) add(TXFASR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkFal", ChkFal)) add(CHKFAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSnr", TxfSnr)) add(TXFSNR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkEip", ChkEip)) add(CHKEIP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWdbePrcDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbePrcDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbePrcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfClk", TxfClk);
		writeStringAttr(wr, itemtag, "sref", "TxfAsr", TxfAsr);
		writeBoolAttr(wr, itemtag, "sref", "ChkFal", ChkFal);
		writeStringAttr(wr, itemtag, "sref", "TxfSnr", TxfSnr);
		writeBoolAttr(wr, itemtag, "sref", "ChkEip", ChkEip);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbePrcDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfClk == comp->TxfClk) insert(items, TXFCLK);
	if (TxfAsr == comp->TxfAsr) insert(items, TXFASR);
	if (ChkFal == comp->ChkFal) insert(items, CHKFAL);
	if (TxfSnr == comp->TxfSnr) insert(items, TXFSNR);
	if (ChkEip == comp->ChkEip) insert(items, CHKEIP);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWdbePrcDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFCLK, TXFASR, CHKFAL, TXFSNR, CHKEIP, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrcDetail::ContInf
 ******************************************************************************/

PnlWdbePrcDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtMdl
			, const string& TxtClk
			, const string& TxtAsr
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtMdl = TxtMdl;
	this->TxtClk = TxtClk;
	this->TxtAsr = TxtAsr;

	mask = {TXTSRF, TXTMDL, TXTCLK, TXTASR};
};

bool PnlWdbePrcDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbePrcDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbePrcDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMdl", TxtMdl)) add(TXTMDL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtClk", TxtClk)) add(TXTCLK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtAsr", TxtAsr)) add(TXTASR);
	};

	return basefound;
};

set<uint> PnlWdbePrcDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtMdl == comp->TxtMdl) insert(items, TXTMDL);
	if (TxtClk == comp->TxtClk) insert(items, TXTCLK);
	if (TxtAsr == comp->TxtAsr) insert(items, TXTASR);

	return(items);
};

set<uint> PnlWdbePrcDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTMDL, TXTCLK, TXTASR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrcDetail::StatApp
 ******************************************************************************/

PnlWdbePrcDetail::StatApp::StatApp(
			const uint ixWdbeVExpstate
			, const bool TxtClkAlt
			, const bool TxtAsrAlt
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->TxtClkAlt = TxtClkAlt;
	this->TxtAsrAlt = TxtAsrAlt;

	mask = {IXWDBEVEXPSTATE, TXTCLKALT, TXTASRALT};
};

bool PnlWdbePrcDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbePrcDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbePrcDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtClkAlt", TxtClkAlt)) add(TXTCLKALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtAsrAlt", TxtAsrAlt)) add(TXTASRALT);
	};

	return basefound;
};

set<uint> PnlWdbePrcDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (TxtClkAlt == comp->TxtClkAlt) insert(items, TXTCLKALT);
	if (TxtAsrAlt == comp->TxtAsrAlt) insert(items, TXTASRALT);

	return(items);
};

set<uint> PnlWdbePrcDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, TXTCLKALT, TXTASRALT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrcDetail::StatShr
 ******************************************************************************/

PnlWdbePrcDetail::StatShr::StatShr(
			const bool TxfClkValid
			, const bool TxfAsrValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxtMdlActive
			, const bool ButMdlViewAvail
			, const bool ButMdlViewActive
			, const bool TxtClkActive
			, const bool ButClkViewAvail
			, const bool TxtAsrActive
			, const bool ButAsrViewAvail
			, const bool ChkFalActive
			, const bool TxfSnrActive
			, const bool ChkEipActive
			, const bool TxfCmtActive
			, const bool ButFsmNewAvail
			, const bool ButFsmDeleteAvail
		) :
			Block()
		{
	this->TxfClkValid = TxfClkValid;
	this->TxfAsrValid = TxfAsrValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxtMdlActive = TxtMdlActive;
	this->ButMdlViewAvail = ButMdlViewAvail;
	this->ButMdlViewActive = ButMdlViewActive;
	this->TxtClkActive = TxtClkActive;
	this->ButClkViewAvail = ButClkViewAvail;
	this->TxtAsrActive = TxtAsrActive;
	this->ButAsrViewAvail = ButAsrViewAvail;
	this->ChkFalActive = ChkFalActive;
	this->TxfSnrActive = TxfSnrActive;
	this->ChkEipActive = ChkEipActive;
	this->TxfCmtActive = TxfCmtActive;
	this->ButFsmNewAvail = ButFsmNewAvail;
	this->ButFsmDeleteAvail = ButFsmDeleteAvail;

	mask = {TXFCLKVALID, TXFASRVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, TXTCLKACTIVE, BUTCLKVIEWAVAIL, TXTASRACTIVE, BUTASRVIEWAVAIL, CHKFALACTIVE, TXFSNRACTIVE, CHKEIPACTIVE, TXFCMTACTIVE, BUTFSMNEWAVAIL, BUTFSMDELETEAVAIL};
};

bool PnlWdbePrcDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbePrcDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbePrcDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfClkValid", TxfClkValid)) add(TXFCLKVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAsrValid", TxfAsrValid)) add(TXFASRVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtMdlActive", TxtMdlActive)) add(TXTMDLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButMdlViewAvail", ButMdlViewAvail)) add(BUTMDLVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButMdlViewActive", ButMdlViewActive)) add(BUTMDLVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtClkActive", TxtClkActive)) add(TXTCLKACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButClkViewAvail", ButClkViewAvail)) add(BUTCLKVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtAsrActive", TxtAsrActive)) add(TXTASRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButAsrViewAvail", ButAsrViewAvail)) add(BUTASRVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkFalActive", ChkFalActive)) add(CHKFALACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfSnrActive", TxfSnrActive)) add(TXFSNRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkEipActive", ChkEipActive)) add(CHKEIPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFsmNewAvail", ButFsmNewAvail)) add(BUTFSMNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFsmDeleteAvail", ButFsmDeleteAvail)) add(BUTFSMDELETEAVAIL);
	};

	return basefound;
};

set<uint> PnlWdbePrcDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfClkValid == comp->TxfClkValid) insert(items, TXFCLKVALID);
	if (TxfAsrValid == comp->TxfAsrValid) insert(items, TXFASRVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxtMdlActive == comp->TxtMdlActive) insert(items, TXTMDLACTIVE);
	if (ButMdlViewAvail == comp->ButMdlViewAvail) insert(items, BUTMDLVIEWAVAIL);
	if (ButMdlViewActive == comp->ButMdlViewActive) insert(items, BUTMDLVIEWACTIVE);
	if (TxtClkActive == comp->TxtClkActive) insert(items, TXTCLKACTIVE);
	if (ButClkViewAvail == comp->ButClkViewAvail) insert(items, BUTCLKVIEWAVAIL);
	if (TxtAsrActive == comp->TxtAsrActive) insert(items, TXTASRACTIVE);
	if (ButAsrViewAvail == comp->ButAsrViewAvail) insert(items, BUTASRVIEWAVAIL);
	if (ChkFalActive == comp->ChkFalActive) insert(items, CHKFALACTIVE);
	if (TxfSnrActive == comp->TxfSnrActive) insert(items, TXFSNRACTIVE);
	if (ChkEipActive == comp->ChkEipActive) insert(items, CHKEIPACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);
	if (ButFsmNewAvail == comp->ButFsmNewAvail) insert(items, BUTFSMNEWAVAIL);
	if (ButFsmDeleteAvail == comp->ButFsmDeleteAvail) insert(items, BUTFSMDELETEAVAIL);

	return(items);
};

set<uint> PnlWdbePrcDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFCLKVALID, TXFASRVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, TXTCLKACTIVE, BUTCLKVIEWAVAIL, TXTASRACTIVE, BUTASRVIEWAVAIL, CHKFALACTIVE, TXFSNRACTIVE, CHKEIPACTIVE, TXFCMTACTIVE, BUTFSMNEWAVAIL, BUTFSMDELETEAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrcDetail::Tag
 ******************************************************************************/

PnlWdbePrcDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptMdl
			, const string& CptClk
			, const string& CptAsr
			, const string& CptFal
			, const string& CptSnr
			, const string& CptEip
			, const string& CptCmt
			, const string& HdgFsm
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptMdl = CptMdl;
	this->CptClk = CptClk;
	this->CptAsr = CptAsr;
	this->CptFal = CptFal;
	this->CptSnr = CptSnr;
	this->CptEip = CptEip;
	this->CptCmt = CptCmt;
	this->HdgFsm = HdgFsm;

	mask = {CPT, CPTSRF, CPTMDL, CPTCLK, CPTASR, CPTFAL, CPTSNR, CPTEIP, CPTCMT, HDGFSM};
};

bool PnlWdbePrcDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbePrcDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbePrcDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMdl", CptMdl)) add(CPTMDL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptClk", CptClk)) add(CPTCLK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAsr", CptAsr)) add(CPTASR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFal", CptFal)) add(CPTFAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSnr", CptSnr)) add(CPTSNR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEip", CptEip)) add(CPTEIP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgFsm", HdgFsm)) add(HDGFSM);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbePrcDetail::DpchAppData
 ******************************************************************************/

PnlWdbePrcDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPRCDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbePrcDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrcDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbePrcDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePrcDetail::DpchAppDo
 ******************************************************************************/

PnlWdbePrcDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPRCDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbePrcDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrcDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbePrcDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePrcDetail::DpchEngData
 ******************************************************************************/

PnlWdbePrcDetail::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEPRCDETAILDATA)
		{
};

string PnlWdbePrcDetail::DpchEngData::getSrefsMask() {
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

void PnlWdbePrcDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbePrcDetailData");
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
