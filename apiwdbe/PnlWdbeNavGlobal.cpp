/**
	* \file PnlWdbeNavGlobal.cpp
	* API code for job PnlWdbeNavGlobal (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "PnlWdbeNavGlobal.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeNavGlobal::VecVDo
 ******************************************************************************/

uint PnlWdbeNavGlobal::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butmchviewclick") return BUTMCHVIEWCLICK;
	if (s == "butmchnewcrdclick") return BUTMCHNEWCRDCLICK;
	if (s == "butlibviewclick") return BUTLIBVIEWCLICK;
	if (s == "butlibnewcrdclick") return BUTLIBNEWCRDCLICK;
	if (s == "butfamviewclick") return BUTFAMVIEWCLICK;
	if (s == "butfamnewcrdclick") return BUTFAMNEWCRDCLICK;
	if (s == "butsilviewclick") return BUTSILVIEWCLICK;
	if (s == "butsilnewcrdclick") return BUTSILNEWCRDCLICK;
	if (s == "butmtpviewclick") return BUTMTPVIEWCLICK;
	if (s == "butmtpnewcrdclick") return BUTMTPNEWCRDCLICK;

	return(0);
};

string PnlWdbeNavGlobal::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMCHVIEWCLICK) return("ButMchViewClick");
	if (ix == BUTMCHNEWCRDCLICK) return("ButMchNewcrdClick");
	if (ix == BUTLIBVIEWCLICK) return("ButLibViewClick");
	if (ix == BUTLIBNEWCRDCLICK) return("ButLibNewcrdClick");
	if (ix == BUTFAMVIEWCLICK) return("ButFamViewClick");
	if (ix == BUTFAMNEWCRDCLICK) return("ButFamNewcrdClick");
	if (ix == BUTSILVIEWCLICK) return("ButSilViewClick");
	if (ix == BUTSILNEWCRDCLICK) return("ButSilNewcrdClick");
	if (ix == BUTMTPVIEWCLICK) return("ButMtpViewClick");
	if (ix == BUTMTPNEWCRDCLICK) return("ButMtpNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWdbeNavGlobal::ContIac
 ******************************************************************************/

PnlWdbeNavGlobal::ContIac::ContIac(
			const uint numFLstMch
			, const uint numFLstLib
			, const uint numFLstFam
			, const uint numFLstSil
			, const uint numFLstMtp
		) :
			Block()
		{
	this->numFLstMch = numFLstMch;
	this->numFLstLib = numFLstLib;
	this->numFLstFam = numFLstFam;
	this->numFLstSil = numFLstSil;
	this->numFLstMtp = numFLstMtp;

	mask = {NUMFLSTMCH, NUMFLSTLIB, NUMFLSTFAM, NUMFLSTSIL, NUMFLSTMTP};
};

bool PnlWdbeNavGlobal::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeNavGlobal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeNavGlobal";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstMch", numFLstMch)) add(NUMFLSTMCH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstLib", numFLstLib)) add(NUMFLSTLIB);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFam", numFLstFam)) add(NUMFLSTFAM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSil", numFLstSil)) add(NUMFLSTSIL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstMtp", numFLstMtp)) add(NUMFLSTMTP);
	};

	return basefound;
};

void PnlWdbeNavGlobal::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeNavGlobal";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeNavGlobal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstMch", numFLstMch);
		writeUintAttr(wr, itemtag, "sref", "numFLstLib", numFLstLib);
		writeUintAttr(wr, itemtag, "sref", "numFLstFam", numFLstFam);
		writeUintAttr(wr, itemtag, "sref", "numFLstSil", numFLstSil);
		writeUintAttr(wr, itemtag, "sref", "numFLstMtp", numFLstMtp);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavGlobal::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstMch == comp->numFLstMch) insert(items, NUMFLSTMCH);
	if (numFLstLib == comp->numFLstLib) insert(items, NUMFLSTLIB);
	if (numFLstFam == comp->numFLstFam) insert(items, NUMFLSTFAM);
	if (numFLstSil == comp->numFLstSil) insert(items, NUMFLSTSIL);
	if (numFLstMtp == comp->numFLstMtp) insert(items, NUMFLSTMTP);

	return(items);
};

set<uint> PnlWdbeNavGlobal::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTMCH, NUMFLSTLIB, NUMFLSTFAM, NUMFLSTSIL, NUMFLSTMTP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavGlobal::StatApp
 ******************************************************************************/

PnlWdbeNavGlobal::StatApp::StatApp(
			const uint ixWdbeVExpstate
			, const bool LstMchAlt
			, const bool LstLibAlt
			, const bool LstFamAlt
			, const bool LstSilAlt
			, const bool LstMtpAlt
			, const uint LstMchNumFirstdisp
			, const uint LstLibNumFirstdisp
			, const uint LstFamNumFirstdisp
			, const uint LstSilNumFirstdisp
			, const uint LstMtpNumFirstdisp
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->LstMchAlt = LstMchAlt;
	this->LstLibAlt = LstLibAlt;
	this->LstFamAlt = LstFamAlt;
	this->LstSilAlt = LstSilAlt;
	this->LstMtpAlt = LstMtpAlt;
	this->LstMchNumFirstdisp = LstMchNumFirstdisp;
	this->LstLibNumFirstdisp = LstLibNumFirstdisp;
	this->LstFamNumFirstdisp = LstFamNumFirstdisp;
	this->LstSilNumFirstdisp = LstSilNumFirstdisp;
	this->LstMtpNumFirstdisp = LstMtpNumFirstdisp;

	mask = {IXWDBEVEXPSTATE, LSTMCHALT, LSTLIBALT, LSTFAMALT, LSTSILALT, LSTMTPALT, LSTMCHNUMFIRSTDISP, LSTLIBNUMFIRSTDISP, LSTFAMNUMFIRSTDISP, LSTSILNUMFIRSTDISP, LSTMTPNUMFIRSTDISP};
};

bool PnlWdbeNavGlobal::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeNavGlobal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeNavGlobal";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstMchAlt", LstMchAlt)) add(LSTMCHALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstLibAlt", LstLibAlt)) add(LSTLIBALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFamAlt", LstFamAlt)) add(LSTFAMALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSilAlt", LstSilAlt)) add(LSTSILALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstMtpAlt", LstMtpAlt)) add(LSTMTPALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstMchNumFirstdisp", LstMchNumFirstdisp)) add(LSTMCHNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstLibNumFirstdisp", LstLibNumFirstdisp)) add(LSTLIBNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFamNumFirstdisp", LstFamNumFirstdisp)) add(LSTFAMNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSilNumFirstdisp", LstSilNumFirstdisp)) add(LSTSILNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstMtpNumFirstdisp", LstMtpNumFirstdisp)) add(LSTMTPNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWdbeNavGlobal::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (LstMchAlt == comp->LstMchAlt) insert(items, LSTMCHALT);
	if (LstLibAlt == comp->LstLibAlt) insert(items, LSTLIBALT);
	if (LstFamAlt == comp->LstFamAlt) insert(items, LSTFAMALT);
	if (LstSilAlt == comp->LstSilAlt) insert(items, LSTSILALT);
	if (LstMtpAlt == comp->LstMtpAlt) insert(items, LSTMTPALT);
	if (LstMchNumFirstdisp == comp->LstMchNumFirstdisp) insert(items, LSTMCHNUMFIRSTDISP);
	if (LstLibNumFirstdisp == comp->LstLibNumFirstdisp) insert(items, LSTLIBNUMFIRSTDISP);
	if (LstFamNumFirstdisp == comp->LstFamNumFirstdisp) insert(items, LSTFAMNUMFIRSTDISP);
	if (LstSilNumFirstdisp == comp->LstSilNumFirstdisp) insert(items, LSTSILNUMFIRSTDISP);
	if (LstMtpNumFirstdisp == comp->LstMtpNumFirstdisp) insert(items, LSTMTPNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWdbeNavGlobal::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, LSTMCHALT, LSTLIBALT, LSTFAMALT, LSTSILALT, LSTMTPALT, LSTMCHNUMFIRSTDISP, LSTLIBNUMFIRSTDISP, LSTFAMNUMFIRSTDISP, LSTSILNUMFIRSTDISP, LSTMTPNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavGlobal::StatShr
 ******************************************************************************/

PnlWdbeNavGlobal::StatShr::StatShr(
			const bool LstMchAvail
			, const bool ButMchViewActive
			, const bool LstLibAvail
			, const bool ButLibViewActive
			, const bool LstFamAvail
			, const bool ButFamViewActive
			, const bool LstSilAvail
			, const bool ButSilViewActive
			, const bool LstMtpAvail
			, const bool ButMtpViewActive
		) :
			Block()
		{
	this->LstMchAvail = LstMchAvail;
	this->ButMchViewActive = ButMchViewActive;
	this->LstLibAvail = LstLibAvail;
	this->ButLibViewActive = ButLibViewActive;
	this->LstFamAvail = LstFamAvail;
	this->ButFamViewActive = ButFamViewActive;
	this->LstSilAvail = LstSilAvail;
	this->ButSilViewActive = ButSilViewActive;
	this->LstMtpAvail = LstMtpAvail;
	this->ButMtpViewActive = ButMtpViewActive;

	mask = {LSTMCHAVAIL, BUTMCHVIEWACTIVE, LSTLIBAVAIL, BUTLIBVIEWACTIVE, LSTFAMAVAIL, BUTFAMVIEWACTIVE, LSTSILAVAIL, BUTSILVIEWACTIVE, LSTMTPAVAIL, BUTMTPVIEWACTIVE};
};

bool PnlWdbeNavGlobal::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeNavGlobal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeNavGlobal";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstMchAvail", LstMchAvail)) add(LSTMCHAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButMchViewActive", ButMchViewActive)) add(BUTMCHVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstLibAvail", LstLibAvail)) add(LSTLIBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButLibViewActive", ButLibViewActive)) add(BUTLIBVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFamAvail", LstFamAvail)) add(LSTFAMAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFamViewActive", ButFamViewActive)) add(BUTFAMVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSilAvail", LstSilAvail)) add(LSTSILAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSilViewActive", ButSilViewActive)) add(BUTSILVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstMtpAvail", LstMtpAvail)) add(LSTMTPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButMtpViewActive", ButMtpViewActive)) add(BUTMTPVIEWACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbeNavGlobal::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstMchAvail == comp->LstMchAvail) insert(items, LSTMCHAVAIL);
	if (ButMchViewActive == comp->ButMchViewActive) insert(items, BUTMCHVIEWACTIVE);
	if (LstLibAvail == comp->LstLibAvail) insert(items, LSTLIBAVAIL);
	if (ButLibViewActive == comp->ButLibViewActive) insert(items, BUTLIBVIEWACTIVE);
	if (LstFamAvail == comp->LstFamAvail) insert(items, LSTFAMAVAIL);
	if (ButFamViewActive == comp->ButFamViewActive) insert(items, BUTFAMVIEWACTIVE);
	if (LstSilAvail == comp->LstSilAvail) insert(items, LSTSILAVAIL);
	if (ButSilViewActive == comp->ButSilViewActive) insert(items, BUTSILVIEWACTIVE);
	if (LstMtpAvail == comp->LstMtpAvail) insert(items, LSTMTPAVAIL);
	if (ButMtpViewActive == comp->ButMtpViewActive) insert(items, BUTMTPVIEWACTIVE);

	return(items);
};

set<uint> PnlWdbeNavGlobal::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTMCHAVAIL, BUTMCHVIEWACTIVE, LSTLIBAVAIL, BUTLIBVIEWACTIVE, LSTFAMAVAIL, BUTFAMVIEWACTIVE, LSTSILAVAIL, BUTSILVIEWACTIVE, LSTMTPAVAIL, BUTMTPVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavGlobal::Tag
 ******************************************************************************/

PnlWdbeNavGlobal::Tag::Tag(
			const string& Cpt
			, const string& CptMch
			, const string& CptLib
			, const string& CptFam
			, const string& CptSil
			, const string& CptMtp
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptMch = CptMch;
	this->CptLib = CptLib;
	this->CptFam = CptFam;
	this->CptSil = CptSil;
	this->CptMtp = CptMtp;

	mask = {CPT, CPTMCH, CPTLIB, CPTFAM, CPTSIL, CPTMTP};
};

bool PnlWdbeNavGlobal::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeNavGlobal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeNavGlobal";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMch", CptMch)) add(CPTMCH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLib", CptLib)) add(CPTLIB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFam", CptFam)) add(CPTFAM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSil", CptSil)) add(CPTSIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMtp", CptMtp)) add(CPTMTP);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeNavGlobal::DpchAppData
 ******************************************************************************/

PnlWdbeNavGlobal::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVGLOBALDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbeNavGlobal::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavGlobal::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeNavGlobalData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavGlobal::DpchAppDo
 ******************************************************************************/

PnlWdbeNavGlobal::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVGLOBALDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbeNavGlobal::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavGlobal::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeNavGlobalDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavGlobal::DpchEngData
 ******************************************************************************/

PnlWdbeNavGlobal::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBENAVGLOBALDATA)
		{
	feedFLstFam.tag = "FeedFLstFam";
	feedFLstLib.tag = "FeedFLstLib";
	feedFLstMch.tag = "FeedFLstMch";
	feedFLstMtp.tag = "FeedFLstMtp";
	feedFLstSil.tag = "FeedFLstSil";
};

string PnlWdbeNavGlobal::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTFAM)) ss.push_back("feedFLstFam");
	if (has(FEEDFLSTLIB)) ss.push_back("feedFLstLib");
	if (has(FEEDFLSTMCH)) ss.push_back("feedFLstMch");
	if (has(FEEDFLSTMTP)) ss.push_back("feedFLstMtp");
	if (has(FEEDFLSTSIL)) ss.push_back("feedFLstSil");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavGlobal::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeNavGlobalData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstFam.readXML(docctx, basexpath, true)) add(FEEDFLSTFAM);
		if (feedFLstLib.readXML(docctx, basexpath, true)) add(FEEDFLSTLIB);
		if (feedFLstMch.readXML(docctx, basexpath, true)) add(FEEDFLSTMCH);
		if (feedFLstMtp.readXML(docctx, basexpath, true)) add(FEEDFLSTMTP);
		if (feedFLstSil.readXML(docctx, basexpath, true)) add(FEEDFLSTSIL);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstFam.clear();
		feedFLstLib.clear();
		feedFLstMch.clear();
		feedFLstMtp.clear();
		feedFLstSil.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

