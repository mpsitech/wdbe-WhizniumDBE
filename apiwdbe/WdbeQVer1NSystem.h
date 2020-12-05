/**
	* \file WdbeQVer1NSystem.h
	* API code for table TblWdbeQVer1NSystem (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQVER1NSYSTEM_H
#define WDBEQVER1NSYSTEM_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQVer1NSystem
	*/
class WdbeQVer1NSystem {

public:
	WdbeQVer1NSystem(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQVer1NSystem
	*/
class ListWdbeQVer1NSystem {

public:
	ListWdbeQVer1NSystem();
	ListWdbeQVer1NSystem(const ListWdbeQVer1NSystem& src);
	ListWdbeQVer1NSystem& operator=(const ListWdbeQVer1NSystem& src);
	~ListWdbeQVer1NSystem();

	void clear();

public:
	std::vector<WdbeQVer1NSystem*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

