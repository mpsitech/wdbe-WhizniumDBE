/**
	* \file WdbeQUsgMNUser.cpp
	* API code for table TblWdbeQUsgMNUser (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQUsgMNUser.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQUsgMNUser
 ******************************************************************************/

WdbeQUsgMNUser::WdbeQUsgMNUser(
			const uint jnum
			, const string stubMref
			, const string srefIxWdbeVUserlevel
			, const string titIxWdbeVUserlevel
		) :
			jnum(jnum)
			, stubMref(stubMref)
			, srefIxWdbeVUserlevel(srefIxWdbeVUserlevel)
			, titIxWdbeVUserlevel(titIxWdbeVUserlevel)
		{
};

bool WdbeQUsgMNUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQUsgMNUser");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "srefIxWdbeVUserlevel", "ulv", srefIxWdbeVUserlevel);
		extractStringUclc(docctx, basexpath, "titIxWdbeVUserlevel", "ulv2", titIxWdbeVUserlevel);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQUsgMNUser
 ******************************************************************************/

ListWdbeQUsgMNUser::ListWdbeQUsgMNUser() {
};

ListWdbeQUsgMNUser::ListWdbeQUsgMNUser(
			const ListWdbeQUsgMNUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUsgMNUser(*(src.nodes[i]));
};

ListWdbeQUsgMNUser& ListWdbeQUsgMNUser::operator=(
			const ListWdbeQUsgMNUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUsgMNUser(*(src.nodes[i]));

	return *this;
};

ListWdbeQUsgMNUser::~ListWdbeQUsgMNUser() {
	clear();
};

void ListWdbeQUsgMNUser::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQUsgMNUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQUsgMNUser* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQUsgMNUser");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQUsgMNUser", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQUsgMNUser(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQUsgMNUser[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
