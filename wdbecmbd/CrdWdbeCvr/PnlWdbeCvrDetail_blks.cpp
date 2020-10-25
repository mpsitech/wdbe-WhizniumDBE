/**
	* \file PnlWdbeCvrDetail_blks.cpp
	* job handler for job PnlWdbeCvrDetail (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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
		{
	this->TxfMaj = TxfMaj;
	this->TxfMin = TxfMin;
	this->TxfSub = TxfSub;
	this->numFPupJst = numFPupJst;
	this->numFPupSte = numFPupSte;
	this->numsFLstSty = numsFLstSty;

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
		{
	this->TxtCpr = TxtCpr;
	this->TxtBcv = TxtBcv;
	this->TxtSty = TxtSty;

	mask = {TXTCPR, TXTBCV, TXTSTY};
};

void PnlWdbeCvrDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeCvrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbeCvrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtCpr", TxtCpr);
		writeStringAttr(wr, itemtag, "sref", "TxtBcv", TxtBcv);
		writeStringAttr(wr, itemtag, "sref", "TxtSty", TxtSty);
	xmlTextWriterEndElement(wr);
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

void PnlWdbeCvrDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
			, const bool LstStyAlt
			, const uint LstStyNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeCvrDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeCvrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstStyAlt", LstStyAlt);
		writeUintAttr(wr, itemtag, "sref", "LstStyNumFirstdisp", LstStyNumFirstdisp);
	xmlTextWriterEndElement(wr);
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
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtCprActive = TxtCprActive;
	this->ButCprViewAvail = ButCprViewAvail;
	this->ButCprViewActive = ButCprViewActive;
	this->TxfMajActive = TxfMajActive;
	this->TxfMinActive = TxfMinActive;
	this->TxfSubActive = TxfSubActive;
	this->TxtBcvActive = TxtBcvActive;
	this->ButBcvViewAvail = ButBcvViewAvail;
	this->ButBcvViewActive = ButBcvViewActive;
	this->PupJstActive = PupJstActive;
	this->ButJstEditAvail = ButJstEditAvail;
	this->PupSteActive = PupSteActive;
	this->LstStyActive = LstStyActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTCPRACTIVE, BUTCPRVIEWAVAIL, BUTCPRVIEWACTIVE, TXFMAJACTIVE, TXFMINACTIVE, TXFSUBACTIVE, TXTBCVACTIVE, BUTBCVVIEWAVAIL, BUTBCVVIEWACTIVE, PUPJSTACTIVE, BUTJSTEDITAVAIL, PUPSTEACTIVE, LSTSTYACTIVE};
};

void PnlWdbeCvrDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeCvrDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeCvrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtCprActive", TxtCprActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCprViewAvail", ButCprViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCprViewActive", ButCprViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfMajActive", TxfMajActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfMinActive", TxfMinActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfSubActive", TxfSubActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtBcvActive", TxtBcvActive);
		writeBoolAttr(wr, itemtag, "sref", "ButBcvViewAvail", ButBcvViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButBcvViewActive", ButBcvViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupJstActive", PupJstActive);
		writeBoolAttr(wr, itemtag, "sref", "ButJstEditAvail", ButJstEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "PupSteActive", PupSteActive);
		writeBoolAttr(wr, itemtag, "sref", "LstStyActive", LstStyActive);
	xmlTextWriterEndElement(wr);
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

void PnlWdbeCvrDetail::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeCvrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeCvrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptCpr", "core project");
			writeStringAttr(wr, itemtag, "sref", "CptMaj", "major version number");
			writeStringAttr(wr, itemtag, "sref", "CptMin", "minor version number");
			writeStringAttr(wr, itemtag, "sref", "CptSub", "sub version number");
			writeStringAttr(wr, itemtag, "sref", "CptBcv", "base core version");
			writeStringAttr(wr, itemtag, "sref", "CptSte", "state");
			writeStringAttr(wr, itemtag, "sref", "CptSty", "specifics types");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeCvrDetail::DpchAppData
 ******************************************************************************/

PnlWdbeCvrDetail::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBECVRDETAILDATA)
		{
};

string PnlWdbeCvrDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeCvrDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeCvrDetailData");
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
 class PnlWdbeCvrDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeCvrDetail::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBECVRDETAILDO)
		{
	ixVDo = 0;
};

string PnlWdbeCvrDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeCvrDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeCvrDetailDo");
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
 class PnlWdbeCvrDetail::DpchEngData
 ******************************************************************************/

PnlWdbeCvrDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstSty
			, Feed* feedFPupJst
			, Feed* feedFPupSte
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBECVRDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTSTY, FEEDFPUPJST, FEEDFPUPSTE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTSTY) && feedFLstSty) this->feedFLstSty = *feedFLstSty;
	if (find(this->mask, FEEDFPUPJST) && feedFPupJst) this->feedFPupJst = *feedFPupJst;
	if (find(this->mask, FEEDFPUPSTE) && feedFPupSte) this->feedFPupSte = *feedFPupSte;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeCvrDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void PnlWdbeCvrDetail::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTSTY)) {feedFLstSty = src->feedFLstSty; add(FEEDFLSTSTY);};
	if (src->has(FEEDFPUPJST)) {feedFPupJst = src->feedFPupJst; add(FEEDFPUPJST);};
	if (src->has(FEEDFPUPSTE)) {feedFPupSte = src->feedFPupSte; add(FEEDFPUPSTE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeCvrDetail::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeCvrDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTSTY)) feedFLstSty.writeXML(wr);
		if (has(FEEDFPUPJST)) feedFPupJst.writeXML(wr);
		if (has(FEEDFPUPSTE)) feedFPupSte.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};

