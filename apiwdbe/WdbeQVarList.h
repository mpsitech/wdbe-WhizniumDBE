/**
	* \file WdbeQVarList.h
	* API code for table TblWdbeQVarList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQVARLIST_H
#define WDBEQVARLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQVarList
	*/
class WdbeQVarList {

public:
	WdbeQVarList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const std::string stubRefUref = "", const std::string yesnoConst = "", const std::string yesnoFalling = "", const std::string srefWdbeKHdltype = "", const std::string titSrefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	std::string stubRefUref;
	std::string yesnoConst;
	std::string yesnoFalling;
	std::string srefWdbeKHdltype;
	std::string titSrefWdbeKHdltype;
	Sbecore::usmallint Width;
	std::string Minmax;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQVarList
	*/
class ListWdbeQVarList {

public:
	ListWdbeQVarList();
	ListWdbeQVarList(const ListWdbeQVarList& src);
	ListWdbeQVarList& operator=(const ListWdbeQVarList& src);
	~ListWdbeQVarList();

	void clear();

public:
	std::vector<WdbeQVarList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
