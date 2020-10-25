/**
	* \file WdbeMtpWrfpga_blks.cpp
	* invocation / return data blocks for operation pack WdbeMtpWrfpga (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeMtpWrfpga_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWdbeMtpWrfpga
 ******************************************************************************/

DpchInvWdbeMtpWrfpga::DpchInvWdbeMtpWrfpga(
			const ubigint oref
			, const string& srefKCustop
			, const ubigint jref
			, const ubigint refWdbeMModule
			, const string& folder
			, const string& Prjshort
			, const string& Untsref
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEMTPWRFPGA, oref, jref)
		{
	this->srefKCustop = srefKCustop;
	this->refWdbeMModule = refWdbeMModule;
	this->folder = folder;
	this->Prjshort = Prjshort;
	this->Untsref = Untsref;
};

void DpchInvWdbeMtpWrfpga::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeMtpWrfpga");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "srefKCustop", "", srefKCustop)) add(SREFKCUSTOP);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMModule", "", refWdbeMModule)) add(REFWDBEMMODULE);
		if (extractStringUclc(docctx, basexpath, "folder", "", folder)) add(FOLDER);
		if (extractStringUclc(docctx, basexpath, "Prjshort", "", Prjshort)) add(PRJSHORT);
		if (extractStringUclc(docctx, basexpath, "Untsref", "", Untsref)) add(UNTSREF);
	};
};

void DpchInvWdbeMtpWrfpga::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeMtpWrfpga");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "srefKCustop", srefKCustop);
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMModule", refWdbeMModule);
		writeString(wr, "folder", folder);
		writeString(wr, "Prjshort", Prjshort);
		writeString(wr, "Untsref", Untsref);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT

