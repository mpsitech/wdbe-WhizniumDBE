/**
	* \file WdbeQCpr1NCoreversion.cpp
	* API code for table TblWdbeQCpr1NCoreversion (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQCpr1NCoreversion.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCpr1NCoreversion
 ******************************************************************************/

WdbeQCpr1NCoreversion::WdbeQCpr1NCoreversion(
			const uint jnum
			, const string stubRef
		) :
			jnum(jnum)
			, stubRef(stubRef)
		{
};

bool WdbeQCpr1NCoreversion::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQCpr1NCoreversion");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQCpr1NCoreversion
 ******************************************************************************/

ListWdbeQCpr1NCoreversion::ListWdbeQCpr1NCoreversion() {
};

ListWdbeQCpr1NCoreversion::ListWdbeQCpr1NCoreversion(
			const ListWdbeQCpr1NCoreversion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCpr1NCoreversion(*(src.nodes[i]));
};

ListWdbeQCpr1NCoreversion& ListWdbeQCpr1NCoreversion::operator=(
			const ListWdbeQCpr1NCoreversion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCpr1NCoreversion(*(src.nodes[i]));

	return *this;
};

ListWdbeQCpr1NCoreversion::~ListWdbeQCpr1NCoreversion() {
	clear();
};

void ListWdbeQCpr1NCoreversion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQCpr1NCoreversion::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQCpr1NCoreversion* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQCpr1NCoreversion");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQCpr1NCoreversion", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQCpr1NCoreversion(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQCpr1NCoreversion[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
