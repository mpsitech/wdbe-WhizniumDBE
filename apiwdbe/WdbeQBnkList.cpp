/**
	* \file WdbeQBnkList.cpp
	* API code for table TblWdbeQBnkList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeQBnkList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQBnkList
 ******************************************************************************/

WdbeQBnkList::WdbeQBnkList(
			const uint jnum
			, const string sref
			, const string stubRefWdbeMUnit
			, const string srefKVoltstd
			, const string titSrefKVoltstd
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubRefWdbeMUnit = stubRefWdbeMUnit;
	this->srefKVoltstd = srefKVoltstd;
	this->titSrefKVoltstd = titSrefKVoltstd;
};

bool WdbeQBnkList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQBnkList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMUnit", "unt", stubRefWdbeMUnit);
		extractStringUclc(docctx, basexpath, "srefKVoltstd", "vst", srefKVoltstd);
		extractStringUclc(docctx, basexpath, "titSrefKVoltstd", "vst2", titSrefKVoltstd);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQBnkList
 ******************************************************************************/

ListWdbeQBnkList::ListWdbeQBnkList() {
};

ListWdbeQBnkList::ListWdbeQBnkList(
			const ListWdbeQBnkList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQBnkList(*(src.nodes[i]));
};

ListWdbeQBnkList& ListWdbeQBnkList::operator=(
			const ListWdbeQBnkList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQBnkList(*(src.nodes[i]));

	return *this;
};

ListWdbeQBnkList::~ListWdbeQBnkList() {
	clear();
};

void ListWdbeQBnkList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQBnkList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQBnkList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQBnkList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQBnkList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQBnkList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQBnkList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

