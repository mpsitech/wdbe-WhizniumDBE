/**
	* \file WdbeQSil1NInterrupt.h
	* API code for table TblWdbeQSil1NInterrupt (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQSIL1NINTERRUPT_H
#define WDBEQSIL1NINTERRUPT_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQSil1NInterrupt
	*/
class WdbeQSil1NInterrupt {

public:
	WdbeQSil1NInterrupt(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQSil1NInterrupt
	*/
class ListWdbeQSil1NInterrupt {

public:
	ListWdbeQSil1NInterrupt();
	ListWdbeQSil1NInterrupt(const ListWdbeQSil1NInterrupt& src);
	ListWdbeQSil1NInterrupt& operator=(const ListWdbeQSil1NInterrupt& src);
	~ListWdbeQSil1NInterrupt();

	void clear();

public:
	std::vector<WdbeQSil1NInterrupt*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
