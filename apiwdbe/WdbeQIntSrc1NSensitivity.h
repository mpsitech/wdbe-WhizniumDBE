/**
	* \file WdbeQIntSrc1NSensitivity.h
	* API code for table TblWdbeQIntSrc1NSensitivity (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQINTSRC1NSENSITIVITY_H
#define WDBEQINTSRC1NSENSITIVITY_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQIntSrc1NSensitivity
	*/
class WdbeQIntSrc1NSensitivity {

public:
	WdbeQIntSrc1NSensitivity(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQIntSrc1NSensitivity
	*/
class ListWdbeQIntSrc1NSensitivity {

public:
	ListWdbeQIntSrc1NSensitivity();
	ListWdbeQIntSrc1NSensitivity(const ListWdbeQIntSrc1NSensitivity& src);
	ListWdbeQIntSrc1NSensitivity& operator=(const ListWdbeQIntSrc1NSensitivity& src);
	~ListWdbeQIntSrc1NSensitivity();

	void clear();

public:
	std::vector<WdbeQIntSrc1NSensitivity*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
