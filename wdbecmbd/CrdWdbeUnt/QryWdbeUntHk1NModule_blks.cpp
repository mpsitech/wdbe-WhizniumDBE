/**
	* \file QryWdbeUntHk1NModule_blks.cpp
	* job handler for job QryWdbeUntHk1NModule (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class QryWdbeUntHk1NModule::StatApp
 ******************************************************************************/

void QryWdbeUntHk1NModule::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint firstcol
			, const uint jnumFirstdisp
			, const uint ncol
			, const uint ndisp
		) {
	if (difftag.length() == 0) difftag = "StatAppQryWdbeUntHk1NModule";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["firstcol"] = firstcol;
	me["jnumFirstdisp"] = jnumFirstdisp;
	me["ncol"] = ncol;
	me["ndisp"] = ndisp;
};

void QryWdbeUntHk1NModule::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint firstcol
			, const uint jnumFirstdisp
			, const uint ncol
			, const uint ndisp
		) {
	if (difftag.length() == 0) difftag = "StatAppQryWdbeUntHk1NModule";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppQryWdbeUntHk1NModule";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "firstcol", firstcol);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstdisp", jnumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "ncol", ncol);
		writeUintAttr(wr, itemtag, "sref", "ndisp", ndisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class QryWdbeUntHk1NModule::StatShr
 ******************************************************************************/

QryWdbeUntHk1NModule::StatShr::StatShr(
			const uint ntot
			, const uint jnumFirstload
			, const uint nload
		) :
			Block()
		{
	this->ntot = ntot;
	this->jnumFirstload = jnumFirstload;
	this->nload = nload;

	mask = {NTOT, JNUMFIRSTLOAD, NLOAD};
};

void QryWdbeUntHk1NModule::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrQryWdbeUntHk1NModule";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ntot"] = ntot;
	me["jnumFirstload"] = jnumFirstload;
	me["nload"] = nload;
};

void QryWdbeUntHk1NModule::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrQryWdbeUntHk1NModule";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrQryWdbeUntHk1NModule";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "ntot", ntot);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstload", jnumFirstload);
		writeUintAttr(wr, itemtag, "sref", "nload", nload);
	xmlTextWriterEndElement(wr);
};

set<uint> QryWdbeUntHk1NModule::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ntot == comp->ntot) insert(items, NTOT);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryWdbeUntHk1NModule::StatShr::diff(
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
 class QryWdbeUntHk1NModule::StgIac
 ******************************************************************************/

QryWdbeUntHk1NModule::StgIac::StgIac(
			const uint jnum
			, const uint jnumFirstload
			, const uint nload
		) :
			Block()
		{
	this->jnum = jnum;
	this->jnumFirstload = jnumFirstload;
	this->nload = nload;
	mask = {JNUM, JNUMFIRSTLOAD, NLOAD};
};

bool QryWdbeUntHk1NModule::StgIac::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["StgIacQryWdbeUntHk1NModule"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("jnum")) {jnum = me["jnum"].asUInt(); add(JNUM);};
		if (me.isMember("jnumFirstload")) {jnumFirstload = me["jnumFirstload"].asUInt(); add(JNUMFIRSTLOAD);};
		if (me.isMember("nload")) {nload = me["nload"].asUInt(); add(NLOAD);};
	};

	return basefound;
};

bool QryWdbeUntHk1NModule::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacQryWdbeUntHk1NModule");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacQryWdbeUntHk1NModule";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnum", jnum)) add(JNUM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstload", jnumFirstload)) add(JNUMFIRSTLOAD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "nload", nload)) add(NLOAD);
	};

	return basefound;
};

void QryWdbeUntHk1NModule::StgIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgIacQryWdbeUntHk1NModule";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["jnum"] = jnum;
	me["jnumFirstload"] = jnumFirstload;
	me["nload"] = nload;
};

void QryWdbeUntHk1NModule::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacQryWdbeUntHk1NModule";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacQryWdbeUntHk1NModule";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "jnum", jnum);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstload", jnumFirstload);
		writeUintAttr(wr, itemtag, "sref", "nload", nload);
	xmlTextWriterEndElement(wr);
};

set<uint> QryWdbeUntHk1NModule::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (jnum == comp->jnum) insert(items, JNUM);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryWdbeUntHk1NModule::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JNUM, JNUMFIRSTLOAD, NLOAD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
