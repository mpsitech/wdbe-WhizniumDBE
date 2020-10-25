/**
	* \file WdbeQCvrList.cpp
	* API code for table TblWdbeQCvrList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQCvrList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCvrList
 ******************************************************************************/

WdbeQCvrList::WdbeQCvrList(
			const uint jnum
			, const string stubGrp
			, const string stubOwn
			, const string stubRefWdbeMCoreproject
			, const usmallint Major
			, const usmallint Minor
			, const usmallint Sub
			, const string stubBcvRefWdbeMCoreversion
			, const string srefIxVState
			, const string titIxVState
		) {
	this->jnum = jnum;
	this->stubGrp = stubGrp;
	this->stubOwn = stubOwn;
	this->stubRefWdbeMCoreproject = stubRefWdbeMCoreproject;
	this->Major = Major;
	this->Minor = Minor;
	this->Sub = Sub;
	this->stubBcvRefWdbeMCoreversion = stubBcvRefWdbeMCoreversion;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
};

bool WdbeQCvrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQCvrList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubGrp", "grp", stubGrp);
		extractStringUclc(docctx, basexpath, "stubOwn", "own", stubOwn);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMCoreproject", "cpr", stubRefWdbeMCoreproject);
		extractUsmallintUclc(docctx, basexpath, "Major", "maj", Major);
		extractUsmallintUclc(docctx, basexpath, "Minor", "min", Minor);
		extractUsmallintUclc(docctx, basexpath, "Sub", "sub", Sub);
		extractStringUclc(docctx, basexpath, "stubBcvRefWdbeMCoreversion", "bcv", stubBcvRefWdbeMCoreversion);
		extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState);
		extractStringUclc(docctx, basexpath, "titIxVState", "ste2", titIxVState);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQCvrList
 ******************************************************************************/

ListWdbeQCvrList::ListWdbeQCvrList() {
};

ListWdbeQCvrList::ListWdbeQCvrList(
			const ListWdbeQCvrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCvrList(*(src.nodes[i]));
};

ListWdbeQCvrList& ListWdbeQCvrList::operator=(
			const ListWdbeQCvrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCvrList(*(src.nodes[i]));

	return *this;
};

ListWdbeQCvrList::~ListWdbeQCvrList() {
	clear();
};

void ListWdbeQCvrList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQCvrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQCvrList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQCvrList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQCvrList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQCvrList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQCvrList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

