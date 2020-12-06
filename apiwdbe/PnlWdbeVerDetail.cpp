/**
	* \file PnlWdbeVerDetail.cpp
	* API code for job PnlWdbeVerDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWdbeVerDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeVerDetail::VecVDo
 ******************************************************************************/

uint PnlWdbeVerDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butprjviewclick") return BUTPRJVIEWCLICK;
	if (s == "butbvrviewclick") return BUTBVRVIEWCLICK;
	if (s == "butjsteditclick") return BUTJSTEDITCLICK;

	return(0);
};

string PnlWdbeVerDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTPRJVIEWCLICK) return("ButPrjViewClick");
	if (ix == BUTBVRVIEWCLICK) return("ButBvrViewClick");
	if (ix == BUTJSTEDITCLICK) return("ButJstEditClick");

	return("");
};

/******************************************************************************
 class PnlWdbeVerDetail::ContIac
 ******************************************************************************/

PnlWdbeVerDetail::ContIac::ContIac(
			const string& TxfMaj
			, const string& TxfMin
			, const string& TxfSub
			, const uint numFPupJst
			, const uint numFPupSte
			, const string& TxfAbt
			, const string& TxfCmt
		) :
			Block()
		{
	this->TxfMaj = TxfMaj;
	this->TxfMin = TxfMin;
	this->TxfSub = TxfSub;
	this->numFPupJst = numFPupJst;
	this->numFPupSte = numFPupSte;
	this->TxfAbt = TxfAbt;
	this->TxfCmt = TxfCmt;

	mask = {TXFMAJ, TXFMIN, TXFSUB, NUMFPUPJST, NUMFPUPSTE, TXFABT, TXFCMT};
};

bool PnlWdbeVerDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeVerDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeVerDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfMaj", TxfMaj)) add(TXFMAJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfMin", TxfMin)) add(TXFMIN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSub", TxfSub)) add(TXFSUB);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJst", numFPupJst)) add(NUMFPUPJST);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSte", numFPupSte)) add(NUMFPUPSTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAbt", TxfAbt)) add(TXFABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWdbeVerDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeVerDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeVerDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfMaj", TxfMaj);
		writeStringAttr(wr, itemtag, "sref", "TxfMin", TxfMin);
		writeStringAttr(wr, itemtag, "sref", "TxfSub", TxfSub);
		writeUintAttr(wr, itemtag, "sref", "numFPupJst", numFPupJst);
		writeUintAttr(wr, itemtag, "sref", "numFPupSte", numFPupSte);
		writeStringAttr(wr, itemtag, "sref", "TxfAbt", TxfAbt);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeVerDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfMaj == comp->TxfMaj) insert(items, TXFMAJ);
	if (TxfMin == comp->TxfMin) insert(items, TXFMIN);
	if (TxfSub == comp->TxfSub) insert(items, TXFSUB);
	if (numFPupJst == comp->numFPupJst) insert(items, NUMFPUPJST);
	if (numFPupSte == comp->numFPupSte) insert(items, NUMFPUPSTE);
	if (TxfAbt == comp->TxfAbt) insert(items, TXFABT);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWdbeVerDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFMAJ, TXFMIN, TXFSUB, NUMFPUPJST, NUMFPUPSTE, TXFABT, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeVerDetail::ContInf
 ******************************************************************************/

PnlWdbeVerDetail::ContInf::ContInf(
			const string& TxtPrj
			, const string& TxtBvr
		) :
			Block()
		{
	this->TxtPrj = TxtPrj;
	this->TxtBvr = TxtBvr;

	mask = {TXTPRJ, TXTBVR};
};

bool PnlWdbeVerDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeVerDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeVerDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrj", TxtPrj)) add(TXTPRJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtBvr", TxtBvr)) add(TXTBVR);
	};

	return basefound;
};

set<uint> PnlWdbeVerDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtPrj == comp->TxtPrj) insert(items, TXTPRJ);
	if (TxtBvr == comp->TxtBvr) insert(items, TXTBVR);

	return(items);
};

set<uint> PnlWdbeVerDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRJ, TXTBVR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeVerDetail::StatApp
 ******************************************************************************/

PnlWdbeVerDetail::StatApp::StatApp(
			const uint ixWdbeVExpstate
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;

	mask = {IXWDBEVEXPSTATE};
};

bool PnlWdbeVerDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeVerDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeVerDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWdbeVerDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);

	return(items);
};

set<uint> PnlWdbeVerDetail::StatApp::diff(
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
 class PnlWdbeVerDetail::StatShr
 ******************************************************************************/

PnlWdbeVerDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtPrjActive
			, const bool ButPrjViewAvail
			, const bool ButPrjViewActive
			, const bool TxfMajActive
			, const bool TxfMinActive
			, const bool TxfSubActive
			, const bool TxtBvrActive
			, const bool ButBvrViewAvail
			, const bool ButBvrViewActive
			, const bool PupJstActive
			, const bool ButJstEditAvail
			, const bool PupSteActive
			, const bool TxfAbtActive
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtPrjActive = TxtPrjActive;
	this->ButPrjViewAvail = ButPrjViewAvail;
	this->ButPrjViewActive = ButPrjViewActive;
	this->TxfMajActive = TxfMajActive;
	this->TxfMinActive = TxfMinActive;
	this->TxfSubActive = TxfSubActive;
	this->TxtBvrActive = TxtBvrActive;
	this->ButBvrViewAvail = ButBvrViewAvail;
	this->ButBvrViewActive = ButBvrViewActive;
	this->PupJstActive = PupJstActive;
	this->ButJstEditAvail = ButJstEditAvail;
	this->PupSteActive = PupSteActive;
	this->TxfAbtActive = TxfAbtActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTPRJACTIVE, BUTPRJVIEWAVAIL, BUTPRJVIEWACTIVE, TXFMAJACTIVE, TXFMINACTIVE, TXFSUBACTIVE, TXTBVRACTIVE, BUTBVRVIEWAVAIL, BUTBVRVIEWACTIVE, PUPJSTACTIVE, BUTJSTEDITAVAIL, PUPSTEACTIVE, TXFABTACTIVE, TXFCMTACTIVE};
};

bool PnlWdbeVerDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeVerDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeVerDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPrjActive", TxtPrjActive)) add(TXTPRJACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrjViewAvail", ButPrjViewAvail)) add(BUTPRJVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrjViewActive", ButPrjViewActive)) add(BUTPRJVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfMajActive", TxfMajActive)) add(TXFMAJACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfMinActive", TxfMinActive)) add(TXFMINACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfSubActive", TxfSubActive)) add(TXFSUBACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtBvrActive", TxtBvrActive)) add(TXTBVRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButBvrViewAvail", ButBvrViewAvail)) add(BUTBVRVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButBvrViewActive", ButBvrViewActive)) add(BUTBVRVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupJstActive", PupJstActive)) add(PUPJSTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJstEditAvail", ButJstEditAvail)) add(BUTJSTEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupSteActive", PupSteActive)) add(PUPSTEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAbtActive", TxfAbtActive)) add(TXFABTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbeVerDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtPrjActive == comp->TxtPrjActive) insert(items, TXTPRJACTIVE);
	if (ButPrjViewAvail == comp->ButPrjViewAvail) insert(items, BUTPRJVIEWAVAIL);
	if (ButPrjViewActive == comp->ButPrjViewActive) insert(items, BUTPRJVIEWACTIVE);
	if (TxfMajActive == comp->TxfMajActive) insert(items, TXFMAJACTIVE);
	if (TxfMinActive == comp->TxfMinActive) insert(items, TXFMINACTIVE);
	if (TxfSubActive == comp->TxfSubActive) insert(items, TXFSUBACTIVE);
	if (TxtBvrActive == comp->TxtBvrActive) insert(items, TXTBVRACTIVE);
	if (ButBvrViewAvail == comp->ButBvrViewAvail) insert(items, BUTBVRVIEWAVAIL);
	if (ButBvrViewActive == comp->ButBvrViewActive) insert(items, BUTBVRVIEWACTIVE);
	if (PupJstActive == comp->PupJstActive) insert(items, PUPJSTACTIVE);
	if (ButJstEditAvail == comp->ButJstEditAvail) insert(items, BUTJSTEDITAVAIL);
	if (PupSteActive == comp->PupSteActive) insert(items, PUPSTEACTIVE);
	if (TxfAbtActive == comp->TxfAbtActive) insert(items, TXFABTACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWdbeVerDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTPRJACTIVE, BUTPRJVIEWAVAIL, BUTPRJVIEWACTIVE, TXFMAJACTIVE, TXFMINACTIVE, TXFSUBACTIVE, TXTBVRACTIVE, BUTBVRVIEWAVAIL, BUTBVRVIEWACTIVE, PUPJSTACTIVE, BUTJSTEDITAVAIL, PUPSTEACTIVE, TXFABTACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeVerDetail::Tag
 ******************************************************************************/

PnlWdbeVerDetail::Tag::Tag(
			const string& Cpt
			, const string& CptPrj
			, const string& CptMaj
			, const string& CptMin
			, const string& CptSub
			, const string& CptBvr
			, const string& CptSte
			, const string& CptAbt
			, const string& CptCmt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptPrj = CptPrj;
	this->CptMaj = CptMaj;
	this->CptMin = CptMin;
	this->CptSub = CptSub;
	this->CptBvr = CptBvr;
	this->CptSte = CptSte;
	this->CptAbt = CptAbt;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTPRJ, CPTMAJ, CPTMIN, CPTSUB, CPTBVR, CPTSTE, CPTABT, CPTCMT};
};

bool PnlWdbeVerDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeVerDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeVerDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrj", CptPrj)) add(CPTPRJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMaj", CptMaj)) add(CPTMAJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMin", CptMin)) add(CPTMIN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSub", CptSub)) add(CPTSUB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptBvr", CptBvr)) add(CPTBVR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSte", CptSte)) add(CPTSTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAbt", CptAbt)) add(CPTABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeVerDetail::DpchAppData
 ******************************************************************************/

PnlWdbeVerDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEVERDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbeVerDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeVerDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeVerDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeVerDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeVerDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEVERDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbeVerDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeVerDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeVerDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeVerDetail::DpchEngData
 ******************************************************************************/

PnlWdbeVerDetail::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEVERDETAILDATA)
		{
	feedFPupJst.tag = "FeedFPupJst";
	feedFPupSte.tag = "FeedFPupSte";
};

string PnlWdbeVerDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPJST)) ss.push_back("feedFPupJst");
	if (has(FEEDFPUPSTE)) ss.push_back("feedFPupSte");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeVerDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeVerDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupJst.readXML(docctx, basexpath, true)) add(FEEDFPUPJST);
		if (feedFPupSte.readXML(docctx, basexpath, true)) add(FEEDFPUPSTE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupJst.clear();
		feedFPupSte.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
