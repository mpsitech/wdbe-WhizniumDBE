/**
	* \file WdbeQRlsList.h
	* API code for table TblWdbeQRlsList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQRLSLIST_H
#define WDBEQRLSLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQRlsList
	*/
class WdbeQRlsList {

public:
	WdbeQRlsList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string stubRefWdbeMVersion = "", const std::string stubRefWdbeMMachine = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string stubRefWdbeMVersion;
	std::string stubRefWdbeMMachine;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQRlsList
	*/
class ListWdbeQRlsList {

public:
	ListWdbeQRlsList();
	ListWdbeQRlsList(const ListWdbeQRlsList& src);
	ListWdbeQRlsList& operator=(const ListWdbeQRlsList& src);
	~ListWdbeQRlsList();

	void clear();

public:
	std::vector<WdbeQRlsList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

