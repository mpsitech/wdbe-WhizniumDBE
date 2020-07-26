/**
	* \file WdbeQUsgAAccess.cpp
	* API code for table TblWdbeQUsgAAccess (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeQUsgAAccess.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQUsgAAccess
 ******************************************************************************/

WdbeQUsgAAccess::WdbeQUsgAAccess(
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

bool WdbeQUsgAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQUsgAAccess");
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
 class ListWdbeQUsgAAccess
 ******************************************************************************/

ListWdbeQUsgAAccess::ListWdbeQUsgAAccess() {
};

ListWdbeQUsgAAccess::ListWdbeQUsgAAccess(
			const ListWdbeQUsgAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUsgAAccess(*(src.nodes[i]));
};

ListWdbeQUsgAAccess& ListWdbeQUsgAAccess::operator=(
			const ListWdbeQUsgAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUsgAAccess(*(src.nodes[i]));

	return *this;
};

ListWdbeQUsgAAccess::~ListWdbeQUsgAAccess() {
	clear();
};

void ListWdbeQUsgAAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQUsgAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQUsgAAccess* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQUsgAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQUsgAAccess", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQUsgAAccess(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQUsgAAccess[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

