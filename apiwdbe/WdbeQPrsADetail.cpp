/**
	* \file WdbeQPrsADetail.cpp
	* API code for table TblWdbeQPrsADetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQPrsADetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPrsADetail
 ******************************************************************************/

WdbeQPrsADetail::WdbeQPrsADetail(
			const uint jnum
			, const string x1SrefKType
			, const string titX1SrefKType
			, const string Val
		) :
			jnum(jnum)
			, x1SrefKType(x1SrefKType)
			, titX1SrefKType(titX1SrefKType)
			, Val(Val)
		{
};

bool WdbeQPrsADetail::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQPrsADetail");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "x1SrefKType", "typ", x1SrefKType);
		extractStringUclc(docctx, basexpath, "titX1SrefKType", "typ2", titX1SrefKType);
		extractStringUclc(docctx, basexpath, "Val", "val", Val);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQPrsADetail
 ******************************************************************************/

ListWdbeQPrsADetail::ListWdbeQPrsADetail() {
};

ListWdbeQPrsADetail::ListWdbeQPrsADetail(
			const ListWdbeQPrsADetail& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrsADetail(*(src.nodes[i]));
};

ListWdbeQPrsADetail& ListWdbeQPrsADetail::operator=(
			const ListWdbeQPrsADetail& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrsADetail(*(src.nodes[i]));

	return *this;
};

ListWdbeQPrsADetail::~ListWdbeQPrsADetail() {
	clear();
};

void ListWdbeQPrsADetail::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQPrsADetail::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQPrsADetail* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQPrsADetail");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQPrsADetail", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQPrsADetail(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQPrsADetail[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
