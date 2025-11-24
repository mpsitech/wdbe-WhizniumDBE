/**
	* \file Wdbecmbd.cpp
	* inter-thread exchange object for Wdbe combined daemon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "Wdbecmbd.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchAppWdbe
 ******************************************************************************/

DpchAppWdbe::DpchAppWdbe(
			const uint ixWdbeVDpch
		) :
			DpchWdbe(ixWdbeVDpch)
		{
	jref = 0;
};

DpchAppWdbe::~DpchAppWdbe() {
};

bool DpchAppWdbe::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;

	return true;
};

string DpchAppWdbe::getSrefsMask() {
	if (has(JREF)) return("jref");
	else return("");
};

void DpchAppWdbe::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup[VecWdbeVDpch::getSref(ixWdbeVDpch)];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {
			jref = Scr::descramble(me["scrJref"].asString());
			add(JREF);
		};
	};
};

void DpchAppWdbe::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	string scrJref;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, VecWdbeVDpch::getSref(ixWdbeVDpch));
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
	};
};

/******************************************************************************
 class DpchAppWdbeAlert
 ******************************************************************************/

DpchAppWdbeAlert::DpchAppWdbeAlert() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEALERT)
		{
};

bool DpchAppWdbeAlert::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;
	if (!find(items, NUMFMCB)) return false;

	return true;
};

string DpchAppWdbeAlert::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(NUMFMCB)) ss.push_back("numFMcb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchAppWdbeAlert::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeAlert"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {
			jref = Scr::descramble(me["scrJref"].asString());
			add(JREF);
		};
		if (me.isMember("numFMcb")) {numFMcb = me["numFMcb"].asInt(); add(NUMFMCB);};
	};
};

void DpchAppWdbeAlert::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeAlert");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractUintUclc(docctx, basexpath, "numFMcb", "", numFMcb)) add(NUMFMCB);
	} else {
	};
};

/******************************************************************************
 class DpchAppWdbeInit
 ******************************************************************************/

DpchAppWdbeInit::DpchAppWdbeInit() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEINIT)
		{
};

/******************************************************************************
 class DpchAppWdbeResume
 ******************************************************************************/

DpchAppWdbeResume::DpchAppWdbeResume() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBERESUME)
		{
};

/******************************************************************************
 class DpchEngWdbe
 ******************************************************************************/

DpchEngWdbe::DpchEngWdbe(
			const uint ixWdbeVDpch
			, const ubigint jref
		) :
			DpchWdbe(ixWdbeVDpch)
			, jref(jref)
		{
	mask = {JREF};
};

DpchEngWdbe::~DpchEngWdbe() {
};

bool DpchEngWdbe::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;

	return true;
};

string DpchEngWdbe::getSrefsMask() {
	if (has(JREF)) return("jref");
	else return("");
};

void DpchEngWdbe::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngWdbe* src = dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
};

void DpchEngWdbe::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup[VecWdbeVDpch::getSref(ixWdbeVDpch)] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
};

void DpchEngWdbe::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	string tag = VecWdbeVDpch::getSref(ixWdbeVDpch);

	xmlTextWriterStartElement(wr, BAD_CAST tag.c_str());
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngWdbeAck
 ******************************************************************************/

DpchEngWdbeAck::DpchEngWdbeAck(
			const ubigint jref
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEACK, jref)
		{
};

/******************************************************************************
 class DpchEngWdbeAlert
 ******************************************************************************/

DpchEngWdbeAlert::DpchEngWdbeAlert(
			const ubigint jref
			, ContInfWdbeAlert* continf
			, Feed* feedFMcb
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEALERT, jref)
		{
	if (continf) this->continf = *continf;
	if (feedFMcb) this->feedFMcb = *feedFMcb;

	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFMCB};
	else this->mask = mask;
};

bool DpchEngWdbeAlert::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;
	if (!find(items, CONTINF)) return false;
	if (!find(items, FEEDFMCB)) return false;

	return true;
};

string DpchEngWdbeAlert::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFMCB)) ss.push_back("feedFMcb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchEngWdbeAlert::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngWdbeAlert* src = (DpchEngWdbeAlert*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFMCB)) {feedFMcb = src->feedFMcb; add(FEEDFMCB);};
};

void DpchEngWdbeAlert::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbeAlert"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFMCB)) feedFMcb.writeJSON(me);
};

void DpchEngWdbeAlert::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeAlert");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFMCB)) feedFMcb.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngWdbeConfirm
 ******************************************************************************/

DpchEngWdbeConfirm::DpchEngWdbeConfirm(
			const bool accepted
			, const ubigint jref
			, const string& sref
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBECONFIRM, jref)
			, accepted(accepted)
			, sref(sref)
		{
	if (find(mask, ALL)) this->mask = {ACCEPTED, JREF, SREF};
	else this->mask = mask;
};

bool DpchEngWdbeConfirm::all(
			const set<uint>& items
		) {
	if (!find(items, ACCEPTED)) return false;
	if (!find(items, JREF)) return false;
	if (!find(items, SREF)) return false;

	return true;
};

string DpchEngWdbeConfirm::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(ACCEPTED)) ss.push_back("accepted");
	if (has(JREF)) ss.push_back("jref");
	if (has(SREF)) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchEngWdbeConfirm::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngWdbeConfirm* src = (DpchEngWdbeConfirm*) dpcheng;

	if (src->has(ACCEPTED)) {accepted = src->accepted; add(ACCEPTED);};
	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(SREF)) {sref = src->sref; add(SREF);};
};

void DpchEngWdbeConfirm::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbeConfirm"] = Json::Value(Json::objectValue);

	if (has(ACCEPTED)) me["accepted"] = accepted;
	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(SREF)) me["sref"] = sref;
};

void DpchEngWdbeConfirm::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeConfirm");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(ACCEPTED)) writeBool(wr, "accepted", accepted);
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(SREF)) writeString(wr, "sref", sref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngWdbeSuspend
 ******************************************************************************/

DpchEngWdbeSuspend::DpchEngWdbeSuspend(
			const ubigint jref
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBESUSPEND, jref)
		{
};

/******************************************************************************
 class StgWdbeAppsrv
 ******************************************************************************/

StgWdbeAppsrv::StgWdbeAppsrv(
			const usmallint port
			, const bool https
			, const string& cors
		) :
			Block()
			, port(port)
			, https(https)
			, cors(cors)
		{
	mask = {PORT, HTTPS, CORS};
};

bool StgWdbeAppsrv::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWdbeAppsrv");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWdbeAppsrv";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "https", https)) add(HTTPS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "cors", cors)) add(CORS);
	};

	return basefound;
};

void StgWdbeAppsrv::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWdbeAppsrv";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWdbeAppsrv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
		writeBoolAttr(wr, itemtag, "sref", "https", https);
		writeStringAttr(wr, itemtag, "sref", "cors", cors);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWdbeAppsrv::comm(
			const StgWdbeAppsrv* comp
		) {
	set<uint> items;

	if (port == comp->port) insert(items, PORT);
	if (https == comp->https) insert(items, HTTPS);
	if (cors == comp->cors) insert(items, CORS);

	return(items);
};

set<uint> StgWdbeAppsrv::diff(
			const StgWdbeAppsrv* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {PORT, HTTPS, CORS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWdbeBehavior
 ******************************************************************************/

StgWdbeBehavior::StgWdbeBehavior(
			const usmallint histlength
			, const bool suspsess
			, const uint sesstterm
			, const uint sesstwarn
			, const uint roottterm
		) :
			Block()
			, histlength(histlength)
			, suspsess(suspsess)
			, sesstterm(sesstterm)
			, sesstwarn(sesstwarn)
			, roottterm(roottterm)
		{
	mask = {HISTLENGTH, SUSPSESS, SESSTTERM, SESSTWARN, ROOTTTERM};
};

bool StgWdbeBehavior::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWdbeBehavior");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWdbeBehavior";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "histlength", histlength)) add(HISTLENGTH);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "suspsess", suspsess)) add(SUSPSESS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "sesstterm", sesstterm)) add(SESSTTERM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "sesstwarn", sesstwarn)) add(SESSTWARN);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "roottterm", roottterm)) add(ROOTTTERM);
	};

	return basefound;
};

void StgWdbeBehavior::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWdbeBehavior";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWdbeBehavior";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "histlength", histlength);
		writeBoolAttr(wr, itemtag, "sref", "suspsess", suspsess);
		writeUintAttr(wr, itemtag, "sref", "sesstterm", sesstterm);
		writeUintAttr(wr, itemtag, "sref", "sesstwarn", sesstwarn);
		writeUintAttr(wr, itemtag, "sref", "roottterm", roottterm);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWdbeBehavior::comm(
			const StgWdbeBehavior* comp
		) {
	set<uint> items;

	if (histlength == comp->histlength) insert(items, HISTLENGTH);
	if (suspsess == comp->suspsess) insert(items, SUSPSESS);
	if (sesstterm == comp->sesstterm) insert(items, SESSTTERM);
	if (sesstwarn == comp->sesstwarn) insert(items, SESSTWARN);
	if (roottterm == comp->roottterm) insert(items, ROOTTTERM);

	return(items);
};

set<uint> StgWdbeBehavior::diff(
			const StgWdbeBehavior* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {HISTLENGTH, SUSPSESS, SESSTTERM, SESSTWARN, ROOTTTERM};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWdbecmbd
 ******************************************************************************/

StgWdbecmbd::StgWdbecmbd(
			const usmallint jobprcn
			, const usmallint opprcn
			, const bool appsrv
		) :
			Block()
			, jobprcn(jobprcn)
			, opprcn(opprcn)
			, appsrv(appsrv)
		{
	mask = {JOBPRCN, OPPRCN, APPSRV};
};

bool StgWdbecmbd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWdbecmbd");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWdbecmbd";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jobprcn", jobprcn)) add(JOBPRCN);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "opprcn", opprcn)) add(OPPRCN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "appsrv", appsrv)) add(APPSRV);
	};

	return basefound;
};

void StgWdbecmbd::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWdbecmbd";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWdbecmbd";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "jobprcn", jobprcn);
		writeUsmallintAttr(wr, itemtag, "sref", "opprcn", opprcn);
		writeBoolAttr(wr, itemtag, "sref", "appsrv", appsrv);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWdbecmbd::comm(
			const StgWdbecmbd* comp
		) {
	set<uint> items;

	if (jobprcn == comp->jobprcn) insert(items, JOBPRCN);
	if (opprcn == comp->opprcn) insert(items, OPPRCN);
	if (appsrv == comp->appsrv) insert(items, APPSRV);

	return(items);
};

set<uint> StgWdbecmbd::diff(
			const StgWdbecmbd* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JOBPRCN, OPPRCN, APPSRV};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWdbeDatabase
 ******************************************************************************/

StgWdbeDatabase::StgWdbeDatabase(
			const uint ixDbsVDbstype
			, const string& dbspath
			, const string& dbsname
			, const string& username
			, const string& password
			, const string& ip
			, const usmallint port
		) :
			Block()
			, ixDbsVDbstype(ixDbsVDbstype)
			, dbspath(dbspath)
			, dbsname(dbsname)
			, username(username)
			, password(password)
			, ip(ip)
			, port(port)
		{
	mask = {IXDBSVDBSTYPE, DBSPATH, DBSNAME, USERNAME, PASSWORD, IP, PORT};
};

bool StgWdbeDatabase::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxDbsVDbstype;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWdbeDatabase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWdbeDatabase";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxDbsVDbstype", srefIxDbsVDbstype)) {
			ixDbsVDbstype = VecDbsVDbstype::getIx(srefIxDbsVDbstype);
			add(IXDBSVDBSTYPE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbspath", dbspath)) add(DBSPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbsname", dbsname)) add(DBSNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ip", ip)) add(IP);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
	};

	return basefound;
};

void StgWdbeDatabase::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWdbeDatabase";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWdbeDatabase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxDbsVDbstype", VecDbsVDbstype::getSref(ixDbsVDbstype));
		writeStringAttr(wr, itemtag, "sref", "dbspath", dbspath);
		writeStringAttr(wr, itemtag, "sref", "dbsname", dbsname);
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
		writeStringAttr(wr, itemtag, "sref", "ip", ip);
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWdbeDatabase::comm(
			const StgWdbeDatabase* comp
		) {
	set<uint> items;

	if (ixDbsVDbstype == comp->ixDbsVDbstype) insert(items, IXDBSVDBSTYPE);
	if (dbspath == comp->dbspath) insert(items, DBSPATH);
	if (dbsname == comp->dbsname) insert(items, DBSNAME);
	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);
	if (ip == comp->ip) insert(items, IP);
	if (port == comp->port) insert(items, PORT);

	return(items);
};

set<uint> StgWdbeDatabase::diff(
			const StgWdbeDatabase* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXDBSVDBSTYPE, DBSPATH, DBSNAME, USERNAME, PASSWORD, IP, PORT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWdbeMonitor
 ******************************************************************************/

StgWdbeMonitor::StgWdbeMonitor(
			const string& username
			, const string& password
			, const string& ip
			, const usmallint port
			, const uint ixDbsVDbstype
			, const string& dbspath
			, const string& dbsname
			, const string& dbsusername
			, const string& dbspassword
		) :
			Block()
			, username(username)
			, password(password)
			, ip(ip)
			, port(port)
			, ixDbsVDbstype(ixDbsVDbstype)
			, dbspath(dbspath)
			, dbsname(dbsname)
			, dbsusername(dbsusername)
			, dbspassword(dbspassword)
		{
	mask = {USERNAME, PASSWORD, IP, PORT, IXDBSVDBSTYPE, DBSPATH, DBSNAME, DBSUSERNAME, DBSPASSWORD};
};

bool StgWdbeMonitor::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxDbsVDbstype;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWdbeMonitor");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWdbeMonitor";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ip", ip)) add(IP);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxDbsVDbstype", srefIxDbsVDbstype)) {
			ixDbsVDbstype = VecDbsVDbstype::getIx(srefIxDbsVDbstype);
			add(IXDBSVDBSTYPE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbspath", dbspath)) add(DBSPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbsname", dbsname)) add(DBSNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbsusername", dbsusername)) add(DBSUSERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbspassword", dbspassword)) add(DBSPASSWORD);
	};

	return basefound;
};

void StgWdbeMonitor::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWdbeMonitor";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWdbeMonitor";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
		writeStringAttr(wr, itemtag, "sref", "ip", ip);
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
		writeStringAttr(wr, itemtag, "sref", "srefIxDbsVDbstype", VecDbsVDbstype::getSref(ixDbsVDbstype));
		writeStringAttr(wr, itemtag, "sref", "dbspath", dbspath);
		writeStringAttr(wr, itemtag, "sref", "dbsname", dbsname);
		writeStringAttr(wr, itemtag, "sref", "dbsusername", dbsusername);
		writeStringAttr(wr, itemtag, "sref", "dbspassword", dbspassword);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWdbeMonitor::comm(
			const StgWdbeMonitor* comp
		) {
	set<uint> items;

	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);
	if (ip == comp->ip) insert(items, IP);
	if (port == comp->port) insert(items, PORT);
	if (ixDbsVDbstype == comp->ixDbsVDbstype) insert(items, IXDBSVDBSTYPE);
	if (dbspath == comp->dbspath) insert(items, DBSPATH);
	if (dbsname == comp->dbsname) insert(items, DBSNAME);
	if (dbsusername == comp->dbsusername) insert(items, DBSUSERNAME);
	if (dbspassword == comp->dbspassword) insert(items, DBSPASSWORD);

	return(items);
};

set<uint> StgWdbeMonitor::diff(
			const StgWdbeMonitor* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {USERNAME, PASSWORD, IP, PORT, IXDBSVDBSTYPE, DBSPATH, DBSNAME, DBSUSERNAME, DBSPASSWORD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWdbePath
 ******************************************************************************/

StgWdbePath::StgWdbePath(
			const string& acvpath
			, const string& keypath
			, const string& monpath
			, const string& tmppath
			, const string& webpath
			, const string& helpurl
		) :
			Block()
			, acvpath(acvpath)
			, keypath(keypath)
			, monpath(monpath)
			, tmppath(tmppath)
			, webpath(webpath)
			, helpurl(helpurl)
		{
	mask = {ACVPATH, KEYPATH, MONPATH, TMPPATH, WEBPATH, HELPURL};
};

bool StgWdbePath::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWdbePath");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWdbePath";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "acvpath", acvpath)) add(ACVPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "keypath", keypath)) add(KEYPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "monpath", monpath)) add(MONPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "tmppath", tmppath)) add(TMPPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "webpath", webpath)) add(WEBPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "helpurl", helpurl)) add(HELPURL);
	};

	return basefound;
};

void StgWdbePath::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWdbePath";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWdbePath";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "acvpath", acvpath);
		writeStringAttr(wr, itemtag, "sref", "keypath", keypath);
		writeStringAttr(wr, itemtag, "sref", "monpath", monpath);
		writeStringAttr(wr, itemtag, "sref", "tmppath", tmppath);
		writeStringAttr(wr, itemtag, "sref", "webpath", webpath);
		writeStringAttr(wr, itemtag, "sref", "helpurl", helpurl);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWdbePath::comm(
			const StgWdbePath* comp
		) {
	set<uint> items;

	if (acvpath == comp->acvpath) insert(items, ACVPATH);
	if (keypath == comp->keypath) insert(items, KEYPATH);
	if (monpath == comp->monpath) insert(items, MONPATH);
	if (tmppath == comp->tmppath) insert(items, TMPPATH);
	if (webpath == comp->webpath) insert(items, WEBPATH);
	if (helpurl == comp->helpurl) insert(items, HELPURL);

	return(items);
};

set<uint> StgWdbePath::diff(
			const StgWdbePath* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ACVPATH, KEYPATH, MONPATH, TMPPATH, WEBPATH, HELPURL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWdbeTenant
 ******************************************************************************/

StgWdbeTenant::StgWdbeTenant(
			const string& orgname
			, const string& orgweb
		) :
			Block()
			, orgname(orgname)
			, orgweb(orgweb)
		{
	mask = {ORGNAME, ORGWEB};
};

bool StgWdbeTenant::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWdbeTenant");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWdbeTenant";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "orgname", orgname)) add(ORGNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "orgweb", orgweb)) add(ORGWEB);
	};

	return basefound;
};

void StgWdbeTenant::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWdbeTenant";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWdbeTenant";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "orgname", orgname);
		writeStringAttr(wr, itemtag, "sref", "orgweb", orgweb);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWdbeTenant::comm(
			const StgWdbeTenant* comp
		) {
	set<uint> items;

	if (orgname == comp->orgname) insert(items, ORGNAME);
	if (orgweb == comp->orgweb) insert(items, ORGWEB);

	return(items);
};

set<uint> StgWdbeTenant::diff(
			const StgWdbeTenant* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ORGNAME, ORGWEB};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 namespace AlrWdbe
 ******************************************************************************/

DpchEngWdbeAlert* AlrWdbe::prepareAlrAbt(
			const ubigint jref
			, const uint ixWdbeVLocale
			, Feed& feedFMcbAlert
		) {
	ContInfWdbeAlert continf;
	// IP prepareAlrAbt --- BEGIN
	continf.TxtCpt = VecWdbeVTag::getTitle(VecWdbeVTag::ABOUT, ixWdbeVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		continf.TxtMsg1 = "WhizniumDBE version v1.1.50 released on 23-11-2025";
		continf.TxtMsg2 = "\\u00a9 MPSI Technologies GmbH";
		continf.TxtMsg4 = "contributors: Alexander Wirthmueller";
		continf.TxtMsg6 = "libraries: apiwzlm 1.0.0, curl 7.65, git2 0.24.0, jsoncpp 1.8.4 and openssl 1.1.1";
		continf.TxtMsg8 = "WhizniumDBE implements all functionality of the Whiznium Device Builder's Edition framework for automated code generation and iteration.";
	};

	feedFMcbAlert.clear();

	VecWdbeVTag::appendToFeed(VecWdbeVTag::CLOSE, ixWdbeVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrAbt --- END
	return(new DpchEngWdbeAlert(jref, &continf, &feedFMcbAlert, {DpchEngWdbeAlert::ALL}));
};

DpchEngWdbeAlert* AlrWdbe::prepareAlrIer(
			const ubigint jref
			, const uint ixWdbeVLocale
			, const string& iexsqk
			, Feed& feedFMcbAlert
		) {
	ContInfWdbeAlert continf;
	// IP prepareAlrIer --- BEGIN
	continf.TxtCpt = VecWdbeVTag::getTitle(VecWdbeVTag::IMPERR, ixWdbeVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		continf.TxtMsg1 = "" + iexsqk + "";
	};

	feedFMcbAlert.clear();

	VecWdbeVTag::appendToFeed(VecWdbeVTag::CANCEL, ixWdbeVLocale, feedFMcbAlert);
	VecWdbeVTag::appendToFeed(VecWdbeVTag::REVERSE, ixWdbeVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrIer --- END
	return(new DpchEngWdbeAlert(jref, &continf, &feedFMcbAlert, {DpchEngWdbeAlert::ALL}));
};

DpchEngWdbeAlert* AlrWdbe::prepareAlrPer(
			const ubigint jref
			, const uint ixWdbeVLocale
			, const string& iexsqk
			, Feed& feedFMcbAlert
		) {
	ContInfWdbeAlert continf;
	// IP prepareAlrPer --- BEGIN
	continf.TxtCpt = VecWdbeVTag::getTitle(VecWdbeVTag::PRSERR, ixWdbeVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		continf.TxtMsg1 = "" + iexsqk + "";
	};

	feedFMcbAlert.clear();

	VecWdbeVTag::appendToFeed(VecWdbeVTag::OK, ixWdbeVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrPer --- END
	return(new DpchEngWdbeAlert(jref, &continf, &feedFMcbAlert, {DpchEngWdbeAlert::ALL}));
};

DpchEngWdbeAlert* AlrWdbe::prepareAlrSav(
			const ubigint jref
			, const uint ixWdbeVLocale
			, Feed& feedFMcbAlert
		) {
	ContInfWdbeAlert continf;
	// IP prepareAlrSav --- BEGIN
	continf.TxtCpt = VecWdbeVTag::getTitle(VecWdbeVTag::QUEST, ixWdbeVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		continf.TxtMsg1 = "Save changes?";
	};

	feedFMcbAlert.clear();

	VecWdbeVTag::appendToFeed(VecWdbeVTag::CANCEL, ixWdbeVLocale, feedFMcbAlert);
	VecWdbeVTag::appendToFeed(VecWdbeVTag::FLS, ixWdbeVLocale, feedFMcbAlert);
	VecWdbeVTag::appendToFeed(VecWdbeVTag::TRU, ixWdbeVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrSav --- END
	return(new DpchEngWdbeAlert(jref, &continf, &feedFMcbAlert, {DpchEngWdbeAlert::ALL}));
};

DpchEngWdbeAlert* AlrWdbe::prepareAlrTrm(
			const ubigint jref
			, const uint ixWdbeVLocale
			, const uint sesstterm
			, const uint sesstwarn
			, Feed& feedFMcbAlert
		) {
	ContInfWdbeAlert continf;
	// IP prepareAlrTrm --- BEGIN
	continf.TxtCpt = VecWdbeVTag::getTitle(VecWdbeVTag::ANNOUNCE, ixWdbeVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		continf.TxtMsg1 = "Your session has been inactive for " + prepareAlrTrm_dtToString(ixWdbeVLocale, sesstterm) + ". It will be terminated in " + prepareAlrTrm_dtToString(ixWdbeVLocale, sesstwarn) + ".";
	};

	feedFMcbAlert.clear();

	VecWdbeVTag::appendToFeed(VecWdbeVTag::OK, ixWdbeVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrTrm --- END
	return(new DpchEngWdbeAlert(jref, &continf, &feedFMcbAlert, {DpchEngWdbeAlert::ALL}));
};

string AlrWdbe::prepareAlrTrm_dtToString(
			const uint ixWdbeVLocale
			, const time_t dt
		) {
	string s;

	if ((dt%3600) == 0) {
		s = to_string(dt/3600);

		if (dt == 3600) s += " " + VecWdbeVTag::getTitle(VecWdbeVTag::HOUR, ixWdbeVLocale);
		else s += " " + VecWdbeVTag::getTitle(VecWdbeVTag::HOURS, ixWdbeVLocale);

	} else if ((dt%60) == 0) {
		s = to_string(dt/60);

		if (dt == 60) s += " " + VecWdbeVTag::getTitle(VecWdbeVTag::MINUTE, ixWdbeVLocale);
		else s += " " + VecWdbeVTag::getTitle(VecWdbeVTag::MINUTES, ixWdbeVLocale);

	} else {
		s = to_string(dt);

		if (dt == 1) s += " " + VecWdbeVTag::getTitle(VecWdbeVTag::SECOND, ixWdbeVLocale);
		else s += " " + VecWdbeVTag::getTitle(VecWdbeVTag::SECONDS, ixWdbeVLocale);
	};

	return s;
};

/******************************************************************************
 class ReqWdbe
 ******************************************************************************/

ReqWdbe::ReqWdbe(
			const uint ixVBasetype
			, const uint ixVState
			, const string& ip
		) :
			ixVBasetype(ixVBasetype)
			, ixVState(ixVState)
			, ip(ip)
			, cReady("cReady", "ReqWdbe", "ReqWdbe")
		{
	pp = NULL;

	retain = !((ixVBasetype == VecVBasetype::CMD) || (ixVBasetype == VecVBasetype::DPCHAPP) || (ixVBasetype == VecVBasetype::NOTIFY)
					|| (ixVBasetype == VecVBasetype::UPLOAD) || (ixVBasetype == VecVBasetype::DOWNLOAD) || (ixVBasetype == VecVBasetype::METHOD));

	file = NULL;
	filelen = 0;

	request = NULL;
	requestlen = 0;

	jsonNotXml = false;

	jref = 0;

	wref = 0;

	call = NULL;

	weak = false;

	dpchapp = NULL;

	dpcheng = NULL;
	ixWdbeVLocale = VecWdbeVLocale::ENUS;

	dpchinv = NULL;
	dpchret = NULL;

	reply = NULL;
	replylen = 0;

	method = NULL;
};

ReqWdbe::~ReqWdbe() {
	if (pp) MHD_destroy_post_processor(pp);

	if (file) {
		if (file->is_open()) file->close();
		delete file;
	};

	if (call) delete call;

	if (request) delete[] request;

	if (dpchapp) delete dpchapp;

	if (dpcheng) delete dpcheng;

	if (dpchinv) delete dpchinv;
	if (dpchret) delete dpchret;

	if (reply) delete[] reply;

	if (method) delete method;
};

void ReqWdbe::setStateReply() {
	cReady.lockMutex("ReqWdbe", "setStateReply", "jref=" + to_string(jref));
	ixVState = VecVState::REPLY;
	cReady.unlockMutex("ReqWdbe", "setStateReply", "jref=" + to_string(jref));

	cReady.signal("ReqWdbe", "setStateReply", "jref=" + to_string(jref));
};

/******************************************************************************
 class DcolWdbe
 ******************************************************************************/

DcolWdbe::DcolWdbe(
			const ubigint jref
			, const uint ixWdbeVLocale
		) :
			jref(jref)
			, ixWdbeVLocale(ixWdbeVLocale)
			, mAccess("dcol.mAccess", "DcolWdbe", "DcolWdbe", "jref=" + to_string(jref))
		{
	hot = false;

	req = NULL;
};

DcolWdbe::~DcolWdbe() {
	for (auto it = dpchs.begin(); it != dpchs.end(); it++) delete(*it);

	if (req) req->cReady.signal("DcolWdbe", "~DcolWdbe", "jref=" + to_string(jref));

	mAccess.lock("DcolWdbe", "~DcolWdbe", "jref=" + to_string(jref));
	mAccess.unlock("DcolWdbe", "~DcolWdbe", "jref=" + to_string(jref));
};

void DcolWdbe::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.lock(srefObject, srefMember, "jref=" + to_string(jref));
};

void DcolWdbe::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.unlock(srefObject, srefMember, "jref=" + to_string(jref));
};

/******************************************************************************
 class JobWdbe
 ******************************************************************************/

JobWdbe::JobWdbe(
			XchgWdbe* xchg
			, const uint ixWdbeVJob
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			xchg(xchg)
			, ixWdbeVJob(ixWdbeVJob)
			, ixWdbeVLocale(ixWdbeVLocale)
			, mAccess("mAccess", VecWdbeVJob::getSref(ixWdbeVJob), VecWdbeVJob::getSref(ixWdbeVJob), "jrefSup=" + to_string(jrefSup))
			, mOps("mOps", VecWdbeVJob::getSref(ixWdbeVJob), VecWdbeVJob::getSref(ixWdbeVJob), "jrefSup=" + to_string(jrefSup))
		{
	jref = 0;

	muteRefresh = false;

	ixVSge = 1;
	nextIxVSgeSuccess = 1;
	nextIxVSgeFailure = 1;

	opN = 0;
	opNSuccess = 0;
	opNFailure = 0;

	wrefLast = 0;
	wrefMin = 0;

	reqCmd = NULL;
};

JobWdbe::~JobWdbe() {
	if (reqCmd) delete reqCmd;

	mAccess.lock(VecWdbeVJob::getSref(ixWdbeVJob), "~" + VecWdbeVJob::getSref(ixWdbeVJob), "jref=" + to_string(jref));
	mAccess.unlock(VecWdbeVJob::getSref(ixWdbeVJob), "~" + VecWdbeVJob::getSref(ixWdbeVJob), "jref=" + to_string(jref));
};

ubigint JobWdbe::insertSubjob(
			map<ubigint, JobWdbe*>& subjobs
			, JobWdbe* subjob
		) {
	subjobs[subjob->jref] = subjob;

	return subjob->jref;
};

bool JobWdbe::eraseSubjobByJref(
			map<ubigint, JobWdbe*>& subjobs
			, const ubigint _jref
		) {
	auto it = subjobs.find(_jref);

	if (it != subjobs.end()) {
		delete it->second;
		subjobs.erase(it);

		return true;
	};

	return false;
};

DpchEngWdbe* JobWdbe::getNewDpchEng(
			set<uint> items
		) {
	return new DpchEngWdbeConfirm(true, jref, "");
};

void JobWdbe::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
			, const bool unmute
		) {
};

void JobWdbe::refreshWithDpchEng(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
			, const bool unmute
		) {
	set<uint> moditems;

	DpchEngWdbe* _dpcheng = NULL;

	refresh(dbswdbe, moditems, unmute);
	if (muteRefresh) return;

	if (dpcheng) {
		_dpcheng = getNewDpchEng(moditems);

		if (*dpcheng) {
			if (_dpcheng->ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECONFIRM) delete _dpcheng;
			else if (_dpcheng->ixWdbeVDpch == (*dpcheng)->ixWdbeVDpch) {
				(*dpcheng)->merge(_dpcheng);
				delete _dpcheng;

			} else xchg->submitDpch(_dpcheng);

		} else *dpcheng = _dpcheng;

	} else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
};

string JobWdbe::getSquawk(
			DbsWdbe* dbswdbe
		) {
	return "";
};

void JobWdbe::handleRequest(
			DbsWdbe* dbswdbe
			, ReqWdbe* req
		) {
};

void JobWdbe::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
};

void JobWdbe::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.lock(srefObject, srefMember, "jref=" + to_string(jref));
};

bool JobWdbe::trylockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return mAccess.trylock(srefObject, srefMember, "jref=" + to_string(jref));
};

void JobWdbe::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.unlock(srefObject, srefMember, "jref=" + to_string(jref));
};

void JobWdbe::lockAccess(
			const string& srefMember
		) {
	mAccess.lock(VecWdbeVJob::getSref(ixWdbeVJob), srefMember, "jref=" + to_string(jref));
};

bool JobWdbe::trylockAccess(
			const string& srefMember
		) {
	return mAccess.trylock(VecWdbeVJob::getSref(ixWdbeVJob), srefMember, "jref=" + to_string(jref));
};

void JobWdbe::unlockAccess(
			const string& srefMember
		) {
	mAccess.unlock(VecWdbeVJob::getSref(ixWdbeVJob), srefMember, "jref=" + to_string(jref));
};

void JobWdbe::setStage(
			DbsWdbe* dbswdbe
			, const uint _ixVSge
		) {
	xchg->setJobStage(dbswdbe, this, _ixVSge);
};

void JobWdbe::clearInvs() {
	for (unsigned int i = 0; i < invs.size(); i++) delete invs[i];
	invs.clear();
};

ubigint JobWdbe::addInv(
			DpchInvWdbe* inv
		) {
	inv->oref = xchg->orefseq.getNewRef();
	inv->jref = jref;

	invs.push_back(inv);

	opN++;

	return(inv->oref);
};

void JobWdbe::addInvs(
			vector<DpchInvWdbe*>& _invs
		) {
	for (unsigned int i = 0; i < _invs.size(); i++) addInv(_invs[i]);
};

void JobWdbe::submitInvs(
			DbsWdbe* dbswdbe
			, const uint nextIxVSgeEmpty
			, uint& _ixVSge
		) {
	if (opN == 0) {
		_ixVSge = nextIxVSgeEmpty;

	} else {
		xchg->addInvs(dbswdbe, this, invs);
		invs.clear();
	};
};

void JobWdbe::clearOps() {
	mOps.lock(VecWdbeVJob::getSref(ixWdbeVJob), "clearOps", "jref=" + to_string(jref));

	for (auto it = ops.begin(); it != ops.end(); it++) delete(*it);
	ops.clear();

	mOps.unlock(VecWdbeVJob::getSref(ixWdbeVJob), "clearOps", "jref=" + to_string(jref));
};

void JobWdbe::addOp(
			DbsWdbe* dbswdbe
			, DpchInvWdbe* inv
		) {
	string squawk;

	mOps.lock(VecWdbeVJob::getSref(ixWdbeVJob), "addOp", "jref=" + to_string(jref));

	// generate squawk
	if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBECPLMSTCTRECTRHOSTIFEHOSTIF) {
		squawk = SqkWdbeCplmst::getSquawkCtrEctrHostifEhostif(dbswdbe, (DpchInvWdbeCplmstCtrEctrHostifEhostif*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBECPLMSTIMBUF) {
		squawk = SqkWdbeCplmst::getSquawkImbuf(dbswdbe, (DpchInvWdbeCplmstImbuf*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBECPLMSTTPLCPY) {
		squawk = SqkWdbeCplmst::getSquawkTplcpy(dbswdbe, (DpchInvWdbeCplmstTplcpy*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBECPLMSTUNT) {
		squawk = SqkWdbeCplmst::getSquawkUnt(dbswdbe, (DpchInvWdbeCplmstUnt*) inv);
	};
	if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENAUX) {
		squawk = SqkWdbeGen::getSquawkAux(dbswdbe, (DpchInvWdbeGenAux*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENSTDVEC) {
		squawk = SqkWdbeGen::getSquawkStdvec(dbswdbe, (DpchInvWdbeGenStdvec*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENWIRING) {
		squawk = SqkWdbeGen::getSquawkWiring(dbswdbe, (DpchInvWdbeGenWiring*) inv);
	};
	if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENFSTCMDBUS) {
		squawk = SqkWdbeGenfst::getSquawkCmdbus(dbswdbe, (DpchInvWdbeGenfstCmdbus*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENFSTCTR) {
		squawk = SqkWdbeGenfst::getSquawkCtr(dbswdbe, (DpchInvWdbeGenfstCtr*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENFSTECTR) {
		squawk = SqkWdbeGenfst::getSquawkEctr(dbswdbe, (DpchInvWdbeGenfstEctr*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENFSTEHOSTIF) {
		squawk = SqkWdbeGenfst::getSquawkEhostif(dbswdbe, (DpchInvWdbeGenfstEhostif*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENFSTHOSTIF) {
		squawk = SqkWdbeGenfst::getSquawkHostif(dbswdbe, (DpchInvWdbeGenfstHostif*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENFSTIMBUF) {
		squawk = SqkWdbeGenfst::getSquawkImbuf(dbswdbe, (DpchInvWdbeGenfstImbuf*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENFSTPPL) {
		squawk = SqkWdbeGenfst::getSquawkPpl(dbswdbe, (DpchInvWdbeGenfstPpl*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEGENFSTTOP) {
		squawk = SqkWdbeGenfst::getSquawkTop(dbswdbe, (DpchInvWdbeGenfstTop*) inv);
	};
	if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPCPLMSTBU) {
		squawk = SqkWdbeMtpCplmstbu::getSquawk(dbswdbe, (DpchInvWdbeMtpCplmstbu*) inv);
	};
	if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPCPLMSTTD) {
		squawk = SqkWdbeMtpCplmsttd::getSquawk(dbswdbe, (DpchInvWdbeMtpCplmsttd*) inv);
	};
	if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPGENFST) {
		squawk = SqkWdbeMtpGenfst::getSquawk(dbswdbe, (DpchInvWdbeMtpGenfst*) inv);
	};
	if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPPLHFPGA) {
		squawk = SqkWdbeMtpPlhfpga::getSquawk(dbswdbe, (DpchInvWdbeMtpPlhfpga*) inv);
	};
	if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPPLHMCU) {
		squawk = SqkWdbeMtpPlhmcu::getSquawk(dbswdbe, (DpchInvWdbeMtpPlhmcu*) inv);
	};
	if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPWRFPGA) {
		squawk = SqkWdbeMtpWrfpga::getSquawk(dbswdbe, (DpchInvWdbeMtpWrfpga*) inv);
	};
	if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEMTPWRMCU) {
		squawk = SqkWdbeMtpWrmcu::getSquawk(dbswdbe, (DpchInvWdbeMtpWrmcu*) inv);
	};
	if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPLHFPGACMDINV) {
		squawk = SqkWdbePlhfpga::getSquawkCmdinv(dbswdbe, (DpchInvWdbePlhfpgaCmdinv*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPLHFPGACMDRET) {
		squawk = SqkWdbePlhfpga::getSquawkCmdret(dbswdbe, (DpchInvWdbePlhfpgaCmdret*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPLHFPGACTR) {
		squawk = SqkWdbePlhfpga::getSquawkCtr(dbswdbe, (DpchInvWdbePlhfpgaCtr*) inv);
	};
	if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPLHMCUECTR) {
		squawk = SqkWdbePlhmcu::getSquawkEctr(dbswdbe, (DpchInvWdbePlhmcuEctr*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPLHMCUEHOSTIF) {
		squawk = SqkWdbePlhmcu::getSquawkEhostif(dbswdbe, (DpchInvWdbePlhmcuEhostif*) inv);
	};
	if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPRCFILECONCAT) {
		squawk = SqkWdbePrcfile::getSquawkConcat(dbswdbe, (DpchInvWdbePrcfileConcat*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPRCFILEPLHRPL) {
		squawk = SqkWdbePrcfile::getSquawkPlhrpl(dbswdbe, (DpchInvWdbePrcfilePlhrpl*) inv);
	};
	if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPRCTREEEXTRACT) {
		squawk = SqkWdbePrctree::getSquawkExtract(dbswdbe, (DpchInvWdbePrctreeExtract*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPRCTREEMERGE) {
		squawk = SqkWdbePrctree::getSquawkMerge(dbswdbe, (DpchInvWdbePrctreeMerge*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEPRCTREEVALIDATE) {
		squawk = SqkWdbePrctree::getSquawkValidate(dbswdbe, (DpchInvWdbePrctreeValidate*) inv);
	};
	if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRDEVBASE) {
		squawk = SqkWdbeWrdev::getSquawkBase(dbswdbe, (DpchInvWdbeWrdevBase*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRDEVCTR) {
		squawk = SqkWdbeWrdev::getSquawkCtr(dbswdbe, (DpchInvWdbeWrdevCtr*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRDEVDEPLOY) {
		squawk = SqkWdbeWrdev::getSquawkDeploy(dbswdbe, (DpchInvWdbeWrdevDeploy*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRDEVUNT) {
		squawk = SqkWdbeWrdev::getSquawkUnt(dbswdbe, (DpchInvWdbeWrdevUnt*) inv);
	};
	if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGAAUX) {
		squawk = SqkWdbeWrfpga::getSquawkAux(dbswdbe, (DpchInvWdbeWrfpgaAux*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGABASE) {
		squawk = SqkWdbeWrfpga::getSquawkBase(dbswdbe, (DpchInvWdbeWrfpgaBase*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGACTR) {
		squawk = SqkWdbeWrfpga::getSquawkCtr(dbswdbe, (DpchInvWdbeWrfpgaCtr*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGADEPLOY) {
		squawk = SqkWdbeWrfpga::getSquawkDeploy(dbswdbe, (DpchInvWdbeWrfpgaDeploy*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGAMDLFINE) {
		squawk = SqkWdbeWrfpga::getSquawkMdlfine(dbswdbe, (DpchInvWdbeWrfpgaMdlfine*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGAMDLRAW) {
		squawk = SqkWdbeWrfpga::getSquawkMdlraw(dbswdbe, (DpchInvWdbeWrfpgaMdlraw*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRFPGATOP) {
		squawk = SqkWdbeWrfpga::getSquawkTop(dbswdbe, (DpchInvWdbeWrfpgaTop*) inv);
	};
	if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRMCUBASE) {
		squawk = SqkWdbeWrmcu::getSquawkBase(dbswdbe, (DpchInvWdbeWrmcuBase*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRMCUCTR) {
		squawk = SqkWdbeWrmcu::getSquawkCtr(dbswdbe, (DpchInvWdbeWrmcuCtr*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRMCUDEPLOY) {
		squawk = SqkWdbeWrmcu::getSquawkDeploy(dbswdbe, (DpchInvWdbeWrmcuDeploy*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRMCUMDLFINE) {
		squawk = SqkWdbeWrmcu::getSquawkMdlfine(dbswdbe, (DpchInvWdbeWrmcuMdlfine*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRMCUMDLRAW) {
		squawk = SqkWdbeWrmcu::getSquawkMdlraw(dbswdbe, (DpchInvWdbeWrmcuMdlraw*) inv);
	};
	if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRTERMDEPLOY) {
		squawk = SqkWdbeWrterm::getSquawkDeploy(dbswdbe, (DpchInvWdbeWrtermDeploy*) inv);
	} else if (inv->ixWdbeVDpch == VecWdbeVDpch::DPCHINVWDBEWRTERMMAIN) {
		squawk = SqkWdbeWrterm::getSquawkMain(dbswdbe, (DpchInvWdbeWrtermMain*) inv);
	};

	// append to op list
	ops.push_back(new Op(inv->oref, inv->ixWdbeVDpch, squawk));

	mOps.unlock(VecWdbeVJob::getSref(ixWdbeVJob), "addOp", "jref=" + to_string(jref));
};

void JobWdbe::removeOp(
			const ubigint oref
		) {
	Op* op = NULL;

	mOps.lock(VecWdbeVJob::getSref(ixWdbeVJob), "removeOp", "jref=" + to_string(jref));

	for (auto it = ops.begin(); it != ops.end(); it++) {
		op = *it;

		if (op->oref == oref) {
			// found
			ops.erase(it);

			// keep squawk of this op
			opsqkLast = op->squawk;

			delete op;
			
			break;
		};
	};

	mOps.unlock(VecWdbeVJob::getSref(ixWdbeVJob), "removeOp", "jref=" + to_string(jref));
};

string JobWdbe::getOpsqkLast() {
	string retval;

	mOps.lock(VecWdbeVJob::getSref(ixWdbeVJob), "getOpsqkLast", "jref=" + to_string(jref));

	retval = opsqkLast;

	mOps.unlock(VecWdbeVJob::getSref(ixWdbeVJob), "getOpsqkLast", "jref=" + to_string(jref));

	return retval;
};

void JobWdbe::callback(
			const uint nextIxVSge
		) {
	nextIxVSgeSuccess = nextIxVSge;
	wrefLast = xchg->addWakeup(jref, "callback", 0);
};

void JobWdbe::invalidateWakeups() {
	wrefMin = wrefLast + 1;
};

/******************************************************************************
 class CsjobWdbe
 ******************************************************************************/

CsjobWdbe::CsjobWdbe(
			XchgWdbe* xchg
			, const uint ixWdbeVJob
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, ixWdbeVJob, jrefSup, ixWdbeVLocale)
		{
	srvNotCli = false;
	srv = NULL;
};

bool CsjobWdbe::handleClaim(
			DbsWdbe* dbswdbe
			, map<ubigint,Claim*>& claims
			, const ubigint jrefNewest
		) {
	return false;
};

/******************************************************************************
 class ShrdatWdbe
 ******************************************************************************/

ShrdatWdbe::ShrdatWdbe(
			const string& srefSupclass
			, const string& srefObject
		) :
			srefSupclass(srefSupclass)
			, srefObject(srefObject)
			, rwmAccess("shrdat.mAccess", srefSupclass + "::" + srefObject, srefObject)
		{
};

ShrdatWdbe::~ShrdatWdbe() {
};

void ShrdatWdbe::init(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
		) {
};

void ShrdatWdbe::term(
			XchgWdbe* xchg
		) {
};

void ShrdatWdbe::rlockAccess(
			const string& srefObject
			, const string& srefMember
			, const string& args
		) {
	rwmAccess.rlock(srefObject, srefMember, args);
};

void ShrdatWdbe::runlockAccess(
			const string& srefObject
			, const string& srefMember
			, const string& args
		) {
	rwmAccess.runlock(srefObject, srefMember, args);
};

void ShrdatWdbe::rlockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	rwmAccess.rlock(srefSupclass, srefMember, "jref=" + to_string(jref));
};

void ShrdatWdbe::runlockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	rwmAccess.runlock(srefSupclass, srefMember, "jref=" + to_string(jref));
};

void ShrdatWdbe::wlockAccess(
			const string& srefObject
			, const string& srefMember
			, const string& args
		) {
	rwmAccess.wlock(srefObject, srefMember, args);
};

void ShrdatWdbe::wunlockAccess(
			const string& srefObject
			, const string& srefMember
			, const string& args
		) {
	rwmAccess.wunlock(srefObject, srefMember, args);
};

void ShrdatWdbe::wlockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	rwmAccess.wlock(srefSupclass, srefMember, "jref=" + to_string(jref));
};

void ShrdatWdbe::wunlockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	rwmAccess.wunlock(srefSupclass, srefMember, "jref=" + to_string(jref));
};

/******************************************************************************
 class StmgrWdbe
 ******************************************************************************/

StmgrWdbe::StmgrWdbe(
			XchgWdbe* xchg
			, const ubigint jref
			, const uint ixVNonetype
		) :
			xchg(xchg)
			, jref(jref)
			, ixVNonetype(ixVNonetype)
			, mAccess("stmgr.mAccess", "StmgrWdbe", "StmgrWdbe", "jref=" + to_string(jref))
		{
	stcch = new Stcch(true);
};

StmgrWdbe::~StmgrWdbe() {
	delete stcch;

	mAccess.lock("StmgrWdbe", "~StmgrWdbe", "jref=" + to_string(jref));
	mAccess.unlock("StmgrWdbe", "~StmgrWdbe", "jref=" + to_string(jref));
};

void StmgrWdbe::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	set<uint> icsWdbeVStub;
	pair<multimap<stcchitemref_t,Stcchitem*>::iterator,multimap<stcchitemref_t,Stcchitem*>::iterator> rng;

	bool notif = false;

	begin();

	if (call->ixVCall == VecWdbeVCall::CALLWDBEBNKUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEBNKSTD);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEBNKSREF);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECDCUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBECDCDSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECMDUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBECMDSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECMPUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBECMPSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECPRUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBECPRSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECTRUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBECTRSTD);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBECTRLONG);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBECTRSREF);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECVRUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBECVRSTD);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBECVRNO);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEERRUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEERRSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEFAMUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEFAMSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEFILUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEFILSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEFSMUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEFSMSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEFSTUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEFSTSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEGENUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEGENSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEIMBUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEIMBSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEINTUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEINTSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBELIBUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBELIBSREF);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBELIBSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMCHUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEMCHSTD);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEMCHSREF);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDLUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEMTPSTD);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEMODSTD);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEMDLSTD);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEMDLSREF);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEMDLHSREF);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPINUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEPINSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPPHUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEPPHSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPPLUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEPPLSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPRCUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEPRCSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPRJUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEPRJSTD);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEPRJSHORT);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPRSUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEPRSSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPRTUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEPRTSTD);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEPRTSREF);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBERLSUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBERLSSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESEGUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBESEGSTD);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBESEGSREF);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBESEGHSREF);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESESUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBESESSTD);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBESESMENU);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESIGUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBESIGSREF);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBESIGSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESNSUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBESNSSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUNTUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBESILSTD);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEUNISTD);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEUNTSTD);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEUNTSREF);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUSGUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEGROUP);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEUSGSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUSRUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEUSRSTD);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEUSRPRS);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEOWNER);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVARUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEVARSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVECUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEVECSTD);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVERUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEVERSTD);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEVERSHORT);
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEVERNO);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVITUPD_REFEQ) {
		insert(icsWdbeVStub, VecWdbeVStub::STUBWDBEVITSTD);
	};

	for (auto it = icsWdbeVStub.begin(); it != icsWdbeVStub.end(); it++) {
		rng = stcch->nodes.equal_range(stcchitemref_t(*it, call->argInv.ref, 0));
		for (auto it2 = rng.first; it2 != rng.second; it2++) if (refresh(dbswdbe, it2->second)) notif = true;
	};

	commit();

	if (notif) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTUBCHG, jref);
};

bool StmgrWdbe::refresh(
			DbsWdbe* dbswdbe
			, Stcchitem* stit
		) {
	set<stcchitemref_t> strefsSub_backup;
	string stub_backup;

	while (!stit->strefsSup.empty()) stcch->unlink(*stit->strefsSup.begin(), stit->stref);

	strefsSub_backup = stit->strefsSub;
	stub_backup = stit->stub;

	StubWdbe::getStub(dbswdbe, stit->stref.ixVStub, stit->stref.ref, stit->stref.ixVLocale, ixVNonetype, stcch, NULL, true);

	if (stit->stub != stub_backup) {
		for (auto it = strefsSub_backup.begin(); it != strefsSub_backup.end(); it++) refresh(dbswdbe, stcch->getStitByStref(*it));
		return true;
	} else return false;
};

void StmgrWdbe::begin() {
	stcch->begin();
};

void StmgrWdbe::commit() {
	for (auto it = stcch->icsVStubNew.begin(); it != stcch->icsVStubNew.end(); it++) {
		if (*it == VecWdbeVStub::STUBWDBEBNKSREF) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEBNKUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEBNKSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEBNKUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBECDCDSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBECDCUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBECMDSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBECMDUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBECMPSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBECMPUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBECPRSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBECPRUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBECTRLONG) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBECTRUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBECTRSREF) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBECTRUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBECTRSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBECTRUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBECVRNO) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBECVRUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBECVRSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBECVRUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEERRSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEERRUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEFAMSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEFAMUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEFILSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEFILUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEFSMSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEFSMUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEFSTSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEFSTUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEGENSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEGENUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEGROUP) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEUSGUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEIMBSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEIMBUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEINTSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEINTUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBELIBSREF) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBELIBUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBELIBSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBELIBUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEMCHSREF) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEMCHUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEMCHSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEMCHUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEMDLHSREF) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEMDLUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEMDLSREF) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEMDLUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEMDLSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEMDLUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEMODSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEMDLUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEMTPSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEMDLUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEOWNER) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEUSRUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEPINSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEPINUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEPPHSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEPPHUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEPPLSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEPPLUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEPRCSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEPRCUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEPRJSHORT) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEPRJUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEPRJSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEPRJUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEPRSSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEPRSUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEPRTSREF) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEPRTUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEPRTSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEPRTUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBERLSSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBERLSUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBESEGHSREF) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBESEGUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBESEGSREF) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBESEGUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBESEGSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBESEGUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBESESMENU) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBESESUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBESESSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBESESUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBESIGSREF) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBESIGUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBESIGSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBESIGUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBESILSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEUNTUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBESNSSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBESNSUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEUNISTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEUNTUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEUNTSREF) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEUNTUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEUNTSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEUNTUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEUSGSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEUSGUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEUSRPRS) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEUSRUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEUSRSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEUSRUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEVARSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEVARUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEVECSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEVECUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEVERNO) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEVERUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEVERSHORT) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEVERUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEVERSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEVERUPD_REFEQ, jref);
		} else if (*it == VecWdbeVStub::STUBWDBEVITSTD) {
			xchg->addClstnStmgr(VecWdbeVCall::CALLWDBEVITUPD_REFEQ, jref);
		};
	};

	stcch->commit();
};

void StmgrWdbe::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.lock(srefObject, srefMember, "jref=" + to_string(jref));
};

void StmgrWdbe::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.unlock(srefObject, srefMember, "jref=" + to_string(jref));
};

/******************************************************************************
 class WakeupWdbe
 ******************************************************************************/

WakeupWdbe::WakeupWdbe(
			XchgWdbe* xchg
			, const ubigint wref
			, const ubigint jref
			, const string sref
			, const uint64_t deltat
			, const bool weak
		) :
			xchg(xchg)
			, wref(wref)
			, jref(jref)
			, sref(sref)
			, deltat(deltat)
			, weak(weak)
		{
};

/******************************************************************************
 class ExtcallWdbe
 ******************************************************************************/

ExtcallWdbe::ExtcallWdbe(
			XchgWdbe* xchg
			, Call* call
		) :
			xchg(xchg)
			, call(call)
		{
};

// IP ShrdatJobprc.subs --- INSERT

/******************************************************************************
 class XchgWdbecmbd::ShrdatJobprc
 ******************************************************************************/

XchgWdbecmbd::ShrdatJobprc::ShrdatJobprc() :
			ShrdatWdbe("XchgWdbe", "ShrdatJobprc")
		{
};

void XchgWdbecmbd::ShrdatJobprc::init(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
		) {
	// IP ShrdatJobprc.init --- INSERT
};

void XchgWdbecmbd::ShrdatJobprc::term(
			XchgWdbe* xchg
		) {
	// IP ShrdatJobprc.term --- INSERT
};

// IP ShrdatOpprc.subs --- INSERT

/******************************************************************************
 class XchgWdbecmbd::ShrdatOpprc
 ******************************************************************************/

XchgWdbecmbd::ShrdatOpprc::ShrdatOpprc() :
			ShrdatWdbe("XchgWdbe", "ShrdatOpprc")
		{
};

void XchgWdbecmbd::ShrdatOpprc::init(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
		) {
	// IP ShrdatOpprc.init --- INSERT
};

void XchgWdbecmbd::ShrdatOpprc::term(
			XchgWdbe* xchg
		) {
	// IP ShrdatOpprc.term --- INSERT
};

/******************************************************************************
 class XchgWdbecmbd
 ******************************************************************************/

XchgWdbecmbd::XchgWdbecmbd() :
			cStable("cStable", "XchgWdbecmbd", "XchgWdbecmbd")
			, mLogfile("mLogfile", "XchgWdbecmbd", "XchgWdbecmbd")
			, cJobprcs("cJobprcs", "XchgWdbecmbd", "XchgWdbecmbd")
			, cOpprcs("cOpprcs", "XchgWdbecmbd", "XchgWdbecmbd")
			, mReqs("mReqs", "XchgWdbecmbd", "XchgWdbecmbd")
			, orefseq("orefseq")
			, mInvs("mInvs", "XchgWdbecmbd", "XchgWdbecmbd")
			, rwmPresets("rwmPresets", "XchgWdbecmbd", "XchgWdbecmbd")
			, rwmStmgrs("rwmStmgrs", "XchgWdbecmbd", "XchgWdbecmbd")
			, rwmClstns("rwmClstns", "XchgWdbecmbd", "XchgWdbecmbd")
			, rwmDcols("rwmDcols", "XchgWdbecmbd", "XchgWdbecmbd")
			, jrefseq("jrefseq")
			, rwmJobs("rwmJobs", "XchgWdbecmbd", "XchgWdbecmbd")
			, rwmCsjobinfos("rwmCsjobinfos", "XchgWdbecmbd", "XchgWdbecmbd")
			, wrefseq("wrefseq")
		{
	// root job
	jrefRoot = 0;

	// job receiving commands
	jrefCmd = 0;

	// client-server job information
	csjobinfos[VecWdbeVJob::JOBWDBELICENSE] = new Csjobinfo(VecWdbeVJob::JOBWDBELICENSE);

};

XchgWdbecmbd::~XchgWdbecmbd() {
	// empty out lists
	for (auto it = reqs.begin(); it != reqs.end(); it++) delete(*it);
	for (auto it = invs.begin(); it != invs.end(); it++) delete(*it);
	for (auto it = presets.begin(); it != presets.end(); it++) delete(it->second);
	for (auto it = stmgrs.begin(); it != stmgrs.end(); it++) delete(it->second);
	for (auto it = clstns.begin(); it != clstns.end(); it++) delete(it->second);
	for (auto it = dcols.begin(); it != dcols.end(); it++) delete(it->second);
	for (auto it = jobs.begin(); it != jobs.end(); it++) delete(it->second);
	for (auto it = jobinfos.begin(); it != jobinfos.end(); it++) delete(it->second);
	for (auto it = csjobinfos.begin(); it != csjobinfos.end(); it++) delete(it->second);
};

// IP cust --- INSERT

void XchgWdbecmbd::startMon() {
	JobWdbe* job = NULL;
	Jobinfo* jobinfo = NULL;

	DcolWdbe* dcol = NULL;
	bool Dcol;

	StmgrWdbe* stmgr = NULL;
	bool Stmgr;

	Clstn* clstn = NULL;
	Preset* preset = NULL;

	mon.start("WhizniumDBE v1.1.50", stgwdbemonitor.ixDbsVDbstype, stgwdbemonitor.dbspath, stgwdbemonitor.dbsname, stgwdbemonitor.ip, stgwdbemonitor.port, stgwdbemonitor.dbsusername, stgwdbemonitor.dbspassword, stgwdbemonitor.username, stgwdbemonitor.password);

	rwmJobs.rlock("XchgWdbecmbd", "startMon");
	for (auto it = jobs.begin(); it != jobs.end(); it++) {
		job = it->second;
		jobinfo = jobinfos[job->jref];

		dcol = getDcolByJref(job->jref, false);
		if (dcol) {
			Dcol = true;
			dcol->unlockAccess("XchgWdbecmbd", "startMon");
		} else Dcol = false;

		stmgr = getStmgrByJref(job->jref);
		if (stmgr) {
			Stmgr = true;
			stmgr->unlockAccess("XchgWdbecmbd", "startMon");
		} else Stmgr = false;

		if (getCsjobNotJob(job->ixWdbeVJob)) mon.insertJob(jobinfo->jrefSup, VecWdbeVJob::getSref(job->ixWdbeVJob), job->jref, true, ((CsjobWdbe*) job)->srvNotCli, Dcol, Stmgr);
		else mon.insertJob(jobinfo->jrefSup, VecWdbeVJob::getSref(job->ixWdbeVJob), job->jref, false, false, Dcol, Stmgr);
	};
	rwmJobs.runlock("XchgWdbecmbd", "startMon");

	rwmClstns.rlock("XchgWdbecmbd", "startMon");
	for (auto it = clstns.begin(); it != clstns.end(); it++) {
		clstn = it->second;
		mon.insertClstn(clstn->cref.jref, Clstn::VecVTarget::getSref(clstn->cref.ixVTarget), VecWdbeVCall::getSref(clstn->cref.ixVCall), Clstn::VecVJobmask::getSref(clstn->cref.ixVJobmask), clstn->cref.jrefTrig, clstn->cref.arg, clstn->cref.ixVSge, Clstn::VecVJactype::getSref(clstn->ixVJactype));
	};
	rwmClstns.runlock("XchgWdbecmbd", "startMon");

	rwmPresets.rlock("XchgWdbecmbd", "startMon");
	for (auto it = presets.begin(); it != presets.end(); it++) {
		preset = it->second;
		mon.insertPreset(preset->pref.jref, VecWdbeVPreset::getSref(preset->pref.ixVPreset), preset->arg);
	};
	rwmPresets.runlock("XchgWdbecmbd", "startMon");

	triggerCall(NULL, VecWdbeVCall::CALLWDBEMONSTATCHG, jrefRoot);
};

void XchgWdbecmbd::stopMon() {
	mon.stop();

	triggerCall(NULL, VecWdbeVCall::CALLWDBEMONSTATCHG, jrefRoot);
};

void XchgWdbecmbd::appendToLogfile(
			const string& str
		) {
	time_t rawtime;
	fstream logfile;

	mLogfile.lock("XchgWdbecmbd", "appendToLogfile");

	time(&rawtime);

	logfile.open(exedir + "/log.txt", ios::out | ios::app);
	logfile << Ftm::stamp(rawtime) << ": " << str << endl;
	logfile.close();

	mLogfile.unlock("XchgWdbecmbd", "appendToLogfile");
};

void XchgWdbecmbd::addReq(
			ReqWdbe* req
		) {
	if (jrefRoot == 0) return;

	mReqs.lock("XchgWdbecmbd", "addReq", "jref=" + to_string(req->jref));

	req->ixVState = ReqWdbe::VecVState::WAITPRC;
	reqs.push_back(req);

	mReqs.unlock("XchgWdbecmbd", "addReq", "jref=" + to_string(req->jref));

	cJobprcs.signal("XchgWdbecmbd", "addReq", "jref=" + to_string(req->jref));
};

ReqWdbe* XchgWdbecmbd::pullFirstReq() {
	ReqWdbe* req;

	// get first element from list
	mReqs.lock("XchgWdbecmbd", "pullFirstReq");

	req = NULL;

	if (!reqs.empty()) {
		req = *(reqs.begin());
		req->ixVState = ReqWdbe::VecVState::PRC;
		reqs.pop_front();
	};

	mReqs.unlock("XchgWdbecmbd", "pullFirstReq");

	return req;
};

void XchgWdbecmbd::addInvs(
			DbsWdbe* dbswdbe
			, JobWdbe* job
			, vector<DpchInvWdbe*>& dpchinvs
		) {
	// append to inv list and signal the news (note the double-lock)
	mInvs.lock("XchgWdbecmbd", "addInvs", "jref=" + to_string(job->jref));
	job->mOps.lock("XchgWdbecmbd", "addInvs", "jref=" + to_string(job->jref));

	for (unsigned int i = 0; i < dpchinvs.size(); i++) {
		job->addOp(dbswdbe, dpchinvs[i]);

		invs.push_back(dpchinvs[i]);

		mon.eventAddInv(job->jref, VecWdbeVDpch::getSref(dpchinvs[i]->ixWdbeVDpch), "", dpchinvs[i]->oref);
	};

	job->mOps.unlock("XchgWdbecmbd", "addInvs", "jref=" + to_string(job->jref));
	mInvs.unlock("XchgWdbecmbd", "addInvs", "jref=" + to_string(job->jref));

	cOpprcs.broadcast("XchgWdbecmbd", "addInvs", "jref=" + to_string(job->jref));
};

DpchInvWdbe* XchgWdbecmbd::pullFirstInv() {
	DpchInvWdbe* inv;

	// get first element from list
	mInvs.lock("XchgWdbecmbd", "pullFirstInv");

	inv = NULL;

	if (!invs.empty()) {
		inv = *(invs.begin());
		invs.pop_front();
	};

	mInvs.unlock("XchgWdbecmbd", "pullFirstInv");

	return inv;
};

Preset* XchgWdbecmbd::addPreset(
			const uint ixWdbeVPreset
			, const ubigint jref
			, const Arg& arg
		) {
	presetref_t pref(jref, ixWdbeVPreset);
	Preset* preset;

	// create new presetting (override value if exists) and append to presetting list
	preset = getPresetByPref(pref);

	rwmPresets.wlock("XchgWdbecmbd", "addPreset", "jref=" + to_string(jref));

	if (preset) {
		preset->arg = arg;

		mon.eventChangePreset(jref, VecWdbeVPreset::getSref(ixWdbeVPreset), arg);

	} else {
		preset = new Preset(pref, arg);
		presets.insert(pair<presetref_t,Preset*>(pref, preset));

		mon.eventAddPreset(jref, VecWdbeVPreset::getSref(ixWdbeVPreset), arg);
	};

	rwmPresets.wunlock("XchgWdbecmbd", "addPreset", "jref=" + to_string(jref));

	return(preset);
};

Preset* XchgWdbecmbd::addIxPreset(
			const uint ixWdbeVPreset
			, const ubigint jref
			, const uint ix
		) {
	return(addPreset(ixWdbeVPreset, jref, Arg(ix, 0, {}, "", 0, 0.0, false, "", Arg::IX)));
};

Preset* XchgWdbecmbd::addRefPreset(
			const uint ixWdbeVPreset
			, const ubigint jref
			, const ubigint ref
		) {
	return(addPreset(ixWdbeVPreset, jref, Arg(0, ref, {}, "", 0, 0.0, false, "", Arg::REF)));
};

Preset* XchgWdbecmbd::addRefsPreset(
			const uint ixWdbeVPreset
			, const ubigint jref
			, const vector<ubigint>& refs
		) {
	Arg arg(0, 0, refs, "", 0, 0.0, false, "", Arg::REFS);

	return(addPreset(ixWdbeVPreset, jref, arg));
};

Preset* XchgWdbecmbd::addSrefPreset(
			const uint ixWdbeVPreset
			, const ubigint jref
			, const string& sref
		) {
	return(addPreset(ixWdbeVPreset, jref, Arg(0, 0, {}, sref, 0, 0.0, false, "", Arg::SREF)));
};

Preset* XchgWdbecmbd::addIntvalPreset(
			const uint ixWdbeVPreset
			, const ubigint jref
			, const int intval
		) {
	return(addPreset(ixWdbeVPreset, jref, Arg(0, 0, {}, "", intval, 0.0, false, "", Arg::INTVAL)));
};

Preset* XchgWdbecmbd::addDblvalPreset(
			const uint ixWdbeVPreset
			, const ubigint jref
			, const double dblval
		) {
	return(addPreset(ixWdbeVPreset, jref, Arg(0, 0, {}, "", 0, dblval, false, "", Arg::DBLVAL)));
};

Preset* XchgWdbecmbd::addBoolvalPreset(
			const uint ixWdbeVPreset
			, const ubigint jref
			, const bool boolval
		) {
	return(addPreset(ixWdbeVPreset, jref, Arg(0, 0, {}, "", 0, 0.0, boolval, "", Arg::BOOLVAL)));
};

Preset* XchgWdbecmbd::addTxtvalPreset(
			const uint ixWdbeVPreset
			, const ubigint jref
			, const string& txtval
		) {
	return(addPreset(ixWdbeVPreset, jref, Arg(0, 0, {}, "", 0, 0.0, false, txtval, Arg::TXTVAL)));
};

Preset* XchgWdbecmbd::getPresetByPref(
			const presetref_t& pref
		) {
	Preset* preset = NULL;

	rwmPresets.rlock("XchgWdbecmbd", "getPresetByPref");

	auto it = presets.find(pref);
	if (it != presets.end()) preset = it->second;

	rwmPresets.runlock("XchgWdbecmbd", "getPresetByPref");

	return preset;
};

Arg XchgWdbecmbd::getPreset(
			const uint ixWdbeVPreset
			, ubigint jref
		) {
	Arg arg;

	Jobinfo* jobinfo = NULL;
	Preset* preset = NULL;

	if ( (ixWdbeVPreset == VecWdbeVPreset::PREWDBESYSDATE) || (ixWdbeVPreset == VecWdbeVPreset::PREWDBESYSTIME) || (ixWdbeVPreset == VecWdbeVPreset::PREWDBESYSSTAMP) ) {
		time_t rawtime;
		time(&rawtime);

		if (ixWdbeVPreset == VecWdbeVPreset::PREWDBESYSSTAMP) {
			arg.mask = Arg::REF;
			arg.ref = rawtime;

		} else {
			arg.mask = Arg::INTVAL;

			if (ixWdbeVPreset == VecWdbeVPreset::PREWDBESYSDATE) arg.intval = (rawtime-rawtime%(3600*24))/(3600*24);
			else arg.intval = rawtime%(3600*24);
		};

	} else {
		rwmJobs.rlock("XchgWdbecmbd", "getPreset", "jref=" + to_string(jref));
		rwmPresets.rlock("XchgWdbecmbd", "getPreset", "jref=" + to_string(jref));

		jobinfo = getJobinfoByJref(jref);

		if (jobinfo && (ixWdbeVPreset == VecWdbeVPreset::PREWDBEIXLCL)) {
			arg.mask = Arg::IX;
			arg.ix = jobs[jref]->ixWdbeVLocale;

		} else {
			while (jobinfo && !preset) {
				preset = getPresetByPref(presetref_t(jref, ixWdbeVPreset));

				if (preset) arg = preset->arg;
				else {
					jref = jobinfo->jrefSup;
					jobinfo = getJobinfoByJref(jref);
				};
			};
		};

		rwmPresets.runlock("XchgWdbecmbd", "getPreset", "jref=" + to_string(jref));
		rwmJobs.runlock("XchgWdbecmbd", "getPreset", "jref=" + to_string(jref));
	};

	return(arg);
};

uint XchgWdbecmbd::getIxPreset(
			const uint ixWdbeVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWdbeVPreset, jref);

	if (arg.mask & Arg::IX) return(arg.ix);
	else return(0);
};

ubigint XchgWdbecmbd::getRefPreset(
			const uint ixWdbeVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWdbeVPreset, jref);

	if (arg.mask & Arg::REF) return(arg.ref);
	else return(0);
};

vector<ubigint> XchgWdbecmbd::getRefsPreset(
			const uint ixWdbeVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWdbeVPreset, jref);
	vector<ubigint> empty;

	if (arg.mask & Arg::REFS) return(arg.refs);
	else return(empty);
};

string XchgWdbecmbd::getSrefPreset(
			const uint ixWdbeVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWdbeVPreset, jref);

	if (arg.mask & Arg::SREF) return(arg.sref);
	else return("");
};

int XchgWdbecmbd::getIntvalPreset(
			const uint ixWdbeVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWdbeVPreset, jref);

	if (arg.mask & Arg::INTVAL) return(arg.intval);
	else return(intvalInvalid);
};

double XchgWdbecmbd::getDblvalPreset(
			const uint ixWdbeVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWdbeVPreset, jref);

	if (arg.mask & Arg::DBLVAL) return(arg.dblval);
	else return(dblvalInvalid);
};

bool XchgWdbecmbd::getBoolvalPreset(
			const uint ixWdbeVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWdbeVPreset, jref);

	if (arg.mask & Arg::BOOLVAL) return(arg.boolval);
	else return(false);
};

string XchgWdbecmbd::getTxtvalPreset(
			const uint ixWdbeVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWdbeVPreset, jref);

	if (arg.mask & Arg::TXTVAL) return(arg.txtval);
	else return("");
};

void XchgWdbecmbd::getPresetsByJref(
			const ubigint jref
			, vector<uint>& icsWdbeVPreset
			, vector<Arg>& args
		) {
	Preset* preset = NULL;

	icsWdbeVPreset.clear();
	args.clear();

	rwmPresets.rlock("XchgWdbecmbd", "getPresetsByJref", "jref=" + to_string(jref));

	auto rng = presets.equal_range(presetref_t(jref, 0));
	for (auto it = rng.first; it != rng.second; it++) {
		preset = it->second;

		icsWdbeVPreset.push_back(preset->pref.ixVPreset);
		args.push_back(preset->arg);
	};

	rwmPresets.runlock("XchgWdbecmbd", "getPresetsByJref", "jref=" + to_string(jref));
};

void XchgWdbecmbd::removePreset(
			const uint ixWdbeVPreset
			, const ubigint jref
		) {
	rwmPresets.wlock("XchgWdbecmbd", "removePreset", "jref=" + to_string(jref) + ",srefIxWdbeVPreset=" + VecWdbeVPreset::getSref(ixWdbeVPreset));

	auto it = presets.find(presetref_t(jref, ixWdbeVPreset));
	if (it != presets.end()) {
		delete it->second;
		presets.erase(it);

		mon.eventRemovePreset(jref, VecWdbeVPreset::getSref(ixWdbeVPreset));
	};

	rwmPresets.wunlock("XchgWdbecmbd", "removePreset", "jref=" + to_string(jref) + ",srefIxWdbeVPreset=" + VecWdbeVPreset::getSref(ixWdbeVPreset));
};

void XchgWdbecmbd::removePresetsByJref(
			const ubigint jref
		) {
	rwmPresets.wlock("XchgWdbecmbd", "removePresetsByJref", "jref=" + to_string(jref));

	uint ixVPreset;

	auto rng = presets.equal_range(presetref_t(jref, 0));
	for (auto it = rng.first; it != rng.second; it++) {
		ixVPreset = it->second->pref.ixVPreset;
		delete it->second;

		mon.eventRemovePreset(jref, VecWdbeVPreset::getSref(ixVPreset));
	};
	presets.erase(rng.first, rng.second);

	rwmPresets.wunlock("XchgWdbecmbd", "removePresetsByJref", "jref=" + to_string(jref));
};

StmgrWdbe* XchgWdbecmbd::addStmgr(
			const ubigint jref
			, const uint ixVNonetype
		) {
	StmgrWdbe* stmgr = NULL;

	// create new stmgr and append to stmgr list
	stmgr = getStmgrByJref(jref);

	if (!stmgr) {
		rwmStmgrs.wlock("XchgWdbecmbd", "addStmgr", "jref=" + to_string(jref));

		stmgr = new StmgrWdbe(this, jref, ixVNonetype);
		stmgrs[jref] = stmgr;

		rwmStmgrs.wunlock("XchgWdbecmbd", "addStmgr", "jref=" + to_string(jref));

		mon.eventAddStmgr(jref);
	};

	return(stmgr);
};

StmgrWdbe* XchgWdbecmbd::getStmgrByJref(
			const ubigint jref
		) {
	StmgrWdbe* stmgr = NULL;

	rwmStmgrs.rlock("XchgWdbecmbd", "getStmgrByJref", "jref=" + to_string(jref));

	auto it = stmgrs.find(jref);

	if (it != stmgrs.end()) {
		stmgr = it->second;
		stmgr->lockAccess("XchgWdbecmbd", "getStmgrByJref");
	};

	rwmStmgrs.runlock("XchgWdbecmbd", "getStmgrByJref", "jref=" + to_string(jref));

	return(stmgr);
};

void XchgWdbecmbd::removeStmgrByJref(
			const ubigint jref
		) {
	rwmStmgrs.wlock("XchgWdbecmbd", "removeStmgrByJref", "jref=" + to_string(jref));

	removeClstnsByJref(jref, Clstn::VecVTarget::STMGR);

	auto it = stmgrs.find(jref);
	if (it != stmgrs.end()) {
		delete it->second;
		stmgrs.erase(it);

		mon.eventRemoveStmgr(jref);
	};

	rwmStmgrs.wunlock("XchgWdbecmbd", "removeStmgrByJref", "jref=" + to_string(jref));
};

Clstn* XchgWdbecmbd::addClstn(
			const uint ixWdbeVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const Arg& arg
			, const uint ixVSge
			, const uint ixVJactype
		) {
	clstnref_t cref(ixWdbeVCall, jref, Clstn::VecVTarget::JOB, ixVJobmask, jrefTrig, arg, ixVSge);
	clstnref2_t cref2(cref);

	multimap<clstnref_t,Clstn*>::iterator it;
	Clstn* clstn = NULL;

	rwmClstns.wlock("XchgWdbecmbd", "addClstn", "jref=" + to_string(jref) + ",srefIxWdbeVCall=" + VecWdbeVCall::getSref(ixWdbeVCall));

	if (!chgarg) it = clstns.end();
	else {
		Arg argFind = arg;
		argFind.clearContent();

		clstnref_t crefFind(ixWdbeVCall, jref, Clstn::VecVTarget::JOB, ixVJobmask, jrefTrig, argFind, ixVSge);

		it = clstns.find(crefFind);
	};

	if (it == clstns.end()) {
		// create new clstn and append to clstn list
		clstn = new Clstn(cref, ixVJactype);
		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));

		mon.eventAddClstn(jref, "job", VecWdbeVCall::getSref(ixWdbeVCall), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, arg, ixVSge, Clstn::VecVJactype::getSref(ixVJactype));

	} else {
		// change clstn argument
		clstn = it->second;
		clstn->cref = cref;

		cref2sClstns.erase(clstnref2_t(it->first));
		clstns.erase(it->first);

		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));
		
		mon.eventChangeClstnArg(jref, "job", VecWdbeVCall::getSref(ixWdbeVCall), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, arg, ixVSge, Clstn::VecVJactype::getSref(ixVJactype));
	};

	rwmClstns.wunlock("XchgWdbecmbd", "addClstn", "jref=" + to_string(jref) + ",srefIxWdbeVCall=" + VecWdbeVCall::getSref(ixWdbeVCall));

	return(clstn);
};

Clstn* XchgWdbecmbd::addIxClstn(
			const uint ixWdbeVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const uint ix
			, const uint ixVSge
			, const uint ixVJactype
		) {
	Arg arg(ix, 0, {}, "", 0, 0.0, false, "", Arg::IX);

	return(addClstn(ixWdbeVCall, jref, ixVJobmask, jrefTrig, chgarg, arg, ixVSge, ixVJactype));
};

Clstn* XchgWdbecmbd::addRefClstn(
			const uint ixWdbeVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const ubigint ref
			, const uint ixVSge
			, const uint ixVJactype
		) {
	Arg arg(0, ref, {}, "", 0, 0.0, false, "", Arg::REF);

	return(addClstn(ixWdbeVCall, jref, ixVJobmask, jrefTrig, chgarg, arg, ixVSge, ixVJactype));
};

Clstn* XchgWdbecmbd::addIxRefClstn(
			const uint ixWdbeVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const uint ix
			, const ubigint ref
			, const uint ixVSge
			, const uint ixVJactype
		) {
	Arg arg(ix, ref, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);

	return(addClstn(ixWdbeVCall, jref, ixVJobmask, jrefTrig, chgarg, arg, ixVSge, ixVJactype));
		};

Clstn* XchgWdbecmbd::addIxRefSrefClstn(
			const uint ixWdbeVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const uint ix
			, const ubigint ref
			, const string& sref
			, const uint ixVSge
			, const uint ixVJactype
		) {
	Arg arg(ix, ref, {}, sref, 0, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF);

	return(addClstn(ixWdbeVCall, jref, ixVJobmask, jrefTrig, chgarg, arg, ixVSge, ixVJactype));
};

Clstn* XchgWdbecmbd::addClstnStmgr(
			const uint ixWdbeVCall
			, const ubigint jref
		) {
	clstnref_t cref(ixWdbeVCall, jref, Clstn::VecVTarget::STMGR, Clstn::VecVJobmask::ALL);
	clstnref2_t cref2(cref);
	Clstn* clstn;

	// create new clstn and append to clstn list
	clstn = getClstnByCref(cref);

	if (!clstn) {
		rwmClstns.wlock("XchgWdbecmbd", "addClstnStmgr", "jref=" + to_string(jref) + ",srefIxWdbeVCall=" + VecWdbeVCall::getSref(ixWdbeVCall));

		clstn = new Clstn(cref, Clstn::VecVJactype::LOCK);
		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));

		rwmClstns.wunlock("XchgWdbecmbd", "addClstnStmgr", "jref=" + to_string(jref) + ",srefIxWdbeVCall=" + VecWdbeVCall::getSref(ixWdbeVCall));

		mon.eventAddClstn(jref, "stmgr", VecWdbeVCall::getSref(ixWdbeVCall), Clstn::VecVJobmask::getSref(Clstn::VecVJobmask::ALL), 0, Arg(), 0, Clstn::VecVJactype::getSref(Clstn::VecVJactype::LOCK));
	};

	return(clstn);
};

Clstn* XchgWdbecmbd::getClstnByCref(
			const clstnref_t& cref
		) {
	Clstn* clstn = NULL;

	rwmClstns.rlock("XchgWdbecmbd", "getClstnByCref");

	auto it = clstns.find(cref);
	if (it != clstns.end()) clstn = it->second;

	rwmClstns.runlock("XchgWdbecmbd", "getClstnByCref");

	return clstn;
};

void XchgWdbecmbd::getClstnsByJref(
			const ubigint jref
			, const uint ixVTarget
			, vector<uint>& icsWdbeVCall
			, vector<uint>& icsVJobmask
		) {
	Clstn* clstn = NULL;

	icsWdbeVCall.clear();
	icsVJobmask.clear();

	rwmClstns.rlock("XchgWdbecmbd", "getClstnsByJref", "jref=" + to_string(jref));

	auto rng = cref2sClstns.equal_range(clstnref2_t(jref, ixVTarget, 0));
	for (auto it = rng.first; it != rng.second; it++) {
		clstn = getClstnByCref(it->second);

		if (clstn) {
			icsWdbeVCall.push_back(clstn->cref.ixVCall);
			icsVJobmask.push_back(clstn->cref.ixVJobmask);
		};
	};

	rwmClstns.runlock("XchgWdbecmbd", "getClstnsByJref", "jref=" + to_string(jref));
};

void XchgWdbecmbd::removeClstns(
			const uint ixWdbeVCall
			, const ubigint jref
			, const uint ixVTarget
		) {
	rwmClstns.wlock("XchgWdbecmbd", "removeClstns", "jref=" + to_string(jref));

	uint ixVJobmask;
	ubigint jrefTrig;
	Arg arg;
	uint ixVSge;
	uint ixVJactype;

	auto rng = clstns.equal_range(clstnref_t(ixWdbeVCall, jref, ixVTarget));
	for (auto it = rng.first; it != rng.second; it++) {
		ixVJobmask = it->second->cref.ixVJobmask;
		jrefTrig = it->second->cref.jrefTrig;
		arg = it->second->cref.arg;
		ixVSge = it->second->cref.ixVSge;
		ixVJactype = it->second->ixVJactype;

		cref2sClstns.erase(clstnref2_t(it->first));
		delete it->second;

		mon.eventRemoveClstn(jref, Clstn::VecVTarget::getSref(ixVTarget), VecWdbeVCall::getSref(ixWdbeVCall), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, arg, ixVSge, Clstn::VecVJobmask::getSref(ixVJactype));
	};
	clstns.erase(rng.first, rng.second);

	rwmClstns.wunlock("XchgWdbecmbd", "removeClstns", "jref=" + to_string(jref));
};

void XchgWdbecmbd::removeClstnsByJref(
			const ubigint jref
			, const uint ixVTarget
		) {
	rwmClstns.wlock("XchgWdbecmbd", "removeClstnsByJref", "jref=" + to_string(jref));

	uint ixVCall;
	uint ixVJobmask;
	ubigint jrefTrig;
	Arg arg;
	uint ixVSge;
	uint ixVJactype;

	auto rng = cref2sClstns.equal_range(clstnref2_t(jref, ixVTarget));
	for (auto it = rng.first; it != rng.second; it++) {
		auto it2 = clstns.find(it->second);

		ixVCall = it2->second->cref.ixVCall;
		ixVJobmask = it2->second->cref.ixVJobmask;
		jrefTrig = it2->second->cref.jrefTrig;
		arg = it2->second->cref.arg;
		ixVSge = it2->second->cref.ixVSge;
		ixVJactype = it2->second->ixVJactype;

		delete it2->second;
		clstns.erase(it2);

		mon.eventRemoveClstn(jref, Clstn::VecVTarget::getSref(ixVTarget), VecWdbeVCall::getSref(ixVCall), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, arg, ixVSge, Clstn::VecVJobmask::getSref(ixVJactype));
	};
	cref2sClstns.erase(rng.first, rng.second);

	rwmClstns.wunlock("XchgWdbecmbd", "removeClstnsByJref", "jref=" + to_string(jref));
};

void XchgWdbecmbd::findJrefsByCall(
			Call* call
			, vector<ubigint>& jrefTrigs
			, vector<ubigint>& jrefs
			, vector<uint>& icsVTarget
			, vector<uint>& icsVJactype
		) {
	Clstn* clstn = NULL;

	set<ubigint> jrefsClissrv;

	ubigint jrefTrig;
	bool match;

	rwmJobs.rlock("XchgWdbecmbd", "findJrefsByCall", "jref=" + to_string(call->jref));
	rwmClstns.rlock("XchgWdbecmbd", "findJrefsByCall", "jref=" + to_string(call->jref));

	jrefsClissrv = getCsjobClisByJref(call->jref);
	jrefsClissrv.insert(call->jref);

	auto rng = clstns.equal_range(clstnref_t(call->ixVCall, 0));
	for (auto it = rng.first; it != rng.second; it++) {
		clstn = it->second;

		jrefTrig = call->jref;

		if (clstn->cref.ixVTarget == Clstn::VecVTarget::JOB) {
			match = true;

			if (clstn->cref.arg.mask & Arg::IX) if (clstn->cref.arg.ix != call->argInv.ix) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::REF) if (clstn->cref.arg.ref != call->argInv.ref) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::SREF) if (clstn->cref.arg.sref != call->argInv.sref) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::INTVAL) if (clstn->cref.arg.intval != call->argInv.intval) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::DBLVAL) if (clstn->cref.arg.dblval != call->argInv.dblval) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::BOOLVAL) if (clstn->cref.arg.boolval != call->argInv.boolval) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::TXTVAL) if (clstn->cref.arg.txtval != call->argInv.txtval) match = false;

			if (match) if (clstn->cref.ixVSge != 0) if (clstn->cref.ixVSge != jobinfos[clstn->cref.jref]->ixVSge) match = false;

			if (match) {
				match = false;

				if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::ALL) {
					// don't care about jrefsClissrv
					match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::IMM) {
					for (auto it = jrefsClissrv.begin(); it != jrefsClissrv.end(); it++) {
						// check if trigger job is immediate sub-job to listener job
						if (clstn->cref.jref == jobinfos[*it]->jrefSup) {
							jrefTrig = *it;
							match = true;
							break;
						};
					};

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SELF) {
					// check if trigger job is equivalent to listener job
					if (clstn->cref.jref == call->jref) match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SPEC) {
					for (auto it = jrefsClissrv.begin(); it != jrefsClissrv.end(); it++) {
						// require specific jref
						if (clstn->cref.jrefTrig == (*it)) {
							jrefTrig = *it;
							match = true;
							break;
						};
					};

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::TREE) {
					if (clstn->cref.jref == call->jref) match = true;
					else {
						for (auto it = jrefsClissrv.begin(); it != jrefsClissrv.end(); it++) {
							// check if trigger job is down the tree from listener job
							if (getJobSup(clstn->cref.jref, *it)) {
								jrefTrig = *it;
								match = true;
								break;
							};
						};
					};
				};
			};

			if (match) {
				jrefTrigs.push_back(jrefTrig);
				jrefs.push_back(clstn->cref.jref);
				icsVTarget.push_back(clstn->cref.ixVTarget);
				icsVJactype.push_back(clstn->ixVJactype);
			};

		} else if (clstn->cref.ixVTarget == Clstn::VecVTarget::STMGR) {
			jrefTrigs.push_back(jrefTrig);
			jrefs.push_back(clstn->cref.jref);
			icsVTarget.push_back(clstn->cref.ixVTarget);
			icsVJactype.push_back(0);

		} else {
			// targets DDSPUB and UASRV
			match = true;

			if (clstn->cref.arg.mask & Arg::SREF) if (clstn->cref.arg.sref != call->argInv.sref) match = false;

			if (match) if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SPEC) {
				match = false;

				for (auto it = jrefsClissrv.begin(); it != jrefsClissrv.end(); it++) {
					// require specific jref
					if (clstn->cref.jrefTrig == (*it)) {
						jrefTrig = *it;
						match = true;
						break;
					};
				};
			};

			if (match) {
				jrefTrigs.push_back(jrefTrig);
				jrefs.push_back(clstn->cref.jref);
				icsVTarget.push_back(clstn->cref.ixVTarget);
				icsVJactype.push_back(0);
			};
		};
	};

	rwmClstns.runlock("XchgWdbecmbd", "findJrefsByCall", "jref=" + to_string(call->jref));
	rwmJobs.runlock("XchgWdbecmbd", "findJrefsByCall", "jref=" + to_string(call->jref));
};

void XchgWdbecmbd::triggerCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	vector<ubigint> jrefTrigs;
	vector<ubigint> jrefs;
	vector<uint> icsVTarget;
	vector<uint> icsVJactype;

	uint ixVTarget;
	ubigint jref;
	uint ixVJactype;

	JobWdbe* job = NULL;

	StmgrWdbe* stmgr = NULL;

	ubigint eref;

	Arg argRet_old;

	eref = mon.eventTriggerCall(call->jref, VecWdbeVCall::getSref(call->ixVCall), call->argInv);

	findJrefsByCall(call, jrefTrigs, jrefs, icsVTarget, icsVJactype);

	for (unsigned int i = 0; i < jrefs.size(); i++) {
		call->jref = jrefTrigs[i];
		jref = jrefs[i];
		ixVTarget = icsVTarget[i];
		ixVJactype = icsVJactype[i];

		if (ixVTarget == Clstn::VecVTarget::JOB) {
			job = getJobByJref(jref);
			if (job) {
				if (ixVJactype != Clstn::VecVJactype::WEAK) {
					if (ixVJactype == Clstn::VecVJactype::LOCK) {
						job->lockAccess("XchgWdbecmbd", "triggerCall");

					} else if (ixVJactype == Clstn::VecVJactype::TRY) {
						if (!job->trylockAccess("XchgWdbecmbd", "triggerCall")) continue;
					};
				};

				mon.eventHandleCall(eref, jref);
				argRet_old = call->argRet;

				job->handleCall(dbswdbe, call);

				if (call->argRet != argRet_old) mon.eventRetCall(eref, jref, call->argRet);
			};

			if (ixVJactype != Clstn::VecVJactype::WEAK) {
				job = getJobByJref(jref);
				if (job) job->unlockAccess("XchgWdbecmbd", "triggerCall");
			};

		} else if (ixVTarget == Clstn::VecVTarget::STMGR) {
			stmgr = getStmgrByJref(jref);

			if (stmgr) {
				mon.eventHandleCall(eref, jref);
				argRet_old = call->argRet;

				stmgr->handleCall(dbswdbe, call);

				if (!(call->argRet == argRet_old)) mon.eventRetCall(eref, jref, call->argRet);

				stmgr->unlockAccess("XchgWdbecmbd", "triggerCall");
			};

		};

		if (call->abort) break;
	};

	mon.eventFinalizeCall(eref);
};

bool XchgWdbecmbd::triggerArgToArgCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const Arg& argInv
			, Arg& argRet
		) {
	Call* call;
	ubigint retval;

	call = new Call(ixWdbeVCall, jref, argInv);
	triggerCall(dbswdbe, call);

	argRet = call->argRet;
	retval = call->abort;

	delete call;
	return retval;
};

bool XchgWdbecmbd::triggerCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
		) {
	Arg argInv;
	Arg argRet;

	return(triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet));
};

bool XchgWdbecmbd::triggerIxCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const uint ixInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, "", Arg::IX);
	Arg argRet;

	return(triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet));
};

bool XchgWdbecmbd::triggerRefCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const ubigint refInv
		) {
	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	return(triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet));
};

bool XchgWdbecmbd::triggerIntvalCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const int intvalInv
		) {
	Arg argInv(0, 0, {}, "", intvalInv, 0.0, false, "", Arg::INTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet));
};

bool XchgWdbecmbd::triggerBoolvalCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const bool boolvalInv
		) {
	Arg argInv(0, 0, {}, "", 0, 0.0, boolvalInv, "", Arg::BOOLVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet));
};

bool XchgWdbecmbd::triggerIxRefCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
		) {
	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	return(triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet));
};

bool XchgWdbecmbd::triggerIxSrefCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const uint ixInv
			, const string& srefInv
		) {
	Arg argInv(ixInv, 0, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::SREF);
	Arg argRet;

	return(triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet));
};

bool XchgWdbecmbd::triggerIxSrefToIxCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const uint ixInv
			, const string& srefInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(ixInv, 0, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;
	
	return retval;
};

bool XchgWdbecmbd::triggerIxIntvalCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const uint ixInv
			, const int intvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", intvalInv, 0.0, false, "", Arg::IX + Arg::INTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet));
};

bool XchgWdbecmbd::triggerIxDblvalCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const uint ixInv
			, const double dblvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, dblvalInv, false, "", Arg::IX + Arg::DBLVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet));
};

bool XchgWdbecmbd::triggerIxTxtvalCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const uint ixInv
			, const string& txtvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, txtvalInv, Arg::IX + Arg::TXTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet));
};

bool XchgWdbecmbd::triggerSrefCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const string& srefInv
		) {
	Arg argInv(0, 0, {}, srefInv, 0, 0.0, false, "", Arg::SREF);
	Arg argRet;

	return(triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet));
};

bool XchgWdbecmbd::triggerToBoolvalCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv;
	Arg argRet;

	retval = triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgWdbecmbd::triggerIxToBoolvalCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, "", Arg::IX);
	Arg argRet;

	retval = triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgWdbecmbd::triggerRefToSrefCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const ubigint refInv
			, string& srefRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet);

	if (!retval) srefRet = argRet.sref;

	return(retval);
};

bool XchgWdbecmbd::triggerRefToBoolvalCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgWdbecmbd::triggerIxRefToIxCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;

	return(retval);
};

bool XchgWdbecmbd::triggerIxRefToRefCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

bool XchgWdbecmbd::triggerIxRefSrefCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet);

	return(retval);
};

bool XchgWdbecmbd::triggerIxRefSrefIntvalCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, intvalInv, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF + Arg::INTVAL);
	Arg argRet;

	retval = triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet);

	return(retval);
};

bool XchgWdbecmbd::triggerIxRefSrefIntvalToRefCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, intvalInv, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF + Arg::INTVAL);
	Arg argRet;

	retval = triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

bool XchgWdbecmbd::triggerRefToIxCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;

	return(retval);
};

bool XchgWdbecmbd::triggerSrefToRefCall(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCall
			, const ubigint jref
			, const string& srefInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(0, 0, {}, srefInv, 0, 0.0, false, "", Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswdbe, ixWdbeVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

DcolWdbe* XchgWdbecmbd::addDcol(
			const ubigint jref
		) {
	JobWdbe* job = NULL;

	DcolWdbe* dcol = NULL;

	// create new dcol and append to dcol list
	rwmJobs.rlock("XchgWdbecmbd", "addDcol", "jref=" + to_string(jref));

	job = getJobByJref(jref);

	if (job) {
		dcol = getDcolByJref(jref);

		if (!dcol) {
			rwmDcols.wlock("XchgWdbecmbd", "addDcol", "jref=" + to_string(jref));

			dcol = new DcolWdbe(jref, job->ixWdbeVLocale);
			dcols[jref] = dcol;

			dcol->lockAccess("XchgWdbecmbd", "addDcol");

			rwmDcols.wunlock("XchgWdbecmbd", "addDcol", "jref=" + to_string(jref));

			mon.eventAddDcol(jref);
		};
	};

	rwmJobs.runlock("XchgWdbecmbd", "addDcol", "jref=" + to_string(jref));

	// make dcol the session's active notify dcol
	triggerIxRefCall(NULL, VecWdbeVCall::CALLWDBEREFPRESET, jref, VecWdbeVPreset::PREWDBEJREFNOTIFY, jref);

	return(dcol);
};

DcolWdbe* XchgWdbecmbd::getDcolByJref(
			ubigint jref
			, const bool tree
		) {
	Jobinfo* jobinfo = NULL;

	DcolWdbe* dcol = NULL;

	rwmJobs.rlock("XchgWdbecmbd", "getDcolByJref", "jref=" + to_string(jref));
	rwmDcols.rlock("XchgWdbecmbd", "getDcolByJref", "jref=" + to_string(jref));

	jobinfo = getJobinfoByJref(jref);

	while (jobinfo != NULL) {
		auto it = dcols.find(jref);

		if (it != dcols.end()) {
			dcol = it->second;
			dcol->lockAccess("XchgWdbecmbd", "getDcolByJref");

			break;
		};

		if (!tree) break;

		jref = jobinfo->jrefSup;
		jobinfo = getJobinfoByJref(jref);
	};

	rwmDcols.runlock("XchgWdbecmbd", "getDcolByJref", "jref=" + to_string(jref));
	rwmJobs.runlock("XchgWdbecmbd", "getDcolByJref", "jref=" + to_string(jref));

	return(dcol);
};

void XchgWdbecmbd::removeDcolByJref(
			const ubigint jref
		) {
	rwmDcols.wlock("XchgWdbecmbd", "removeDcolByJref", "jref=" + to_string(jref));

	auto it = dcols.find(jref);
	if (it != dcols.end()) {
		delete it->second;
		dcols.erase(it);

		mon.eventRemoveDcol(jref);
	};

	rwmDcols.wunlock("XchgWdbecmbd", "removeDcolByJref", "jref=" + to_string(jref));
};

void XchgWdbecmbd::removeDcolsByJref(
			const ubigint jref
		) {
	Jobinfo* jobinfo = NULL;

	vector<ubigint> jrefs;

	rwmJobs.rlock("XchgWdbecmbd", "removeDcolsByJref", "jref=" + to_string(jref));
	rwmDcols.wlock("XchgWdbecmbd", "removeDcolsByJref", "jref=" + to_string(jref));

	jrefs.push_back(jref);

	// sub-tree without recursion
	for (unsigned int i = 0; i < jrefs.size(); i++) {
		jobinfo = getJobinfoByJref(jrefs[i]);

		if (jobinfo) for (auto it = jobinfo->jrefsSub.begin(); it != jobinfo->jrefsSub.end(); it++) jrefs.push_back(*it);
	};

	for (unsigned int i = 0; i < jrefs.size(); i++) {
		auto it = dcols.find(jrefs[i]);
		if (it != dcols.end()) {
			delete it->second;
			dcols.erase(it);

			mon.eventRemoveDcol(jrefs[i]);
		};
	};

	rwmDcols.wunlock("XchgWdbecmbd", "removeDcolsByJref", "jref=" + to_string(jref));
	rwmJobs.runlock("XchgWdbecmbd", "removeDcolsByJref", "jref=" + to_string(jref));
};

void XchgWdbecmbd::submitDpch(
			DpchEngWdbe* dpcheng
		) {
	DcolWdbe* dcol = NULL;

	Cond* cReady_backup;

	DpchEngWdbe* dpchtest;

	// find dcol in charge
	dcol = getDcolByJref(dpcheng->jref);

	if (dcol) {
		mon.eventSubmitDpch(dpcheng->jref, VecWdbeVDpch::getSref(dpcheng->ixWdbeVDpch), dpcheng->getSrefsMask(), "");

		if (dcol->req != NULL) {
			// a request is waiting
			delete dcol->req->dpcheng;
			dcol->req->dpcheng = dpcheng;

			cReady_backup = &(dcol->req->cReady);

			dcol->req = NULL;
			//cout << "XchgWdbecmbd::submitDpch() waiting request for ixWdbeVDpch = " << dpcheng->ixWdbeVDpch << ", jref = " << dpcheng->jref << endl;

			cReady_backup->signal("XchgWdbecmbd", "submitDpch", "jref=" + to_string(dcol->jref));

			dcol->unlockAccess("XchgWdbecmbd", "submitDpch");

		} else {
			// merge with similar dispatch if available
			for (auto it = dcol->dpchs.begin(); it != dcol->dpchs.end();) {
				dpchtest = *it;

				if ((dpchtest->ixWdbeVDpch == dpcheng->ixWdbeVDpch) && (dpchtest->jref == dpcheng->jref)) {
					dpchtest->merge(dpcheng);
					//cout << "XchgWdbecmbd::submitDpch() merge for ixWdbeVDpch = " << dpcheng->ixWdbeVDpch << ", jref = " << dpcheng->jref << endl;

					delete dpcheng;
					dpcheng = NULL;

					break;

				} else it++;
			};

			// append to list of dispatches
			if (dpcheng) {
				dcol->dpchs.push_back(dpcheng);
				//cout << "XchgWdbecmbd::submitDpch() append for ixWdbeVDpch = " << dpcheng->ixWdbeVDpch << ", jref = " << dpcheng->jref << endl;
			};

			dcol->unlockAccess("XchgWdbecmbd", "submitDpch");
		};

	} else {
		delete dpcheng;
	};
};

DpchEngWdbe* XchgWdbecmbd::pullFirstDpch(
			DcolWdbe* dcol
		) {
	DpchEngWdbe* dpcheng = NULL;

	// get first element from list ; assume access is locked
	if (!dcol->dpchs.empty()) {
		dpcheng = *(dcol->dpchs.begin());
		dcol->dpchs.pop_front();
	};

	return dpcheng;
};

ubigint XchgWdbecmbd::addJob(
			DbsWdbe* dbswdbe
			, JobWdbe* job
			, const ubigint jrefSup
		) {
	CsjobWdbe* csjob = NULL;
	Csjobinfo* csjobinfo = NULL;

	bool csjobNotJob = getCsjobNotJob(job->ixWdbeVJob);
	bool srvNotCli = false;

	// get new jref and append to job list
	rwmJobs.wlock("XchgWdbecmbd", "addJob", "jrefSup=" + to_string(jrefSup));

	job->jref = jrefseq.getNewRef();
	jobs[job->jref] = job;

	if (jobs.size() == 1) {
		// root job
		jrefRoot = job->jref;
		jrefCmd = job->jref;
	};

	ixWdbeVJobs[job->jref] = job->ixWdbeVJob;
	jobinfos[job->jref] = new Jobinfo(jrefSup);

	if (jrefSup != 0) jobinfos[jrefSup]->jrefsSub.insert(job->jref);

	if (csjobNotJob) {
		rwmCsjobinfos.wlock("XchgWdbecmbd", "addJob", "jref=" + to_string(job->jref));

		csjob = (CsjobWdbe*) job;
		csjobinfo = csjobinfos[job->ixWdbeVJob];

		if (jrefSup == jrefRoot) {
			csjob->srvNotCli = true;
			srvNotCli = true;
			
			csjobinfo->jrefSrv = job->jref;
			for (auto it = csjobinfo->jrefsCli.begin(); it != csjobinfo->jrefsCli.end(); it++) {
				jobs[*it]->ixVSge = job->ixVSge;
				((CsjobWdbe*) (jobs[*it]))->srv = csjob;
			};

		} else {
			csjob->srvNotCli = false;
			
			if (csjobinfo->jrefSrv != 0) {
				job->ixVSge = jobs[csjobinfo->jrefSrv]->ixVSge;
				csjob->srv = (CsjobWdbe*) jobs[csjobinfo->jrefSrv];
			};
			csjobinfo->jrefsCli.insert(job->jref);
		};

		rwmCsjobinfos.wunlock("XchgWdbecmbd", "addJob", "jref=" + to_string(job->jref));
	};

	rwmJobs.wunlock("XchgWdbecmbd", "addJob", "jref=" + to_string(job->jref));

	mon.eventAddJob(jrefSup, VecWdbeVJob::getSref(job->ixWdbeVJob), job->jref, csjobNotJob, srvNotCli);

	return(job->jref);
};

JobWdbe* XchgWdbecmbd::getJobByJref(
			const ubigint jref
		) {
	JobWdbe* job = NULL;

	rwmJobs.rlock("XchgWdbecmbd", "getJobByJref", "jref=" + to_string(jref));

	auto it = jobs.find(jref);
	if (it != jobs.end()) job = it->second;

	rwmJobs.runlock("XchgWdbecmbd", "getJobByJref", "jref=" + to_string(jref));

	return job;
};

Jobinfo* XchgWdbecmbd::getJobinfoByJref(
			const ubigint jref
		) {
	Jobinfo* jobinfo = NULL;

	rwmJobs.rlock("XchgWdbecmbd", "getJobinfoByJref", "jref=" + to_string(jref));

	auto it = jobinfos.find(jref);
	if (it != jobinfos.end()) jobinfo = it->second;

	rwmJobs.runlock("XchgWdbecmbd", "getJobinfoByJref", "jref=" + to_string(jref));

	return jobinfo;
};

void XchgWdbecmbd::removeJobByJref(
			const ubigint jref
		) {
	JobWdbe* job = NULL;
	Jobinfo* jobinfo = NULL;

	CsjobWdbe* csjob = NULL;
	Csjobinfo* csjobinfo = NULL;

	bool csjobNotJob;

	rwmJobs.rlock("XchgWdbecmbd", "removeJobByJref[1]", "jref=" + to_string(jref));

	job = getJobByJref(jref);

	if (job) {
 		csjobNotJob = getCsjobNotJob(job->ixWdbeVJob);

		job->invalidateWakeups();

		removePresetsByJref(jref);
		removeStmgrByJref(jref);
		removeClstnsByJref(jref);
		removeDcolByJref(jref);

		if (csjobNotJob) {
			rwmCsjobinfos.rlock("XchgWdbecmbd", "removeJobByJref[1]", "jref=" + to_string(jref));

			csjob = (CsjobWdbe*) job;
			csjobinfo = csjobinfos[job->ixWdbeVJob];

			removeCsjobClaim(NULL, csjob);

			rwmCsjobinfos.runlock("XchgWdbecmbd", "removeJobByJref[1]", "jref=" + to_string(jref));

			rwmCsjobinfos.wlock("XchgWdbecmbd", "removeJobByJref[2]", "jref=" + to_string(jref));

			if (csjob->srvNotCli) {
				csjobinfo->jrefSrv = 0;
				for (auto it = csjobinfo->jrefsCli.begin(); it != csjobinfo->jrefsCli.end(); it++) ((CsjobWdbe*) (jobs[*it]))->srv = NULL;

			} else csjobinfo->jrefsCli.erase(jref);

			rwmCsjobinfos.wunlock("XchgWdbecmbd", "removeJobByJref[2]", "jref=" + to_string(jref));
		};

		jobinfo = jobinfos[jref];

		rwmJobs.runlock("XchgWdbecmbd", "removeJobByJref[1]", "jref=" + to_string(jref));

		rwmJobs.wlock("XchgWdbecmbd", "removeJobByJref[2]", "jref=" + to_string(jref));

		if (jobinfo->jrefSup != 0) jobinfos[jobinfo->jrefSup]->jrefsSub.erase(jref);

		rwmJobs.wunlock("XchgWdbecmbd", "removeJobByJref[2]", "jref=" + to_string(jref));

		while (jobinfo->jrefsSub.size() > 0) delete jobs[*(jobinfo->jrefsSub.begin())];

		rwmJobs.wlock("XchgWdbecmbd", "removeJobByJref[3]", "jref=" + to_string(jref));

		// remove job from list only here otherwise sub-job delete will loop forever
		jobs.erase(jref);

		delete jobinfo;
		jobinfos.erase(jref);

		ixWdbeVJobs.erase(jref);

		if (jobs.empty()) {
			// root job
			jrefRoot = 0;
			jrefCmd = 0;
		};

		rwmJobs.wunlock("XchgWdbecmbd", "removeJobByJref[3]", "jref=" + to_string(jref));

		mon.eventRemoveJob(jref);

	} else rwmJobs.wunlock("XchgWdbecmbd", "removeJobByJref[4]", "jref=" + to_string(jref));
};

bool XchgWdbecmbd::getJobSup(
			const ubigint jrefSup
			, ubigint jref
		) {
	bool retval = false;

	Jobinfo* jobinfo = NULL;

	jobinfo = getJobinfoByJref(jref);

	while (jobinfo) {
		if (jobinfo->jrefSup == jrefSup) {
			retval = true;
			break;
		};

		jref = jobinfo->jrefSup;
		jobinfo = getJobinfoByJref(jref);
	};

	return retval;
};

void XchgWdbecmbd::setJobStage(
			DbsWdbe* dbswdbe
			, JobWdbe* job
			, const uint ixVSge
		) {
	set<ubigint> jrefsCli;

	bool csjobNotJob = getCsjobNotJob(job->ixWdbeVJob);

	rwmJobs.rlock("XchgWdbecmbd", "setJobStage", "jref=" + to_string(job->jref));
	if (csjobNotJob) rwmCsjobinfos.rlock("XchgWdbecmbd", "setJobStage", "jref=" + to_string(job->jref));

	jobinfos[job->jref]->ixVSge = ixVSge;
	job->ixVSge = ixVSge;
	
	if (csjobNotJob) {
		jrefsCli = getCsjobClisByJref(job->jref);
		
		for (auto it = jrefsCli.begin(); it != jrefsCli.end(); it++) {
			jobinfos[*it]->ixVSge = ixVSge;
			jobs[*it]->ixVSge = ixVSge;
		};
	};

	if (csjobNotJob) rwmCsjobinfos.runlock("XchgWdbecmbd", "setJobStage", "jref=" + to_string(job->jref));
	rwmJobs.runlock("XchgWdbecmbd", "setJobStage", "jref=" + to_string(job->jref));

	triggerIxCall(dbswdbe, VecWdbeVCall::CALLWDBESGECHG, job->jref, ixVSge);
};

void XchgWdbecmbd::addCsjobClaim(
			DbsWdbe* dbswdbe
			, CsjobWdbe* csjob
			, Claim* claim
		) {
	Csjobinfo* csjobinfo = NULL;;

	bool mod;

	if (!csjob->srvNotCli && csjob->srv) {
		rwmCsjobinfos.rlock("XchgWdbecmbd", "addCsjobClaim", "jref=" + to_string(csjob->jref));

		csjobinfo = csjobinfos[csjob->ixWdbeVJob];

		rwmCsjobinfos.runlock("XchgWdbecmbd", "addCsjobClaim", "jref=" + to_string(csjob->jref));

		csjob->srv->lockAccess("XchgWdbecmbd", "addCsjobClaim");

		csjobinfo->mClaims.wlock("XchgWdbecmbd", "addCsjobClaim", "jref=" + to_string(csjob->jref));

		auto it = csjobinfo->claims.find(csjob->jref);
		if (it != csjobinfo->claims.end()) delete it->second;

		csjobinfo->claims[csjob->jref] = claim;

		mod = csjob->srv->handleClaim(dbswdbe, csjobinfo->claims, csjob->jref);

		csjobinfo->mClaims.wunlock("XchgWdbecmbd", "addCsjobClaim", "jref=" + to_string(csjob->jref));

		csjob->srv->unlockAccess("XchgWdbecmbd", "addCsjobClaim");

		if (mod) triggerCall(dbswdbe, VecWdbeVCall::CALLWDBECLAIMCHG, csjob->jref);
	};
};

bool XchgWdbecmbd::getCsjobClaim(
			CsjobWdbe* csjob
			, bool& takenNotAvailable
			, bool& fulfilled
			, bool& run
		) {
	bool retval = false;

	Csjobinfo* csjobinfo = NULL;;

	takenNotAvailable = false;
	fulfilled = false;
	run = false;

	if (!csjob->srvNotCli && csjob->srv) {
		rwmCsjobinfos.rlock("XchgWdbecmbd", "getCsjobClaim", "jref=" + to_string(csjob->jref));

		csjobinfo = csjobinfos[csjob->ixWdbeVJob];

		csjobinfo->mClaims.rlock("XchgWdbecmbd", "getCsjobClaim", "jref=" + to_string(csjob->jref));

		auto it = csjobinfo->claims.find(csjob->jref);
		retval = (it != csjobinfo->claims.end());

		if (retval) {
			takenNotAvailable = it->second->takenNotAvailable;
			fulfilled = it->second->fulfilled;
			run = it->second->run;
		};

		csjobinfo->mClaims.runlock("XchgWdbecmbd", "getCsjobClaim", "jref=" + to_string(csjob->jref));

		rwmCsjobinfos.runlock("XchgWdbecmbd", "getCsjobClaim", "jref=" + to_string(csjob->jref));
	};

	return retval;
};

bool XchgWdbecmbd::getCsjobClaim(
			CsjobWdbe* csjob
			, bool& takenNotAvailable
			, bool& fulfilled
		) {
	bool run;

	return getCsjobClaim(csjob, takenNotAvailable, fulfilled, run);
};

void XchgWdbecmbd::clearCsjobRun(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVJob
		) {
	Csjobinfo* csjobinfo = NULL;
	Claim* claim = NULL;

	bool mod = false;

	rwmCsjobinfos.rlock("XchgWdbecmbd", "clearCsjobRun", "srefIxWdbeVJob=" + VecWdbeVJob::getSref(ixWdbeVJob));

	auto it = csjobinfos.find(ixWdbeVJob);
	if (it != csjobinfos.end()) csjobinfo = it->second;

	rwmCsjobinfos.runlock("XchgWdbecmbd", "clearCsjobRun", "srefIxWdbeVJob=" + VecWdbeVJob::getSref(ixWdbeVJob));

	if (csjobinfo) {
		csjobinfo->mClaims.wlock("XchgWdbecmbd", "clearCsjobRun", "srefIxWdbeVJob=" + VecWdbeVJob::getSref(ixWdbeVJob));

		for (auto it2 = csjobinfo->claims.begin(); it2 != csjobinfo->claims.end(); it2++) {
			claim = it2->second;

			if (claim->run) {
				claim->run = false;
				mod = true;
			};
		};

		csjobinfo->mClaims.wunlock("XchgWdbecmbd", "clearCsjobRun", "srefIxWdbeVJob=" + VecWdbeVJob::getSref(ixWdbeVJob));

		if (mod) triggerCall(dbswdbe, VecWdbeVCall::CALLWDBECLAIMCHG, csjobinfo->jrefSrv);
	};
};

void XchgWdbecmbd::removeCsjobClaim(
			DbsWdbe* dbswdbe
			, CsjobWdbe* csjob
		) {
	Csjobinfo* csjobinfo = NULL;;

	bool mod = false;

	if (!csjob->srvNotCli && csjob->srv) {
		rwmCsjobinfos.rlock("XchgWdbecmbd", "removeCsjobClaim", "jref=" + to_string(csjob->jref));

		csjobinfo = csjobinfos[csjob->ixWdbeVJob];

		rwmCsjobinfos.runlock("XchgWdbecmbd", "removeCsjobClaim", "jref=" + to_string(csjob->jref));

		csjob->srv->lockAccess("XchgWdbecmbd", "removeCsjobClaim");

		csjobinfo->mClaims.wlock("XchgWdbecmbd", "removeCsjobClaim", "jref=" + to_string(csjob->jref));

		auto it = csjobinfo->claims.find(csjob->jref);
		if (it != csjobinfo->claims.end()) {
			delete it->second;
			csjobinfo->claims.erase(it);

			mod = csjob->srv->handleClaim(dbswdbe, csjobinfo->claims, 0);
		};

		csjobinfo->mClaims.wunlock("XchgWdbecmbd", "removeCsjobClaim", "jref=" + to_string(csjob->jref));

		csjob->srv->unlockAccess("XchgWdbecmbd", "removeCsjobClaim");

		if (mod) triggerCall(dbswdbe, VecWdbeVCall::CALLWDBECLAIMCHG, csjobinfo->jrefSrv);
	};
};

bool XchgWdbecmbd::getCsjobNotJob(
			const uint ixWdbeVJob
		) {
	bool retval;

	rwmCsjobinfos.rlock("XchgWdbecmbd", "getCsjobNotJob", "srefIxWdbeVJob=" + VecWdbeVJob::getSref(ixWdbeVJob));

	retval = (csjobinfos.find(ixWdbeVJob) != csjobinfos.end());

	rwmCsjobinfos.runlock("XchgWdbecmbd", "getCsjobNotJob", "srefIxWdbeVJob=" + VecWdbeVJob::getSref(ixWdbeVJob));

	return retval;
};

set<ubigint> XchgWdbecmbd::getCsjobClisByJref(
			const ubigint jref
		) {
	set<ubigint> retval;

	rwmCsjobinfos.rlock("XchgWdbecmbd", "getCsjobClis", "jref=" + to_string(jref));

	auto it = csjobinfos.find(ixWdbeVJobs[jref]);
	
	if (it != csjobinfos.end()) retval = it->second->jrefsCli;

	rwmCsjobinfos.runlock("XchgWdbecmbd", "getCsjobClis", "jref=" + to_string(jref));

	return retval;
};

ubigint XchgWdbecmbd::addWakeup(
			const ubigint jref
			, const string sref
			, const uint64_t deltat
			, const bool weak
		) {
	int res;

	ubigint wref;

	pthread_t timer;

	wref = wrefseq.getNewRef();

	if (deltat == 0) {
		// immediate callback: generate request to be treated by job processor
		ReqWdbe* req = new ReqWdbe(ReqWdbe::VecVBasetype::TIMER);
		req->jref = jref;
		req->wref = wref;
		req->sref = sref;
		req->weak = false;

		addReq(req);

	} else {
		// delayed callback: generate dedicated wait thread
		WakeupWdbe* wakeup = new WakeupWdbe(this, wref, jref, sref, deltat, weak);

		for (unsigned int i = 0; i < 3; i++) {
			res = pthread_create(&timer, NULL, &runWakeup, (void*) wakeup);
			if ((res == 0) || (res != EAGAIN)) break;
		};
		if (res != 0) cout << "XchgWdbecmbd::addWakeup() error creating timer thread (" << res << ")" << endl;
		else {
			res = pthread_detach(timer);
			if (res != 0) cout << "XchgWdbecmbd::addWakeup() error detaching timer thread (" << res << ")" << endl;
		};
	};

	return(wref);
};

void* XchgWdbecmbd::runWakeup(
			void* arg
		) {
	WakeupWdbe* wakeup = (WakeupWdbe*) arg;

	// wait for time specified in microseconds
	timespec deltat;
	deltat.tv_sec = wakeup->deltat / 1000000;
	deltat.tv_nsec = 1000 * (wakeup->deltat%1000000);
#ifdef _WIN32
	usleep(wakeup->deltat);
#else
	nanosleep(&deltat, NULL);
#endif

	// generate request to be treated by job processor
	ReqWdbe* req = new ReqWdbe(ReqWdbe::VecVBasetype::TIMER);
	req->jref = wakeup->jref;
	req->wref = wakeup->wref;
	req->sref = wakeup->sref;
	req->weak = wakeup->weak;

	wakeup->xchg->addReq(req);

	delete wakeup;

	return(NULL);
};

void XchgWdbecmbd::runExtcall(
			void* arg
		) {
	ExtcallWdbe* extcall = (ExtcallWdbe*) arg;

	// generate request to be treated by job processor
	ReqWdbe* req = new ReqWdbe(ReqWdbe::VecVBasetype::EXTCALL);
	req->call = new Call(*(extcall->call));

	extcall->xchg->addReq(req);
};
