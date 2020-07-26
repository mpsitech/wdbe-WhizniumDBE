/**
	* \file WdbeQUnt1NTarget.h
	* API code for table TblWdbeQUnt1NTarget (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQUNT1NTARGET_H
#define WDBEQUNT1NTARGET_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQUnt1NTarget
	*/
class WdbeQUnt1NTarget {

public:
	WdbeQUnt1NTarget(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQUnt1NTarget
	*/
class ListWdbeQUnt1NTarget {

public:
	ListWdbeQUnt1NTarget();
	ListWdbeQUnt1NTarget(const ListWdbeQUnt1NTarget& src);
	ListWdbeQUnt1NTarget& operator=(const ListWdbeQUnt1NTarget& src);
	~ListWdbeQUnt1NTarget();

	void clear();

public:
	std::vector<WdbeQUnt1NTarget*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

