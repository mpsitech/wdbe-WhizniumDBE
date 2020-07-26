/**
	* \file WdbeQGenList.h
	* API code for table TblWdbeQGenList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQGENLIST_H
#define WDBEQGENLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQGenList
	*/
class WdbeQGenList {

public:
	WdbeQGenList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubMdlRefWdbeMModule = "", const std::string srefWdbeKHdltype = "", const std::string titSrefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubMdlRefWdbeMModule;
	std::string srefWdbeKHdltype;
	std::string titSrefWdbeKHdltype;
	Sbecore::usmallint Width;
	std::string Minmax;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQGenList
	*/
class ListWdbeQGenList {

public:
	ListWdbeQGenList();
	ListWdbeQGenList(const ListWdbeQGenList& src);
	ListWdbeQGenList& operator=(const ListWdbeQGenList& src);
	~ListWdbeQGenList();

	void clear();

public:
	std::vector<WdbeQGenList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

