/**
	* \file WdbeModdet_blks.h
	* invocation / return data blocks for operation pack WdbeModdet (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMODDET_BLKS_H
#define WDBEMODDET_BLKS_H

#include "Wdbe.h"

/**
	* DpchInvWdbeModdetCmdbus
	*/
class DpchInvWdbeModdetCmdbus : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMMODULE = 3;
	static const Sbecore::uint MCUNOTFPGA = 4;

public:
	DpchInvWdbeModdetCmdbus(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0, const bool mcuNotFpga = false);

public:
	Sbecore::ubigint refWdbeMModule;
	bool mcuNotFpga;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeModdetCtrFwdctr
	*/
class DpchInvWdbeModdetCtrFwdctr : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMMODULE = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint UNTSREF = 5;

public:
	DpchInvWdbeModdetCtrFwdctr(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string& Prjshort = "", const std::string& Untsref = "");

public:
	Sbecore::ubigint refWdbeMModule;
	std::string Prjshort;
	std::string Untsref;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeModdetEctr
	*/
class DpchInvWdbeModdetEctr : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMMODULE = 3;
	static const Sbecore::uint PRJSHORT = 4;
	static const Sbecore::uint UNTSREF = 5;

public:
	DpchInvWdbeModdetEctr(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string& Prjshort = "", const std::string& Untsref = "");

public:
	Sbecore::ubigint refWdbeMModule;
	std::string Prjshort;
	std::string Untsref;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeModdetEhostif
	*/
class DpchInvWdbeModdetEhostif : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMMODULE = 3;
	static const Sbecore::uint MCUNOTFPGA = 4;

public:
	DpchInvWdbeModdetEhostif(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0, const bool mcuNotFpga = false);

public:
	Sbecore::ubigint refWdbeMModule;
	bool mcuNotFpga;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeModdetImbuf
	*/
class DpchInvWdbeModdetImbuf : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMMODULE = 3;

public:
	DpchInvWdbeModdetImbuf(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0);

public:
	Sbecore::ubigint refWdbeMModule;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeModdetUnt
	*/
class DpchInvWdbeModdetUnt : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMUNIT = 3;

public:
	DpchInvWdbeModdetUnt(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMUnit = 0);

public:
	Sbecore::ubigint refWdbeMUnit;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeModdetWiring
	*/
class DpchInvWdbeModdetWiring : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMMODULE = 3;

public:
	DpchInvWdbeModdetWiring(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0);

public:
	Sbecore::ubigint refWdbeMModule;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetWdbeModdetWiring
	*/
class DpchRetWdbeModdetWiring : public DpchRetWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint IXOPVOPRES = 3;
	static const Sbecore::uint PDONE = 4;
	static const Sbecore::uint LOGFILE = 5;

public:
	DpchRetWdbeModdetWiring(const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::uint ixOpVOpres = 0, const Sbecore::utinyint pdone = 0, const std::string& logfile = "");

public:
	std::string logfile;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif



