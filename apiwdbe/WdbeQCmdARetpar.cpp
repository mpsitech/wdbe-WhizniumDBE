/**
	* \file WdbeQCmdARetpar.cpp
	* API code for table TblWdbeQCmdARetpar (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQCmdARetpar.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCmdARetpar
 ******************************************************************************/

WdbeQCmdARetpar::WdbeQCmdARetpar(
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

bool WdbeQCmdARetpar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQCmdARetpar");
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
 class ListWdbeQCmdARetpar
 ******************************************************************************/

ListWdbeQCmdARetpar::ListWdbeQCmdARetpar() {
};

ListWdbeQCmdARetpar::ListWdbeQCmdARetpar(
			const ListWdbeQCmdARetpar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCmdARetpar(*(src.nodes[i]));
};

ListWdbeQCmdARetpar& ListWdbeQCmdARetpar::operator=(
			const ListWdbeQCmdARetpar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCmdARetpar(*(src.nodes[i]));

	return *this;
};

ListWdbeQCmdARetpar::~ListWdbeQCmdARetpar() {
	clear();
};

void ListWdbeQCmdARetpar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQCmdARetpar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQCmdARetpar* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQCmdARetpar");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQCmdARetpar", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQCmdARetpar(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQCmdARetpar[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

