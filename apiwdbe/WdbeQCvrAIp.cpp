/**
	* \file WdbeQCvrAIp.cpp
	* API code for table TblWdbeQCvrAIp (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQCvrAIp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCvrAIp
 ******************************************************************************/

WdbeQCvrAIp::WdbeQCvrAIp(
			const uint jnum
			, const string sref
			, const string srefIxVTagtype
			, const string titIxVTagtype
			, const string Comment
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->srefIxVTagtype = srefIxVTagtype;
	this->titIxVTagtype = titIxVTagtype;
	this->Comment = Comment;
};

bool WdbeQCvrAIp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQCvrAIp");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefIxVTagtype", "tty", srefIxVTagtype);
		extractStringUclc(docctx, basexpath, "titIxVTagtype", "tty2", titIxVTagtype);
		extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQCvrAIp
 ******************************************************************************/

ListWdbeQCvrAIp::ListWdbeQCvrAIp() {
};

ListWdbeQCvrAIp::ListWdbeQCvrAIp(
			const ListWdbeQCvrAIp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCvrAIp(*(src.nodes[i]));
};

ListWdbeQCvrAIp& ListWdbeQCvrAIp::operator=(
			const ListWdbeQCvrAIp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCvrAIp(*(src.nodes[i]));

	return *this;
};

ListWdbeQCvrAIp::~ListWdbeQCvrAIp() {
	clear();
};

void ListWdbeQCvrAIp::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQCvrAIp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQCvrAIp* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQCvrAIp");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQCvrAIp", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQCvrAIp(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQCvrAIp[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

