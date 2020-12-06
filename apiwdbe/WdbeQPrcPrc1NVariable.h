/**
	* \file WdbeQPrcPrc1NVariable.h
	* API code for table TblWdbeQPrcPrc1NVariable (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPRCPRC1NVARIABLE_H
#define WDBEQPRCPRC1NVARIABLE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPrcPrc1NVariable
	*/
class WdbeQPrcPrc1NVariable {

public:
	WdbeQPrcPrc1NVariable(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPrcPrc1NVariable
	*/
class ListWdbeQPrcPrc1NVariable {

public:
	ListWdbeQPrcPrc1NVariable();
	ListWdbeQPrcPrc1NVariable(const ListWdbeQPrcPrc1NVariable& src);
	ListWdbeQPrcPrc1NVariable& operator=(const ListWdbeQPrcPrc1NVariable& src);
	~ListWdbeQPrcPrc1NVariable();

	void clear();

public:
	std::vector<WdbeQPrcPrc1NVariable*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
