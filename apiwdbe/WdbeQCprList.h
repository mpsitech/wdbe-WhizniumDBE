/**
	* \file WdbeQCprList.h
	* API code for table TblWdbeQCprList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQCPRLIST_H
#define WDBEQCPRLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQCprList
	*/
class WdbeQCprList {

public:
	WdbeQCprList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string sref = "", const std::string Title = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubRefWdbeMCoreversion = "", const std::string Giturl = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string sref;
	std::string Title;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubRefWdbeMCoreversion;
	std::string Giturl;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQCprList
	*/
class ListWdbeQCprList {

public:
	ListWdbeQCprList();
	ListWdbeQCprList(const ListWdbeQCprList& src);
	ListWdbeQCprList& operator=(const ListWdbeQCprList& src);
	~ListWdbeQCprList();

	void clear();

public:
	std::vector<WdbeQCprList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
