/**
	* \file WdbeQVecVec1NVectoritem.h
	* API code for table TblWdbeQVecVec1NVectoritem (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQVECVEC1NVECTORITEM_H
#define WDBEQVECVEC1NVECTORITEM_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQVecVec1NVectoritem
	*/
class WdbeQVecVec1NVectoritem {

public:
	WdbeQVecVec1NVectoritem(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQVecVec1NVectoritem
	*/
class ListWdbeQVecVec1NVectoritem {

public:
	ListWdbeQVecVec1NVectoritem();
	ListWdbeQVecVec1NVectoritem(const ListWdbeQVecVec1NVectoritem& src);
	ListWdbeQVecVec1NVectoritem& operator=(const ListWdbeQVecVec1NVectoritem& src);
	~ListWdbeQVecVec1NVectoritem();

	void clear();

public:
	std::vector<WdbeQVecVec1NVectoritem*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
