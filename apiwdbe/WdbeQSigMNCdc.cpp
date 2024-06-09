/**
	* \file WdbeQSigMNCdc.cpp
	* API code for table TblWdbeQSigMNCdc (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#include "WdbeQSigMNCdc.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQSigMNCdc
 ******************************************************************************/

WdbeQSigMNCdc::WdbeQSigMNCdc(
			const uint jnum
			, const string stubMref
			, const string srefIxVDir
			, const string titIxVDir
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->srefIxVDir = srefIxVDir;
	this->titIxVDir = titIxVDir;
};

bool WdbeQSigMNCdc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQSigMNCdc");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "srefIxVDir", "dir", srefIxVDir);
		extractStringUclc(docctx, basexpath, "titIxVDir", "dir2", titIxVDir);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQSigMNCdc
 ******************************************************************************/

ListWdbeQSigMNCdc::ListWdbeQSigMNCdc() {
};

ListWdbeQSigMNCdc::ListWdbeQSigMNCdc(
			const ListWdbeQSigMNCdc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSigMNCdc(*(src.nodes[i]));
};

ListWdbeQSigMNCdc& ListWdbeQSigMNCdc::operator=(
			const ListWdbeQSigMNCdc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSigMNCdc(*(src.nodes[i]));

	return *this;
};

ListWdbeQSigMNCdc::~ListWdbeQSigMNCdc() {
	clear();
};

void ListWdbeQSigMNCdc::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQSigMNCdc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQSigMNCdc* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQSigMNCdc");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQSigMNCdc", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQSigMNCdc(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQSigMNCdc[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
