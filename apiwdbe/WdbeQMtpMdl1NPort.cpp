/**
	* \file WdbeQMtpMdl1NPort.cpp
	* API code for table TblWdbeQMtpMdl1NPort (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQMtpMdl1NPort.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQMtpMdl1NPort
 ******************************************************************************/

WdbeQMtpMdl1NPort::WdbeQMtpMdl1NPort(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WdbeQMtpMdl1NPort::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQMtpMdl1NPort");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQMtpMdl1NPort
 ******************************************************************************/

ListWdbeQMtpMdl1NPort::ListWdbeQMtpMdl1NPort() {
};

ListWdbeQMtpMdl1NPort::ListWdbeQMtpMdl1NPort(
			const ListWdbeQMtpMdl1NPort& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMtpMdl1NPort(*(src.nodes[i]));
};

ListWdbeQMtpMdl1NPort& ListWdbeQMtpMdl1NPort::operator=(
			const ListWdbeQMtpMdl1NPort& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMtpMdl1NPort(*(src.nodes[i]));

	return *this;
};

ListWdbeQMtpMdl1NPort::~ListWdbeQMtpMdl1NPort() {
	clear();
};

void ListWdbeQMtpMdl1NPort::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQMtpMdl1NPort::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQMtpMdl1NPort* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQMtpMdl1NPort");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQMtpMdl1NPort", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQMtpMdl1NPort(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQMtpMdl1NPort[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

