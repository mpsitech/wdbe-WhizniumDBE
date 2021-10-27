/**
	* \file WdbeQPphMNModule.h
	* API code for table TblWdbeQPphMNModule (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 13 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBEQPPHMNMODULE_H
#define WDBEQPPHMNMODULE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPphMNModule
	*/
class WdbeQPphMNModule {

public:
	WdbeQPphMNModule(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPphMNModule
	*/
class ListWdbeQPphMNModule {

public:
	ListWdbeQPphMNModule();
	ListWdbeQPphMNModule(const ListWdbeQPphMNModule& src);
	ListWdbeQPphMNModule& operator=(const ListWdbeQPphMNModule& src);
	~ListWdbeQPphMNModule();

	void clear();

public:
	std::vector<WdbeQPphMNModule*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
