/**
	* \file WdbeQModHsm1NPipeline.cpp
	* API code for table TblWdbeQModHsm1NPipeline (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeQModHsm1NPipeline.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQModHsm1NPipeline
 ******************************************************************************/

WdbeQModHsm1NPipeline::WdbeQModHsm1NPipeline(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQModHsm1NPipeline::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQModHsm1NPipeline");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQModHsm1NPipeline
 ******************************************************************************/

ListWdbeQModHsm1NPipeline::ListWdbeQModHsm1NPipeline() {
};

ListWdbeQModHsm1NPipeline::ListWdbeQModHsm1NPipeline(
			const ListWdbeQModHsm1NPipeline& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModHsm1NPipeline(*(src.nodes[i]));
};

ListWdbeQModHsm1NPipeline& ListWdbeQModHsm1NPipeline::operator=(
			const ListWdbeQModHsm1NPipeline& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModHsm1NPipeline(*(src.nodes[i]));

	return *this;
};

ListWdbeQModHsm1NPipeline::~ListWdbeQModHsm1NPipeline() {
	clear();
};

void ListWdbeQModHsm1NPipeline::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQModHsm1NPipeline::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQModHsm1NPipeline* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQModHsm1NPipeline");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQModHsm1NPipeline", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQModHsm1NPipeline(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQModHsm1NPipeline[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
