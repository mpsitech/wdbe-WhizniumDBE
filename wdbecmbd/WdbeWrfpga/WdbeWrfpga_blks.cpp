/**
	* \file WdbeWrfpga_blks.cpp
	* invocation / return data blocks for operation pack WdbeWrfpga (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "WdbeWrfpga_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWdbeWrfpgaAux
 ******************************************************************************/

DpchInvWdbeWrfpgaAux::DpchInvWdbeWrfpgaAux(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMModule
			, const string& folder
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEWRFPGAAUX, oref, jref)
			, refWdbeMModule(refWdbeMModule)
			, folder(folder)
		{
};

void DpchInvWdbeWrfpgaAux::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeWrfpgaAux");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMModule", "", refWdbeMModule)) add(REFWDBEMMODULE);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
	};
};

void DpchInvWdbeWrfpgaAux::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeWrfpgaAux");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMModule", refWdbeMModule);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbeWrfpgaBase
 ******************************************************************************/

DpchInvWdbeWrfpgaBase::DpchInvWdbeWrfpgaBase(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMUnit
			, const string& folder
			, const string& Prjshort
			, const string& Untsref
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEWRFPGABASE, oref, jref)
			, refWdbeMUnit(refWdbeMUnit)
			, folder(folder)
			, Prjshort(Prjshort)
			, Untsref(Untsref)
		{
};

void DpchInvWdbeWrfpgaBase::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeWrfpgaBase");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMUnit", "", refWdbeMUnit)) add(REFWDBEMUNIT);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
		if (extractStringUclc(docctx, basexpath, "Untsref", "", Untsref)) add(UNTSREF);
	};
};

void DpchInvWdbeWrfpgaBase::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeWrfpgaBase");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMUnit", refWdbeMUnit);
		writeString(wr, "folder", folder);
		writeString(wr, "Prjshort", Prjshort);
		writeString(wr, "Untsref", Untsref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbeWrfpgaCtr
 ******************************************************************************/

DpchInvWdbeWrfpgaCtr::DpchInvWdbeWrfpgaCtr(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMModule
			, const string& folder
			, const string& Prjshort
			, const string& Untsref
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEWRFPGACTR, oref, jref)
			, refWdbeMModule(refWdbeMModule)
			, folder(folder)
			, Prjshort(Prjshort)
			, Untsref(Untsref)
		{
};

void DpchInvWdbeWrfpgaCtr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeWrfpgaCtr");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMModule", "", refWdbeMModule)) add(REFWDBEMMODULE);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
		if (extractStringUclc(docctx, basexpath, "Untsref", "", Untsref)) add(UNTSREF);
	};
};

void DpchInvWdbeWrfpgaCtr::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeWrfpgaCtr");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMModule", refWdbeMModule);
		writeString(wr, "folder", folder);
		writeString(wr, "Prjshort", Prjshort);
		writeString(wr, "Untsref", Untsref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbeWrfpgaDeploy
 ******************************************************************************/

DpchInvWdbeWrfpgaDeploy::DpchInvWdbeWrfpgaDeploy(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMRelease
			, const string& folder
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEWRFPGADEPLOY, oref, jref)
			, refWdbeMRelease(refWdbeMRelease)
			, folder(folder)
		{
};

void DpchInvWdbeWrfpgaDeploy::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeWrfpgaDeploy");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMRelease", "", refWdbeMRelease)) add(REFWDBEMRELEASE);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
	};
};

void DpchInvWdbeWrfpgaDeploy::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeWrfpgaDeploy");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMRelease", refWdbeMRelease);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbeWrfpgaMdlfine
 ******************************************************************************/

DpchInvWdbeWrfpgaMdlfine::DpchInvWdbeWrfpgaMdlfine(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMModule
			, const string& folder
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEWRFPGAMDLFINE, oref, jref)
			, refWdbeMModule(refWdbeMModule)
			, folder(folder)
		{
};

void DpchInvWdbeWrfpgaMdlfine::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeWrfpgaMdlfine");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMModule", "", refWdbeMModule)) add(REFWDBEMMODULE);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
	};
};

void DpchInvWdbeWrfpgaMdlfine::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeWrfpgaMdlfine");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMModule", refWdbeMModule);
		writeString(wr, "folder", folder);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbeWrfpgaMdlraw
 ******************************************************************************/

DpchInvWdbeWrfpgaMdlraw::DpchInvWdbeWrfpgaMdlraw(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMModule
			, const string& folder
			, const string& Prjshort
			, const string& Untsref
			, const string& srefKToolch
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEWRFPGAMDLRAW, oref, jref)
			, refWdbeMModule(refWdbeMModule)
			, folder(folder)
			, Prjshort(Prjshort)
			, Untsref(Untsref)
			, srefKToolch(srefKToolch)
		{
};

void DpchInvWdbeWrfpgaMdlraw::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeWrfpgaMdlraw");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMModule", "", refWdbeMModule)) add(REFWDBEMMODULE);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
		if (extractStringUclc(docctx, basexpath, "Untsref", "", Untsref)) add(UNTSREF);
		if (extractStringUclc(docctx, basexpath, "srefKToolch", "", srefKToolch)) add(SREFKTOOLCH);
	};
};

void DpchInvWdbeWrfpgaMdlraw::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeWrfpgaMdlraw");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMModule", refWdbeMModule);
		writeString(wr, "folder", folder);
		writeString(wr, "Prjshort", Prjshort);
		writeString(wr, "Untsref", Untsref);
		writeString(wr, "srefKToolch", srefKToolch);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbeWrfpgaTop
 ******************************************************************************/

DpchInvWdbeWrfpgaTop::DpchInvWdbeWrfpgaTop(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMModule
			, const string& folder
			, const string& Prjshort
			, const string& Untsref
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEWRFPGATOP, oref, jref)
			, refWdbeMModule(refWdbeMModule)
			, folder(folder)
			, Prjshort(Prjshort)
			, Untsref(Untsref)
		{
};

void DpchInvWdbeWrfpgaTop::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeWrfpgaTop");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMModule", "", refWdbeMModule)) add(REFWDBEMMODULE);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
		if (extractStringUclc(docctx, basexpath, "Untsref", "", Untsref)) add(UNTSREF);
	};
};

void DpchInvWdbeWrfpgaTop::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeWrfpgaTop");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMModule", refWdbeMModule);
		writeString(wr, "folder", folder);
		writeString(wr, "Prjshort", Prjshort);
		writeString(wr, "Untsref", Untsref);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT
