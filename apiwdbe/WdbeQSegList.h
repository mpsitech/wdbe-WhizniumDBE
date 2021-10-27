/**
	* \file WdbeQSegList.h
	* API code for table TblWdbeQSegList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQSEGLIST_H
#define WDBEQSEGLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQSegList
	*/
class WdbeQSegList {

public:
	WdbeQSegList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubPplRefWdbeMPipeline = "", const std::string stubSupRefWdbeMSegment = "", const std::string Infmt = "", const std::string Outfmt = "", const Sbecore::usmallint Latency = 0);

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubPplRefWdbeMPipeline;
	std::string stubSupRefWdbeMSegment;
	std::string Infmt;
	std::string Outfmt;
	Sbecore::usmallint Latency;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQSegList
	*/
class ListWdbeQSegList {

public:
	ListWdbeQSegList();
	ListWdbeQSegList(const ListWdbeQSegList& src);
	ListWdbeQSegList& operator=(const ListWdbeQSegList& src);
	~ListWdbeQSegList();

	void clear();

public:
	std::vector<WdbeQSegList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
