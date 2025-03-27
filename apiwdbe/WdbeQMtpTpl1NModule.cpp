/**
	* \file WdbeQMtpTpl1NModule.cpp
	* API code for table TblWdbeQMtpTpl1NModule (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQMtpTpl1NModule.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQMtpTpl1NModule
 ******************************************************************************/

WdbeQMtpTpl1NModule::WdbeQMtpTpl1NModule(
			const uint jnum
			, const string stubRef
		) :
			jnum(jnum)
			, stubRef(stubRef)
		{
};

bool WdbeQMtpTpl1NModule::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQMtpTpl1NModule");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQMtpTpl1NModule
 ******************************************************************************/

ListWdbeQMtpTpl1NModule::ListWdbeQMtpTpl1NModule() {
};

ListWdbeQMtpTpl1NModule::ListWdbeQMtpTpl1NModule(
			const ListWdbeQMtpTpl1NModule& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMtpTpl1NModule(*(src.nodes[i]));
};

ListWdbeQMtpTpl1NModule& ListWdbeQMtpTpl1NModule::operator=(
			const ListWdbeQMtpTpl1NModule& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMtpTpl1NModule(*(src.nodes[i]));

	return *this;
};

ListWdbeQMtpTpl1NModule::~ListWdbeQMtpTpl1NModule() {
	clear();
};

void ListWdbeQMtpTpl1NModule::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQMtpTpl1NModule::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQMtpTpl1NModule* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQMtpTpl1NModule");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQMtpTpl1NModule", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQMtpTpl1NModule(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQMtpTpl1NModule[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
