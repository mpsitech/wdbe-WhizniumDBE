/**
	* \file PnlWdbeNavDeploy_blks.cpp
	* job handler for job PnlWdbeNavDeploy (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeNavDeploy::VecVDo
 ******************************************************************************/

uint PnlWdbeNavDeploy::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butcmpviewclick") return BUTCMPVIEWCLICK;
	if (s == "butcmpnewcrdclick") return BUTCMPNEWCRDCLICK;
	if (s == "butrlsviewclick") return BUTRLSVIEWCLICK;
	if (s == "butrlsnewcrdclick") return BUTRLSNEWCRDCLICK;

	return(0);
};

string PnlWdbeNavDeploy::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTCMPVIEWCLICK) return("ButCmpViewClick");
	if (ix == BUTCMPNEWCRDCLICK) return("ButCmpNewcrdClick");
	if (ix == BUTRLSVIEWCLICK) return("ButRlsViewClick");
	if (ix == BUTRLSNEWCRDCLICK) return("ButRlsNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWdbeNavDeploy::ContIac
 ******************************************************************************/

PnlWdbeNavDeploy::ContIac::ContIac(
			const uint numFLstCmp
			, const uint numFLstRls
		) :
			Block()
		{
	this->numFLstCmp = numFLstCmp;
	this->numFLstRls = numFLstRls;

	mask = {NUMFLSTCMP, NUMFLSTRLS};
};

bool PnlWdbeNavDeploy::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWdbeNavDeploy"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFLstCmp")) {numFLstCmp = me["numFLstCmp"].asUInt(); add(NUMFLSTCMP);};
		if (me.isMember("numFLstRls")) {numFLstRls = me["numFLstRls"].asUInt(); add(NUMFLSTRLS);};
	};

	return basefound;
};

bool PnlWdbeNavDeploy::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeNavDeploy");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeNavDeploy";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCmp", numFLstCmp)) add(NUMFLSTCMP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstRls", numFLstRls)) add(NUMFLSTRLS);
	};

	return basefound;
};

void PnlWdbeNavDeploy::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeNavDeploy";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFLstCmp"] = (Json::Value::UInt) numFLstCmp;
	me["numFLstRls"] = (Json::Value::UInt) numFLstRls;
};

void PnlWdbeNavDeploy::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeNavDeploy";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeNavDeploy";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstCmp", numFLstCmp);
		writeUintAttr(wr, itemtag, "sref", "numFLstRls", numFLstRls);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavDeploy::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstCmp == comp->numFLstCmp) insert(items, NUMFLSTCMP);
	if (numFLstRls == comp->numFLstRls) insert(items, NUMFLSTRLS);

	return(items);
};

set<uint> PnlWdbeNavDeploy::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTCMP, NUMFLSTRLS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavDeploy::StatApp
 ******************************************************************************/

void PnlWdbeNavDeploy::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWdbeVExpstate
			, const bool LstCmpAlt
			, const bool LstRlsAlt
			, const uint LstCmpNumFirstdisp
			, const uint LstRlsNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeNavDeploy";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
	me["LstCmpAlt"] = LstCmpAlt;
	me["LstRlsAlt"] = LstRlsAlt;
	me["LstCmpNumFirstdisp"] = (Json::Value::UInt) LstCmpNumFirstdisp;
	me["LstRlsNumFirstdisp"] = (Json::Value::UInt) LstRlsNumFirstdisp;
};

void PnlWdbeNavDeploy::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
			, const bool LstCmpAlt
			, const bool LstRlsAlt
			, const uint LstCmpNumFirstdisp
			, const uint LstRlsNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeNavDeploy";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeNavDeploy";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstCmpAlt", LstCmpAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstRlsAlt", LstRlsAlt);
		writeUintAttr(wr, itemtag, "sref", "LstCmpNumFirstdisp", LstCmpNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstRlsNumFirstdisp", LstRlsNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavDeploy::StatShr
 ******************************************************************************/

PnlWdbeNavDeploy::StatShr::StatShr(
			const bool LstCmpAvail
			, const bool ButCmpViewActive
			, const bool LstRlsAvail
			, const bool ButRlsViewActive
			, const bool ButRlsNewcrdActive
		) :
			Block()
		{
	this->LstCmpAvail = LstCmpAvail;
	this->ButCmpViewActive = ButCmpViewActive;
	this->LstRlsAvail = LstRlsAvail;
	this->ButRlsViewActive = ButRlsViewActive;
	this->ButRlsNewcrdActive = ButRlsNewcrdActive;

	mask = {LSTCMPAVAIL, BUTCMPVIEWACTIVE, LSTRLSAVAIL, BUTRLSVIEWACTIVE, BUTRLSNEWCRDACTIVE};
};

void PnlWdbeNavDeploy::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeNavDeploy";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["LstCmpAvail"] = LstCmpAvail;
	me["ButCmpViewActive"] = ButCmpViewActive;
	me["LstRlsAvail"] = LstRlsAvail;
	me["ButRlsViewActive"] = ButRlsViewActive;
	me["ButRlsNewcrdActive"] = ButRlsNewcrdActive;
};

void PnlWdbeNavDeploy::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeNavDeploy";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeNavDeploy";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstCmpAvail", LstCmpAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCmpViewActive", ButCmpViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstRlsAvail", LstRlsAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRlsViewActive", ButRlsViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButRlsNewcrdActive", ButRlsNewcrdActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavDeploy::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstCmpAvail == comp->LstCmpAvail) insert(items, LSTCMPAVAIL);
	if (ButCmpViewActive == comp->ButCmpViewActive) insert(items, BUTCMPVIEWACTIVE);
	if (LstRlsAvail == comp->LstRlsAvail) insert(items, LSTRLSAVAIL);
	if (ButRlsViewActive == comp->ButRlsViewActive) insert(items, BUTRLSVIEWACTIVE);
	if (ButRlsNewcrdActive == comp->ButRlsNewcrdActive) insert(items, BUTRLSNEWCRDACTIVE);

	return(items);
};

set<uint> PnlWdbeNavDeploy::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTCMPAVAIL, BUTCMPVIEWACTIVE, LSTRLSAVAIL, BUTRLSVIEWACTIVE, BUTRLSNEWCRDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavDeploy::Tag
 ******************************************************************************/

void PnlWdbeNavDeploy::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbeNavDeploy";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["Cpt"] = "Deployment module";
		me["CptCmp"] = "components";
		me["CptRls"] = "releases";
	};
};

void PnlWdbeNavDeploy::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeNavDeploy";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeNavDeploy";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Deployment module");
			writeStringAttr(wr, itemtag, "sref", "CptCmp", "components");
			writeStringAttr(wr, itemtag, "sref", "CptRls", "releases");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavDeploy::DpchAppData
 ******************************************************************************/

PnlWdbeNavDeploy::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVDEPLOYDATA)
		{
};

string PnlWdbeNavDeploy::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavDeploy::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeNavDeployData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWdbeNavDeploy::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeNavDeployData");
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
 class PnlWdbeNavDeploy::DpchAppDo
 ******************************************************************************/

PnlWdbeNavDeploy::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVDEPLOYDO)
		{
	ixVDo = 0;
};

string PnlWdbeNavDeploy::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavDeploy::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeNavDeployDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWdbeNavDeploy::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeNavDeployDo");
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
 class PnlWdbeNavDeploy::DpchEngData
 ******************************************************************************/

PnlWdbeNavDeploy::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstCmp
			, Feed* feedFLstRls
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBENAVDEPLOYDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTCMP, FEEDFLSTRLS, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTCMP) && feedFLstCmp) this->feedFLstCmp = *feedFLstCmp;
	if (find(this->mask, FEEDFLSTRLS) && feedFLstRls) this->feedFLstRls = *feedFLstRls;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeNavDeploy::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTCMP)) ss.push_back("feedFLstCmp");
	if (has(FEEDFLSTRLS)) ss.push_back("feedFLstRls");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavDeploy::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTCMP)) {feedFLstCmp = src->feedFLstCmp; add(FEEDFLSTCMP);};
	if (src->has(FEEDFLSTRLS)) {feedFLstRls = src->feedFLstRls; add(FEEDFLSTRLS);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeNavDeploy::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbeNavDeployData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(FEEDFLSTCMP)) feedFLstCmp.writeJSON(me);
	if (has(FEEDFLSTRLS)) feedFLstRls.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void PnlWdbeNavDeploy::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeNavDeployData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTCMP)) feedFLstCmp.writeXML(wr);
		if (has(FEEDFLSTRLS)) feedFLstRls.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
