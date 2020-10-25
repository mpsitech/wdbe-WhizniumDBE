/**
	* \file WdbeQCprMNPerson.h
	* API code for table TblWdbeQCprMNPerson (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQCPRMNPERSON_H
#define WDBEQCPRMNPERSON_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQCprMNPerson
	*/
class WdbeQCprMNPerson {

public:
	WdbeQCprMNPerson(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string ftmX1Startd = "", const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");

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
	* ListWdbeQCprMNPerson
	*/
class ListWdbeQCprMNPerson {

public:
	ListWdbeQCprMNPerson();
	ListWdbeQCprMNPerson(const ListWdbeQCprMNPerson& src);
	ListWdbeQCprMNPerson& operator=(const ListWdbeQCprMNPerson& src);
	~ListWdbeQCprMNPerson();

	void clear();

public:
	std::vector<WdbeQCprMNPerson*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

