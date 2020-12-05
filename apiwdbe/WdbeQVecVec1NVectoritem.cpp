/**
	* \file WdbeQVecVec1NVectoritem.cpp
	* API code for table TblWdbeQVecVec1NVectoritem (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQVecVec1NVectoritem.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQVecVec1NVectoritem
 ******************************************************************************/

WdbeQVecVec1NVectoritem::WdbeQVecVec1NVectoritem(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQVecVec1NVectoritem::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQVecVec1NVectoritem");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQVecVec1NVectoritem
 ******************************************************************************/

ListWdbeQVecVec1NVectoritem::ListWdbeQVecVec1NVectoritem() {
};

ListWdbeQVecVec1NVectoritem::ListWdbeQVecVec1NVectoritem(
			const ListWdbeQVecVec1NVectoritem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQVecVec1NVectoritem(*(src.nodes[i]));
};

ListWdbeQVecVec1NVectoritem& ListWdbeQVecVec1NVectoritem::operator=(
			const ListWdbeQVecVec1NVectoritem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQVecVec1NVectoritem(*(src.nodes[i]));

	return *this;
};

ListWdbeQVecVec1NVectoritem::~ListWdbeQVecVec1NVectoritem() {
	clear();
};

void ListWdbeQVecVec1NVectoritem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQVecVec1NVectoritem::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQVecVec1NVectoritem* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQVecVec1NVectoritem");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQVecVec1NVectoritem", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQVecVec1NVectoritem(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQVecVec1NVectoritem[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

