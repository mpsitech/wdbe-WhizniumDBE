/**
	* \file PnlWdbeSilDetail.cpp
	* API code for job PnlWdbeSilDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWdbeSilDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeSilDetail::VecVDo
 ******************************************************************************/

uint PnlWdbeSilDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butreuviewclick") return BUTREUVIEWCLICK;
	if (s == "butsysviewclick") return BUTSYSVIEWCLICK;
	if (s == "butmdlviewclick") return BUTMDLVIEWCLICK;
	if (s == "butpkgeditclick") return BUTPKGEDITCLICK;
	if (s == "buttcheditclick") return BUTTCHEDITCLICK;

	return(0);
};

string PnlWdbeSilDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");
	if (ix == BUTSYSVIEWCLICK) return("ButSysViewClick");
	if (ix == BUTMDLVIEWCLICK) return("ButMdlViewClick");
	if (ix == BUTPKGEDITCLICK) return("ButPkgEditClick");
	if (ix == BUTTCHEDITCLICK) return("ButTchEditClick");

	return("");
};

/******************************************************************************
 class PnlWdbeSilDetail::ContIac
 ******************************************************************************/

PnlWdbeSilDetail::ContIac::ContIac(
			const string& TxfTit
			, const string& TxfFsr
			, const uint numFPupTyp
			, const uint numFPupRet
			, const uint numFPupPkg
			, const string& TxfPkg
			, const bool ChkEsy
			, const uint numFPupTch
			, const string& TxfTch
			, const string& TxfCmt
		) :
			Block()
		{
	this->TxfTit = TxfTit;
	this->TxfFsr = TxfFsr;
	this->numFPupTyp = numFPupTyp;
	this->numFPupRet = numFPupRet;
	this->numFPupPkg = numFPupPkg;
	this->TxfPkg = TxfPkg;
	this->ChkEsy = ChkEsy;
	this->numFPupTch = numFPupTch;
	this->TxfTch = TxfTch;
	this->TxfCmt = TxfCmt;

	mask = {TXFTIT, TXFFSR, NUMFPUPTYP, NUMFPUPRET, NUMFPUPPKG, TXFPKG, CHKESY, NUMFPUPTCH, TXFTCH, TXFCMT};
};

bool PnlWdbeSilDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeSilDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeSilDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFsr", TxfFsr)) add(TXFFSR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRet", numFPupRet)) add(NUMFPUPRET);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupPkg", numFPupPkg)) add(NUMFPUPPKG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPkg", TxfPkg)) add(TXFPKG);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkEsy", ChkEsy)) add(CHKESY);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTch", numFPupTch)) add(NUMFPUPTCH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTch", TxfTch)) add(TXFTCH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWdbeSilDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeSilDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeSilDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeStringAttr(wr, itemtag, "sref", "TxfFsr", TxfFsr);
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintAttr(wr, itemtag, "sref", "numFPupRet", numFPupRet);
		writeUintAttr(wr, itemtag, "sref", "numFPupPkg", numFPupPkg);
		writeStringAttr(wr, itemtag, "sref", "TxfPkg", TxfPkg);
		writeBoolAttr(wr, itemtag, "sref", "ChkEsy", ChkEsy);
		writeUintAttr(wr, itemtag, "sref", "numFPupTch", numFPupTch);
		writeStringAttr(wr, itemtag, "sref", "TxfTch", TxfTch);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeSilDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTit == comp->TxfTit) insert(items, TXFTIT);
	if (TxfFsr == comp->TxfFsr) insert(items, TXFFSR);
	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (numFPupRet == comp->numFPupRet) insert(items, NUMFPUPRET);
	if (numFPupPkg == comp->numFPupPkg) insert(items, NUMFPUPPKG);
	if (TxfPkg == comp->TxfPkg) insert(items, TXFPKG);
	if (ChkEsy == comp->ChkEsy) insert(items, CHKESY);
	if (numFPupTch == comp->numFPupTch) insert(items, NUMFPUPTCH);
	if (TxfTch == comp->TxfTch) insert(items, TXFTCH);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWdbeSilDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTIT, TXFFSR, NUMFPUPTYP, NUMFPUPRET, NUMFPUPPKG, TXFPKG, CHKESY, NUMFPUPTCH, TXFTCH, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeSilDetail::ContInf
 ******************************************************************************/

PnlWdbeSilDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtReu
			, const string& TxtSys
			, const string& TxtMdl
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtReu = TxtReu;
	this->TxtSys = TxtSys;
	this->TxtMdl = TxtMdl;

	mask = {TXTSRF, TXTREU, TXTSYS, TXTMDL};
};

bool PnlWdbeSilDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeSilDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeSilDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtReu", TxtReu)) add(TXTREU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSys", TxtSys)) add(TXTSYS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMdl", TxtMdl)) add(TXTMDL);
	};

	return basefound;
};

set<uint> PnlWdbeSilDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtReu == comp->TxtReu) insert(items, TXTREU);
	if (TxtSys == comp->TxtSys) insert(items, TXTSYS);
	if (TxtMdl == comp->TxtMdl) insert(items, TXTMDL);

	return(items);
};

set<uint> PnlWdbeSilDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTREU, TXTSYS, TXTMDL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeSilDetail::StatApp
 ******************************************************************************/

PnlWdbeSilDetail::StatApp::StatApp(
			const uint ixWdbeVExpstate
			, const bool PupPkgAlt
			, const bool PupTchAlt
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->PupPkgAlt = PupPkgAlt;
	this->PupTchAlt = PupTchAlt;

	mask = {IXWDBEVEXPSTATE, PUPPKGALT, PUPTCHALT};
};

bool PnlWdbeSilDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeSilDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeSilDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupPkgAlt", PupPkgAlt)) add(PUPPKGALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTchAlt", PupTchAlt)) add(PUPTCHALT);
	};

	return basefound;
};

set<uint> PnlWdbeSilDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (PupPkgAlt == comp->PupPkgAlt) insert(items, PUPPKGALT);
	if (PupTchAlt == comp->PupTchAlt) insert(items, PUPTCHALT);

	return(items);
};

set<uint> PnlWdbeSilDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, PUPPKGALT, PUPTCHALT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeSilDetail::StatShr
 ******************************************************************************/

PnlWdbeSilDetail::StatShr::StatShr(
			const bool TxfPkgValid
			, const bool TxfTchValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxfTitActive
			, const bool TxfFsrActive
			, const bool PupTypActive
			, const bool TxtReuActive
			, const bool ButReuViewAvail
			, const bool ButReuViewActive
			, const bool TxtSysActive
			, const bool ButSysViewAvail
			, const bool ButSysViewActive
			, const bool TxtMdlActive
			, const bool ButMdlViewAvail
			, const bool ButMdlViewActive
			, const bool PupPkgActive
			, const bool ButPkgEditAvail
			, const bool ChkEsyActive
			, const bool PupTchActive
			, const bool ButTchEditAvail
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->TxfPkgValid = TxfPkgValid;
	this->TxfTchValid = TxfTchValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxfTitActive = TxfTitActive;
	this->TxfFsrActive = TxfFsrActive;
	this->PupTypActive = PupTypActive;
	this->TxtReuActive = TxtReuActive;
	this->ButReuViewAvail = ButReuViewAvail;
	this->ButReuViewActive = ButReuViewActive;
	this->TxtSysActive = TxtSysActive;
	this->ButSysViewAvail = ButSysViewAvail;
	this->ButSysViewActive = ButSysViewActive;
	this->TxtMdlActive = TxtMdlActive;
	this->ButMdlViewAvail = ButMdlViewAvail;
	this->ButMdlViewActive = ButMdlViewActive;
	this->PupPkgActive = PupPkgActive;
	this->ButPkgEditAvail = ButPkgEditAvail;
	this->ChkEsyActive = ChkEsyActive;
	this->PupTchActive = PupTchActive;
	this->ButTchEditAvail = ButTchEditAvail;
	this->TxfCmtActive = TxfCmtActive;

	mask = {TXFPKGVALID, TXFTCHVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFTITACTIVE, TXFFSRACTIVE, PUPTYPACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTSYSACTIVE, BUTSYSVIEWAVAIL, BUTSYSVIEWACTIVE, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, PUPPKGACTIVE, BUTPKGEDITAVAIL, CHKESYACTIVE, PUPTCHACTIVE, BUTTCHEDITAVAIL, TXFCMTACTIVE};
};

bool PnlWdbeSilDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeSilDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeSilDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfPkgValid", TxfPkgValid)) add(TXFPKGVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfTchValid", TxfTchValid)) add(TXFTCHVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfTitActive", TxfTitActive)) add(TXFTITACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFsrActive", TxfFsrActive)) add(TXFFSRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTypActive", PupTypActive)) add(PUPTYPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtReuActive", TxtReuActive)) add(TXTREUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButReuViewAvail", ButReuViewAvail)) add(BUTREUVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButReuViewActive", ButReuViewActive)) add(BUTREUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSysActive", TxtSysActive)) add(TXTSYSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSysViewAvail", ButSysViewAvail)) add(BUTSYSVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSysViewActive", ButSysViewActive)) add(BUTSYSVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtMdlActive", TxtMdlActive)) add(TXTMDLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButMdlViewAvail", ButMdlViewAvail)) add(BUTMDLVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButMdlViewActive", ButMdlViewActive)) add(BUTMDLVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupPkgActive", PupPkgActive)) add(PUPPKGACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPkgEditAvail", ButPkgEditAvail)) add(BUTPKGEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkEsyActive", ChkEsyActive)) add(CHKESYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTchActive", PupTchActive)) add(PUPTCHACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTchEditAvail", ButTchEditAvail)) add(BUTTCHEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbeSilDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfPkgValid == comp->TxfPkgValid) insert(items, TXFPKGVALID);
	if (TxfTchValid == comp->TxfTchValid) insert(items, TXFTCHVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxfTitActive == comp->TxfTitActive) insert(items, TXFTITACTIVE);
	if (TxfFsrActive == comp->TxfFsrActive) insert(items, TXFFSRACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (TxtReuActive == comp->TxtReuActive) insert(items, TXTREUACTIVE);
	if (ButReuViewAvail == comp->ButReuViewAvail) insert(items, BUTREUVIEWAVAIL);
	if (ButReuViewActive == comp->ButReuViewActive) insert(items, BUTREUVIEWACTIVE);
	if (TxtSysActive == comp->TxtSysActive) insert(items, TXTSYSACTIVE);
	if (ButSysViewAvail == comp->ButSysViewAvail) insert(items, BUTSYSVIEWAVAIL);
	if (ButSysViewActive == comp->ButSysViewActive) insert(items, BUTSYSVIEWACTIVE);
	if (TxtMdlActive == comp->TxtMdlActive) insert(items, TXTMDLACTIVE);
	if (ButMdlViewAvail == comp->ButMdlViewAvail) insert(items, BUTMDLVIEWAVAIL);
	if (ButMdlViewActive == comp->ButMdlViewActive) insert(items, BUTMDLVIEWACTIVE);
	if (PupPkgActive == comp->PupPkgActive) insert(items, PUPPKGACTIVE);
	if (ButPkgEditAvail == comp->ButPkgEditAvail) insert(items, BUTPKGEDITAVAIL);
	if (ChkEsyActive == comp->ChkEsyActive) insert(items, CHKESYACTIVE);
	if (PupTchActive == comp->PupTchActive) insert(items, PUPTCHACTIVE);
	if (ButTchEditAvail == comp->ButTchEditAvail) insert(items, BUTTCHEDITAVAIL);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWdbeSilDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFPKGVALID, TXFTCHVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFTITACTIVE, TXFFSRACTIVE, PUPTYPACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTSYSACTIVE, BUTSYSVIEWAVAIL, BUTSYSVIEWACTIVE, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, PUPPKGACTIVE, BUTPKGEDITAVAIL, CHKESYACTIVE, PUPTCHACTIVE, BUTTCHEDITAVAIL, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeSilDetail::Tag
 ******************************************************************************/

PnlWdbeSilDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptTit
			, const string& CptFsr
			, const string& CptTyp
			, const string& CptReu
			, const string& CptSys
			, const string& CptMdl
			, const string& CptPkg
			, const string& CptEsy
			, const string& CptTch
			, const string& CptCmt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptTit = CptTit;
	this->CptFsr = CptFsr;
	this->CptTyp = CptTyp;
	this->CptReu = CptReu;
	this->CptSys = CptSys;
	this->CptMdl = CptMdl;
	this->CptPkg = CptPkg;
	this->CptEsy = CptEsy;
	this->CptTch = CptTch;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTSRF, CPTTIT, CPTFSR, CPTTYP, CPTREU, CPTSYS, CPTMDL, CPTPKG, CPTESY, CPTTCH, CPTCMT};
};

bool PnlWdbeSilDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeSilDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeSilDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTit", CptTit)) add(CPTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFsr", CptFsr)) add(CPTFSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptReu", CptReu)) add(CPTREU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSys", CptSys)) add(CPTSYS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMdl", CptMdl)) add(CPTMDL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPkg", CptPkg)) add(CPTPKG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEsy", CptEsy)) add(CPTESY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTch", CptTch)) add(CPTTCH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeSilDetail::DpchAppData
 ******************************************************************************/

PnlWdbeSilDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBESILDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbeSilDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeSilDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeSilDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeSilDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeSilDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBESILDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbeSilDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeSilDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeSilDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeSilDetail::DpchEngData
 ******************************************************************************/

PnlWdbeSilDetail::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBESILDETAILDATA)
		{
	feedFPupPkg.tag = "FeedFPupPkg";
	feedFPupRet.tag = "FeedFPupRet";
	feedFPupTch.tag = "FeedFPupTch";
	feedFPupTyp.tag = "FeedFPupTyp";
};

string PnlWdbeSilDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPPKG)) ss.push_back("feedFPupPkg");
	if (has(FEEDFPUPRET)) ss.push_back("feedFPupRet");
	if (has(FEEDFPUPTCH)) ss.push_back("feedFPupTch");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeSilDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeSilDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupPkg.readXML(docctx, basexpath, true)) add(FEEDFPUPPKG);
		if (feedFPupRet.readXML(docctx, basexpath, true)) add(FEEDFPUPRET);
		if (feedFPupTch.readXML(docctx, basexpath, true)) add(FEEDFPUPTCH);
		if (feedFPupTyp.readXML(docctx, basexpath, true)) add(FEEDFPUPTYP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupPkg.clear();
		feedFPupRet.clear();
		feedFPupTch.clear();
		feedFPupTyp.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
