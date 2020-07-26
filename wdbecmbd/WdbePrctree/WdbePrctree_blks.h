/**
	* \file WdbePrctree_blks.h
	* invocation / return data blocks for operation pack WdbePrctree (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEPRCTREE_BLKS_H
#define WDBEPRCTREE_BLKS_H

#include "Wdbe.h"

/**
	* DpchInvWdbePrctreeExtract
	*/
class DpchInvWdbePrctreeExtract : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint INFILE = 3;
	static const Sbecore::uint INFOLDER = 4;
	static const Sbecore::uint EXTFILE = 5;
	static const Sbecore::uint EXTFOLDER = 6;

public:
	DpchInvWdbePrctreeExtract(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const std::string& infile = "", const std::string& infolder = "", const std::string& extfile = "", const std::string& extfolder = "");

public:
	std::string infile;
	std::string infolder;
	std::string extfile;
	std::string extfolder;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetWdbePrctreeExtract
	*/
class DpchRetWdbePrctreeExtract : public DpchRetWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint IXOPVOPRES = 3;
	static const Sbecore::uint PDONE = 4;
	static const Sbecore::uint LOGFILE = 5;

public:
	DpchRetWdbePrctreeExtract(const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::uint ixOpVOpres = 0, const Sbecore::utinyint pdone = 0, const std::string& logfile = "");

public:
	std::string logfile;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbePrctreeMerge
	*/
class DpchInvWdbePrctreeMerge : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint EXTFILE = 3;
	static const Sbecore::uint EXTFOLDER = 4;
	static const Sbecore::uint TPLFILE = 5;
	static const Sbecore::uint TPLFOLDER = 6;
	static const Sbecore::uint NOTRACE = 7;
	static const Sbecore::uint SKIPMULTVOID = 8;

public:
	DpchInvWdbePrctreeMerge(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0, const std::string& extfile = "", const std::string& extfolder = "", const std::string& tplfile = "", const std::string& tplfolder = "", const bool notrace = false, const bool skipmultvoid = false);

public:
	std::string extfile;
	std::string extfolder;
	std::string tplfile;
	std::string tplfolder;
	bool notrace;
	bool skipmultvoid;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetWdbePrctreeMerge
	*/
class DpchRetWdbePrctreeMerge : public DpchRetWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint IXOPVOPRES = 3;
	static const Sbecore::uint PDONE = 4;
	static const Sbecore::uint LOGFILE = 5;

public:
	DpchRetWdbePrctreeMerge(const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::uint ixOpVOpres = 0, const Sbecore::utinyint pdone = 0, const std::string& logfile = "");

public:
	std::string logfile;

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvWdbePrctreeValidate
	*/
class DpchInvWdbePrctreeValidate : public DpchInvWdbe {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;

public:
	DpchInvWdbePrctreeValidate(const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0);

public:

public:
	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif

