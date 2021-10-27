/**
	* \file WdbeQModCtdMNModule.h
	* API code for table TblWdbeQModCtdMNModule (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBEQMODCTDMNMODULE_H
#define WDBEQMODCTDMNMODULE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQModCtdMNModule
	*/
class WdbeQModCtdMNModule {

public:
	WdbeQModCtdMNModule(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string srefKFunction;
	std::string titSrefKFunction;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQModCtdMNModule
	*/
class ListWdbeQModCtdMNModule {

public:
	ListWdbeQModCtdMNModule();
	ListWdbeQModCtdMNModule(const ListWdbeQModCtdMNModule& src);
	ListWdbeQModCtdMNModule& operator=(const ListWdbeQModCtdMNModule& src);
	~ListWdbeQModCtdMNModule();

	void clear();

public:
	std::vector<WdbeQModCtdMNModule*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
