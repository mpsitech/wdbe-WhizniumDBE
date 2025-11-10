/**
	* \file WdbeQSil1NInterrupt.cpp
	* API code for table TblWdbeQSil1NInterrupt (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeQSil1NInterrupt.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQSil1NInterrupt
 ******************************************************************************/

WdbeQSil1NInterrupt::WdbeQSil1NInterrupt(
			const uint jnum
			, const string stubRef
		) :
			jnum(jnum)
			, stubRef(stubRef)
		{
};

bool WdbeQSil1NInterrupt::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQSil1NInterrupt");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQSil1NInterrupt
 ******************************************************************************/

ListWdbeQSil1NInterrupt::ListWdbeQSil1NInterrupt() {
};

ListWdbeQSil1NInterrupt::ListWdbeQSil1NInterrupt(
			const ListWdbeQSil1NInterrupt& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSil1NInterrupt(*(src.nodes[i]));
};

ListWdbeQSil1NInterrupt& ListWdbeQSil1NInterrupt::operator=(
			const ListWdbeQSil1NInterrupt& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSil1NInterrupt(*(src.nodes[i]));

	return *this;
};

ListWdbeQSil1NInterrupt::~ListWdbeQSil1NInterrupt() {
	clear();
};

void ListWdbeQSil1NInterrupt::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQSil1NInterrupt::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQSil1NInterrupt* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQSil1NInterrupt");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQSil1NInterrupt", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQSil1NInterrupt(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQSil1NInterrupt[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
