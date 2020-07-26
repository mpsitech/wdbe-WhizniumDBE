/**
	* \file WdbeQFilList.h
	* API code for table TblWdbeQFilList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQFILLIST_H
#define WDBEQFILLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQFilList
	*/
class WdbeQFilList {

public:
	WdbeQFilList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string Filename = "", const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const std::string stubRefUref = "", const std::string osrefKContent = "", const std::string titOsrefKContent = "", const std::string srefKMimetype = "", const std::string titSrefKMimetype = "", const Sbecore::usmallint Size = 0);

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string Filename;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	std::string stubRefUref;
	std::string osrefKContent;
	std::string titOsrefKContent;
	std::string srefKMimetype;
	std::string titSrefKMimetype;
	Sbecore::usmallint Size;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQFilList
	*/
class ListWdbeQFilList {

public:
	ListWdbeQFilList();
	ListWdbeQFilList(const ListWdbeQFilList& src);
	ListWdbeQFilList& operator=(const ListWdbeQFilList& src);
	~ListWdbeQFilList();

	void clear();

public:
	std::vector<WdbeQFilList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

