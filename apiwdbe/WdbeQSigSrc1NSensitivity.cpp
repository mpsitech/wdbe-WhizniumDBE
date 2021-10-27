/**
	* \file WdbeQSigSrc1NSensitivity.cpp
	* API code for table TblWdbeQSigSrc1NSensitivity (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeQSigSrc1NSensitivity.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQSigSrc1NSensitivity
 ******************************************************************************/

WdbeQSigSrc1NSensitivity::WdbeQSigSrc1NSensitivity(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQSigSrc1NSensitivity::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQSigSrc1NSensitivity");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQSigSrc1NSensitivity
 ******************************************************************************/

ListWdbeQSigSrc1NSensitivity::ListWdbeQSigSrc1NSensitivity() {
};

ListWdbeQSigSrc1NSensitivity::ListWdbeQSigSrc1NSensitivity(
			const ListWdbeQSigSrc1NSensitivity& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSigSrc1NSensitivity(*(src.nodes[i]));
};

ListWdbeQSigSrc1NSensitivity& ListWdbeQSigSrc1NSensitivity::operator=(
			const ListWdbeQSigSrc1NSensitivity& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSigSrc1NSensitivity(*(src.nodes[i]));

	return *this;
};

ListWdbeQSigSrc1NSensitivity::~ListWdbeQSigSrc1NSensitivity() {
	clear();
};

void ListWdbeQSigSrc1NSensitivity::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQSigSrc1NSensitivity::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQSigSrc1NSensitivity* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQSigSrc1NSensitivity");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQSigSrc1NSensitivity", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQSigSrc1NSensitivity(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQSigSrc1NSensitivity[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
