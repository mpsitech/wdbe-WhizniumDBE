/**
	* \file WdbeQUntRef1NSignal.cpp
	* API code for table TblWdbeQUntRef1NSignal (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2021
  */
// IP header --- ABOVE

#include "WdbeQUntRef1NSignal.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQUntRef1NSignal
 ******************************************************************************/

WdbeQUntRef1NSignal::WdbeQUntRef1NSignal(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQUntRef1NSignal::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQUntRef1NSignal");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQUntRef1NSignal
 ******************************************************************************/

ListWdbeQUntRef1NSignal::ListWdbeQUntRef1NSignal() {
};

ListWdbeQUntRef1NSignal::ListWdbeQUntRef1NSignal(
			const ListWdbeQUntRef1NSignal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUntRef1NSignal(*(src.nodes[i]));
};

ListWdbeQUntRef1NSignal& ListWdbeQUntRef1NSignal::operator=(
			const ListWdbeQUntRef1NSignal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUntRef1NSignal(*(src.nodes[i]));

	return *this;
};

ListWdbeQUntRef1NSignal::~ListWdbeQUntRef1NSignal() {
	clear();
};

void ListWdbeQUntRef1NSignal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQUntRef1NSignal::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQUntRef1NSignal* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQUntRef1NSignal");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQUntRef1NSignal", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQUntRef1NSignal(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQUntRef1NSignal[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
