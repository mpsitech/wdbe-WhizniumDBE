/**
	* \file WdbeQPrcRef1NVariable.cpp
	* API code for table TblWdbeQPrcRef1NVariable (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeQPrcRef1NVariable.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPrcRef1NVariable
 ******************************************************************************/

WdbeQPrcRef1NVariable::WdbeQPrcRef1NVariable(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQPrcRef1NVariable::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQPrcRef1NVariable");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQPrcRef1NVariable
 ******************************************************************************/

ListWdbeQPrcRef1NVariable::ListWdbeQPrcRef1NVariable() {
};

ListWdbeQPrcRef1NVariable::ListWdbeQPrcRef1NVariable(
			const ListWdbeQPrcRef1NVariable& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrcRef1NVariable(*(src.nodes[i]));
};

ListWdbeQPrcRef1NVariable& ListWdbeQPrcRef1NVariable::operator=(
			const ListWdbeQPrcRef1NVariable& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrcRef1NVariable(*(src.nodes[i]));

	return *this;
};

ListWdbeQPrcRef1NVariable::~ListWdbeQPrcRef1NVariable() {
	clear();
};

void ListWdbeQPrcRef1NVariable::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQPrcRef1NVariable::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQPrcRef1NVariable* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQPrcRef1NVariable");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQPrcRef1NVariable", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQPrcRef1NVariable(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQPrcRef1NVariable[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
