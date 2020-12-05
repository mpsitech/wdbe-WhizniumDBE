/**
	* \file PnlWdbeNavDevdev.cpp
	* API code for job PnlWdbeNavDevdev (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWdbeNavDevdev.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeNavDevdev::VecVDo
 ******************************************************************************/

uint PnlWdbeNavDevdev::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butprjviewclick") return BUTPRJVIEWCLICK;
	if (s == "butprjnewcrdclick") return BUTPRJNEWCRDCLICK;
	if (s == "butverviewclick") return BUTVERVIEWCLICK;
	if (s == "butvernewcrdclick") return BUTVERNEWCRDCLICK;
	if (s == "butsysviewclick") return BUTSYSVIEWCLICK;
	if (s == "butsysnewcrdclick") return BUTSYSNEWCRDCLICK;
	if (s == "buttrgviewclick") return BUTTRGVIEWCLICK;
	if (s == "buttrgnewcrdclick") return BUTTRGNEWCRDCLICK;
	if (s == "butuntviewclick") return BUTUNTVIEWCLICK;
	if (s == "butuntnewcrdclick") return BUTUNTNEWCRDCLICK;
	if (s == "butrlsviewclick") return BUTRLSVIEWCLICK;
	if (s == "butrlsnewcrdclick") return BUTRLSNEWCRDCLICK;

	return(0);
};

string PnlWdbeNavDevdev::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTPRJVIEWCLICK) return("ButPrjViewClick");
	if (ix == BUTPRJNEWCRDCLICK) return("ButPrjNewcrdClick");
	if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
	if (ix == BUTVERNEWCRDCLICK) return("ButVerNewcrdClick");
	if (ix == BUTSYSVIEWCLICK) return("ButSysViewClick");
	if (ix == BUTSYSNEWCRDCLICK) return("ButSysNewcrdClick");
	if (ix == BUTTRGVIEWCLICK) return("ButTrgViewClick");
	if (ix == BUTTRGNEWCRDCLICK) return("ButTrgNewcrdClick");
	if (ix == BUTUNTVIEWCLICK) return("ButUntViewClick");
	if (ix == BUTUNTNEWCRDCLICK) return("ButUntNewcrdClick");
	if (ix == BUTRLSVIEWCLICK) return("ButRlsViewClick");
	if (ix == BUTRLSNEWCRDCLICK) return("ButRlsNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWdbeNavDevdev::ContIac
 ******************************************************************************/

PnlWdbeNavDevdev::ContIac::ContIac(
			const uint numFLstPrj
			, const uint numFLstVer
			, const uint numFLstSys
			, const uint numFLstTrg
			, const uint numFLstUnt
			, const uint numFLstRls
		) :
			Block()
		{
	this->numFLstPrj = numFLstPrj;
	this->numFLstVer = numFLstVer;
	this->numFLstSys = numFLstSys;
	this->numFLstTrg = numFLstTrg;
	this->numFLstUnt = numFLstUnt;
	this->numFLstRls = numFLstRls;

	mask = {NUMFLSTPRJ, NUMFLSTVER, NUMFLSTSYS, NUMFLSTTRG, NUMFLSTUNT, NUMFLSTRLS};
};

bool PnlWdbeNavDevdev::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeNavDevdev");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeNavDevdev";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPrj", numFLstPrj)) add(NUMFLSTPRJ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstVer", numFLstVer)) add(NUMFLSTVER);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSys", numFLstSys)) add(NUMFLSTSYS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstTrg", numFLstTrg)) add(NUMFLSTTRG);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstUnt", numFLstUnt)) add(NUMFLSTUNT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstRls", numFLstRls)) add(NUMFLSTRLS);
	};

	return basefound;
};

void PnlWdbeNavDevdev::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeNavDevdev";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeNavDevdev";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstPrj", numFLstPrj);
		writeUintAttr(wr, itemtag, "sref", "numFLstVer", numFLstVer);
		writeUintAttr(wr, itemtag, "sref", "numFLstSys", numFLstSys);
		writeUintAttr(wr, itemtag, "sref", "numFLstTrg", numFLstTrg);
		writeUintAttr(wr, itemtag, "sref", "numFLstUnt", numFLstUnt);
		writeUintAttr(wr, itemtag, "sref", "numFLstRls", numFLstRls);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavDevdev::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstPrj == comp->numFLstPrj) insert(items, NUMFLSTPRJ);
	if (numFLstVer == comp->numFLstVer) insert(items, NUMFLSTVER);
	if (numFLstSys == comp->numFLstSys) insert(items, NUMFLSTSYS);
	if (numFLstTrg == comp->numFLstTrg) insert(items, NUMFLSTTRG);
	if (numFLstUnt == comp->numFLstUnt) insert(items, NUMFLSTUNT);
	if (numFLstRls == comp->numFLstRls) insert(items, NUMFLSTRLS);

	return(items);
};

set<uint> PnlWdbeNavDevdev::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTPRJ, NUMFLSTVER, NUMFLSTSYS, NUMFLSTTRG, NUMFLSTUNT, NUMFLSTRLS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavDevdev::StatApp
 ******************************************************************************/

PnlWdbeNavDevdev::StatApp::StatApp(
			const uint ixWdbeVExpstate
			, const bool LstPrjAlt
			, const bool LstVerAlt
			, const bool LstSysAlt
			, const bool LstTrgAlt
			, const bool LstUntAlt
			, const bool LstRlsAlt
			, const uint LstPrjNumFirstdisp
			, const uint LstVerNumFirstdisp
			, const uint LstSysNumFirstdisp
			, const uint LstTrgNumFirstdisp
			, const uint LstUntNumFirstdisp
			, const uint LstRlsNumFirstdisp
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->LstPrjAlt = LstPrjAlt;
	this->LstVerAlt = LstVerAlt;
	this->LstSysAlt = LstSysAlt;
	this->LstTrgAlt = LstTrgAlt;
	this->LstUntAlt = LstUntAlt;
	this->LstRlsAlt = LstRlsAlt;
	this->LstPrjNumFirstdisp = LstPrjNumFirstdisp;
	this->LstVerNumFirstdisp = LstVerNumFirstdisp;
	this->LstSysNumFirstdisp = LstSysNumFirstdisp;
	this->LstTrgNumFirstdisp = LstTrgNumFirstdisp;
	this->LstUntNumFirstdisp = LstUntNumFirstdisp;
	this->LstRlsNumFirstdisp = LstRlsNumFirstdisp;

	mask = {IXWDBEVEXPSTATE, LSTPRJALT, LSTVERALT, LSTSYSALT, LSTTRGALT, LSTUNTALT, LSTRLSALT, LSTPRJNUMFIRSTDISP, LSTVERNUMFIRSTDISP, LSTSYSNUMFIRSTDISP, LSTTRGNUMFIRSTDISP, LSTUNTNUMFIRSTDISP, LSTRLSNUMFIRSTDISP};
};

bool PnlWdbeNavDevdev::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeNavDevdev");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeNavDevdev";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrjAlt", LstPrjAlt)) add(LSTPRJALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVerAlt", LstVerAlt)) add(LSTVERALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSysAlt", LstSysAlt)) add(LSTSYSALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTrgAlt", LstTrgAlt)) add(LSTTRGALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUntAlt", LstUntAlt)) add(LSTUNTALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRlsAlt", LstRlsAlt)) add(LSTRLSALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrjNumFirstdisp", LstPrjNumFirstdisp)) add(LSTPRJNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVerNumFirstdisp", LstVerNumFirstdisp)) add(LSTVERNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSysNumFirstdisp", LstSysNumFirstdisp)) add(LSTSYSNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTrgNumFirstdisp", LstTrgNumFirstdisp)) add(LSTTRGNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUntNumFirstdisp", LstUntNumFirstdisp)) add(LSTUNTNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRlsNumFirstdisp", LstRlsNumFirstdisp)) add(LSTRLSNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWdbeNavDevdev::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (LstPrjAlt == comp->LstPrjAlt) insert(items, LSTPRJALT);
	if (LstVerAlt == comp->LstVerAlt) insert(items, LSTVERALT);
	if (LstSysAlt == comp->LstSysAlt) insert(items, LSTSYSALT);
	if (LstTrgAlt == comp->LstTrgAlt) insert(items, LSTTRGALT);
	if (LstUntAlt == comp->LstUntAlt) insert(items, LSTUNTALT);
	if (LstRlsAlt == comp->LstRlsAlt) insert(items, LSTRLSALT);
	if (LstPrjNumFirstdisp == comp->LstPrjNumFirstdisp) insert(items, LSTPRJNUMFIRSTDISP);
	if (LstVerNumFirstdisp == comp->LstVerNumFirstdisp) insert(items, LSTVERNUMFIRSTDISP);
	if (LstSysNumFirstdisp == comp->LstSysNumFirstdisp) insert(items, LSTSYSNUMFIRSTDISP);
	if (LstTrgNumFirstdisp == comp->LstTrgNumFirstdisp) insert(items, LSTTRGNUMFIRSTDISP);
	if (LstUntNumFirstdisp == comp->LstUntNumFirstdisp) insert(items, LSTUNTNUMFIRSTDISP);
	if (LstRlsNumFirstdisp == comp->LstRlsNumFirstdisp) insert(items, LSTRLSNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWdbeNavDevdev::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, LSTPRJALT, LSTVERALT, LSTSYSALT, LSTTRGALT, LSTUNTALT, LSTRLSALT, LSTPRJNUMFIRSTDISP, LSTVERNUMFIRSTDISP, LSTSYSNUMFIRSTDISP, LSTTRGNUMFIRSTDISP, LSTUNTNUMFIRSTDISP, LSTRLSNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavDevdev::StatShr
 ******************************************************************************/

PnlWdbeNavDevdev::StatShr::StatShr(
			const bool LstPrjAvail
			, const bool ButPrjViewActive
			, const bool LstVerAvail
			, const bool ButVerViewActive
			, const bool LstSysAvail
			, const bool ButSysViewActive
			, const bool ButSysNewcrdActive
			, const bool LstTrgAvail
			, const bool ButTrgViewActive
			, const bool ButTrgNewcrdActive
			, const bool LstUntAvail
			, const bool ButUntViewActive
			, const bool ButUntNewcrdActive
			, const bool LstRlsAvail
			, const bool ButRlsViewActive
			, const bool ButRlsNewcrdActive
		) :
			Block()
		{
	this->LstPrjAvail = LstPrjAvail;
	this->ButPrjViewActive = ButPrjViewActive;
	this->LstVerAvail = LstVerAvail;
	this->ButVerViewActive = ButVerViewActive;
	this->LstSysAvail = LstSysAvail;
	this->ButSysViewActive = ButSysViewActive;
	this->ButSysNewcrdActive = ButSysNewcrdActive;
	this->LstTrgAvail = LstTrgAvail;
	this->ButTrgViewActive = ButTrgViewActive;
	this->ButTrgNewcrdActive = ButTrgNewcrdActive;
	this->LstUntAvail = LstUntAvail;
	this->ButUntViewActive = ButUntViewActive;
	this->ButUntNewcrdActive = ButUntNewcrdActive;
	this->LstRlsAvail = LstRlsAvail;
	this->ButRlsViewActive = ButRlsViewActive;
	this->ButRlsNewcrdActive = ButRlsNewcrdActive;

	mask = {LSTPRJAVAIL, BUTPRJVIEWACTIVE, LSTVERAVAIL, BUTVERVIEWACTIVE, LSTSYSAVAIL, BUTSYSVIEWACTIVE, BUTSYSNEWCRDACTIVE, LSTTRGAVAIL, BUTTRGVIEWACTIVE, BUTTRGNEWCRDACTIVE, LSTUNTAVAIL, BUTUNTVIEWACTIVE, BUTUNTNEWCRDACTIVE, LSTRLSAVAIL, BUTRLSVIEWACTIVE, BUTRLSNEWCRDACTIVE};
};

bool PnlWdbeNavDevdev::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeNavDevdev");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeNavDevdev";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrjAvail", LstPrjAvail)) add(LSTPRJAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrjViewActive", ButPrjViewActive)) add(BUTPRJVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVerAvail", LstVerAvail)) add(LSTVERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVerViewActive", ButVerViewActive)) add(BUTVERVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSysAvail", LstSysAvail)) add(LSTSYSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSysViewActive", ButSysViewActive)) add(BUTSYSVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSysNewcrdActive", ButSysNewcrdActive)) add(BUTSYSNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTrgAvail", LstTrgAvail)) add(LSTTRGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTrgViewActive", ButTrgViewActive)) add(BUTTRGVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTrgNewcrdActive", ButTrgNewcrdActive)) add(BUTTRGNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUntAvail", LstUntAvail)) add(LSTUNTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUntViewActive", ButUntViewActive)) add(BUTUNTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUntNewcrdActive", ButUntNewcrdActive)) add(BUTUNTNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRlsAvail", LstRlsAvail)) add(LSTRLSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRlsViewActive", ButRlsViewActive)) add(BUTRLSVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRlsNewcrdActive", ButRlsNewcrdActive)) add(BUTRLSNEWCRDACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbeNavDevdev::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstPrjAvail == comp->LstPrjAvail) insert(items, LSTPRJAVAIL);
	if (ButPrjViewActive == comp->ButPrjViewActive) insert(items, BUTPRJVIEWACTIVE);
	if (LstVerAvail == comp->LstVerAvail) insert(items, LSTVERAVAIL);
	if (ButVerViewActive == comp->ButVerViewActive) insert(items, BUTVERVIEWACTIVE);
	if (LstSysAvail == comp->LstSysAvail) insert(items, LSTSYSAVAIL);
	if (ButSysViewActive == comp->ButSysViewActive) insert(items, BUTSYSVIEWACTIVE);
	if (ButSysNewcrdActive == comp->ButSysNewcrdActive) insert(items, BUTSYSNEWCRDACTIVE);
	if (LstTrgAvail == comp->LstTrgAvail) insert(items, LSTTRGAVAIL);
	if (ButTrgViewActive == comp->ButTrgViewActive) insert(items, BUTTRGVIEWACTIVE);
	if (ButTrgNewcrdActive == comp->ButTrgNewcrdActive) insert(items, BUTTRGNEWCRDACTIVE);
	if (LstUntAvail == comp->LstUntAvail) insert(items, LSTUNTAVAIL);
	if (ButUntViewActive == comp->ButUntViewActive) insert(items, BUTUNTVIEWACTIVE);
	if (ButUntNewcrdActive == comp->ButUntNewcrdActive) insert(items, BUTUNTNEWCRDACTIVE);
	if (LstRlsAvail == comp->LstRlsAvail) insert(items, LSTRLSAVAIL);
	if (ButRlsViewActive == comp->ButRlsViewActive) insert(items, BUTRLSVIEWACTIVE);
	if (ButRlsNewcrdActive == comp->ButRlsNewcrdActive) insert(items, BUTRLSNEWCRDACTIVE);

	return(items);
};

set<uint> PnlWdbeNavDevdev::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTPRJAVAIL, BUTPRJVIEWACTIVE, LSTVERAVAIL, BUTVERVIEWACTIVE, LSTSYSAVAIL, BUTSYSVIEWACTIVE, BUTSYSNEWCRDACTIVE, LSTTRGAVAIL, BUTTRGVIEWACTIVE, BUTTRGNEWCRDACTIVE, LSTUNTAVAIL, BUTUNTVIEWACTIVE, BUTUNTNEWCRDACTIVE, LSTRLSAVAIL, BUTRLSVIEWACTIVE, BUTRLSNEWCRDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavDevdev::Tag
 ******************************************************************************/

PnlWdbeNavDevdev::Tag::Tag(
			const string& Cpt
			, const string& CptPrj
			, const string& CptVer
			, const string& CptSys
			, const string& CptTrg
			, const string& CptUnt
			, const string& CptRls
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptPrj = CptPrj;
	this->CptVer = CptVer;
	this->CptSys = CptSys;
	this->CptTrg = CptTrg;
	this->CptUnt = CptUnt;
	this->CptRls = CptRls;

	mask = {CPT, CPTPRJ, CPTVER, CPTSYS, CPTTRG, CPTUNT, CPTRLS};
};

bool PnlWdbeNavDevdev::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeNavDevdev");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeNavDevdev";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrj", CptPrj)) add(CPTPRJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVer", CptVer)) add(CPTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSys", CptSys)) add(CPTSYS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTrg", CptTrg)) add(CPTTRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUnt", CptUnt)) add(CPTUNT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptRls", CptRls)) add(CPTRLS);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeNavDevdev::DpchAppData
 ******************************************************************************/

PnlWdbeNavDevdev::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVDEVDEVDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbeNavDevdev::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavDevdev::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeNavDevdevData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavDevdev::DpchAppDo
 ******************************************************************************/

PnlWdbeNavDevdev::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVDEVDEVDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbeNavDevdev::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavDevdev::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeNavDevdevDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavDevdev::DpchEngData
 ******************************************************************************/

PnlWdbeNavDevdev::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBENAVDEVDEVDATA)
		{
	feedFLstPrj.tag = "FeedFLstPrj";
	feedFLstRls.tag = "FeedFLstRls";
	feedFLstSys.tag = "FeedFLstSys";
	feedFLstTrg.tag = "FeedFLstTrg";
	feedFLstUnt.tag = "FeedFLstUnt";
	feedFLstVer.tag = "FeedFLstVer";
};

string PnlWdbeNavDevdev::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTPRJ)) ss.push_back("feedFLstPrj");
	if (has(FEEDFLSTRLS)) ss.push_back("feedFLstRls");
	if (has(FEEDFLSTSYS)) ss.push_back("feedFLstSys");
	if (has(FEEDFLSTTRG)) ss.push_back("feedFLstTrg");
	if (has(FEEDFLSTUNT)) ss.push_back("feedFLstUnt");
	if (has(FEEDFLSTVER)) ss.push_back("feedFLstVer");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavDevdev::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeNavDevdevData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstPrj.readXML(docctx, basexpath, true)) add(FEEDFLSTPRJ);
		if (feedFLstRls.readXML(docctx, basexpath, true)) add(FEEDFLSTRLS);
		if (feedFLstSys.readXML(docctx, basexpath, true)) add(FEEDFLSTSYS);
		if (feedFLstTrg.readXML(docctx, basexpath, true)) add(FEEDFLSTTRG);
		if (feedFLstUnt.readXML(docctx, basexpath, true)) add(FEEDFLSTUNT);
		if (feedFLstVer.readXML(docctx, basexpath, true)) add(FEEDFLSTVER);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstPrj.clear();
		feedFLstRls.clear();
		feedFLstSys.clear();
		feedFLstTrg.clear();
		feedFLstUnt.clear();
		feedFLstVer.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

