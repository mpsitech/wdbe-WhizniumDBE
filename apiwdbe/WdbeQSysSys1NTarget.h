/**
	* \file WdbeQSysSys1NTarget.h
	* API code for table TblWdbeQSysSys1NTarget (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQSYSSYS1NTARGET_H
#define WDBEQSYSSYS1NTARGET_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQSysSys1NTarget
	*/
class WdbeQSysSys1NTarget {

public:
	WdbeQSysSys1NTarget(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQSysSys1NTarget
	*/
class ListWdbeQSysSys1NTarget {

public:
	ListWdbeQSysSys1NTarget();
	ListWdbeQSysSys1NTarget(const ListWdbeQSysSys1NTarget& src);
	ListWdbeQSysSys1NTarget& operator=(const ListWdbeQSysSys1NTarget& src);
	~ListWdbeQSysSys1NTarget();

	void clear();

public:
	std::vector<WdbeQSysSys1NTarget*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

