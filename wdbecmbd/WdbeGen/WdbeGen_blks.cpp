/**
	* \file WdbeGen_blks.cpp
	* invocation / return data blocks for operation pack WdbeGen (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeGen_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWdbeGenStdvec
 ******************************************************************************/

DpchInvWdbeGenStdvec::DpchInvWdbeGenStdvec(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMUnit
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEGENSTDVEC, oref, jref)
		{
	this->refWdbeMUnit = refWdbeMUnit;
};

void DpchInvWdbeGenStdvec::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeGenStdvec");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMUnit", "", refWdbeMUnit)) add(REFWDBEMUNIT);
	};
};

void DpchInvWdbeGenStdvec::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeGenStdvec");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMUnit", refWdbeMUnit);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbeGenTest
 ******************************************************************************/

DpchInvWdbeGenTest::DpchInvWdbeGenTest(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMModule
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEGENTEST, oref, jref)
		{
	this->refWdbeMModule = refWdbeMModule;
};

void DpchInvWdbeGenTest::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeGenTest");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMModule", "", refWdbeMModule)) add(REFWDBEMMODULE);
	};
};

void DpchInvWdbeGenTest::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeGenTest");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMModule", refWdbeMModule);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetWdbeGenTest
 ******************************************************************************/

DpchRetWdbeGenTest::DpchRetWdbeGenTest(
			const string& scrOref
			, const string& scrJref
			, const uint ixOpVOpres
			, const utinyint pdone
			, const string& logfile
		) :
			DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBEGENTEST, scrOref, scrJref, ixOpVOpres, pdone)
		{
	this->logfile = logfile;
};

void DpchRetWdbeGenTest::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxOpVOpres;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetWdbeGenTest");
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
		if (extractStringUclc(docctx, basexpath, "logfile", "", logfile)) add(LOGFILE);
	};
};

void DpchRetWdbeGenTest::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetWdbeGenTest");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeString(wr, "srefIxOpVOpres", VecOpVOpres::getSref(ixOpVOpres));
		writeUtinyint(wr, "pdone", pdone);
		writeString(wr, "logfile", logfile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbeGenWiring
 ******************************************************************************/

DpchInvWdbeGenWiring::DpchInvWdbeGenWiring(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMModule
			, const string& srefKToolch
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEGENWIRING, oref, jref)
		{
	this->refWdbeMModule = refWdbeMModule;
	this->srefKToolch = srefKToolch;
};

void DpchInvWdbeGenWiring::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeGenWiring");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMModule", "", refWdbeMModule)) add(REFWDBEMMODULE);
		if (extractStringUclc(docctx, basexpath, "srefKToolch", "", srefKToolch)) add(SREFKTOOLCH);
	};
};

void DpchInvWdbeGenWiring::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeGenWiring");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMModule", refWdbeMModule);
		writeString(wr, "srefKToolch", srefKToolch);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetWdbeGenWiring
 ******************************************************************************/

DpchRetWdbeGenWiring::DpchRetWdbeGenWiring(
			const string& scrOref
			, const string& scrJref
			, const uint ixOpVOpres
			, const utinyint pdone
			, const string& logfile
		) :
			DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBEGENWIRING, scrOref, scrJref, ixOpVOpres, pdone)
		{
	this->logfile = logfile;
};

void DpchRetWdbeGenWiring::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxOpVOpres;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetWdbeGenWiring");
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
		if (extractStringUclc(docctx, basexpath, "logfile", "", logfile)) add(LOGFILE);
	};
};

void DpchRetWdbeGenWiring::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetWdbeGenWiring");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeString(wr, "srefIxOpVOpres", VecOpVOpres::getSref(ixOpVOpres));
		writeUtinyint(wr, "pdone", pdone);
		writeString(wr, "logfile", logfile);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT
