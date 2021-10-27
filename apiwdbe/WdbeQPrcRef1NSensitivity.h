/**
	* \file WdbeQPrcRef1NSensitivity.h
	* API code for table TblWdbeQPrcRef1NSensitivity (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQPRCREF1NSENSITIVITY_H
#define WDBEQPRCREF1NSENSITIVITY_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPrcRef1NSensitivity
	*/
class WdbeQPrcRef1NSensitivity {

public:
	WdbeQPrcRef1NSensitivity(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPrcRef1NSensitivity
	*/
class ListWdbeQPrcRef1NSensitivity {

public:
	ListWdbeQPrcRef1NSensitivity();
	ListWdbeQPrcRef1NSensitivity(const ListWdbeQPrcRef1NSensitivity& src);
	ListWdbeQPrcRef1NSensitivity& operator=(const ListWdbeQPrcRef1NSensitivity& src);
	~ListWdbeQPrcRef1NSensitivity();

	void clear();

public:
	std::vector<WdbeQPrcRef1NSensitivity*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
