/**
	* \file PnlWdbeModDetail.cpp
	* API code for job PnlWdbeModDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWdbeModDetail.h"

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

bool PnlWdbeModDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeModDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeModDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtHku", TxtHku)) add(TXTHKU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSup", TxtSup)) add(TXTSUP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTpl", TxtTpl)) add(TXTTPL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCtrFwd", TxtCtrFwd)) add(TXTCTRFWD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCtrClr", TxtCtrClr)) add(TXTCTRCLR);
	};

	return basefound;
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

PnlWdbeModDetail::StatApp::StatApp(
			const uint ixWdbeVExpstate
			, const bool PupVndAlt
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->PupVndAlt = PupVndAlt;

	mask = {IXWDBEVEXPSTATE, PUPVNDALT};
};

bool PnlWdbeModDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeModDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeModDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupVndAlt", PupVndAlt)) add(PUPVNDALT);
	};

	return basefound;
};

set<uint> PnlWdbeModDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (PupVndAlt == comp->PupVndAlt) insert(items, PUPVNDALT);

	return(items);
};

set<uint> PnlWdbeModDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, PUPVNDALT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
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

bool PnlWdbeModDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeModDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeModDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfVndValid", TxfVndValid)) add(TXFVNDVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupVndActive", PupVndActive)) add(PUPVNDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVndEditAvail", ButVndEditAvail)) add(BUTVNDEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTypActive", PupTypActive)) add(PUPTYPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtHkuActive", TxtHkuActive)) add(TXTHKUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButHkuViewAvail", ButHkuViewAvail)) add(BUTHKUVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButHkuViewActive", ButHkuViewActive)) add(BUTHKUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSupActive", TxtSupActive)) add(TXTSUPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSupViewAvail", ButSupViewAvail)) add(BUTSUPVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSupViewActive", ButSupViewActive)) add(BUTSUPVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtTplActive", TxtTplActive)) add(TXTTPLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTplViewAvail", ButTplViewAvail)) add(BUTTPLVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTplViewActive", ButTplViewActive)) add(BUTTPLVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfSrrActive", TxfSrrActive)) add(TXFSRRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SepCtrAvail", SepCtrAvail)) add(SEPCTRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "HdgCtrAvail", HdgCtrAvail)) add(HDGCTRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCtrNewAvail", ButCtrNewAvail)) add(BUTCTRNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCtrDeleteAvail", ButCtrDeleteAvail)) add(BUTCTRDELETEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCtrFsrAvail", TxfCtrFsrAvail)) add(TXFCTRFSRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCtrFsrActive", TxfCtrFsrActive)) add(TXFCTRFSRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCtrFwdAvail", TxtCtrFwdAvail)) add(TXTCTRFWDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCtrFwdActive", TxtCtrFwdActive)) add(TXTCTRFWDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCtrFwdViewAvail", ButCtrFwdViewAvail)) add(BUTCTRFWDVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCtrFwdViewActive", ButCtrFwdViewActive)) add(BUTCTRFWDVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCtrClrAvail", TxtCtrClrAvail)) add(TXTCTRCLRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCtrClrActive", TxtCtrClrActive)) add(TXTCTRCLRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCtrClrViewAvail", ButCtrClrViewAvail)) add(BUTCTRCLRVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCtrClrViewActive", ButCtrClrViewActive)) add(BUTCTRCLRVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SepImbAvail", SepImbAvail)) add(SEPIMBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "HdgImbAvail", HdgImbAvail)) add(HDGIMBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButImbNewAvail", ButImbNewAvail)) add(BUTIMBNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButImbDeleteAvail", ButImbDeleteAvail)) add(BUTIMBDELETEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfImbFsrAvail", TxfImbFsrAvail)) add(TXFIMBFSRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfImbFsrActive", TxfImbFsrActive)) add(TXFIMBFSRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupImbRtyAvail", PupImbRtyAvail)) add(PUPIMBRTYAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupImbRtyActive", PupImbRtyActive)) add(PUPIMBRTYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfImbWidAvail", TxfImbWidAvail)) add(TXFIMBWIDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfImbWidActive", TxfImbWidActive)) add(TXFIMBWIDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfImbMmxAvail", TxfImbMmxAvail)) add(TXFIMBMMXAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfImbMmxActive", TxfImbMmxActive)) add(TXFIMBMMXACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfImbPriAvail", TxfImbPriAvail)) add(TXFIMBPRIAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfImbPriActive", TxfImbPriActive)) add(TXFIMBPRIACTIVE);
	};

	return basefound;
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

PnlWdbeModDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptVnd
			, const string& CptTyp
			, const string& CptHku
			, const string& CptSup
			, const string& CptTpl
			, const string& CptSrr
			, const string& CptCmt
			, const string& HdgCtr
			, const string& CptCtrFsr
			, const string& CptCtrFwd
			, const string& CptCtrClr
			, const string& HdgImb
			, const string& CptImbFsr
			, const string& CptImbRty
			, const string& CptImbWid
			, const string& CptImbMmx
			, const string& CptImbPri
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptVnd = CptVnd;
	this->CptTyp = CptTyp;
	this->CptHku = CptHku;
	this->CptSup = CptSup;
	this->CptTpl = CptTpl;
	this->CptSrr = CptSrr;
	this->CptCmt = CptCmt;
	this->HdgCtr = HdgCtr;
	this->CptCtrFsr = CptCtrFsr;
	this->CptCtrFwd = CptCtrFwd;
	this->CptCtrClr = CptCtrClr;
	this->HdgImb = HdgImb;
	this->CptImbFsr = CptImbFsr;
	this->CptImbRty = CptImbRty;
	this->CptImbWid = CptImbWid;
	this->CptImbMmx = CptImbMmx;
	this->CptImbPri = CptImbPri;

	mask = {CPT, CPTSRF, CPTVND, CPTTYP, CPTHKU, CPTSUP, CPTTPL, CPTSRR, CPTCMT, HDGCTR, CPTCTRFSR, CPTCTRFWD, CPTCTRCLR, HDGIMB, CPTIMBFSR, CPTIMBRTY, CPTIMBWID, CPTIMBMMX, CPTIMBPRI};
};

bool PnlWdbeModDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeModDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeModDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVnd", CptVnd)) add(CPTVND);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptHku", CptHku)) add(CPTHKU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSup", CptSup)) add(CPTSUP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTpl", CptTpl)) add(CPTTPL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrr", CptSrr)) add(CPTSRR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgCtr", HdgCtr)) add(HDGCTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCtrFsr", CptCtrFsr)) add(CPTCTRFSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCtrFwd", CptCtrFwd)) add(CPTCTRFWD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCtrClr", CptCtrClr)) add(CPTCTRCLR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgImb", HdgImb)) add(HDGIMB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptImbFsr", CptImbFsr)) add(CPTIMBFSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptImbRty", CptImbRty)) add(CPTIMBRTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptImbWid", CptImbWid)) add(CPTIMBWID);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptImbMmx", CptImbMmx)) add(CPTIMBMMX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptImbPri", CptImbPri)) add(CPTIMBPRI);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeModDetail::DpchAppData
 ******************************************************************************/

PnlWdbeModDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEMODDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbeModDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeModDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeModDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeModDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeModDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEMODDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbeModDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeModDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeModDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeModDetail::DpchEngData
 ******************************************************************************/

PnlWdbeModDetail::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEMODDETAILDATA)
		{
	feedFPupHkt.tag = "FeedFPupHkt";
	feedFPupImbRty.tag = "FeedFPupImbRty";
	feedFPupTyp.tag = "FeedFPupTyp";
	feedFPupVnd.tag = "FeedFPupVnd";
};

string PnlWdbeModDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
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

void PnlWdbeModDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeModDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupHkt.readXML(docctx, basexpath, true)) add(FEEDFPUPHKT);
		if (feedFPupImbRty.readXML(docctx, basexpath, true)) add(FEEDFPUPIMBRTY);
		if (feedFPupTyp.readXML(docctx, basexpath, true)) add(FEEDFPUPTYP);
		if (feedFPupVnd.readXML(docctx, basexpath, true)) add(FEEDFPUPVND);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupHkt.clear();
		feedFPupImbRty.clear();
		feedFPupTyp.clear();
		feedFPupVnd.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
