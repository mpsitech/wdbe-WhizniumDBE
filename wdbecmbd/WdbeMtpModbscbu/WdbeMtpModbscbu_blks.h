/**
	* \file WdbeMtpModbscbu_blks.h
	* invocation / return data blocks for operation pack WdbeMtpModbscbu (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

