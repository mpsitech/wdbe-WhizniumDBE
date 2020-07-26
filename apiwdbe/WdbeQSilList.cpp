/**
	* \file WdbeQSilList.cpp
	* API code for table TblWdbeQSilList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeQSilList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQSilList
 ******************************************************************************/

WdbeQSilList::WdbeQSilList(
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

bool WdbeQSilList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQSilList");
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
 class ListWdbeQSilList
 ******************************************************************************/

ListWdbeQSilList::ListWdbeQSilList() {
};

ListWdbeQSilList::ListWdbeQSilList(
			const ListWdbeQSilList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSilList(*(src.nodes[i]));
};

ListWdbeQSilList& ListWdbeQSilList::operator=(
			const ListWdbeQSilList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSilList(*(src.nodes[i]));

	return *this;
};

ListWdbeQSilList::~ListWdbeQSilList() {
	clear();
};

void ListWdbeQSilList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQSilList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQSilList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQSilList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQSilList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQSilList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQSilList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

