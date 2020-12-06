/**
	* \file WdbeQUntSil1NUnit.h
	* API code for table TblWdbeQUntSil1NUnit (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQUNTSIL1NUNIT_H
#define WDBEQUNTSIL1NUNIT_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQUntSil1NUnit
	*/
class WdbeQUntSil1NUnit {

public:
	WdbeQUntSil1NUnit(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQUntSil1NUnit
	*/
class ListWdbeQUntSil1NUnit {

public:
	ListWdbeQUntSil1NUnit();
	ListWdbeQUntSil1NUnit(const ListWdbeQUntSil1NUnit& src);
	ListWdbeQUntSil1NUnit& operator=(const ListWdbeQUntSil1NUnit& src);
	~ListWdbeQUntSil1NUnit();

	void clear();

public:
	std::vector<WdbeQUntSil1NUnit*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
