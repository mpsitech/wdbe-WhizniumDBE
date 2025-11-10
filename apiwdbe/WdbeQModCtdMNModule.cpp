/**
	* \file WdbeQModCtdMNModule.cpp
	* API code for table TblWdbeQModCtdMNModule (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 Oct 2021
  */
// IP header --- ABOVE

#include "WdbeQModCtdMNModule.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQModCtdMNModule
 ******************************************************************************/

WdbeQModCtdMNModule::WdbeQModCtdMNModule(
			const uint jnum
			, const string stubMref
			, const string srefKFunction
			, const string titSrefKFunction
		) :
			jnum(jnum)
			, stubMref(stubMref)
			, srefKFunction(srefKFunction)
			, titSrefKFunction(titSrefKFunction)
		{
};

bool WdbeQModCtdMNModule::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQModCtdMNModule");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "srefKFunction", "fct", srefKFunction);
		extractStringUclc(docctx, basexpath, "titSrefKFunction", "fct2", titSrefKFunction);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQModCtdMNModule
 ******************************************************************************/

ListWdbeQModCtdMNModule::ListWdbeQModCtdMNModule() {
};

ListWdbeQModCtdMNModule::ListWdbeQModCtdMNModule(
			const ListWdbeQModCtdMNModule& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModCtdMNModule(*(src.nodes[i]));
};

ListWdbeQModCtdMNModule& ListWdbeQModCtdMNModule::operator=(
			const ListWdbeQModCtdMNModule& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModCtdMNModule(*(src.nodes[i]));

	return *this;
};

ListWdbeQModCtdMNModule::~ListWdbeQModCtdMNModule() {
	clear();
};

void ListWdbeQModCtdMNModule::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQModCtdMNModule::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQModCtdMNModule* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQModCtdMNModule");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQModCtdMNModule", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQModCtdMNModule(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQModCtdMNModule[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
