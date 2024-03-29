/**
	* \file WdbePlhmcu_blks.cpp
	* invocation / return data blocks for operation pack WdbePlhmcu (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "WdbePlhmcu_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWdbePlhmcuEctr
 ******************************************************************************/

DpchInvWdbePlhmcuEctr::DpchInvWdbePlhmcuEctr(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMModule
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEPLHMCUECTR, oref, jref)
		{
	this->refWdbeMModule = refWdbeMModule;
};

void DpchInvWdbePlhmcuEctr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbePlhmcuEctr");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMModule", "", refWdbeMModule)) add(REFWDBEMMODULE);
	};
};

void DpchInvWdbePlhmcuEctr::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbePlhmcuEctr");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMModule", refWdbeMModule);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetWdbePlhmcuEctr
 ******************************************************************************/

DpchRetWdbePlhmcuEctr::DpchRetWdbePlhmcuEctr(
			const string& scrOref
			, const string& scrJref
			, const uint ixOpVOpres
			, const utinyint pdone
			, const vector<string>& keys
			, const vector<string>& vals
		) :
			DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBEPLHMCUECTR, scrOref, scrJref, ixOpVOpres, pdone)
		{
	this->keys = keys;
	this->vals = vals;
};

void DpchRetWdbePlhmcuEctr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxOpVOpres;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetWdbePlhmcuEctr");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) {
			oref = Scr::descramble(scrOref);
			add(OREF);
		};
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxOpVOpres", "", srefIxOpVOpres)) {
			ixOpVOpres = VecOpVOpres::getIx(srefIxOpVOpres);
			add(IXOPVOPRES);
		};
		if (extractUtinyintUclc(docctx, basexpath, "pdone", "", pdone)) add(PDONE);
		if (extractStringvecUclc(docctx, basexpath, "keys", "", keys)) add(KEYS);
		if (extractStringvecUclc(docctx, basexpath, "vals", "", vals)) add(VALS);
	};
};

void DpchRetWdbePlhmcuEctr::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetWdbePlhmcuEctr");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeString(wr, "srefIxOpVOpres", VecOpVOpres::getSref(ixOpVOpres));
		writeUtinyint(wr, "pdone", pdone);
		writeStringvec(wr, "keys", keys);
		writeStringvec(wr, "vals", vals);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbePlhmcuEhostif
 ******************************************************************************/

DpchInvWdbePlhmcuEhostif::DpchInvWdbePlhmcuEhostif(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMModule
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEPLHMCUEHOSTIF, oref, jref)
		{
	this->refWdbeMModule = refWdbeMModule;
};

void DpchInvWdbePlhmcuEhostif::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbePlhmcuEhostif");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMModule", "", refWdbeMModule)) add(REFWDBEMMODULE);
	};
};

void DpchInvWdbePlhmcuEhostif::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbePlhmcuEhostif");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMModule", refWdbeMModule);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetWdbePlhmcuEhostif
 ******************************************************************************/

DpchRetWdbePlhmcuEhostif::DpchRetWdbePlhmcuEhostif(
			const string& scrOref
			, const string& scrJref
			, const uint ixOpVOpres
			, const utinyint pdone
			, const vector<string>& keys
			, const vector<string>& vals
		) :
			DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBEPLHMCUEHOSTIF, scrOref, scrJref, ixOpVOpres, pdone)
		{
	this->keys = keys;
	this->vals = vals;
};

void DpchRetWdbePlhmcuEhostif::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxOpVOpres;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetWdbePlhmcuEhostif");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) {
			oref = Scr::descramble(scrOref);
			add(OREF);
		};
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxOpVOpres", "", srefIxOpVOpres)) {
			ixOpVOpres = VecOpVOpres::getIx(srefIxOpVOpres);
			add(IXOPVOPRES);
		};
		if (extractUtinyintUclc(docctx, basexpath, "pdone", "", pdone)) add(PDONE);
		if (extractStringvecUclc(docctx, basexpath, "keys", "", keys)) add(KEYS);
		if (extractStringvecUclc(docctx, basexpath, "vals", "", vals)) add(VALS);
	};
};

void DpchRetWdbePlhmcuEhostif::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetWdbePlhmcuEhostif");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeString(wr, "srefIxOpVOpres", VecOpVOpres::getSref(ixOpVOpres));
		writeUtinyint(wr, "pdone", pdone);
		writeStringvec(wr, "keys", keys);
		writeStringvec(wr, "vals", vals);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT
