/**
	* \file WdbeQPrtList.cpp
	* API code for table TblWdbeQPrtList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQPrtList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPrtList
 ******************************************************************************/

WdbeQPrtList::WdbeQPrtList(
			const uint jnum
			, const string sref
			, const string stubMdlRefWdbeMModule
			, const string srefMdlIxVCat
			, const string titMdlIxVCat
			, const string srefIxVDir
			, const string titIxVDir
			, const string srefWdbeKHdltype
			, const string titSrefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
		) :
			jnum(jnum)
			, sref(sref)
			, stubMdlRefWdbeMModule(stubMdlRefWdbeMModule)
			, srefMdlIxVCat(srefMdlIxVCat)
			, titMdlIxVCat(titMdlIxVCat)
			, srefIxVDir(srefIxVDir)
			, titIxVDir(titIxVDir)
			, srefWdbeKHdltype(srefWdbeKHdltype)
			, titSrefWdbeKHdltype(titSrefWdbeKHdltype)
			, Width(Width)
			, Minmax(Minmax)
		{
};

bool WdbeQPrtList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQPrtList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubMdlRefWdbeMModule", "mdl", stubMdlRefWdbeMModule);
		extractStringUclc(docctx, basexpath, "srefMdlIxVCat", "mdc", srefMdlIxVCat);
		extractStringUclc(docctx, basexpath, "titMdlIxVCat", "mdc2", titMdlIxVCat);
		extractStringUclc(docctx, basexpath, "srefIxVDir", "dir", srefIxVDir);
		extractStringUclc(docctx, basexpath, "titIxVDir", "dir2", titIxVDir);
		extractStringUclc(docctx, basexpath, "srefWdbeKHdltype", "hty", srefWdbeKHdltype);
		extractStringUclc(docctx, basexpath, "titSrefWdbeKHdltype", "hty2", titSrefWdbeKHdltype);
		extractUsmallintUclc(docctx, basexpath, "Width", "wid", Width);
		extractStringUclc(docctx, basexpath, "Minmax", "mmx", Minmax);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQPrtList
 ******************************************************************************/

ListWdbeQPrtList::ListWdbeQPrtList() {
};

ListWdbeQPrtList::ListWdbeQPrtList(
			const ListWdbeQPrtList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrtList(*(src.nodes[i]));
};

ListWdbeQPrtList& ListWdbeQPrtList::operator=(
			const ListWdbeQPrtList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrtList(*(src.nodes[i]));

	return *this;
};

ListWdbeQPrtList::~ListWdbeQPrtList() {
	clear();
};

void ListWdbeQPrtList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQPrtList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQPrtList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQPrtList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQPrtList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQPrtList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQPrtList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
