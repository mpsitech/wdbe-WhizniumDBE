/**
	* \file WdbeQCpr1NCoreversion.h
	* API code for table TblWdbeQCpr1NCoreversion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQCPR1NCOREVERSION_H
#define WDBEQCPR1NCOREVERSION_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQCpr1NCoreversion
	*/
class WdbeQCpr1NCoreversion {

public:
	WdbeQCpr1NCoreversion(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQCpr1NCoreversion
	*/
class ListWdbeQCpr1NCoreversion {

public:
	ListWdbeQCpr1NCoreversion();
	ListWdbeQCpr1NCoreversion(const ListWdbeQCpr1NCoreversion& src);
	ListWdbeQCpr1NCoreversion& operator=(const ListWdbeQCpr1NCoreversion& src);
	~ListWdbeQCpr1NCoreversion();

	void clear();

public:
	std::vector<WdbeQCpr1NCoreversion*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

