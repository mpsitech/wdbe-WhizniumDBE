/**
	* \file QryWdbeMtpList.cpp
	* API code for job QryWdbeMtpList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "QryWdbeMtpList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class QryWdbeMtpList::VecVOrd
 ******************************************************************************/

uint QryWdbeMtpList::VecVOrd::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "hku") return HKU;
	if (s == "hkt") return HKT;
	if (s == "typ") return TYP;
	if (s == "srf") return SRF;

	return(0);
};

string QryWdbeMtpList::VecVOrd::getSref(
			const uint ix
		) {
	if (ix == HKU) return("hku");
	if (ix == HKT) return("hkt");
	if (ix == TYP) return("typ");
	if (ix == SRF) return("srf");

	return("");
};

/******************************************************************************
 class QryWdbeMtpList::StatApp
 ******************************************************************************/

QryWdbeMtpList::StatApp::StatApp(
			const uint firstcol
			, const uint jnumFirstdisp
			, const uint ncol
			, const uint ndisp
		) :
			Block()
		{
	this->firstcol = firstcol;
	this->jnumFirstdisp = jnumFirstdisp;
	this->ncol = ncol;
	this->ndisp = ndisp;

	mask = {FIRSTCOL, JNUMFIRSTDISP, NCOL, NDISP};
};

bool QryWdbeMtpList::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppQryWdbeMtpList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppQryWdbeMtpList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "firstcol", firstcol)) add(FIRSTCOL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstdisp", jnumFirstdisp)) add(JNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ncol", ncol)) add(NCOL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ndisp", ndisp)) add(NDISP);
	};

	return basefound;
};

set<uint> QryWdbeMtpList::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (firstcol == comp->firstcol) insert(items, FIRSTCOL);
	if (jnumFirstdisp == comp->jnumFirstdisp) insert(items, JNUMFIRSTDISP);
	if (ncol == comp->ncol) insert(items, NCOL);
	if (ndisp == comp->ndisp) insert(items, NDISP);

	return(items);
};

set<uint> QryWdbeMtpList::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {FIRSTCOL, JNUMFIRSTDISP, NCOL, NDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class QryWdbeMtpList::StatShr
 ******************************************************************************/

QryWdbeMtpList::StatShr::StatShr(
			const uint ntot
			, const uint jnumFirstload
			, const uint nload
		) :
			Block()
		{
	this->ntot = ntot;
	this->jnumFirstload = jnumFirstload;
	this->nload = nload;

	mask = {NTOT, JNUMFIRSTLOAD, NLOAD};
};

bool QryWdbeMtpList::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrQryWdbeMtpList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrQryWdbeMtpList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ntot", ntot)) add(NTOT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstload", jnumFirstload)) add(JNUMFIRSTLOAD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "nload", nload)) add(NLOAD);
	};

	return basefound;
};

set<uint> QryWdbeMtpList::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ntot == comp->ntot) insert(items, NTOT);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryWdbeMtpList::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NTOT, JNUMFIRSTLOAD, NLOAD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class QryWdbeMtpList::StgIac
 ******************************************************************************/

QryWdbeMtpList::StgIac::StgIac(
			const uint jnum
			, const uint jnumFirstload
			, const uint nload
		) :
			Block()
		{
	this->jnum = jnum;
	this->jnumFirstload = jnumFirstload;
	this->nload = nload;

	mask = {JNUM, JNUMFIRSTLOAD, NLOAD};
};

bool QryWdbeMtpList::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacQryWdbeMtpList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacQryWdbeMtpList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnum", jnum)) add(JNUM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstload", jnumFirstload)) add(JNUMFIRSTLOAD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "nload", nload)) add(NLOAD);
	};

	return basefound;
};

void QryWdbeMtpList::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacQryWdbeMtpList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacQryWdbeMtpList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "jnum", jnum);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstload", jnumFirstload);
		writeUintAttr(wr, itemtag, "sref", "nload", nload);
	xmlTextWriterEndElement(wr);
};

set<uint> QryWdbeMtpList::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (jnum == comp->jnum) insert(items, JNUM);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryWdbeMtpList::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JNUM, JNUMFIRSTLOAD, NLOAD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
