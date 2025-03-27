/**
	* \file WdbeQSnsList.cpp
	* API code for table TblWdbeQSnsList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeQSnsList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQSnsList
 ******************************************************************************/

WdbeQSnsList::WdbeQSnsList(
			const uint jnum
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const string stubRefUref
			, const string srefSrcIxVTbl
			, const string titSrcIxVTbl
			, const string stubSrcUref
		) :
			jnum(jnum)
			, srefRefIxVTbl(srefRefIxVTbl)
			, titRefIxVTbl(titRefIxVTbl)
			, stubRefUref(stubRefUref)
			, srefSrcIxVTbl(srefSrcIxVTbl)
			, titSrcIxVTbl(titSrcIxVTbl)
			, stubSrcUref(stubSrcUref)
		{
};

bool WdbeQSnsList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQSnsList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl);
		extractStringUclc(docctx, basexpath, "titRefIxVTbl", "ret2", titRefIxVTbl);
		extractStringUclc(docctx, basexpath, "stubRefUref", "reu", stubRefUref);
		extractStringUclc(docctx, basexpath, "srefSrcIxVTbl", "srt", srefSrcIxVTbl);
		extractStringUclc(docctx, basexpath, "titSrcIxVTbl", "srt2", titSrcIxVTbl);
		extractStringUclc(docctx, basexpath, "stubSrcUref", "sru", stubSrcUref);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQSnsList
 ******************************************************************************/

ListWdbeQSnsList::ListWdbeQSnsList() {
};

ListWdbeQSnsList::ListWdbeQSnsList(
			const ListWdbeQSnsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSnsList(*(src.nodes[i]));
};

ListWdbeQSnsList& ListWdbeQSnsList::operator=(
			const ListWdbeQSnsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSnsList(*(src.nodes[i]));

	return *this;
};

ListWdbeQSnsList::~ListWdbeQSnsList() {
	clear();
};

void ListWdbeQSnsList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQSnsList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQSnsList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQSnsList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQSnsList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQSnsList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQSnsList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
