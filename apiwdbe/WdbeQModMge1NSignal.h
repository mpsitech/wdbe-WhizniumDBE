/**
	* \file WdbeQModMge1NSignal.h
	* API code for table TblWdbeQModMge1NSignal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMODMGE1NSIGNAL_H
#define WDBEQMODMGE1NSIGNAL_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQModMge1NSignal
	*/
class WdbeQModMge1NSignal {

public:
	WdbeQModMge1NSignal(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQModMge1NSignal
	*/
class ListWdbeQModMge1NSignal {

public:
	ListWdbeQModMge1NSignal();
	ListWdbeQModMge1NSignal(const ListWdbeQModMge1NSignal& src);
	ListWdbeQModMge1NSignal& operator=(const ListWdbeQModMge1NSignal& src);
	~ListWdbeQModMge1NSignal();

	void clear();

public:
	std::vector<WdbeQModMge1NSignal*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
