/**
	* \file PnlWdbeSegDetail.cpp
	* API code for job PnlWdbeSegDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#include "PnlWdbeSegDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeSegDetail::VecVDo
 ******************************************************************************/

uint PnlWdbeSegDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butcluviewclick") return BUTCLUVIEWCLICK;
	if (s == "butcluclusterclick") return BUTCLUCLUSTERCLICK;
	if (s == "butcluunclusterclick") return BUTCLUUNCLUSTERCLICK;
	if (s == "butpplviewclick") return BUTPPLVIEWCLICK;
	if (s == "butsupviewclick") return BUTSUPVIEWCLICK;

	return(0);
};

string PnlWdbeSegDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTCLUVIEWCLICK) return("ButCluViewClick");
	if (ix == BUTCLUCLUSTERCLICK) return("ButCluClusterClick");
	if (ix == BUTCLUUNCLUSTERCLICK) return("ButCluUnclusterClick");
	if (ix == BUTPPLVIEWCLICK) return("ButPplViewClick");
	if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");

	return("");
};

/******************************************************************************
 class PnlWdbeSegDetail::ContIac
 ******************************************************************************/

PnlWdbeSegDetail::ContIac::ContIac(
			const uint numFLstClu
			, const string& TxfIfm
			, const string& TxfOfm
			, const string& TxfLcy
			, const string& TxfCmt
		) :
			Block()
		{
	this->numFLstClu = numFLstClu;
	this->TxfIfm = TxfIfm;
	this->TxfOfm = TxfOfm;
	this->TxfLcy = TxfLcy;
	this->TxfCmt = TxfCmt;

	mask = {NUMFLSTCLU, TXFIFM, TXFOFM, TXFLCY, TXFCMT};
};

bool PnlWdbeSegDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeSegDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeSegDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstClu", numFLstClu)) add(NUMFLSTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfIfm", TxfIfm)) add(TXFIFM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfOfm", TxfOfm)) add(TXFOFM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfLcy", TxfLcy)) add(TXFLCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWdbeSegDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeSegDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeSegDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstClu", numFLstClu);
		writeStringAttr(wr, itemtag, "sref", "TxfIfm", TxfIfm);
		writeStringAttr(wr, itemtag, "sref", "TxfOfm", TxfOfm);
		writeStringAttr(wr, itemtag, "sref", "TxfLcy", TxfLcy);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeSegDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstClu == comp->numFLstClu) insert(items, NUMFLSTCLU);
	if (TxfIfm == comp->TxfIfm) insert(items, TXFIFM);
	if (TxfOfm == comp->TxfOfm) insert(items, TXFOFM);
	if (TxfLcy == comp->TxfLcy) insert(items, TXFLCY);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWdbeSegDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTCLU, TXFIFM, TXFOFM, TXFLCY, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeSegDetail::ContInf
 ******************************************************************************/

PnlWdbeSegDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtClu
			, const string& TxtPpl
			, const string& TxtSup
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtClu = TxtClu;
	this->TxtPpl = TxtPpl;
	this->TxtSup = TxtSup;

	mask = {TXTSRF, TXTCLU, TXTPPL, TXTSUP};
};

bool PnlWdbeSegDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeSegDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeSegDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtClu", TxtClu)) add(TXTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPpl", TxtPpl)) add(TXTPPL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSup", TxtSup)) add(TXTSUP);
	};

	return basefound;
};

set<uint> PnlWdbeSegDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtClu == comp->TxtClu) insert(items, TXTCLU);
	if (TxtPpl == comp->TxtPpl) insert(items, TXTPPL);
	if (TxtSup == comp->TxtSup) insert(items, TXTSUP);

	return(items);
};

set<uint> PnlWdbeSegDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTCLU, TXTPPL, TXTSUP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeSegDetail::StatApp
 ******************************************************************************/

PnlWdbeSegDetail::StatApp::StatApp(
			const uint ixWdbeVExpstate
			, const bool LstCluAlt
			, const uint LstCluNumFirstdisp
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->LstCluAlt = LstCluAlt;
	this->LstCluNumFirstdisp = LstCluNumFirstdisp;

	mask = {IXWDBEVEXPSTATE, LSTCLUALT, LSTCLUNUMFIRSTDISP};
};

bool PnlWdbeSegDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeSegDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeSegDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluAlt", LstCluAlt)) add(LSTCLUALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluNumFirstdisp", LstCluNumFirstdisp)) add(LSTCLUNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWdbeSegDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (LstCluAlt == comp->LstCluAlt) insert(items, LSTCLUALT);
	if (LstCluNumFirstdisp == comp->LstCluNumFirstdisp) insert(items, LSTCLUNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWdbeSegDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, LSTCLUALT, LSTCLUNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeSegDetail::StatShr
 ******************************************************************************/

PnlWdbeSegDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool LstCluActive
			, const bool ButCluViewActive
			, const bool ButCluClusterAvail
			, const bool ButCluUnclusterAvail
			, const bool TxtPplActive
			, const bool ButPplViewAvail
			, const bool ButPplViewActive
			, const bool TxtSupActive
			, const bool ButSupViewAvail
			, const bool ButSupViewActive
			, const bool TxfIfmActive
			, const bool TxfOfmActive
			, const bool TxfLcyActive
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->LstCluActive = LstCluActive;
	this->ButCluViewActive = ButCluViewActive;
	this->ButCluClusterAvail = ButCluClusterAvail;
	this->ButCluUnclusterAvail = ButCluUnclusterAvail;
	this->TxtPplActive = TxtPplActive;
	this->ButPplViewAvail = ButPplViewAvail;
	this->ButPplViewActive = ButPplViewActive;
	this->TxtSupActive = TxtSupActive;
	this->ButSupViewAvail = ButSupViewAvail;
	this->ButSupViewActive = ButSupViewActive;
	this->TxfIfmActive = TxfIfmActive;
	this->TxfOfmActive = TxfOfmActive;
	this->TxfLcyActive = TxfLcyActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTPPLACTIVE, BUTPPLVIEWAVAIL, BUTPPLVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXFIFMACTIVE, TXFOFMACTIVE, TXFLCYACTIVE, TXFCMTACTIVE};
};

bool PnlWdbeSegDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeSegDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeSegDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluActive", LstCluActive)) add(LSTCLUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluViewActive", ButCluViewActive)) add(BUTCLUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluClusterAvail", ButCluClusterAvail)) add(BUTCLUCLUSTERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluUnclusterAvail", ButCluUnclusterAvail)) add(BUTCLUUNCLUSTERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPplActive", TxtPplActive)) add(TXTPPLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPplViewAvail", ButPplViewAvail)) add(BUTPPLVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPplViewActive", ButPplViewActive)) add(BUTPPLVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSupActive", TxtSupActive)) add(TXTSUPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSupViewAvail", ButSupViewAvail)) add(BUTSUPVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSupViewActive", ButSupViewActive)) add(BUTSUPVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfIfmActive", TxfIfmActive)) add(TXFIFMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfOfmActive", TxfOfmActive)) add(TXFOFMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfLcyActive", TxfLcyActive)) add(TXFLCYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbeSegDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (LstCluActive == comp->LstCluActive) insert(items, LSTCLUACTIVE);
	if (ButCluViewActive == comp->ButCluViewActive) insert(items, BUTCLUVIEWACTIVE);
	if (ButCluClusterAvail == comp->ButCluClusterAvail) insert(items, BUTCLUCLUSTERAVAIL);
	if (ButCluUnclusterAvail == comp->ButCluUnclusterAvail) insert(items, BUTCLUUNCLUSTERAVAIL);
	if (TxtPplActive == comp->TxtPplActive) insert(items, TXTPPLACTIVE);
	if (ButPplViewAvail == comp->ButPplViewAvail) insert(items, BUTPPLVIEWAVAIL);
	if (ButPplViewActive == comp->ButPplViewActive) insert(items, BUTPPLVIEWACTIVE);
	if (TxtSupActive == comp->TxtSupActive) insert(items, TXTSUPACTIVE);
	if (ButSupViewAvail == comp->ButSupViewAvail) insert(items, BUTSUPVIEWAVAIL);
	if (ButSupViewActive == comp->ButSupViewActive) insert(items, BUTSUPVIEWACTIVE);
	if (TxfIfmActive == comp->TxfIfmActive) insert(items, TXFIFMACTIVE);
	if (TxfOfmActive == comp->TxfOfmActive) insert(items, TXFOFMACTIVE);
	if (TxfLcyActive == comp->TxfLcyActive) insert(items, TXFLCYACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWdbeSegDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTPPLACTIVE, BUTPPLVIEWAVAIL, BUTPPLVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXFIFMACTIVE, TXFOFMACTIVE, TXFLCYACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeSegDetail::Tag
 ******************************************************************************/

PnlWdbeSegDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptClu
			, const string& CptPpl
			, const string& CptSup
			, const string& CptIfm
			, const string& CptOfm
			, const string& CptLcy
			, const string& CptCmt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptClu = CptClu;
	this->CptPpl = CptPpl;
	this->CptSup = CptSup;
	this->CptIfm = CptIfm;
	this->CptOfm = CptOfm;
	this->CptLcy = CptLcy;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTSRF, CPTCLU, CPTPPL, CPTSUP, CPTIFM, CPTOFM, CPTLCY, CPTCMT};
};

bool PnlWdbeSegDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeSegDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeSegDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptClu", CptClu)) add(CPTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPpl", CptPpl)) add(CPTPPL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSup", CptSup)) add(CPTSUP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptIfm", CptIfm)) add(CPTIFM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOfm", CptOfm)) add(CPTOFM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLcy", CptLcy)) add(CPTLCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeSegDetail::DpchAppData
 ******************************************************************************/

PnlWdbeSegDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBESEGDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbeSegDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeSegDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeSegDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeSegDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeSegDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBESEGDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbeSegDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeSegDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeSegDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeSegDetail::DpchEngData
 ******************************************************************************/

PnlWdbeSegDetail::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBESEGDETAILDATA)
		{
	feedFLstClu.tag = "FeedFLstClu";
};

string PnlWdbeSegDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTCLU)) ss.push_back("feedFLstClu");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeSegDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeSegDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstClu.readXML(docctx, basexpath, true)) add(FEEDFLSTCLU);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstClu.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
