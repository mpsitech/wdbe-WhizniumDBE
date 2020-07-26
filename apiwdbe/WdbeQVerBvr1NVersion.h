/**
	* \file WdbeQVerBvr1NVersion.h
	* API code for table TblWdbeQVerBvr1NVersion (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQVERBVR1NVERSION_H
#define WDBEQVERBVR1NVERSION_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQVerBvr1NVersion
	*/
class WdbeQVerBvr1NVersion {

public:
	WdbeQVerBvr1NVersion(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQVerBvr1NVersion
	*/
class ListWdbeQVerBvr1NVersion {

public:
	ListWdbeQVerBvr1NVersion();
	ListWdbeQVerBvr1NVersion(const ListWdbeQVerBvr1NVersion& src);
	ListWdbeQVerBvr1NVersion& operator=(const ListWdbeQVerBvr1NVersion& src);
	~ListWdbeQVerBvr1NVersion();

	void clear();

public:
	std::vector<WdbeQVerBvr1NVersion*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

