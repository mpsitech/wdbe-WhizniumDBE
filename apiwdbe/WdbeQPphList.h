/**
	* \file WdbeQPphList.h
	* API code for table TblWdbeQPphList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPPHLIST_H
#define WDBEQPPHLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPphList
	*/
class WdbeQPphList {

public:
	WdbeQPphList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubRefWdbeMUnit = "", const std::string stubRefWdbeMModule = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubRefWdbeMUnit;
	std::string stubRefWdbeMModule;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPphList
	*/
class ListWdbeQPphList {

public:
	ListWdbeQPphList();
	ListWdbeQPphList(const ListWdbeQPphList& src);
	ListWdbeQPphList& operator=(const ListWdbeQPphList& src);
	~ListWdbeQPphList();

	void clear();

public:
	std::vector<WdbeQPphList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

