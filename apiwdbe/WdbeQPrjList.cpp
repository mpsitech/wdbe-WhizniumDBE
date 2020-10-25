/**
	* \file WdbeQPrjList.cpp
	* API code for table TblWdbeQPrjList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQPrjList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPrjList
 ******************************************************************************/

WdbeQPrjList::WdbeQPrjList(
			const uint jnum
			, const string stubGrp
			, const string stubOwn
			, const string Short
			, const string Title
			, const string stubRefWdbeMVersion
			, const string yesnoEasy
			, const string Giturl
		) {
	this->jnum = jnum;
	this->stubGrp = stubGrp;
	this->stubOwn = stubOwn;
	this->Short = Short;
	this->Title = Title;
	this->stubRefWdbeMVersion = stubRefWdbeMVersion;
	this->yesnoEasy = yesnoEasy;
	this->Giturl = Giturl;
};

bool WdbeQPrjList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQPrjList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubGrp", "grp", stubGrp);
		extractStringUclc(docctx, basexpath, "stubOwn", "own", stubOwn);
		extractStringUclc(docctx, basexpath, "Short", "sho", Short);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMVersion", "ver", stubRefWdbeMVersion);
		extractStringUclc(docctx, basexpath, "yesnoEasy", "esy", yesnoEasy);
		extractStringUclc(docctx, basexpath, "Giturl", "grl", Giturl);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQPrjList
 ******************************************************************************/

ListWdbeQPrjList::ListWdbeQPrjList() {
};

ListWdbeQPrjList::ListWdbeQPrjList(
			const ListWdbeQPrjList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrjList(*(src.nodes[i]));
};

ListWdbeQPrjList& ListWdbeQPrjList::operator=(
			const ListWdbeQPrjList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrjList(*(src.nodes[i]));

	return *this;
};

ListWdbeQPrjList::~ListWdbeQPrjList() {
	clear();
};

void ListWdbeQPrjList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQPrjList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQPrjList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQPrjList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQPrjList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQPrjList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQPrjList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

