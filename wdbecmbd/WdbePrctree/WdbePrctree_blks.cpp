/**
	* \file WdbePrctree_blks.cpp
	* invocation / return data blocks for operation pack WdbePrctree (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "WdbePrctree_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWdbePrctreeExtract
 ******************************************************************************/

DpchInvWdbePrctreeExtract::DpchInvWdbePrctreeExtract(
			const ubigint oref
			, const ubigint jref
			, const string& infile
			, const string& infolder
			, const string& extfile
			, const string& extfolder
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEPRCTREEEXTRACT, oref, jref)
			, infile(infile)
			, infolder(infolder)
			, extfile(extfile)
			, extfolder(extfolder)
		{
};

void DpchInvWdbePrctreeExtract::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbePrctreeExtract");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractStringUclc(docctx, basexpath, "infile", "", infile)) add(INFILE);
		if (extractStringUclc(docctx, basexpath, "infolder", "", infolder)) add(INFOLDER);
		if (extractStringUclc(docctx, basexpath, "extfile", "", extfile)) add(EXTFILE);
		if (extractStringUclc(docctx, basexpath, "extfolder", "", extfolder)) add(EXTFOLDER);
	};
};

void DpchInvWdbePrctreeExtract::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbePrctreeExtract");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeString(wr, "infile", infile);
		writeString(wr, "infolder", infolder);
		writeString(wr, "extfile", extfile);
		writeString(wr, "extfolder", extfolder);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetWdbePrctreeExtract
 ******************************************************************************/

DpchRetWdbePrctreeExtract::DpchRetWdbePrctreeExtract(
			const string& scrOref
			, const string& scrJref
			, const uint ixOpVOpres
			, const utinyint pdone
			, const string& logfile
		) :
			DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBEPRCTREEEXTRACT, scrOref, scrJref, ixOpVOpres, pdone)
			, logfile(logfile)
		{
};

void DpchRetWdbePrctreeExtract::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxOpVOpres;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetWdbePrctreeExtract");
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

void DpchRetWdbePrctreeExtract::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetWdbePrctreeExtract");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeString(wr, "srefIxOpVOpres", VecOpVOpres::getSref(ixOpVOpres));
		writeUtinyint(wr, "pdone", pdone);
		writeString(wr, "logfile", logfile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbePrctreeMerge
 ******************************************************************************/

DpchInvWdbePrctreeMerge::DpchInvWdbePrctreeMerge(
			const ubigint oref
			, const ubigint jref
			, const string& extfile
			, const string& extfolder
			, const string& tplfile
			, const string& tplfolder
			, const bool notrace
			, const bool skipmultvoid
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEPRCTREEMERGE, oref, jref)
			, extfile(extfile)
			, extfolder(extfolder)
			, tplfile(tplfile)
			, tplfolder(tplfolder)
			, notrace(notrace)
			, skipmultvoid(skipmultvoid)
		{
};

void DpchInvWdbePrctreeMerge::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbePrctreeMerge");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractStringUclc(docctx, basexpath, "extfile", "", extfile)) add(EXTFILE);
		if (extractStringUclc(docctx, basexpath, "extfolder", "", extfolder)) add(EXTFOLDER);
		if (extractStringUclc(docctx, basexpath, "tplfile", "", tplfile)) add(TPLFILE);
		if (extractStringUclc(docctx, basexpath, "tplfolder", "", tplfolder)) add(TPLFOLDER);
		if (extractBoolUclc(docctx, basexpath, "notrace", "", notrace)) add(NOTRACE);
		if (extractBoolUclc(docctx, basexpath, "skipmultvoid", "", skipmultvoid)) add(SKIPMULTVOID);
	};
};

void DpchInvWdbePrctreeMerge::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbePrctreeMerge");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeString(wr, "extfile", extfile);
		writeString(wr, "extfolder", extfolder);
		writeString(wr, "tplfile", tplfile);
		writeString(wr, "tplfolder", tplfolder);
		writeBool(wr, "notrace", notrace);
		writeBool(wr, "skipmultvoid", skipmultvoid);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetWdbePrctreeMerge
 ******************************************************************************/

DpchRetWdbePrctreeMerge::DpchRetWdbePrctreeMerge(
			const string& scrOref
			, const string& scrJref
			, const uint ixOpVOpres
			, const utinyint pdone
			, const string& logfile
		) :
			DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBEPRCTREEMERGE, scrOref, scrJref, ixOpVOpres, pdone)
			, logfile(logfile)
		{
};

void DpchRetWdbePrctreeMerge::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxOpVOpres;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetWdbePrctreeMerge");
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

void DpchRetWdbePrctreeMerge::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetWdbePrctreeMerge");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeString(wr, "srefIxOpVOpres", VecOpVOpres::getSref(ixOpVOpres));
		writeUtinyint(wr, "pdone", pdone);
		writeString(wr, "logfile", logfile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbePrctreeValidate
 ******************************************************************************/

DpchInvWdbePrctreeValidate::DpchInvWdbePrctreeValidate(
			const ubigint oref
			, const ubigint jref
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEPRCTREEVALIDATE, oref, jref)
		{
};

void DpchInvWdbePrctreeValidate::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbePrctreeValidate");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
	};
};

void DpchInvWdbePrctreeValidate::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbePrctreeValidate");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT
