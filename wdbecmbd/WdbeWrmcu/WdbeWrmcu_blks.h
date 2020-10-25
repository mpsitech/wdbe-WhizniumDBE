/**
	* \file WdbeWrmcu_blks.h
	* invocation / return data blocks for operation pack WdbeWrmcu (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEWRMCU_BLKS_H
#define WDBEWRMCU_BLKS_H

#include "Wdbe.h"

/**
	* DpchInvWdbeWrmcuBase
	*/
class DpchInvWdbeWrmcuBase : public DpchInvWdbe {

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
	DpchInvWdbeWrmcuBase(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMUnit = 0, const std::string& folder = "", const std::string& Prjshort = "", const std::string& Untsref = "");

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
	* DpchInvWdbeWrmcuCtrFwdctr
	*/
class DpchInvWdbeWrmcuCtrFwdctr : public DpchInvWdbe {

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
	DpchInvWdbeWrmcuCtrFwdctr(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string& folder = "", const std::string& Prjshort = "", const std::string& Untsref = "");

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
	* DpchInvWdbeWrmcuDeploy
	*/
class DpchInvWdbeWrmcuDeploy : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMRELEASE = 3;
	static const Sbecore::uint FOLDER = 4;

public:
	DpchInvWdbeWrmcuDeploy(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMRelease = 0, const std::string& folder = "");

public:
	Sbecore::ubigint refWdbeMRelease;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeWrmcuEhostif
	*/
class DpchInvWdbeWrmcuEhostif : public DpchInvWdbe {

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
	DpchInvWdbeWrmcuEhostif(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string& folder = "", const std::string& Prjshort = "", const std::string& Untsref = "");

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
	* DpchInvWdbeWrmcuMdlfine
	*/
class DpchInvWdbeWrmcuMdlfine : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMMODULE = 3;
	static const Sbecore::uint FOLDER = 4;

public:
	DpchInvWdbeWrmcuMdlfine(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string& folder = "");

public:
	Sbecore::ubigint refWdbeMModule;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeWrmcuMdlraw
	*/
class DpchInvWdbeWrmcuMdlraw : public DpchInvWdbe {

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
	DpchInvWdbeWrmcuMdlraw(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string& folder = "", const std::string& Prjshort = "", const std::string& Untsref = "");

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

