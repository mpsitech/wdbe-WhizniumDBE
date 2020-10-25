/**
	* \file WdbeQUnt1NPeripheral.h
	* API code for table TblWdbeQUnt1NPeripheral (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQUNT1NPERIPHERAL_H
#define WDBEQUNT1NPERIPHERAL_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQUnt1NPeripheral
	*/
class WdbeQUnt1NPeripheral {

public:
	WdbeQUnt1NPeripheral(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQUnt1NPeripheral
	*/
class ListWdbeQUnt1NPeripheral {

public:
	ListWdbeQUnt1NPeripheral();
	ListWdbeQUnt1NPeripheral(const ListWdbeQUnt1NPeripheral& src);
	ListWdbeQUnt1NPeripheral& operator=(const ListWdbeQUnt1NPeripheral& src);
	~ListWdbeQUnt1NPeripheral();

	void clear();

public:
	std::vector<WdbeQUnt1NPeripheral*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

