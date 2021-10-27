/**
	* \file WdbeQSnsList.h
	* API code for table TblWdbeQSnsList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQSNSLIST_H
#define WDBEQSNSLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQSnsList
	*/
class WdbeQSnsList {

public:
	WdbeQSnsList(const Sbecore::uint jnum = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const std::string stubRefUref = "", const std::string srefSrcIxVTbl = "", const std::string titSrcIxVTbl = "", const std::string stubSrcUref = "");

public:
	Sbecore::uint jnum;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	std::string stubRefUref;
	std::string srefSrcIxVTbl;
	std::string titSrcIxVTbl;
	std::string stubSrcUref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQSnsList
	*/
class ListWdbeQSnsList {

public:
	ListWdbeQSnsList();
	ListWdbeQSnsList(const ListWdbeQSnsList& src);
	ListWdbeQSnsList& operator=(const ListWdbeQSnsList& src);
	~ListWdbeQSnsList();

	void clear();

public:
	std::vector<WdbeQSnsList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
