/**
	* \file WdbeQVarList.cpp
	* API code for table TblWdbeQVarList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQVarList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQVarList
 ******************************************************************************/

WdbeQVarList::WdbeQVarList(
			const uint jnum
			, const string sref
			, const string stubPrcRefWdbeMProcess
			, const string yesnoConst
			, const string yesnoFalling
			, const string srefWdbeKHdltype
			, const string titSrefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubPrcRefWdbeMProcess = stubPrcRefWdbeMProcess;
	this->yesnoConst = yesnoConst;
	this->yesnoFalling = yesnoFalling;
	this->srefWdbeKHdltype = srefWdbeKHdltype;
	this->titSrefWdbeKHdltype = titSrefWdbeKHdltype;
	this->Width = Width;
	this->Minmax = Minmax;
};

bool WdbeQVarList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQVarList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubPrcRefWdbeMProcess", "prc", stubPrcRefWdbeMProcess);
		extractStringUclc(docctx, basexpath, "yesnoConst", "con", yesnoConst);
		extractStringUclc(docctx, basexpath, "yesnoFalling", "fal", yesnoFalling);
		extractStringUclc(docctx, basexpath, "srefWdbeKHdltype", "hty", srefWdbeKHdltype);
		extractStringUclc(docctx, basexpath, "titSrefWdbeKHdltype", "hty2", titSrefWdbeKHdltype);
		extractUsmallintUclc(docctx, basexpath, "Width", "wid", Width);
		extractStringUclc(docctx, basexpath, "Minmax", "mmx", Minmax);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQVarList
 ******************************************************************************/

ListWdbeQVarList::ListWdbeQVarList() {
};

ListWdbeQVarList::ListWdbeQVarList(
			const ListWdbeQVarList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQVarList(*(src.nodes[i]));
};

ListWdbeQVarList& ListWdbeQVarList::operator=(
			const ListWdbeQVarList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQVarList(*(src.nodes[i]));

	return *this;
};

ListWdbeQVarList::~ListWdbeQVarList() {
	clear();
};

void ListWdbeQVarList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQVarList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQVarList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQVarList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQVarList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQVarList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQVarList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

