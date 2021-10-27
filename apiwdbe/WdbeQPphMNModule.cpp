/**
	* \file WdbeQPphMNModule.cpp
	* API code for table TblWdbeQPphMNModule (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 13 Oct 2021
  */
// IP header --- ABOVE

#include "WdbeQPphMNModule.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPphMNModule
 ******************************************************************************/

WdbeQPphMNModule::WdbeQPphMNModule(
			const uint jnum
			, const string stubMref
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
};

bool WdbeQPphMNModule::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQPphMNModule");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQPphMNModule
 ******************************************************************************/

ListWdbeQPphMNModule::ListWdbeQPphMNModule() {
};

ListWdbeQPphMNModule::ListWdbeQPphMNModule(
			const ListWdbeQPphMNModule& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPphMNModule(*(src.nodes[i]));
};

ListWdbeQPphMNModule& ListWdbeQPphMNModule::operator=(
			const ListWdbeQPphMNModule& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPphMNModule(*(src.nodes[i]));

	return *this;
};

ListWdbeQPphMNModule::~ListWdbeQPphMNModule() {
	clear();
};

void ListWdbeQPphMNModule::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQPphMNModule::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQPphMNModule* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQPphMNModule");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQPphMNModule", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQPphMNModule(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQPphMNModule[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
