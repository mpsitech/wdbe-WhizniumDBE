/**
	* \file WdbeQCmp1NRelease.h
	* API code for table TblWdbeQCmp1NRelease (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

#ifndef WDBEQCMP1NRELEASE_H
#define WDBEQCMP1NRELEASE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQCmp1NRelease
	*/
class WdbeQCmp1NRelease {

public:
	WdbeQCmp1NRelease(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQCmp1NRelease
	*/
class ListWdbeQCmp1NRelease {

public:
	ListWdbeQCmp1NRelease();
	ListWdbeQCmp1NRelease(const ListWdbeQCmp1NRelease& src);
	ListWdbeQCmp1NRelease& operator=(const ListWdbeQCmp1NRelease& src);
	~ListWdbeQCmp1NRelease();

	void clear();

public:
	std::vector<WdbeQCmp1NRelease*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
