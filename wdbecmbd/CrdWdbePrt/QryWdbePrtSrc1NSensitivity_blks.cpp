/**
	* \file QryWdbePrtSrc1NSensitivity_blks.cpp
	* job handler for job QryWdbePrtSrc1NSensitivity (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class QryWdbePrtSrc1NSensitivity::StatApp
 ******************************************************************************/

void QryWdbePrtSrc1NSensitivity::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint firstcol
			, const uint jnumFirstdisp
			, const uint ncol
			, const uint ndisp
		) {
	if (difftag.length() == 0) difftag = "StatAppQryWdbePrtSrc1NSensitivity";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["firstcol"] = (Json::Value::UInt) firstcol;
	me["jnumFirstdisp"] = (Json::Value::UInt) jnumFirstdisp;
	me["ncol"] = (Json::Value::UInt) ncol;
	me["ndisp"] = (Json::Value::UInt) ndisp;
};

void QryWdbePrtSrc1NSensitivity::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint firstcol
			, const uint jnumFirstdisp
			, const uint ncol
			, const uint ndisp
		) {
	if (difftag.length() == 0) difftag = "StatAppQryWdbePrtSrc1NSensitivity";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppQryWdbePrtSrc1NSensitivity";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "firstcol", firstcol);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstdisp", jnumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "ncol", ncol);
		writeUintAttr(wr, itemtag, "sref", "ndisp", ndisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class QryWdbePrtSrc1NSensitivity::StatShr
 ******************************************************************************/

QryWdbePrtSrc1NSensitivity::StatShr::StatShr(
			const uint ntot
			, const uint jnumFirstload
			, const uint nload
		) :
			Block()
			, ntot(ntot)
			, jnumFirstload(jnumFirstload)
			, nload(nload)
		{
	mask = {NTOT, JNUMFIRSTLOAD, NLOAD};
};

void QryWdbePrtSrc1NSensitivity::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrQryWdbePrtSrc1NSensitivity";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ntot"] = (Json::Value::UInt) ntot;
	me["jnumFirstload"] = (Json::Value::UInt) jnumFirstload;
	me["nload"] = (Json::Value::UInt) nload;
};

void QryWdbePrtSrc1NSensitivity::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrQryWdbePrtSrc1NSensitivity";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrQryWdbePrtSrc1NSensitivity";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "ntot", ntot);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstload", jnumFirstload);
		writeUintAttr(wr, itemtag, "sref", "nload", nload);
	xmlTextWriterEndElement(wr);
};

set<uint> QryWdbePrtSrc1NSensitivity::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ntot == comp->ntot) insert(items, NTOT);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryWdbePrtSrc1NSensitivity::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NTOT, JNUMFIRSTLOAD, NLOAD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class QryWdbePrtSrc1NSensitivity::StgIac
 ******************************************************************************/

QryWdbePrtSrc1NSensitivity::StgIac::StgIac(
			const uint jnum
			, const uint jnumFirstload
			, const uint nload
		) :
			Block()
			, jnum(jnum)
			, jnumFirstload(jnumFirstload)
			, nload(nload)
		{
	mask = {JNUM, JNUMFIRSTLOAD, NLOAD};
};

bool QryWdbePrtSrc1NSensitivity::StgIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["StgIacQryWdbePrtSrc1NSensitivity"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("jnum")) {jnum = me["jnum"].asUInt(); add(JNUM);};
		if (me.isMember("jnumFirstload")) {jnumFirstload = me["jnumFirstload"].asUInt(); add(JNUMFIRSTLOAD);};
		if (me.isMember("nload")) {nload = me["nload"].asUInt(); add(NLOAD);};
	};

	return basefound;
};

bool QryWdbePrtSrc1NSensitivity::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacQryWdbePrtSrc1NSensitivity");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacQryWdbePrtSrc1NSensitivity";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnum", jnum)) add(JNUM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstload", jnumFirstload)) add(JNUMFIRSTLOAD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "nload", nload)) add(NLOAD);
	};

	return basefound;
};

void QryWdbePrtSrc1NSensitivity::StgIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgIacQryWdbePrtSrc1NSensitivity";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["jnum"] = (Json::Value::UInt) jnum;
	me["jnumFirstload"] = (Json::Value::UInt) jnumFirstload;
	me["nload"] = (Json::Value::UInt) nload;
};

void QryWdbePrtSrc1NSensitivity::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacQryWdbePrtSrc1NSensitivity";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacQryWdbePrtSrc1NSensitivity";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "jnum", jnum);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstload", jnumFirstload);
		writeUintAttr(wr, itemtag, "sref", "nload", nload);
	xmlTextWriterEndElement(wr);
};

set<uint> QryWdbePrtSrc1NSensitivity::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (jnum == comp->jnum) insert(items, JNUM);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryWdbePrtSrc1NSensitivity::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JNUM, JNUMFIRSTLOAD, NLOAD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
