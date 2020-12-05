/**
	* \file WdbeQModCtrHk1NVector.h
	* API code for table TblWdbeQModCtrHk1NVector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMODCTRHK1NVECTOR_H
#define WDBEQMODCTRHK1NVECTOR_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQModCtrHk1NVector
	*/
class WdbeQModCtrHk1NVector {

public:
	WdbeQModCtrHk1NVector(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQModCtrHk1NVector
	*/
class ListWdbeQModCtrHk1NVector {

public:
	ListWdbeQModCtrHk1NVector();
	ListWdbeQModCtrHk1NVector(const ListWdbeQModCtrHk1NVector& src);
	ListWdbeQModCtrHk1NVector& operator=(const ListWdbeQModCtrHk1NVector& src);
	~ListWdbeQModCtrHk1NVector();

	void clear();

public:
	std::vector<WdbeQModCtrHk1NVector*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

