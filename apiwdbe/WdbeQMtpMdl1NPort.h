/**
	* \file WdbeQMtpMdl1NPort.h
	* API code for table TblWdbeQMtpMdl1NPort (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQMTPMDL1NPORT_H
#define WDBEQMTPMDL1NPORT_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMtpMdl1NPort
	*/
class WdbeQMtpMdl1NPort {

public:
	WdbeQMtpMdl1NPort(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQMtpMdl1NPort
	*/
class ListWdbeQMtpMdl1NPort {

public:
	ListWdbeQMtpMdl1NPort();
	ListWdbeQMtpMdl1NPort(const ListWdbeQMtpMdl1NPort& src);
	ListWdbeQMtpMdl1NPort& operator=(const ListWdbeQMtpMdl1NPort& src);
	~ListWdbeQMtpMdl1NPort();

	void clear();

public:
	std::vector<WdbeQMtpMdl1NPort*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

