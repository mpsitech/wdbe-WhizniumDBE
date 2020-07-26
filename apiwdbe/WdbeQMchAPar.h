/**
	* \file WdbeQMchAPar.h
	* API code for table TblWdbeQMchAPar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQMCHAPAR_H
#define WDBEQMCHAPAR_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMchAPar
	*/
class WdbeQMchAPar {

public:
	WdbeQMchAPar(const Sbecore::uint jnum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");

public:
	Sbecore::uint jnum;
	std::string x1SrefKKey;
	std::string titX1SrefKKey;
	std::string Val;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQMchAPar
	*/
class ListWdbeQMchAPar {

public:
	ListWdbeQMchAPar();
	ListWdbeQMchAPar(const ListWdbeQMchAPar& src);
	ListWdbeQMchAPar& operator=(const ListWdbeQMchAPar& src);
	~ListWdbeQMchAPar();

	void clear();

public:
	std::vector<WdbeQMchAPar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

