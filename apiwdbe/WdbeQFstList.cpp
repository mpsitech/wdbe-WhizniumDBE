/**
	* \file WdbeQFstList.cpp
	* API code for table TblWdbeQFstList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQFstList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQFstList
 ******************************************************************************/

WdbeQFstList::WdbeQFstList(
			const uint jnum
			, const string sref
			, const string stubFsmRefWdbeMFsm
		) :
			jnum(jnum)
			, sref(sref)
			, stubFsmRefWdbeMFsm(stubFsmRefWdbeMFsm)
		{
};

bool WdbeQFstList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQFstList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubFsmRefWdbeMFsm", "fsm", stubFsmRefWdbeMFsm);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQFstList
 ******************************************************************************/

ListWdbeQFstList::ListWdbeQFstList() {
};

ListWdbeQFstList::ListWdbeQFstList(
			const ListWdbeQFstList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQFstList(*(src.nodes[i]));
};

ListWdbeQFstList& ListWdbeQFstList::operator=(
			const ListWdbeQFstList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQFstList(*(src.nodes[i]));

	return *this;
};

ListWdbeQFstList::~ListWdbeQFstList() {
	clear();
};

void ListWdbeQFstList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQFstList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQFstList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQFstList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQFstList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQFstList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQFstList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
