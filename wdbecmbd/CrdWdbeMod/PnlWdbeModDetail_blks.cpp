/**
	* \file PnlWdbeModDetail_blks.cpp
	* job handler for job PnlWdbeModDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeModDetail::VecVDo
 ******************************************************************************/

uint PnlWdbeModDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butvndeditclick") return BUTVNDEDITCLICK;
	if (s == "buthkuviewclick") return BUTHKUVIEWCLICK;
	if (s == "butsupviewclick") return BUTSUPVIEWCLICK;
	if (s == "buttplviewclick") return BUTTPLVIEWCLICK;
	if (s == "butctrnewclick") return BUTCTRNEWCLICK;
	if (s == "butctrdeleteclick") return BUTCTRDELETECLICK;
	if (s == "butctrfwdviewclick") return BUTCTRFWDVIEWCLICK;
	if (s == "butctrclrviewclick") return BUTCTRCLRVIEWCLICK;
	if (s == "butimbnewclick") return BUTIMBNEWCLICK;
	if (s == "butimbdeleteclick") return BUTIMBDELETECLICK;

	return(0);
};

string PnlWdbeModDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTVNDEDITCLICK) return("ButVndEditClick");
	if (ix == BUTHKUVIEWCLICK) return("ButHkuViewClick");
	if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");
	if (ix == BUTTPLVIEWCLICK) return("ButTplViewClick");
	if (ix == BUTCTRNEWCLICK) return("ButCtrNewClick");
	if (ix == BUTCTRDELETECLICK) return("ButCtrDeleteClick");
	if (ix == BUTCTRFWDVIEWCLICK) return("ButCtrFwdViewClick");
	if (ix == BUTCTRCLRVIEWCLICK) return("ButCtrClrViewClick");
	if (ix == BUTIMBNEWCLICK) return("ButImbNewClick");
	if (ix == BUTIMBDELETECLICK) return("ButImbDeleteClick");

	return("");
};

/******************************************************************************
 class PnlWdbeModDetail::ContIac
 ******************************************************************************/

PnlWdbeModDetail::ContIac::ContIac(
			const uint numFPupVnd
			, const string& TxfVnd
			, const uint numFPupTyp
			, const uint numFPupHkt
			, const string& TxfSrr
			, const string& TxfCmt
			, const string& TxfCtrFsr
			, const string& TxfImbFsr
			, const uint numFPupImbRty
			, const string& TxfImbWid
			, const string& TxfImbMmx
			, const string& TxfImbPri
		) :
			Block()
		{
	this->numFPupVnd = numFPupVnd;
	this->TxfVnd = TxfVnd;
	this->numFPupTyp = numFPupTyp;
	this->numFPupHkt = numFPupHkt;
	this->TxfSrr = TxfSrr;
	this->TxfCmt = TxfCmt;
	this->TxfCtrFsr = TxfCtrFsr;
	this->TxfImbFsr = TxfImbFsr;
	this->numFPupImbRty = numFPupImbRty;
	this->TxfImbWid = TxfImbWid;
	this->TxfImbMmx = TxfImbMmx;
	this->TxfImbPri = TxfImbPri;

	mask = {NUMFPUPVND, TXFVND, NUMFPUPTYP, NUMFPUPHKT, TXFSRR, TXFCMT, TXFCTRFSR, TXFIMBFSR, NUMFPUPIMBRTY, TXFIMBWID, TXFIMBMMX, TXFIMBPRI};
};

bool PnlWdbeModDetail::ContIac::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["ContIacWdbeModDetail"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFPupVnd")) {numFPupVnd = me["numFPupVnd"].asUInt(); add(NUMFPUPVND);};
		if (me.isMember("TxfVnd")) {TxfVnd = me["TxfVnd"].asString(); add(TXFVND);};
		if (me.isMember("numFPupTyp")) {numFPupTyp = me["numFPupTyp"].asUInt(); add(NUMFPUPTYP);};
		if (me.isMember("numFPupHkt")) {numFPupHkt = me["numFPupHkt"].asUInt(); add(NUMFPUPHKT);};
		if (me.isMember("TxfSrr")) {TxfSrr = me["TxfSrr"].asString(); add(TXFSRR);};
		if (me.isMember("TxfCmt")) {TxfCmt = me["TxfCmt"].asString(); add(TXFCMT);};
		if (me.isMember("TxfCtrFsr")) {TxfCtrFsr = me["TxfCtrFsr"].asString(); add(TXFCTRFSR);};
		if (me.isMember("TxfImbFsr")) {TxfImbFsr = me["TxfImbFsr"].asString(); add(TXFIMBFSR);};
		if (me.isMember("numFPupImbRty")) {numFPupImbRty = me["numFPupImbRty"].asUInt(); add(NUMFPUPIMBRTY);};
		if (me.isMember("TxfImbWid")) {TxfImbWid = me["TxfImbWid"].asString(); add(TXFIMBWID);};
		if (me.isMember("TxfImbMmx")) {TxfImbMmx = me["TxfImbMmx"].asString(); add(TXFIMBMMX);};
		if (me.isMember("TxfImbPri")) {TxfImbPri = me["TxfImbPri"].asString(); add(TXFIMBPRI);};
	};

	return basefound;
};

bool PnlWdbeModDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeModDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeModDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupVnd", numFPupVnd)) add(NUMFPUPVND);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfVnd", TxfVnd)) add(TXFVND);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupHkt", numFPupHkt)) add(NUMFPUPHKT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSrr", TxfSrr)) add(TXFSRR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCtrFsr", TxfCtrFsr)) add(TXFCTRFSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfImbFsr", TxfImbFsr)) add(TXFIMBFSR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupImbRty", numFPupImbRty)) add(NUMFPUPIMBRTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfImbWid", TxfImbWid)) add(TXFIMBWID);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfImbMmx", TxfImbMmx)) add(TXFIMBMMX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfImbPri", TxfImbPri)) add(TXFIMBPRI);
	};

	return basefound;
};

void PnlWdbeModDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeModDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFPupVnd"] = numFPupVnd;
	me["TxfVnd"] = TxfVnd;
	me["numFPupTyp"] = numFPupTyp;
	me["numFPupHkt"] = numFPupHkt;
	me["TxfSrr"] = TxfSrr;
	me["TxfCmt"] = TxfCmt;
	me["TxfCtrFsr"] = TxfCtrFsr;
	me["TxfImbFsr"] = TxfImbFsr;
	me["numFPupImbRty"] = numFPupImbRty;
	me["TxfImbWid"] = TxfImbWid;
	me["TxfImbMmx"] = TxfImbMmx;
	me["TxfImbPri"] = TxfImbPri;
};

void PnlWdbeModDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeModDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeModDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupVnd", numFPupVnd);
		writeStringAttr(wr, itemtag, "sref", "TxfVnd", TxfVnd);
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintAttr(wr, itemtag, "sref", "numFPupHkt", numFPupHkt);
		writeStringAttr(wr, itemtag, "sref", "TxfSrr", TxfSrr);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
		writeStringAttr(wr, itemtag, "sref", "TxfCtrFsr", TxfCtrFsr);
		writeStringAttr(wr, itemtag, "sref", "TxfImbFsr", TxfImbFsr);
		writeUintAttr(wr, itemtag, "sref", "numFPupImbRty", numFPupImbRty);
		writeStringAttr(wr, itemtag, "sref", "TxfImbWid", TxfImbWid);
		writeStringAttr(wr, itemtag, "sref", "TxfImbMmx", TxfImbMmx);
		writeStringAttr(wr, itemtag, "sref", "TxfImbPri", TxfImbPri);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeModDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupVnd == comp->numFPupVnd) insert(items, NUMFPUPVND);
	if (TxfVnd == comp->TxfVnd) insert(items, TXFVND);
	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (numFPupHkt == comp->numFPupHkt) insert(items, NUMFPUPHKT);
	if (TxfSrr == comp->TxfSrr) insert(items, TXFSRR);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);
	if (TxfCtrFsr == comp->TxfCtrFsr) insert(items, TXFCTRFSR);
	if (TxfImbFsr == comp->TxfImbFsr) insert(items, TXFIMBFSR);
	if (numFPupImbRty == comp->numFPupImbRty) insert(items, NUMFPUPIMBRTY);
	if (TxfImbWid == comp->TxfImbWid) insert(items, TXFIMBWID);
	if (TxfImbMmx == comp->TxfImbMmx) insert(items, TXFIMBMMX);
	if (TxfImbPri == comp->TxfImbPri) insert(items, TXFIMBPRI);

	return(items);
};

set<uint> PnlWdbeModDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPVND, TXFVND, NUMFPUPTYP, NUMFPUPHKT, TXFSRR, TXFCMT, TXFCTRFSR, TXFIMBFSR, NUMFPUPIMBRTY, TXFIMBWID, TXFIMBMMX, TXFIMBPRI};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeModDetail::ContInf
 ******************************************************************************/

PnlWdbeModDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtHku
			, const string& TxtSup
			, const string& TxtTpl
			, const string& TxtCtrFwd
			, const string& TxtCtrClr
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtHku = TxtHku;
	this->TxtSup = TxtSup;
	this->TxtTpl = TxtTpl;
	this->TxtCtrFwd = TxtCtrFwd;
	this->TxtCtrClr = TxtCtrClr;

	mask = {TXTSRF, TXTHKU, TXTSUP, TXTTPL, TXTCTRFWD, TXTCTRCLR};
};

void PnlWdbeModDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeModDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtSrf"] = TxtSrf;
	me["TxtHku"] = TxtHku;
	me["TxtSup"] = TxtSup;
	me["TxtTpl"] = TxtTpl;
	me["TxtCtrFwd"] = TxtCtrFwd;
	me["TxtCtrClr"] = TxtCtrClr;
};

void PnlWdbeModDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeModDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbeModDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtHku", TxtHku);
		writeStringAttr(wr, itemtag, "sref", "TxtSup", TxtSup);
		writeStringAttr(wr, itemtag, "sref", "TxtTpl", TxtTpl);
		writeStringAttr(wr, itemtag, "sref", "TxtCtrFwd", TxtCtrFwd);
		writeStringAttr(wr, itemtag, "sref", "TxtCtrClr", TxtCtrClr);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeModDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtHku == comp->TxtHku) insert(items, TXTHKU);
	if (TxtSup == comp->TxtSup) insert(items, TXTSUP);
	if (TxtTpl == comp->TxtTpl) insert(items, TXTTPL);
	if (TxtCtrFwd == comp->TxtCtrFwd) insert(items, TXTCTRFWD);
	if (TxtCtrClr == comp->TxtCtrClr) insert(items, TXTCTRCLR);

	return(items);
};

set<uint> PnlWdbeModDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTHKU, TXTSUP, TXTTPL, TXTCTRFWD, TXTCTRCLR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeModDetail::StatApp
 ******************************************************************************/

void PnlWdbeModDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWdbeVExpstate
			, const bool PupVndAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeModDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
	me["PupVndAlt"] = PupVndAlt;
};

void PnlWdbeModDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
			, const bool PupVndAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeModDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeModDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "PupVndAlt", PupVndAlt);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeModDetail::StatShr
 ******************************************************************************/

PnlWdbeModDetail::StatShr::StatShr(
			const bool TxfVndValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool PupVndActive
			, const bool ButVndEditAvail
			, const bool PupTypActive
			, const bool TxtHkuActive
			, const bool ButHkuViewAvail
			, const bool ButHkuViewActive
			, const bool TxtSupActive
			, const bool ButSupViewAvail
			, const bool ButSupViewActive
			, const bool TxtTplActive
			, const bool ButTplViewAvail
			, const bool ButTplViewActive
			, const bool TxfSrrActive
			, const bool TxfCmtActive
			, const bool SepCtrAvail
			, const bool HdgCtrAvail
			, const bool ButCtrNewAvail
			, const bool ButCtrDeleteAvail
			, const bool TxfCtrFsrAvail
			, const bool TxfCtrFsrActive
			, const bool TxtCtrFwdAvail
			, const bool TxtCtrFwdActive
			, const bool ButCtrFwdViewAvail
			, const bool ButCtrFwdViewActive
			, const bool TxtCtrClrAvail
			, const bool TxtCtrClrActive
			, const bool ButCtrClrViewAvail
			, const bool ButCtrClrViewActive
			, const bool SepImbAvail
			, const bool HdgImbAvail
			, const bool ButImbNewAvail
			, const bool ButImbDeleteAvail
			, const bool TxfImbFsrAvail
			, const bool TxfImbFsrActive
			, const bool PupImbRtyAvail
			, const bool PupImbRtyActive
			, const bool TxfImbWidAvail
			, const bool TxfImbWidActive
			, const bool TxfImbMmxAvail
			, const bool TxfImbMmxActive
			, const bool TxfImbPriAvail
			, const bool TxfImbPriActive
		) :
			Block()
		{
	this->TxfVndValid = TxfVndValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->PupVndActive = PupVndActive;
	this->ButVndEditAvail = ButVndEditAvail;
	this->PupTypActive = PupTypActive;
	this->TxtHkuActive = TxtHkuActive;
	this->ButHkuViewAvail = ButHkuViewAvail;
	this->ButHkuViewActive = ButHkuViewActive;
	this->TxtSupActive = TxtSupActive;
	this->ButSupViewAvail = ButSupViewAvail;
	this->ButSupViewActive = ButSupViewActive;
	this->TxtTplActive = TxtTplActive;
	this->ButTplViewAvail = ButTplViewAvail;
	this->ButTplViewActive = ButTplViewActive;
	this->TxfSrrActive = TxfSrrActive;
	this->TxfCmtActive = TxfCmtActive;
	this->SepCtrAvail = SepCtrAvail;
	this->HdgCtrAvail = HdgCtrAvail;
	this->ButCtrNewAvail = ButCtrNewAvail;
	this->ButCtrDeleteAvail = ButCtrDeleteAvail;
	this->TxfCtrFsrAvail = TxfCtrFsrAvail;
	this->TxfCtrFsrActive = TxfCtrFsrActive;
	this->TxtCtrFwdAvail = TxtCtrFwdAvail;
	this->TxtCtrFwdActive = TxtCtrFwdActive;
	this->ButCtrFwdViewAvail = ButCtrFwdViewAvail;
	this->ButCtrFwdViewActive = ButCtrFwdViewActive;
	this->TxtCtrClrAvail = TxtCtrClrAvail;
	this->TxtCtrClrActive = TxtCtrClrActive;
	this->ButCtrClrViewAvail = ButCtrClrViewAvail;
	this->ButCtrClrViewActive = ButCtrClrViewActive;
	this->SepImbAvail = SepImbAvail;
	this->HdgImbAvail = HdgImbAvail;
	this->ButImbNewAvail = ButImbNewAvail;
	this->ButImbDeleteAvail = ButImbDeleteAvail;
	this->TxfImbFsrAvail = TxfImbFsrAvail;
	this->TxfImbFsrActive = TxfImbFsrActive;
	this->PupImbRtyAvail = PupImbRtyAvail;
	this->PupImbRtyActive = PupImbRtyActive;
	this->TxfImbWidAvail = TxfImbWidAvail;
	this->TxfImbWidActive = TxfImbWidActive;
	this->TxfImbMmxAvail = TxfImbMmxAvail;
	this->TxfImbMmxActive = TxfImbMmxActive;
	this->TxfImbPriAvail = TxfImbPriAvail;
	this->TxfImbPriActive = TxfImbPriActive;

	mask = {TXFVNDVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPVNDACTIVE, BUTVNDEDITAVAIL, PUPTYPACTIVE, TXTHKUACTIVE, BUTHKUVIEWAVAIL, BUTHKUVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTPLACTIVE, BUTTPLVIEWAVAIL, BUTTPLVIEWACTIVE, TXFSRRACTIVE, TXFCMTACTIVE, SEPCTRAVAIL, HDGCTRAVAIL, BUTCTRNEWAVAIL, BUTCTRDELETEAVAIL, TXFCTRFSRAVAIL, TXFCTRFSRACTIVE, TXTCTRFWDAVAIL, TXTCTRFWDACTIVE, BUTCTRFWDVIEWAVAIL, BUTCTRFWDVIEWACTIVE, TXTCTRCLRAVAIL, TXTCTRCLRACTIVE, BUTCTRCLRVIEWAVAIL, BUTCTRCLRVIEWACTIVE, SEPIMBAVAIL, HDGIMBAVAIL, BUTIMBNEWAVAIL, BUTIMBDELETEAVAIL, TXFIMBFSRAVAIL, TXFIMBFSRACTIVE, PUPIMBRTYAVAIL, PUPIMBRTYACTIVE, TXFIMBWIDAVAIL, TXFIMBWIDACTIVE, TXFIMBMMXAVAIL, TXFIMBMMXACTIVE, TXFIMBPRIAVAIL, TXFIMBPRIACTIVE};
};

void PnlWdbeModDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeModDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfVndValid"] = TxfVndValid;
	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtSrfActive"] = TxtSrfActive;
	me["PupVndActive"] = PupVndActive;
	me["ButVndEditAvail"] = ButVndEditAvail;
	me["PupTypActive"] = PupTypActive;
	me["TxtHkuActive"] = TxtHkuActive;
	me["ButHkuViewAvail"] = ButHkuViewAvail;
	me["ButHkuViewActive"] = ButHkuViewActive;
	me["TxtSupActive"] = TxtSupActive;
	me["ButSupViewAvail"] = ButSupViewAvail;
	me["ButSupViewActive"] = ButSupViewActive;
	me["TxtTplActive"] = TxtTplActive;
	me["ButTplViewAvail"] = ButTplViewAvail;
	me["ButTplViewActive"] = ButTplViewActive;
	me["TxfSrrActive"] = TxfSrrActive;
	me["TxfCmtActive"] = TxfCmtActive;
	me["SepCtrAvail"] = SepCtrAvail;
	me["HdgCtrAvail"] = HdgCtrAvail;
	me["ButCtrNewAvail"] = ButCtrNewAvail;
	me["ButCtrDeleteAvail"] = ButCtrDeleteAvail;
	me["TxfCtrFsrAvail"] = TxfCtrFsrAvail;
	me["TxfCtrFsrActive"] = TxfCtrFsrActive;
	me["TxtCtrFwdAvail"] = TxtCtrFwdAvail;
	me["TxtCtrFwdActive"] = TxtCtrFwdActive;
	me["ButCtrFwdViewAvail"] = ButCtrFwdViewAvail;
	me["ButCtrFwdViewActive"] = ButCtrFwdViewActive;
	me["TxtCtrClrAvail"] = TxtCtrClrAvail;
	me["TxtCtrClrActive"] = TxtCtrClrActive;
	me["ButCtrClrViewAvail"] = ButCtrClrViewAvail;
	me["ButCtrClrViewActive"] = ButCtrClrViewActive;
	me["SepImbAvail"] = SepImbAvail;
	me["HdgImbAvail"] = HdgImbAvail;
	me["ButImbNewAvail"] = ButImbNewAvail;
	me["ButImbDeleteAvail"] = ButImbDeleteAvail;
	me["TxfImbFsrAvail"] = TxfImbFsrAvail;
	me["TxfImbFsrActive"] = TxfImbFsrActive;
	me["PupImbRtyAvail"] = PupImbRtyAvail;
	me["PupImbRtyActive"] = PupImbRtyActive;
	me["TxfImbWidAvail"] = TxfImbWidAvail;
	me["TxfImbWidActive"] = TxfImbWidActive;
	me["TxfImbMmxAvail"] = TxfImbMmxAvail;
	me["TxfImbMmxActive"] = TxfImbMmxActive;
	me["TxfImbPriAvail"] = TxfImbPriAvail;
	me["TxfImbPriActive"] = TxfImbPriActive;
};

void PnlWdbeModDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeModDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeModDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfVndValid", TxfVndValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "PupVndActive", PupVndActive);
		writeBoolAttr(wr, itemtag, "sref", "ButVndEditAvail", ButVndEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "PupTypActive", PupTypActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtHkuActive", TxtHkuActive);
		writeBoolAttr(wr, itemtag, "sref", "ButHkuViewAvail", ButHkuViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButHkuViewActive", ButHkuViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSupActive", TxtSupActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSupViewAvail", ButSupViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSupViewActive", ButSupViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtTplActive", TxtTplActive);
		writeBoolAttr(wr, itemtag, "sref", "ButTplViewAvail", ButTplViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButTplViewActive", ButTplViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfSrrActive", TxfSrrActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
		writeBoolAttr(wr, itemtag, "sref", "SepCtrAvail", SepCtrAvail);
		writeBoolAttr(wr, itemtag, "sref", "HdgCtrAvail", HdgCtrAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCtrNewAvail", ButCtrNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCtrDeleteAvail", ButCtrDeleteAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfCtrFsrAvail", TxfCtrFsrAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfCtrFsrActive", TxfCtrFsrActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtCtrFwdAvail", TxtCtrFwdAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtCtrFwdActive", TxtCtrFwdActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCtrFwdViewAvail", ButCtrFwdViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCtrFwdViewActive", ButCtrFwdViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtCtrClrAvail", TxtCtrClrAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtCtrClrActive", TxtCtrClrActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCtrClrViewAvail", ButCtrClrViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCtrClrViewActive", ButCtrClrViewActive);
		writeBoolAttr(wr, itemtag, "sref", "SepImbAvail", SepImbAvail);
		writeBoolAttr(wr, itemtag, "sref", "HdgImbAvail", HdgImbAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButImbNewAvail", ButImbNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButImbDeleteAvail", ButImbDeleteAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfImbFsrAvail", TxfImbFsrAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfImbFsrActive", TxfImbFsrActive);
		writeBoolAttr(wr, itemtag, "sref", "PupImbRtyAvail", PupImbRtyAvail);
		writeBoolAttr(wr, itemtag, "sref", "PupImbRtyActive", PupImbRtyActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfImbWidAvail", TxfImbWidAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfImbWidActive", TxfImbWidActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfImbMmxAvail", TxfImbMmxAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfImbMmxActive", TxfImbMmxActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfImbPriAvail", TxfImbPriAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfImbPriActive", TxfImbPriActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeModDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfVndValid == comp->TxfVndValid) insert(items, TXFVNDVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (PupVndActive == comp->PupVndActive) insert(items, PUPVNDACTIVE);
	if (ButVndEditAvail == comp->ButVndEditAvail) insert(items, BUTVNDEDITAVAIL);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (TxtHkuActive == comp->TxtHkuActive) insert(items, TXTHKUACTIVE);
	if (ButHkuViewAvail == comp->ButHkuViewAvail) insert(items, BUTHKUVIEWAVAIL);
	if (ButHkuViewActive == comp->ButHkuViewActive) insert(items, BUTHKUVIEWACTIVE);
	if (TxtSupActive == comp->TxtSupActive) insert(items, TXTSUPACTIVE);
	if (ButSupViewAvail == comp->ButSupViewAvail) insert(items, BUTSUPVIEWAVAIL);
	if (ButSupViewActive == comp->ButSupViewActive) insert(items, BUTSUPVIEWACTIVE);
	if (TxtTplActive == comp->TxtTplActive) insert(items, TXTTPLACTIVE);
	if (ButTplViewAvail == comp->ButTplViewAvail) insert(items, BUTTPLVIEWAVAIL);
	if (ButTplViewActive == comp->ButTplViewActive) insert(items, BUTTPLVIEWACTIVE);
	if (TxfSrrActive == comp->TxfSrrActive) insert(items, TXFSRRACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);
	if (SepCtrAvail == comp->SepCtrAvail) insert(items, SEPCTRAVAIL);
	if (HdgCtrAvail == comp->HdgCtrAvail) insert(items, HDGCTRAVAIL);
	if (ButCtrNewAvail == comp->ButCtrNewAvail) insert(items, BUTCTRNEWAVAIL);
	if (ButCtrDeleteAvail == comp->ButCtrDeleteAvail) insert(items, BUTCTRDELETEAVAIL);
	if (TxfCtrFsrAvail == comp->TxfCtrFsrAvail) insert(items, TXFCTRFSRAVAIL);
	if (TxfCtrFsrActive == comp->TxfCtrFsrActive) insert(items, TXFCTRFSRACTIVE);
	if (TxtCtrFwdAvail == comp->TxtCtrFwdAvail) insert(items, TXTCTRFWDAVAIL);
	if (TxtCtrFwdActive == comp->TxtCtrFwdActive) insert(items, TXTCTRFWDACTIVE);
	if (ButCtrFwdViewAvail == comp->ButCtrFwdViewAvail) insert(items, BUTCTRFWDVIEWAVAIL);
	if (ButCtrFwdViewActive == comp->ButCtrFwdViewActive) insert(items, BUTCTRFWDVIEWACTIVE);
	if (TxtCtrClrAvail == comp->TxtCtrClrAvail) insert(items, TXTCTRCLRAVAIL);
	if (TxtCtrClrActive == comp->TxtCtrClrActive) insert(items, TXTCTRCLRACTIVE);
	if (ButCtrClrViewAvail == comp->ButCtrClrViewAvail) insert(items, BUTCTRCLRVIEWAVAIL);
	if (ButCtrClrViewActive == comp->ButCtrClrViewActive) insert(items, BUTCTRCLRVIEWACTIVE);
	if (SepImbAvail == comp->SepImbAvail) insert(items, SEPIMBAVAIL);
	if (HdgImbAvail == comp->HdgImbAvail) insert(items, HDGIMBAVAIL);
	if (ButImbNewAvail == comp->ButImbNewAvail) insert(items, BUTIMBNEWAVAIL);
	if (ButImbDeleteAvail == comp->ButImbDeleteAvail) insert(items, BUTIMBDELETEAVAIL);
	if (TxfImbFsrAvail == comp->TxfImbFsrAvail) insert(items, TXFIMBFSRAVAIL);
	if (TxfImbFsrActive == comp->TxfImbFsrActive) insert(items, TXFIMBFSRACTIVE);
	if (PupImbRtyAvail == comp->PupImbRtyAvail) insert(items, PUPIMBRTYAVAIL);
	if (PupImbRtyActive == comp->PupImbRtyActive) insert(items, PUPIMBRTYACTIVE);
	if (TxfImbWidAvail == comp->TxfImbWidAvail) insert(items, TXFIMBWIDAVAIL);
	if (TxfImbWidActive == comp->TxfImbWidActive) insert(items, TXFIMBWIDACTIVE);
	if (TxfImbMmxAvail == comp->TxfImbMmxAvail) insert(items, TXFIMBMMXAVAIL);
	if (TxfImbMmxActive == comp->TxfImbMmxActive) insert(items, TXFIMBMMXACTIVE);
	if (TxfImbPriAvail == comp->TxfImbPriAvail) insert(items, TXFIMBPRIAVAIL);
	if (TxfImbPriActive == comp->TxfImbPriActive) insert(items, TXFIMBPRIACTIVE);

	return(items);
};

set<uint> PnlWdbeModDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFVNDVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPVNDACTIVE, BUTVNDEDITAVAIL, PUPTYPACTIVE, TXTHKUACTIVE, BUTHKUVIEWAVAIL, BUTHKUVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTPLACTIVE, BUTTPLVIEWAVAIL, BUTTPLVIEWACTIVE, TXFSRRACTIVE, TXFCMTACTIVE, SEPCTRAVAIL, HDGCTRAVAIL, BUTCTRNEWAVAIL, BUTCTRDELETEAVAIL, TXFCTRFSRAVAIL, TXFCTRFSRACTIVE, TXTCTRFWDAVAIL, TXTCTRFWDACTIVE, BUTCTRFWDVIEWAVAIL, BUTCTRFWDVIEWACTIVE, TXTCTRCLRAVAIL, TXTCTRCLRACTIVE, BUTCTRCLRVIEWAVAIL, BUTCTRCLRVIEWACTIVE, SEPIMBAVAIL, HDGIMBAVAIL, BUTIMBNEWAVAIL, BUTIMBDELETEAVAIL, TXFIMBFSRAVAIL, TXFIMBFSRACTIVE, PUPIMBRTYAVAIL, PUPIMBRTYACTIVE, TXFIMBWIDAVAIL, TXFIMBWIDACTIVE, TXFIMBMMXAVAIL, TXFIMBMMXACTIVE, TXFIMBPRIAVAIL, TXFIMBPRIACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeModDetail::Tag
 ******************************************************************************/

void PnlWdbeModDetail::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbeModDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["CptSrf"] = "identifier";
		me["CptVnd"] = "vendor";
		me["CptTyp"] = "type";
		me["CptHku"] = "hook";
		me["CptSup"] = "super module";
		me["CptTpl"] = "template";
		me["CptSrr"] = "identifier rule";
		me["CptCmt"] = "comment";
		me["HdgCtr"] = "Controller";
		me["CptCtrFsr"] = "full identifier";
		me["CptCtrFwd"] = "unit forwarded to";
		me["CptCtrClr"] = "command lock request signal";
		me["HdgImb"] = "Inter-module buffer";
		me["CptImbFsr"] = "full identifier";
		me["CptImbRty"] = "read-out type";
		me["CptImbWid"] = "width";
		me["CptImbMmx"] = "range";
		me["CptImbPri"] = "priority";
	};
	me["Cpt"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale));
};

void PnlWdbeModDetail::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeModDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeModDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptVnd", "vendor");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "type");
			writeStringAttr(wr, itemtag, "sref", "CptHku", "hook");
			writeStringAttr(wr, itemtag, "sref", "CptSup", "super module");
			writeStringAttr(wr, itemtag, "sref", "CptTpl", "template");
			writeStringAttr(wr, itemtag, "sref", "CptSrr", "identifier rule");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
			writeStringAttr(wr, itemtag, "sref", "HdgCtr", "Controller");
			writeStringAttr(wr, itemtag, "sref", "CptCtrFsr", "full identifier");
			writeStringAttr(wr, itemtag, "sref", "CptCtrFwd", "unit forwarded to");
			writeStringAttr(wr, itemtag, "sref", "CptCtrClr", "command lock request signal");
			writeStringAttr(wr, itemtag, "sref", "HdgImb", "Inter-module buffer");
			writeStringAttr(wr, itemtag, "sref", "CptImbFsr", "full identifier");
			writeStringAttr(wr, itemtag, "sref", "CptImbRty", "read-out type");
			writeStringAttr(wr, itemtag, "sref", "CptImbWid", "width");
			writeStringAttr(wr, itemtag, "sref", "CptImbMmx", "range");
			writeStringAttr(wr, itemtag, "sref", "CptImbPri", "priority");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeModDetail::DpchAppData
 ******************************************************************************/

PnlWdbeModDetail::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEMODDETAILDATA)
		{
};

string PnlWdbeModDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeModDetail::DpchAppData::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWdbeModDetailData"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWdbeModDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeModDetailData");
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
 class PnlWdbeModDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeModDetail::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEMODDETAILDO)
		{
	ixVDo = 0;
};

string PnlWdbeModDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeModDetail::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWdbeModDetailDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWdbeModDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeModDetailDo");
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
 class PnlWdbeModDetail::DpchEngData
 ******************************************************************************/

PnlWdbeModDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupHkt
			, Feed* feedFPupImbRty
			, Feed* feedFPupTyp
			, Feed* feedFPupVnd
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEMODDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPHKT, FEEDFPUPIMBRTY, FEEDFPUPTYP, FEEDFPUPVND, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPHKT) && feedFPupHkt) this->feedFPupHkt = *feedFPupHkt;
	if (find(this->mask, FEEDFPUPIMBRTY) && feedFPupImbRty) this->feedFPupImbRty = *feedFPupImbRty;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, FEEDFPUPVND) && feedFPupVnd) this->feedFPupVnd = *feedFPupVnd;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeModDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPHKT)) ss.push_back("feedFPupHkt");
	if (has(FEEDFPUPIMBRTY)) ss.push_back("feedFPupImbRty");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(FEEDFPUPVND)) ss.push_back("feedFPupVnd");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeModDetail::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPHKT)) {feedFPupHkt = src->feedFPupHkt; add(FEEDFPUPHKT);};
	if (src->has(FEEDFPUPIMBRTY)) {feedFPupImbRty = src->feedFPupImbRty; add(FEEDFPUPIMBRTY);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(FEEDFPUPVND)) {feedFPupVnd = src->feedFPupVnd; add(FEEDFPUPVND);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeModDetail::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbeModDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFPUPHKT)) feedFPupHkt.writeJSON(me);
	if (has(FEEDFPUPIMBRTY)) feedFPupImbRty.writeJSON(me);
	if (has(FEEDFPUPTYP)) feedFPupTyp.writeJSON(me);
	if (has(FEEDFPUPVND)) feedFPupVnd.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void PnlWdbeModDetail::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeModDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPHKT)) feedFPupHkt.writeXML(wr);
		if (has(FEEDFPUPIMBRTY)) feedFPupImbRty.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(FEEDFPUPVND)) feedFPupVnd.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
