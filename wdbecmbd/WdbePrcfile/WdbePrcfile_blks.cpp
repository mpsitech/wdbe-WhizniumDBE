/**
	* \file WdbePrcfile_blks.cpp
	* invocation / return data blocks for operation pack WdbePrcfile (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "WdbePrcfile_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchInvWdbePrcfileConcat
 ******************************************************************************/

DpchInvWdbePrcfileConcat::DpchInvWdbePrcfileConcat(
			const ubigint oref
			, const ubigint jref
			, const vector<string>& infiles
			, const vector<string>& headers
			, const string& outfile
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEPRCFILECONCAT, oref, jref)
		{
	this->infiles = infiles;
	this->headers = headers;
	this->outfile = outfile;
};

void DpchInvWdbePrcfileConcat::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbePrcfileConcat");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractStringvecUclc(docctx, basexpath, "infiles", "", infiles)) add(INFILES);
		if (extractStringvecUclc(docctx, basexpath, "headers", "", headers)) add(HEADERS);
		if (extractStringUclc(docctx, basexpath, "outfile", "", outfile)) add(OUTFILE);
	};
};

void DpchInvWdbePrcfileConcat::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbePrcfileConcat");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeStringvec(wr, "infiles", infiles);
		writeStringvec(wr, "headers", headers);
		writeString(wr, "outfile", outfile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvWdbePrcfilePlhrpl
 ******************************************************************************/

DpchInvWdbePrcfilePlhrpl::DpchInvWdbePrcfilePlhrpl(
			const ubigint oref
			, const ubigint jref
			, const ubigint inRefWdbeMFile
			, const string& infile
			, const string& outfile
			, const vector<string>& keys
			, const vector<string>& vals
		) :
			DpchInvWdbe(VecWdbeVDpch::DPCHINVWDBEPRCFILEPLHRPL, oref, jref)
		{
	this->inRefWdbeMFile = inRefWdbeMFile;
	this->infile = infile;
	this->outfile = outfile;
	this->keys = keys;
	this->vals = vals;
};

void DpchInvWdbePrcfilePlhrpl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbePrcfilePlhrpl");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "inRefWdbeMFile", "", inRefWdbeMFile)) add(INREFWDBEMFILE);
		if (extractStringUclc(docctx, basexpath, "infile", "", infile)) add(INFILE);
		if (extractStringUclc(docctx, basexpath, "outfile", "", outfile)) add(OUTFILE);
		if (extractStringvecUclc(docctx, basexpath, "keys", "", keys)) add(KEYS);
		if (extractStringvecUclc(docctx, basexpath, "vals", "", vals)) add(VALS);
	};
};

void DpchInvWdbePrcfilePlhrpl::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvWdbePrcfilePlhrpl");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
		writeUbigint(wr, "inRefWdbeMFile", inRefWdbeMFile);
		writeString(wr, "infile", infile);
		writeString(wr, "outfile", outfile);
		writeStringvec(wr, "keys", keys);
		writeStringvec(wr, "vals", vals);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT
