/**
	* \file PnlWdbeCdcDetail.cpp
	* API code for job PnlWdbeCdcDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
	*/
// IP header --- ABOVE

#include "PnlWdbeCdcDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeCdcDetail::VecVDo
 ******************************************************************************/

uint PnlWdbeCdcDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butfckviewclick") return BUTFCKVIEWCLICK;
	if (s == "butsckviewclick") return BUTSCKVIEWCLICK;
	if (s == "butmdlviewclick") return BUTMDLVIEWCLICK;
	if (s == "butfarviewclick") return BUTFARVIEWCLICK;
	if (s == "butsarviewclick") return BUTSARVIEWCLICK;

	return(0);
};

string PnlWdbeCdcDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTFCKVIEWCLICK) return("ButFckViewClick");
	if (ix == BUTSCKVIEWCLICK) return("ButSckViewClick");
	if (ix == BUTMDLVIEWCLICK) return("ButMdlViewClick");
	if (ix == BUTFARVIEWCLICK) return("ButFarViewClick");
	if (ix == BUTSARVIEWCLICK) return("ButSarViewClick");

	return("");
};

/******************************************************************************
 class PnlWdbeCdcDetail::ContIac
 ******************************************************************************/

PnlWdbeCdcDetail::ContIac::ContIac(
			const string& TxfFck
			, const string& TxfSck
			, const string& TxfFar
			, const string& TxfSar
			, const string& TxfRat
		) :
			Block()
			, TxfFck(TxfFck)
			, TxfSck(TxfSck)
			, TxfFar(TxfFar)
			, TxfSar(TxfSar)
			, TxfRat(TxfRat)
		{
	mask = {TXFFCK, TXFSCK, TXFFAR, TXFSAR, TXFRAT};
};

bool PnlWdbeCdcDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeCdcDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeCdcDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFck", TxfFck)) add(TXFFCK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSck", TxfSck)) add(TXFSCK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFar", TxfFar)) add(TXFFAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSar", TxfSar)) add(TXFSAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfRat", TxfRat)) add(TXFRAT);
	};

	return basefound;
};

void PnlWdbeCdcDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeCdcDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeCdcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfFck", TxfFck);
		writeStringAttr(wr, itemtag, "sref", "TxfSck", TxfSck);
		writeStringAttr(wr, itemtag, "sref", "TxfFar", TxfFar);
		writeStringAttr(wr, itemtag, "sref", "TxfSar", TxfSar);
		writeStringAttr(wr, itemtag, "sref", "TxfRat", TxfRat);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeCdcDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfFck == comp->TxfFck) insert(items, TXFFCK);
	if (TxfSck == comp->TxfSck) insert(items, TXFSCK);
	if (TxfFar == comp->TxfFar) insert(items, TXFFAR);
	if (TxfSar == comp->TxfSar) insert(items, TXFSAR);
	if (TxfRat == comp->TxfRat) insert(items, TXFRAT);

	return(items);
};

set<uint> PnlWdbeCdcDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFFCK, TXFSCK, TXFFAR, TXFSAR, TXFRAT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeCdcDetail::ContInf
 ******************************************************************************/

PnlWdbeCdcDetail::ContInf::ContInf(
			const string& TxtFck
			, const string& TxtSck
			, const string& TxtMdl
			, const string& TxtFar
			, const string& TxtSar
		) :
			Block()
			, TxtFck(TxtFck)
			, TxtSck(TxtSck)
			, TxtMdl(TxtMdl)
			, TxtFar(TxtFar)
			, TxtSar(TxtSar)
		{
	mask = {TXTFCK, TXTSCK, TXTMDL, TXTFAR, TXTSAR};
};

bool PnlWdbeCdcDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeCdcDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeCdcDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtFck", TxtFck)) add(TXTFCK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSck", TxtSck)) add(TXTSCK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMdl", TxtMdl)) add(TXTMDL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtFar", TxtFar)) add(TXTFAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSar", TxtSar)) add(TXTSAR);
	};

	return basefound;
};

set<uint> PnlWdbeCdcDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtFck == comp->TxtFck) insert(items, TXTFCK);
	if (TxtSck == comp->TxtSck) insert(items, TXTSCK);
	if (TxtMdl == comp->TxtMdl) insert(items, TXTMDL);
	if (TxtFar == comp->TxtFar) insert(items, TXTFAR);
	if (TxtSar == comp->TxtSar) insert(items, TXTSAR);

	return(items);
};

set<uint> PnlWdbeCdcDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTFCK, TXTSCK, TXTMDL, TXTFAR, TXTSAR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeCdcDetail::StatApp
 ******************************************************************************/

PnlWdbeCdcDetail::StatApp::StatApp(
			const uint ixWdbeVExpstate
			, const bool TxtFckAlt
			, const bool TxtSckAlt
			, const bool TxtFarAlt
			, const bool TxtSarAlt
		) :
			Block()
			, ixWdbeVExpstate(ixWdbeVExpstate)
			, TxtFckAlt(TxtFckAlt)
			, TxtSckAlt(TxtSckAlt)
			, TxtFarAlt(TxtFarAlt)
			, TxtSarAlt(TxtSarAlt)
		{
	mask = {IXWDBEVEXPSTATE, TXTFCKALT, TXTSCKALT, TXTFARALT, TXTSARALT};
};

bool PnlWdbeCdcDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeCdcDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeCdcDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtFckAlt", TxtFckAlt)) add(TXTFCKALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSckAlt", TxtSckAlt)) add(TXTSCKALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtFarAlt", TxtFarAlt)) add(TXTFARALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSarAlt", TxtSarAlt)) add(TXTSARALT);
	};

	return basefound;
};

set<uint> PnlWdbeCdcDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (TxtFckAlt == comp->TxtFckAlt) insert(items, TXTFCKALT);
	if (TxtSckAlt == comp->TxtSckAlt) insert(items, TXTSCKALT);
	if (TxtFarAlt == comp->TxtFarAlt) insert(items, TXTFARALT);
	if (TxtSarAlt == comp->TxtSarAlt) insert(items, TXTSARALT);

	return(items);
};

set<uint> PnlWdbeCdcDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, TXTFCKALT, TXTSCKALT, TXTFARALT, TXTSARALT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeCdcDetail::StatShr
 ******************************************************************************/

PnlWdbeCdcDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtFckActive
			, const bool TxfFckValid
			, const bool ButFckViewAvail
			, const bool TxtSckActive
			, const bool TxfSckValid
			, const bool ButSckViewAvail
			, const bool TxtMdlActive
			, const bool ButMdlViewAvail
			, const bool ButMdlViewActive
			, const bool TxtFarActive
			, const bool TxfFarValid
			, const bool ButFarViewAvail
			, const bool TxtSarActive
			, const bool TxfSarValid
			, const bool ButSarViewAvail
			, const bool TxfRatActive
		) :
			Block()
			, ButSaveAvail(ButSaveAvail)
			, ButSaveActive(ButSaveActive)
			, TxtFckActive(TxtFckActive)
			, TxfFckValid(TxfFckValid)
			, ButFckViewAvail(ButFckViewAvail)
			, TxtSckActive(TxtSckActive)
			, TxfSckValid(TxfSckValid)
			, ButSckViewAvail(ButSckViewAvail)
			, TxtMdlActive(TxtMdlActive)
			, ButMdlViewAvail(ButMdlViewAvail)
			, ButMdlViewActive(ButMdlViewActive)
			, TxtFarActive(TxtFarActive)
			, TxfFarValid(TxfFarValid)
			, ButFarViewAvail(ButFarViewAvail)
			, TxtSarActive(TxtSarActive)
			, TxfSarValid(TxfSarValid)
			, ButSarViewAvail(ButSarViewAvail)
			, TxfRatActive(TxfRatActive)
		{
	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTFCKACTIVE, TXFFCKVALID, BUTFCKVIEWAVAIL, TXTSCKACTIVE, TXFSCKVALID, BUTSCKVIEWAVAIL, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, TXTFARACTIVE, TXFFARVALID, BUTFARVIEWAVAIL, TXTSARACTIVE, TXFSARVALID, BUTSARVIEWAVAIL, TXFRATACTIVE};
};

bool PnlWdbeCdcDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeCdcDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeCdcDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtFckActive", TxtFckActive)) add(TXTFCKACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFckValid", TxfFckValid)) add(TXFFCKVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFckViewAvail", ButFckViewAvail)) add(BUTFCKVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSckActive", TxtSckActive)) add(TXTSCKACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfSckValid", TxfSckValid)) add(TXFSCKVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSckViewAvail", ButSckViewAvail)) add(BUTSCKVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtMdlActive", TxtMdlActive)) add(TXTMDLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButMdlViewAvail", ButMdlViewAvail)) add(BUTMDLVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButMdlViewActive", ButMdlViewActive)) add(BUTMDLVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtFarActive", TxtFarActive)) add(TXTFARACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFarValid", TxfFarValid)) add(TXFFARVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFarViewAvail", ButFarViewAvail)) add(BUTFARVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSarActive", TxtSarActive)) add(TXTSARACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfSarValid", TxfSarValid)) add(TXFSARVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSarViewAvail", ButSarViewAvail)) add(BUTSARVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfRatActive", TxfRatActive)) add(TXFRATACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbeCdcDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtFckActive == comp->TxtFckActive) insert(items, TXTFCKACTIVE);
	if (TxfFckValid == comp->TxfFckValid) insert(items, TXFFCKVALID);
	if (ButFckViewAvail == comp->ButFckViewAvail) insert(items, BUTFCKVIEWAVAIL);
	if (TxtSckActive == comp->TxtSckActive) insert(items, TXTSCKACTIVE);
	if (TxfSckValid == comp->TxfSckValid) insert(items, TXFSCKVALID);
	if (ButSckViewAvail == comp->ButSckViewAvail) insert(items, BUTSCKVIEWAVAIL);
	if (TxtMdlActive == comp->TxtMdlActive) insert(items, TXTMDLACTIVE);
	if (ButMdlViewAvail == comp->ButMdlViewAvail) insert(items, BUTMDLVIEWAVAIL);
	if (ButMdlViewActive == comp->ButMdlViewActive) insert(items, BUTMDLVIEWACTIVE);
	if (TxtFarActive == comp->TxtFarActive) insert(items, TXTFARACTIVE);
	if (TxfFarValid == comp->TxfFarValid) insert(items, TXFFARVALID);
	if (ButFarViewAvail == comp->ButFarViewAvail) insert(items, BUTFARVIEWAVAIL);
	if (TxtSarActive == comp->TxtSarActive) insert(items, TXTSARACTIVE);
	if (TxfSarValid == comp->TxfSarValid) insert(items, TXFSARVALID);
	if (ButSarViewAvail == comp->ButSarViewAvail) insert(items, BUTSARVIEWAVAIL);
	if (TxfRatActive == comp->TxfRatActive) insert(items, TXFRATACTIVE);

	return(items);
};

set<uint> PnlWdbeCdcDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTFCKACTIVE, TXFFCKVALID, BUTFCKVIEWAVAIL, TXTSCKACTIVE, TXFSCKVALID, BUTSCKVIEWAVAIL, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, TXTFARACTIVE, TXFFARVALID, BUTFARVIEWAVAIL, TXTSARACTIVE, TXFSARVALID, BUTSARVIEWAVAIL, TXFRATACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeCdcDetail::Tag
 ******************************************************************************/

PnlWdbeCdcDetail::Tag::Tag(
			const string& Cpt
			, const string& CptFck
			, const string& CptSck
			, const string& CptMdl
			, const string& CptFar
			, const string& CptSar
			, const string& CptRat
		) :
			Block()
			, Cpt(Cpt)
			, CptFck(CptFck)
			, CptSck(CptSck)
			, CptMdl(CptMdl)
			, CptFar(CptFar)
			, CptSar(CptSar)
			, CptRat(CptRat)
		{
	mask = {CPT, CPTFCK, CPTSCK, CPTMDL, CPTFAR, CPTSAR, CPTRAT};
};

bool PnlWdbeCdcDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeCdcDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeCdcDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFck", CptFck)) add(CPTFCK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSck", CptSck)) add(CPTSCK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMdl", CptMdl)) add(CPTMDL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFar", CptFar)) add(CPTFAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSar", CptSar)) add(CPTSAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptRat", CptRat)) add(CPTRAT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeCdcDetail::DpchAppData
 ******************************************************************************/

PnlWdbeCdcDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBECDCDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbeCdcDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeCdcDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeCdcDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeCdcDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeCdcDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBECDCDETAILDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWdbeCdcDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeCdcDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeCdcDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeCdcDetail::DpchEngData
 ******************************************************************************/

PnlWdbeCdcDetail::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBECDCDETAILDATA)
		{
};

string PnlWdbeCdcDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeCdcDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeCdcDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
