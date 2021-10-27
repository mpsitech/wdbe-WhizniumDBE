/**
	* \file WdbeMtpCplmsttd_blks.h
	* invocation / return data blocks for operation pack WdbeMtpCplmsttd (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTTD_BLKS_H
#define WDBEMTPCPLMSTTD_BLKS_H

#include "Wdbe.h"

/**
	* DpchInvWdbeMtpCplmsttd
	*/
class DpchInvWdbeMtpCplmsttd : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint SREFKCUSTOP = 3;
	static const Sbecore::uint REFWDBEMMODULE = 4;

public:
	DpchInvWdbeMtpCplmsttd(const Sbecore::ubigint oref = 0, const std::string& srefKCustop = "", const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0);

public:
	std::string srefKCustop;

	Sbecore::ubigint refWdbeMModule;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif
