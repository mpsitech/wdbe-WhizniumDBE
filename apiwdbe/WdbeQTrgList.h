/**
	* \file WdbeQTrgList.h
	* API code for table TblWdbeQTrgList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQTRGLIST_H
#define WDBEQTRGLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQTrgList
	*/
class WdbeQTrgList {

public:
	WdbeQTrgList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubSysRefWdbeMSystem = "", const std::string stubRefWdbeMUnit = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubSysRefWdbeMSystem;
	std::string stubRefWdbeMUnit;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQTrgList
	*/
class ListWdbeQTrgList {

public:
	ListWdbeQTrgList();
	ListWdbeQTrgList(const ListWdbeQTrgList& src);
	ListWdbeQTrgList& operator=(const ListWdbeQTrgList& src);
	~ListWdbeQTrgList();

	void clear();

public:
	std::vector<WdbeQTrgList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

