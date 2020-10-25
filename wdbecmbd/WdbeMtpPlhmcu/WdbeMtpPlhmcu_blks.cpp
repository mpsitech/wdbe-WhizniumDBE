/**
	* \file WdbeMtpPlhmcu_blks.cpp
	* invocation / return data blocks for operation pack WdbeMtpPlhmcu (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeMtpPlhmcu_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWdbeMtpPlhmcu
 ******************************************************************************/

DpchInvWdbeMtpPlhmcu::DpchInvWdbeMtpPlhmcu(
			const ubigint oref
			, const string& srefKCustop
			, const ubigint jref
			, const ubigint refWdbeMModule
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEMTPPLHMCU, oref, jref)
		{
	this->srefKCustop = srefKCustop;
	this->refWdbeMModule = refWdbeMModule;
};

void DpchInvWdbeMtpPlhmcu::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbeMtpPlhmcu");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "srefKCustop", "", srefKCustop)) add(SREFKCUSTOP);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refWdbeMModule", "", refWdbeMModule)) add(REFWDBEMMODULE);
	};
};

void DpchInvWdbeMtpPlhmcu::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbeMtpPlhmcu");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "srefKCustop", srefKCustop);
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "refWdbeMModule", refWdbeMModule);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetWdbeMtpPlhmcu
 ******************************************************************************/

DpchRetWdbeMtpPlhmcu::DpchRetWdbeMtpPlhmcu(
			const string& scrOref
			, const string& scrJref
			, const uint ixOpVOpres
			, const utinyint pdone
			, const vector<string>& keys
			, const vector<string>& vals
		) :
			DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBEMTPPLHMCU, scrOref, scrJref, ixOpVOpres, pdone)
		{
	this->keys = keys;
	this->vals = vals;
};

void DpchRetWdbeMtpPlhmcu::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxOpVOpres;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetWdbeMtpPlhmcu");
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

void DpchRetWdbeMtpPlhmcu::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetWdbeMtpPlhmcu");
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

