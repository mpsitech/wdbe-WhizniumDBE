/**
	* \file WdbeQUsrAAccess.cpp
	* API code for table TblWdbeQUsrAAccess (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQUsrAAccess.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQUsrAAccess
 ******************************************************************************/

WdbeQUsrAAccess::WdbeQUsrAAccess(
			const uint jnum
			, const string srefX1IxWdbeVFeatgroup
			, const string titX1IxWdbeVFeatgroup
			, const string x2FeaSrefUix
			, const string srefsIxWdbeWAccess
			, const string titsIxWdbeWAccess
		) {
	this->jnum = jnum;
	this->srefX1IxWdbeVFeatgroup = srefX1IxWdbeVFeatgroup;
	this->titX1IxWdbeVFeatgroup = titX1IxWdbeVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->srefsIxWdbeWAccess = srefsIxWdbeWAccess;
	this->titsIxWdbeWAccess = titsIxWdbeWAccess;
};

bool WdbeQUsrAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQUsrAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "srefX1IxWdbeVFeatgroup", "feg", srefX1IxWdbeVFeatgroup);
		extractStringUclc(docctx, basexpath, "titX1IxWdbeVFeatgroup", "feg2", titX1IxWdbeVFeatgroup);
		extractStringUclc(docctx, basexpath, "x2FeaSrefUix", "fea", x2FeaSrefUix);
		extractStringUclc(docctx, basexpath, "srefsIxWdbeWAccess", "acc", srefsIxWdbeWAccess);
		extractStringUclc(docctx, basexpath, "titsIxWdbeWAccess", "acc2", titsIxWdbeWAccess);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQUsrAAccess
 ******************************************************************************/

ListWdbeQUsrAAccess::ListWdbeQUsrAAccess() {
};

ListWdbeQUsrAAccess::ListWdbeQUsrAAccess(
			const ListWdbeQUsrAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUsrAAccess(*(src.nodes[i]));
};

ListWdbeQUsrAAccess& ListWdbeQUsrAAccess::operator=(
			const ListWdbeQUsrAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUsrAAccess(*(src.nodes[i]));

	return *this;
};

ListWdbeQUsrAAccess::~ListWdbeQUsrAAccess() {
	clear();
};

void ListWdbeQUsrAAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQUsrAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQUsrAAccess* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQUsrAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQUsrAAccess", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQUsrAAccess(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQUsrAAccess[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

