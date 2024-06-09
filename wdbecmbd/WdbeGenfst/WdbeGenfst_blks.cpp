/**
	* \file WdbeGenfst_blks.cpp
	* invocation / return data blocks for operation pack WdbeGenfst (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeGenfst_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWdbeGenfstCmdbus
 ******************************************************************************/

DpchInvWdbeGenfstCmdbus::DpchInvWdbeGenfstCmdbus(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMModule
			, const bool mcuNotFpga
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEGENFSTCMDBUS, oref, jref)
		{
	this->refWdbeMModule = refWdbeMModule;
	this->mcuNotFpga = mcuNotFpga;
};

void DpchInvWdbeGenfstCmdbus::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeGenfstCmdbus");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMModule", "", refWdbeMModule)) add(REFWDBEMMODULE);
		if (extractBoolUclc(docctx, basexpath, "mcuNotFpga", "", mcuNotFpga)) add(MCUNOTFPGA);
	};
};

void DpchInvWdbeGenfstCmdbus::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeGenfstCmdbus");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMModule", refWdbeMModule);
		writeBool(wr, "mcuNotFpga", mcuNotFpga);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbeGenfstCtr
 ******************************************************************************/

DpchInvWdbeGenfstCtr::DpchInvWdbeGenfstCtr(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMModule
			, const string& Prjshort
			, const string& Untsref
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEGENFSTCTR, oref, jref)
		{
	this->refWdbeMModule = refWdbeMModule;
	this->Prjshort = Prjshort;
	this->Untsref = Untsref;
};

void DpchInvWdbeGenfstCtr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeGenfstCtr");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMModule", "", refWdbeMModule)) add(REFWDBEMMODULE);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
		if (extractStringUclc(docctx, basexpath, "Untsref", "", Untsref)) add(UNTSREF);
	};
};

void DpchInvWdbeGenfstCtr::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeGenfstCtr");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMModule", refWdbeMModule);
		writeString(wr, "Prjshort", Prjshort);
		writeString(wr, "Untsref", Untsref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbeGenfstEctr
 ******************************************************************************/

DpchInvWdbeGenfstEctr::DpchInvWdbeGenfstEctr(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMModule
			, const string& Prjshort
			, const string& Untsref
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEGENFSTECTR, oref, jref)
		{
	this->refWdbeMModule = refWdbeMModule;
	this->Prjshort = Prjshort;
	this->Untsref = Untsref;
};

void DpchInvWdbeGenfstEctr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeGenfstEctr");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMModule", "", refWdbeMModule)) add(REFWDBEMMODULE);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
		if (extractStringUclc(docctx, basexpath, "Untsref", "", Untsref)) add(UNTSREF);
	};
};

void DpchInvWdbeGenfstEctr::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeGenfstEctr");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMModule", refWdbeMModule);
		writeString(wr, "Prjshort", Prjshort);
		writeString(wr, "Untsref", Untsref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbeGenfstEhostif
 ******************************************************************************/

DpchInvWdbeGenfstEhostif::DpchInvWdbeGenfstEhostif(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMModule
			, const bool mcuNotFpga
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEGENFSTEHOSTIF, oref, jref)
		{
	this->refWdbeMModule = refWdbeMModule;
	this->mcuNotFpga = mcuNotFpga;
};

void DpchInvWdbeGenfstEhostif::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeGenfstEhostif");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMModule", "", refWdbeMModule)) add(REFWDBEMMODULE);
		if (extractBoolUclc(docctx, basexpath, "mcuNotFpga", "", mcuNotFpga)) add(MCUNOTFPGA);
	};
};

void DpchInvWdbeGenfstEhostif::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeGenfstEhostif");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMModule", refWdbeMModule);
		writeBool(wr, "mcuNotFpga", mcuNotFpga);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbeGenfstHostif
 ******************************************************************************/

DpchInvWdbeGenfstHostif::DpchInvWdbeGenfstHostif(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMModule
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEGENFSTHOSTIF, oref, jref)
		{
	this->refWdbeMModule = refWdbeMModule;
};

void DpchInvWdbeGenfstHostif::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeGenfstHostif");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMModule", "", refWdbeMModule)) add(REFWDBEMMODULE);
	};
};

void DpchInvWdbeGenfstHostif::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeGenfstHostif");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMModule", refWdbeMModule);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbeGenfstImbuf
 ******************************************************************************/

DpchInvWdbeGenfstImbuf::DpchInvWdbeGenfstImbuf(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMModule
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEGENFSTIMBUF, oref, jref)
		{
	this->refWdbeMModule = refWdbeMModule;
};

void DpchInvWdbeGenfstImbuf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeGenfstImbuf");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMModule", "", refWdbeMModule)) add(REFWDBEMMODULE);
	};
};

void DpchInvWdbeGenfstImbuf::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeGenfstImbuf");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMModule", refWdbeMModule);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbeGenfstPpl
 ******************************************************************************/

DpchInvWdbeGenfstPpl::DpchInvWdbeGenfstPpl(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMPipeline
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEGENFSTPPL, oref, jref)
		{
	this->refWdbeMPipeline = refWdbeMPipeline;
};

void DpchInvWdbeGenfstPpl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeGenfstPpl");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMPipeline", "", refWdbeMPipeline)) add(REFWDBEMPIPELINE);
	};
};

void DpchInvWdbeGenfstPpl::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeGenfstPpl");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMPipeline", refWdbeMPipeline);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbeGenfstTop
 ******************************************************************************/

DpchInvWdbeGenfstTop::DpchInvWdbeGenfstTop(
			const ubigint oref
			, const ubigint jref
			, const ubigint refWdbeMModule
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEGENFSTTOP, oref, jref)
		{
	this->refWdbeMModule = refWdbeMModule;
};

void DpchInvWdbeGenfstTop::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeGenfstTop");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMModule", "", refWdbeMModule)) add(REFWDBEMMODULE);
	};
};

void DpchInvWdbeGenfstTop::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeGenfstTop");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMModule", refWdbeMModule);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT
