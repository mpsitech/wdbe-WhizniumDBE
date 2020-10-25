/**
	* \file PnlWdbeGenDetail.cpp
	* API code for job PnlWdbeGenDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "PnlWdbeGenDetail.h"

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

bool PnlWdbeGenDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeGenDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeGenDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtClu", TxtClu)) add(TXTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMdl", TxtMdl)) add(TXTMDL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrc", TxtSrc)) add(TXTSRC);
	};

	return basefound;
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

PnlWdbeGenDetail::StatApp::StatApp(
			const uint ixWdbeVExpstate
			, const bool LstCluAlt
			, const bool PupHtyAlt
			, const bool TxtSrcAlt
			, const uint LstCluNumFirstdisp
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->LstCluAlt = LstCluAlt;
	this->PupHtyAlt = PupHtyAlt;
	this->TxtSrcAlt = TxtSrcAlt;
	this->LstCluNumFirstdisp = LstCluNumFirstdisp;

	mask = {IXWDBEVEXPSTATE, LSTCLUALT, PUPHTYALT, TXTSRCALT, LSTCLUNUMFIRSTDISP};
};

bool PnlWdbeGenDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeGenDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeGenDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluAlt", LstCluAlt)) add(LSTCLUALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupHtyAlt", PupHtyAlt)) add(PUPHTYALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrcAlt", TxtSrcAlt)) add(TXTSRCALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluNumFirstdisp", LstCluNumFirstdisp)) add(LSTCLUNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWdbeGenDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (LstCluAlt == comp->LstCluAlt) insert(items, LSTCLUALT);
	if (PupHtyAlt == comp->PupHtyAlt) insert(items, PUPHTYALT);
	if (TxtSrcAlt == comp->TxtSrcAlt) insert(items, TXTSRCALT);
	if (LstCluNumFirstdisp == comp->LstCluNumFirstdisp) insert(items, LSTCLUNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWdbeGenDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, LSTCLUALT, PUPHTYALT, TXTSRCALT, LSTCLUNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
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

bool PnlWdbeGenDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeGenDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeGenDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfHtyValid", TxfHtyValid)) add(TXFHTYVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfSrcValid", TxfSrcValid)) add(TXFSRCVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluActive", LstCluActive)) add(LSTCLUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluViewActive", ButCluViewActive)) add(BUTCLUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluClusterAvail", ButCluClusterAvail)) add(BUTCLUCLUSTERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluUnclusterAvail", ButCluUnclusterAvail)) add(BUTCLUUNCLUSTERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtMdlActive", TxtMdlActive)) add(TXTMDLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButMdlViewAvail", ButMdlViewAvail)) add(BUTMDLVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButMdlViewActive", ButMdlViewActive)) add(BUTMDLVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupHtyActive", PupHtyActive)) add(PUPHTYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButHtyEditAvail", ButHtyEditAvail)) add(BUTHTYEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfWidActive", TxfWidActive)) add(TXFWIDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfMmxActive", TxfMmxActive)) add(TXFMMXACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfDfvActive", TxfDfvActive)) add(TXFDFVACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrcActive", TxtSrcActive)) add(TXTSRCACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSrcViewAvail", ButSrcViewAvail)) add(BUTSRCVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
	};

	return basefound;
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

PnlWdbeGenDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptClu
			, const string& CptMdl
			, const string& CptHty
			, const string& CptWid
			, const string& CptMmx
			, const string& CptDfv
			, const string& CptSrc
			, const string& CptCmt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptClu = CptClu;
	this->CptMdl = CptMdl;
	this->CptHty = CptHty;
	this->CptWid = CptWid;
	this->CptMmx = CptMmx;
	this->CptDfv = CptDfv;
	this->CptSrc = CptSrc;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTSRF, CPTCLU, CPTMDL, CPTHTY, CPTWID, CPTMMX, CPTDFV, CPTSRC, CPTCMT};
};

bool PnlWdbeGenDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeGenDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeGenDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptClu", CptClu)) add(CPTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMdl", CptMdl)) add(CPTMDL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptHty", CptHty)) add(CPTHTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptWid", CptWid)) add(CPTWID);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMmx", CptMmx)) add(CPTMMX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDfv", CptDfv)) add(CPTDFV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrc", CptSrc)) add(CPTSRC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeGenDetail::DpchAppData
 ******************************************************************************/

PnlWdbeGenDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEGENDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbeGenDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeGenDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeGenDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeGenDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeGenDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEGENDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbeGenDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeGenDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeGenDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeGenDetail::DpchEngData
 ******************************************************************************/

PnlWdbeGenDetail::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEGENDETAILDATA)
		{
	feedFLstClu.tag = "FeedFLstClu";
	feedFPupHty.tag = "FeedFPupHty";
};

string PnlWdbeGenDetail::DpchEngData::getSrefsMask() {
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

void PnlWdbeGenDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeGenDetailData");
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

