/**
	* \file WdbeQSigList.cpp
	* API code for table TblWdbeQSigList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQSigList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQSigList
 ******************************************************************************/

WdbeQSigList::WdbeQSigList(
			const uint jnum
			, const string sref
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string stubMdlRefWdbeMModule
			, const string srefMgeIxVTbl
			, const string titMgeIxVTbl
			, const string stubMgeUref
			, const string stubRefWdbeMVector
			, const string yesnoConst
			, const string srefWdbeKHdltype
			, const string titSrefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->stubMdlRefWdbeMModule = stubMdlRefWdbeMModule;
	this->srefMgeIxVTbl = srefMgeIxVTbl;
	this->titMgeIxVTbl = titMgeIxVTbl;
	this->stubMgeUref = stubMgeUref;
	this->stubRefWdbeMVector = stubRefWdbeMVector;
	this->yesnoConst = yesnoConst;
	this->srefWdbeKHdltype = srefWdbeKHdltype;
	this->titSrefWdbeKHdltype = titSrefWdbeKHdltype;
	this->Width = Width;
	this->Minmax = Minmax;
};

bool WdbeQSigList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQSigList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "stubMdlRefWdbeMModule", "mdl", stubMdlRefWdbeMModule);
		extractStringUclc(docctx, basexpath, "srefMgeIxVTbl", "mgt", srefMgeIxVTbl);
		extractStringUclc(docctx, basexpath, "titMgeIxVTbl", "mgt2", titMgeIxVTbl);
		extractStringUclc(docctx, basexpath, "stubMgeUref", "mgu", stubMgeUref);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMVector", "vec", stubRefWdbeMVector);
		extractStringUclc(docctx, basexpath, "yesnoConst", "con", yesnoConst);
		extractStringUclc(docctx, basexpath, "srefWdbeKHdltype", "hty", srefWdbeKHdltype);
		extractStringUclc(docctx, basexpath, "titSrefWdbeKHdltype", "hty2", titSrefWdbeKHdltype);
		extractUsmallintUclc(docctx, basexpath, "Width", "wid", Width);
		extractStringUclc(docctx, basexpath, "Minmax", "mmx", Minmax);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQSigList
 ******************************************************************************/

ListWdbeQSigList::ListWdbeQSigList() {
};

ListWdbeQSigList::ListWdbeQSigList(
			const ListWdbeQSigList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSigList(*(src.nodes[i]));
};

ListWdbeQSigList& ListWdbeQSigList::operator=(
			const ListWdbeQSigList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSigList(*(src.nodes[i]));

	return *this;
};

ListWdbeQSigList::~ListWdbeQSigList() {
	clear();
};

void ListWdbeQSigList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQSigList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQSigList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQSigList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQSigList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQSigList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQSigList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

