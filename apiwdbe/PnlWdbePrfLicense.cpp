/**
	* \file PnlWdbePrfLicense.cpp
	* API code for job PnlWdbePrfLicense (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 8 Jan 2025
	*/
// IP header --- ABOVE

#include "PnlWdbePrfLicense.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbePrfLicense::VecVDo
 ******************************************************************************/

uint PnlWdbePrfLicense::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;

	return(0);
};

string PnlWdbePrfLicense::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");

	return("");
};

/******************************************************************************
 class PnlWdbePrfLicense::ContIac
 ******************************************************************************/

PnlWdbePrfLicense::ContIac::ContIac(
			const string& Txf1
			, const string& Txf2
			, const string& Txf3
			, const string& Txf4
			, const string& Txf5
			, const string& Txf6
			, const string& Txf7
			, const string& Txf8
			, const string& Txf9
			, const string& Txf10
		) :
			Block()
			, Txf1(Txf1)
			, Txf2(Txf2)
			, Txf3(Txf3)
			, Txf4(Txf4)
			, Txf5(Txf5)
			, Txf6(Txf6)
			, Txf7(Txf7)
			, Txf8(Txf8)
			, Txf9(Txf9)
			, Txf10(Txf10)
		{
	mask = {TXF1, TXF2, TXF3, TXF4, TXF5, TXF6, TXF7, TXF8, TXF9, TXF10};
};

bool PnlWdbePrfLicense::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbePrfLicense");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbePrfLicense";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf1", Txf1)) add(TXF1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf2", Txf2)) add(TXF2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf3", Txf3)) add(TXF3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf4", Txf4)) add(TXF4);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf5", Txf5)) add(TXF5);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf6", Txf6)) add(TXF6);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf7", Txf7)) add(TXF7);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf8", Txf8)) add(TXF8);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf9", Txf9)) add(TXF9);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf10", Txf10)) add(TXF10);
	};

	return basefound;
};

void PnlWdbePrfLicense::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbePrfLicense";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbePrfLicense";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Txf1", Txf1);
		writeStringAttr(wr, itemtag, "sref", "Txf2", Txf2);
		writeStringAttr(wr, itemtag, "sref", "Txf3", Txf3);
		writeStringAttr(wr, itemtag, "sref", "Txf4", Txf4);
		writeStringAttr(wr, itemtag, "sref", "Txf5", Txf5);
		writeStringAttr(wr, itemtag, "sref", "Txf6", Txf6);
		writeStringAttr(wr, itemtag, "sref", "Txf7", Txf7);
		writeStringAttr(wr, itemtag, "sref", "Txf8", Txf8);
		writeStringAttr(wr, itemtag, "sref", "Txf9", Txf9);
		writeStringAttr(wr, itemtag, "sref", "Txf10", Txf10);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbePrfLicense::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (Txf1 == comp->Txf1) insert(items, TXF1);
	if (Txf2 == comp->Txf2) insert(items, TXF2);
	if (Txf3 == comp->Txf3) insert(items, TXF3);
	if (Txf4 == comp->Txf4) insert(items, TXF4);
	if (Txf5 == comp->Txf5) insert(items, TXF5);
	if (Txf6 == comp->Txf6) insert(items, TXF6);
	if (Txf7 == comp->Txf7) insert(items, TXF7);
	if (Txf8 == comp->Txf8) insert(items, TXF8);
	if (Txf9 == comp->Txf9) insert(items, TXF9);
	if (Txf10 == comp->Txf10) insert(items, TXF10);

	return(items);
};

set<uint> PnlWdbePrfLicense::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXF1, TXF2, TXF3, TXF4, TXF5, TXF6, TXF7, TXF8, TXF9, TXF10};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrfLicense::StatShr
 ******************************************************************************/

PnlWdbePrfLicense::StatShr::StatShr(
			const uint ixWdbeVExpstate
			, const bool Txf1Clean
			, const bool Txf2Clean
			, const bool Txf3Clean
			, const bool Txf4Clean
			, const bool Txf5Clean
			, const bool Txf6Clean
			, const bool Txf7Clean
			, const bool Txf8Clean
			, const bool Txf9Clean
			, const bool Txf10Clean
		) :
			Block()
			, ixWdbeVExpstate(ixWdbeVExpstate)
			, Txf1Clean(Txf1Clean)
			, Txf2Clean(Txf2Clean)
			, Txf3Clean(Txf3Clean)
			, Txf4Clean(Txf4Clean)
			, Txf5Clean(Txf5Clean)
			, Txf6Clean(Txf6Clean)
			, Txf7Clean(Txf7Clean)
			, Txf8Clean(Txf8Clean)
			, Txf9Clean(Txf9Clean)
			, Txf10Clean(Txf10Clean)
		{
	mask = {IXWDBEVEXPSTATE, TXF1CLEAN, TXF2CLEAN, TXF3CLEAN, TXF4CLEAN, TXF5CLEAN, TXF6CLEAN, TXF7CLEAN, TXF8CLEAN, TXF9CLEAN, TXF10CLEAN};
};

bool PnlWdbePrfLicense::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbePrfLicense");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbePrfLicense";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf1Clean", Txf1Clean)) add(TXF1CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf2Clean", Txf2Clean)) add(TXF2CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf3Clean", Txf3Clean)) add(TXF3CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf4Clean", Txf4Clean)) add(TXF4CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf5Clean", Txf5Clean)) add(TXF5CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf6Clean", Txf6Clean)) add(TXF6CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf7Clean", Txf7Clean)) add(TXF7CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf8Clean", Txf8Clean)) add(TXF8CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf9Clean", Txf9Clean)) add(TXF9CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf10Clean", Txf10Clean)) add(TXF10CLEAN);
	};

	return basefound;
};

set<uint> PnlWdbePrfLicense::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (Txf1Clean == comp->Txf1Clean) insert(items, TXF1CLEAN);
	if (Txf2Clean == comp->Txf2Clean) insert(items, TXF2CLEAN);
	if (Txf3Clean == comp->Txf3Clean) insert(items, TXF3CLEAN);
	if (Txf4Clean == comp->Txf4Clean) insert(items, TXF4CLEAN);
	if (Txf5Clean == comp->Txf5Clean) insert(items, TXF5CLEAN);
	if (Txf6Clean == comp->Txf6Clean) insert(items, TXF6CLEAN);
	if (Txf7Clean == comp->Txf7Clean) insert(items, TXF7CLEAN);
	if (Txf8Clean == comp->Txf8Clean) insert(items, TXF8CLEAN);
	if (Txf9Clean == comp->Txf9Clean) insert(items, TXF9CLEAN);
	if (Txf10Clean == comp->Txf10Clean) insert(items, TXF10CLEAN);

	return(items);
};

set<uint> PnlWdbePrfLicense::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, TXF1CLEAN, TXF2CLEAN, TXF3CLEAN, TXF4CLEAN, TXF5CLEAN, TXF6CLEAN, TXF7CLEAN, TXF8CLEAN, TXF9CLEAN, TXF10CLEAN};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrfLicense::Tag
 ******************************************************************************/

PnlWdbePrfLicense::Tag::Tag(
			const string& Cpt
			, const string& Cpt1
			, const string& Cpt2
			, const string& Cpt3
			, const string& Cpt4
			, const string& Cpt5
			, const string& Cpt6
			, const string& Cpt7
			, const string& Cpt8
			, const string& Cpt9
			, const string& Cpt10
		) :
			Block()
			, Cpt(Cpt)
			, Cpt1(Cpt1)
			, Cpt2(Cpt2)
			, Cpt3(Cpt3)
			, Cpt4(Cpt4)
			, Cpt5(Cpt5)
			, Cpt6(Cpt6)
			, Cpt7(Cpt7)
			, Cpt8(Cpt8)
			, Cpt9(Cpt9)
			, Cpt10(Cpt10)
		{
	mask = {CPT, CPT1, CPT2, CPT3, CPT4, CPT5, CPT6, CPT7, CPT8, CPT9, CPT10};
};

bool PnlWdbePrfLicense::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbePrfLicense");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbePrfLicense";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt1", Cpt1)) add(CPT1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt2", Cpt2)) add(CPT2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt3", Cpt3)) add(CPT3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt4", Cpt4)) add(CPT4);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt5", Cpt5)) add(CPT5);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt6", Cpt6)) add(CPT6);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt7", Cpt7)) add(CPT7);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt8", Cpt8)) add(CPT8);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt9", Cpt9)) add(CPT9);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt10", Cpt10)) add(CPT10);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbePrfLicense::DpchAppData
 ******************************************************************************/

PnlWdbePrfLicense::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPRFLICENSEDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbePrfLicense::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrfLicense::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbePrfLicenseData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePrfLicense::DpchAppDo
 ******************************************************************************/

PnlWdbePrfLicense::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPRFLICENSEDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWdbePrfLicense::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrfLicense::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbePrfLicenseDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePrfLicense::DpchEngData
 ******************************************************************************/

PnlWdbePrfLicense::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEPRFLICENSEDATA)
		{
};

string PnlWdbePrfLicense::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrfLicense::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbePrfLicenseData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		statshr = StatShr();
		tag = Tag();
	};
};
