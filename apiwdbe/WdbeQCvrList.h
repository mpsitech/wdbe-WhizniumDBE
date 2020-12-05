/**
	* \file WdbeQCvrList.h
	* API code for table TblWdbeQCvrList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQCVRLIST_H
#define WDBEQCVRLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQCvrList
	*/
class WdbeQCvrList {

public:
	WdbeQCvrList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string stubRefWdbeMCoreproject = "", const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const std::string stubBcvRefWdbeMCoreversion = "", const std::string srefIxVState = "", const std::string titIxVState = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string stubRefWdbeMCoreproject;
	Sbecore::usmallint Major;
	Sbecore::usmallint Minor;
	Sbecore::usmallint Sub;
	std::string stubBcvRefWdbeMCoreversion;
	std::string srefIxVState;
	std::string titIxVState;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQCvrList
	*/
class ListWdbeQCvrList {

public:
	ListWdbeQCvrList();
	ListWdbeQCvrList(const ListWdbeQCvrList& src);
	ListWdbeQCvrList& operator=(const ListWdbeQCvrList& src);
	~ListWdbeQCvrList();

	void clear();

public:
	std::vector<WdbeQCvrList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

