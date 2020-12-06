/**
	* \file WdbeQUntList.h
	* API code for table TblWdbeQUntList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQUNTLIST_H
#define WDBEQUNTLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQUntList
	*/
class WdbeQUntList {

public:
	WdbeQUntList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Title = "", const std::string Fullsref = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const std::string stubRefUref = "", const std::string stubRefWdbeMSystem = "", const std::string stubRefWdbeMModule = "", const std::string srefKPackage = "", const std::string titSrefKPackage = "", const std::string yesnoEasy = "", const std::string srefKToolch = "", const std::string titSrefKToolch = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Title;
	std::string Fullsref;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	std::string stubRefUref;
	std::string stubRefWdbeMSystem;
	std::string stubRefWdbeMModule;
	std::string srefKPackage;
	std::string titSrefKPackage;
	std::string yesnoEasy;
	std::string srefKToolch;
	std::string titSrefKToolch;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQUntList
	*/
class ListWdbeQUntList {

public:
	ListWdbeQUntList();
	ListWdbeQUntList(const ListWdbeQUntList& src);
	ListWdbeQUntList& operator=(const ListWdbeQUntList& src);
	~ListWdbeQUntList();

	void clear();

public:
	std::vector<WdbeQUntList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
