/**
	* \file WdbeQPrcMge1NSignal.cpp
	* API code for table TblWdbeQPrcMge1NSignal (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQPrcMge1NSignal.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPrcMge1NSignal
 ******************************************************************************/

WdbeQPrcMge1NSignal::WdbeQPrcMge1NSignal(
			const uint jnum
			, const string stubRef
		) :
			jnum(jnum)
			, stubRef(stubRef)
		{
};

bool WdbeQPrcMge1NSignal::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQPrcMge1NSignal");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQPrcMge1NSignal
 ******************************************************************************/

ListWdbeQPrcMge1NSignal::ListWdbeQPrcMge1NSignal() {
};

ListWdbeQPrcMge1NSignal::ListWdbeQPrcMge1NSignal(
			const ListWdbeQPrcMge1NSignal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrcMge1NSignal(*(src.nodes[i]));
};

ListWdbeQPrcMge1NSignal& ListWdbeQPrcMge1NSignal::operator=(
			const ListWdbeQPrcMge1NSignal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrcMge1NSignal(*(src.nodes[i]));

	return *this;
};

ListWdbeQPrcMge1NSignal::~ListWdbeQPrcMge1NSignal() {
	clear();
};

void ListWdbeQPrcMge1NSignal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQPrcMge1NSignal::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQPrcMge1NSignal* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQPrcMge1NSignal");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQPrcMge1NSignal", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQPrcMge1NSignal(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQPrcMge1NSignal[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
