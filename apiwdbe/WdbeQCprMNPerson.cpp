/**
	* \file WdbeQCprMNPerson.cpp
	* API code for table TblWdbeQCprMNPerson (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQCprMNPerson.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCprMNPerson
 ******************************************************************************/

WdbeQCprMNPerson::WdbeQCprMNPerson(
			const uint jnum
			, const string stubMref
			, const string ftmX1Startd
			, const string ftmX1Stopd
			, const string srefKFunction
			, const string titSrefKFunction
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->ftmX1Startd = ftmX1Startd;
	this->ftmX1Stopd = ftmX1Stopd;
	this->srefKFunction = srefKFunction;
	this->titSrefKFunction = titSrefKFunction;
};

bool WdbeQCprMNPerson::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQCprMNPerson");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "ftmX1Startd", "sta", ftmX1Startd);
		extractStringUclc(docctx, basexpath, "ftmX1Stopd", "sto", ftmX1Stopd);
		extractStringUclc(docctx, basexpath, "srefKFunction", "fct", srefKFunction);
		extractStringUclc(docctx, basexpath, "titSrefKFunction", "fct2", titSrefKFunction);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQCprMNPerson
 ******************************************************************************/

ListWdbeQCprMNPerson::ListWdbeQCprMNPerson() {
};

ListWdbeQCprMNPerson::ListWdbeQCprMNPerson(
			const ListWdbeQCprMNPerson& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCprMNPerson(*(src.nodes[i]));
};

ListWdbeQCprMNPerson& ListWdbeQCprMNPerson::operator=(
			const ListWdbeQCprMNPerson& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCprMNPerson(*(src.nodes[i]));

	return *this;
};

ListWdbeQCprMNPerson::~ListWdbeQCprMNPerson() {
	clear();
};

void ListWdbeQCprMNPerson::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQCprMNPerson::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQCprMNPerson* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQCprMNPerson");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQCprMNPerson", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQCprMNPerson(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQCprMNPerson[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

