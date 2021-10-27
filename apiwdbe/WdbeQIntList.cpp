/**
	* \file WdbeQIntList.cpp
	* API code for table TblWdbeQIntList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeQIntList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQIntList
 ******************************************************************************/

WdbeQIntList::WdbeQIntList(
			const uint jnum
			, const string sref
			, const string stubRefWdbeMUnit
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubRefWdbeMUnit = stubRefWdbeMUnit;
};

bool WdbeQIntList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQIntList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMUnit", "unt", stubRefWdbeMUnit);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQIntList
 ******************************************************************************/

ListWdbeQIntList::ListWdbeQIntList() {
};

ListWdbeQIntList::ListWdbeQIntList(
			const ListWdbeQIntList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQIntList(*(src.nodes[i]));
};

ListWdbeQIntList& ListWdbeQIntList::operator=(
			const ListWdbeQIntList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQIntList(*(src.nodes[i]));

	return *this;
};

ListWdbeQIntList::~ListWdbeQIntList() {
	clear();
};

void ListWdbeQIntList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQIntList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQIntList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQIntList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQIntList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQIntList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQIntList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
