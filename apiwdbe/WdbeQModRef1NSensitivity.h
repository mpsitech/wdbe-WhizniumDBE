/**
	* \file WdbeQModRef1NSensitivity.h
	* API code for table TblWdbeQModRef1NSensitivity (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQMODREF1NSENSITIVITY_H
#define WDBEQMODREF1NSENSITIVITY_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQModRef1NSensitivity
	*/
class WdbeQModRef1NSensitivity {

public:
	WdbeQModRef1NSensitivity(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQModRef1NSensitivity
	*/
class ListWdbeQModRef1NSensitivity {

public:
	ListWdbeQModRef1NSensitivity();
	ListWdbeQModRef1NSensitivity(const ListWdbeQModRef1NSensitivity& src);
	ListWdbeQModRef1NSensitivity& operator=(const ListWdbeQModRef1NSensitivity& src);
	~ListWdbeQModRef1NSensitivity();

	void clear();

public:
	std::vector<WdbeQModRef1NSensitivity*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
