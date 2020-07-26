/**
	* \file WdbeQLibMNVersion.h
	* API code for table TblWdbeQLibMNVersion (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

