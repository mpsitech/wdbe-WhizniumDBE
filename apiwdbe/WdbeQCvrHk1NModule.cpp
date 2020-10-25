/**
	* \file WdbeQCvrHk1NModule.cpp
	* API code for table TblWdbeQCvrHk1NModule (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQCvrHk1NModule.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCvrHk1NModule
 ******************************************************************************/

WdbeQCvrHk1NModule::WdbeQCvrHk1NModule(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQCvrHk1NModule::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQCvrHk1NModule");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQCvrHk1NModule
 ******************************************************************************/

ListWdbeQCvrHk1NModule::ListWdbeQCvrHk1NModule() {
};

ListWdbeQCvrHk1NModule::ListWdbeQCvrHk1NModule(
			const ListWdbeQCvrHk1NModule& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCvrHk1NModule(*(src.nodes[i]));
};

ListWdbeQCvrHk1NModule& ListWdbeQCvrHk1NModule::operator=(
			const ListWdbeQCvrHk1NModule& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCvrHk1NModule(*(src.nodes[i]));

	return *this;
};

ListWdbeQCvrHk1NModule::~ListWdbeQCvrHk1NModule() {
	clear();
};

void ListWdbeQCvrHk1NModule::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQCvrHk1NModule::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQCvrHk1NModule* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQCvrHk1NModule");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQCvrHk1NModule", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQCvrHk1NModule(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQCvrHk1NModule[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

