/**
	* \file WdbeQMtpMdl1NGeneric.cpp
	* API code for table TblWdbeQMtpMdl1NGeneric (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQMtpMdl1NGeneric.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQMtpMdl1NGeneric
 ******************************************************************************/

WdbeQMtpMdl1NGeneric::WdbeQMtpMdl1NGeneric(
			const uint jnum
			, const string stubRef
		) :
			jnum(jnum)
			, stubRef(stubRef)
		{
};

bool WdbeQMtpMdl1NGeneric::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQMtpMdl1NGeneric");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQMtpMdl1NGeneric
 ******************************************************************************/

ListWdbeQMtpMdl1NGeneric::ListWdbeQMtpMdl1NGeneric() {
};

ListWdbeQMtpMdl1NGeneric::ListWdbeQMtpMdl1NGeneric(
			const ListWdbeQMtpMdl1NGeneric& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMtpMdl1NGeneric(*(src.nodes[i]));
};

ListWdbeQMtpMdl1NGeneric& ListWdbeQMtpMdl1NGeneric::operator=(
			const ListWdbeQMtpMdl1NGeneric& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMtpMdl1NGeneric(*(src.nodes[i]));

	return *this;
};

ListWdbeQMtpMdl1NGeneric::~ListWdbeQMtpMdl1NGeneric() {
	clear();
};

void ListWdbeQMtpMdl1NGeneric::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQMtpMdl1NGeneric::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQMtpMdl1NGeneric* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQMtpMdl1NGeneric");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQMtpMdl1NGeneric", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQMtpMdl1NGeneric(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQMtpMdl1NGeneric[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
