/**
	* \file WdbeQCvrBcv1NCoreversion.cpp
	* API code for table TblWdbeQCvrBcv1NCoreversion (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQCvrBcv1NCoreversion.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCvrBcv1NCoreversion
 ******************************************************************************/

WdbeQCvrBcv1NCoreversion::WdbeQCvrBcv1NCoreversion(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQCvrBcv1NCoreversion::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQCvrBcv1NCoreversion");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQCvrBcv1NCoreversion
 ******************************************************************************/

ListWdbeQCvrBcv1NCoreversion::ListWdbeQCvrBcv1NCoreversion() {
};

ListWdbeQCvrBcv1NCoreversion::ListWdbeQCvrBcv1NCoreversion(
			const ListWdbeQCvrBcv1NCoreversion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCvrBcv1NCoreversion(*(src.nodes[i]));
};

ListWdbeQCvrBcv1NCoreversion& ListWdbeQCvrBcv1NCoreversion::operator=(
			const ListWdbeQCvrBcv1NCoreversion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCvrBcv1NCoreversion(*(src.nodes[i]));

	return *this;
};

ListWdbeQCvrBcv1NCoreversion::~ListWdbeQCvrBcv1NCoreversion() {
	clear();
};

void ListWdbeQCvrBcv1NCoreversion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQCvrBcv1NCoreversion::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQCvrBcv1NCoreversion* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQCvrBcv1NCoreversion");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQCvrBcv1NCoreversion", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQCvrBcv1NCoreversion(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQCvrBcv1NCoreversion[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

