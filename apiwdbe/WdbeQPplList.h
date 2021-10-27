/**
	* \file WdbeQPplList.h
	* API code for table TblWdbeQPplList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQPPLLIST_H
#define WDBEQPPLLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPplList
	*/
class WdbeQPplList {

public:
	WdbeQPplList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubHsmRefWdbeMModule = "", const Sbecore::usmallint Depth = 0);

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubHsmRefWdbeMModule;
	Sbecore::usmallint Depth;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPplList
	*/
class ListWdbeQPplList {

public:
	ListWdbeQPplList();
	ListWdbeQPplList(const ListWdbeQPplList& src);
	ListWdbeQPplList& operator=(const ListWdbeQPplList& src);
	~ListWdbeQPplList();

	void clear();

public:
	std::vector<WdbeQPplList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
