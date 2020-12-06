/**
	* \file WdbeQModAPar.h
	* API code for table TblWdbeQModAPar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMODAPAR_H
#define WDBEQMODAPAR_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQModAPar
	*/
class WdbeQModAPar {

public:
	WdbeQModAPar(const Sbecore::uint jnum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");

public:
	Sbecore::uint jnum;
	std::string x1SrefKKey;
	std::string titX1SrefKKey;
	std::string Val;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQModAPar
	*/
class ListWdbeQModAPar {

public:
	ListWdbeQModAPar();
	ListWdbeQModAPar(const ListWdbeQModAPar& src);
	ListWdbeQModAPar& operator=(const ListWdbeQModAPar& src);
	~ListWdbeQModAPar();

	void clear();

public:
	std::vector<WdbeQModAPar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
