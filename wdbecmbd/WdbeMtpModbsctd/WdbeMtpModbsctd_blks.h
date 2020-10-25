/**
	* \file WdbeMtpModbsctd_blks.h
	* invocation / return data blocks for operation pack WdbeMtpModbsctd (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMTPMODBSCTD_BLKS_H
#define WDBEMTPMODBSCTD_BLKS_H

#include "Wdbe.h"

/**
	* DpchInvWdbeMtpModbsctd
	*/
class DpchInvWdbeMtpModbsctd : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint SREFKCUSTOP = 3;
	static const Sbecore::uint REFWDBEMMODULE = 4;

public:
	DpchInvWdbeMtpModbsctd(const Sbecore::ubigint oref = 0, const std::string& srefKCustop = "", const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0);

public:
	std::string srefKCustop;

	Sbecore::ubigint refWdbeMModule;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif

