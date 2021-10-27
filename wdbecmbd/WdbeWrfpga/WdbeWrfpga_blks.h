/**
	* \file WdbeWrfpga_blks.h
	* invocation / return data blocks for operation pack WdbeWrfpga (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEWRFPGA_BLKS_H
#define WDBEWRFPGA_BLKS_H

#include "Wdbe.h"

/**
	* DpchInvWdbeWrfpgaBase
	*/
class DpchInvWdbeWrfpgaBase : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMUNIT = 3;
	static const Sbecore::uint FOLDER = 4;
	static const Sbecore::uint PRJSHORT = 5;
	static const Sbecore::uint UNTSREF = 6;

public:
	DpchInvWdbeWrfpgaBase(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMUnit = 0, const std::string& folder = "", const std::string& Prjshort = "", const std::string& Untsref = "");

public:
	Sbecore::ubigint refWdbeMUnit;
	std::string folder;
	std::string Prjshort;
	std::string Untsref;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeWrfpgaCtrFwdctr
	*/
class DpchInvWdbeWrfpgaCtrFwdctr : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMMODULE = 3;
	static const Sbecore::uint FOLDER = 4;
	static const Sbecore::uint PRJSHORT = 5;
	static const Sbecore::uint UNTSREF = 6;

public:
	DpchInvWdbeWrfpgaCtrFwdctr(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string& folder = "", const std::string& Prjshort = "", const std::string& Untsref = "");

public:
	Sbecore::ubigint refWdbeMModule;
	std::string folder;
	std::string Prjshort;
	std::string Untsref;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeWrfpgaDeploy
	*/
class DpchInvWdbeWrfpgaDeploy : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMRELEASE = 3;
	static const Sbecore::uint FOLDER = 4;

public:
	DpchInvWdbeWrfpgaDeploy(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMRelease = 0, const std::string& folder = "");

public:
	Sbecore::ubigint refWdbeMRelease;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeWrfpgaEhostif
	*/
class DpchInvWdbeWrfpgaEhostif : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMMODULE = 3;
	static const Sbecore::uint FOLDER = 4;
	static const Sbecore::uint PRJSHORT = 5;
	static const Sbecore::uint UNTSREF = 6;

public:
	DpchInvWdbeWrfpgaEhostif(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string& folder = "", const std::string& Prjshort = "", const std::string& Untsref = "");

public:
	Sbecore::ubigint refWdbeMModule;
	std::string folder;
	std::string Prjshort;
	std::string Untsref;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeWrfpgaHostif
	*/
class DpchInvWdbeWrfpgaHostif : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMMODULE = 3;
	static const Sbecore::uint FOLDER = 4;
	static const Sbecore::uint PRJSHORT = 5;
	static const Sbecore::uint UNTSREF = 6;

public:
	DpchInvWdbeWrfpgaHostif(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string& folder = "", const std::string& Prjshort = "", const std::string& Untsref = "");

public:
	Sbecore::ubigint refWdbeMModule;
	std::string folder;
	std::string Prjshort;
	std::string Untsref;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeWrfpgaIpclr
	*/
class DpchInvWdbeWrfpgaIpclr : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMMODULE = 3;
	static const Sbecore::uint FOLDER = 4;

public:
	DpchInvWdbeWrfpgaIpclr(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string& folder = "");

public:
	Sbecore::ubigint refWdbeMModule;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeWrfpgaMdlfine
	*/
class DpchInvWdbeWrfpgaMdlfine : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMMODULE = 3;
	static const Sbecore::uint FOLDER = 4;

public:
	DpchInvWdbeWrfpgaMdlfine(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string& folder = "");

public:
	Sbecore::ubigint refWdbeMModule;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeWrfpgaMdlraw
	*/
class DpchInvWdbeWrfpgaMdlraw : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMMODULE = 3;
	static const Sbecore::uint FOLDER = 4;
	static const Sbecore::uint PRJSHORT = 5;
	static const Sbecore::uint UNTSREF = 6;
	static const Sbecore::uint SREFKTOOLCH = 7;

public:
	DpchInvWdbeWrfpgaMdlraw(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string& folder = "", const std::string& Prjshort = "", const std::string& Untsref = "", const std::string& srefKToolch = "");

public:
	Sbecore::ubigint refWdbeMModule;
	std::string folder;
	std::string Prjshort;
	std::string Untsref;
	std::string srefKToolch;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeWrfpgaTop
	*/
class DpchInvWdbeWrfpgaTop : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMMODULE = 3;
	static const Sbecore::uint FOLDER = 4;
	static const Sbecore::uint PRJSHORT = 5;
	static const Sbecore::uint UNTSREF = 6;

public:
	DpchInvWdbeWrfpgaTop(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string& folder = "", const std::string& Prjshort = "", const std::string& Untsref = "");

public:
	Sbecore::ubigint refWdbeMModule;
	std::string folder;
	std::string Prjshort;
	std::string Untsref;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif
