/**
	* \file WdbeQVitList.cpp
	* API code for table TblWdbeQVitList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQVitList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQVitList
 ******************************************************************************/

WdbeQVitList::WdbeQVitList(
			const uint jnum
			, const string sref
			, const string Title
			, const string stubVecRefWdbeMVector
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Title = Title;
	this->stubVecRefWdbeMVector = stubVecRefWdbeMVector;
};

bool WdbeQVitList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQVitList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubVecRefWdbeMVector", "vec", stubVecRefWdbeMVector);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQVitList
 ******************************************************************************/

ListWdbeQVitList::ListWdbeQVitList() {
};

ListWdbeQVitList::ListWdbeQVitList(
			const ListWdbeQVitList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQVitList(*(src.nodes[i]));
};

ListWdbeQVitList& ListWdbeQVitList::operator=(
			const ListWdbeQVitList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQVitList(*(src.nodes[i]));

	return *this;
};

ListWdbeQVitList::~ListWdbeQVitList() {
	clear();
};

void ListWdbeQVitList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQVitList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQVitList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQVitList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQVitList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQVitList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQVitList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

