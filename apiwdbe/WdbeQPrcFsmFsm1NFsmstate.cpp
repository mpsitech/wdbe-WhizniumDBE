/**
	* \file WdbeQPrcFsmFsm1NFsmstate.cpp
	* API code for table TblWdbeQPrcFsmFsm1NFsmstate (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQPrcFsmFsm1NFsmstate.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPrcFsmFsm1NFsmstate
 ******************************************************************************/

WdbeQPrcFsmFsm1NFsmstate::WdbeQPrcFsmFsm1NFsmstate(
			const uint jnum
			, const string stubRef
		) :
			jnum(jnum)
			, stubRef(stubRef)
		{
};

bool WdbeQPrcFsmFsm1NFsmstate::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQPrcFsmFsm1NFsmstate");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQPrcFsmFsm1NFsmstate
 ******************************************************************************/

ListWdbeQPrcFsmFsm1NFsmstate::ListWdbeQPrcFsmFsm1NFsmstate() {
};

ListWdbeQPrcFsmFsm1NFsmstate::ListWdbeQPrcFsmFsm1NFsmstate(
			const ListWdbeQPrcFsmFsm1NFsmstate& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrcFsmFsm1NFsmstate(*(src.nodes[i]));
};

ListWdbeQPrcFsmFsm1NFsmstate& ListWdbeQPrcFsmFsm1NFsmstate::operator=(
			const ListWdbeQPrcFsmFsm1NFsmstate& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrcFsmFsm1NFsmstate(*(src.nodes[i]));

	return *this;
};

ListWdbeQPrcFsmFsm1NFsmstate::~ListWdbeQPrcFsmFsm1NFsmstate() {
	clear();
};

void ListWdbeQPrcFsmFsm1NFsmstate::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQPrcFsmFsm1NFsmstate::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQPrcFsmFsm1NFsmstate* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQPrcFsmFsm1NFsmstate");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQPrcFsmFsm1NFsmstate", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQPrcFsmFsm1NFsmstate(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQPrcFsmFsm1NFsmstate[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
