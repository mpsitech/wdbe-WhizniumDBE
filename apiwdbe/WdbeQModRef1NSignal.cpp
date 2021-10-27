/**
	* \file WdbeQModRef1NSignal.cpp
	* API code for table TblWdbeQModRef1NSignal (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2021
  */
// IP header --- ABOVE

#include "WdbeQModRef1NSignal.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQModRef1NSignal
 ******************************************************************************/

WdbeQModRef1NSignal::WdbeQModRef1NSignal(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQModRef1NSignal::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQModRef1NSignal");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQModRef1NSignal
 ******************************************************************************/

ListWdbeQModRef1NSignal::ListWdbeQModRef1NSignal() {
};

ListWdbeQModRef1NSignal::ListWdbeQModRef1NSignal(
			const ListWdbeQModRef1NSignal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModRef1NSignal(*(src.nodes[i]));
};

ListWdbeQModRef1NSignal& ListWdbeQModRef1NSignal::operator=(
			const ListWdbeQModRef1NSignal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModRef1NSignal(*(src.nodes[i]));

	return *this;
};

ListWdbeQModRef1NSignal::~ListWdbeQModRef1NSignal() {
	clear();
};

void ListWdbeQModRef1NSignal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQModRef1NSignal::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQModRef1NSignal* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQModRef1NSignal");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQModRef1NSignal", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQModRef1NSignal(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQModRef1NSignal[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
