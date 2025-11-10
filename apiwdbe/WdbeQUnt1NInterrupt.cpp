/**
	* \file WdbeQUnt1NInterrupt.cpp
	* API code for table TblWdbeQUnt1NInterrupt (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeQUnt1NInterrupt.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQUnt1NInterrupt
 ******************************************************************************/

WdbeQUnt1NInterrupt::WdbeQUnt1NInterrupt(
			const uint jnum
			, const string stubRef
		) :
			jnum(jnum)
			, stubRef(stubRef)
		{
};

bool WdbeQUnt1NInterrupt::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQUnt1NInterrupt");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQUnt1NInterrupt
 ******************************************************************************/

ListWdbeQUnt1NInterrupt::ListWdbeQUnt1NInterrupt() {
};

ListWdbeQUnt1NInterrupt::ListWdbeQUnt1NInterrupt(
			const ListWdbeQUnt1NInterrupt& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUnt1NInterrupt(*(src.nodes[i]));
};

ListWdbeQUnt1NInterrupt& ListWdbeQUnt1NInterrupt::operator=(
			const ListWdbeQUnt1NInterrupt& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUnt1NInterrupt(*(src.nodes[i]));

	return *this;
};

ListWdbeQUnt1NInterrupt::~ListWdbeQUnt1NInterrupt() {
	clear();
};

void ListWdbeQUnt1NInterrupt::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQUnt1NInterrupt::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQUnt1NInterrupt* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQUnt1NInterrupt");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQUnt1NInterrupt", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQUnt1NInterrupt(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQUnt1NInterrupt[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
