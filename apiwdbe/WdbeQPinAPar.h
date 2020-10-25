/**
	* \file WdbeQPinAPar.h
	* API code for table TblWdbeQPinAPar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQPINAPAR_H
#define WDBEQPINAPAR_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPinAPar
	*/
class WdbeQPinAPar {

public:
	WdbeQPinAPar(const Sbecore::uint jnum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");

public:
	Sbecore::uint jnum;
	std::string x1SrefKKey;
	std::string titX1SrefKKey;
	std::string Val;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPinAPar
	*/
class ListWdbeQPinAPar {

public:
	ListWdbeQPinAPar();
	ListWdbeQPinAPar(const ListWdbeQPinAPar& src);
	ListWdbeQPinAPar& operator=(const ListWdbeQPinAPar& src);
	~ListWdbeQPinAPar();

	void clear();

public:
	std::vector<WdbeQPinAPar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

