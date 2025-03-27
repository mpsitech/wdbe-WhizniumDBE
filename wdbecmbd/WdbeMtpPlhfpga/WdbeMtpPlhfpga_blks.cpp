/**
	* \file WdbeMtpPlhfpga_blks.cpp
	* invocation / return data blocks for operation pack WdbeMtpPlhfpga (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "WdbeMtpPlhfpga_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWdbeMtpPlhfpga
 ******************************************************************************/

DpchInvWdbeMtpPlhfpga::DpchInvWdbeMtpPlhfpga(
			const ubigint oref
			, const string& srefKCustop
			, const ubigint jref
			, const ubigint refWdbeMModule
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEMTPPLHFPGA, oref, jref)
			, srefKCustop(srefKCustop)
			, refWdbeMModule(refWdbeMModule)
		{
};

void DpchInvWdbeMtpPlhfpga::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeMtpPlhfpga");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "srefKCustop", "", srefKCustop)) add(SREFKCUSTOP);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMModule", "", refWdbeMModule)) add(REFWDBEMMODULE);
	};
};

void DpchInvWdbeMtpPlhfpga::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeMtpPlhfpga");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "srefKCustop", srefKCustop);
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMModule", refWdbeMModule);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetWdbeMtpPlhfpga
 ******************************************************************************/

DpchRetWdbeMtpPlhfpga::DpchRetWdbeMtpPlhfpga(
			const string& scrOref
			, const string& scrJref
			, const uint ixOpVOpres
			, const utinyint pdone
			, const vector<string>& keys
			, const vector<string>& vals
		) :
			DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBEMTPPLHFPGA, scrOref, scrJref, ixOpVOpres, pdone)
			, keys(keys)
			, vals(vals)
		{
};

void DpchRetWdbeMtpPlhfpga::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxOpVOpres;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetWdbeMtpPlhfpga");
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

void DpchRetWdbeMtpPlhfpga::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetWdbeMtpPlhfpga");
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
