/**
	* \file WdbeQModRef1NSignal.h
	* API code for table TblWdbeQModRef1NSignal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2021
  */
// IP header --- ABOVE

#ifndef WDBEQMODREF1NSIGNAL_H
#define WDBEQMODREF1NSIGNAL_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQModRef1NSignal
	*/
class WdbeQModRef1NSignal {

public:
	WdbeQModRef1NSignal(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQModRef1NSignal
	*/
class ListWdbeQModRef1NSignal {

public:
	ListWdbeQModRef1NSignal();
	ListWdbeQModRef1NSignal(const ListWdbeQModRef1NSignal& src);
	ListWdbeQModRef1NSignal& operator=(const ListWdbeQModRef1NSignal& src);
	~ListWdbeQModRef1NSignal();

	void clear();

public:
	std::vector<WdbeQModRef1NSignal*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
