/**
	* \file WdbeMtpModbscbu_blks.h
	* invocation / return data blocks for operation pack WdbeMtpModbscbu (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMTPMODBSCBU_BLKS_H
#define WDBEMTPMODBSCBU_BLKS_H

#include "Wdbe.h"

/**
	* DpchInvWdbeMtpModbscbu
	*/
class DpchInvWdbeMtpModbscbu : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint SREFKCUSTOP = 3;
	static const Sbecore::uint REFWDBEMMODULE = 4;

public:
	DpchInvWdbeMtpModbscbu(const Sbecore::ubigint oref = 0, const std::string& srefKCustop = "", const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0);

public:
	std::string srefKCustop;

	Sbecore::ubigint refWdbeMModule;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif
