/**
	* \file WdbeQVer1NComponent.h
	* API code for table TblWdbeQVer1NComponent (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

#ifndef WDBEQVER1NCOMPONENT_H
#define WDBEQVER1NCOMPONENT_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQVer1NComponent
	*/
class WdbeQVer1NComponent {

public:
	WdbeQVer1NComponent(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQVer1NComponent
	*/
class ListWdbeQVer1NComponent {

public:
	ListWdbeQVer1NComponent();
	ListWdbeQVer1NComponent(const ListWdbeQVer1NComponent& src);
	ListWdbeQVer1NComponent& operator=(const ListWdbeQVer1NComponent& src);
	~ListWdbeQVer1NComponent();

	void clear();

public:
	std::vector<WdbeQVer1NComponent*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
