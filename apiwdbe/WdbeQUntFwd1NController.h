/**
	* \file WdbeQUntFwd1NController.h
	* API code for table TblWdbeQUntFwd1NController (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQUNTFWD1NCONTROLLER_H
#define WDBEQUNTFWD1NCONTROLLER_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQUntFwd1NController
	*/
class WdbeQUntFwd1NController {

public:
	WdbeQUntFwd1NController(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQUntFwd1NController
	*/
class ListWdbeQUntFwd1NController {

public:
	ListWdbeQUntFwd1NController();
	ListWdbeQUntFwd1NController(const ListWdbeQUntFwd1NController& src);
	ListWdbeQUntFwd1NController& operator=(const ListWdbeQUntFwd1NController& src);
	~ListWdbeQUntFwd1NController();

	void clear();

public:
	std::vector<WdbeQUntFwd1NController*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

