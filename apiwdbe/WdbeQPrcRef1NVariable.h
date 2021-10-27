/**
	* \file WdbeQPrcRef1NVariable.h
	* API code for table TblWdbeQPrcRef1NVariable (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQPRCREF1NVARIABLE_H
#define WDBEQPRCREF1NVARIABLE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPrcRef1NVariable
	*/
class WdbeQPrcRef1NVariable {

public:
	WdbeQPrcRef1NVariable(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPrcRef1NVariable
	*/
class ListWdbeQPrcRef1NVariable {

public:
	ListWdbeQPrcRef1NVariable();
	ListWdbeQPrcRef1NVariable(const ListWdbeQPrcRef1NVariable& src);
	ListWdbeQPrcRef1NVariable& operator=(const ListWdbeQPrcRef1NVariable& src);
	~ListWdbeQPrcRef1NVariable();

	void clear();

public:
	std::vector<WdbeQPrcRef1NVariable*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
