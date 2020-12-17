/**
	* \file WdbeQVerList.h
	* API code for table TblWdbeQVerList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQVERLIST_H
#define WDBEQVERLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQVerList
	*/
class WdbeQVerList {

public:
	WdbeQVerList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string stubPrjRefWdbeMProject = "", const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const std::string stubBvrRefWdbeMVersion = "", const std::string srefIxVState = "", const std::string titIxVState = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string stubPrjRefWdbeMProject;
	Sbecore::usmallint Major;
	Sbecore::usmallint Minor;
	Sbecore::usmallint Sub;
	std::string stubBvrRefWdbeMVersion;
	std::string srefIxVState;
	std::string titIxVState;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQVerList
	*/
class ListWdbeQVerList {

public:
	ListWdbeQVerList();
	ListWdbeQVerList(const ListWdbeQVerList& src);
	ListWdbeQVerList& operator=(const ListWdbeQVerList& src);
	~ListWdbeQVerList();

	void clear();

public:
	std::vector<WdbeQVerList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
