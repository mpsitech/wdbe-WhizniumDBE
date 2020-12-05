/**
	* \file WdbeQBnk1NPin.h
	* API code for table TblWdbeQBnk1NPin (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQBNK1NPIN_H
#define WDBEQBNK1NPIN_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQBnk1NPin
	*/
class WdbeQBnk1NPin {

public:
	WdbeQBnk1NPin(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQBnk1NPin
	*/
class ListWdbeQBnk1NPin {

public:
	ListWdbeQBnk1NPin();
	ListWdbeQBnk1NPin(const ListWdbeQBnk1NPin& src);
	ListWdbeQBnk1NPin& operator=(const ListWdbeQBnk1NPin& src);
	~ListWdbeQBnk1NPin();

	void clear();

public:
	std::vector<WdbeQBnk1NPin*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

