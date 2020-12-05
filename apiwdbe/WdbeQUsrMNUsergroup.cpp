/**
	* \file WdbeQUsrMNUsergroup.cpp
	* API code for table TblWdbeQUsrMNUsergroup (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQUsrMNUsergroup.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQUsrMNUsergroup
 ******************************************************************************/

WdbeQUsrMNUsergroup::WdbeQUsrMNUsergroup(
			const uint jnum
			, const string stubMref
			, const string srefIxWdbeVUserlevel
			, const string titIxWdbeVUserlevel
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->srefIxWdbeVUserlevel = srefIxWdbeVUserlevel;
	this->titIxWdbeVUserlevel = titIxWdbeVUserlevel;
};

bool WdbeQUsrMNUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQUsrMNUsergroup");
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
 class ListWdbeQUsrMNUsergroup
 ******************************************************************************/

ListWdbeQUsrMNUsergroup::ListWdbeQUsrMNUsergroup() {
};

ListWdbeQUsrMNUsergroup::ListWdbeQUsrMNUsergroup(
			const ListWdbeQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUsrMNUsergroup(*(src.nodes[i]));
};

ListWdbeQUsrMNUsergroup& ListWdbeQUsrMNUsergroup::operator=(
			const ListWdbeQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUsrMNUsergroup(*(src.nodes[i]));

	return *this;
};

ListWdbeQUsrMNUsergroup::~ListWdbeQUsrMNUsergroup() {
	clear();
};

void ListWdbeQUsrMNUsergroup::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQUsrMNUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQUsrMNUsergroup* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQUsrMNUsergroup");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQUsrMNUsergroup", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQUsrMNUsergroup(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQUsrMNUsergroup[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

