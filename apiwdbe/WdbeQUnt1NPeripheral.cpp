/**
	* \file WdbeQUnt1NPeripheral.cpp
	* API code for table TblWdbeQUnt1NPeripheral (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQUnt1NPeripheral.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQUnt1NPeripheral
 ******************************************************************************/

WdbeQUnt1NPeripheral::WdbeQUnt1NPeripheral(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQUnt1NPeripheral::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQUnt1NPeripheral");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQUnt1NPeripheral
 ******************************************************************************/

ListWdbeQUnt1NPeripheral::ListWdbeQUnt1NPeripheral() {
};

ListWdbeQUnt1NPeripheral::ListWdbeQUnt1NPeripheral(
			const ListWdbeQUnt1NPeripheral& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUnt1NPeripheral(*(src.nodes[i]));
};

ListWdbeQUnt1NPeripheral& ListWdbeQUnt1NPeripheral::operator=(
			const ListWdbeQUnt1NPeripheral& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUnt1NPeripheral(*(src.nodes[i]));

	return *this;
};

ListWdbeQUnt1NPeripheral::~ListWdbeQUnt1NPeripheral() {
	clear();
};

void ListWdbeQUnt1NPeripheral::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQUnt1NPeripheral::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQUnt1NPeripheral* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQUnt1NPeripheral");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQUnt1NPeripheral", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQUnt1NPeripheral(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQUnt1NPeripheral[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

