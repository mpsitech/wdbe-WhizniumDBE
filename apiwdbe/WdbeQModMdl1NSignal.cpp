/**
	* \file WdbeQModMdl1NSignal.cpp
	* API code for table TblWdbeQModMdl1NSignal (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQModMdl1NSignal.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQModMdl1NSignal
 ******************************************************************************/

WdbeQModMdl1NSignal::WdbeQModMdl1NSignal(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQModMdl1NSignal::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQModMdl1NSignal");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQModMdl1NSignal
 ******************************************************************************/

ListWdbeQModMdl1NSignal::ListWdbeQModMdl1NSignal() {
};

ListWdbeQModMdl1NSignal::ListWdbeQModMdl1NSignal(
			const ListWdbeQModMdl1NSignal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModMdl1NSignal(*(src.nodes[i]));
};

ListWdbeQModMdl1NSignal& ListWdbeQModMdl1NSignal::operator=(
			const ListWdbeQModMdl1NSignal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModMdl1NSignal(*(src.nodes[i]));

	return *this;
};

ListWdbeQModMdl1NSignal::~ListWdbeQModMdl1NSignal() {
	clear();
};

void ListWdbeQModMdl1NSignal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQModMdl1NSignal::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQModMdl1NSignal* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQModMdl1NSignal");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQModMdl1NSignal", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQModMdl1NSignal(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQModMdl1NSignal[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

