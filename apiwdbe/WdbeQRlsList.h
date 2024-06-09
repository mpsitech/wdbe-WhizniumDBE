/**
	* \file WdbeQRlsList.h
	* API code for table TblWdbeQRlsList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQRLSLIST_H
#define WDBEQRLSLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQRlsList
	*/
class WdbeQRlsList {

public:
	WdbeQRlsList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubRefWdbeMComponent = "", const std::string stubRefWdbeMMachine = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubRefWdbeMComponent;
	std::string stubRefWdbeMMachine;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQRlsList
	*/
class ListWdbeQRlsList {

public:
	ListWdbeQRlsList();
	ListWdbeQRlsList(const ListWdbeQRlsList& src);
	ListWdbeQRlsList& operator=(const ListWdbeQRlsList& src);
	~ListWdbeQRlsList();

	void clear();

public:
	std::vector<WdbeQRlsList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
