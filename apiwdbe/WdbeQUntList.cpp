/**
	* \file WdbeQUntList.cpp
	* API code for table TblWdbeQUntList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeQUntList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQUntList
 ******************************************************************************/

WdbeQUntList::WdbeQUntList(
			const uint jnum
			, const string sref
			, const string Title
			, const string Fullsref
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const string stubRefUref
			, const string stubRefWdbeMSystem
			, const string stubRefWdbeMModule
			, const string srefKPackage
			, const string titSrefKPackage
			, const string yesnoEasy
			, const string srefKToolch
			, const string titSrefKToolch
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Title = Title;
	this->Fullsref = Fullsref;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->stubRefUref = stubRefUref;
	this->stubRefWdbeMSystem = stubRefWdbeMSystem;
	this->stubRefWdbeMModule = stubRefWdbeMModule;
	this->srefKPackage = srefKPackage;
	this->titSrefKPackage = titSrefKPackage;
	this->yesnoEasy = yesnoEasy;
	this->srefKToolch = srefKToolch;
	this->titSrefKToolch = titSrefKToolch;
};

bool WdbeQUntList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQUntList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "Fullsref", "fsr", Fullsref);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl);
		extractStringUclc(docctx, basexpath, "titRefIxVTbl", "ret2", titRefIxVTbl);
		extractStringUclc(docctx, basexpath, "stubRefUref", "reu", stubRefUref);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMSystem", "sys", stubRefWdbeMSystem);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMModule", "mdl", stubRefWdbeMModule);
		extractStringUclc(docctx, basexpath, "srefKPackage", "pkg", srefKPackage);
		extractStringUclc(docctx, basexpath, "titSrefKPackage", "pkg2", titSrefKPackage);
		extractStringUclc(docctx, basexpath, "yesnoEasy", "esy", yesnoEasy);
		extractStringUclc(docctx, basexpath, "srefKToolch", "tch", srefKToolch);
		extractStringUclc(docctx, basexpath, "titSrefKToolch", "tch2", titSrefKToolch);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQUntList
 ******************************************************************************/

ListWdbeQUntList::ListWdbeQUntList() {
};

ListWdbeQUntList::ListWdbeQUntList(
			const ListWdbeQUntList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUntList(*(src.nodes[i]));
};

ListWdbeQUntList& ListWdbeQUntList::operator=(
			const ListWdbeQUntList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUntList(*(src.nodes[i]));

	return *this;
};

ListWdbeQUntList::~ListWdbeQUntList() {
	clear();
};

void ListWdbeQUntList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQUntList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQUntList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQUntList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQUntList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQUntList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQUntList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

