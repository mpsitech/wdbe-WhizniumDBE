/**
	* \file WdbeQPplPpl1NSegment.h
	* API code for table TblWdbeQPplPpl1NSegment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQPPLPPL1NSEGMENT_H
#define WDBEQPPLPPL1NSEGMENT_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPplPpl1NSegment
	*/
class WdbeQPplPpl1NSegment {

public:
	WdbeQPplPpl1NSegment(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPplPpl1NSegment
	*/
class ListWdbeQPplPpl1NSegment {

public:
	ListWdbeQPplPpl1NSegment();
	ListWdbeQPplPpl1NSegment(const ListWdbeQPplPpl1NSegment& src);
	ListWdbeQPplPpl1NSegment& operator=(const ListWdbeQPplPpl1NSegment& src);
	~ListWdbeQPplPpl1NSegment();

	void clear();

public:
	std::vector<WdbeQPplPpl1NSegment*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
