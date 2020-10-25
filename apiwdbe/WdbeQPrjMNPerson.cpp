/**
	* \file WdbeQPrjMNPerson.cpp
	* API code for table TblWdbeQPrjMNPerson (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQPrjMNPerson.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPrjMNPerson
 ******************************************************************************/

WdbeQPrjMNPerson::WdbeQPrjMNPerson(
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

bool WdbeQPrjMNPerson::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQPrjMNPerson");
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
 class ListWdbeQPrjMNPerson
 ******************************************************************************/

ListWdbeQPrjMNPerson::ListWdbeQPrjMNPerson() {
};

ListWdbeQPrjMNPerson::ListWdbeQPrjMNPerson(
			const ListWdbeQPrjMNPerson& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrjMNPerson(*(src.nodes[i]));
};

ListWdbeQPrjMNPerson& ListWdbeQPrjMNPerson::operator=(
			const ListWdbeQPrjMNPerson& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrjMNPerson(*(src.nodes[i]));

	return *this;
};

ListWdbeQPrjMNPerson::~ListWdbeQPrjMNPerson() {
	clear();
};

void ListWdbeQPrjMNPerson::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQPrjMNPerson::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQPrjMNPerson* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQPrjMNPerson");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQPrjMNPerson", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQPrjMNPerson(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQPrjMNPerson[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

