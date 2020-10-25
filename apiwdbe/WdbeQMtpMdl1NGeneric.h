/**
	* \file WdbeQMtpMdl1NGeneric.h
	* API code for table TblWdbeQMtpMdl1NGeneric (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQMTPMDL1NGENERIC_H
#define WDBEQMTPMDL1NGENERIC_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMtpMdl1NGeneric
	*/
class WdbeQMtpMdl1NGeneric {

public:
	WdbeQMtpMdl1NGeneric(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQMtpMdl1NGeneric
	*/
class ListWdbeQMtpMdl1NGeneric {

public:
	ListWdbeQMtpMdl1NGeneric();
	ListWdbeQMtpMdl1NGeneric(const ListWdbeQMtpMdl1NGeneric& src);
	ListWdbeQMtpMdl1NGeneric& operator=(const ListWdbeQMtpMdl1NGeneric& src);
	~ListWdbeQMtpMdl1NGeneric();

	void clear();

public:
	std::vector<WdbeQMtpMdl1NGeneric*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

