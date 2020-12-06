/**
	* \file WdbeQSigList.h
	* API code for table TblWdbeQSigList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQSIGLIST_H
#define WDBEQSIGLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQSigList
	*/
class WdbeQSigList {

public:
	WdbeQSigList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubMdlRefWdbeMModule = "", const std::string srefMgeIxVTbl = "", const std::string titMgeIxVTbl = "", const std::string stubMgeUref = "", const std::string stubRefWdbeMVector = "", const std::string yesnoConst = "", const std::string srefWdbeKHdltype = "", const std::string titSrefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string Minmax = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubMdlRefWdbeMModule;
	std::string srefMgeIxVTbl;
	std::string titMgeIxVTbl;
	std::string stubMgeUref;
	std::string stubRefWdbeMVector;
	std::string yesnoConst;
	std::string srefWdbeKHdltype;
	std::string titSrefWdbeKHdltype;
	Sbecore::usmallint Width;
	std::string Minmax;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQSigList
	*/
class ListWdbeQSigList {

public:
	ListWdbeQSigList();
	ListWdbeQSigList(const ListWdbeQSigList& src);
	ListWdbeQSigList& operator=(const ListWdbeQSigList& src);
	~ListWdbeQSigList();

	void clear();

public:
	std::vector<WdbeQSigList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
