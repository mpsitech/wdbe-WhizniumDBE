/**
	* \file WdbeQLibMNComponent.h
	* API code for table TblWdbeQLibMNComponent (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

#ifndef WDBEQLIBMNCOMPONENT_H
#define WDBEQLIBMNCOMPONENT_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQLibMNComponent
	*/
class WdbeQLibMNComponent {

public:
	WdbeQLibMNComponent(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQLibMNComponent
	*/
class ListWdbeQLibMNComponent {

public:
	ListWdbeQLibMNComponent();
	ListWdbeQLibMNComponent(const ListWdbeQLibMNComponent& src);
	ListWdbeQLibMNComponent& operator=(const ListWdbeQLibMNComponent& src);
	~ListWdbeQLibMNComponent();

	void clear();

public:
	std::vector<WdbeQLibMNComponent*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
