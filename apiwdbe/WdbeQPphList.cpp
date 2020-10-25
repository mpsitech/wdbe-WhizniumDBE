/**
	* \file WdbeQPphList.cpp
	* API code for table TblWdbeQPphList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQPphList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPphList
 ******************************************************************************/

WdbeQPphList::WdbeQPphList(
			const uint jnum
			, const string sref
			, const string stubRefWdbeMUnit
			, const string stubRefWdbeMModule
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubRefWdbeMUnit = stubRefWdbeMUnit;
	this->stubRefWdbeMModule = stubRefWdbeMModule;
};

bool WdbeQPphList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQPphList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMUnit", "unt", stubRefWdbeMUnit);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMModule", "mdl", stubRefWdbeMModule);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQPphList
 ******************************************************************************/

ListWdbeQPphList::ListWdbeQPphList() {
};

ListWdbeQPphList::ListWdbeQPphList(
			const ListWdbeQPphList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPphList(*(src.nodes[i]));
};

ListWdbeQPphList& ListWdbeQPphList::operator=(
			const ListWdbeQPphList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPphList(*(src.nodes[i]));

	return *this;
};

ListWdbeQPphList::~ListWdbeQPphList() {
	clear();
};

void ListWdbeQPphList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQPphList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQPphList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQPphList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQPphList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQPphList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQPphList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

