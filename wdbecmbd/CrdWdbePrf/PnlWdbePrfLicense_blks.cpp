/**
	* \file PnlWdbePrfLicense_blks.cpp
	* job handler for job PnlWdbePrfLicense (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 8 Jan 2025
	*/
// IP header --- ABOVE

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

bool PnlWdbePrfLicense::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWdbePrfLicense"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("Txf1")) {Txf1 = me["Txf1"].asString(); add(TXF1);};
		if (me.isMember("Txf2")) {Txf2 = me["Txf2"].asString(); add(TXF2);};
		if (me.isMember("Txf3")) {Txf3 = me["Txf3"].asString(); add(TXF3);};
		if (me.isMember("Txf4")) {Txf4 = me["Txf4"].asString(); add(TXF4);};
		if (me.isMember("Txf5")) {Txf5 = me["Txf5"].asString(); add(TXF5);};
		if (me.isMember("Txf6")) {Txf6 = me["Txf6"].asString(); add(TXF6);};
		if (me.isMember("Txf7")) {Txf7 = me["Txf7"].asString(); add(TXF7);};
		if (me.isMember("Txf8")) {Txf8 = me["Txf8"].asString(); add(TXF8);};
		if (me.isMember("Txf9")) {Txf9 = me["Txf9"].asString(); add(TXF9);};
		if (me.isMember("Txf10")) {Txf10 = me["Txf10"].asString(); add(TXF10);};
	};

	return basefound;
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

void PnlWdbePrfLicense::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbePrfLicense";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["Txf1"] = Txf1;
	me["Txf2"] = Txf2;
	me["Txf3"] = Txf3;
	me["Txf4"] = Txf4;
	me["Txf5"] = Txf5;
	me["Txf6"] = Txf6;
	me["Txf7"] = Txf7;
	me["Txf8"] = Txf8;
	me["Txf9"] = Txf9;
	me["Txf10"] = Txf10;
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

void PnlWdbePrfLicense::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbePrfLicense";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
	me["Txf1Clean"] = Txf1Clean;
	me["Txf2Clean"] = Txf2Clean;
	me["Txf3Clean"] = Txf3Clean;
	me["Txf4Clean"] = Txf4Clean;
	me["Txf5Clean"] = Txf5Clean;
	me["Txf6Clean"] = Txf6Clean;
	me["Txf7Clean"] = Txf7Clean;
	me["Txf8Clean"] = Txf8Clean;
	me["Txf9Clean"] = Txf9Clean;
	me["Txf10Clean"] = Txf10Clean;
};

void PnlWdbePrfLicense::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbePrfLicense";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbePrfLicense";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "Txf1Clean", Txf1Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf2Clean", Txf2Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf3Clean", Txf3Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf4Clean", Txf4Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf5Clean", Txf5Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf6Clean", Txf6Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf7Clean", Txf7Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf8Clean", Txf8Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf9Clean", Txf9Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf10Clean", Txf10Clean);
	xmlTextWriterEndElement(wr);
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

void PnlWdbePrfLicense::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbePrfLicense";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["Cpt"] = "JobWdbeLicense settings";
		me["Cpt1"] = "engip";
		me["Cpt2"] = "engport";
		me["Cpt3"] = "username";
		me["Cpt4"] = "password";
		me["Cpt5"] = "licenseBase";
		me["Cpt6"] = "licenseFull";
		me["Cpt7"] = "licenseTpl";
		me["Cpt8"] = "lastAttempt";
		me["Cpt9"] = "lastSuccess";
		me["Cpt10"] = "lastSync";
	};
};

void PnlWdbePrfLicense::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbePrfLicense";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbePrfLicense";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "JobWdbeLicense settings");
			writeStringAttr(wr, itemtag, "sref", "Cpt1", "engip");
			writeStringAttr(wr, itemtag, "sref", "Cpt2", "engport");
			writeStringAttr(wr, itemtag, "sref", "Cpt3", "username");
			writeStringAttr(wr, itemtag, "sref", "Cpt4", "password");
			writeStringAttr(wr, itemtag, "sref", "Cpt5", "licenseBase");
			writeStringAttr(wr, itemtag, "sref", "Cpt6", "licenseFull");
			writeStringAttr(wr, itemtag, "sref", "Cpt7", "licenseTpl");
			writeStringAttr(wr, itemtag, "sref", "Cpt8", "lastAttempt");
			writeStringAttr(wr, itemtag, "sref", "Cpt9", "lastSuccess");
			writeStringAttr(wr, itemtag, "sref", "Cpt10", "lastSync");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePrfLicense::DpchAppData
 ******************************************************************************/

PnlWdbePrfLicense::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPRFLICENSEDATA)
		{
};

string PnlWdbePrfLicense::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrfLicense::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbePrfLicenseData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWdbePrfLicense::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbePrfLicenseData");
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
 class PnlWdbePrfLicense::DpchAppDo
 ******************************************************************************/

PnlWdbePrfLicense::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPRFLICENSEDO)
		{
	ixVDo = 0;
};

string PnlWdbePrfLicense::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrfLicense::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbePrfLicenseDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWdbePrfLicense::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbePrfLicenseDo");
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
 class PnlWdbePrfLicense::DpchEngData
 ******************************************************************************/

PnlWdbePrfLicense::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEPRFLICENSEDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbePrfLicense::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrfLicense::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbePrfLicense::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbePrfLicenseData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void PnlWdbePrfLicense::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbePrfLicenseData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
