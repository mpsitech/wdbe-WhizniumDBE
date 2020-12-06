/**
	* \file WdbeQPrcList.cpp
	* API code for table TblWdbeQPrcList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQPrcList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPrcList
 ******************************************************************************/

WdbeQPrcList::WdbeQPrcList(
			const uint jnum
			, const string sref
			, const string stubRefWdbeMModule
			, const string yesnoFalling
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubRefWdbeMModule = stubRefWdbeMModule;
	this->yesnoFalling = yesnoFalling;
};

bool WdbeQPrcList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQPrcList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMModule", "mdl", stubRefWdbeMModule);
		extractStringUclc(docctx, basexpath, "yesnoFalling", "fal", yesnoFalling);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQPrcList
 ******************************************************************************/

ListWdbeQPrcList::ListWdbeQPrcList() {
};

ListWdbeQPrcList::ListWdbeQPrcList(
			const ListWdbeQPrcList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrcList(*(src.nodes[i]));
};

ListWdbeQPrcList& ListWdbeQPrcList::operator=(
			const ListWdbeQPrcList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrcList(*(src.nodes[i]));

	return *this;
};

ListWdbeQPrcList::~ListWdbeQPrcList() {
	clear();
};

void ListWdbeQPrcList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQPrcList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQPrcList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQPrcList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQPrcList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQPrcList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQPrcList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
