/**
	* \file WdbeQCdcMNSignal.cpp
	* API code for table TblWdbeQCdcMNSignal (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#include "WdbeQCdcMNSignal.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCdcMNSignal
 ******************************************************************************/

WdbeQCdcMNSignal::WdbeQCdcMNSignal(
			const uint jnum
			, const string stubMref
			, const string srefIxVDir
			, const string titIxVDir
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->srefIxVDir = srefIxVDir;
	this->titIxVDir = titIxVDir;
};

bool WdbeQCdcMNSignal::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQCdcMNSignal");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "srefIxVDir", "dir", srefIxVDir);
		extractStringUclc(docctx, basexpath, "titIxVDir", "dir2", titIxVDir);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQCdcMNSignal
 ******************************************************************************/

ListWdbeQCdcMNSignal::ListWdbeQCdcMNSignal() {
};

ListWdbeQCdcMNSignal::ListWdbeQCdcMNSignal(
			const ListWdbeQCdcMNSignal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCdcMNSignal(*(src.nodes[i]));
};

ListWdbeQCdcMNSignal& ListWdbeQCdcMNSignal::operator=(
			const ListWdbeQCdcMNSignal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCdcMNSignal(*(src.nodes[i]));

	return *this;
};

ListWdbeQCdcMNSignal::~ListWdbeQCdcMNSignal() {
	clear();
};

void ListWdbeQCdcMNSignal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQCdcMNSignal::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQCdcMNSignal* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQCdcMNSignal");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQCdcMNSignal", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQCdcMNSignal(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQCdcMNSignal[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
