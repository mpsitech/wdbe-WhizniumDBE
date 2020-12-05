/**
	* \file WdbeQSilHk1NModule.h
	* API code for table TblWdbeQSilHk1NModule (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQSILHK1NMODULE_H
#define WDBEQSILHK1NMODULE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQSilHk1NModule
	*/
class WdbeQSilHk1NModule {

public:
	WdbeQSilHk1NModule(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQSilHk1NModule
	*/
class ListWdbeQSilHk1NModule {

public:
	ListWdbeQSilHk1NModule();
	ListWdbeQSilHk1NModule(const ListWdbeQSilHk1NModule& src);
	ListWdbeQSilHk1NModule& operator=(const ListWdbeQSilHk1NModule& src);
	~ListWdbeQSilHk1NModule();

	void clear();

public:
	std::vector<WdbeQSilHk1NModule*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

