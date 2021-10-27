/**
	* \file WdbeQModMNPeripheral.h
	* API code for table TblWdbeQModMNPeripheral (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 13 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBEQMODMNPERIPHERAL_H
#define WDBEQMODMNPERIPHERAL_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQModMNPeripheral
	*/
class WdbeQModMNPeripheral {

public:
	WdbeQModMNPeripheral(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQModMNPeripheral
	*/
class ListWdbeQModMNPeripheral {

public:
	ListWdbeQModMNPeripheral();
	ListWdbeQModMNPeripheral(const ListWdbeQModMNPeripheral& src);
	ListWdbeQModMNPeripheral& operator=(const ListWdbeQModMNPeripheral& src);
	~ListWdbeQModMNPeripheral();

	void clear();

public:
	std::vector<WdbeQModMNPeripheral*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
