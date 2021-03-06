/**
	* \file WdbeQBnkList.h
	* API code for table TblWdbeQBnkList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQBNKLIST_H
#define WDBEQBNKLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQBnkList
	*/
class WdbeQBnkList {

public:
	WdbeQBnkList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubRefWdbeMUnit = "", const std::string srefKVoltstd = "", const std::string titSrefKVoltstd = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubRefWdbeMUnit;
	std::string srefKVoltstd;
	std::string titSrefKVoltstd;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQBnkList
	*/
class ListWdbeQBnkList {

public:
	ListWdbeQBnkList();
	ListWdbeQBnkList(const ListWdbeQBnkList& src);
	ListWdbeQBnkList& operator=(const ListWdbeQBnkList& src);
	~ListWdbeQBnkList();

	void clear();

public:
	std::vector<WdbeQBnkList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
