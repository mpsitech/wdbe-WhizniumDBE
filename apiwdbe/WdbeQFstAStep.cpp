/**
	* \file WdbeQFstAStep.cpp
	* API code for table TblWdbeQFstAStep (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQFstAStep.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQFstAStep
 ******************************************************************************/

WdbeQFstAStep::WdbeQFstAStep(
			const uint jnum
			, const string stubFnxRefWdbeMFsmstate
			, const string Cond1
			, const string Ip1
			, const string Cond2
			, const string Ip2
			, const string Cond3
			, const string Ip3
			, const string Cond4
			, const string Ip4
		) {
	this->jnum = jnum;
	this->stubFnxRefWdbeMFsmstate = stubFnxRefWdbeMFsmstate;
	this->Cond1 = Cond1;
	this->Ip1 = Ip1;
	this->Cond2 = Cond2;
	this->Ip2 = Ip2;
	this->Cond3 = Cond3;
	this->Ip3 = Ip3;
	this->Cond4 = Cond4;
	this->Ip4 = Ip4;
};

bool WdbeQFstAStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WdbeQFstAStep");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubFnxRefWdbeMFsmstate", "fnx", stubFnxRefWdbeMFsmstate);
		extractStringUclc(docctx, basexpath, "Cond1", "cn1", Cond1);
		extractStringUclc(docctx, basexpath, "Ip1", "ip1", Ip1);
		extractStringUclc(docctx, basexpath, "Cond2", "cn2", Cond2);
		extractStringUclc(docctx, basexpath, "Ip2", "ip2", Ip2);
		extractStringUclc(docctx, basexpath, "Cond3", "cn3", Cond3);
		extractStringUclc(docctx, basexpath, "Ip3", "ip3", Ip3);
		extractStringUclc(docctx, basexpath, "Cond4", "cn4", Cond4);
		extractStringUclc(docctx, basexpath, "Ip4", "ip4", Ip4);
	};

	return basefound;
};

/******************************************************************************
 class ListWdbeQFstAStep
 ******************************************************************************/

ListWdbeQFstAStep::ListWdbeQFstAStep() {
};

ListWdbeQFstAStep::ListWdbeQFstAStep(
			const ListWdbeQFstAStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQFstAStep(*(src.nodes[i]));
};

ListWdbeQFstAStep& ListWdbeQFstAStep::operator=(
			const ListWdbeQFstAStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQFstAStep(*(src.nodes[i]));

	return *this;
};

ListWdbeQFstAStep::~ListWdbeQFstAStep() {
	clear();
};

void ListWdbeQFstAStep::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWdbeQFstAStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WdbeQFstAStep* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWdbeQFstAStep");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WdbeQFstAStep", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WdbeQFstAStep(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WdbeQFstAStep[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

