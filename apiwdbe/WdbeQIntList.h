/**
	* \file WdbeQIntList.h
	* API code for table TblWdbeQIntList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQINTLIST_H
#define WDBEQINTLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQIntList
	*/
class WdbeQIntList {

public:
	WdbeQIntList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubRefWdbeMUnit = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubRefWdbeMUnit;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQIntList
	*/
class ListWdbeQIntList {

public:
	ListWdbeQIntList();
	ListWdbeQIntList(const ListWdbeQIntList& src);
	ListWdbeQIntList& operator=(const ListWdbeQIntList& src);
	~ListWdbeQIntList();

	void clear();

public:
	std::vector<WdbeQIntList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
