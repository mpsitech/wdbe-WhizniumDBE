/**
	* \file WdbeQUntRef1NSignal.h
	* API code for table TblWdbeQUntRef1NSignal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2021
  */
// IP header --- ABOVE

#ifndef WDBEQUNTREF1NSIGNAL_H
#define WDBEQUNTREF1NSIGNAL_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQUntRef1NSignal
	*/
class WdbeQUntRef1NSignal {

public:
	WdbeQUntRef1NSignal(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQUntRef1NSignal
	*/
class ListWdbeQUntRef1NSignal {

public:
	ListWdbeQUntRef1NSignal();
	ListWdbeQUntRef1NSignal(const ListWdbeQUntRef1NSignal& src);
	ListWdbeQUntRef1NSignal& operator=(const ListWdbeQUntRef1NSignal& src);
	~ListWdbeQUntRef1NSignal();

	void clear();

public:
	std::vector<WdbeQUntRef1NSignal*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
