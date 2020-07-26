/**
	* \file WdbeQCmdMNController.cpp
	* API code for table TblWdbeQCmdMNController (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeQCmdMNController.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCmdMNController
 ******************************************************************************/

WdbeQCmdMNController::WdbeQCmdMNController(
			const uint jnum
			, const string stubMref
			, const string stubIvrRefWdbeMSignal
			, const string stubRvrRefWdbeMSignal
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->stubIvrRefWdbeMSignal = stubIvrRefWdbeMSignal;
	this->stubRvrRefWdbeMSignal = stubRvrRefWdbeMSignal;
};

bool WdbeQCmdMNController::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQCmdMNController");
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
 class ListWdbeQCmdMNController
 ******************************************************************************/

ListWdbeQCmdMNController::ListWdbeQCmdMNController() {
};

ListWdbeQCmdMNController::ListWdbeQCmdMNController(
			const ListWdbeQCmdMNController& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCmdMNController(*(src.nodes[i]));
};

ListWdbeQCmdMNController& ListWdbeQCmdMNController::operator=(
			const ListWdbeQCmdMNController& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCmdMNController(*(src.nodes[i]));

	return *this;
};

ListWdbeQCmdMNController::~ListWdbeQCmdMNController() {
	clear();
};

void ListWdbeQCmdMNController::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQCmdMNController::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQCmdMNController* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQCmdMNController");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQCmdMNController", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQCmdMNController(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQCmdMNController[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

