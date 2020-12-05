/**
	* \file WdbeMtpWrmcu_blks.h
	* invocation / return data blocks for operation pack WdbeMtpWrmcu (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMTPWRMCU_BLKS_H
#define WDBEMTPWRMCU_BLKS_H

#include "Wdbe.h"

/**
	* DpchInvWdbeMtpWrmcu
	*/
class DpchInvWdbeMtpWrmcu : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint SREFKCUSTOP = 3;
	static const Sbecore::uint REFWDBEMMODULE = 4;
	static const Sbecore::uint FOLDER = 5;
	static const Sbecore::uint PRJSHORT = 6;
	static const Sbecore::uint UNTSREF = 7;

public:
	DpchInvWdbeMtpWrmcu(const Sbecore::ubigint oref = 0, const std::string& srefKCustop = "", const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string& folder = "", const std::string& Prjshort = "", const std::string& Untsref = "");

public:
	std::string srefKCustop;

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



