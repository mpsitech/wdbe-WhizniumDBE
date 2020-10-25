/**
	* \file WdbeQUnt1NTarget.cpp
	* API code for table TblWdbeQUnt1NTarget (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQUnt1NTarget.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQUnt1NTarget
 ******************************************************************************/

WdbeQUnt1NTarget::WdbeQUnt1NTarget(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQUnt1NTarget::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQUnt1NTarget");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQUnt1NTarget
 ******************************************************************************/

ListWdbeQUnt1NTarget::ListWdbeQUnt1NTarget() {
};

ListWdbeQUnt1NTarget::ListWdbeQUnt1NTarget(
			const ListWdbeQUnt1NTarget& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUnt1NTarget(*(src.nodes[i]));
};

ListWdbeQUnt1NTarget& ListWdbeQUnt1NTarget::operator=(
			const ListWdbeQUnt1NTarget& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUnt1NTarget(*(src.nodes[i]));

	return *this;
};

ListWdbeQUnt1NTarget::~ListWdbeQUnt1NTarget() {
	clear();
};

void ListWdbeQUnt1NTarget::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQUnt1NTarget::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQUnt1NTarget* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQUnt1NTarget");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQUnt1NTarget", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQUnt1NTarget(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQUnt1NTarget[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

