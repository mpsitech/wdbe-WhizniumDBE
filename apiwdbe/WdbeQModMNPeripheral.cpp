/**
	* \file WdbeQModMNPeripheral.cpp
	* API code for table TblWdbeQModMNPeripheral (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 13 Oct 2021
  */
// IP header --- ABOVE

#include "WdbeQModMNPeripheral.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQModMNPeripheral
 ******************************************************************************/

WdbeQModMNPeripheral::WdbeQModMNPeripheral(
			const uint jnum
			, const string stubMref
		) :
			jnum(jnum)
			, stubMref(stubMref)
		{
};

bool WdbeQModMNPeripheral::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQModMNPeripheral");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQModMNPeripheral
 ******************************************************************************/

ListWdbeQModMNPeripheral::ListWdbeQModMNPeripheral() {
};

ListWdbeQModMNPeripheral::ListWdbeQModMNPeripheral(
			const ListWdbeQModMNPeripheral& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModMNPeripheral(*(src.nodes[i]));
};

ListWdbeQModMNPeripheral& ListWdbeQModMNPeripheral::operator=(
			const ListWdbeQModMNPeripheral& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModMNPeripheral(*(src.nodes[i]));

	return *this;
};

ListWdbeQModMNPeripheral::~ListWdbeQModMNPeripheral() {
	clear();
};

void ListWdbeQModMNPeripheral::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQModMNPeripheral::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQModMNPeripheral* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQModMNPeripheral");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQModMNPeripheral", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQModMNPeripheral(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQModMNPeripheral[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
