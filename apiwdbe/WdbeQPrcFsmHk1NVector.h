/**
	* \file WdbeQPrcFsmHk1NVector.h
	* API code for table TblWdbeQPrcFsmHk1NVector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Feb 2024
  */
// IP header --- ABOVE

#ifndef WDBEQPRCFSMHK1NVECTOR_H
#define WDBEQPRCFSMHK1NVECTOR_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPrcFsmHk1NVector
	*/
class WdbeQPrcFsmHk1NVector {

public:
	WdbeQPrcFsmHk1NVector(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPrcFsmHk1NVector
	*/
class ListWdbeQPrcFsmHk1NVector {

public:
	ListWdbeQPrcFsmHk1NVector();
	ListWdbeQPrcFsmHk1NVector(const ListWdbeQPrcFsmHk1NVector& src);
	ListWdbeQPrcFsmHk1NVector& operator=(const ListWdbeQPrcFsmHk1NVector& src);
	~ListWdbeQPrcFsmHk1NVector();

	void clear();

public:
	std::vector<WdbeQPrcFsmHk1NVector*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
