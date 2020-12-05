/**
	* \file WdbeQMchSup1NMachine.cpp
	* API code for table TblWdbeQMchSup1NMachine (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQMchSup1NMachine.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQMchSup1NMachine
 ******************************************************************************/

WdbeQMchSup1NMachine::WdbeQMchSup1NMachine(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQMchSup1NMachine::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQMchSup1NMachine");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQMchSup1NMachine
 ******************************************************************************/

ListWdbeQMchSup1NMachine::ListWdbeQMchSup1NMachine() {
};

ListWdbeQMchSup1NMachine::ListWdbeQMchSup1NMachine(
			const ListWdbeQMchSup1NMachine& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMchSup1NMachine(*(src.nodes[i]));
};

ListWdbeQMchSup1NMachine& ListWdbeQMchSup1NMachine::operator=(
			const ListWdbeQMchSup1NMachine& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMchSup1NMachine(*(src.nodes[i]));

	return *this;
};

ListWdbeQMchSup1NMachine::~ListWdbeQMchSup1NMachine() {
	clear();
};

void ListWdbeQMchSup1NMachine::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQMchSup1NMachine::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQMchSup1NMachine* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQMchSup1NMachine");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQMchSup1NMachine", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQMchSup1NMachine(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQMchSup1NMachine[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

