/**
	* \file WdbeQErrAPar.cpp
	* API code for table TblWdbeQErrAPar (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQErrAPar.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQErrAPar
 ******************************************************************************/

WdbeQErrAPar::WdbeQErrAPar(
			const uint jnum
			, const string sref
			, const string srefIxWdbeVPartype
			, const string titIxWdbeVPartype
			, const string stubRefWdbeMVector
			, const utinyint Length
			, const string Comment
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->srefIxWdbeVPartype = srefIxWdbeVPartype;
	this->titIxWdbeVPartype = titIxWdbeVPartype;
	this->stubRefWdbeMVector = stubRefWdbeMVector;
	this->Length = Length;
	this->Comment = Comment;
};

bool WdbeQErrAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQErrAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefIxWdbeVPartype", "pty", srefIxWdbeVPartype);
		extractStringUclc(docctx, basexpath, "titIxWdbeVPartype", "pty2", titIxWdbeVPartype);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMVector", "vec", stubRefWdbeMVector);
		extractUtinyintUclc(docctx, basexpath, "Length", "len", Length);
		extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQErrAPar
 ******************************************************************************/

ListWdbeQErrAPar::ListWdbeQErrAPar() {
};

ListWdbeQErrAPar::ListWdbeQErrAPar(
			const ListWdbeQErrAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQErrAPar(*(src.nodes[i]));
};

ListWdbeQErrAPar& ListWdbeQErrAPar::operator=(
			const ListWdbeQErrAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQErrAPar(*(src.nodes[i]));

	return *this;
};

ListWdbeQErrAPar::~ListWdbeQErrAPar() {
	clear();
};

void ListWdbeQErrAPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQErrAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQErrAPar* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQErrAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQErrAPar", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQErrAPar(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQErrAPar[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

