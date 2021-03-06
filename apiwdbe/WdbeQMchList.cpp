/**
	* \file WdbeQMchList.cpp
	* API code for table TblWdbeQMchList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQMchList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQMchList
 ******************************************************************************/

WdbeQMchList::WdbeQMchList(
			const uint jnum
			, const string sref
			, const string stubSupRefWdbeMMachine
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubSupRefWdbeMMachine = stubSupRefWdbeMMachine;
};

bool WdbeQMchList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQMchList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubSupRefWdbeMMachine", "sup", stubSupRefWdbeMMachine);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQMchList
 ******************************************************************************/

ListWdbeQMchList::ListWdbeQMchList() {
};

ListWdbeQMchList::ListWdbeQMchList(
			const ListWdbeQMchList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMchList(*(src.nodes[i]));
};

ListWdbeQMchList& ListWdbeQMchList::operator=(
			const ListWdbeQMchList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMchList(*(src.nodes[i]));

	return *this;
};

ListWdbeQMchList::~ListWdbeQMchList() {
	clear();
};

void ListWdbeQMchList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQMchList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQMchList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQMchList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQMchList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQMchList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQMchList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
