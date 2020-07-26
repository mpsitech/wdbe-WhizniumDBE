/**
	* \file WdbeQGenList.cpp
	* API code for table TblWdbeQGenList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeQGenList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQGenList
 ******************************************************************************/

WdbeQGenList::WdbeQGenList(
			const uint jnum
			, const string sref
			, const string stubMdlRefWdbeMModule
			, const string srefWdbeKHdltype
			, const string titSrefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubMdlRefWdbeMModule = stubMdlRefWdbeMModule;
	this->srefWdbeKHdltype = srefWdbeKHdltype;
	this->titSrefWdbeKHdltype = titSrefWdbeKHdltype;
	this->Width = Width;
	this->Minmax = Minmax;
};

bool WdbeQGenList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQGenList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubMdlRefWdbeMModule", "mdl", stubMdlRefWdbeMModule);
		extractStringUclc(docctx, basexpath, "srefWdbeKHdltype", "hty", srefWdbeKHdltype);
		extractStringUclc(docctx, basexpath, "titSrefWdbeKHdltype", "hty2", titSrefWdbeKHdltype);
		extractUsmallintUclc(docctx, basexpath, "Width", "wid", Width);
		extractStringUclc(docctx, basexpath, "Minmax", "mmx", Minmax);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQGenList
 ******************************************************************************/

ListWdbeQGenList::ListWdbeQGenList() {
};

ListWdbeQGenList::ListWdbeQGenList(
			const ListWdbeQGenList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQGenList(*(src.nodes[i]));
};

ListWdbeQGenList& ListWdbeQGenList::operator=(
			const ListWdbeQGenList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQGenList(*(src.nodes[i]));

	return *this;
};

ListWdbeQGenList::~ListWdbeQGenList() {
	clear();
};

void ListWdbeQGenList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQGenList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQGenList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQGenList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQGenList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQGenList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQGenList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

