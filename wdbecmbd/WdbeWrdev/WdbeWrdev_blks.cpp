/**
	* \file WdbeWrdev_blks.cpp
	* invocation / return data blocks for operation pack WdbeWrdev (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "WdbeWrdev_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWdbeWrdevBase
 ******************************************************************************/

DpchInvWdbeWrdevBase::DpchInvWdbeWrdevBase(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMVersion
			, const string& folder
			, const string& Prjshort
			, const bool Easy
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEWRDEVBASE, oref, jref)
			, refWdbeMVersion(refWdbeMVersion)
			, folder(folder)
			, Prjshort(Prjshort)
			, Easy(Easy)
		{
};

void DpchInvWdbeWrdevBase::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeWrdevBase");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMVersion", "", refWdbeMVersion)) add(REFWDBEMVERSION);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
		if (extractBoolUclc(docctx, basexpath, "Easy", "", Easy)) add(EASY);
	};
};

void DpchInvWdbeWrdevBase::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeWrdevBase");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMVersion", refWdbeMVersion);
		writeString(wr, "folder", folder);
		writeString(wr, "Prjshort", Prjshort);
		writeBool(wr, "Easy", Easy);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbeWrdevCtr
 ******************************************************************************/

DpchInvWdbeWrdevCtr::DpchInvWdbeWrdevCtr(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMController
			, const string& folder
			, const bool Easy
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEWRDEVCTR, oref, jref)
			, refWdbeMController(refWdbeMController)
			, folder(folder)
			, Easy(Easy)
		{
};

void DpchInvWdbeWrdevCtr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeWrdevCtr");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMController", "", refWdbeMController)) add(REFWDBEMCONTROLLER);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
		if (extractBoolUclc(docctx, basexpath, "Easy", "", Easy)) add(EASY);
	};
};

void DpchInvWdbeWrdevCtr::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeWrdevCtr");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMController", refWdbeMController);
		writeString(wr, "folder", folder);
		writeBool(wr, "Easy", Easy);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbeWrdevDeploy
 ******************************************************************************/

DpchInvWdbeWrdevDeploy::DpchInvWdbeWrdevDeploy(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMRelease
			, const string& folder
			, const bool Easy
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEWRDEVDEPLOY, oref, jref)
			, refWdbeMRelease(refWdbeMRelease)
			, folder(folder)
			, Easy(Easy)
		{
};

void DpchInvWdbeWrdevDeploy::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeWrdevDeploy");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMRelease", "", refWdbeMRelease)) add(REFWDBEMRELEASE);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
		if (extractBoolUclc(docctx, basexpath, "Easy", "", Easy)) add(EASY);
	};
};

void DpchInvWdbeWrdevDeploy::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeWrdevDeploy");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMRelease", refWdbeMRelease);
		writeString(wr, "folder", folder);
		writeBool(wr, "Easy", Easy);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbeWrdevUnt
 ******************************************************************************/

DpchInvWdbeWrdevUnt::DpchInvWdbeWrdevUnt(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMUnit
			, const string& folder
			, const bool Easy
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEWRDEVUNT, oref, jref)
			, refWdbeMUnit(refWdbeMUnit)
			, folder(folder)
			, Easy(Easy)
		{
};

void DpchInvWdbeWrdevUnt::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeWrdevUnt");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMUnit", "", refWdbeMUnit)) add(REFWDBEMUNIT);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
		if (extractBoolUclc(docctx, basexpath, "Easy", "", Easy)) add(EASY);
	};
};

void DpchInvWdbeWrdevUnt::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeWrdevUnt");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMUnit", refWdbeMUnit);
		writeString(wr, "folder", folder);
		writeBool(wr, "Easy", Easy);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT
