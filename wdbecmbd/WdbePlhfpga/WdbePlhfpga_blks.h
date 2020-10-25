/**
	* \file WdbePlhfpga_blks.h
	* invocation / return data blocks for operation pack WdbePlhfpga (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEPLHFPGA_BLKS_H
#define WDBEPLHFPGA_BLKS_H

#include "Wdbe.h"

/**
	* DpchInvWdbePlhfpgaCmdinv
	*/
class DpchInvWdbePlhfpgaCmdinv : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMMODULE = 3;

public:
	DpchInvWdbePlhfpgaCmdinv(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0);

public:
	Sbecore::ubigint refWdbeMModule;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetWdbePlhfpgaCmdinv
	*/
class DpchRetWdbePlhfpgaCmdinv : public DpchRetWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint IXOPVOPRES = 3;
	static const Sbecore::uint PDONE = 4;
	static const Sbecore::uint KEYS = 5;
	static const Sbecore::uint VALS = 6;

public:
	DpchRetWdbePlhfpgaCmdinv(const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::uint ixOpVOpres = 0, const Sbecore::utinyint pdone = 0, const std::vector<std::string>& keys = {}, const std::vector<std::string>& vals = {});

public:
	std::vector<std::string> keys;
	std::vector<std::string> vals;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbePlhfpgaCmdret
	*/
class DpchInvWdbePlhfpgaCmdret : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMMODULE = 3;

public:
	DpchInvWdbePlhfpgaCmdret(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0);

public:
	Sbecore::ubigint refWdbeMModule;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetWdbePlhfpgaCmdret
	*/
class DpchRetWdbePlhfpgaCmdret : public DpchRetWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint IXOPVOPRES = 3;
	static const Sbecore::uint PDONE = 4;
	static const Sbecore::uint KEYS = 5;
	static const Sbecore::uint VALS = 6;

public:
	DpchRetWdbePlhfpgaCmdret(const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::uint ixOpVOpres = 0, const Sbecore::utinyint pdone = 0, const std::vector<std::string>& keys = {}, const std::vector<std::string>& vals = {});

public:
	std::vector<std::string> keys;
	std::vector<std::string> vals;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbePlhfpgaEhostif
	*/
class DpchInvWdbePlhfpgaEhostif : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMMODULE = 3;

public:
	DpchInvWdbePlhfpgaEhostif(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0);

public:
	Sbecore::ubigint refWdbeMModule;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetWdbePlhfpgaEhostif
	*/
class DpchRetWdbePlhfpgaEhostif : public DpchRetWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint IXOPVOPRES = 3;
	static const Sbecore::uint PDONE = 4;
	static const Sbecore::uint KEYS = 5;
	static const Sbecore::uint VALS = 6;

public:
	DpchRetWdbePlhfpgaEhostif(const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::uint ixOpVOpres = 0, const Sbecore::utinyint pdone = 0, const std::vector<std::string>& keys = {}, const std::vector<std::string>& vals = {});

public:
	std::vector<std::string> keys;
	std::vector<std::string> vals;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbePlhfpgaFwdctr
	*/
class DpchInvWdbePlhfpgaFwdctr : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint REFWDBEMMODULE = 3;

public:
	DpchInvWdbePlhfpgaFwdctr(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const Sbecore::ubigint refWdbeMModule = 0);

public:
	Sbecore::ubigint refWdbeMModule;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetWdbePlhfpgaFwdctr
	*/
class DpchRetWdbePlhfpgaFwdctr : public DpchRetWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint IXOPVOPRES = 3;
	static const Sbecore::uint PDONE = 4;
	static const Sbecore::uint KEYS = 5;
	static const Sbecore::uint VALS = 6;

public:
	DpchRetWdbePlhfpgaFwdctr(const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::uint ixOpVOpres = 0, const Sbecore::utinyint pdone = 0, const std::vector<std::string>& keys = {}, const std::vector<std::string>& vals = {});

public:
	std::vector<std::string> keys;
	std::vector<std::string> vals;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif

