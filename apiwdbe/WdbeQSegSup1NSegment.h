/**
	* \file WdbeQSegSup1NSegment.h
	* API code for table TblWdbeQSegSup1NSegment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQSEGSUP1NSEGMENT_H
#define WDBEQSEGSUP1NSEGMENT_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQSegSup1NSegment
	*/
class WdbeQSegSup1NSegment {

public:
	WdbeQSegSup1NSegment(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQSegSup1NSegment
	*/
class ListWdbeQSegSup1NSegment {

public:
	ListWdbeQSegSup1NSegment();
	ListWdbeQSegSup1NSegment(const ListWdbeQSegSup1NSegment& src);
	ListWdbeQSegSup1NSegment& operator=(const ListWdbeQSegSup1NSegment& src);
	~ListWdbeQSegSup1NSegment();

	void clear();

public:
	std::vector<WdbeQSegSup1NSegment*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
