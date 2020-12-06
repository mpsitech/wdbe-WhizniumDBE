/**
	* \file WdbeQSilSil1NUnit.h
	* API code for table TblWdbeQSilSil1NUnit (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQSILSIL1NUNIT_H
#define WDBEQSILSIL1NUNIT_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQSilSil1NUnit
	*/
class WdbeQSilSil1NUnit {

public:
	WdbeQSilSil1NUnit(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQSilSil1NUnit
	*/
class ListWdbeQSilSil1NUnit {

public:
	ListWdbeQSilSil1NUnit();
	ListWdbeQSilSil1NUnit(const ListWdbeQSilSil1NUnit& src);
	ListWdbeQSilSil1NUnit& operator=(const ListWdbeQSilSil1NUnit& src);
	~ListWdbeQSilSil1NUnit();

	void clear();

public:
	std::vector<WdbeQSilSil1NUnit*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
