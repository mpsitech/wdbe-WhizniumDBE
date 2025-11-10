/**
	* \file WdbeQModCtrRef1NCommand.cpp
	* API code for table TblWdbeQModCtrRef1NCommand (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQModCtrRef1NCommand.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQModCtrRef1NCommand
 ******************************************************************************/

WdbeQModCtrRef1NCommand::WdbeQModCtrRef1NCommand(
			const uint jnum
			, const string stubRef
		) :
			jnum(jnum)
			, stubRef(stubRef)
		{
};

bool WdbeQModCtrRef1NCommand::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQModCtrRef1NCommand");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQModCtrRef1NCommand
 ******************************************************************************/

ListWdbeQModCtrRef1NCommand::ListWdbeQModCtrRef1NCommand() {
};

ListWdbeQModCtrRef1NCommand::ListWdbeQModCtrRef1NCommand(
			const ListWdbeQModCtrRef1NCommand& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModCtrRef1NCommand(*(src.nodes[i]));
};

ListWdbeQModCtrRef1NCommand& ListWdbeQModCtrRef1NCommand::operator=(
			const ListWdbeQModCtrRef1NCommand& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModCtrRef1NCommand(*(src.nodes[i]));

	return *this;
};

ListWdbeQModCtrRef1NCommand::~ListWdbeQModCtrRef1NCommand() {
	clear();
};

void ListWdbeQModCtrRef1NCommand::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQModCtrRef1NCommand::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQModCtrRef1NCommand* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQModCtrRef1NCommand");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQModCtrRef1NCommand", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQModCtrRef1NCommand(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQModCtrRef1NCommand[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
