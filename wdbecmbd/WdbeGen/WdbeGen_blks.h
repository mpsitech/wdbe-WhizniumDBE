/**
	* \file WdbeGen_blks.h
	* invocation / return data blocks for operation pack WdbeGen (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEGEN_BLKS_H
#define WDBEGEN_BLKS_H

#include "Wdbe.h"

/**
	* DpchInvWdbeGenStdvec
	*/
class DpchInvWdbeGenStdvec : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMUNIT = 3;

public:
	DpchInvWdbeGenStdvec(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMUnit = 0);

public:
	Sbecore::ubigint refWdbeMUnit;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeGenTest
	*/
class DpchInvWdbeGenTest : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMMODULE = 3;

public:
	DpchInvWdbeGenTest(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0);

public:
	Sbecore::ubigint refWdbeMModule;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetWdbeGenTest
	*/
class DpchRetWdbeGenTest : public DpchRetWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint IXOPVOPRES = 3;
	static const Sbecore::uint PDONE = 4;
	static const Sbecore::uint LOGFILE = 5;

public:
	DpchRetWdbeGenTest(const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::uint ixOpVOpres = 0, const Sbecore::utinyint pdone = 0, const std::string& logfile = "");

public:
	std::string logfile;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeGenWiring
	*/
class DpchInvWdbeGenWiring : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMMODULE = 3;
	static const Sbecore::uint SREFKTOOLCH = 4;

public:
	DpchInvWdbeGenWiring(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string& srefKToolch = "");

public:
	Sbecore::ubigint refWdbeMModule;
	std::string srefKToolch;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetWdbeGenWiring
	*/
class DpchRetWdbeGenWiring : public DpchRetWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint IXOPVOPRES = 3;
	static const Sbecore::uint PDONE = 4;
	static const Sbecore::uint LOGFILE = 5;

public:
	DpchRetWdbeGenWiring(const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::uint ixOpVOpres = 0, const Sbecore::utinyint pdone = 0, const std::string& logfile = "");

public:
	std::string logfile;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif
