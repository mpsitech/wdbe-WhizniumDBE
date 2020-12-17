/**
	* \file WdbeQPrjPrj1NVersion.h
	* API code for table TblWdbeQPrjPrj1NVersion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 16 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPRJPRJ1NVERSION_H
#define WDBEQPRJPRJ1NVERSION_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPrjPrj1NVersion
	*/
class WdbeQPrjPrj1NVersion {

public:
	WdbeQPrjPrj1NVersion(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPrjPrj1NVersion
	*/
class ListWdbeQPrjPrj1NVersion {

public:
	ListWdbeQPrjPrj1NVersion();
	ListWdbeQPrjPrj1NVersion(const ListWdbeQPrjPrj1NVersion& src);
	ListWdbeQPrjPrj1NVersion& operator=(const ListWdbeQPrjPrj1NVersion& src);
	~ListWdbeQPrjPrj1NVersion();

	void clear();

public:
	std::vector<WdbeQPrjPrj1NVersion*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
