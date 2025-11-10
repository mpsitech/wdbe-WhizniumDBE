/**
	* \file PnlWdbeCvrDetail.cpp
	* API code for job PnlWdbeCvrDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWdbeCvrDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeCvrDetail::VecVDo
 ******************************************************************************/

uint PnlWdbeCvrDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butcprviewclick") return BUTCPRVIEWCLICK;
	if (s == "butbcvviewclick") return BUTBCVVIEWCLICK;
	if (s == "butjsteditclick") return BUTJSTEDITCLICK;

	return(0);
};

string PnlWdbeCvrDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTCPRVIEWCLICK) return("ButCprViewClick");
	if (ix == BUTBCVVIEWCLICK) return("ButBcvViewClick");
	if (ix == BUTJSTEDITCLICK) return("ButJstEditClick");

	return("");
};

/******************************************************************************
 class PnlWdbeCvrDetail::ContIac
 ******************************************************************************/

PnlWdbeCvrDetail::ContIac::ContIac(
			const string& TxfMaj
			, const string& TxfMin
			, const string& TxfSub
			, const uint numFPupJst
			, const uint numFPupSte
			, const vector<uint>& numsFLstSty
		) :
			Block()
			, TxfMaj(TxfMaj)
			, TxfMin(TxfMin)
			, TxfSub(TxfSub)
			, numFPupJst(numFPupJst)
			, numFPupSte(numFPupSte)
			, numsFLstSty(numsFLstSty)
		{
	mask = {TXFMAJ, TXFMIN, TXFSUB, NUMFPUPJST, NUMFPUPSTE, NUMSFLSTSTY};
};

bool PnlWdbeCvrDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeCvrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeCvrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfMaj", TxfMaj)) add(TXFMAJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfMin", TxfMin)) add(TXFMIN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSub", TxfSub)) add(TXFSUB);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJst", numFPupJst)) add(NUMFPUPJST);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSte", numFPupSte)) add(NUMFPUPSTE);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstSty", numsFLstSty)) add(NUMSFLSTSTY);
	};

	return basefound;
};

void PnlWdbeCvrDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeCvrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeCvrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfMaj", TxfMaj);
		writeStringAttr(wr, itemtag, "sref", "TxfMin", TxfMin);
		writeStringAttr(wr, itemtag, "sref", "TxfSub", TxfSub);
		writeUintAttr(wr, itemtag, "sref", "numFPupJst", numFPupJst);
		writeUintAttr(wr, itemtag, "sref", "numFPupSte", numFPupSte);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstSty", numsFLstSty);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeCvrDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfMaj == comp->TxfMaj) insert(items, TXFMAJ);
	if (TxfMin == comp->TxfMin) insert(items, TXFMIN);
	if (TxfSub == comp->TxfSub) insert(items, TXFSUB);
	if (numFPupJst == comp->numFPupJst) insert(items, NUMFPUPJST);
	if (numFPupSte == comp->numFPupSte) insert(items, NUMFPUPSTE);
	if (compareUintvec(numsFLstSty, comp->numsFLstSty)) insert(items, NUMSFLSTSTY);

	return(items);
};

set<uint> PnlWdbeCvrDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFMAJ, TXFMIN, TXFSUB, NUMFPUPJST, NUMFPUPSTE, NUMSFLSTSTY};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeCvrDetail::ContInf
 ******************************************************************************/

PnlWdbeCvrDetail::ContInf::ContInf(
			const string& TxtCpr
			, const string& TxtBcv
			, const string& TxtSty
		) :
			Block()
			, TxtCpr(TxtCpr)
			, TxtBcv(TxtBcv)
			, TxtSty(TxtSty)
		{
	mask = {TXTCPR, TXTBCV, TXTSTY};
};

bool PnlWdbeCvrDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeCvrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeCvrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCpr", TxtCpr)) add(TXTCPR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtBcv", TxtBcv)) add(TXTBCV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSty", TxtSty)) add(TXTSTY);
	};

	return basefound;
};

set<uint> PnlWdbeCvrDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtCpr == comp->TxtCpr) insert(items, TXTCPR);
	if (TxtBcv == comp->TxtBcv) insert(items, TXTBCV);
	if (TxtSty == comp->TxtSty) insert(items, TXTSTY);

	return(items);
};

set<uint> PnlWdbeCvrDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTCPR, TXTBCV, TXTSTY};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeCvrDetail::StatApp
 ******************************************************************************/

PnlWdbeCvrDetail::StatApp::StatApp(
			const uint ixWdbeVExpstate
			, const bool LstStyAlt
			, const uint LstStyNumFirstdisp
		) :
			Block()
			, ixWdbeVExpstate(ixWdbeVExpstate)
			, LstStyAlt(LstStyAlt)
			, LstStyNumFirstdisp(LstStyNumFirstdisp)
		{
	mask = {IXWDBEVEXPSTATE, LSTSTYALT, LSTSTYNUMFIRSTDISP};
};

bool PnlWdbeCvrDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeCvrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeCvrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstStyAlt", LstStyAlt)) add(LSTSTYALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstStyNumFirstdisp", LstStyNumFirstdisp)) add(LSTSTYNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWdbeCvrDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (LstStyAlt == comp->LstStyAlt) insert(items, LSTSTYALT);
	if (LstStyNumFirstdisp == comp->LstStyNumFirstdisp) insert(items, LSTSTYNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWdbeCvrDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, LSTSTYALT, LSTSTYNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeCvrDetail::StatShr
 ******************************************************************************/

PnlWdbeCvrDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtCprActive
			, const bool ButCprViewAvail
			, const bool ButCprViewActive
			, const bool TxfMajActive
			, const bool TxfMinActive
			, const bool TxfSubActive
			, const bool TxtBcvActive
			, const bool ButBcvViewAvail
			, const bool ButBcvViewActive
			, const bool PupJstActive
			, const bool ButJstEditAvail
			, const bool PupSteActive
			, const bool LstStyActive
		) :
			Block()
			, ButSaveAvail(ButSaveAvail)
			, ButSaveActive(ButSaveActive)
			, TxtCprActive(TxtCprActive)
			, ButCprViewAvail(ButCprViewAvail)
			, ButCprViewActive(ButCprViewActive)
			, TxfMajActive(TxfMajActive)
			, TxfMinActive(TxfMinActive)
			, TxfSubActive(TxfSubActive)
			, TxtBcvActive(TxtBcvActive)
			, ButBcvViewAvail(ButBcvViewAvail)
			, ButBcvViewActive(ButBcvViewActive)
			, PupJstActive(PupJstActive)
			, ButJstEditAvail(ButJstEditAvail)
			, PupSteActive(PupSteActive)
			, LstStyActive(LstStyActive)
		{
	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTCPRACTIVE, BUTCPRVIEWAVAIL, BUTCPRVIEWACTIVE, TXFMAJACTIVE, TXFMINACTIVE, TXFSUBACTIVE, TXTBCVACTIVE, BUTBCVVIEWAVAIL, BUTBCVVIEWACTIVE, PUPJSTACTIVE, BUTJSTEDITAVAIL, PUPSTEACTIVE, LSTSTYACTIVE};
};

bool PnlWdbeCvrDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeCvrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeCvrDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCprActive", TxtCprActive)) add(TXTCPRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCprViewAvail", ButCprViewAvail)) add(BUTCPRVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCprViewActive", ButCprViewActive)) add(BUTCPRVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfMajActive", TxfMajActive)) add(TXFMAJACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfMinActive", TxfMinActive)) add(TXFMINACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfSubActive", TxfSubActive)) add(TXFSUBACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtBcvActive", TxtBcvActive)) add(TXTBCVACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButBcvViewAvail", ButBcvViewAvail)) add(BUTBCVVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButBcvViewActive", ButBcvViewActive)) add(BUTBCVVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupJstActive", PupJstActive)) add(PUPJSTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJstEditAvail", ButJstEditAvail)) add(BUTJSTEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupSteActive", PupSteActive)) add(PUPSTEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstStyActive", LstStyActive)) add(LSTSTYACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbeCvrDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtCprActive == comp->TxtCprActive) insert(items, TXTCPRACTIVE);
	if (ButCprViewAvail == comp->ButCprViewAvail) insert(items, BUTCPRVIEWAVAIL);
	if (ButCprViewActive == comp->ButCprViewActive) insert(items, BUTCPRVIEWACTIVE);
	if (TxfMajActive == comp->TxfMajActive) insert(items, TXFMAJACTIVE);
	if (TxfMinActive == comp->TxfMinActive) insert(items, TXFMINACTIVE);
	if (TxfSubActive == comp->TxfSubActive) insert(items, TXFSUBACTIVE);
	if (TxtBcvActive == comp->TxtBcvActive) insert(items, TXTBCVACTIVE);
	if (ButBcvViewAvail == comp->ButBcvViewAvail) insert(items, BUTBCVVIEWAVAIL);
	if (ButBcvViewActive == comp->ButBcvViewActive) insert(items, BUTBCVVIEWACTIVE);
	if (PupJstActive == comp->PupJstActive) insert(items, PUPJSTACTIVE);
	if (ButJstEditAvail == comp->ButJstEditAvail) insert(items, BUTJSTEDITAVAIL);
	if (PupSteActive == comp->PupSteActive) insert(items, PUPSTEACTIVE);
	if (LstStyActive == comp->LstStyActive) insert(items, LSTSTYACTIVE);

	return(items);
};

set<uint> PnlWdbeCvrDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTCPRACTIVE, BUTCPRVIEWAVAIL, BUTCPRVIEWACTIVE, TXFMAJACTIVE, TXFMINACTIVE, TXFSUBACTIVE, TXTBCVACTIVE, BUTBCVVIEWAVAIL, BUTBCVVIEWACTIVE, PUPJSTACTIVE, BUTJSTEDITAVAIL, PUPSTEACTIVE, LSTSTYACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeCvrDetail::Tag
 ******************************************************************************/

PnlWdbeCvrDetail::Tag::Tag(
			const string& Cpt
			, const string& CptCpr
			, const string& CptMaj
			, const string& CptMin
			, const string& CptSub
			, const string& CptBcv
			, const string& CptSte
			, const string& CptSty
		) :
			Block()
			, Cpt(Cpt)
			, CptCpr(CptCpr)
			, CptMaj(CptMaj)
			, CptMin(CptMin)
			, CptSub(CptSub)
			, CptBcv(CptBcv)
			, CptSte(CptSte)
			, CptSty(CptSty)
		{
	mask = {CPT, CPTCPR, CPTMAJ, CPTMIN, CPTSUB, CPTBCV, CPTSTE, CPTSTY};
};

bool PnlWdbeCvrDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeCvrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeCvrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCpr", CptCpr)) add(CPTCPR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMaj", CptMaj)) add(CPTMAJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMin", CptMin)) add(CPTMIN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSub", CptSub)) add(CPTSUB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptBcv", CptBcv)) add(CPTBCV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSte", CptSte)) add(CPTSTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSty", CptSty)) add(CPTSTY);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeCvrDetail::DpchAppData
 ******************************************************************************/

PnlWdbeCvrDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBECVRDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbeCvrDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeCvrDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeCvrDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeCvrDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeCvrDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBECVRDETAILDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWdbeCvrDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeCvrDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeCvrDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeCvrDetail::DpchEngData
 ******************************************************************************/

PnlWdbeCvrDetail::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBECVRDETAILDATA)
		{
	feedFLstSty.tag = "FeedFLstSty";
	feedFPupJst.tag = "FeedFPupJst";
	feedFPupSte.tag = "FeedFPupSte";
};

string PnlWdbeCvrDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTSTY)) ss.push_back("feedFLstSty");
	if (has(FEEDFPUPJST)) ss.push_back("feedFPupJst");
	if (has(FEEDFPUPSTE)) ss.push_back("feedFPupSte");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeCvrDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeCvrDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstSty.readXML(docctx, basexpath, true)) add(FEEDFLSTSTY);
		if (feedFPupJst.readXML(docctx, basexpath, true)) add(FEEDFPUPJST);
		if (feedFPupSte.readXML(docctx, basexpath, true)) add(FEEDFPUPSTE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstSty.clear();
		feedFPupJst.clear();
		feedFPupSte.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
