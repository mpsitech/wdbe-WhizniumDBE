/**
	* \file WdbeQCmpMNLibrary.h
	* API code for table TblWdbeQCmpMNLibrary (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

#ifndef WDBEQCMPMNLIBRARY_H
#define WDBEQCMPMNLIBRARY_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQCmpMNLibrary
	*/
class WdbeQCmpMNLibrary {

public:
	WdbeQCmpMNLibrary(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQCmpMNLibrary
	*/
class ListWdbeQCmpMNLibrary {

public:
	ListWdbeQCmpMNLibrary();
	ListWdbeQCmpMNLibrary(const ListWdbeQCmpMNLibrary& src);
	ListWdbeQCmpMNLibrary& operator=(const ListWdbeQCmpMNLibrary& src);
	~ListWdbeQCmpMNLibrary();

	void clear();

public:
	std::vector<WdbeQCmpMNLibrary*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
