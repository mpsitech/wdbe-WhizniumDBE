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
		{
	this->refWdbeMUnit = refWdbeMUnit;
	this->folder = folder;
	this->Prjshort = Prjshort;
	this->Untsref = Untsref;
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
 class DpchInvWdbeWrfpgaCtrFwdctr
 ******************************************************************************/

DpchInvWdbeWrfpgaCtrFwdctr::DpchInvWdbeWrfpgaCtrFwdctr(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMModule
			, const string& folder
			, const string& Prjshort
			, const string& Untsref
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEWRFPGACTRFWDCTR, oref, jref)
		{
	this->refWdbeMModule = refWdbeMModule;
	this->folder = folder;
	this->Prjshort = Prjshort;
	this->Untsref = Untsref;
};

void DpchInvWdbeWrfpgaCtrFwdctr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeWrfpgaCtrFwdctr");
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

void DpchInvWdbeWrfpgaCtrFwdctr::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeWrfpgaCtrFwdctr");
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
		{
	this->refWdbeMRelease = refWdbeMRelease;
	this->folder = folder;
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
 class DpchInvWdbeWrfpgaEhostif
 ******************************************************************************/

DpchInvWdbeWrfpgaEhostif::DpchInvWdbeWrfpgaEhostif(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMModule
			, const string& folder
			, const string& Prjshort
			, const string& Untsref
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEWRFPGAEHOSTIF, oref, jref)
		{
	this->refWdbeMModule = refWdbeMModule;
	this->folder = folder;
	this->Prjshort = Prjshort;
	this->Untsref = Untsref;
};

void DpchInvWdbeWrfpgaEhostif::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeWrfpgaEhostif");
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

void DpchInvWdbeWrfpgaEhostif::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeWrfpgaEhostif");
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
 class DpchInvWdbeWrfpgaHostif
 ******************************************************************************/

DpchInvWdbeWrfpgaHostif::DpchInvWdbeWrfpgaHostif(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMModule
			, const string& folder
			, const string& Prjshort
			, const string& Untsref
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEWRFPGAHOSTIF, oref, jref)
		{
	this->refWdbeMModule = refWdbeMModule;
	this->folder = folder;
	this->Prjshort = Prjshort;
	this->Untsref = Untsref;
};

void DpchInvWdbeWrfpgaHostif::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeWrfpgaHostif");
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

void DpchInvWdbeWrfpgaHostif::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeWrfpgaHostif");
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
 class DpchInvWdbeWrfpgaIpclr
 ******************************************************************************/

DpchInvWdbeWrfpgaIpclr::DpchInvWdbeWrfpgaIpclr(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMModule
			, const string& folder
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEWRFPGAIPCLR, oref, jref)
		{
	this->refWdbeMModule = refWdbeMModule;
	this->folder = folder;
};

void DpchInvWdbeWrfpgaIpclr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeWrfpgaIpclr");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMModule", "", refWdbeMModule)) add(REFWDBEMMODULE);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
	};
};

void DpchInvWdbeWrfpgaIpclr::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeWrfpgaIpclr");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMModule", refWdbeMModule);
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
		{
	this->refWdbeMModule = refWdbeMModule;
	this->folder = folder;
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
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEWRFPGAMDLRAW, oref, jref)
		{
	this->refWdbeMModule = refWdbeMModule;
	this->folder = folder;
	this->Prjshort = Prjshort;
	this->Untsref = Untsref;
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
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT



