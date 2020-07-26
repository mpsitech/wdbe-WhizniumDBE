/**
	* \file WdbeQTrgList.cpp
	* API code for table TblWdbeQTrgList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeQTrgList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQTrgList
 ******************************************************************************/

WdbeQTrgList::WdbeQTrgList(
			const uint jnum
			, const string sref
			, const string stubSysRefWdbeMSystem
			, const string stubRefWdbeMUnit
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubSysRefWdbeMSystem = stubSysRefWdbeMSystem;
	this->stubRefWdbeMUnit = stubRefWdbeMUnit;
};

bool WdbeQTrgList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQTrgList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubSysRefWdbeMSystem", "sys", stubSysRefWdbeMSystem);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMUnit", "unt", stubRefWdbeMUnit);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQTrgList
 ******************************************************************************/

ListWdbeQTrgList::ListWdbeQTrgList() {
};

ListWdbeQTrgList::ListWdbeQTrgList(
			const ListWdbeQTrgList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQTrgList(*(src.nodes[i]));
};

ListWdbeQTrgList& ListWdbeQTrgList::operator=(
			const ListWdbeQTrgList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQTrgList(*(src.nodes[i]));

	return *this;
};

ListWdbeQTrgList::~ListWdbeQTrgList() {
	clear();
};

void ListWdbeQTrgList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQTrgList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQTrgList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQTrgList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQTrgList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQTrgList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQTrgList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

