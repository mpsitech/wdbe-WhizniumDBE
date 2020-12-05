/**
	* \file PnlWdbeTrgDetail_blks.cpp
	* job handler for job PnlWdbeTrgDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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

void PnlWdbeTrgDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeTrgDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbeTrgDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtSys", TxtSys);
		writeStringAttr(wr, itemtag, "sref", "TxtUnt", TxtUnt);
	xmlTextWriterEndElement(wr);
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

void PnlWdbeTrgDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
			, const bool LstRteAlt
			, const uint LstRteNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeTrgDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeTrgDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstRteAlt", LstRteAlt);
		writeUintAttr(wr, itemtag, "sref", "LstRteNumFirstdisp", LstRteNumFirstdisp);
	xmlTextWriterEndElement(wr);
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

void PnlWdbeTrgDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeTrgDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeTrgDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfRteValid", TxfRteValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSysActive", TxtSysActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSysViewAvail", ButSysViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSysViewActive", ButSysViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtUntActive", TxtUntActive);
		writeBoolAttr(wr, itemtag, "sref", "ButUntViewAvail", ButUntViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButUntViewActive", ButUntViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstRteActive", LstRteActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
	xmlTextWriterEndElement(wr);
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

void PnlWdbeTrgDetail::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeTrgDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeTrgDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptSys", "system");
			writeStringAttr(wr, itemtag, "sref", "CptUnt", "unit");
			writeStringAttr(wr, itemtag, "sref", "CptRte", "routing");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeTrgDetail::DpchAppData
 ******************************************************************************/

PnlWdbeTrgDetail::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBETRGDETAILDATA)
		{
};

string PnlWdbeTrgDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeTrgDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeTrgDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

/******************************************************************************
 class PnlWdbeTrgDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeTrgDetail::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBETRGDETAILDO)
		{
	ixVDo = 0;
};

string PnlWdbeTrgDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeTrgDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeTrgDetailDo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDo", "", srefIxVDo)) {
			ixVDo = VecVDo::getIx(srefIxVDo);
			add(IXVDO);
		};
	} else {
	};
};

/******************************************************************************
 class PnlWdbeTrgDetail::DpchEngData
 ******************************************************************************/

PnlWdbeTrgDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstRte
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBETRGDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTRTE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTRTE) && feedFLstRte) this->feedFLstRte = *feedFLstRte;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeTrgDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTRTE)) ss.push_back("feedFLstRte");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeTrgDetail::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTRTE)) {feedFLstRte = src->feedFLstRte; add(FEEDFLSTRTE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeTrgDetail::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeTrgDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTRTE)) feedFLstRte.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};



