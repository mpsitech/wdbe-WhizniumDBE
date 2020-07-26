/**
	* \file WdbePlhmcu_blks.h
	* invocation / return data blocks for operation pack WdbePlhmcu (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEPLHMCU_BLKS_H
#define WDBEPLHMCU_BLKS_H

#include "Wdbe.h"

/**
	* DpchInvWdbePlhmcuEhostif
	*/
class DpchInvWdbePlhmcuEhostif : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMMODULE = 3;

public:
	DpchInvWdbePlhmcuEhostif(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0);

public:
	Sbecore::ubigint refWdbeMModule;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetWdbePlhmcuEhostif
	*/
class DpchRetWdbePlhmcuEhostif : public DpchRetWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint IXOPVOPRES = 3;
	static const Sbecore::uint PDONE = 4;
	static const Sbecore::uint KEYS = 5;
	static const Sbecore::uint VALS = 6;

public:
	DpchRetWdbePlhmcuEhostif(const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::uint ixOpVOpres = 0, const Sbecore::utinyint pdone = 0, const std::vector<std::string>& keys = {}, const std::vector<std::string>& vals = {});

public:
	std::vector<std::string> keys;
	std::vector<std::string> vals;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif

