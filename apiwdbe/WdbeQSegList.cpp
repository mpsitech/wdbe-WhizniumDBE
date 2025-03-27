/**
	* \file WdbeQSegList.cpp
	* API code for table TblWdbeQSegList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeQSegList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQSegList
 ******************************************************************************/

WdbeQSegList::WdbeQSegList(
			const uint jnum
			, const string sref
			, const string stubPplRefWdbeMPipeline
			, const string stubSupRefWdbeMSegment
			, const string Infmt
			, const string Outfmt
			, const usmallint Latency
		) :
			jnum(jnum)
			, sref(sref)
			, stubPplRefWdbeMPipeline(stubPplRefWdbeMPipeline)
			, stubSupRefWdbeMSegment(stubSupRefWdbeMSegment)
			, Infmt(Infmt)
			, Outfmt(Outfmt)
			, Latency(Latency)
		{
};

bool WdbeQSegList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQSegList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubPplRefWdbeMPipeline", "ppl", stubPplRefWdbeMPipeline);
		extractStringUclc(docctx, basexpath, "stubSupRefWdbeMSegment", "sup", stubSupRefWdbeMSegment);
		extractStringUclc(docctx, basexpath, "Infmt", "ifm", Infmt);
		extractStringUclc(docctx, basexpath, "Outfmt", "ofm", Outfmt);
		extractUsmallintUclc(docctx, basexpath, "Latency", "lcy", Latency);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQSegList
 ******************************************************************************/

ListWdbeQSegList::ListWdbeQSegList() {
};

ListWdbeQSegList::ListWdbeQSegList(
			const ListWdbeQSegList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSegList(*(src.nodes[i]));
};

ListWdbeQSegList& ListWdbeQSegList::operator=(
			const ListWdbeQSegList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSegList(*(src.nodes[i]));

	return *this;
};

ListWdbeQSegList::~ListWdbeQSegList() {
	clear();
};

void ListWdbeQSegList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQSegList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQSegList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQSegList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQSegList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQSegList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQSegList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
