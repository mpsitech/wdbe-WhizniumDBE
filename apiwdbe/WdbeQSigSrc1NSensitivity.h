/**
	* \file WdbeQSigSrc1NSensitivity.h
	* API code for table TblWdbeQSigSrc1NSensitivity (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQSIGSRC1NSENSITIVITY_H
#define WDBEQSIGSRC1NSENSITIVITY_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQSigSrc1NSensitivity
	*/
class WdbeQSigSrc1NSensitivity {

public:
	WdbeQSigSrc1NSensitivity(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQSigSrc1NSensitivity
	*/
class ListWdbeQSigSrc1NSensitivity {

public:
	ListWdbeQSigSrc1NSensitivity();
	ListWdbeQSigSrc1NSensitivity(const ListWdbeQSigSrc1NSensitivity& src);
	ListWdbeQSigSrc1NSensitivity& operator=(const ListWdbeQSigSrc1NSensitivity& src);
	~ListWdbeQSigSrc1NSensitivity();

	void clear();

public:
	std::vector<WdbeQSigSrc1NSensitivity*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
