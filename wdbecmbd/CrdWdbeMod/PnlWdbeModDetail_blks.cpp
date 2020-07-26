/**
	* \file PnlWdbeModDetail_blks.cpp
	* job handler for job PnlWdbeModDetail (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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
	if (s == "buthkuviewclick") return BUTHKUVIEWCLICK;
	if (s == "butsupviewclick") return BUTSUPVIEWCLICK;
	if (s == "buttplviewclick") return BUTTPLVIEWCLICK;
	if (s == "butimbnewclick") return BUTIMBNEWCLICK;
	if (s == "butimbdeleteclick") return BUTIMBDELETECLICK;
	if (s == "butimbcorviewclick") return BUTIMBCORVIEWCLICK;
	if (s == "butctrnewclick") return BUTCTRNEWCLICK;
	if (s == "butctrdeleteclick") return BUTCTRDELETECLICK;
	if (s == "butctrfwdviewclick") return BUTCTRFWDVIEWCLICK;
	if (s == "butctrclrviewclick") return BUTCTRCLRVIEWCLICK;

	return(0);
};

string PnlWdbeModDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTHKUVIEWCLICK) return("ButHkuViewClick");
	if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");
	if (ix == BUTTPLVIEWCLICK) return("ButTplViewClick");
	if (ix == BUTIMBNEWCLICK) return("ButImbNewClick");
	if (ix == BUTIMBDELETECLICK) return("ButImbDeleteClick");
	if (ix == BUTIMBCORVIEWCLICK) return("ButImbCorViewClick");
	if (ix == BUTCTRNEWCLICK) return("ButCtrNewClick");
	if (ix == BUTCTRDELETECLICK) return("ButCtrDeleteClick");
	if (ix == BUTCTRFWDVIEWCLICK) return("ButCtrFwdViewClick");
	if (ix == BUTCTRCLRVIEWCLICK) return("ButCtrClrViewClick");

	return("");
};

/******************************************************************************
 class PnlWdbeModDetail::ContIac
 ******************************************************************************/

PnlWdbeModDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const uint numFPupHkt
			, const string& TxfSrr
			, const string& TxfCmt
			, const uint numFPupImbDir
			, const string& TxfImbPri
			, const string& TxfCtrFsr
		) :
			Block()
		{
	this->numFPupTyp = numFPupTyp;
	this->numFPupHkt = numFPupHkt;
	this->TxfSrr = TxfSrr;
	this->TxfCmt = TxfCmt;
	this->numFPupImbDir = numFPupImbDir;
	this->TxfImbPri = TxfImbPri;
	this->TxfCtrFsr = TxfCtrFsr;

	mask = {NUMFPUPTYP, NUMFPUPHKT, TXFSRR, TXFCMT, NUMFPUPIMBDIR, TXFIMBPRI, TXFCTRFSR};
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
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupHkt", numFPupHkt)) add(NUMFPUPHKT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSrr", TxfSrr)) add(TXFSRR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupImbDir", numFPupImbDir)) add(NUMFPUPIMBDIR);
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
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintAttr(wr, itemtag, "sref", "numFPupHkt", numFPupHkt);
		writeStringAttr(wr, itemtag, "sref", "TxfSrr", TxfSrr);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
		writeUintAttr(wr, itemtag, "sref", "numFPupImbDir", numFPupImbDir);
		writeStringAttr(wr, itemtag, "sref", "TxfImbPri", TxfImbPri);
		writeStringAttr(wr, itemtag, "sref", "TxfCtrFsr", TxfCtrFsr);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeModDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (numFPupHkt == comp->numFPupHkt) insert(items, NUMFPUPHKT);
	if (TxfSrr == comp->TxfSrr) insert(items, TXFSRR);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);
	if (numFPupImbDir == comp->numFPupImbDir) insert(items, NUMFPUPIMBDIR);
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

	diffitems = {NUMFPUPTYP, NUMFPUPHKT, TXFSRR, TXFCMT, NUMFPUPIMBDIR, TXFIMBPRI, TXFCTRFSR};
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
			, const string& TxtImbSrf
			, const string& TxtImbCor
			, const string& TxtCtrFwd
			, const string& TxtCtrClr
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtHku = TxtHku;
	this->TxtSup = TxtSup;
	this->TxtTpl = TxtTpl;
	this->TxtImbSrf = TxtImbSrf;
	this->TxtImbCor = TxtImbCor;
	this->TxtCtrFwd = TxtCtrFwd;
	this->TxtCtrClr = TxtCtrClr;

	mask = {TXTSRF, TXTHKU, TXTSUP, TXTTPL, TXTIMBSRF, TXTIMBCOR, TXTCTRFWD, TXTCTRCLR};
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
		writeStringAttr(wr, itemtag, "sref", "TxtImbSrf", TxtImbSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtImbCor", TxtImbCor);
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
	if (TxtImbSrf == comp->TxtImbSrf) insert(items, TXTIMBSRF);
	if (TxtImbCor == comp->TxtImbCor) insert(items, TXTIMBCOR);
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

	diffitems = {TXTSRF, TXTHKU, TXTSUP, TXTTPL, TXTIMBSRF, TXTIMBCOR, TXTCTRFWD, TXTCTRCLR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeModDetail::StatApp
 ******************************************************************************/

void PnlWdbeModDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeModDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeModDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeModDetail::StatShr
 ******************************************************************************/

PnlWdbeModDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
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
			, const bool TxtImbSrfAvail
			, const bool TxtImbSrfActive
			, const bool TxtImbCorAvail
			, const bool TxtImbCorActive
			, const bool ButImbCorViewAvail
			, const bool ButImbCorViewActive
			, const bool PupImbDirAvail
			, const bool PupImbDirActive
			, const bool TxfImbPriAvail
			, const bool TxfImbPriActive
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
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
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
	this->SepImbAvail = SepImbAvail;
	this->HdgImbAvail = HdgImbAvail;
	this->ButImbNewAvail = ButImbNewAvail;
	this->ButImbDeleteAvail = ButImbDeleteAvail;
	this->TxtImbSrfAvail = TxtImbSrfAvail;
	this->TxtImbSrfActive = TxtImbSrfActive;
	this->TxtImbCorAvail = TxtImbCorAvail;
	this->TxtImbCorActive = TxtImbCorActive;
	this->ButImbCorViewAvail = ButImbCorViewAvail;
	this->ButImbCorViewActive = ButImbCorViewActive;
	this->PupImbDirAvail = PupImbDirAvail;
	this->PupImbDirActive = PupImbDirActive;
	this->TxfImbPriAvail = TxfImbPriAvail;
	this->TxfImbPriActive = TxfImbPriActive;
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

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTHKUACTIVE, BUTHKUVIEWAVAIL, BUTHKUVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTPLACTIVE, BUTTPLVIEWAVAIL, BUTTPLVIEWACTIVE, TXFSRRACTIVE, TXFCMTACTIVE, SEPIMBAVAIL, HDGIMBAVAIL, BUTIMBNEWAVAIL, BUTIMBDELETEAVAIL, TXTIMBSRFAVAIL, TXTIMBSRFACTIVE, TXTIMBCORAVAIL, TXTIMBCORACTIVE, BUTIMBCORVIEWAVAIL, BUTIMBCORVIEWACTIVE, PUPIMBDIRAVAIL, PUPIMBDIRACTIVE, TXFIMBPRIAVAIL, TXFIMBPRIACTIVE, SEPCTRAVAIL, HDGCTRAVAIL, BUTCTRNEWAVAIL, BUTCTRDELETEAVAIL, TXFCTRFSRAVAIL, TXFCTRFSRACTIVE, TXTCTRFWDAVAIL, TXTCTRFWDACTIVE, BUTCTRFWDVIEWAVAIL, BUTCTRFWDVIEWACTIVE, TXTCTRCLRAVAIL, TXTCTRCLRACTIVE, BUTCTRCLRVIEWAVAIL, BUTCTRCLRVIEWACTIVE};
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
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
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
		writeBoolAttr(wr, itemtag, "sref", "SepImbAvail", SepImbAvail);
		writeBoolAttr(wr, itemtag, "sref", "HdgImbAvail", HdgImbAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButImbNewAvail", ButImbNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButImbDeleteAvail", ButImbDeleteAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtImbSrfAvail", TxtImbSrfAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtImbSrfActive", TxtImbSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtImbCorAvail", TxtImbCorAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtImbCorActive", TxtImbCorActive);
		writeBoolAttr(wr, itemtag, "sref", "ButImbCorViewAvail", ButImbCorViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButImbCorViewActive", ButImbCorViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupImbDirAvail", PupImbDirAvail);
		writeBoolAttr(wr, itemtag, "sref", "PupImbDirActive", PupImbDirActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfImbPriAvail", TxfImbPriAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfImbPriActive", TxfImbPriActive);
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
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeModDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
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
	if (TxtImbSrfAvail == comp->TxtImbSrfAvail) insert(items, TXTIMBSRFAVAIL);
	if (TxtImbSrfActive == comp->TxtImbSrfActive) insert(items, TXTIMBSRFACTIVE);
	if (TxtImbCorAvail == comp->TxtImbCorAvail) insert(items, TXTIMBCORAVAIL);
	if (TxtImbCorActive == comp->TxtImbCorActive) insert(items, TXTIMBCORACTIVE);
	if (ButImbCorViewAvail == comp->ButImbCorViewAvail) insert(items, BUTIMBCORVIEWAVAIL);
	if (ButImbCorViewActive == comp->ButImbCorViewActive) insert(items, BUTIMBCORVIEWACTIVE);
	if (PupImbDirAvail == comp->PupImbDirAvail) insert(items, PUPIMBDIRAVAIL);
	if (PupImbDirActive == comp->PupImbDirActive) insert(items, PUPIMBDIRACTIVE);
	if (TxfImbPriAvail == comp->TxfImbPriAvail) insert(items, TXFIMBPRIAVAIL);
	if (TxfImbPriActive == comp->TxfImbPriActive) insert(items, TXFIMBPRIACTIVE);
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

	return(items);
};

set<uint> PnlWdbeModDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTHKUACTIVE, BUTHKUVIEWAVAIL, BUTHKUVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTPLACTIVE, BUTTPLVIEWAVAIL, BUTTPLVIEWACTIVE, TXFSRRACTIVE, TXFCMTACTIVE, SEPIMBAVAIL, HDGIMBAVAIL, BUTIMBNEWAVAIL, BUTIMBDELETEAVAIL, TXTIMBSRFAVAIL, TXTIMBSRFACTIVE, TXTIMBCORAVAIL, TXTIMBCORACTIVE, BUTIMBCORVIEWAVAIL, BUTIMBCORVIEWACTIVE, PUPIMBDIRAVAIL, PUPIMBDIRACTIVE, TXFIMBPRIAVAIL, TXFIMBPRIACTIVE, SEPCTRAVAIL, HDGCTRAVAIL, BUTCTRNEWAVAIL, BUTCTRDELETEAVAIL, TXFCTRFSRAVAIL, TXFCTRFSRACTIVE, TXTCTRFWDAVAIL, TXTCTRFWDACTIVE, BUTCTRFWDVIEWAVAIL, BUTCTRFWDVIEWACTIVE, TXTCTRCLRAVAIL, TXTCTRCLRACTIVE, BUTCTRCLRVIEWAVAIL, BUTCTRCLRVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeModDetail::Tag
 ******************************************************************************/

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
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "type");
			writeStringAttr(wr, itemtag, "sref", "CptHku", "hook");
			writeStringAttr(wr, itemtag, "sref", "CptSup", "super module");
			writeStringAttr(wr, itemtag, "sref", "CptTpl", "template");
			writeStringAttr(wr, itemtag, "sref", "CptSrr", "identifier rule");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
			writeStringAttr(wr, itemtag, "sref", "HdgImb", "Inter-module buffer");
			writeStringAttr(wr, itemtag, "sref", "CptImbSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptImbCor", "corresponding module");
			writeStringAttr(wr, itemtag, "sref", "CptImbDir", "direction");
			writeStringAttr(wr, itemtag, "sref", "CptImbPri", "priority");
			writeStringAttr(wr, itemtag, "sref", "HdgCtr", "Controller");
			writeStringAttr(wr, itemtag, "sref", "CptCtrFsr", "full identifier");
			writeStringAttr(wr, itemtag, "sref", "CptCtrFwd", "unit forwarded to");
			writeStringAttr(wr, itemtag, "sref", "CptCtrClr", "command lock request signal");
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
			, Feed* feedFPupImbDir
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEMODDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPHKT, FEEDFPUPIMBDIR, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPHKT) && feedFPupHkt) this->feedFPupHkt = *feedFPupHkt;
	if (find(this->mask, FEEDFPUPIMBDIR) && feedFPupImbDir) this->feedFPupImbDir = *feedFPupImbDir;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeModDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPHKT)) ss.push_back("feedFPupHkt");
	if (has(FEEDFPUPIMBDIR)) ss.push_back("feedFPupImbDir");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
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
	if (src->has(FEEDFPUPIMBDIR)) {feedFPupImbDir = src->feedFPupImbDir; add(FEEDFPUPIMBDIR);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
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
		if (has(FEEDFPUPIMBDIR)) feedFPupImbDir.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};

