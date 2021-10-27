/**
	* \file WdbeQMtpList.cpp
	* API code for table TblWdbeQMtpList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQMtpList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQMtpList
 ******************************************************************************/

WdbeQMtpList::WdbeQMtpList(
			const uint jnum
			, const string sref
			, const string srefWdbeKVendor
			, const string titSrefWdbeKVendor
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const string stubHkUref
			, const string Srefrule
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->srefWdbeKVendor = srefWdbeKVendor;
	this->titSrefWdbeKVendor = titSrefWdbeKVendor;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->srefHkIxVTbl = srefHkIxVTbl;
	this->titHkIxVTbl = titHkIxVTbl;
	this->stubHkUref = stubHkUref;
	this->Srefrule = Srefrule;
};

bool WdbeQMtpList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQMtpList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefWdbeKVendor", "vnd", srefWdbeKVendor);
		extractStringUclc(docctx, basexpath, "titSrefWdbeKVendor", "vnd2", titSrefWdbeKVendor);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "srefHkIxVTbl", "hkt", srefHkIxVTbl);
		extractStringUclc(docctx, basexpath, "titHkIxVTbl", "hkt2", titHkIxVTbl);
		extractStringUclc(docctx, basexpath, "stubHkUref", "hku", stubHkUref);
		extractStringUclc(docctx, basexpath, "Srefrule", "srr", Srefrule);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQMtpList
 ******************************************************************************/

ListWdbeQMtpList::ListWdbeQMtpList() {
};

ListWdbeQMtpList::ListWdbeQMtpList(
			const ListWdbeQMtpList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMtpList(*(src.nodes[i]));
};

ListWdbeQMtpList& ListWdbeQMtpList::operator=(
			const ListWdbeQMtpList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMtpList(*(src.nodes[i]));

	return *this;
};

ListWdbeQMtpList::~ListWdbeQMtpList() {
	clear();
};

void ListWdbeQMtpList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQMtpList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQMtpList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQMtpList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQMtpList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQMtpList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQMtpList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
