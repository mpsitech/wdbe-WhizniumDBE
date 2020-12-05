/**
	* \file WdbeQModSup1NModule.h
	* API code for table TblWdbeQModSup1NModule (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMODSUP1NMODULE_H
#define WDBEQMODSUP1NMODULE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQModSup1NModule
	*/
class WdbeQModSup1NModule {

public:
	WdbeQModSup1NModule(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQModSup1NModule
	*/
class ListWdbeQModSup1NModule {

public:
	ListWdbeQModSup1NModule();
	ListWdbeQModSup1NModule(const ListWdbeQModSup1NModule& src);
	ListWdbeQModSup1NModule& operator=(const ListWdbeQModSup1NModule& src);
	~ListWdbeQModSup1NModule();

	void clear();

public:
	std::vector<WdbeQModSup1NModule*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

