/**
	* \file WdbeQFam1NUnit.h
	* API code for table TblWdbeQFam1NUnit (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQFAM1NUNIT_H
#define WDBEQFAM1NUNIT_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQFam1NUnit
	*/
class WdbeQFam1NUnit {

public:
	WdbeQFam1NUnit(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQFam1NUnit
	*/
class ListWdbeQFam1NUnit {

public:
	ListWdbeQFam1NUnit();
	ListWdbeQFam1NUnit(const ListWdbeQFam1NUnit& src);
	ListWdbeQFam1NUnit& operator=(const ListWdbeQFam1NUnit& src);
	~ListWdbeQFam1NUnit();

	void clear();

public:
	std::vector<WdbeQFam1NUnit*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

