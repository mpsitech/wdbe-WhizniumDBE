/**
	* \file WdbeQUntSil1NUnit.cpp
	* API code for table TblWdbeQUntSil1NUnit (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQUntSil1NUnit.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQUntSil1NUnit
 ******************************************************************************/

WdbeQUntSil1NUnit::WdbeQUntSil1NUnit(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQUntSil1NUnit::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQUntSil1NUnit");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQUntSil1NUnit
 ******************************************************************************/

ListWdbeQUntSil1NUnit::ListWdbeQUntSil1NUnit() {
};

ListWdbeQUntSil1NUnit::ListWdbeQUntSil1NUnit(
			const ListWdbeQUntSil1NUnit& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUntSil1NUnit(*(src.nodes[i]));
};

ListWdbeQUntSil1NUnit& ListWdbeQUntSil1NUnit::operator=(
			const ListWdbeQUntSil1NUnit& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUntSil1NUnit(*(src.nodes[i]));

	return *this;
};

ListWdbeQUntSil1NUnit::~ListWdbeQUntSil1NUnit() {
	clear();
};

void ListWdbeQUntSil1NUnit::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQUntSil1NUnit::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQUntSil1NUnit* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQUntSil1NUnit");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQUntSil1NUnit", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQUntSil1NUnit(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQUntSil1NUnit[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

