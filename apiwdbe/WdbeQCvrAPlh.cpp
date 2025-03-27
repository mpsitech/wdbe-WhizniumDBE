/**
	* \file WdbeQCvrAPlh.cpp
	* API code for table TblWdbeQCvrAPlh (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQCvrAPlh.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCvrAPlh
 ******************************************************************************/

WdbeQCvrAPlh::WdbeQCvrAPlh(
			const uint jnum
			, const string sref
			, const string Comment
		) :
			jnum(jnum)
			, sref(sref)
			, Comment(Comment)
		{
};

bool WdbeQCvrAPlh::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQCvrAPlh");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQCvrAPlh
 ******************************************************************************/

ListWdbeQCvrAPlh::ListWdbeQCvrAPlh() {
};

ListWdbeQCvrAPlh::ListWdbeQCvrAPlh(
			const ListWdbeQCvrAPlh& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCvrAPlh(*(src.nodes[i]));
};

ListWdbeQCvrAPlh& ListWdbeQCvrAPlh::operator=(
			const ListWdbeQCvrAPlh& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCvrAPlh(*(src.nodes[i]));

	return *this;
};

ListWdbeQCvrAPlh::~ListWdbeQCvrAPlh() {
	clear();
};

void ListWdbeQCvrAPlh::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQCvrAPlh::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQCvrAPlh* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQCvrAPlh");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQCvrAPlh", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQCvrAPlh(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQCvrAPlh[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
