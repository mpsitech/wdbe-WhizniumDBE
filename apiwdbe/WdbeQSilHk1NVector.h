/**
	* \file WdbeQSilHk1NVector.h
	* API code for table TblWdbeQSilHk1NVector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQSILHK1NVECTOR_H
#define WDBEQSILHK1NVECTOR_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQSilHk1NVector
	*/
class WdbeQSilHk1NVector {

public:
	WdbeQSilHk1NVector(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQSilHk1NVector
	*/
class ListWdbeQSilHk1NVector {

public:
	ListWdbeQSilHk1NVector();
	ListWdbeQSilHk1NVector(const ListWdbeQSilHk1NVector& src);
	ListWdbeQSilHk1NVector& operator=(const ListWdbeQSilHk1NVector& src);
	~ListWdbeQSilHk1NVector();

	void clear();

public:
	std::vector<WdbeQSilHk1NVector*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

