/**
	* \file WdbeQMchList.h
	* API code for table TblWdbeQMchList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQMCHLIST_H
#define WDBEQMCHLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMchList
	*/
class WdbeQMchList {

public:
	WdbeQMchList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefKPlatform = "", const std::string titSrefKPlatform = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefKPlatform;
	std::string titSrefKPlatform;

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

