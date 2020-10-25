/**
	* \file WdbeQVer1NRelease.h
	* API code for table TblWdbeQVer1NRelease (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQVER1NRELEASE_H
#define WDBEQVER1NRELEASE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQVer1NRelease
	*/
class WdbeQVer1NRelease {

public:
	WdbeQVer1NRelease(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQVer1NRelease
	*/
class ListWdbeQVer1NRelease {

public:
	ListWdbeQVer1NRelease();
	ListWdbeQVer1NRelease(const ListWdbeQVer1NRelease& src);
	ListWdbeQVer1NRelease& operator=(const ListWdbeQVer1NRelease& src);
	~ListWdbeQVer1NRelease();

	void clear();

public:
	std::vector<WdbeQVer1NRelease*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

