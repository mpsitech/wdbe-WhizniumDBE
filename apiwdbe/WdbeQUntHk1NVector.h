/**
	* \file WdbeQUntHk1NVector.h
	* API code for table TblWdbeQUntHk1NVector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQUNTHK1NVECTOR_H
#define WDBEQUNTHK1NVECTOR_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQUntHk1NVector
	*/
class WdbeQUntHk1NVector {

public:
	WdbeQUntHk1NVector(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQUntHk1NVector
	*/
class ListWdbeQUntHk1NVector {

public:
	ListWdbeQUntHk1NVector();
	ListWdbeQUntHk1NVector(const ListWdbeQUntHk1NVector& src);
	ListWdbeQUntHk1NVector& operator=(const ListWdbeQUntHk1NVector& src);
	~ListWdbeQUntHk1NVector();

	void clear();

public:
	std::vector<WdbeQUntHk1NVector*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

