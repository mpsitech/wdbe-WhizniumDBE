/**
	* \file WdbeQPrsList.cpp
	* API code for table TblWdbeQPrsList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQPrsList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPrsList
 ******************************************************************************/

WdbeQPrsList::WdbeQPrsList(
			const uint jnum
			, const string stubGrp
			, const string stubOwn
			, const string Title
			, const string Firstname
			, const string Lastname
			, const string srefIxVSex
			, const string titIxVSex
			, const string telVal
			, const string emlVal
		) {
	this->jnum = jnum;
	this->stubGrp = stubGrp;
	this->stubOwn = stubOwn;
	this->Title = Title;
	this->Firstname = Firstname;
	this->Lastname = Lastname;
	this->srefIxVSex = srefIxVSex;
	this->titIxVSex = titIxVSex;
	this->telVal = telVal;
	this->emlVal = emlVal;
};

bool WdbeQPrsList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQPrsList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubGrp", "grp", stubGrp);
		extractStringUclc(docctx, basexpath, "stubOwn", "own", stubOwn);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "Firstname", "fnm", Firstname);
		extractStringUclc(docctx, basexpath, "Lastname", "lnm", Lastname);
		extractStringUclc(docctx, basexpath, "srefIxVSex", "sex", srefIxVSex);
		extractStringUclc(docctx, basexpath, "titIxVSex", "sex2", titIxVSex);
		extractStringUclc(docctx, basexpath, "telVal", "tel", telVal);
		extractStringUclc(docctx, basexpath, "emlVal", "eml", emlVal);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQPrsList
 ******************************************************************************/

ListWdbeQPrsList::ListWdbeQPrsList() {
};

ListWdbeQPrsList::ListWdbeQPrsList(
			const ListWdbeQPrsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrsList(*(src.nodes[i]));
};

ListWdbeQPrsList& ListWdbeQPrsList::operator=(
			const ListWdbeQPrsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrsList(*(src.nodes[i]));

	return *this;
};

ListWdbeQPrsList::~ListWdbeQPrsList() {
	clear();
};

void ListWdbeQPrsList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQPrsList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQPrsList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQPrsList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQPrsList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQPrsList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQPrsList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

