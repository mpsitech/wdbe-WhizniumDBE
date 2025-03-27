/**
	* \file WdbeQCprList.cpp
	* API code for table TblWdbeQCprList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQCprList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCprList
 ******************************************************************************/

WdbeQCprList::WdbeQCprList(
			const uint jnum
			, const string stubGrp
			, const string stubOwn
			, const string sref
			, const string Title
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string stubRefWdbeMCoreversion
			, const string Giturl
		) :
			jnum(jnum)
			, stubGrp(stubGrp)
			, stubOwn(stubOwn)
			, sref(sref)
			, Title(Title)
			, srefIxVBasetype(srefIxVBasetype)
			, titIxVBasetype(titIxVBasetype)
			, stubRefWdbeMCoreversion(stubRefWdbeMCoreversion)
			, Giturl(Giturl)
		{
};

bool WdbeQCprList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQCprList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubGrp", "grp", stubGrp);
		extractStringUclc(docctx, basexpath, "stubOwn", "own", stubOwn);
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMCoreversion", "cvr", stubRefWdbeMCoreversion);
		extractStringUclc(docctx, basexpath, "Giturl", "grl", Giturl);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQCprList
 ******************************************************************************/

ListWdbeQCprList::ListWdbeQCprList() {
};

ListWdbeQCprList::ListWdbeQCprList(
			const ListWdbeQCprList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCprList(*(src.nodes[i]));
};

ListWdbeQCprList& ListWdbeQCprList::operator=(
			const ListWdbeQCprList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCprList(*(src.nodes[i]));

	return *this;
};

ListWdbeQCprList::~ListWdbeQCprList() {
	clear();
};

void ListWdbeQCprList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQCprList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQCprList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQCprList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQCprList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQCprList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQCprList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
