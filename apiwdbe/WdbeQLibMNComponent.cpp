/**
	* \file WdbeQLibMNComponent.cpp
	* API code for table TblWdbeQLibMNComponent (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

#include "WdbeQLibMNComponent.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQLibMNComponent
 ******************************************************************************/

WdbeQLibMNComponent::WdbeQLibMNComponent(
			const uint jnum
			, const string stubMref
		) :
			jnum(jnum)
			, stubMref(stubMref)
		{
};

bool WdbeQLibMNComponent::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQLibMNComponent");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQLibMNComponent
 ******************************************************************************/

ListWdbeQLibMNComponent::ListWdbeQLibMNComponent() {
};

ListWdbeQLibMNComponent::ListWdbeQLibMNComponent(
			const ListWdbeQLibMNComponent& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQLibMNComponent(*(src.nodes[i]));
};

ListWdbeQLibMNComponent& ListWdbeQLibMNComponent::operator=(
			const ListWdbeQLibMNComponent& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQLibMNComponent(*(src.nodes[i]));

	return *this;
};

ListWdbeQLibMNComponent::~ListWdbeQLibMNComponent() {
	clear();
};

void ListWdbeQLibMNComponent::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQLibMNComponent::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQLibMNComponent* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQLibMNComponent");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQLibMNComponent", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQLibMNComponent(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQLibMNComponent[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
