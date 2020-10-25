/**
	* \file PnlWdbePinDetail.cpp
	* API code for job PnlWdbePinDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "PnlWdbePinDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbePinDetail::VecVDo
 ******************************************************************************/

uint PnlWdbePinDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butjsreditclick") return BUTJSREDITCLICK;
	if (s == "butcluviewclick") return BUTCLUVIEWCLICK;
	if (s == "butcluclusterclick") return BUTCLUCLUSTERCLICK;
	if (s == "butcluunclusterclick") return BUTCLUUNCLUSTERCLICK;
	if (s == "butbnkviewclick") return BUTBNKVIEWCLICK;

	return(0);
};

string PnlWdbePinDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTJSREDITCLICK) return("ButJsrEditClick");
	if (ix == BUTCLUVIEWCLICK) return("ButCluViewClick");
	if (ix == BUTCLUCLUSTERCLICK) return("ButCluClusterClick");
	if (ix == BUTCLUUNCLUSTERCLICK) return("ButCluUnclusterClick");
	if (ix == BUTBNKVIEWCLICK) return("ButBnkViewClick");

	return("");
};

/******************************************************************************
 class PnlWdbePinDetail::ContIac
 ******************************************************************************/

PnlWdbePinDetail::ContIac::ContIac(
			const uint numFPupJsr
			, const uint numFLstClu
			, const string& TxfLoc
		) :
			Block()
		{
	this->numFPupJsr = numFPupJsr;
	this->numFLstClu = numFLstClu;
	this->TxfLoc = TxfLoc;

	mask = {NUMFPUPJSR, NUMFLSTCLU, TXFLOC};
};

bool PnlWdbePinDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbePinDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbePinDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJsr", numFPupJsr)) add(NUMFPUPJSR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstClu", numFLstClu)) add(NUMFLSTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfLoc", TxfLoc)) add(TXFLOC);
	};

	return basefound;
};

void PnlWdbePinDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbePinDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbePinDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupJsr", numFPupJsr);
		writeUintAttr(wr, itemtag, "sref", "numFLstClu", numFLstClu);
		writeStringAttr(wr, itemtag, "sref", "TxfLoc", TxfLoc);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbePinDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupJsr == comp->numFPupJsr) insert(items, NUMFPUPJSR);
	if (numFLstClu == comp->numFLstClu) insert(items, NUMFLSTCLU);
	if (TxfLoc == comp->TxfLoc) insert(items, TXFLOC);

	return(items);
};

set<uint> PnlWdbePinDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPJSR, NUMFLSTCLU, TXFLOC};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePinDetail::ContInf
 ******************************************************************************/

PnlWdbePinDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtClu
			, const string& TxtBnk
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtClu = TxtClu;
	this->TxtBnk = TxtBnk;

	mask = {TXTSRF, TXTCLU, TXTBNK};
};

bool PnlWdbePinDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbePinDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbePinDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtClu", TxtClu)) add(TXTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtBnk", TxtBnk)) add(TXTBNK);
	};

	return basefound;
};

set<uint> PnlWdbePinDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtClu == comp->TxtClu) insert(items, TXTCLU);
	if (TxtBnk == comp->TxtBnk) insert(items, TXTBNK);

	return(items);
};

set<uint> PnlWdbePinDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTCLU, TXTBNK};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePinDetail::StatApp
 ******************************************************************************/

PnlWdbePinDetail::StatApp::StatApp(
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

bool PnlWdbePinDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbePinDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbePinDetail";

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

set<uint> PnlWdbePinDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (LstCluAlt == comp->LstCluAlt) insert(items, LSTCLUALT);
	if (LstCluNumFirstdisp == comp->LstCluNumFirstdisp) insert(items, LSTCLUNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWdbePinDetail::StatApp::diff(
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
 class PnlWdbePinDetail::StatShr
 ******************************************************************************/

PnlWdbePinDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool PupJsrActive
			, const bool ButJsrEditAvail
			, const bool TxtSrfActive
			, const bool LstCluActive
			, const bool ButCluViewActive
			, const bool ButCluClusterAvail
			, const bool ButCluUnclusterAvail
			, const bool TxtBnkActive
			, const bool ButBnkViewAvail
			, const bool ButBnkViewActive
			, const bool TxfLocActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->PupJsrActive = PupJsrActive;
	this->ButJsrEditAvail = ButJsrEditAvail;
	this->TxtSrfActive = TxtSrfActive;
	this->LstCluActive = LstCluActive;
	this->ButCluViewActive = ButCluViewActive;
	this->ButCluClusterAvail = ButCluClusterAvail;
	this->ButCluUnclusterAvail = ButCluUnclusterAvail;
	this->TxtBnkActive = TxtBnkActive;
	this->ButBnkViewAvail = ButBnkViewAvail;
	this->ButBnkViewActive = ButBnkViewActive;
	this->TxfLocActive = TxfLocActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, PUPJSRACTIVE, BUTJSREDITAVAIL, TXTSRFACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTBNKACTIVE, BUTBNKVIEWAVAIL, BUTBNKVIEWACTIVE, TXFLOCACTIVE};
};

bool PnlWdbePinDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbePinDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbePinDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupJsrActive", PupJsrActive)) add(PUPJSRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJsrEditAvail", ButJsrEditAvail)) add(BUTJSREDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluActive", LstCluActive)) add(LSTCLUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluViewActive", ButCluViewActive)) add(BUTCLUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluClusterAvail", ButCluClusterAvail)) add(BUTCLUCLUSTERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluUnclusterAvail", ButCluUnclusterAvail)) add(BUTCLUUNCLUSTERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtBnkActive", TxtBnkActive)) add(TXTBNKACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButBnkViewAvail", ButBnkViewAvail)) add(BUTBNKVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButBnkViewActive", ButBnkViewActive)) add(BUTBNKVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfLocActive", TxfLocActive)) add(TXFLOCACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbePinDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (PupJsrActive == comp->PupJsrActive) insert(items, PUPJSRACTIVE);
	if (ButJsrEditAvail == comp->ButJsrEditAvail) insert(items, BUTJSREDITAVAIL);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (LstCluActive == comp->LstCluActive) insert(items, LSTCLUACTIVE);
	if (ButCluViewActive == comp->ButCluViewActive) insert(items, BUTCLUVIEWACTIVE);
	if (ButCluClusterAvail == comp->ButCluClusterAvail) insert(items, BUTCLUCLUSTERAVAIL);
	if (ButCluUnclusterAvail == comp->ButCluUnclusterAvail) insert(items, BUTCLUUNCLUSTERAVAIL);
	if (TxtBnkActive == comp->TxtBnkActive) insert(items, TXTBNKACTIVE);
	if (ButBnkViewAvail == comp->ButBnkViewAvail) insert(items, BUTBNKVIEWAVAIL);
	if (ButBnkViewActive == comp->ButBnkViewActive) insert(items, BUTBNKVIEWACTIVE);
	if (TxfLocActive == comp->TxfLocActive) insert(items, TXFLOCACTIVE);

	return(items);
};

set<uint> PnlWdbePinDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, PUPJSRACTIVE, BUTJSREDITAVAIL, TXTSRFACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTBNKACTIVE, BUTBNKVIEWAVAIL, BUTBNKVIEWACTIVE, TXFLOCACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePinDetail::Tag
 ******************************************************************************/

PnlWdbePinDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptClu
			, const string& CptBnk
			, const string& CptLoc
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptClu = CptClu;
	this->CptBnk = CptBnk;
	this->CptLoc = CptLoc;

	mask = {CPT, CPTSRF, CPTCLU, CPTBNK, CPTLOC};
};

bool PnlWdbePinDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbePinDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbePinDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptClu", CptClu)) add(CPTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptBnk", CptBnk)) add(CPTBNK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLoc", CptLoc)) add(CPTLOC);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbePinDetail::DpchAppData
 ******************************************************************************/

PnlWdbePinDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPINDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbePinDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePinDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbePinDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePinDetail::DpchAppDo
 ******************************************************************************/

PnlWdbePinDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPINDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbePinDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePinDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbePinDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePinDetail::DpchEngData
 ******************************************************************************/

PnlWdbePinDetail::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEPINDETAILDATA)
		{
	feedFLstClu.tag = "FeedFLstClu";
	feedFPupJsr.tag = "FeedFPupJsr";
};

string PnlWdbePinDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTCLU)) ss.push_back("feedFLstClu");
	if (has(FEEDFPUPJSR)) ss.push_back("feedFPupJsr");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePinDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbePinDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstClu.readXML(docctx, basexpath, true)) add(FEEDFLSTCLU);
		if (feedFPupJsr.readXML(docctx, basexpath, true)) add(FEEDFPUPJSR);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstClu.clear();
		feedFPupJsr.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

