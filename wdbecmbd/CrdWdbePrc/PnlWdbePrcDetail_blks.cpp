/**
	* \file PnlWdbePrcDetail_blks.cpp
	* job handler for job PnlWdbePrcDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbePrcDetail::VecVDo
 ******************************************************************************/

uint PnlWdbePrcDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butmdlviewclick") return BUTMDLVIEWCLICK;
	if (s == "butclkviewclick") return BUTCLKVIEWCLICK;
	if (s == "butasrviewclick") return BUTASRVIEWCLICK;
	if (s == "butfsmnewclick") return BUTFSMNEWCLICK;
	if (s == "butfsmdeleteclick") return BUTFSMDELETECLICK;

	return(0);
};

string PnlWdbePrcDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTMDLVIEWCLICK) return("ButMdlViewClick");
	if (ix == BUTCLKVIEWCLICK) return("ButClkViewClick");
	if (ix == BUTASRVIEWCLICK) return("ButAsrViewClick");
	if (ix == BUTFSMNEWCLICK) return("ButFsmNewClick");
	if (ix == BUTFSMDELETECLICK) return("ButFsmDeleteClick");

	return("");
};

/******************************************************************************
 class PnlWdbePrcDetail::ContIac
 ******************************************************************************/

PnlWdbePrcDetail::ContIac::ContIac(
			const string& TxfClk
			, const string& TxfAsr
			, const bool ChkFal
			, const string& TxfSnr
			, const bool ChkEip
			, const string& TxfCmt
			, const uint numFPupFsmDtt
		) :
			Block()
		{
	this->TxfClk = TxfClk;
	this->TxfAsr = TxfAsr;
	this->ChkFal = ChkFal;
	this->TxfSnr = TxfSnr;
	this->ChkEip = ChkEip;
	this->TxfCmt = TxfCmt;
	this->numFPupFsmDtt = numFPupFsmDtt;

	mask = {TXFCLK, TXFASR, CHKFAL, TXFSNR, CHKEIP, TXFCMT, NUMFPUPFSMDTT};
};

bool PnlWdbePrcDetail::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWdbePrcDetail"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TxfClk")) {TxfClk = me["TxfClk"].asString(); add(TXFCLK);};
		if (me.isMember("TxfAsr")) {TxfAsr = me["TxfAsr"].asString(); add(TXFASR);};
		if (me.isMember("ChkFal")) {ChkFal = me["ChkFal"].asBool(); add(CHKFAL);};
		if (me.isMember("TxfSnr")) {TxfSnr = me["TxfSnr"].asString(); add(TXFSNR);};
		if (me.isMember("ChkEip")) {ChkEip = me["ChkEip"].asBool(); add(CHKEIP);};
		if (me.isMember("TxfCmt")) {TxfCmt = me["TxfCmt"].asString(); add(TXFCMT);};
		if (me.isMember("numFPupFsmDtt")) {numFPupFsmDtt = me["numFPupFsmDtt"].asUInt(); add(NUMFPUPFSMDTT);};
	};

	return basefound;
};

bool PnlWdbePrcDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbePrcDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbePrcDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfClk", TxfClk)) add(TXFCLK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAsr", TxfAsr)) add(TXFASR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkFal", ChkFal)) add(CHKFAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSnr", TxfSnr)) add(TXFSNR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkEip", ChkEip)) add(CHKEIP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupFsmDtt", numFPupFsmDtt)) add(NUMFPUPFSMDTT);
	};

	return basefound;
};

void PnlWdbePrcDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbePrcDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfClk"] = TxfClk;
	me["TxfAsr"] = TxfAsr;
	me["ChkFal"] = ChkFal;
	me["TxfSnr"] = TxfSnr;
	me["ChkEip"] = ChkEip;
	me["TxfCmt"] = TxfCmt;
	me["numFPupFsmDtt"] = (Json::Value::UInt) numFPupFsmDtt;
};

void PnlWdbePrcDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbePrcDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbePrcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfClk", TxfClk);
		writeStringAttr(wr, itemtag, "sref", "TxfAsr", TxfAsr);
		writeBoolAttr(wr, itemtag, "sref", "ChkFal", ChkFal);
		writeStringAttr(wr, itemtag, "sref", "TxfSnr", TxfSnr);
		writeBoolAttr(wr, itemtag, "sref", "ChkEip", ChkEip);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
		writeUintAttr(wr, itemtag, "sref", "numFPupFsmDtt", numFPupFsmDtt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbePrcDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfClk == comp->TxfClk) insert(items, TXFCLK);
	if (TxfAsr == comp->TxfAsr) insert(items, TXFASR);
	if (ChkFal == comp->ChkFal) insert(items, CHKFAL);
	if (TxfSnr == comp->TxfSnr) insert(items, TXFSNR);
	if (ChkEip == comp->ChkEip) insert(items, CHKEIP);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);
	if (numFPupFsmDtt == comp->numFPupFsmDtt) insert(items, NUMFPUPFSMDTT);

	return(items);
};

set<uint> PnlWdbePrcDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFCLK, TXFASR, CHKFAL, TXFSNR, CHKEIP, TXFCMT, NUMFPUPFSMDTT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrcDetail::ContInf
 ******************************************************************************/

PnlWdbePrcDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtMdl
			, const string& TxtClk
			, const string& TxtAsr
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtMdl = TxtMdl;
	this->TxtClk = TxtClk;
	this->TxtAsr = TxtAsr;

	mask = {TXTSRF, TXTMDL, TXTCLK, TXTASR};
};

void PnlWdbePrcDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbePrcDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtSrf"] = TxtSrf;
	me["TxtMdl"] = TxtMdl;
	me["TxtClk"] = TxtClk;
	me["TxtAsr"] = TxtAsr;
};

void PnlWdbePrcDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbePrcDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbePrcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtMdl", TxtMdl);
		writeStringAttr(wr, itemtag, "sref", "TxtClk", TxtClk);
		writeStringAttr(wr, itemtag, "sref", "TxtAsr", TxtAsr);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbePrcDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtMdl == comp->TxtMdl) insert(items, TXTMDL);
	if (TxtClk == comp->TxtClk) insert(items, TXTCLK);
	if (TxtAsr == comp->TxtAsr) insert(items, TXTASR);

	return(items);
};

set<uint> PnlWdbePrcDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTMDL, TXTCLK, TXTASR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrcDetail::StatApp
 ******************************************************************************/

void PnlWdbePrcDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWdbeVExpstate
			, const bool TxtClkAlt
			, const bool TxtAsrAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbePrcDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
	me["TxtClkAlt"] = TxtClkAlt;
	me["TxtAsrAlt"] = TxtAsrAlt;
};

void PnlWdbePrcDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
			, const bool TxtClkAlt
			, const bool TxtAsrAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbePrcDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbePrcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "TxtClkAlt", TxtClkAlt);
		writeBoolAttr(wr, itemtag, "sref", "TxtAsrAlt", TxtAsrAlt);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePrcDetail::StatShr
 ******************************************************************************/

PnlWdbePrcDetail::StatShr::StatShr(
			const bool TxfClkValid
			, const bool TxfAsrValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxtMdlActive
			, const bool ButMdlViewAvail
			, const bool ButMdlViewActive
			, const bool TxtClkActive
			, const bool ButClkViewAvail
			, const bool TxtAsrActive
			, const bool ButAsrViewAvail
			, const bool ChkFalActive
			, const bool TxfSnrActive
			, const bool ChkEipActive
			, const bool TxfCmtActive
			, const bool ButFsmNewAvail
			, const bool ButFsmDeleteAvail
			, const bool PupFsmDttAvail
			, const bool PupFsmDttActive
		) :
			Block()
		{
	this->TxfClkValid = TxfClkValid;
	this->TxfAsrValid = TxfAsrValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxtMdlActive = TxtMdlActive;
	this->ButMdlViewAvail = ButMdlViewAvail;
	this->ButMdlViewActive = ButMdlViewActive;
	this->TxtClkActive = TxtClkActive;
	this->ButClkViewAvail = ButClkViewAvail;
	this->TxtAsrActive = TxtAsrActive;
	this->ButAsrViewAvail = ButAsrViewAvail;
	this->ChkFalActive = ChkFalActive;
	this->TxfSnrActive = TxfSnrActive;
	this->ChkEipActive = ChkEipActive;
	this->TxfCmtActive = TxfCmtActive;
	this->ButFsmNewAvail = ButFsmNewAvail;
	this->ButFsmDeleteAvail = ButFsmDeleteAvail;
	this->PupFsmDttAvail = PupFsmDttAvail;
	this->PupFsmDttActive = PupFsmDttActive;

	mask = {TXFCLKVALID, TXFASRVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, TXTCLKACTIVE, BUTCLKVIEWAVAIL, TXTASRACTIVE, BUTASRVIEWAVAIL, CHKFALACTIVE, TXFSNRACTIVE, CHKEIPACTIVE, TXFCMTACTIVE, BUTFSMNEWAVAIL, BUTFSMDELETEAVAIL, PUPFSMDTTAVAIL, PUPFSMDTTACTIVE};
};

void PnlWdbePrcDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbePrcDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfClkValid"] = TxfClkValid;
	me["TxfAsrValid"] = TxfAsrValid;
	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtSrfActive"] = TxtSrfActive;
	me["TxtMdlActive"] = TxtMdlActive;
	me["ButMdlViewAvail"] = ButMdlViewAvail;
	me["ButMdlViewActive"] = ButMdlViewActive;
	me["TxtClkActive"] = TxtClkActive;
	me["ButClkViewAvail"] = ButClkViewAvail;
	me["TxtAsrActive"] = TxtAsrActive;
	me["ButAsrViewAvail"] = ButAsrViewAvail;
	me["ChkFalActive"] = ChkFalActive;
	me["TxfSnrActive"] = TxfSnrActive;
	me["ChkEipActive"] = ChkEipActive;
	me["TxfCmtActive"] = TxfCmtActive;
	me["ButFsmNewAvail"] = ButFsmNewAvail;
	me["ButFsmDeleteAvail"] = ButFsmDeleteAvail;
	me["PupFsmDttAvail"] = PupFsmDttAvail;
	me["PupFsmDttActive"] = PupFsmDttActive;
};

void PnlWdbePrcDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbePrcDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbePrcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfClkValid", TxfClkValid);
		writeBoolAttr(wr, itemtag, "sref", "TxfAsrValid", TxfAsrValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtMdlActive", TxtMdlActive);
		writeBoolAttr(wr, itemtag, "sref", "ButMdlViewAvail", ButMdlViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButMdlViewActive", ButMdlViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtClkActive", TxtClkActive);
		writeBoolAttr(wr, itemtag, "sref", "ButClkViewAvail", ButClkViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtAsrActive", TxtAsrActive);
		writeBoolAttr(wr, itemtag, "sref", "ButAsrViewAvail", ButAsrViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ChkFalActive", ChkFalActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfSnrActive", TxfSnrActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkEipActive", ChkEipActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
		writeBoolAttr(wr, itemtag, "sref", "ButFsmNewAvail", ButFsmNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFsmDeleteAvail", ButFsmDeleteAvail);
		writeBoolAttr(wr, itemtag, "sref", "PupFsmDttAvail", PupFsmDttAvail);
		writeBoolAttr(wr, itemtag, "sref", "PupFsmDttActive", PupFsmDttActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbePrcDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfClkValid == comp->TxfClkValid) insert(items, TXFCLKVALID);
	if (TxfAsrValid == comp->TxfAsrValid) insert(items, TXFASRVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxtMdlActive == comp->TxtMdlActive) insert(items, TXTMDLACTIVE);
	if (ButMdlViewAvail == comp->ButMdlViewAvail) insert(items, BUTMDLVIEWAVAIL);
	if (ButMdlViewActive == comp->ButMdlViewActive) insert(items, BUTMDLVIEWACTIVE);
	if (TxtClkActive == comp->TxtClkActive) insert(items, TXTCLKACTIVE);
	if (ButClkViewAvail == comp->ButClkViewAvail) insert(items, BUTCLKVIEWAVAIL);
	if (TxtAsrActive == comp->TxtAsrActive) insert(items, TXTASRACTIVE);
	if (ButAsrViewAvail == comp->ButAsrViewAvail) insert(items, BUTASRVIEWAVAIL);
	if (ChkFalActive == comp->ChkFalActive) insert(items, CHKFALACTIVE);
	if (TxfSnrActive == comp->TxfSnrActive) insert(items, TXFSNRACTIVE);
	if (ChkEipActive == comp->ChkEipActive) insert(items, CHKEIPACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);
	if (ButFsmNewAvail == comp->ButFsmNewAvail) insert(items, BUTFSMNEWAVAIL);
	if (ButFsmDeleteAvail == comp->ButFsmDeleteAvail) insert(items, BUTFSMDELETEAVAIL);
	if (PupFsmDttAvail == comp->PupFsmDttAvail) insert(items, PUPFSMDTTAVAIL);
	if (PupFsmDttActive == comp->PupFsmDttActive) insert(items, PUPFSMDTTACTIVE);

	return(items);
};

set<uint> PnlWdbePrcDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFCLKVALID, TXFASRVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, TXTCLKACTIVE, BUTCLKVIEWAVAIL, TXTASRACTIVE, BUTASRVIEWAVAIL, CHKFALACTIVE, TXFSNRACTIVE, CHKEIPACTIVE, TXFCMTACTIVE, BUTFSMNEWAVAIL, BUTFSMDELETEAVAIL, PUPFSMDTTAVAIL, PUPFSMDTTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrcDetail::Tag
 ******************************************************************************/

void PnlWdbePrcDetail::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbePrcDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["CptSrf"] = "identifier";
		me["CptMdl"] = "module";
		me["CptClk"] = "clock signal";
		me["CptAsr"] = "asynchronous reset signal";
		me["CptFal"] = "falling edge sub-process";
		me["CptSnr"] = "synchronized reset condition";
		me["CptEip"] = "external insertion point";
		me["CptCmt"] = "comment";
		me["HdgFsm"] = "Finite state machine";
		me["CptFsmDtt"] = "debug tap type";
	};
	me["Cpt"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale));
};

void PnlWdbePrcDetail::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbePrcDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbePrcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptMdl", "module");
			writeStringAttr(wr, itemtag, "sref", "CptClk", "clock signal");
			writeStringAttr(wr, itemtag, "sref", "CptAsr", "asynchronous reset signal");
			writeStringAttr(wr, itemtag, "sref", "CptFal", "falling edge sub-process");
			writeStringAttr(wr, itemtag, "sref", "CptSnr", "synchronized reset condition");
			writeStringAttr(wr, itemtag, "sref", "CptEip", "external insertion point");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
			writeStringAttr(wr, itemtag, "sref", "HdgFsm", "Finite state machine");
			writeStringAttr(wr, itemtag, "sref", "CptFsmDtt", "debug tap type");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePrcDetail::DpchAppData
 ******************************************************************************/

PnlWdbePrcDetail::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPRCDETAILDATA)
		{
};

string PnlWdbePrcDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrcDetail::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbePrcDetailData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWdbePrcDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbePrcDetailData");
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
 class PnlWdbePrcDetail::DpchAppDo
 ******************************************************************************/

PnlWdbePrcDetail::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPRCDETAILDO)
		{
	ixVDo = 0;
};

string PnlWdbePrcDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrcDetail::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbePrcDetailDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWdbePrcDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbePrcDetailDo");
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
 class PnlWdbePrcDetail::DpchEngData
 ******************************************************************************/

PnlWdbePrcDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupFsmDtt
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEPRCDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPFSMDTT, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPFSMDTT) && feedFPupFsmDtt) this->feedFPupFsmDtt = *feedFPupFsmDtt;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbePrcDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPFSMDTT)) ss.push_back("feedFPupFsmDtt");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrcDetail::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPFSMDTT)) {feedFPupFsmDtt = src->feedFPupFsmDtt; add(FEEDFPUPFSMDTT);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbePrcDetail::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbePrcDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFPUPFSMDTT)) feedFPupFsmDtt.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void PnlWdbePrcDetail::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbePrcDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPFSMDTT)) feedFPupFsmDtt.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
