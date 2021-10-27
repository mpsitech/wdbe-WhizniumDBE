/**
	* \file WdbeQMtpHsm1NPipeline.cpp
	* API code for table TblWdbeQMtpHsm1NPipeline (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeQMtpHsm1NPipeline.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQMtpHsm1NPipeline
 ******************************************************************************/

WdbeQMtpHsm1NPipeline::WdbeQMtpHsm1NPipeline(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQMtpHsm1NPipeline::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQMtpHsm1NPipeline");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQMtpHsm1NPipeline
 ******************************************************************************/

ListWdbeQMtpHsm1NPipeline::ListWdbeQMtpHsm1NPipeline() {
};

ListWdbeQMtpHsm1NPipeline::ListWdbeQMtpHsm1NPipeline(
			const ListWdbeQMtpHsm1NPipeline& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMtpHsm1NPipeline(*(src.nodes[i]));
};

ListWdbeQMtpHsm1NPipeline& ListWdbeQMtpHsm1NPipeline::operator=(
			const ListWdbeQMtpHsm1NPipeline& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMtpHsm1NPipeline(*(src.nodes[i]));

	return *this;
};

ListWdbeQMtpHsm1NPipeline::~ListWdbeQMtpHsm1NPipeline() {
	clear();
};

void ListWdbeQMtpHsm1NPipeline::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQMtpHsm1NPipeline::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQMtpHsm1NPipeline* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQMtpHsm1NPipeline");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQMtpHsm1NPipeline", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQMtpHsm1NPipeline(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQMtpHsm1NPipeline[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
