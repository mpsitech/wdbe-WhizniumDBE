/**
	* \file WdbeQCmpList.h
	* API code for table TblWdbeQCmpList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

#ifndef WDBEQCMPLIST_H
#define WDBEQCMPLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQCmpList
	*/
class WdbeQCmpList {

public:
	WdbeQCmpList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubRefWdbeMVersion = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubRefWdbeMVersion;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQCmpList
	*/
class ListWdbeQCmpList {

public:
	ListWdbeQCmpList();
	ListWdbeQCmpList(const ListWdbeQCmpList& src);
	ListWdbeQCmpList& operator=(const ListWdbeQCmpList& src);
	~ListWdbeQCmpList();

	void clear();

public:
	std::vector<WdbeQCmpList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
