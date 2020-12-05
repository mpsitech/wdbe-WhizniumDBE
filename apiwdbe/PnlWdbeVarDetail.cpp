/**
	* \file PnlWdbeVarDetail.cpp
	* API code for job PnlWdbeVarDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWdbeVarDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeVarDetail::VecVDo
 ******************************************************************************/

uint PnlWdbeVarDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butcluviewclick") return BUTCLUVIEWCLICK;
	if (s == "butcluclusterclick") return BUTCLUCLUSTERCLICK;
	if (s == "butcluunclusterclick") return BUTCLUUNCLUSTERCLICK;
	if (s == "buthtyeditclick") return BUTHTYEDITCLICK;

	return(0);
};

string PnlWdbeVarDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTCLUVIEWCLICK) return("ButCluViewClick");
	if (ix == BUTCLUCLUSTERCLICK) return("ButCluClusterClick");
	if (ix == BUTCLUUNCLUSTERCLICK) return("ButCluUnclusterClick");
	if (ix == BUTHTYEDITCLICK) return("ButHtyEditClick");

	return("");
};

/******************************************************************************
 class PnlWdbeVarDetail::ContIac
 ******************************************************************************/

PnlWdbeVarDetail::ContIac::ContIac(
			const uint numFLstClu
			, const bool ChkCon
			, const bool ChkFal
			, const uint numFPupHty
			, const string& TxfHty
			, const string& TxfWid
			, const string& TxfMmx
			, const string& TxfOnv
			, const string& TxfOfv
			, const bool ChkDfo
			, const string& TxfCmt
		) :
			Block()
		{
	this->numFLstClu = numFLstClu;
	this->ChkCon = ChkCon;
	this->ChkFal = ChkFal;
	this->numFPupHty = numFPupHty;
	this->TxfHty = TxfHty;
	this->TxfWid = TxfWid;
	this->TxfMmx = TxfMmx;
	this->TxfOnv = TxfOnv;
	this->TxfOfv = TxfOfv;
	this->ChkDfo = ChkDfo;
	this->TxfCmt = TxfCmt;

	mask = {NUMFLSTCLU, CHKCON, CHKFAL, NUMFPUPHTY, TXFHTY, TXFWID, TXFMMX, TXFONV, TXFOFV, CHKDFO, TXFCMT};
};

bool PnlWdbeVarDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeVarDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeVarDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstClu", numFLstClu)) add(NUMFLSTCLU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkCon", ChkCon)) add(CHKCON);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkFal", ChkFal)) add(CHKFAL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupHty", numFPupHty)) add(NUMFPUPHTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfHty", TxfHty)) add(TXFHTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfWid", TxfWid)) add(TXFWID);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfMmx", TxfMmx)) add(TXFMMX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfOnv", TxfOnv)) add(TXFONV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfOfv", TxfOfv)) add(TXFOFV);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkDfo", ChkDfo)) add(CHKDFO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWdbeVarDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeVarDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeVarDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstClu", numFLstClu);
		writeBoolAttr(wr, itemtag, "sref", "ChkCon", ChkCon);
		writeBoolAttr(wr, itemtag, "sref", "ChkFal", ChkFal);
		writeUintAttr(wr, itemtag, "sref", "numFPupHty", numFPupHty);
		writeStringAttr(wr, itemtag, "sref", "TxfHty", TxfHty);
		writeStringAttr(wr, itemtag, "sref", "TxfWid", TxfWid);
		writeStringAttr(wr, itemtag, "sref", "TxfMmx", TxfMmx);
		writeStringAttr(wr, itemtag, "sref", "TxfOnv", TxfOnv);
		writeStringAttr(wr, itemtag, "sref", "TxfOfv", TxfOfv);
		writeBoolAttr(wr, itemtag, "sref", "ChkDfo", ChkDfo);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeVarDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstClu == comp->numFLstClu) insert(items, NUMFLSTCLU);
	if (ChkCon == comp->ChkCon) insert(items, CHKCON);
	if (ChkFal == comp->ChkFal) insert(items, CHKFAL);
	if (numFPupHty == comp->numFPupHty) insert(items, NUMFPUPHTY);
	if (TxfHty == comp->TxfHty) insert(items, TXFHTY);
	if (TxfWid == comp->TxfWid) insert(items, TXFWID);
	if (TxfMmx == comp->TxfMmx) insert(items, TXFMMX);
	if (TxfOnv == comp->TxfOnv) insert(items, TXFONV);
	if (TxfOfv == comp->TxfOfv) insert(items, TXFOFV);
	if (ChkDfo == comp->ChkDfo) insert(items, CHKDFO);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWdbeVarDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTCLU, CHKCON, CHKFAL, NUMFPUPHTY, TXFHTY, TXFWID, TXFMMX, TXFONV, TXFOFV, CHKDFO, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeVarDetail::ContInf
 ******************************************************************************/

PnlWdbeVarDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtClu
			, const string& TxtPrc
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtClu = TxtClu;
	this->TxtPrc = TxtPrc;

	mask = {TXTSRF, TXTCLU, TXTPRC};
};

bool PnlWdbeVarDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeVarDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeVarDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtClu", TxtClu)) add(TXTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrc", TxtPrc)) add(TXTPRC);
	};

	return basefound;
};

set<uint> PnlWdbeVarDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtClu == comp->TxtClu) insert(items, TXTCLU);
	if (TxtPrc == comp->TxtPrc) insert(items, TXTPRC);

	return(items);
};

set<uint> PnlWdbeVarDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTCLU, TXTPRC};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeVarDetail::StatApp
 ******************************************************************************/

PnlWdbeVarDetail::StatApp::StatApp(
			const uint ixWdbeVExpstate
			, const bool LstCluAlt
			, const bool PupHtyAlt
			, const uint LstCluNumFirstdisp
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->LstCluAlt = LstCluAlt;
	this->PupHtyAlt = PupHtyAlt;
	this->LstCluNumFirstdisp = LstCluNumFirstdisp;

	mask = {IXWDBEVEXPSTATE, LSTCLUALT, PUPHTYALT, LSTCLUNUMFIRSTDISP};
};

bool PnlWdbeVarDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeVarDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeVarDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluAlt", LstCluAlt)) add(LSTCLUALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupHtyAlt", PupHtyAlt)) add(PUPHTYALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluNumFirstdisp", LstCluNumFirstdisp)) add(LSTCLUNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWdbeVarDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (LstCluAlt == comp->LstCluAlt) insert(items, LSTCLUALT);
	if (PupHtyAlt == comp->PupHtyAlt) insert(items, PUPHTYALT);
	if (LstCluNumFirstdisp == comp->LstCluNumFirstdisp) insert(items, LSTCLUNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWdbeVarDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, LSTCLUALT, PUPHTYALT, LSTCLUNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeVarDetail::StatShr
 ******************************************************************************/

PnlWdbeVarDetail::StatShr::StatShr(
			const bool TxfHtyValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool LstCluActive
			, const bool ButCluViewActive
			, const bool ButCluClusterAvail
			, const bool ButCluUnclusterAvail
			, const bool TxtPrcActive
			, const bool ChkConActive
			, const bool ChkFalActive
			, const bool PupHtyActive
			, const bool ButHtyEditAvail
			, const bool TxfWidActive
			, const bool TxfMmxActive
			, const bool TxfOnvActive
			, const bool TxfOfvActive
			, const bool ChkDfoActive
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->TxfHtyValid = TxfHtyValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->LstCluActive = LstCluActive;
	this->ButCluViewActive = ButCluViewActive;
	this->ButCluClusterAvail = ButCluClusterAvail;
	this->ButCluUnclusterAvail = ButCluUnclusterAvail;
	this->TxtPrcActive = TxtPrcActive;
	this->ChkConActive = ChkConActive;
	this->ChkFalActive = ChkFalActive;
	this->PupHtyActive = PupHtyActive;
	this->ButHtyEditAvail = ButHtyEditAvail;
	this->TxfWidActive = TxfWidActive;
	this->TxfMmxActive = TxfMmxActive;
	this->TxfOnvActive = TxfOnvActive;
	this->TxfOfvActive = TxfOfvActive;
	this->ChkDfoActive = ChkDfoActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {TXFHTYVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTPRCACTIVE, CHKCONACTIVE, CHKFALACTIVE, PUPHTYACTIVE, BUTHTYEDITAVAIL, TXFWIDACTIVE, TXFMMXACTIVE, TXFONVACTIVE, TXFOFVACTIVE, CHKDFOACTIVE, TXFCMTACTIVE};
};

bool PnlWdbeVarDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeVarDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeVarDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfHtyValid", TxfHtyValid)) add(TXFHTYVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluActive", LstCluActive)) add(LSTCLUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluViewActive", ButCluViewActive)) add(BUTCLUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluClusterAvail", ButCluClusterAvail)) add(BUTCLUCLUSTERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluUnclusterAvail", ButCluUnclusterAvail)) add(BUTCLUUNCLUSTERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPrcActive", TxtPrcActive)) add(TXTPRCACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkConActive", ChkConActive)) add(CHKCONACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkFalActive", ChkFalActive)) add(CHKFALACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupHtyActive", PupHtyActive)) add(PUPHTYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButHtyEditAvail", ButHtyEditAvail)) add(BUTHTYEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfWidActive", TxfWidActive)) add(TXFWIDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfMmxActive", TxfMmxActive)) add(TXFMMXACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfOnvActive", TxfOnvActive)) add(TXFONVACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfOfvActive", TxfOfvActive)) add(TXFOFVACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkDfoActive", ChkDfoActive)) add(CHKDFOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbeVarDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfHtyValid == comp->TxfHtyValid) insert(items, TXFHTYVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (LstCluActive == comp->LstCluActive) insert(items, LSTCLUACTIVE);
	if (ButCluViewActive == comp->ButCluViewActive) insert(items, BUTCLUVIEWACTIVE);
	if (ButCluClusterAvail == comp->ButCluClusterAvail) insert(items, BUTCLUCLUSTERAVAIL);
	if (ButCluUnclusterAvail == comp->ButCluUnclusterAvail) insert(items, BUTCLUUNCLUSTERAVAIL);
	if (TxtPrcActive == comp->TxtPrcActive) insert(items, TXTPRCACTIVE);
	if (ChkConActive == comp->ChkConActive) insert(items, CHKCONACTIVE);
	if (ChkFalActive == comp->ChkFalActive) insert(items, CHKFALACTIVE);
	if (PupHtyActive == comp->PupHtyActive) insert(items, PUPHTYACTIVE);
	if (ButHtyEditAvail == comp->ButHtyEditAvail) insert(items, BUTHTYEDITAVAIL);
	if (TxfWidActive == comp->TxfWidActive) insert(items, TXFWIDACTIVE);
	if (TxfMmxActive == comp->TxfMmxActive) insert(items, TXFMMXACTIVE);
	if (TxfOnvActive == comp->TxfOnvActive) insert(items, TXFONVACTIVE);
	if (TxfOfvActive == comp->TxfOfvActive) insert(items, TXFOFVACTIVE);
	if (ChkDfoActive == comp->ChkDfoActive) insert(items, CHKDFOACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWdbeVarDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFHTYVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTPRCACTIVE, CHKCONACTIVE, CHKFALACTIVE, PUPHTYACTIVE, BUTHTYEDITAVAIL, TXFWIDACTIVE, TXFMMXACTIVE, TXFONVACTIVE, TXFOFVACTIVE, CHKDFOACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeVarDetail::Tag
 ******************************************************************************/

PnlWdbeVarDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptClu
			, const string& CptPrc
			, const string& CptCon
			, const string& CptFal
			, const string& CptHty
			, const string& CptWid
			, const string& CptMmx
			, const string& CptOnv
			, const string& CptOfv
			, const string& CptDfo
			, const string& CptCmt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptClu = CptClu;
	this->CptPrc = CptPrc;
	this->CptCon = CptCon;
	this->CptFal = CptFal;
	this->CptHty = CptHty;
	this->CptWid = CptWid;
	this->CptMmx = CptMmx;
	this->CptOnv = CptOnv;
	this->CptOfv = CptOfv;
	this->CptDfo = CptDfo;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTSRF, CPTCLU, CPTPRC, CPTCON, CPTFAL, CPTHTY, CPTWID, CPTMMX, CPTONV, CPTOFV, CPTDFO, CPTCMT};
};

bool PnlWdbeVarDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeVarDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeVarDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptClu", CptClu)) add(CPTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrc", CptPrc)) add(CPTPRC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCon", CptCon)) add(CPTCON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFal", CptFal)) add(CPTFAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptHty", CptHty)) add(CPTHTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptWid", CptWid)) add(CPTWID);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMmx", CptMmx)) add(CPTMMX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOnv", CptOnv)) add(CPTONV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOfv", CptOfv)) add(CPTOFV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDfo", CptDfo)) add(CPTDFO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeVarDetail::DpchAppData
 ******************************************************************************/

PnlWdbeVarDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEVARDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbeVarDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeVarDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeVarDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeVarDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeVarDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEVARDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbeVarDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeVarDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeVarDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeVarDetail::DpchEngData
 ******************************************************************************/

PnlWdbeVarDetail::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEVARDETAILDATA)
		{
	feedFLstClu.tag = "FeedFLstClu";
	feedFPupHty.tag = "FeedFPupHty";
};

string PnlWdbeVarDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
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

void PnlWdbeVarDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeVarDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstClu.readXML(docctx, basexpath, true)) add(FEEDFLSTCLU);
		if (feedFPupHty.readXML(docctx, basexpath, true)) add(FEEDFPUPHTY);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstClu.clear();
		feedFPupHty.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

