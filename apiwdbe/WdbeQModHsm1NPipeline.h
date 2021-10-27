/**
	* \file WdbeQModHsm1NPipeline.h
	* API code for table TblWdbeQModHsm1NPipeline (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQMODHSM1NPIPELINE_H
#define WDBEQMODHSM1NPIPELINE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQModHsm1NPipeline
	*/
class WdbeQModHsm1NPipeline {

public:
	WdbeQModHsm1NPipeline(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQModHsm1NPipeline
	*/
class ListWdbeQModHsm1NPipeline {

public:
	ListWdbeQModHsm1NPipeline();
	ListWdbeQModHsm1NPipeline(const ListWdbeQModHsm1NPipeline& src);
	ListWdbeQModHsm1NPipeline& operator=(const ListWdbeQModHsm1NPipeline& src);
	~ListWdbeQModHsm1NPipeline();

	void clear();

public:
	std::vector<WdbeQModHsm1NPipeline*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
