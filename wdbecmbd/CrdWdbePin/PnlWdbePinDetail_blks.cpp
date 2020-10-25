/**
	* \file PnlWdbePinDetail_blks.cpp
	* job handler for job PnlWdbePinDetail (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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

void PnlWdbePinDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbePinDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbePinDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtClu", TxtClu);
		writeStringAttr(wr, itemtag, "sref", "TxtBnk", TxtBnk);
	xmlTextWriterEndElement(wr);
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

void PnlWdbePinDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
			, const bool LstCluAlt
			, const uint LstCluNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbePinDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbePinDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstCluAlt", LstCluAlt);
		writeUintAttr(wr, itemtag, "sref", "LstCluNumFirstdisp", LstCluNumFirstdisp);
	xmlTextWriterEndElement(wr);
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

void PnlWdbePinDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbePinDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbePinDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "PupJsrActive", PupJsrActive);
		writeBoolAttr(wr, itemtag, "sref", "ButJsrEditAvail", ButJsrEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "LstCluActive", LstCluActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCluViewActive", ButCluViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCluClusterAvail", ButCluClusterAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCluUnclusterAvail", ButCluUnclusterAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtBnkActive", TxtBnkActive);
		writeBoolAttr(wr, itemtag, "sref", "ButBnkViewAvail", ButBnkViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButBnkViewActive", ButBnkViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfLocActive", TxfLocActive);
	xmlTextWriterEndElement(wr);
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

void PnlWdbePinDetail::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbePinDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbePinDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptBnk", "I/O bank");
			writeStringAttr(wr, itemtag, "sref", "CptLoc", "location");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "CptClu", VecWdbeVTag::getTitle(VecWdbeVTag::CLUST, ixWdbeVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePinDetail::DpchAppData
 ******************************************************************************/

PnlWdbePinDetail::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPINDETAILDATA)
		{
};

string PnlWdbePinDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePinDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbePinDetailData");
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
 class PnlWdbePinDetail::DpchAppDo
 ******************************************************************************/

PnlWdbePinDetail::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPINDETAILDO)
		{
	ixVDo = 0;
};

string PnlWdbePinDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePinDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbePinDetailDo");
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
 class PnlWdbePinDetail::DpchEngData
 ******************************************************************************/

PnlWdbePinDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstClu
			, Feed* feedFPupJsr
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEPINDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTCLU, FEEDFPUPJSR, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTCLU) && feedFLstClu) this->feedFLstClu = *feedFLstClu;
	if (find(this->mask, FEEDFPUPJSR) && feedFPupJsr) this->feedFPupJsr = *feedFPupJsr;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbePinDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void PnlWdbePinDetail::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTCLU)) {feedFLstClu = src->feedFLstClu; add(FEEDFLSTCLU);};
	if (src->has(FEEDFPUPJSR)) {feedFPupJsr = src->feedFPupJsr; add(FEEDFPUPJSR);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbePinDetail::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbePinDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTCLU)) feedFLstClu.writeXML(wr);
		if (has(FEEDFPUPJSR)) feedFPupJsr.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};

