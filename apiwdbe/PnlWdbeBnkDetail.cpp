/**
	* \file PnlWdbeBnkDetail.cpp
	* API code for job PnlWdbeBnkDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWdbeBnkDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeBnkDetail::VecVDo
 ******************************************************************************/

uint PnlWdbeBnkDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butuntviewclick") return BUTUNTVIEWCLICK;
	if (s == "butvsteditclick") return BUTVSTEDITCLICK;

	return(0);
};

string PnlWdbeBnkDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTUNTVIEWCLICK) return("ButUntViewClick");
	if (ix == BUTVSTEDITCLICK) return("ButVstEditClick");

	return("");
};

/******************************************************************************
 class PnlWdbeBnkDetail::ContIac
 ******************************************************************************/

PnlWdbeBnkDetail::ContIac::ContIac(
			const uint numFPupVst
			, const string& TxfVst
		) :
			Block()
			, numFPupVst(numFPupVst)
			, TxfVst(TxfVst)
		{
	mask = {NUMFPUPVST, TXFVST};
};

bool PnlWdbeBnkDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeBnkDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeBnkDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupVst", numFPupVst)) add(NUMFPUPVST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfVst", TxfVst)) add(TXFVST);
	};

	return basefound;
};

void PnlWdbeBnkDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeBnkDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeBnkDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupVst", numFPupVst);
		writeStringAttr(wr, itemtag, "sref", "TxfVst", TxfVst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeBnkDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupVst == comp->numFPupVst) insert(items, NUMFPUPVST);
	if (TxfVst == comp->TxfVst) insert(items, TXFVST);

	return(items);
};

set<uint> PnlWdbeBnkDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPVST, TXFVST};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeBnkDetail::ContInf
 ******************************************************************************/

PnlWdbeBnkDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtUnt
		) :
			Block()
			, TxtSrf(TxtSrf)
			, TxtUnt(TxtUnt)
		{
	mask = {TXTSRF, TXTUNT};
};

bool PnlWdbeBnkDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeBnkDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeBnkDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtUnt", TxtUnt)) add(TXTUNT);
	};

	return basefound;
};

set<uint> PnlWdbeBnkDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtUnt == comp->TxtUnt) insert(items, TXTUNT);

	return(items);
};

set<uint> PnlWdbeBnkDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTUNT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeBnkDetail::StatApp
 ******************************************************************************/

PnlWdbeBnkDetail::StatApp::StatApp(
			const uint ixWdbeVExpstate
			, const bool PupVstAlt
		) :
			Block()
			, ixWdbeVExpstate(ixWdbeVExpstate)
			, PupVstAlt(PupVstAlt)
		{
	mask = {IXWDBEVEXPSTATE, PUPVSTALT};
};

bool PnlWdbeBnkDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeBnkDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeBnkDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupVstAlt", PupVstAlt)) add(PUPVSTALT);
	};

	return basefound;
};

set<uint> PnlWdbeBnkDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (PupVstAlt == comp->PupVstAlt) insert(items, PUPVSTALT);

	return(items);
};

set<uint> PnlWdbeBnkDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, PUPVSTALT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeBnkDetail::StatShr
 ******************************************************************************/

PnlWdbeBnkDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxtUntActive
			, const bool ButUntViewAvail
			, const bool ButUntViewActive
			, const bool PupVstActive
			, const bool TxfVstValid
			, const bool ButVstEditAvail
		) :
			Block()
			, ButSaveAvail(ButSaveAvail)
			, ButSaveActive(ButSaveActive)
			, TxtSrfActive(TxtSrfActive)
			, TxtUntActive(TxtUntActive)
			, ButUntViewAvail(ButUntViewAvail)
			, ButUntViewActive(ButUntViewActive)
			, PupVstActive(PupVstActive)
			, TxfVstValid(TxfVstValid)
			, ButVstEditAvail(ButVstEditAvail)
		{
	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTUNTACTIVE, BUTUNTVIEWAVAIL, BUTUNTVIEWACTIVE, PUPVSTACTIVE, TXFVSTVALID, BUTVSTEDITAVAIL};
};

bool PnlWdbeBnkDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeBnkDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeBnkDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtUntActive", TxtUntActive)) add(TXTUNTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUntViewAvail", ButUntViewAvail)) add(BUTUNTVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUntViewActive", ButUntViewActive)) add(BUTUNTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupVstActive", PupVstActive)) add(PUPVSTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfVstValid", TxfVstValid)) add(TXFVSTVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVstEditAvail", ButVstEditAvail)) add(BUTVSTEDITAVAIL);
	};

	return basefound;
};

set<uint> PnlWdbeBnkDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxtUntActive == comp->TxtUntActive) insert(items, TXTUNTACTIVE);
	if (ButUntViewAvail == comp->ButUntViewAvail) insert(items, BUTUNTVIEWAVAIL);
	if (ButUntViewActive == comp->ButUntViewActive) insert(items, BUTUNTVIEWACTIVE);
	if (PupVstActive == comp->PupVstActive) insert(items, PUPVSTACTIVE);
	if (TxfVstValid == comp->TxfVstValid) insert(items, TXFVSTVALID);
	if (ButVstEditAvail == comp->ButVstEditAvail) insert(items, BUTVSTEDITAVAIL);

	return(items);
};

set<uint> PnlWdbeBnkDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTUNTACTIVE, BUTUNTVIEWAVAIL, BUTUNTVIEWACTIVE, PUPVSTACTIVE, TXFVSTVALID, BUTVSTEDITAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeBnkDetail::Tag
 ******************************************************************************/

PnlWdbeBnkDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptUnt
			, const string& CptVst
		) :
			Block()
			, Cpt(Cpt)
			, CptSrf(CptSrf)
			, CptUnt(CptUnt)
			, CptVst(CptVst)
		{
	mask = {CPT, CPTSRF, CPTUNT, CPTVST};
};

bool PnlWdbeBnkDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeBnkDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeBnkDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUnt", CptUnt)) add(CPTUNT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVst", CptVst)) add(CPTVST);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeBnkDetail::DpchAppData
 ******************************************************************************/

PnlWdbeBnkDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEBNKDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbeBnkDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeBnkDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeBnkDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeBnkDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeBnkDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEBNKDETAILDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWdbeBnkDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeBnkDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeBnkDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeBnkDetail::DpchEngData
 ******************************************************************************/

PnlWdbeBnkDetail::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEBNKDETAILDATA)
		{
	feedFPupVst.tag = "FeedFPupVst";
};

string PnlWdbeBnkDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPVST)) ss.push_back("feedFPupVst");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeBnkDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeBnkDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupVst.readXML(docctx, basexpath, true)) add(FEEDFPUPVST);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupVst.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
