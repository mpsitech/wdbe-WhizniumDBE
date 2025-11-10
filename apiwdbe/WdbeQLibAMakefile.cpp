/**
	* \file WdbeQLibAMakefile.cpp
	* API code for table TblWdbeQLibAMakefile (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQLibAMakefile.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQLibAMakefile
 ******************************************************************************/

WdbeQLibAMakefile::WdbeQLibAMakefile(
			const uint jnum
			, const string stubX1RefWdbeMMachine
			, const string x2SrefKTag
			, const string titX2SrefKTag
			, const string Val
		) :
			jnum(jnum)
			, stubX1RefWdbeMMachine(stubX1RefWdbeMMachine)
			, x2SrefKTag(x2SrefKTag)
			, titX2SrefKTag(titX2SrefKTag)
			, Val(Val)
		{
};

bool WdbeQLibAMakefile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQLibAMakefile");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubX1RefWdbeMMachine", "mch", stubX1RefWdbeMMachine);
		extractStringUclc(docctx, basexpath, "x2SrefKTag", "tag", x2SrefKTag);
		extractStringUclc(docctx, basexpath, "titX2SrefKTag", "tag2", titX2SrefKTag);
		extractStringUclc(docctx, basexpath, "Val", "val", Val);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQLibAMakefile
 ******************************************************************************/

ListWdbeQLibAMakefile::ListWdbeQLibAMakefile() {
};

ListWdbeQLibAMakefile::ListWdbeQLibAMakefile(
			const ListWdbeQLibAMakefile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQLibAMakefile(*(src.nodes[i]));
};

ListWdbeQLibAMakefile& ListWdbeQLibAMakefile::operator=(
			const ListWdbeQLibAMakefile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQLibAMakefile(*(src.nodes[i]));

	return *this;
};

ListWdbeQLibAMakefile::~ListWdbeQLibAMakefile() {
	clear();
};

void ListWdbeQLibAMakefile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQLibAMakefile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQLibAMakefile* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQLibAMakefile");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQLibAMakefile", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQLibAMakefile(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQLibAMakefile[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
