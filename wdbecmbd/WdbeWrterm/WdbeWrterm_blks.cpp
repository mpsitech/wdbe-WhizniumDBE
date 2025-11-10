/**
	* \file WdbeWrterm_blks.cpp
	* invocation / return data blocks for operation pack WdbeWrterm (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

#include "WdbeWrterm_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWdbeWrtermDeploy
 ******************************************************************************/

DpchInvWdbeWrtermDeploy::DpchInvWdbeWrtermDeploy(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMRelease
			, const string& folder
			, const bool Easy
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEWRTERMDEPLOY, oref, jref)
			, refWdbeMRelease(refWdbeMRelease)
			, folder(folder)
			, Easy(Easy)
		{
};

void DpchInvWdbeWrtermDeploy::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeWrtermDeploy");
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

void DpchInvWdbeWrtermDeploy::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeWrtermDeploy");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMRelease", refWdbeMRelease);
		writeString(wr, "folder", folder);
		writeBool(wr, "Easy", Easy);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbeWrtermMain
 ******************************************************************************/

DpchInvWdbeWrtermMain::DpchInvWdbeWrtermMain(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMRelease
			, const string& folder
			, const string& Prjshort
			, const bool Easy
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEWRTERMMAIN, oref, jref)
			, refWdbeMRelease(refWdbeMRelease)
			, folder(folder)
			, Prjshort(Prjshort)
			, Easy(Easy)
		{
};

void DpchInvWdbeWrtermMain::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeWrtermMain");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMRelease", "", refWdbeMRelease)) add(REFWDBEMRELEASE);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
		if (extractBoolUclc(docctx, basexpath, "Easy", "", Easy)) add(EASY);
	};
};

void DpchInvWdbeWrtermMain::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeWrtermMain");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMRelease", refWdbeMRelease);
		writeString(wr, "folder", folder);
		writeString(wr, "Prjshort", Prjshort);
		writeBool(wr, "Easy", Easy);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT
