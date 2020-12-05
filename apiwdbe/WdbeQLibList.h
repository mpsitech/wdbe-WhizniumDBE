/**
	* \file WdbeQLibList.h
	* API code for table TblWdbeQLibList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQLIBLIST_H
#define WDBEQLIBLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQLibList
	*/
class WdbeQLibList {

public:
	WdbeQLibList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Title = "", const std::string Version = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Title;
	std::string Version;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQLibList
	*/
class ListWdbeQLibList {

public:
	ListWdbeQLibList();
	ListWdbeQLibList(const ListWdbeQLibList& src);
	ListWdbeQLibList& operator=(const ListWdbeQLibList& src);
	~ListWdbeQLibList();

	void clear();

public:
	std::vector<WdbeQLibList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

