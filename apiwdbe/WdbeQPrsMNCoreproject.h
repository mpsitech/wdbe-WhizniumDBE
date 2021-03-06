/**
	* \file WdbeQPrsMNCoreproject.h
	* API code for table TblWdbeQPrsMNCoreproject (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPRSMNCOREPROJECT_H
#define WDBEQPRSMNCOREPROJECT_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPrsMNCoreproject
	*/
class WdbeQPrsMNCoreproject {

public:
	WdbeQPrsMNCoreproject(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string ftmX1Startd = "", const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string ftmX1Startd;
	std::string ftmX1Stopd;
	std::string srefKFunction;
	std::string titSrefKFunction;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPrsMNCoreproject
	*/
class ListWdbeQPrsMNCoreproject {

public:
	ListWdbeQPrsMNCoreproject();
	ListWdbeQPrsMNCoreproject(const ListWdbeQPrsMNCoreproject& src);
	ListWdbeQPrsMNCoreproject& operator=(const ListWdbeQPrsMNCoreproject& src);
	~ListWdbeQPrsMNCoreproject();

	void clear();

public:
	std::vector<WdbeQPrsMNCoreproject*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
