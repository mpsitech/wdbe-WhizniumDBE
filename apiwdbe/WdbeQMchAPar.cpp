/**
	* \file WdbeQMchAPar.cpp
	* API code for table TblWdbeQMchAPar (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQMchAPar.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQMchAPar
 ******************************************************************************/

WdbeQMchAPar::WdbeQMchAPar(
			const uint jnum
			, const string x1SrefKKey
			, const string titX1SrefKKey
			, const string Val
		) {
	this->jnum = jnum;
	this->x1SrefKKey = x1SrefKKey;
	this->titX1SrefKKey = titX1SrefKKey;
	this->Val = Val;
};

bool WdbeQMchAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQMchAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "x1SrefKKey", "key", x1SrefKKey);
		extractStringUclc(docctx, basexpath, "titX1SrefKKey", "key2", titX1SrefKKey);
		extractStringUclc(docctx, basexpath, "Val", "val", Val);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQMchAPar
 ******************************************************************************/

ListWdbeQMchAPar::ListWdbeQMchAPar() {
};

ListWdbeQMchAPar::ListWdbeQMchAPar(
			const ListWdbeQMchAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMchAPar(*(src.nodes[i]));
};

ListWdbeQMchAPar& ListWdbeQMchAPar::operator=(
			const ListWdbeQMchAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMchAPar(*(src.nodes[i]));

	return *this;
};

ListWdbeQMchAPar::~ListWdbeQMchAPar() {
	clear();
};

void ListWdbeQMchAPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQMchAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQMchAPar* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQMchAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQMchAPar", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQMchAPar(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQMchAPar[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

