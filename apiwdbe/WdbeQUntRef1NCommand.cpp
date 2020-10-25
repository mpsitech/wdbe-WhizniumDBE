/**
	* \file WdbeQUntRef1NCommand.cpp
	* API code for table TblWdbeQUntRef1NCommand (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQUntRef1NCommand.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQUntRef1NCommand
 ******************************************************************************/

WdbeQUntRef1NCommand::WdbeQUntRef1NCommand(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQUntRef1NCommand::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQUntRef1NCommand");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQUntRef1NCommand
 ******************************************************************************/

ListWdbeQUntRef1NCommand::ListWdbeQUntRef1NCommand() {
};

ListWdbeQUntRef1NCommand::ListWdbeQUntRef1NCommand(
			const ListWdbeQUntRef1NCommand& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUntRef1NCommand(*(src.nodes[i]));
};

ListWdbeQUntRef1NCommand& ListWdbeQUntRef1NCommand::operator=(
			const ListWdbeQUntRef1NCommand& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUntRef1NCommand(*(src.nodes[i]));

	return *this;
};

ListWdbeQUntRef1NCommand::~ListWdbeQUntRef1NCommand() {
	clear();
};

void ListWdbeQUntRef1NCommand::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQUntRef1NCommand::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQUntRef1NCommand* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQUntRef1NCommand");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQUntRef1NCommand", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQUntRef1NCommand(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQUntRef1NCommand[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

