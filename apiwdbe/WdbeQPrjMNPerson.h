/**
	* \file WdbeQPrjMNPerson.h
	* API code for table TblWdbeQPrjMNPerson (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPRJMNPERSON_H
#define WDBEQPRJMNPERSON_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPrjMNPerson
	*/
class WdbeQPrjMNPerson {

public:
	WdbeQPrjMNPerson(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string ftmX1Startd = "", const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");

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
	* ListWdbeQPrjMNPerson
	*/
class ListWdbeQPrjMNPerson {

public:
	ListWdbeQPrjMNPerson();
	ListWdbeQPrjMNPerson(const ListWdbeQPrjMNPerson& src);
	ListWdbeQPrjMNPerson& operator=(const ListWdbeQPrjMNPerson& src);
	~ListWdbeQPrjMNPerson();

	void clear();

public:
	std::vector<WdbeQPrjMNPerson*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

