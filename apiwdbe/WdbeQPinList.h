/**
	* \file WdbeQPinList.h
	* API code for table TblWdbeQPinList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPINLIST_H
#define WDBEQPINLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPinList
	*/
class WdbeQPinList {

public:
	WdbeQPinList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubRefWdbeMBank = "", const std::string Location = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubRefWdbeMBank;
	std::string Location;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPinList
	*/
class ListWdbeQPinList {

public:
	ListWdbeQPinList();
	ListWdbeQPinList(const ListWdbeQPinList& src);
	ListWdbeQPinList& operator=(const ListWdbeQPinList& src);
	~ListWdbeQPinList();

	void clear();

public:
	std::vector<WdbeQPinList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
