/**
	* \file WdbeQModList.h
	* API code for table TblWdbeQModList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQMODLIST_H
#define WDBEQMODLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQModList
	*/
class WdbeQModList {

public:
	WdbeQModList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string srefHkIxVTbl = "", const std::string titHkIxVTbl = "", const std::string stubHkUref = "", const std::string stubSupRefWdbeMModule = "", const std::string stubTplRefWdbeMModule = "", const std::string Srefrule = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string srefHkIxVTbl;
	std::string titHkIxVTbl;
	std::string stubHkUref;
	std::string stubSupRefWdbeMModule;
	std::string stubTplRefWdbeMModule;
	std::string Srefrule;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQModList
	*/
class ListWdbeQModList {

public:
	ListWdbeQModList();
	ListWdbeQModList(const ListWdbeQModList& src);
	ListWdbeQModList& operator=(const ListWdbeQModList& src);
	~ListWdbeQModList();

	void clear();

public:
	std::vector<WdbeQModList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

