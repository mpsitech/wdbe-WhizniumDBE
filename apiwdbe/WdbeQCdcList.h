/**
	* \file WdbeQCdcList.h
	* API code for table TblWdbeQCdcList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#ifndef WDBEQCDCLIST_H
#define WDBEQCDCLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQCdcList
	*/
class WdbeQCdcList {

public:
	WdbeQCdcList(const Sbecore::uint jnum = 0, const std::string stubRefWdbeMModule = "");

public:
	Sbecore::uint jnum;
	std::string stubRefWdbeMModule;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQCdcList
	*/
class ListWdbeQCdcList {

public:
	ListWdbeQCdcList();
	ListWdbeQCdcList(const ListWdbeQCdcList& src);
	ListWdbeQCdcList& operator=(const ListWdbeQCdcList& src);
	~ListWdbeQCdcList();

	void clear();

public:
	std::vector<WdbeQCdcList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
