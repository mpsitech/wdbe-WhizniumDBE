/**
	* \file WdbeQCmdList.cpp
	* API code for table TblWdbeQCmdList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQCmdList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCmdList
 ******************************************************************************/

WdbeQCmdList::WdbeQCmdList(
			const uint jnum
			, const string sref
			, const string Fullsref
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const string stubRefUref
			, const string srefIxVRettype
			, const string titIxVRettype
		) :
			jnum(jnum)
			, sref(sref)
			, Fullsref(Fullsref)
			, srefRefIxVTbl(srefRefIxVTbl)
			, titRefIxVTbl(titRefIxVTbl)
			, stubRefUref(stubRefUref)
			, srefIxVRettype(srefIxVRettype)
			, titIxVRettype(titIxVRettype)
		{
};

bool WdbeQCmdList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQCmdList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Fullsref", "fsr", Fullsref);
		extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl);
		extractStringUclc(docctx, basexpath, "titRefIxVTbl", "ret2", titRefIxVTbl);
		extractStringUclc(docctx, basexpath, "stubRefUref", "reu", stubRefUref);
		extractStringUclc(docctx, basexpath, "srefIxVRettype", "rty", srefIxVRettype);
		extractStringUclc(docctx, basexpath, "titIxVRettype", "rty2", titIxVRettype);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQCmdList
 ******************************************************************************/

ListWdbeQCmdList::ListWdbeQCmdList() {
};

ListWdbeQCmdList::ListWdbeQCmdList(
			const ListWdbeQCmdList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCmdList(*(src.nodes[i]));
};

ListWdbeQCmdList& ListWdbeQCmdList::operator=(
			const ListWdbeQCmdList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCmdList(*(src.nodes[i]));

	return *this;
};

ListWdbeQCmdList::~ListWdbeQCmdList() {
	clear();
};

void ListWdbeQCmdList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQCmdList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQCmdList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQCmdList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQCmdList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQCmdList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQCmdList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
