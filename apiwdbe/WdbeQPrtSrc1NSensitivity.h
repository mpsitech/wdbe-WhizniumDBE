/**
	* \file WdbeQPrtSrc1NSensitivity.h
	* API code for table TblWdbeQPrtSrc1NSensitivity (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQPRTSRC1NSENSITIVITY_H
#define WDBEQPRTSRC1NSENSITIVITY_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPrtSrc1NSensitivity
	*/
class WdbeQPrtSrc1NSensitivity {

public:
	WdbeQPrtSrc1NSensitivity(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPrtSrc1NSensitivity
	*/
class ListWdbeQPrtSrc1NSensitivity {

public:
	ListWdbeQPrtSrc1NSensitivity();
	ListWdbeQPrtSrc1NSensitivity(const ListWdbeQPrtSrc1NSensitivity& src);
	ListWdbeQPrtSrc1NSensitivity& operator=(const ListWdbeQPrtSrc1NSensitivity& src);
	~ListWdbeQPrtSrc1NSensitivity();

	void clear();

public:
	std::vector<WdbeQPrtSrc1NSensitivity*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
