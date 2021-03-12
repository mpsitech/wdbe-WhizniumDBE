/**
	* \file PnlWdbeVerDetail_blks.cpp
	* job handler for job PnlWdbeVerDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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

bool PnlWdbeVerDetail::ContIac::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["ContIacWdbeVerDetail"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TxfMaj")) {TxfMaj = me["TxfMaj"].asString(); add(TXFMAJ);};
		if (me.isMember("TxfMin")) {TxfMin = me["TxfMin"].asString(); add(TXFMIN);};
		if (me.isMember("TxfSub")) {TxfSub = me["TxfSub"].asString(); add(TXFSUB);};
		if (me.isMember("numFPupJst")) {numFPupJst = me["numFPupJst"].asUInt(); add(NUMFPUPJST);};
		if (me.isMember("numFPupSte")) {numFPupSte = me["numFPupSte"].asUInt(); add(NUMFPUPSTE);};
		if (me.isMember("TxfAbt")) {TxfAbt = me["TxfAbt"].asString(); add(TXFABT);};
		if (me.isMember("TxfCmt")) {TxfCmt = me["TxfCmt"].asString(); add(TXFCMT);};
	};

	return basefound;
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

void PnlWdbeVerDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeVerDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfMaj"] = TxfMaj;
	me["TxfMin"] = TxfMin;
	me["TxfSub"] = TxfSub;
	me["numFPupJst"] = numFPupJst;
	me["numFPupSte"] = numFPupSte;
	me["TxfAbt"] = TxfAbt;
	me["TxfCmt"] = TxfCmt;
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

void PnlWdbeVerDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeVerDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtPrj"] = TxtPrj;
	me["TxtBvr"] = TxtBvr;
};

void PnlWdbeVerDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeVerDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbeVerDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrj", TxtPrj);
		writeStringAttr(wr, itemtag, "sref", "TxtBvr", TxtBvr);
	xmlTextWriterEndElement(wr);
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

void PnlWdbeVerDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWdbeVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeVerDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
};

void PnlWdbeVerDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeVerDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeVerDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
	xmlTextWriterEndElement(wr);
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

void PnlWdbeVerDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeVerDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtPrjActive"] = TxtPrjActive;
	me["ButPrjViewAvail"] = ButPrjViewAvail;
	me["ButPrjViewActive"] = ButPrjViewActive;
	me["TxfMajActive"] = TxfMajActive;
	me["TxfMinActive"] = TxfMinActive;
	me["TxfSubActive"] = TxfSubActive;
	me["TxtBvrActive"] = TxtBvrActive;
	me["ButBvrViewAvail"] = ButBvrViewAvail;
	me["ButBvrViewActive"] = ButBvrViewActive;
	me["PupJstActive"] = PupJstActive;
	me["ButJstEditAvail"] = ButJstEditAvail;
	me["PupSteActive"] = PupSteActive;
	me["TxfAbtActive"] = TxfAbtActive;
	me["TxfCmtActive"] = TxfCmtActive;
};

void PnlWdbeVerDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeVerDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeVerDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtPrjActive", TxtPrjActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPrjViewAvail", ButPrjViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPrjViewActive", ButPrjViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfMajActive", TxfMajActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfMinActive", TxfMinActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfSubActive", TxfSubActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtBvrActive", TxtBvrActive);
		writeBoolAttr(wr, itemtag, "sref", "ButBvrViewAvail", ButBvrViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButBvrViewActive", ButBvrViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupJstActive", PupJstActive);
		writeBoolAttr(wr, itemtag, "sref", "ButJstEditAvail", ButJstEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "PupSteActive", PupSteActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfAbtActive", TxfAbtActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
	xmlTextWriterEndElement(wr);
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

void PnlWdbeVerDetail::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbeVerDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["CptPrj"] = "project";
		me["CptMaj"] = "major version number";
		me["CptMin"] = "minor version number";
		me["CptSub"] = "sub version number";
		me["CptBvr"] = "base version";
		me["CptSte"] = "state";
		me["CptAbt"] = "about text";
		me["CptCmt"] = "comment";
	};
	me["Cpt"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale));
};

void PnlWdbeVerDetail::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeVerDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeVerDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptPrj", "project");
			writeStringAttr(wr, itemtag, "sref", "CptMaj", "major version number");
			writeStringAttr(wr, itemtag, "sref", "CptMin", "minor version number");
			writeStringAttr(wr, itemtag, "sref", "CptSub", "sub version number");
			writeStringAttr(wr, itemtag, "sref", "CptBvr", "base version");
			writeStringAttr(wr, itemtag, "sref", "CptSte", "state");
			writeStringAttr(wr, itemtag, "sref", "CptAbt", "about text");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeVerDetail::DpchAppData
 ******************************************************************************/

PnlWdbeVerDetail::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEVERDETAILDATA)
		{
};

string PnlWdbeVerDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeVerDetail::DpchAppData::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWdbeVerDetailData"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWdbeVerDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeVerDetailData");
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
 class PnlWdbeVerDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeVerDetail::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEVERDETAILDO)
		{
	ixVDo = 0;
};

string PnlWdbeVerDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeVerDetail::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWdbeVerDetailDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWdbeVerDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeVerDetailDo");
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
 class PnlWdbeVerDetail::DpchEngData
 ******************************************************************************/

PnlWdbeVerDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupJst
			, Feed* feedFPupSte
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEVERDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPJST, FEEDFPUPSTE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPJST) && feedFPupJst) this->feedFPupJst = *feedFPupJst;
	if (find(this->mask, FEEDFPUPSTE) && feedFPupSte) this->feedFPupSte = *feedFPupSte;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeVerDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void PnlWdbeVerDetail::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPJST)) {feedFPupJst = src->feedFPupJst; add(FEEDFPUPJST);};
	if (src->has(FEEDFPUPSTE)) {feedFPupSte = src->feedFPupSte; add(FEEDFPUPSTE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeVerDetail::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbeVerDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFPUPJST)) feedFPupJst.writeJSON(me);
	if (has(FEEDFPUPSTE)) feedFPupSte.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void PnlWdbeVerDetail::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeVerDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPJST)) feedFPupJst.writeXML(wr);
		if (has(FEEDFPUPSTE)) feedFPupSte.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
