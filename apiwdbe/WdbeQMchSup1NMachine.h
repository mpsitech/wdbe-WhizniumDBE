/**
	* \file WdbeQMchSup1NMachine.h
	* API code for table TblWdbeQMchSup1NMachine (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMCHSUP1NMACHINE_H
#define WDBEQMCHSUP1NMACHINE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMchSup1NMachine
	*/
class WdbeQMchSup1NMachine {

public:
	WdbeQMchSup1NMachine(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQMchSup1NMachine
	*/
class ListWdbeQMchSup1NMachine {

public:
	ListWdbeQMchSup1NMachine();
	ListWdbeQMchSup1NMachine(const ListWdbeQMchSup1NMachine& src);
	ListWdbeQMchSup1NMachine& operator=(const ListWdbeQMchSup1NMachine& src);
	~ListWdbeQMchSup1NMachine();

	void clear();

public:
	std::vector<WdbeQMchSup1NMachine*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
