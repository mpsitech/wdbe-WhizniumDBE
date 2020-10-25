/**
	* \file WdbeQPrcPrc1NVariable.cpp
	* API code for table TblWdbeQPrcPrc1NVariable (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQPrcPrc1NVariable.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPrcPrc1NVariable
 ******************************************************************************/

WdbeQPrcPrc1NVariable::WdbeQPrcPrc1NVariable(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQPrcPrc1NVariable::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQPrcPrc1NVariable");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQPrcPrc1NVariable
 ******************************************************************************/

ListWdbeQPrcPrc1NVariable::ListWdbeQPrcPrc1NVariable() {
};

ListWdbeQPrcPrc1NVariable::ListWdbeQPrcPrc1NVariable(
			const ListWdbeQPrcPrc1NVariable& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrcPrc1NVariable(*(src.nodes[i]));
};

ListWdbeQPrcPrc1NVariable& ListWdbeQPrcPrc1NVariable::operator=(
			const ListWdbeQPrcPrc1NVariable& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrcPrc1NVariable(*(src.nodes[i]));

	return *this;
};

ListWdbeQPrcPrc1NVariable::~ListWdbeQPrcPrc1NVariable() {
	clear();
};

void ListWdbeQPrcPrc1NVariable::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQPrcPrc1NVariable::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQPrcPrc1NVariable* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQPrcPrc1NVariable");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQPrcPrc1NVariable", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQPrcPrc1NVariable(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQPrcPrc1NVariable[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

