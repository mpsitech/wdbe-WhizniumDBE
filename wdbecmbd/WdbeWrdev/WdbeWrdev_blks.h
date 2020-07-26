/**
	* \file WdbeWrdev_blks.h
	* invocation / return data blocks for operation pack WdbeWrdev (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEWRDEV_BLKS_H
#define WDBEWRDEV_BLKS_H

#include "Wdbe.h"

/**
	* DpchInvWdbeWrdevBase
	*/
class DpchInvWdbeWrdevBase : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMVERSION = 3;
	static const Sbecore::uint FOLDER = 4;
	static const Sbecore::uint PRJSHORT = 5;
	static const Sbecore::uint EASY = 6;

public:
	DpchInvWdbeWrdevBase(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMVersion = 0, const std::string& folder = "", const std::string& Prjshort = "", const bool Easy = false);

public:
	Sbecore::ubigint refWdbeMVersion;
	std::string folder;
	std::string Prjshort;
	bool Easy;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeWrdevCtr
	*/
class DpchInvWdbeWrdevCtr : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMCONTROLLER = 3;
	static const Sbecore::uint FOLDER = 4;
	static const Sbecore::uint EASY = 5;

public:
	DpchInvWdbeWrdevCtr(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMController = 0, const std::string& folder = "", const bool Easy = false);

public:
	Sbecore::ubigint refWdbeMController;
	std::string folder;
	bool Easy;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeWrdevDeploy
	*/
class DpchInvWdbeWrdevDeploy : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMRELEASE = 3;
	static const Sbecore::uint FOLDER = 4;
	static const Sbecore::uint EASY = 5;

public:
	DpchInvWdbeWrdevDeploy(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMRelease = 0, const std::string& folder = "", const bool Easy = false);

public:
	Sbecore::ubigint refWdbeMRelease;
	std::string folder;
	bool Easy;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeWrdevSys
	*/
class DpchInvWdbeWrdevSys : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMSYSTEM = 3;
	static const Sbecore::uint FOLDER = 4;

public:
	DpchInvWdbeWrdevSys(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMSystem = 0, const std::string& folder = "");

public:
	Sbecore::ubigint refWdbeMSystem;
	std::string folder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeWrdevUnt
	*/
class DpchInvWdbeWrdevUnt : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMUNIT = 3;
	static const Sbecore::uint FOLDER = 4;
	static const Sbecore::uint EASY = 5;

public:
	DpchInvWdbeWrdevUnt(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMUnit = 0, const std::string& folder = "", const bool Easy = false);

public:
	Sbecore::ubigint refWdbeMUnit;
	std::string folder;
	bool Easy;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif

