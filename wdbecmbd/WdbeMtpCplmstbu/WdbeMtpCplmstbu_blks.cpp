/**
	* \file WdbeMtpCplmstbu_blks.cpp
	* invocation / return data blocks for operation pack WdbeMtpCplmstbu (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeMtpCplmstbu_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWdbeMtpCplmstbu
 ******************************************************************************/

DpchInvWdbeMtpCplmstbu::DpchInvWdbeMtpCplmstbu(
			const ubigint oref
			, const string& srefKCustop
			, const ubigint jref
			, const ubigint refWdbeMModule
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEMTPCPLMSTBU, oref, jref)
		{
	this->srefKCustop = srefKCustop;
	this->refWdbeMModule = refWdbeMModule;
};

void DpchInvWdbeMtpCplmstbu::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeMtpCplmstbu");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "srefKCustop", "", srefKCustop)) add(SREFKCUSTOP);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMModule", "", refWdbeMModule)) add(REFWDBEMMODULE);
	};
};

void DpchInvWdbeMtpCplmstbu::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeMtpCplmstbu");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "srefKCustop", srefKCustop);
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMModule", refWdbeMModule);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT
