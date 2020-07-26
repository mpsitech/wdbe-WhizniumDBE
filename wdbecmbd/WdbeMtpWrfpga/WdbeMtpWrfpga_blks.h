/**
	* \file WdbeMtpWrfpga_blks.h
	* invocation / return data blocks for operation pack WdbeMtpWrfpga (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMTPWRFPGA_BLKS_H
#define WDBEMTPWRFPGA_BLKS_H

#include "Wdbe.h"

/**
	* DpchInvWdbeMtpWrfpga
	*/
class DpchInvWdbeMtpWrfpga : public DpchInvWdbe {

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
	DpchInvWdbeMtpWrfpga(const Sbecore::ubigint oref = 0, const std::string& srefKCustop = "", const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0, const std::string& folder = "", const std::string& Prjshort = "", const std::string& Untsref = "");

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

