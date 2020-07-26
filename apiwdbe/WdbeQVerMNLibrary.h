/**
	* \file WdbeQVerMNLibrary.h
	* API code for table TblWdbeQVerMNLibrary (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQVERMNLIBRARY_H
#define WDBEQVERMNLIBRARY_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQVerMNLibrary
	*/
class WdbeQVerMNLibrary {

public:
	WdbeQVerMNLibrary(const Sbecore::uint jnum = 0, const std::string stubMref = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQVerMNLibrary
	*/
class ListWdbeQVerMNLibrary {

public:
	ListWdbeQVerMNLibrary();
	ListWdbeQVerMNLibrary(const ListWdbeQVerMNLibrary& src);
	ListWdbeQVerMNLibrary& operator=(const ListWdbeQVerMNLibrary& src);
	~ListWdbeQVerMNLibrary();

	void clear();

public:
	std::vector<WdbeQVerMNLibrary*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

