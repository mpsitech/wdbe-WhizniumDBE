/**
	* \file WdbeQFamList.h
	* API code for table TblWdbeQFamList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQFAMLIST_H
#define WDBEQFAMLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQFamList
	*/
class WdbeQFamList {

public:
	WdbeQFamList(const Sbecore::uint jnum = 0, const std::string srefKVendor = "", const std::string titSrefKVendor = "", const std::string Title = "");

public:
	Sbecore::uint jnum;
	std::string srefKVendor;
	std::string titSrefKVendor;
	std::string Title;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQFamList
	*/
class ListWdbeQFamList {

public:
	ListWdbeQFamList();
	ListWdbeQFamList(const ListWdbeQFamList& src);
	ListWdbeQFamList& operator=(const ListWdbeQFamList& src);
	~ListWdbeQFamList();

	void clear();

public:
	std::vector<WdbeQFamList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

