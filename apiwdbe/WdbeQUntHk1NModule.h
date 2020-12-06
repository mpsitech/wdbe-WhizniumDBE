/**
	* \file WdbeQUntHk1NModule.h
	* API code for table TblWdbeQUntHk1NModule (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQUNTHK1NMODULE_H
#define WDBEQUNTHK1NMODULE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQUntHk1NModule
	*/
class WdbeQUntHk1NModule {

public:
	WdbeQUntHk1NModule(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQUntHk1NModule
	*/
class ListWdbeQUntHk1NModule {

public:
	ListWdbeQUntHk1NModule();
	ListWdbeQUntHk1NModule(const ListWdbeQUntHk1NModule& src);
	ListWdbeQUntHk1NModule& operator=(const ListWdbeQUntHk1NModule& src);
	~ListWdbeQUntHk1NModule();

	void clear();

public:
	std::vector<WdbeQUntHk1NModule*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
