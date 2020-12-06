/**
	* \file WdbeQPrcMge1NSignal.h
	* API code for table TblWdbeQPrcMge1NSignal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPRCMGE1NSIGNAL_H
#define WDBEQPRCMGE1NSIGNAL_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPrcMge1NSignal
	*/
class WdbeQPrcMge1NSignal {

public:
	WdbeQPrcMge1NSignal(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPrcMge1NSignal
	*/
class ListWdbeQPrcMge1NSignal {

public:
	ListWdbeQPrcMge1NSignal();
	ListWdbeQPrcMge1NSignal(const ListWdbeQPrcMge1NSignal& src);
	ListWdbeQPrcMge1NSignal& operator=(const ListWdbeQPrcMge1NSignal& src);
	~ListWdbeQPrcMge1NSignal();

	void clear();

public:
	std::vector<WdbeQPrcMge1NSignal*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
