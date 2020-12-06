/**
	* \file WdbeQMchList.h
	* API code for table TblWdbeQMchList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMCHLIST_H
#define WDBEQMCHLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMchList
	*/
class WdbeQMchList {

public:
	WdbeQMchList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubSupRefWdbeMMachine = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubSupRefWdbeMMachine;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQMchList
	*/
class ListWdbeQMchList {

public:
	ListWdbeQMchList();
	ListWdbeQMchList(const ListWdbeQMchList& src);
	ListWdbeQMchList& operator=(const ListWdbeQMchList& src);
	~ListWdbeQMchList();

	void clear();

public:
	std::vector<WdbeQMchList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
