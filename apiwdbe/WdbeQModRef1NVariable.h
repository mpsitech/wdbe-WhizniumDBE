/**
	* \file WdbeQModRef1NVariable.h
	* API code for table TblWdbeQModRef1NVariable (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQMODREF1NVARIABLE_H
#define WDBEQMODREF1NVARIABLE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQModRef1NVariable
	*/
class WdbeQModRef1NVariable {

public:
	WdbeQModRef1NVariable(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQModRef1NVariable
	*/
class ListWdbeQModRef1NVariable {

public:
	ListWdbeQModRef1NVariable();
	ListWdbeQModRef1NVariable(const ListWdbeQModRef1NVariable& src);
	ListWdbeQModRef1NVariable& operator=(const ListWdbeQModRef1NVariable& src);
	~ListWdbeQModRef1NVariable();

	void clear();

public:
	std::vector<WdbeQModRef1NVariable*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
