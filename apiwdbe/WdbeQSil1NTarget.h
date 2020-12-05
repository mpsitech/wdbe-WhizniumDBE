/**
	* \file WdbeQSil1NTarget.h
	* API code for table TblWdbeQSil1NTarget (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQSIL1NTARGET_H
#define WDBEQSIL1NTARGET_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQSil1NTarget
	*/
class WdbeQSil1NTarget {

public:
	WdbeQSil1NTarget(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQSil1NTarget
	*/
class ListWdbeQSil1NTarget {

public:
	ListWdbeQSil1NTarget();
	ListWdbeQSil1NTarget(const ListWdbeQSil1NTarget& src);
	ListWdbeQSil1NTarget& operator=(const ListWdbeQSil1NTarget& src);
	~ListWdbeQSil1NTarget();

	void clear();

public:
	std::vector<WdbeQSil1NTarget*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

