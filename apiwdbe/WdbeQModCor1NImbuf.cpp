/**
	* \file WdbeQModCor1NImbuf.cpp
	* API code for table TblWdbeQModCor1NImbuf (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQModCor1NImbuf.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQModCor1NImbuf
 ******************************************************************************/

WdbeQModCor1NImbuf::WdbeQModCor1NImbuf(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQModCor1NImbuf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQModCor1NImbuf");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQModCor1NImbuf
 ******************************************************************************/

ListWdbeQModCor1NImbuf::ListWdbeQModCor1NImbuf() {
};

ListWdbeQModCor1NImbuf::ListWdbeQModCor1NImbuf(
			const ListWdbeQModCor1NImbuf& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModCor1NImbuf(*(src.nodes[i]));
};

ListWdbeQModCor1NImbuf& ListWdbeQModCor1NImbuf::operator=(
			const ListWdbeQModCor1NImbuf& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModCor1NImbuf(*(src.nodes[i]));

	return *this;
};

ListWdbeQModCor1NImbuf::~ListWdbeQModCor1NImbuf() {
	clear();
};

void ListWdbeQModCor1NImbuf::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQModCor1NImbuf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQModCor1NImbuf* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQModCor1NImbuf");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQModCor1NImbuf", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQModCor1NImbuf(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQModCor1NImbuf[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

