/**
	* \file WdbeQUntFwd1NController.cpp
	* API code for table TblWdbeQUntFwd1NController (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQUntFwd1NController.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQUntFwd1NController
 ******************************************************************************/

WdbeQUntFwd1NController::WdbeQUntFwd1NController(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQUntFwd1NController::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQUntFwd1NController");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQUntFwd1NController
 ******************************************************************************/

ListWdbeQUntFwd1NController::ListWdbeQUntFwd1NController() {
};

ListWdbeQUntFwd1NController::ListWdbeQUntFwd1NController(
			const ListWdbeQUntFwd1NController& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUntFwd1NController(*(src.nodes[i]));
};

ListWdbeQUntFwd1NController& ListWdbeQUntFwd1NController::operator=(
			const ListWdbeQUntFwd1NController& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUntFwd1NController(*(src.nodes[i]));

	return *this;
};

ListWdbeQUntFwd1NController::~ListWdbeQUntFwd1NController() {
	clear();
};

void ListWdbeQUntFwd1NController::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQUntFwd1NController::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQUntFwd1NController* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQUntFwd1NController");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQUntFwd1NController", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQUntFwd1NController(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQUntFwd1NController[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

