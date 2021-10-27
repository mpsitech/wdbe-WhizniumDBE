/**
	* \file WdbeQUnt1NInterrupt.h
	* API code for table TblWdbeQUnt1NInterrupt (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQUNT1NINTERRUPT_H
#define WDBEQUNT1NINTERRUPT_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQUnt1NInterrupt
	*/
class WdbeQUnt1NInterrupt {

public:
	WdbeQUnt1NInterrupt(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQUnt1NInterrupt
	*/
class ListWdbeQUnt1NInterrupt {

public:
	ListWdbeQUnt1NInterrupt();
	ListWdbeQUnt1NInterrupt(const ListWdbeQUnt1NInterrupt& src);
	ListWdbeQUnt1NInterrupt& operator=(const ListWdbeQUnt1NInterrupt& src);
	~ListWdbeQUnt1NInterrupt();

	void clear();

public:
	std::vector<WdbeQUnt1NInterrupt*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
