/**
	* \file WdbeMtpPlhmcu_blks.h
	* invocation / return data blocks for operation pack WdbeMtpPlhmcu (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMTPPLHMCU_BLKS_H
#define WDBEMTPPLHMCU_BLKS_H

#include "Wdbe.h"

/**
	* DpchInvWdbeMtpPlhmcu
	*/
class DpchInvWdbeMtpPlhmcu : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint SREFKCUSTOP = 3;
	static const Sbecore::uint REFWDBEMMODULE = 4;

public:
	DpchInvWdbeMtpPlhmcu(const Sbecore::ubigint oref = 0, const std::string& srefKCustop = "", const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0);

public:
	std::string srefKCustop;

	Sbecore::ubigint refWdbeMModule;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetWdbeMtpPlhmcu
	*/
class DpchRetWdbeMtpPlhmcu : public DpchRetWdbe {

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
	DpchRetWdbeMtpPlhmcu(const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::uint ixOpVOpres = 0, const Sbecore::utinyint pdone = 0, const std::vector<std::string>& keys = {}, const std::vector<std::string>& vals = {});

public:
	std::vector<std::string> keys;
	std::vector<std::string> vals;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif

