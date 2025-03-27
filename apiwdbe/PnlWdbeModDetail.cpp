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
	if (s == "butimbnewclick") return BUTIMBNEWCLICK;
	if (s == "butimbdeleteclick") return BUTIMBDELETECLICK;
	if (s == "butctrnewclick") return BUTCTRNEWCLICK;
	if (s == "butctrdeleteclick") return BUTCTRDELETECLICK;
	if (s == "butctrclrviewclick") return BUTCTRCLRVIEWCLICK;

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
	if (ix == BUTIMBNEWCLICK) return("ButImbNewClick");
	if (ix == BUTIMBDELETECLICK) return("ButImbDeleteClick");
	if (ix == BUTCTRNEWCLICK) return("ButCtrNewClick");
	if (ix == BUTCTRDELETECLICK) return("ButCtrDeleteClick");
	if (ix == BUTCTRCLRVIEWCLICK) return("ButCtrClrViewClick");

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
			, const string& TxfImbFsr
			, const uint numFPupImbRty
			, const string& TxfImbWid
			, const string& TxfImbMmx
			, const string& TxfImbPri
			, const string& TxfCtrFsr
		) :
			Block()
			, numFPupVnd(numFPupVnd)
			, TxfVnd(TxfVnd)
			, numFPupTyp(numFPupTyp)
			, numFPupHkt(numFPupHkt)
			, TxfSrr(TxfSrr)
			, TxfCmt(TxfCmt)
			, TxfImbFsr(TxfImbFsr)
			, numFPupImbRty(numFPupImbRty)
			, TxfImbWid(TxfImbWid)
			, TxfImbMmx(TxfImbMmx)
			, TxfImbPri(TxfImbPri)
			, TxfCtrFsr(TxfCtrFsr)
		{
	mask = {NUMFPUPVND, TXFVND, NUMFPUPTYP, NUMFPUPHKT, TXFSRR, TXFCMT, TXFIMBFSR, NUMFPUPIMBRTY, TXFIMBWID, TXFIMBMMX, TXFIMBPRI, TXFCTRFSR};
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
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfImbFsr", TxfImbFsr)) add(TXFIMBFSR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupImbRty", numFPupImbRty)) add(NUMFPUPIMBRTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfImbWid", TxfImbWid)) add(TXFIMBWID);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfImbMmx", TxfImbMmx)) add(TXFIMBMMX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfImbPri", TxfImbPri)) add(TXFIMBPRI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCtrFsr", TxfCtrFsr)) add(TXFCTRFSR);
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
		writeStringAttr(wr, itemtag, "sref", "TxfImbFsr", TxfImbFsr);
		writeUintAttr(wr, itemtag, "sref", "numFPupImbRty", numFPupImbRty);
		writeStringAttr(wr, itemtag, "sref", "TxfImbWid", TxfImbWid);
		writeStringAttr(wr, itemtag, "sref", "TxfImbMmx", TxfImbMmx);
		writeStringAttr(wr, itemtag, "sref", "TxfImbPri", TxfImbPri);
		writeStringAttr(wr, itemtag, "sref", "TxfCtrFsr", TxfCtrFsr);
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
	if (TxfImbFsr == comp->TxfImbFsr) insert(items, TXFIMBFSR);
	if (numFPupImbRty == comp->numFPupImbRty) insert(items, NUMFPUPIMBRTY);
	if (TxfImbWid == comp->TxfImbWid) insert(items, TXFIMBWID);
	if (TxfImbMmx == comp->TxfImbMmx) insert(items, TXFIMBMMX);
	if (TxfImbPri == comp->TxfImbPri) insert(items, TXFIMBPRI);
	if (TxfCtrFsr == comp->TxfCtrFsr) insert(items, TXFCTRFSR);

	return(items);
};

set<uint> PnlWdbeModDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPVND, TXFVND, NUMFPUPTYP, NUMFPUPHKT, TXFSRR, TXFCMT, TXFIMBFSR, NUMFPUPIMBRTY, TXFIMBWID, TXFIMBMMX, TXFIMBPRI, TXFCTRFSR};
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
			, const string& TxtCtrClr
		) :
			Block()
			, TxtSrf(TxtSrf)
			, TxtHku(TxtHku)
			, TxtSup(TxtSup)
			, TxtTpl(TxtTpl)
			, TxtCtrClr(TxtCtrClr)
		{
	mask = {TXTSRF, TXTHKU, TXTSUP, TXTTPL, TXTCTRCLR};
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
	if (TxtCtrClr == comp->TxtCtrClr) insert(items, TXTCTRCLR);

	return(items);
};

set<uint> PnlWdbeModDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTHKU, TXTSUP, TXTTPL, TXTCTRCLR};
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
			, ixWdbeVExpstate(ixWdbeVExpstate)
			, PupVndAlt(PupVndAlt)
		{
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
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool PupVndActive
			, const bool TxfVndValid
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
			, const bool SepCtrAvail
			, const bool HdgCtrAvail
			, const bool ButCtrNewAvail
			, const bool ButCtrDeleteAvail
			, const bool TxfCtrFsrAvail
			, const bool TxfCtrFsrActive
			, const bool TxtCtrClrAvail
			, const bool TxtCtrClrActive
			, const bool ButCtrClrViewAvail
			, const bool ButCtrClrViewActive
		) :
			Block()
			, ButSaveAvail(ButSaveAvail)
			, ButSaveActive(ButSaveActive)
			, TxtSrfActive(TxtSrfActive)
			, PupVndActive(PupVndActive)
			, TxfVndValid(TxfVndValid)
			, ButVndEditAvail(ButVndEditAvail)
			, PupTypActive(PupTypActive)
			, TxtHkuActive(TxtHkuActive)
			, ButHkuViewAvail(ButHkuViewAvail)
			, ButHkuViewActive(ButHkuViewActive)
			, TxtSupActive(TxtSupActive)
			, ButSupViewAvail(ButSupViewAvail)
			, ButSupViewActive(ButSupViewActive)
			, TxtTplActive(TxtTplActive)
			, ButTplViewAvail(ButTplViewAvail)
			, ButTplViewActive(ButTplViewActive)
			, TxfSrrActive(TxfSrrActive)
			, TxfCmtActive(TxfCmtActive)
			, SepImbAvail(SepImbAvail)
			, HdgImbAvail(HdgImbAvail)
			, ButImbNewAvail(ButImbNewAvail)
			, ButImbDeleteAvail(ButImbDeleteAvail)
			, TxfImbFsrAvail(TxfImbFsrAvail)
			, TxfImbFsrActive(TxfImbFsrActive)
			, PupImbRtyAvail(PupImbRtyAvail)
			, PupImbRtyActive(PupImbRtyActive)
			, TxfImbWidAvail(TxfImbWidAvail)
			, TxfImbWidActive(TxfImbWidActive)
			, TxfImbMmxAvail(TxfImbMmxAvail)
			, TxfImbMmxActive(TxfImbMmxActive)
			, TxfImbPriAvail(TxfImbPriAvail)
			, TxfImbPriActive(TxfImbPriActive)
			, SepCtrAvail(SepCtrAvail)
			, HdgCtrAvail(HdgCtrAvail)
			, ButCtrNewAvail(ButCtrNewAvail)
			, ButCtrDeleteAvail(ButCtrDeleteAvail)
			, TxfCtrFsrAvail(TxfCtrFsrAvail)
			, TxfCtrFsrActive(TxfCtrFsrActive)
			, TxtCtrClrAvail(TxtCtrClrAvail)
			, TxtCtrClrActive(TxtCtrClrActive)
			, ButCtrClrViewAvail(ButCtrClrViewAvail)
			, ButCtrClrViewActive(ButCtrClrViewActive)
		{
	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPVNDACTIVE, TXFVNDVALID, BUTVNDEDITAVAIL, PUPTYPACTIVE, TXTHKUACTIVE, BUTHKUVIEWAVAIL, BUTHKUVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTPLACTIVE, BUTTPLVIEWAVAIL, BUTTPLVIEWACTIVE, TXFSRRACTIVE, TXFCMTACTIVE, SEPIMBAVAIL, HDGIMBAVAIL, BUTIMBNEWAVAIL, BUTIMBDELETEAVAIL, TXFIMBFSRAVAIL, TXFIMBFSRACTIVE, PUPIMBRTYAVAIL, PUPIMBRTYACTIVE, TXFIMBWIDAVAIL, TXFIMBWIDACTIVE, TXFIMBMMXAVAIL, TXFIMBMMXACTIVE, TXFIMBPRIAVAIL, TXFIMBPRIACTIVE, SEPCTRAVAIL, HDGCTRAVAIL, BUTCTRNEWAVAIL, BUTCTRDELETEAVAIL, TXFCTRFSRAVAIL, TXFCTRFSRACTIVE, TXTCTRCLRAVAIL, TXTCTRCLRACTIVE, BUTCTRCLRVIEWAVAIL, BUTCTRCLRVIEWACTIVE};
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
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupVndActive", PupVndActive)) add(PUPVNDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfVndValid", TxfVndValid)) add(TXFVNDVALID);
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
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SepCtrAvail", SepCtrAvail)) add(SEPCTRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "HdgCtrAvail", HdgCtrAvail)) add(HDGCTRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCtrNewAvail", ButCtrNewAvail)) add(BUTCTRNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCtrDeleteAvail", ButCtrDeleteAvail)) add(BUTCTRDELETEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCtrFsrAvail", TxfCtrFsrAvail)) add(TXFCTRFSRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCtrFsrActive", TxfCtrFsrActive)) add(TXFCTRFSRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCtrClrAvail", TxtCtrClrAvail)) add(TXTCTRCLRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCtrClrActive", TxtCtrClrActive)) add(TXTCTRCLRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCtrClrViewAvail", ButCtrClrViewAvail)) add(BUTCTRCLRVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCtrClrViewActive", ButCtrClrViewActive)) add(BUTCTRCLRVIEWACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbeModDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (PupVndActive == comp->PupVndActive) insert(items, PUPVNDACTIVE);
	if (TxfVndValid == comp->TxfVndValid) insert(items, TXFVNDVALID);
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
	if (SepCtrAvail == comp->SepCtrAvail) insert(items, SEPCTRAVAIL);
	if (HdgCtrAvail == comp->HdgCtrAvail) insert(items, HDGCTRAVAIL);
	if (ButCtrNewAvail == comp->ButCtrNewAvail) insert(items, BUTCTRNEWAVAIL);
	if (ButCtrDeleteAvail == comp->ButCtrDeleteAvail) insert(items, BUTCTRDELETEAVAIL);
	if (TxfCtrFsrAvail == comp->TxfCtrFsrAvail) insert(items, TXFCTRFSRAVAIL);
	if (TxfCtrFsrActive == comp->TxfCtrFsrActive) insert(items, TXFCTRFSRACTIVE);
	if (TxtCtrClrAvail == comp->TxtCtrClrAvail) insert(items, TXTCTRCLRAVAIL);
	if (TxtCtrClrActive == comp->TxtCtrClrActive) insert(items, TXTCTRCLRACTIVE);
	if (ButCtrClrViewAvail == comp->ButCtrClrViewAvail) insert(items, BUTCTRCLRVIEWAVAIL);
	if (ButCtrClrViewActive == comp->ButCtrClrViewActive) insert(items, BUTCTRCLRVIEWACTIVE);

	return(items);
};

set<uint> PnlWdbeModDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPVNDACTIVE, TXFVNDVALID, BUTVNDEDITAVAIL, PUPTYPACTIVE, TXTHKUACTIVE, BUTHKUVIEWAVAIL, BUTHKUVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTPLACTIVE, BUTTPLVIEWAVAIL, BUTTPLVIEWACTIVE, TXFSRRACTIVE, TXFCMTACTIVE, SEPIMBAVAIL, HDGIMBAVAIL, BUTIMBNEWAVAIL, BUTIMBDELETEAVAIL, TXFIMBFSRAVAIL, TXFIMBFSRACTIVE, PUPIMBRTYAVAIL, PUPIMBRTYACTIVE, TXFIMBWIDAVAIL, TXFIMBWIDACTIVE, TXFIMBMMXAVAIL, TXFIMBMMXACTIVE, TXFIMBPRIAVAIL, TXFIMBPRIACTIVE, SEPCTRAVAIL, HDGCTRAVAIL, BUTCTRNEWAVAIL, BUTCTRDELETEAVAIL, TXFCTRFSRAVAIL, TXFCTRFSRACTIVE, TXTCTRCLRAVAIL, TXTCTRCLRACTIVE, BUTCTRCLRVIEWAVAIL, BUTCTRCLRVIEWACTIVE};
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
			, const string& HdgImb
			, const string& CptImbFsr
			, const string& CptImbRty
			, const string& CptImbWid
			, const string& CptImbMmx
			, const string& CptImbPri
			, const string& HdgCtr
			, const string& CptCtrFsr
			, const string& CptCtrClr
		) :
			Block()
			, Cpt(Cpt)
			, CptSrf(CptSrf)
			, CptVnd(CptVnd)
			, CptTyp(CptTyp)
			, CptHku(CptHku)
			, CptSup(CptSup)
			, CptTpl(CptTpl)
			, CptSrr(CptSrr)
			, CptCmt(CptCmt)
			, HdgImb(HdgImb)
			, CptImbFsr(CptImbFsr)
			, CptImbRty(CptImbRty)
			, CptImbWid(CptImbWid)
			, CptImbMmx(CptImbMmx)
			, CptImbPri(CptImbPri)
			, HdgCtr(HdgCtr)
			, CptCtrFsr(CptCtrFsr)
			, CptCtrClr(CptCtrClr)
		{
	mask = {CPT, CPTSRF, CPTVND, CPTTYP, CPTHKU, CPTSUP, CPTTPL, CPTSRR, CPTCMT, HDGIMB, CPTIMBFSR, CPTIMBRTY, CPTIMBWID, CPTIMBMMX, CPTIMBPRI, HDGCTR, CPTCTRFSR, CPTCTRCLR};
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
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgImb", HdgImb)) add(HDGIMB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptImbFsr", CptImbFsr)) add(CPTIMBFSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptImbRty", CptImbRty)) add(CPTIMBRTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptImbWid", CptImbWid)) add(CPTIMBWID);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptImbMmx", CptImbMmx)) add(CPTIMBMMX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptImbPri", CptImbPri)) add(CPTIMBPRI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgCtr", HdgCtr)) add(HDGCTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCtrFsr", CptCtrFsr)) add(CPTCTRFSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCtrClr", CptCtrClr)) add(CPTCTRCLR);
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
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

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
