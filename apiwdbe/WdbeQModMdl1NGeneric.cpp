/**
	* \file WdbeQModMdl1NGeneric.cpp
	* API code for table TblWdbeQModMdl1NGeneric (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQModMdl1NGeneric.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQModMdl1NGeneric
 ******************************************************************************/

WdbeQModMdl1NGeneric::WdbeQModMdl1NGeneric(
			const uint jnum
			, const string stubRef
		) :
			jnum(jnum)
			, stubRef(stubRef)
		{
};

bool WdbeQModMdl1NGeneric::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQModMdl1NGeneric");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQModMdl1NGeneric
 ******************************************************************************/

ListWdbeQModMdl1NGeneric::ListWdbeQModMdl1NGeneric() {
};

ListWdbeQModMdl1NGeneric::ListWdbeQModMdl1NGeneric(
			const ListWdbeQModMdl1NGeneric& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModMdl1NGeneric(*(src.nodes[i]));
};

ListWdbeQModMdl1NGeneric& ListWdbeQModMdl1NGeneric::operator=(
			const ListWdbeQModMdl1NGeneric& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModMdl1NGeneric(*(src.nodes[i]));

	return *this;
};

ListWdbeQModMdl1NGeneric::~ListWdbeQModMdl1NGeneric() {
	clear();
};

void ListWdbeQModMdl1NGeneric::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQModMdl1NGeneric::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQModMdl1NGeneric* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQModMdl1NGeneric");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQModMdl1NGeneric", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQModMdl1NGeneric(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQModMdl1NGeneric[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
