/**
	* \file WdbeQSysSys1NTarget.cpp
	* API code for table TblWdbeQSysSys1NTarget (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQSysSys1NTarget.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQSysSys1NTarget
 ******************************************************************************/

WdbeQSysSys1NTarget::WdbeQSysSys1NTarget(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQSysSys1NTarget::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQSysSys1NTarget");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQSysSys1NTarget
 ******************************************************************************/

ListWdbeQSysSys1NTarget::ListWdbeQSysSys1NTarget() {
};

ListWdbeQSysSys1NTarget::ListWdbeQSysSys1NTarget(
			const ListWdbeQSysSys1NTarget& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSysSys1NTarget(*(src.nodes[i]));
};

ListWdbeQSysSys1NTarget& ListWdbeQSysSys1NTarget::operator=(
			const ListWdbeQSysSys1NTarget& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSysSys1NTarget(*(src.nodes[i]));

	return *this;
};

ListWdbeQSysSys1NTarget::~ListWdbeQSysSys1NTarget() {
	clear();
};

void ListWdbeQSysSys1NTarget::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQSysSys1NTarget::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQSysSys1NTarget* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQSysSys1NTarget");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQSysSys1NTarget", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQSysSys1NTarget(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQSysSys1NTarget[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

