/**
	* \file WdbeQPplList.cpp
	* API code for table TblWdbeQPplList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeQPplList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPplList
 ******************************************************************************/

WdbeQPplList::WdbeQPplList(
			const uint jnum
			, const string sref
			, const string stubHsmRefWdbeMModule
			, const usmallint Depth
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubHsmRefWdbeMModule = stubHsmRefWdbeMModule;
	this->Depth = Depth;
};

bool WdbeQPplList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQPplList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubHsmRefWdbeMModule", "hsm", stubHsmRefWdbeMModule);
		extractUsmallintUclc(docctx, basexpath, "Depth", "dpt", Depth);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQPplList
 ******************************************************************************/

ListWdbeQPplList::ListWdbeQPplList() {
};

ListWdbeQPplList::ListWdbeQPplList(
			const ListWdbeQPplList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPplList(*(src.nodes[i]));
};

ListWdbeQPplList& ListWdbeQPplList::operator=(
			const ListWdbeQPplList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPplList(*(src.nodes[i]));

	return *this;
};

ListWdbeQPplList::~ListWdbeQPplList() {
	clear();
};

void ListWdbeQPplList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQPplList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQPplList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQPplList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQPplList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQPplList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQPplList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
