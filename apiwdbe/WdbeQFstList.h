/**
	* \file WdbeQFstList.h
	* API code for table TblWdbeQFstList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQFSTLIST_H
#define WDBEQFSTLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQFstList
	*/
class WdbeQFstList {

public:
	WdbeQFstList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubFsmRefWdbeMFsm = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubFsmRefWdbeMFsm;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQFstList
	*/
class ListWdbeQFstList {

public:
	ListWdbeQFstList();
	ListWdbeQFstList(const ListWdbeQFstList& src);
	ListWdbeQFstList& operator=(const ListWdbeQFstList& src);
	~ListWdbeQFstList();

	void clear();

public:
	std::vector<WdbeQFstList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

