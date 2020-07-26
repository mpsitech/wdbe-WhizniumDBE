/**
	* \file WdbeQSysList.cpp
	* API code for table TblWdbeQSysList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeQSysList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQSysList
 ******************************************************************************/

WdbeQSysList::WdbeQSysList(
			const uint jnum
			, const string sref
			, const string stubRefWdbeMVersion
			, const string stubRefWdbeMUnit
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubRefWdbeMVersion = stubRefWdbeMVersion;
	this->stubRefWdbeMUnit = stubRefWdbeMUnit;
};

bool WdbeQSysList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQSysList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMVersion", "ver", stubRefWdbeMVersion);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMUnit", "unt", stubRefWdbeMUnit);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQSysList
 ******************************************************************************/

ListWdbeQSysList::ListWdbeQSysList() {
};

ListWdbeQSysList::ListWdbeQSysList(
			const ListWdbeQSysList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSysList(*(src.nodes[i]));
};

ListWdbeQSysList& ListWdbeQSysList::operator=(
			const ListWdbeQSysList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSysList(*(src.nodes[i]));

	return *this;
};

ListWdbeQSysList::~ListWdbeQSysList() {
	clear();
};

void ListWdbeQSysList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQSysList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQSysList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQSysList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQSysList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQSysList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQSysList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

