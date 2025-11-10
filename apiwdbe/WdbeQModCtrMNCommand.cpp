/**
	* \file WdbeQModCtrMNCommand.cpp
	* API code for table TblWdbeQModCtrMNCommand (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQModCtrMNCommand.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQModCtrMNCommand
 ******************************************************************************/

WdbeQModCtrMNCommand::WdbeQModCtrMNCommand(
			const uint jnum
			, const string stubMref
			, const string stubIvrRefWdbeMSignal
			, const string stubRvrRefWdbeMSignal
		) :
			jnum(jnum)
			, stubMref(stubMref)
			, stubIvrRefWdbeMSignal(stubIvrRefWdbeMSignal)
			, stubRvrRefWdbeMSignal(stubRvrRefWdbeMSignal)
		{
};

bool WdbeQModCtrMNCommand::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQModCtrMNCommand");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "stubIvrRefWdbeMSignal", "ivr", stubIvrRefWdbeMSignal);
		extractStringUclc(docctx, basexpath, "stubRvrRefWdbeMSignal", "rvr", stubRvrRefWdbeMSignal);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQModCtrMNCommand
 ******************************************************************************/

ListWdbeQModCtrMNCommand::ListWdbeQModCtrMNCommand() {
};

ListWdbeQModCtrMNCommand::ListWdbeQModCtrMNCommand(
			const ListWdbeQModCtrMNCommand& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModCtrMNCommand(*(src.nodes[i]));
};

ListWdbeQModCtrMNCommand& ListWdbeQModCtrMNCommand::operator=(
			const ListWdbeQModCtrMNCommand& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModCtrMNCommand(*(src.nodes[i]));

	return *this;
};

ListWdbeQModCtrMNCommand::~ListWdbeQModCtrMNCommand() {
	clear();
};

void ListWdbeQModCtrMNCommand::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQModCtrMNCommand::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQModCtrMNCommand* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQModCtrMNCommand");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQModCtrMNCommand", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQModCtrMNCommand(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQModCtrMNCommand[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
