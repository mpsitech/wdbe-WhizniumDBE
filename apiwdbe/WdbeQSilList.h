/**
	* \file WdbeQSilList.h
	* API code for table TblWdbeQSilList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQSILLIST_H
#define WDBEQSILLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQSilList
	*/
class WdbeQSilList {

public:
	WdbeQSilList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Title = "", const std::string Fullsref = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const std::string stubRefUref = "", const std::string stubRefWdbeMSystem = "", const std::string stubRefWdbeMModule = "", const std::string srefKPackage = "", const std::string titSrefKPackage = "", const std::string yesnoEasy = "", const std::string srefKToolch = "", const std::string titSrefKToolch = "");

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
	* ListWdbeQSilList
	*/
class ListWdbeQSilList {

public:
	ListWdbeQSilList();
	ListWdbeQSilList(const ListWdbeQSilList& src);
	ListWdbeQSilList& operator=(const ListWdbeQSilList& src);
	~ListWdbeQSilList();

	void clear();

public:
	std::vector<WdbeQSilList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

