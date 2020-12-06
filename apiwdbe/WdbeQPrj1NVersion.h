/**
	* \file WdbeQPrj1NVersion.h
	* API code for table TblWdbeQPrj1NVersion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPRJ1NVERSION_H
#define WDBEQPRJ1NVERSION_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPrj1NVersion
	*/
class WdbeQPrj1NVersion {

public:
	WdbeQPrj1NVersion(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPrj1NVersion
	*/
class ListWdbeQPrj1NVersion {

public:
	ListWdbeQPrj1NVersion();
	ListWdbeQPrj1NVersion(const ListWdbeQPrj1NVersion& src);
	ListWdbeQPrj1NVersion& operator=(const ListWdbeQPrj1NVersion& src);
	~ListWdbeQPrj1NVersion();

	void clear();

public:
	std::vector<WdbeQPrj1NVersion*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
