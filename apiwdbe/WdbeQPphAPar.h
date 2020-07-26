/**
	* \file WdbeQPphAPar.h
	* API code for table TblWdbeQPphAPar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQPPHAPAR_H
#define WDBEQPPHAPAR_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPphAPar
	*/
class WdbeQPphAPar {

public:
	WdbeQPphAPar(const Sbecore::uint jnum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");

public:
	Sbecore::uint jnum;
	std::string x1SrefKKey;
	std::string titX1SrefKKey;
	std::string Val;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPphAPar
	*/
class ListWdbeQPphAPar {

public:
	ListWdbeQPphAPar();
	ListWdbeQPphAPar(const ListWdbeQPphAPar& src);
	ListWdbeQPphAPar& operator=(const ListWdbeQPphAPar& src);
	~ListWdbeQPphAPar();

	void clear();

public:
	std::vector<WdbeQPphAPar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

