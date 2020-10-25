/**
	* \file WdbeQPphList.h
	* API code for table TblWdbeQPphList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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

