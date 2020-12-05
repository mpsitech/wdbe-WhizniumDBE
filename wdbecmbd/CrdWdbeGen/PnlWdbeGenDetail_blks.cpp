/**
	* \file PnlWdbeGenDetail_blks.cpp
	* job handler for job PnlWdbeGenDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeGenDetail::VecVDo
 ******************************************************************************/

uint PnlWdbeGenDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butcluviewclick") return BUTCLUVIEWCLICK;
	if (s == "butcluclusterclick") return BUTCLUCLUSTERCLICK;
	if (s == "butcluunclusterclick") return BUTCLUUNCLUSTERCLICK;
	if (s == "butmdlviewclick") return BUTMDLVIEWCLICK;
	if (s == "buthtyeditclick") return BUTHTYEDITCLICK;
	if (s == "butsrcviewclick") return BUTSRCVIEWCLICK;

	return(0);
};

string PnlWdbeGenDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTCLUVIEWCLICK) return("ButCluViewClick");
	if (ix == BUTCLUCLUSTERCLICK) return("ButCluClusterClick");
	if (ix == BUTCLUUNCLUSTERCLICK) return("ButCluUnclusterClick");
	if (ix == BUTMDLVIEWCLICK) return("ButMdlViewClick");
	if (ix == BUTHTYEDITCLICK) return("ButHtyEditClick");
	if (ix == BUTSRCVIEWCLICK) return("ButSrcViewClick");

	return("");
};

/******************************************************************************
 class PnlWdbeGenDetail::ContIac
 ******************************************************************************/

PnlWdbeGenDetail::ContIac::ContIac(
			const uint numFLstClu
			, const uint numFPupHty
			, const string& TxfHty
			, const string& TxfWid
			, const string& TxfMmx
			, const string& TxfDfv
			, const string& TxfSrc
			, const string& TxfCmt
		) :
			Block()
		{
	this->numFLstClu = numFLstClu;
	this->numFPupHty = numFPupHty;
	this->TxfHty = TxfHty;
	this->TxfWid = TxfWid;
	this->TxfMmx = TxfMmx;
	this->TxfDfv = TxfDfv;
	this->TxfSrc = TxfSrc;
	this->TxfCmt = TxfCmt;

	mask = {NUMFLSTCLU, NUMFPUPHTY, TXFHTY, TXFWID, TXFMMX, TXFDFV, TXFSRC, TXFCMT};
};

bool PnlWdbeGenDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeGenDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeGenDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstClu", numFLstClu)) add(NUMFLSTCLU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupHty", numFPupHty)) add(NUMFPUPHTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfHty", TxfHty)) add(TXFHTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfWid", TxfWid)) add(TXFWID);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfMmx", TxfMmx)) add(TXFMMX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDfv", TxfDfv)) add(TXFDFV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSrc", TxfSrc)) add(TXFSRC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWdbeGenDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeGenDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeGenDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstClu", numFLstClu);
		writeUintAttr(wr, itemtag, "sref", "numFPupHty", numFPupHty);
		writeStringAttr(wr, itemtag, "sref", "TxfHty", TxfHty);
		writeStringAttr(wr, itemtag, "sref", "TxfWid", TxfWid);
		writeStringAttr(wr, itemtag, "sref", "TxfMmx", TxfMmx);
		writeStringAttr(wr, itemtag, "sref", "TxfDfv", TxfDfv);
		writeStringAttr(wr, itemtag, "sref", "TxfSrc", TxfSrc);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeGenDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstClu == comp->numFLstClu) insert(items, NUMFLSTCLU);
	if (numFPupHty == comp->numFPupHty) insert(items, NUMFPUPHTY);
	if (TxfHty == comp->TxfHty) insert(items, TXFHTY);
	if (TxfWid == comp->TxfWid) insert(items, TXFWID);
	if (TxfMmx == comp->TxfMmx) insert(items, TXFMMX);
	if (TxfDfv == comp->TxfDfv) insert(items, TXFDFV);
	if (TxfSrc == comp->TxfSrc) insert(items, TXFSRC);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWdbeGenDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTCLU, NUMFPUPHTY, TXFHTY, TXFWID, TXFMMX, TXFDFV, TXFSRC, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeGenDetail::ContInf
 ******************************************************************************/

PnlWdbeGenDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtClu
			, const string& TxtMdl
			, const string& TxtSrc
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtClu = TxtClu;
	this->TxtMdl = TxtMdl;
	this->TxtSrc = TxtSrc;

	mask = {TXTSRF, TXTCLU, TXTMDL, TXTSRC};
};

void PnlWdbeGenDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeGenDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbeGenDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtClu", TxtClu);
		writeStringAttr(wr, itemtag, "sref", "TxtMdl", TxtMdl);
		writeStringAttr(wr, itemtag, "sref", "TxtSrc", TxtSrc);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeGenDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtClu == comp->TxtClu) insert(items, TXTCLU);
	if (TxtMdl == comp->TxtMdl) insert(items, TXTMDL);
	if (TxtSrc == comp->TxtSrc) insert(items, TXTSRC);

	return(items);
};

set<uint> PnlWdbeGenDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTCLU, TXTMDL, TXTSRC};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeGenDetail::StatApp
 ******************************************************************************/

void PnlWdbeGenDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
			, const bool LstCluAlt
			, const bool PupHtyAlt
			, const bool TxtSrcAlt
			, const uint LstCluNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeGenDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeGenDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstCluAlt", LstCluAlt);
		writeBoolAttr(wr, itemtag, "sref", "PupHtyAlt", PupHtyAlt);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrcAlt", TxtSrcAlt);
		writeUintAttr(wr, itemtag, "sref", "LstCluNumFirstdisp", LstCluNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeGenDetail::StatShr
 ******************************************************************************/

PnlWdbeGenDetail::StatShr::StatShr(
			const bool TxfHtyValid
			, const bool TxfSrcValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool LstCluActive
			, const bool ButCluViewActive
			, const bool ButCluClusterAvail
			, const bool ButCluUnclusterAvail
			, const bool TxtMdlActive
			, const bool ButMdlViewAvail
			, const bool ButMdlViewActive
			, const bool PupHtyActive
			, const bool ButHtyEditAvail
			, const bool TxfWidActive
			, const bool TxfMmxActive
			, const bool TxfDfvActive
			, const bool TxtSrcActive
			, const bool ButSrcViewAvail
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->TxfHtyValid = TxfHtyValid;
	this->TxfSrcValid = TxfSrcValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->LstCluActive = LstCluActive;
	this->ButCluViewActive = ButCluViewActive;
	this->ButCluClusterAvail = ButCluClusterAvail;
	this->ButCluUnclusterAvail = ButCluUnclusterAvail;
	this->TxtMdlActive = TxtMdlActive;
	this->ButMdlViewAvail = ButMdlViewAvail;
	this->ButMdlViewActive = ButMdlViewActive;
	this->PupHtyActive = PupHtyActive;
	this->ButHtyEditAvail = ButHtyEditAvail;
	this->TxfWidActive = TxfWidActive;
	this->TxfMmxActive = TxfMmxActive;
	this->TxfDfvActive = TxfDfvActive;
	this->TxtSrcActive = TxtSrcActive;
	this->ButSrcViewAvail = ButSrcViewAvail;
	this->TxfCmtActive = TxfCmtActive;

	mask = {TXFHTYVALID, TXFSRCVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, PUPHTYACTIVE, BUTHTYEDITAVAIL, TXFWIDACTIVE, TXFMMXACTIVE, TXFDFVACTIVE, TXTSRCACTIVE, BUTSRCVIEWAVAIL, TXFCMTACTIVE};
};

void PnlWdbeGenDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeGenDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeGenDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfHtyValid", TxfHtyValid);
		writeBoolAttr(wr, itemtag, "sref", "TxfSrcValid", TxfSrcValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "LstCluActive", LstCluActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCluViewActive", ButCluViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCluClusterAvail", ButCluClusterAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCluUnclusterAvail", ButCluUnclusterAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtMdlActive", TxtMdlActive);
		writeBoolAttr(wr, itemtag, "sref", "ButMdlViewAvail", ButMdlViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButMdlViewActive", ButMdlViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupHtyActive", PupHtyActive);
		writeBoolAttr(wr, itemtag, "sref", "ButHtyEditAvail", ButHtyEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfWidActive", TxfWidActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfMmxActive", TxfMmxActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfDfvActive", TxfDfvActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrcActive", TxtSrcActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSrcViewAvail", ButSrcViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeGenDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfHtyValid == comp->TxfHtyValid) insert(items, TXFHTYVALID);
	if (TxfSrcValid == comp->TxfSrcValid) insert(items, TXFSRCVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (LstCluActive == comp->LstCluActive) insert(items, LSTCLUACTIVE);
	if (ButCluViewActive == comp->ButCluViewActive) insert(items, BUTCLUVIEWACTIVE);
	if (ButCluClusterAvail == comp->ButCluClusterAvail) insert(items, BUTCLUCLUSTERAVAIL);
	if (ButCluUnclusterAvail == comp->ButCluUnclusterAvail) insert(items, BUTCLUUNCLUSTERAVAIL);
	if (TxtMdlActive == comp->TxtMdlActive) insert(items, TXTMDLACTIVE);
	if (ButMdlViewAvail == comp->ButMdlViewAvail) insert(items, BUTMDLVIEWAVAIL);
	if (ButMdlViewActive == comp->ButMdlViewActive) insert(items, BUTMDLVIEWACTIVE);
	if (PupHtyActive == comp->PupHtyActive) insert(items, PUPHTYACTIVE);
	if (ButHtyEditAvail == comp->ButHtyEditAvail) insert(items, BUTHTYEDITAVAIL);
	if (TxfWidActive == comp->TxfWidActive) insert(items, TXFWIDACTIVE);
	if (TxfMmxActive == comp->TxfMmxActive) insert(items, TXFMMXACTIVE);
	if (TxfDfvActive == comp->TxfDfvActive) insert(items, TXFDFVACTIVE);
	if (TxtSrcActive == comp->TxtSrcActive) insert(items, TXTSRCACTIVE);
	if (ButSrcViewAvail == comp->ButSrcViewAvail) insert(items, BUTSRCVIEWAVAIL);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWdbeGenDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFHTYVALID, TXFSRCVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, PUPHTYACTIVE, BUTHTYEDITAVAIL, TXFWIDACTIVE, TXFMMXACTIVE, TXFDFVACTIVE, TXTSRCACTIVE, BUTSRCVIEWAVAIL, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeGenDetail::Tag
 ******************************************************************************/

void PnlWdbeGenDetail::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeGenDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeGenDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptMdl", "module");
			writeStringAttr(wr, itemtag, "sref", "CptHty", "HDL data type");
			writeStringAttr(wr, itemtag, "sref", "CptWid", "width");
			writeStringAttr(wr, itemtag, "sref", "CptMmx", "range");
			writeStringAttr(wr, itemtag, "sref", "CptDfv", "default value");
			writeStringAttr(wr, itemtag, "sref", "CptSrc", "source generic");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "CptClu", VecWdbeVTag::getTitle(VecWdbeVTag::CLUST, ixWdbeVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeGenDetail::DpchAppData
 ******************************************************************************/

PnlWdbeGenDetail::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEGENDETAILDATA)
		{
};

string PnlWdbeGenDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeGenDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeGenDetailData");
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
 class PnlWdbeGenDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeGenDetail::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEGENDETAILDO)
		{
	ixVDo = 0;
};

string PnlWdbeGenDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeGenDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeGenDetailDo");
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
 class PnlWdbeGenDetail::DpchEngData
 ******************************************************************************/

PnlWdbeGenDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstClu
			, Feed* feedFPupHty
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEGENDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTCLU, FEEDFPUPHTY, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTCLU) && feedFLstClu) this->feedFLstClu = *feedFLstClu;
	if (find(this->mask, FEEDFPUPHTY) && feedFPupHty) this->feedFPupHty = *feedFPupHty;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeGenDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTCLU)) ss.push_back("feedFLstClu");
	if (has(FEEDFPUPHTY)) ss.push_back("feedFPupHty");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeGenDetail::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTCLU)) {feedFLstClu = src->feedFLstClu; add(FEEDFLSTCLU);};
	if (src->has(FEEDFPUPHTY)) {feedFPupHty = src->feedFPupHty; add(FEEDFPUPHTY);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeGenDetail::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeGenDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTCLU)) feedFLstClu.writeXML(wr);
		if (has(FEEDFPUPHTY)) feedFPupHty.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};



