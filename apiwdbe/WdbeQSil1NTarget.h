/**
	* \file WdbeQSil1NTarget.h
	* API code for table TblWdbeQSil1NTarget (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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

