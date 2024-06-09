/**
	* \file WdbeQCdcList.cpp
	* API code for table TblWdbeQCdcList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#include "WdbeQCdcList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCdcList
 ******************************************************************************/

WdbeQCdcList::WdbeQCdcList(
			const uint jnum
			, const string stubRefWdbeMModule
		) {
	this->jnum = jnum;
	this->stubRefWdbeMModule = stubRefWdbeMModule;
};

bool WdbeQCdcList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQCdcList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRefWdbeMModule", "mdl", stubRefWdbeMModule);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQCdcList
 ******************************************************************************/

ListWdbeQCdcList::ListWdbeQCdcList() {
};

ListWdbeQCdcList::ListWdbeQCdcList(
			const ListWdbeQCdcList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCdcList(*(src.nodes[i]));
};

ListWdbeQCdcList& ListWdbeQCdcList::operator=(
			const ListWdbeQCdcList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCdcList(*(src.nodes[i]));

	return *this;
};

ListWdbeQCdcList::~ListWdbeQCdcList() {
	clear();
};

void ListWdbeQCdcList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQCdcList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQCdcList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQCdcList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQCdcList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQCdcList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQCdcList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
