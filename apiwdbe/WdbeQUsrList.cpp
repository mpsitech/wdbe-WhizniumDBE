/**
	* \file WdbeQUsrList.cpp
	* API code for table TblWdbeQUsrList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQUsrList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQUsrList
 ******************************************************************************/

WdbeQUsrList::WdbeQUsrList(
			const uint jnum
			, const string stubGrp
			, const string stubOwn
			, const string stubRefWdbeMPerson
			, const string sref
			, const string stubRefWdbeMUsergroup
			, const string srefIxVState
			, const string titIxVState
			, const string srefIxWdbeVLocale
			, const string titIxWdbeVLocale
			, const string srefIxWdbeVUserlevel
			, const string titIxWdbeVUserlevel
		) {
	this->jnum = jnum;
	this->stubGrp = stubGrp;
	this->stubOwn = stubOwn;
	this->stubRefWdbeMPerson = stubRefWdbeMPerson;
	this->sref = sref;
	this->stubRefWdbeMUsergroup = stubRefWdbeMUsergroup;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->srefIxWdbeVLocale = srefIxWdbeVLocale;
	this->titIxWdbeVLocale = titIxWdbeVLocale;
	this->srefIxWdbeVUserlevel = srefIxWdbeVUserlevel;
	this->titIxWdbeVUserlevel = titIxWdbeVUserlevel;
};

bool WdbeQUsrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubGrp", "grp", stubGrp);
		extractStringUclc(docctx, basexpath, "stubOwn", "own", stubOwn);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMPerson", "prs", stubRefWdbeMPerson);
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMUsergroup", "usg", stubRefWdbeMUsergroup);
		extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState);
		extractStringUclc(docctx, basexpath, "titIxVState", "ste2", titIxVState);
		extractStringUclc(docctx, basexpath, "srefIxWdbeVLocale", "lcl", srefIxWdbeVLocale);
		extractStringUclc(docctx, basexpath, "titIxWdbeVLocale", "lcl2", titIxWdbeVLocale);
		extractStringUclc(docctx, basexpath, "srefIxWdbeVUserlevel", "ulv", srefIxWdbeVUserlevel);
		extractStringUclc(docctx, basexpath, "titIxWdbeVUserlevel", "ulv2", titIxWdbeVUserlevel);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQUsrList
 ******************************************************************************/

ListWdbeQUsrList::ListWdbeQUsrList() {
};

ListWdbeQUsrList::ListWdbeQUsrList(
			const ListWdbeQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUsrList(*(src.nodes[i]));
};

ListWdbeQUsrList& ListWdbeQUsrList::operator=(
			const ListWdbeQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUsrList(*(src.nodes[i]));

	return *this;
};

ListWdbeQUsrList::~ListWdbeQUsrList() {
	clear();
};

void ListWdbeQUsrList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQUsrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQUsrList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQUsrList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQUsrList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQUsrList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

