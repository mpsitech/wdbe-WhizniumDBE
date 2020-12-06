/**
	* \file WdbePrcfile_blks.h
	* invocation / return data blocks for operation pack WdbePrcfile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEPRCFILE_BLKS_H
#define WDBEPRCFILE_BLKS_H

#include "Wdbe.h"

/**
	* DpchInvWdbePrcfileConcat
	*/
class DpchInvWdbePrcfileConcat : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint INFILES = 3;
	static const Sbecore::uint HEADERS = 4;
	static const Sbecore::uint OUTFILE = 5;

public:
	DpchInvWdbePrcfileConcat(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const std::vector<std::string>& infiles = {}, const std::vector<std::string>& headers = {}, const std::string& outfile = "");

public:
	std::vector<std::string> infiles;
	std::vector<std::string> headers;
	std::string outfile;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbePrcfilePlhrpl
	*/
class DpchInvWdbePrcfilePlhrpl : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint INREFWDBEMFILE = 3;
	static const Sbecore::uint INFILE = 4;
	static const Sbecore::uint OUTFILE = 5;
	static const Sbecore::uint KEYS = 6;
	static const Sbecore::uint VALS = 7;

public:
	DpchInvWdbePrcfilePlhrpl(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint inRefWdbeMFile = 0, const std::string& infile = "", const std::string& outfile = "", const std::vector<std::string>& keys = {}, const std::vector<std::string>& vals = {});

public:
	Sbecore::ubigint inRefWdbeMFile;
	std::string infile;
	std::string outfile;
	std::vector<std::string> keys;
	std::vector<std::string> vals;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif
