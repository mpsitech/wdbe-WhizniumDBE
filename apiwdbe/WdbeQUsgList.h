/**
	* \file WdbeQUsgList.h
	* API code for table TblWdbeQUsgList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQUSGLIST_H
#define WDBEQUSGLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQUsgList
	*/
class WdbeQUsgList {

public:
	WdbeQUsgList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string sref = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string sref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQUsgList
	*/
class ListWdbeQUsgList {

public:
	ListWdbeQUsgList();
	ListWdbeQUsgList(const ListWdbeQUsgList& src);
	ListWdbeQUsgList& operator=(const ListWdbeQUsgList& src);
	~ListWdbeQUsgList();

	void clear();

public:
	std::vector<WdbeQUsgList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
