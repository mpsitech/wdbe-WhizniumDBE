/**
	* \file WdbeQVerList.cpp
	* API code for table TblWdbeQVerList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQVerList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQVerList
 ******************************************************************************/

WdbeQVerList::WdbeQVerList(
			const uint jnum
			, const string stubGrp
			, const string stubOwn
			, const string stubPrjRefWdbeMProject
			, const usmallint Major
			, const usmallint Minor
			, const usmallint Sub
			, const string stubBvrRefWdbeMVersion
			, const string srefIxVState
			, const string titIxVState
		) {
	this->jnum = jnum;
	this->stubGrp = stubGrp;
	this->stubOwn = stubOwn;
	this->stubPrjRefWdbeMProject = stubPrjRefWdbeMProject;
	this->Major = Major;
	this->Minor = Minor;
	this->Sub = Sub;
	this->stubBvrRefWdbeMVersion = stubBvrRefWdbeMVersion;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
};

bool WdbeQVerList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQVerList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubGrp", "grp", stubGrp);
		extractStringUclc(docctx, basexpath, "stubOwn", "own", stubOwn);
		extractStringUclc(docctx, basexpath, "stubPrjRefWdbeMProject", "prj", stubPrjRefWdbeMProject);
		extractUsmallintUclc(docctx, basexpath, "Major", "maj", Major);
		extractUsmallintUclc(docctx, basexpath, "Minor", "min", Minor);
		extractUsmallintUclc(docctx, basexpath, "Sub", "sub", Sub);
		extractStringUclc(docctx, basexpath, "stubBvrRefWdbeMVersion", "bvr", stubBvrRefWdbeMVersion);
		extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState);
		extractStringUclc(docctx, basexpath, "titIxVState", "ste2", titIxVState);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQVerList
 ******************************************************************************/

ListWdbeQVerList::ListWdbeQVerList() {
};

ListWdbeQVerList::ListWdbeQVerList(
			const ListWdbeQVerList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQVerList(*(src.nodes[i]));
};

ListWdbeQVerList& ListWdbeQVerList::operator=(
			const ListWdbeQVerList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQVerList(*(src.nodes[i]));

	return *this;
};

ListWdbeQVerList::~ListWdbeQVerList() {
	clear();
};

void ListWdbeQVerList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQVerList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQVerList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQVerList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQVerList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQVerList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQVerList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
