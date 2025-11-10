/**
	* \file WdbeQPplPpl1NSegment.cpp
	* API code for table TblWdbeQPplPpl1NSegment (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeQPplPpl1NSegment.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPplPpl1NSegment
 ******************************************************************************/

WdbeQPplPpl1NSegment::WdbeQPplPpl1NSegment(
			const uint jnum
			, const string stubRef
		) :
			jnum(jnum)
			, stubRef(stubRef)
		{
};

bool WdbeQPplPpl1NSegment::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQPplPpl1NSegment");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQPplPpl1NSegment
 ******************************************************************************/

ListWdbeQPplPpl1NSegment::ListWdbeQPplPpl1NSegment() {
};

ListWdbeQPplPpl1NSegment::ListWdbeQPplPpl1NSegment(
			const ListWdbeQPplPpl1NSegment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPplPpl1NSegment(*(src.nodes[i]));
};

ListWdbeQPplPpl1NSegment& ListWdbeQPplPpl1NSegment::operator=(
			const ListWdbeQPplPpl1NSegment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPplPpl1NSegment(*(src.nodes[i]));

	return *this;
};

ListWdbeQPplPpl1NSegment::~ListWdbeQPplPpl1NSegment() {
	clear();
};

void ListWdbeQPplPpl1NSegment::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQPplPpl1NSegment::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQPplPpl1NSegment* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQPplPpl1NSegment");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQPplPpl1NSegment", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQPplPpl1NSegment(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQPplPpl1NSegment[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
