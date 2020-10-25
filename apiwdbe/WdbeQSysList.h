/**
	* \file WdbeQSysList.h
	* API code for table TblWdbeQSysList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQSYSLIST_H
#define WDBEQSYSLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQSysList
	*/
class WdbeQSysList {

public:
	WdbeQSysList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubRefWdbeMVersion = "", const std::string stubRefWdbeMUnit = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubRefWdbeMVersion;
	std::string stubRefWdbeMUnit;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQSysList
	*/
class ListWdbeQSysList {

public:
	ListWdbeQSysList();
	ListWdbeQSysList(const ListWdbeQSysList& src);
	ListWdbeQSysList& operator=(const ListWdbeQSysList& src);
	~ListWdbeQSysList();

	void clear();

public:
	std::vector<WdbeQSysList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

