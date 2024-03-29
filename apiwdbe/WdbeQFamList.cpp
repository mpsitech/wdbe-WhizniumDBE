/**
	* \file WdbeQFamList.cpp
	* API code for table TblWdbeQFamList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQFamList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQFamList
 ******************************************************************************/

WdbeQFamList::WdbeQFamList(
			const uint jnum
			, const string srefWdbeKVendor
			, const string titSrefWdbeKVendor
			, const string Title
		) {
	this->jnum = jnum;
	this->srefWdbeKVendor = srefWdbeKVendor;
	this->titSrefWdbeKVendor = titSrefWdbeKVendor;
	this->Title = Title;
};

bool WdbeQFamList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQFamList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "srefWdbeKVendor", "vnd", srefWdbeKVendor);
		extractStringUclc(docctx, basexpath, "titSrefWdbeKVendor", "vnd2", titSrefWdbeKVendor);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQFamList
 ******************************************************************************/

ListWdbeQFamList::ListWdbeQFamList() {
};

ListWdbeQFamList::ListWdbeQFamList(
			const ListWdbeQFamList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQFamList(*(src.nodes[i]));
};

ListWdbeQFamList& ListWdbeQFamList::operator=(
			const ListWdbeQFamList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQFamList(*(src.nodes[i]));

	return *this;
};

ListWdbeQFamList::~ListWdbeQFamList() {
	clear();
};

void ListWdbeQFamList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQFamList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQFamList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQFamList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQFamList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQFamList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQFamList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
