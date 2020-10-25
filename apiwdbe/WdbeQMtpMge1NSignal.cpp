/**
	* \file WdbeQMtpMge1NSignal.cpp
	* API code for table TblWdbeQMtpMge1NSignal (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQMtpMge1NSignal.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQMtpMge1NSignal
 ******************************************************************************/

WdbeQMtpMge1NSignal::WdbeQMtpMge1NSignal(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQMtpMge1NSignal::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQMtpMge1NSignal");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQMtpMge1NSignal
 ******************************************************************************/

ListWdbeQMtpMge1NSignal::ListWdbeQMtpMge1NSignal() {
};

ListWdbeQMtpMge1NSignal::ListWdbeQMtpMge1NSignal(
			const ListWdbeQMtpMge1NSignal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMtpMge1NSignal(*(src.nodes[i]));
};

ListWdbeQMtpMge1NSignal& ListWdbeQMtpMge1NSignal::operator=(
			const ListWdbeQMtpMge1NSignal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMtpMge1NSignal(*(src.nodes[i]));

	return *this;
};

ListWdbeQMtpMge1NSignal::~ListWdbeQMtpMge1NSignal() {
	clear();
};

void ListWdbeQMtpMge1NSignal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQMtpMge1NSignal::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQMtpMge1NSignal* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQMtpMge1NSignal");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQMtpMge1NSignal", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQMtpMge1NSignal(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQMtpMge1NSignal[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

