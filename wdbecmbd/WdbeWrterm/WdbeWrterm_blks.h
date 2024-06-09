/**
	* \file WdbeWrterm_blks.h
	* invocation / return data blocks for operation pack WdbeWrterm (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

#ifndef WDBEWRTERM_BLKS_H
#define WDBEWRTERM_BLKS_H

#include "Wdbe.h"

/**
	* DpchInvWdbeWrtermDeploy
	*/
class DpchInvWdbeWrtermDeploy : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMRELEASE = 3;
	static const Sbecore::uint FOLDER = 4;
	static const Sbecore::uint EASY = 5;

public:
	DpchInvWdbeWrtermDeploy(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMRelease = 0, const std::string& folder = "", const bool Easy = false);

public:
	Sbecore::ubigint refWdbeMRelease;
	std::string folder;
	bool Easy;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbeWrtermMain
	*/
class DpchInvWdbeWrtermMain : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMRELEASE = 3;
	static const Sbecore::uint FOLDER = 4;
	static const Sbecore::uint PRJSHORT = 5;
	static const Sbecore::uint EASY = 6;

public:
	DpchInvWdbeWrtermMain(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMRelease = 0, const std::string& folder = "", const std::string& Prjshort = "", const bool Easy = false);

public:
	Sbecore::ubigint refWdbeMRelease;
	std::string folder;
	std::string Prjshort;
	bool Easy;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif
