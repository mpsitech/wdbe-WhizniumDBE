/**
	* \file PnlWdbeSilDetail_blks.cpp
	* job handler for job PnlWdbeSilDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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

void PnlWdbeSilDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeSilDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbeSilDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtReu", TxtReu);
		writeStringAttr(wr, itemtag, "sref", "TxtSys", TxtSys);
		writeStringAttr(wr, itemtag, "sref", "TxtMdl", TxtMdl);
	xmlTextWriterEndElement(wr);
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

void PnlWdbeSilDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
			, const bool PupPkgAlt
			, const bool PupTchAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeSilDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeSilDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "PupPkgAlt", PupPkgAlt);
		writeBoolAttr(wr, itemtag, "sref", "PupTchAlt", PupTchAlt);
	xmlTextWriterEndElement(wr);
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

void PnlWdbeSilDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeSilDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeSilDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfPkgValid", TxfPkgValid);
		writeBoolAttr(wr, itemtag, "sref", "TxfTchValid", TxfTchValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfTitActive", TxfTitActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFsrActive", TxfFsrActive);
		writeBoolAttr(wr, itemtag, "sref", "PupTypActive", PupTypActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtReuActive", TxtReuActive);
		writeBoolAttr(wr, itemtag, "sref", "ButReuViewAvail", ButReuViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButReuViewActive", ButReuViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSysActive", TxtSysActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSysViewAvail", ButSysViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSysViewActive", ButSysViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtMdlActive", TxtMdlActive);
		writeBoolAttr(wr, itemtag, "sref", "ButMdlViewAvail", ButMdlViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButMdlViewActive", ButMdlViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupPkgActive", PupPkgActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPkgEditAvail", ButPkgEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "ChkEsyActive", ChkEsyActive);
		writeBoolAttr(wr, itemtag, "sref", "PupTchActive", PupTchActive);
		writeBoolAttr(wr, itemtag, "sref", "ButTchEditAvail", ButTchEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
	xmlTextWriterEndElement(wr);
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

void PnlWdbeSilDetail::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeSilDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeSilDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptTit", "name");
			writeStringAttr(wr, itemtag, "sref", "CptFsr", "full identifier");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "type");
			writeStringAttr(wr, itemtag, "sref", "CptReu", "reference");
			writeStringAttr(wr, itemtag, "sref", "CptSys", "root to system");
			writeStringAttr(wr, itemtag, "sref", "CptMdl", "top module");
			writeStringAttr(wr, itemtag, "sref", "CptPkg", "srefKPackage");
			writeStringAttr(wr, itemtag, "sref", "CptEsy", "easy model");
			writeStringAttr(wr, itemtag, "sref", "CptTch", "srefKToolch");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeSilDetail::DpchAppData
 ******************************************************************************/

PnlWdbeSilDetail::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBESILDETAILDATA)
		{
};

string PnlWdbeSilDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeSilDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeSilDetailData");
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
 class PnlWdbeSilDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeSilDetail::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBESILDETAILDO)
		{
	ixVDo = 0;
};

string PnlWdbeSilDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeSilDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeSilDetailDo");
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
 class PnlWdbeSilDetail::DpchEngData
 ******************************************************************************/

PnlWdbeSilDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupPkg
			, Feed* feedFPupRet
			, Feed* feedFPupTch
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBESILDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPPKG, FEEDFPUPRET, FEEDFPUPTCH, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPPKG) && feedFPupPkg) this->feedFPupPkg = *feedFPupPkg;
	if (find(this->mask, FEEDFPUPRET) && feedFPupRet) this->feedFPupRet = *feedFPupRet;
	if (find(this->mask, FEEDFPUPTCH) && feedFPupTch) this->feedFPupTch = *feedFPupTch;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeSilDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void PnlWdbeSilDetail::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPPKG)) {feedFPupPkg = src->feedFPupPkg; add(FEEDFPUPPKG);};
	if (src->has(FEEDFPUPRET)) {feedFPupRet = src->feedFPupRet; add(FEEDFPUPRET);};
	if (src->has(FEEDFPUPTCH)) {feedFPupTch = src->feedFPupTch; add(FEEDFPUPTCH);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeSilDetail::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeSilDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPPKG)) feedFPupPkg.writeXML(wr);
		if (has(FEEDFPUPRET)) feedFPupRet.writeXML(wr);
		if (has(FEEDFPUPTCH)) feedFPupTch.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};



