/**
	* \file WdbeQPrjPrj1NVersion.cpp
	* API code for table TblWdbeQPrjPrj1NVersion (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 16 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQPrjPrj1NVersion.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPrjPrj1NVersion
 ******************************************************************************/

WdbeQPrjPrj1NVersion::WdbeQPrjPrj1NVersion(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQPrjPrj1NVersion::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQPrjPrj1NVersion");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQPrjPrj1NVersion
 ******************************************************************************/

ListWdbeQPrjPrj1NVersion::ListWdbeQPrjPrj1NVersion() {
};

ListWdbeQPrjPrj1NVersion::ListWdbeQPrjPrj1NVersion(
			const ListWdbeQPrjPrj1NVersion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrjPrj1NVersion(*(src.nodes[i]));
};

ListWdbeQPrjPrj1NVersion& ListWdbeQPrjPrj1NVersion::operator=(
			const ListWdbeQPrjPrj1NVersion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrjPrj1NVersion(*(src.nodes[i]));

	return *this;
};

ListWdbeQPrjPrj1NVersion::~ListWdbeQPrjPrj1NVersion() {
	clear();
};

void ListWdbeQPrjPrj1NVersion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQPrjPrj1NVersion::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQPrjPrj1NVersion* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQPrjPrj1NVersion");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQPrjPrj1NVersion", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQPrjPrj1NVersion(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQPrjPrj1NVersion[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
