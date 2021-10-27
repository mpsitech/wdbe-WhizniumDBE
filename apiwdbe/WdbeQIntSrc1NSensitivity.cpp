/**
	* \file WdbeQIntSrc1NSensitivity.cpp
	* API code for table TblWdbeQIntSrc1NSensitivity (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeQIntSrc1NSensitivity.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQIntSrc1NSensitivity
 ******************************************************************************/

WdbeQIntSrc1NSensitivity::WdbeQIntSrc1NSensitivity(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQIntSrc1NSensitivity::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQIntSrc1NSensitivity");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQIntSrc1NSensitivity
 ******************************************************************************/

ListWdbeQIntSrc1NSensitivity::ListWdbeQIntSrc1NSensitivity() {
};

ListWdbeQIntSrc1NSensitivity::ListWdbeQIntSrc1NSensitivity(
			const ListWdbeQIntSrc1NSensitivity& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQIntSrc1NSensitivity(*(src.nodes[i]));
};

ListWdbeQIntSrc1NSensitivity& ListWdbeQIntSrc1NSensitivity::operator=(
			const ListWdbeQIntSrc1NSensitivity& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQIntSrc1NSensitivity(*(src.nodes[i]));

	return *this;
};

ListWdbeQIntSrc1NSensitivity::~ListWdbeQIntSrc1NSensitivity() {
	clear();
};

void ListWdbeQIntSrc1NSensitivity::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQIntSrc1NSensitivity::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQIntSrc1NSensitivity* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQIntSrc1NSensitivity");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQIntSrc1NSensitivity", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQIntSrc1NSensitivity(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQIntSrc1NSensitivity[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
