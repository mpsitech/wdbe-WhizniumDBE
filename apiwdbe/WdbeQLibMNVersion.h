/**
	* \file WdbeQLibMNVersion.h
	* API code for table TblWdbeQLibMNVersion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQLIBMNVERSION_H
#define WDBEQLIBMNVERSION_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQLibMNVersion
	*/
class WdbeQLibMNVersion {

public:
	WdbeQLibMNVersion(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQLibMNVersion
	*/
class ListWdbeQLibMNVersion {

public:
	ListWdbeQLibMNVersion();
	ListWdbeQLibMNVersion(const ListWdbeQLibMNVersion& src);
	ListWdbeQLibMNVersion& operator=(const ListWdbeQLibMNVersion& src);
	~ListWdbeQLibMNVersion();

	void clear();

public:
	std::vector<WdbeQLibMNVersion*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
