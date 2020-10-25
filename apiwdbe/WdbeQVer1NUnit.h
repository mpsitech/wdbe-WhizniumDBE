/**
	* \file WdbeQVer1NUnit.h
	* API code for table TblWdbeQVer1NUnit (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQVER1NUNIT_H
#define WDBEQVER1NUNIT_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQVer1NUnit
	*/
class WdbeQVer1NUnit {

public:
	WdbeQVer1NUnit(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQVer1NUnit
	*/
class ListWdbeQVer1NUnit {

public:
	ListWdbeQVer1NUnit();
	ListWdbeQVer1NUnit(const ListWdbeQVer1NUnit& src);
	ListWdbeQVer1NUnit& operator=(const ListWdbeQVer1NUnit& src);
	~ListWdbeQVer1NUnit();

	void clear();

public:
	std::vector<WdbeQVer1NUnit*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

