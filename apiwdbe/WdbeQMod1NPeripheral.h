/**
	* \file WdbeQMod1NPeripheral.h
	* API code for table TblWdbeQMod1NPeripheral (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMOD1NPERIPHERAL_H
#define WDBEQMOD1NPERIPHERAL_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMod1NPeripheral
	*/
class WdbeQMod1NPeripheral {

public:
	WdbeQMod1NPeripheral(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQMod1NPeripheral
	*/
class ListWdbeQMod1NPeripheral {

public:
	ListWdbeQMod1NPeripheral();
	ListWdbeQMod1NPeripheral(const ListWdbeQMod1NPeripheral& src);
	ListWdbeQMod1NPeripheral& operator=(const ListWdbeQMod1NPeripheral& src);
	~ListWdbeQMod1NPeripheral();

	void clear();

public:
	std::vector<WdbeQMod1NPeripheral*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

