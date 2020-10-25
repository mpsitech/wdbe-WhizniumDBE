/**
	* \file PnlWdbeFstAStep.cpp
	* API code for job PnlWdbeFstAStep (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "PnlWdbeFstAStep.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeFstAStep::VecVDo
 ******************************************************************************/

uint PnlWdbeFstAStep::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butupclick") return BUTUPCLICK;
	if (s == "butdownclick") return BUTDOWNCLICK;
	if (s == "butnewclick") return BUTNEWCLICK;
	if (s == "butduplicateclick") return BUTDUPLICATECLICK;
	if (s == "butdeleteclick") return BUTDELETECLICK;
	if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlWdbeFstAStep::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTUPCLICK) return("ButUpClick");
	if (ix == BUTDOWNCLICK) return("ButDownClick");
	if (ix == BUTNEWCLICK) return("ButNewClick");
	if (ix == BUTDUPLICATECLICK) return("ButDuplicateClick");
	if (ix == BUTDELETECLICK) return("ButDeleteClick");
	if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlWdbeFstAStep::ContInf
 ******************************************************************************/

PnlWdbeFstAStep::ContInf::ContInf(
			const uint numFCsiQst
		) :
			Block()
		{
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

bool PnlWdbeFstAStep::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeFstAStep");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeFstAStep";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFCsiQst", numFCsiQst)) add(NUMFCSIQST);
	};

	return basefound;
};

set<uint> PnlWdbeFstAStep::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlWdbeFstAStep::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFCSIQST};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeFstAStep::StatApp
 ******************************************************************************/

PnlWdbeFstAStep::StatApp::StatApp(
			const uint ixWdbeVExpstate
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;

	mask = {IXWDBEVEXPSTATE};
};

bool PnlWdbeFstAStep::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeFstAStep");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeFstAStep";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWdbeFstAStep::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);

	return(items);
};

set<uint> PnlWdbeFstAStep::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeFstAStep::StatShr
 ******************************************************************************/

PnlWdbeFstAStep::StatShr::StatShr(
			const bool ButUpAvail
			, const bool ButUpActive
			, const bool ButDownAvail
			, const bool ButDownActive
			, const bool ButNewAvail
			, const bool ButDuplicateAvail
			, const bool ButDuplicateActive
			, const bool ButDeleteAvail
			, const bool ButDeleteActive
		) :
			Block()
		{
	this->ButUpAvail = ButUpAvail;
	this->ButUpActive = ButUpActive;
	this->ButDownAvail = ButDownAvail;
	this->ButDownActive = ButDownActive;
	this->ButNewAvail = ButNewAvail;
	this->ButDuplicateAvail = ButDuplicateAvail;
	this->ButDuplicateActive = ButDuplicateActive;
	this->ButDeleteAvail = ButDeleteAvail;
	this->ButDeleteActive = ButDeleteActive;

	mask = {BUTUPAVAIL, BUTUPACTIVE, BUTDOWNAVAIL, BUTDOWNACTIVE, BUTNEWAVAIL, BUTDUPLICATEAVAIL, BUTDUPLICATEACTIVE, BUTDELETEAVAIL, BUTDELETEACTIVE};
};

bool PnlWdbeFstAStep::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeFstAStep");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeFstAStep";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUpAvail", ButUpAvail)) add(BUTUPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUpActive", ButUpActive)) add(BUTUPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDownAvail", ButDownAvail)) add(BUTDOWNAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDownActive", ButDownActive)) add(BUTDOWNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButNewAvail", ButNewAvail)) add(BUTNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDuplicateAvail", ButDuplicateAvail)) add(BUTDUPLICATEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDuplicateActive", ButDuplicateActive)) add(BUTDUPLICATEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDeleteAvail", ButDeleteAvail)) add(BUTDELETEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDeleteActive", ButDeleteActive)) add(BUTDELETEACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbeFstAStep::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButUpAvail == comp->ButUpAvail) insert(items, BUTUPAVAIL);
	if (ButUpActive == comp->ButUpActive) insert(items, BUTUPACTIVE);
	if (ButDownAvail == comp->ButDownAvail) insert(items, BUTDOWNAVAIL);
	if (ButDownActive == comp->ButDownActive) insert(items, BUTDOWNACTIVE);
	if (ButNewAvail == comp->ButNewAvail) insert(items, BUTNEWAVAIL);
	if (ButDuplicateAvail == comp->ButDuplicateAvail) insert(items, BUTDUPLICATEAVAIL);
	if (ButDuplicateActive == comp->ButDuplicateActive) insert(items, BUTDUPLICATEACTIVE);
	if (ButDeleteAvail == comp->ButDeleteAvail) insert(items, BUTDELETEAVAIL);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlWdbeFstAStep::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTUPAVAIL, BUTUPACTIVE, BUTDOWNAVAIL, BUTDOWNACTIVE, BUTNEWAVAIL, BUTDUPLICATEAVAIL, BUTDUPLICATEACTIVE, BUTDELETEAVAIL, BUTDELETEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeFstAStep::StgIac
 ******************************************************************************/

PnlWdbeFstAStep::StgIac::StgIac(
			const uint TcoFnxWidth
			, const uint TcoCn1Width
			, const uint TcoIp1Width
			, const uint TcoCn2Width
			, const uint TcoIp2Width
			, const uint TcoCn3Width
			, const uint TcoIp3Width
			, const uint TcoCn4Width
			, const uint TcoIp4Width
		) :
			Block()
		{
	this->TcoFnxWidth = TcoFnxWidth;
	this->TcoCn1Width = TcoCn1Width;
	this->TcoIp1Width = TcoIp1Width;
	this->TcoCn2Width = TcoCn2Width;
	this->TcoIp2Width = TcoIp2Width;
	this->TcoCn3Width = TcoCn3Width;
	this->TcoIp3Width = TcoIp3Width;
	this->TcoCn4Width = TcoCn4Width;
	this->TcoIp4Width = TcoIp4Width;

	mask = {TCOFNXWIDTH, TCOCN1WIDTH, TCOIP1WIDTH, TCOCN2WIDTH, TCOIP2WIDTH, TCOCN3WIDTH, TCOIP3WIDTH, TCOCN4WIDTH, TCOIP4WIDTH};
};

bool PnlWdbeFstAStep::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacWdbeFstAStep");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacWdbeFstAStep";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoFnxWidth", TcoFnxWidth)) add(TCOFNXWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCn1Width", TcoCn1Width)) add(TCOCN1WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoIp1Width", TcoIp1Width)) add(TCOIP1WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCn2Width", TcoCn2Width)) add(TCOCN2WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoIp2Width", TcoIp2Width)) add(TCOIP2WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCn3Width", TcoCn3Width)) add(TCOCN3WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoIp3Width", TcoIp3Width)) add(TCOIP3WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCn4Width", TcoCn4Width)) add(TCOCN4WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoIp4Width", TcoIp4Width)) add(TCOIP4WIDTH);
	};

	return basefound;
};

void PnlWdbeFstAStep::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacWdbeFstAStep";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacWdbeFstAStep";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoFnxWidth", TcoFnxWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoCn1Width", TcoCn1Width);
		writeUintAttr(wr, itemtag, "sref", "TcoIp1Width", TcoIp1Width);
		writeUintAttr(wr, itemtag, "sref", "TcoCn2Width", TcoCn2Width);
		writeUintAttr(wr, itemtag, "sref", "TcoIp2Width", TcoIp2Width);
		writeUintAttr(wr, itemtag, "sref", "TcoCn3Width", TcoCn3Width);
		writeUintAttr(wr, itemtag, "sref", "TcoIp3Width", TcoIp3Width);
		writeUintAttr(wr, itemtag, "sref", "TcoCn4Width", TcoCn4Width);
		writeUintAttr(wr, itemtag, "sref", "TcoIp4Width", TcoIp4Width);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeFstAStep::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoFnxWidth == comp->TcoFnxWidth) insert(items, TCOFNXWIDTH);
	if (TcoCn1Width == comp->TcoCn1Width) insert(items, TCOCN1WIDTH);
	if (TcoIp1Width == comp->TcoIp1Width) insert(items, TCOIP1WIDTH);
	if (TcoCn2Width == comp->TcoCn2Width) insert(items, TCOCN2WIDTH);
	if (TcoIp2Width == comp->TcoIp2Width) insert(items, TCOIP2WIDTH);
	if (TcoCn3Width == comp->TcoCn3Width) insert(items, TCOCN3WIDTH);
	if (TcoIp3Width == comp->TcoIp3Width) insert(items, TCOIP3WIDTH);
	if (TcoCn4Width == comp->TcoCn4Width) insert(items, TCOCN4WIDTH);
	if (TcoIp4Width == comp->TcoIp4Width) insert(items, TCOIP4WIDTH);

	return(items);
};

set<uint> PnlWdbeFstAStep::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOFNXWIDTH, TCOCN1WIDTH, TCOIP1WIDTH, TCOCN2WIDTH, TCOIP2WIDTH, TCOCN3WIDTH, TCOIP3WIDTH, TCOCN4WIDTH, TCOIP4WIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeFstAStep::Tag
 ******************************************************************************/

PnlWdbeFstAStep::Tag::Tag(
			const string& Cpt
			, const string& TxtRecord1
			, const string& TxtRecord2
			, const string& Trs
			, const string& TxtShowing1
			, const string& TxtShowing2
			, const string& TcoFnx
			, const string& TcoCn1
			, const string& TcoIp1
			, const string& TcoCn2
			, const string& TcoIp2
			, const string& TcoCn3
			, const string& TcoIp3
			, const string& TcoCn4
			, const string& TcoIp4
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->TxtRecord1 = TxtRecord1;
	this->TxtRecord2 = TxtRecord2;
	this->Trs = Trs;
	this->TxtShowing1 = TxtShowing1;
	this->TxtShowing2 = TxtShowing2;
	this->TcoFnx = TcoFnx;
	this->TcoCn1 = TcoCn1;
	this->TcoIp1 = TcoIp1;
	this->TcoCn2 = TcoCn2;
	this->TcoIp2 = TcoIp2;
	this->TcoCn3 = TcoCn3;
	this->TcoIp3 = TcoIp3;
	this->TcoCn4 = TcoCn4;
	this->TcoIp4 = TcoIp4;

	mask = {CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOFNX, TCOCN1, TCOIP1, TCOCN2, TCOIP2, TCOCN3, TCOIP3, TCOCN4, TCOIP4};
};

bool PnlWdbeFstAStep::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeFstAStep");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeFstAStep";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtRecord1", TxtRecord1)) add(TXTRECORD1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtRecord2", TxtRecord2)) add(TXTRECORD2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Trs", Trs)) add(TRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing1", TxtShowing1)) add(TXTSHOWING1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing2", TxtShowing2)) add(TXTSHOWING2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoFnx", TcoFnx)) add(TCOFNX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoCn1", TcoCn1)) add(TCOCN1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoIp1", TcoIp1)) add(TCOIP1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoCn2", TcoCn2)) add(TCOCN2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoIp2", TcoIp2)) add(TCOIP2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoCn3", TcoCn3)) add(TCOCN3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoIp3", TcoIp3)) add(TCOIP3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoCn4", TcoCn4)) add(TCOCN4);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoIp4", TcoIp4)) add(TCOIP4);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeFstAStep::DpchAppData
 ******************************************************************************/

PnlWdbeFstAStep::DpchAppData::DpchAppData(
			const string& scrJref
			, StgIac* stgiac
			, QryWdbeFstAStep::StgIac* stgiacqry
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEFSTASTEPDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, STGIAC, STGIACQRY};
	else this->mask = mask;

		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
		if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlWdbeFstAStep::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeFstAStep::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeFstAStepData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeFstAStep::DpchAppDo
 ******************************************************************************/

PnlWdbeFstAStep::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEFSTASTEPDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbeFstAStep::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeFstAStep::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeFstAStepDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeFstAStep::DpchEngData
 ******************************************************************************/

PnlWdbeFstAStep::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEFSTASTEPDATA)
		{
	feedFCsiQst.tag = "FeedFCsiQst";
};

string PnlWdbeFstAStep::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFCSIQST)) ss.push_back("feedFCsiQst");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(TAG)) ss.push_back("tag");
	if (has(RST)) ss.push_back("rst");
	if (has(STATAPPQRY)) ss.push_back("statappqry");
	if (has(STATSHRQRY)) ss.push_back("statshrqry");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeFstAStep::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeFstAStepData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFCsiQst.readXML(docctx, basexpath, true)) add(FEEDFCSIQST);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (rst.readXML(docctx, basexpath, true)) add(RST);
		if (statappqry.readXML(docctx, basexpath, true)) add(STATAPPQRY);
		if (statshrqry.readXML(docctx, basexpath, true)) add(STATSHRQRY);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		continf = ContInf();
		feedFCsiQst.clear();
		statapp = StatApp();
		statshr = StatShr();
		stgiac = StgIac();
		tag = Tag();
		rst.clear();
		statappqry = QryWdbeFstAStep::StatApp();
		statshrqry = QryWdbeFstAStep::StatShr();
		stgiacqry = QryWdbeFstAStep::StgIac();
	};
};

