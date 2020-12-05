/**
	* \file WdbeQModCtrRef1NError.cpp
	* API code for table TblWdbeQModCtrRef1NError (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQModCtrRef1NError.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQModCtrRef1NError
 ******************************************************************************/

WdbeQModCtrRef1NError::WdbeQModCtrRef1NError(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQModCtrRef1NError::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQModCtrRef1NError");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQModCtrRef1NError
 ******************************************************************************/

ListWdbeQModCtrRef1NError::ListWdbeQModCtrRef1NError() {
};

ListWdbeQModCtrRef1NError::ListWdbeQModCtrRef1NError(
			const ListWdbeQModCtrRef1NError& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModCtrRef1NError(*(src.nodes[i]));
};

ListWdbeQModCtrRef1NError& ListWdbeQModCtrRef1NError::operator=(
			const ListWdbeQModCtrRef1NError& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModCtrRef1NError(*(src.nodes[i]));

	return *this;
};

ListWdbeQModCtrRef1NError::~ListWdbeQModCtrRef1NError() {
	clear();
};

void ListWdbeQModCtrRef1NError::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQModCtrRef1NError::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQModCtrRef1NError* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQModCtrRef1NError");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQModCtrRef1NError", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQModCtrRef1NError(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQModCtrRef1NError[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

