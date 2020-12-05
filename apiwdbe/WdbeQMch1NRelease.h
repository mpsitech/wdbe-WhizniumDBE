/**
	* \file WdbeQMch1NRelease.h
	* API code for table TblWdbeQMch1NRelease (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMCH1NRELEASE_H
#define WDBEQMCH1NRELEASE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMch1NRelease
	*/
class WdbeQMch1NRelease {

public:
	WdbeQMch1NRelease(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQMch1NRelease
	*/
class ListWdbeQMch1NRelease {

public:
	ListWdbeQMch1NRelease();
	ListWdbeQMch1NRelease(const ListWdbeQMch1NRelease& src);
	ListWdbeQMch1NRelease& operator=(const ListWdbeQMch1NRelease& src);
	~ListWdbeQMch1NRelease();

	void clear();

public:
	std::vector<WdbeQMch1NRelease*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

