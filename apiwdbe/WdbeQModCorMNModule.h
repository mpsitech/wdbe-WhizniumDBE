/**
	* \file WdbeQModCorMNModule.h
	* API code for table TblWdbeQModCorMNModule (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 4 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBEQMODCORMNMODULE_H
#define WDBEQMODCORMNMODULE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQModCorMNModule
	*/
class WdbeQModCorMNModule {

public:
	WdbeQModCorMNModule(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string srefKFunction;
	std::string titSrefKFunction;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQModCorMNModule
	*/
class ListWdbeQModCorMNModule {

public:
	ListWdbeQModCorMNModule();
	ListWdbeQModCorMNModule(const ListWdbeQModCorMNModule& src);
	ListWdbeQModCorMNModule& operator=(const ListWdbeQModCorMNModule& src);
	~ListWdbeQModCorMNModule();

	void clear();

public:
	std::vector<WdbeQModCorMNModule*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
