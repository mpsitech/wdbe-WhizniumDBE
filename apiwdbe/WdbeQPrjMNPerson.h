/**
	* \file WdbeQPrjMNPerson.h
	* API code for table TblWdbeQPrjMNPerson (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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

