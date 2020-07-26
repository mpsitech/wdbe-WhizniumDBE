/**
	* \file WdbeQRlsList.cpp
	* API code for table TblWdbeQRlsList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeQRlsList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQRlsList
 ******************************************************************************/

WdbeQRlsList::WdbeQRlsList(
			const uint jnum
			, const string sref
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string stubRefWdbeMVersion
			, const string stubRefWdbeMMachine
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->stubRefWdbeMVersion = stubRefWdbeMVersion;
	this->stubRefWdbeMMachine = stubRefWdbeMMachine;
};

bool WdbeQRlsList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQRlsList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMVersion", "ver", stubRefWdbeMVersion);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMMachine", "mch", stubRefWdbeMMachine);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQRlsList
 ******************************************************************************/

ListWdbeQRlsList::ListWdbeQRlsList() {
};

ListWdbeQRlsList::ListWdbeQRlsList(
			const ListWdbeQRlsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQRlsList(*(src.nodes[i]));
};

ListWdbeQRlsList& ListWdbeQRlsList::operator=(
			const ListWdbeQRlsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQRlsList(*(src.nodes[i]));

	return *this;
};

ListWdbeQRlsList::~ListWdbeQRlsList() {
	clear();
};

void ListWdbeQRlsList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQRlsList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQRlsList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQRlsList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQRlsList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQRlsList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQRlsList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

