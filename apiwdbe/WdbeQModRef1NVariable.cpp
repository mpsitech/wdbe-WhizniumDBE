/**
	* \file WdbeQModRef1NVariable.cpp
	* API code for table TblWdbeQModRef1NVariable (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeQModRef1NVariable.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQModRef1NVariable
 ******************************************************************************/

WdbeQModRef1NVariable::WdbeQModRef1NVariable(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQModRef1NVariable::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQModRef1NVariable");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQModRef1NVariable
 ******************************************************************************/

ListWdbeQModRef1NVariable::ListWdbeQModRef1NVariable() {
};

ListWdbeQModRef1NVariable::ListWdbeQModRef1NVariable(
			const ListWdbeQModRef1NVariable& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModRef1NVariable(*(src.nodes[i]));
};

ListWdbeQModRef1NVariable& ListWdbeQModRef1NVariable::operator=(
			const ListWdbeQModRef1NVariable& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModRef1NVariable(*(src.nodes[i]));

	return *this;
};

ListWdbeQModRef1NVariable::~ListWdbeQModRef1NVariable() {
	clear();
};

void ListWdbeQModRef1NVariable::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQModRef1NVariable::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQModRef1NVariable* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQModRef1NVariable");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQModRef1NVariable", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQModRef1NVariable(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQModRef1NVariable[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
