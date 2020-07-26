/**
	* \file WdbeQSil1NPeripheral.h
	* API code for table TblWdbeQSil1NPeripheral (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQSIL1NPERIPHERAL_H
#define WDBEQSIL1NPERIPHERAL_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQSil1NPeripheral
	*/
class WdbeQSil1NPeripheral {

public:
	WdbeQSil1NPeripheral(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQSil1NPeripheral
	*/
class ListWdbeQSil1NPeripheral {

public:
	ListWdbeQSil1NPeripheral();
	ListWdbeQSil1NPeripheral(const ListWdbeQSil1NPeripheral& src);
	ListWdbeQSil1NPeripheral& operator=(const ListWdbeQSil1NPeripheral& src);
	~ListWdbeQSil1NPeripheral();

	void clear();

public:
	std::vector<WdbeQSil1NPeripheral*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

