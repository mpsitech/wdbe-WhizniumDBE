/**
	* \file WdbeQPinList.cpp
	* API code for table TblWdbeQPinList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQPinList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPinList
 ******************************************************************************/

WdbeQPinList::WdbeQPinList(
			const uint jnum
			, const string sref
			, const string stubRefWdbeMBank
			, const string Location
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubRefWdbeMBank = stubRefWdbeMBank;
	this->Location = Location;
};

bool WdbeQPinList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQPinList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMBank", "bnk", stubRefWdbeMBank);
		extractStringUclc(docctx, basexpath, "Location", "loc", Location);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQPinList
 ******************************************************************************/

ListWdbeQPinList::ListWdbeQPinList() {
};

ListWdbeQPinList::ListWdbeQPinList(
			const ListWdbeQPinList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPinList(*(src.nodes[i]));
};

ListWdbeQPinList& ListWdbeQPinList::operator=(
			const ListWdbeQPinList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPinList(*(src.nodes[i]));

	return *this;
};

ListWdbeQPinList::~ListWdbeQPinList() {
	clear();
};

void ListWdbeQPinList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQPinList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQPinList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQPinList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQPinList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQPinList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQPinList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

