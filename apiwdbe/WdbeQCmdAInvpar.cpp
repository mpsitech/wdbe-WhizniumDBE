/**
	* \file WdbeQCmdAInvpar.cpp
	* API code for table TblWdbeQCmdAInvpar (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQCmdAInvpar.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCmdAInvpar
 ******************************************************************************/

WdbeQCmdAInvpar::WdbeQCmdAInvpar(
			const uint jnum
			, const string sref
			, const string srefIxWdbeVPartype
			, const string titIxWdbeVPartype
			, const string stubRefWdbeMVector
			, const utinyint Length
			, const string Defval
			, const string stubRefWdbeMVectoritem
			, const string Comment
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->srefIxWdbeVPartype = srefIxWdbeVPartype;
	this->titIxWdbeVPartype = titIxWdbeVPartype;
	this->stubRefWdbeMVector = stubRefWdbeMVector;
	this->Length = Length;
	this->Defval = Defval;
	this->stubRefWdbeMVectoritem = stubRefWdbeMVectoritem;
	this->Comment = Comment;
};

bool WdbeQCmdAInvpar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQCmdAInvpar");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefIxWdbeVPartype", "pty", srefIxWdbeVPartype);
		extractStringUclc(docctx, basexpath, "titIxWdbeVPartype", "pty2", titIxWdbeVPartype);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMVector", "vec", stubRefWdbeMVector);
		extractUtinyintUclc(docctx, basexpath, "Length", "len", Length);
		extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval);
		extractStringUclc(docctx, basexpath, "stubRefWdbeMVectoritem", "vit", stubRefWdbeMVectoritem);
		extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQCmdAInvpar
 ******************************************************************************/

ListWdbeQCmdAInvpar::ListWdbeQCmdAInvpar() {
};

ListWdbeQCmdAInvpar::ListWdbeQCmdAInvpar(
			const ListWdbeQCmdAInvpar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCmdAInvpar(*(src.nodes[i]));
};

ListWdbeQCmdAInvpar& ListWdbeQCmdAInvpar::operator=(
			const ListWdbeQCmdAInvpar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCmdAInvpar(*(src.nodes[i]));

	return *this;
};

ListWdbeQCmdAInvpar::~ListWdbeQCmdAInvpar() {
	clear();
};

void ListWdbeQCmdAInvpar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQCmdAInvpar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQCmdAInvpar* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQCmdAInvpar");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQCmdAInvpar", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQCmdAInvpar(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQCmdAInvpar[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

