/**
	* \file WdbeQPrtList.h
	* API code for table TblWdbeQPrtList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPRTLIST_H
#define WDBEQPRTLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPrtList
	*/
class WdbeQPrtList {

public:
	WdbeQPrtList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubMdlRefWdbeMModule = "", const std::string srefMdlIxVCat = "", const std::string titMdlIxVCat = "", const std::string srefIxVDir = "", const std::string titIxVDir = "", const std::string srefWdbeKHdltype = "", const std::string titSrefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubMdlRefWdbeMModule;
	std::string srefMdlIxVCat;
	std::string titMdlIxVCat;
	std::string srefIxVDir;
	std::string titIxVDir;
	std::string srefWdbeKHdltype;
	std::string titSrefWdbeKHdltype;
	Sbecore::usmallint Width;
	std::string Minmax;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPrtList
	*/
class ListWdbeQPrtList {

public:
	ListWdbeQPrtList();
	ListWdbeQPrtList(const ListWdbeQPrtList& src);
	ListWdbeQPrtList& operator=(const ListWdbeQPrtList& src);
	~ListWdbeQPrtList();

	void clear();

public:
	std::vector<WdbeQPrtList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

