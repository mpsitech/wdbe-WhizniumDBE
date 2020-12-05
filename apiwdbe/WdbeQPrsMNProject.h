/**
	* \file WdbeQPrsMNProject.h
	* API code for table TblWdbeQPrsMNProject (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPRSMNPROJECT_H
#define WDBEQPRSMNPROJECT_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPrsMNProject
	*/
class WdbeQPrsMNProject {

public:
	WdbeQPrsMNProject(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string ftmX1Startd = "", const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");

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
	* ListWdbeQPrsMNProject
	*/
class ListWdbeQPrsMNProject {

public:
	ListWdbeQPrsMNProject();
	ListWdbeQPrsMNProject(const ListWdbeQPrsMNProject& src);
	ListWdbeQPrsMNProject& operator=(const ListWdbeQPrsMNProject& src);
	~ListWdbeQPrsMNProject();

	void clear();

public:
	std::vector<WdbeQPrsMNProject*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

