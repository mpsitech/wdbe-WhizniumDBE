/**
	* \file PnlWdbeSnsDetail.cpp
	* API code for job PnlWdbeSnsDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#include "PnlWdbeSnsDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeSnsDetail::VecVDo
 ******************************************************************************/

uint PnlWdbeSnsDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butreuviewclick") return BUTREUVIEWCLICK;
	if (s == "butsruviewclick") return BUTSRUVIEWCLICK;

	return(0);
};

string PnlWdbeSnsDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");
	if (ix == BUTSRUVIEWCLICK) return("ButSruViewClick");

	return("");
};

/******************************************************************************
 class PnlWdbeSnsDetail::ContIac
 ******************************************************************************/

PnlWdbeSnsDetail::ContIac::ContIac(
			const uint numFPupRet
			, const uint numFPupSrt
		) :
			Block()
		{
	this->numFPupRet = numFPupRet;
	this->numFPupSrt = numFPupSrt;

	mask = {NUMFPUPRET, NUMFPUPSRT};
};

bool PnlWdbeSnsDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeSnsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeSnsDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRet", numFPupRet)) add(NUMFPUPRET);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSrt", numFPupSrt)) add(NUMFPUPSRT);
	};

	return basefound;
};

void PnlWdbeSnsDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeSnsDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeSnsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupRet", numFPupRet);
		writeUintAttr(wr, itemtag, "sref", "numFPupSrt", numFPupSrt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeSnsDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupRet == comp->numFPupRet) insert(items, NUMFPUPRET);
	if (numFPupSrt == comp->numFPupSrt) insert(items, NUMFPUPSRT);

	return(items);
};

set<uint> PnlWdbeSnsDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPRET, NUMFPUPSRT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeSnsDetail::ContInf
 ******************************************************************************/

PnlWdbeSnsDetail::ContInf::ContInf(
			const string& TxtReu
			, const string& TxtSru
		) :
			Block()
		{
	this->TxtReu = TxtReu;
	this->TxtSru = TxtSru;

	mask = {TXTREU, TXTSRU};
};

bool PnlWdbeSnsDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeSnsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeSnsDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtReu", TxtReu)) add(TXTREU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSru", TxtSru)) add(TXTSRU);
	};

	return basefound;
};

set<uint> PnlWdbeSnsDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtReu == comp->TxtReu) insert(items, TXTREU);
	if (TxtSru == comp->TxtSru) insert(items, TXTSRU);

	return(items);
};

set<uint> PnlWdbeSnsDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTREU, TXTSRU};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeSnsDetail::StatApp
 ******************************************************************************/

PnlWdbeSnsDetail::StatApp::StatApp(
			const uint ixWdbeVExpstate
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;

	mask = {IXWDBEVEXPSTATE};
};

bool PnlWdbeSnsDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeSnsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeSnsDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWdbeSnsDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);

	return(items);
};

set<uint> PnlWdbeSnsDetail::StatApp::diff(
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
 class PnlWdbeSnsDetail::StatShr
 ******************************************************************************/

PnlWdbeSnsDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtReuActive
			, const bool ButReuViewAvail
			, const bool ButReuViewActive
			, const bool TxtSruActive
			, const bool ButSruViewAvail
			, const bool ButSruViewActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtReuActive = TxtReuActive;
	this->ButReuViewAvail = ButReuViewAvail;
	this->ButReuViewActive = ButReuViewActive;
	this->TxtSruActive = TxtSruActive;
	this->ButSruViewAvail = ButSruViewAvail;
	this->ButSruViewActive = ButSruViewActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTSRUACTIVE, BUTSRUVIEWAVAIL, BUTSRUVIEWACTIVE};
};

bool PnlWdbeSnsDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeSnsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeSnsDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtReuActive", TxtReuActive)) add(TXTREUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButReuViewAvail", ButReuViewAvail)) add(BUTREUVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButReuViewActive", ButReuViewActive)) add(BUTREUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSruActive", TxtSruActive)) add(TXTSRUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSruViewAvail", ButSruViewAvail)) add(BUTSRUVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSruViewActive", ButSruViewActive)) add(BUTSRUVIEWACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbeSnsDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtReuActive == comp->TxtReuActive) insert(items, TXTREUACTIVE);
	if (ButReuViewAvail == comp->ButReuViewAvail) insert(items, BUTREUVIEWAVAIL);
	if (ButReuViewActive == comp->ButReuViewActive) insert(items, BUTREUVIEWACTIVE);
	if (TxtSruActive == comp->TxtSruActive) insert(items, TXTSRUACTIVE);
	if (ButSruViewAvail == comp->ButSruViewAvail) insert(items, BUTSRUVIEWAVAIL);
	if (ButSruViewActive == comp->ButSruViewActive) insert(items, BUTSRUVIEWACTIVE);

	return(items);
};

set<uint> PnlWdbeSnsDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTSRUACTIVE, BUTSRUVIEWAVAIL, BUTSRUVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeSnsDetail::Tag
 ******************************************************************************/

PnlWdbeSnsDetail::Tag::Tag(
			const string& Cpt
			, const string& CptReu
			, const string& CptSru
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptReu = CptReu;
	this->CptSru = CptSru;

	mask = {CPT, CPTREU, CPTSRU};
};

bool PnlWdbeSnsDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeSnsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeSnsDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptReu", CptReu)) add(CPTREU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSru", CptSru)) add(CPTSRU);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeSnsDetail::DpchAppData
 ******************************************************************************/

PnlWdbeSnsDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBESNSDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbeSnsDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeSnsDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeSnsDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeSnsDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeSnsDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBESNSDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbeSnsDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeSnsDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeSnsDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeSnsDetail::DpchEngData
 ******************************************************************************/

PnlWdbeSnsDetail::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBESNSDETAILDATA)
		{
	feedFPupRet.tag = "FeedFPupRet";
	feedFPupSrt.tag = "FeedFPupSrt";
};

string PnlWdbeSnsDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPRET)) ss.push_back("feedFPupRet");
	if (has(FEEDFPUPSRT)) ss.push_back("feedFPupSrt");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeSnsDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeSnsDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupRet.readXML(docctx, basexpath, true)) add(FEEDFPUPRET);
		if (feedFPupSrt.readXML(docctx, basexpath, true)) add(FEEDFPUPSRT);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupRet.clear();
		feedFPupSrt.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
