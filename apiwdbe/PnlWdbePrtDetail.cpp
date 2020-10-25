/**
	* \file PnlWdbePrtDetail.cpp
	* API code for job PnlWdbePrtDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "PnlWdbePrtDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbePrtDetail::VecVDo
 ******************************************************************************/

uint PnlWdbePrtDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butcluviewclick") return BUTCLUVIEWCLICK;
	if (s == "butcluclusterclick") return BUTCLUCLUSTERCLICK;
	if (s == "butcluunclusterclick") return BUTCLUUNCLUSTERCLICK;
	if (s == "butmdlviewclick") return BUTMDLVIEWCLICK;
	if (s == "buthtyeditclick") return BUTHTYEDITCLICK;
	if (s == "butcpiviewclick") return BUTCPIVIEWCLICK;
	if (s == "butcprviewclick") return BUTCPRVIEWCLICK;
	if (s == "butcsiviewclick") return BUTCSIVIEWCLICK;

	return(0);
};

string PnlWdbePrtDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTCLUVIEWCLICK) return("ButCluViewClick");
	if (ix == BUTCLUCLUSTERCLICK) return("ButCluClusterClick");
	if (ix == BUTCLUUNCLUSTERCLICK) return("ButCluUnclusterClick");
	if (ix == BUTMDLVIEWCLICK) return("ButMdlViewClick");
	if (ix == BUTHTYEDITCLICK) return("ButHtyEditClick");
	if (ix == BUTCPIVIEWCLICK) return("ButCpiViewClick");
	if (ix == BUTCPRVIEWCLICK) return("ButCprViewClick");
	if (ix == BUTCSIVIEWCLICK) return("ButCsiViewClick");

	return("");
};

/******************************************************************************
 class PnlWdbePrtDetail::ContIac
 ******************************************************************************/

PnlWdbePrtDetail::ContIac::ContIac(
			const uint numFLstClu
			, const uint numFPupDir
			, const uint numFPupHty
			, const string& TxfHty
			, const string& TxfWid
			, const string& TxfMmx
			, const string& TxfDfv
			, const string& TxfCpi
			, const string& TxfCpr
			, const string& TxfCsi
			, const string& TxfCmt
		) :
			Block()
		{
	this->numFLstClu = numFLstClu;
	this->numFPupDir = numFPupDir;
	this->numFPupHty = numFPupHty;
	this->TxfHty = TxfHty;
	this->TxfWid = TxfWid;
	this->TxfMmx = TxfMmx;
	this->TxfDfv = TxfDfv;
	this->TxfCpi = TxfCpi;
	this->TxfCpr = TxfCpr;
	this->TxfCsi = TxfCsi;
	this->TxfCmt = TxfCmt;

	mask = {NUMFLSTCLU, NUMFPUPDIR, NUMFPUPHTY, TXFHTY, TXFWID, TXFMMX, TXFDFV, TXFCPI, TXFCPR, TXFCSI, TXFCMT};
};

bool PnlWdbePrtDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbePrtDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbePrtDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstClu", numFLstClu)) add(NUMFLSTCLU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupDir", numFPupDir)) add(NUMFPUPDIR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupHty", numFPupHty)) add(NUMFPUPHTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfHty", TxfHty)) add(TXFHTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfWid", TxfWid)) add(TXFWID);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfMmx", TxfMmx)) add(TXFMMX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDfv", TxfDfv)) add(TXFDFV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCpi", TxfCpi)) add(TXFCPI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCpr", TxfCpr)) add(TXFCPR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCsi", TxfCsi)) add(TXFCSI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWdbePrtDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbePrtDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbePrtDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstClu", numFLstClu);
		writeUintAttr(wr, itemtag, "sref", "numFPupDir", numFPupDir);
		writeUintAttr(wr, itemtag, "sref", "numFPupHty", numFPupHty);
		writeStringAttr(wr, itemtag, "sref", "TxfHty", TxfHty);
		writeStringAttr(wr, itemtag, "sref", "TxfWid", TxfWid);
		writeStringAttr(wr, itemtag, "sref", "TxfMmx", TxfMmx);
		writeStringAttr(wr, itemtag, "sref", "TxfDfv", TxfDfv);
		writeStringAttr(wr, itemtag, "sref", "TxfCpi", TxfCpi);
		writeStringAttr(wr, itemtag, "sref", "TxfCpr", TxfCpr);
		writeStringAttr(wr, itemtag, "sref", "TxfCsi", TxfCsi);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbePrtDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstClu == comp->numFLstClu) insert(items, NUMFLSTCLU);
	if (numFPupDir == comp->numFPupDir) insert(items, NUMFPUPDIR);
	if (numFPupHty == comp->numFPupHty) insert(items, NUMFPUPHTY);
	if (TxfHty == comp->TxfHty) insert(items, TXFHTY);
	if (TxfWid == comp->TxfWid) insert(items, TXFWID);
	if (TxfMmx == comp->TxfMmx) insert(items, TXFMMX);
	if (TxfDfv == comp->TxfDfv) insert(items, TXFDFV);
	if (TxfCpi == comp->TxfCpi) insert(items, TXFCPI);
	if (TxfCpr == comp->TxfCpr) insert(items, TXFCPR);
	if (TxfCsi == comp->TxfCsi) insert(items, TXFCSI);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWdbePrtDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTCLU, NUMFPUPDIR, NUMFPUPHTY, TXFHTY, TXFWID, TXFMMX, TXFDFV, TXFCPI, TXFCPR, TXFCSI, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrtDetail::ContInf
 ******************************************************************************/

PnlWdbePrtDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtClu
			, const string& TxtMdl
			, const string& TxtCpi
			, const string& TxtCpr
			, const string& TxtCsi
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtClu = TxtClu;
	this->TxtMdl = TxtMdl;
	this->TxtCpi = TxtCpi;
	this->TxtCpr = TxtCpr;
	this->TxtCsi = TxtCsi;

	mask = {TXTSRF, TXTCLU, TXTMDL, TXTCPI, TXTCPR, TXTCSI};
};

bool PnlWdbePrtDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbePrtDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbePrtDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtClu", TxtClu)) add(TXTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMdl", TxtMdl)) add(TXTMDL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCpi", TxtCpi)) add(TXTCPI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCpr", TxtCpr)) add(TXTCPR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCsi", TxtCsi)) add(TXTCSI);
	};

	return basefound;
};

set<uint> PnlWdbePrtDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtClu == comp->TxtClu) insert(items, TXTCLU);
	if (TxtMdl == comp->TxtMdl) insert(items, TXTMDL);
	if (TxtCpi == comp->TxtCpi) insert(items, TXTCPI);
	if (TxtCpr == comp->TxtCpr) insert(items, TXTCPR);
	if (TxtCsi == comp->TxtCsi) insert(items, TXTCSI);

	return(items);
};

set<uint> PnlWdbePrtDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTCLU, TXTMDL, TXTCPI, TXTCPR, TXTCSI};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrtDetail::StatApp
 ******************************************************************************/

PnlWdbePrtDetail::StatApp::StatApp(
			const uint ixWdbeVExpstate
			, const bool LstCluAlt
			, const bool PupHtyAlt
			, const bool TxtCpiAlt
			, const bool TxtCprAlt
			, const bool TxtCsiAlt
			, const uint LstCluNumFirstdisp
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->LstCluAlt = LstCluAlt;
	this->PupHtyAlt = PupHtyAlt;
	this->TxtCpiAlt = TxtCpiAlt;
	this->TxtCprAlt = TxtCprAlt;
	this->TxtCsiAlt = TxtCsiAlt;
	this->LstCluNumFirstdisp = LstCluNumFirstdisp;

	mask = {IXWDBEVEXPSTATE, LSTCLUALT, PUPHTYALT, TXTCPIALT, TXTCPRALT, TXTCSIALT, LSTCLUNUMFIRSTDISP};
};

bool PnlWdbePrtDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbePrtDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbePrtDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluAlt", LstCluAlt)) add(LSTCLUALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupHtyAlt", PupHtyAlt)) add(PUPHTYALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCpiAlt", TxtCpiAlt)) add(TXTCPIALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCprAlt", TxtCprAlt)) add(TXTCPRALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCsiAlt", TxtCsiAlt)) add(TXTCSIALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluNumFirstdisp", LstCluNumFirstdisp)) add(LSTCLUNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWdbePrtDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (LstCluAlt == comp->LstCluAlt) insert(items, LSTCLUALT);
	if (PupHtyAlt == comp->PupHtyAlt) insert(items, PUPHTYALT);
	if (TxtCpiAlt == comp->TxtCpiAlt) insert(items, TXTCPIALT);
	if (TxtCprAlt == comp->TxtCprAlt) insert(items, TXTCPRALT);
	if (TxtCsiAlt == comp->TxtCsiAlt) insert(items, TXTCSIALT);
	if (LstCluNumFirstdisp == comp->LstCluNumFirstdisp) insert(items, LSTCLUNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWdbePrtDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, LSTCLUALT, PUPHTYALT, TXTCPIALT, TXTCPRALT, TXTCSIALT, LSTCLUNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrtDetail::StatShr
 ******************************************************************************/

PnlWdbePrtDetail::StatShr::StatShr(
			const bool TxfHtyValid
			, const bool TxfCpiValid
			, const bool TxfCprValid
			, const bool TxfCsiValid
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
			, const bool PupDirActive
			, const bool PupHtyActive
			, const bool ButHtyEditAvail
			, const bool TxfWidActive
			, const bool TxfMmxActive
			, const bool TxfDfvActive
			, const bool TxtCpiActive
			, const bool ButCpiViewAvail
			, const bool TxtCprActive
			, const bool ButCprViewAvail
			, const bool TxtCsiActive
			, const bool ButCsiViewAvail
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->TxfHtyValid = TxfHtyValid;
	this->TxfCpiValid = TxfCpiValid;
	this->TxfCprValid = TxfCprValid;
	this->TxfCsiValid = TxfCsiValid;
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
	this->PupDirActive = PupDirActive;
	this->PupHtyActive = PupHtyActive;
	this->ButHtyEditAvail = ButHtyEditAvail;
	this->TxfWidActive = TxfWidActive;
	this->TxfMmxActive = TxfMmxActive;
	this->TxfDfvActive = TxfDfvActive;
	this->TxtCpiActive = TxtCpiActive;
	this->ButCpiViewAvail = ButCpiViewAvail;
	this->TxtCprActive = TxtCprActive;
	this->ButCprViewAvail = ButCprViewAvail;
	this->TxtCsiActive = TxtCsiActive;
	this->ButCsiViewAvail = ButCsiViewAvail;
	this->TxfCmtActive = TxfCmtActive;

	mask = {TXFHTYVALID, TXFCPIVALID, TXFCPRVALID, TXFCSIVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, PUPDIRACTIVE, PUPHTYACTIVE, BUTHTYEDITAVAIL, TXFWIDACTIVE, TXFMMXACTIVE, TXFDFVACTIVE, TXTCPIACTIVE, BUTCPIVIEWAVAIL, TXTCPRACTIVE, BUTCPRVIEWAVAIL, TXTCSIACTIVE, BUTCSIVIEWAVAIL, TXFCMTACTIVE};
};

bool PnlWdbePrtDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbePrtDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbePrtDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfHtyValid", TxfHtyValid)) add(TXFHTYVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCpiValid", TxfCpiValid)) add(TXFCPIVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCprValid", TxfCprValid)) add(TXFCPRVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCsiValid", TxfCsiValid)) add(TXFCSIVALID);
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
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupDirActive", PupDirActive)) add(PUPDIRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupHtyActive", PupHtyActive)) add(PUPHTYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButHtyEditAvail", ButHtyEditAvail)) add(BUTHTYEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfWidActive", TxfWidActive)) add(TXFWIDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfMmxActive", TxfMmxActive)) add(TXFMMXACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfDfvActive", TxfDfvActive)) add(TXFDFVACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCpiActive", TxtCpiActive)) add(TXTCPIACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCpiViewAvail", ButCpiViewAvail)) add(BUTCPIVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCprActive", TxtCprActive)) add(TXTCPRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCprViewAvail", ButCprViewAvail)) add(BUTCPRVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCsiActive", TxtCsiActive)) add(TXTCSIACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCsiViewAvail", ButCsiViewAvail)) add(BUTCSIVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbePrtDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfHtyValid == comp->TxfHtyValid) insert(items, TXFHTYVALID);
	if (TxfCpiValid == comp->TxfCpiValid) insert(items, TXFCPIVALID);
	if (TxfCprValid == comp->TxfCprValid) insert(items, TXFCPRVALID);
	if (TxfCsiValid == comp->TxfCsiValid) insert(items, TXFCSIVALID);
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
	if (PupDirActive == comp->PupDirActive) insert(items, PUPDIRACTIVE);
	if (PupHtyActive == comp->PupHtyActive) insert(items, PUPHTYACTIVE);
	if (ButHtyEditAvail == comp->ButHtyEditAvail) insert(items, BUTHTYEDITAVAIL);
	if (TxfWidActive == comp->TxfWidActive) insert(items, TXFWIDACTIVE);
	if (TxfMmxActive == comp->TxfMmxActive) insert(items, TXFMMXACTIVE);
	if (TxfDfvActive == comp->TxfDfvActive) insert(items, TXFDFVACTIVE);
	if (TxtCpiActive == comp->TxtCpiActive) insert(items, TXTCPIACTIVE);
	if (ButCpiViewAvail == comp->ButCpiViewAvail) insert(items, BUTCPIVIEWAVAIL);
	if (TxtCprActive == comp->TxtCprActive) insert(items, TXTCPRACTIVE);
	if (ButCprViewAvail == comp->ButCprViewAvail) insert(items, BUTCPRVIEWAVAIL);
	if (TxtCsiActive == comp->TxtCsiActive) insert(items, TXTCSIACTIVE);
	if (ButCsiViewAvail == comp->ButCsiViewAvail) insert(items, BUTCSIVIEWAVAIL);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWdbePrtDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFHTYVALID, TXFCPIVALID, TXFCPRVALID, TXFCSIVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, PUPDIRACTIVE, PUPHTYACTIVE, BUTHTYEDITAVAIL, TXFWIDACTIVE, TXFMMXACTIVE, TXFDFVACTIVE, TXTCPIACTIVE, BUTCPIVIEWAVAIL, TXTCPRACTIVE, BUTCPRVIEWAVAIL, TXTCSIACTIVE, BUTCSIVIEWAVAIL, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrtDetail::Tag
 ******************************************************************************/

PnlWdbePrtDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptClu
			, const string& CptMdl
			, const string& CptDir
			, const string& CptHty
			, const string& CptWid
			, const string& CptMmx
			, const string& CptDfv
			, const string& CptCpi
			, const string& CptCpr
			, const string& CptCsi
			, const string& CptCmt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptClu = CptClu;
	this->CptMdl = CptMdl;
	this->CptDir = CptDir;
	this->CptHty = CptHty;
	this->CptWid = CptWid;
	this->CptMmx = CptMmx;
	this->CptDfv = CptDfv;
	this->CptCpi = CptCpi;
	this->CptCpr = CptCpr;
	this->CptCsi = CptCsi;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTSRF, CPTCLU, CPTMDL, CPTDIR, CPTHTY, CPTWID, CPTMMX, CPTDFV, CPTCPI, CPTCPR, CPTCSI, CPTCMT};
};

bool PnlWdbePrtDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbePrtDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbePrtDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptClu", CptClu)) add(CPTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMdl", CptMdl)) add(CPTMDL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDir", CptDir)) add(CPTDIR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptHty", CptHty)) add(CPTHTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptWid", CptWid)) add(CPTWID);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMmx", CptMmx)) add(CPTMMX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDfv", CptDfv)) add(CPTDFV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCpi", CptCpi)) add(CPTCPI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCpr", CptCpr)) add(CPTCPR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCsi", CptCsi)) add(CPTCSI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbePrtDetail::DpchAppData
 ******************************************************************************/

PnlWdbePrtDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPRTDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbePrtDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrtDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbePrtDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePrtDetail::DpchAppDo
 ******************************************************************************/

PnlWdbePrtDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPRTDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbePrtDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrtDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbePrtDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePrtDetail::DpchEngData
 ******************************************************************************/

PnlWdbePrtDetail::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEPRTDETAILDATA)
		{
	feedFLstClu.tag = "FeedFLstClu";
	feedFPupDir.tag = "FeedFPupDir";
	feedFPupHty.tag = "FeedFPupHty";
};

string PnlWdbePrtDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTCLU)) ss.push_back("feedFLstClu");
	if (has(FEEDFPUPDIR)) ss.push_back("feedFPupDir");
	if (has(FEEDFPUPHTY)) ss.push_back("feedFPupHty");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrtDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbePrtDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstClu.readXML(docctx, basexpath, true)) add(FEEDFLSTCLU);
		if (feedFPupDir.readXML(docctx, basexpath, true)) add(FEEDFPUPDIR);
		if (feedFPupHty.readXML(docctx, basexpath, true)) add(FEEDFPUPHTY);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstClu.clear();
		feedFPupDir.clear();
		feedFPupHty.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

