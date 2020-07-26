/**
	* \file WdbeQSilFwd1NController.h
	* API code for table TblWdbeQSilFwd1NController (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQSILFWD1NCONTROLLER_H
#define WDBEQSILFWD1NCONTROLLER_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQSilFwd1NController
	*/
class WdbeQSilFwd1NController {

public:
	WdbeQSilFwd1NController(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQSilFwd1NController
	*/
class ListWdbeQSilFwd1NController {

public:
	ListWdbeQSilFwd1NController();
	ListWdbeQSilFwd1NController(const ListWdbeQSilFwd1NController& src);
	ListWdbeQSilFwd1NController& operator=(const ListWdbeQSilFwd1NController& src);
	~ListWdbeQSilFwd1NController();

	void clear();

public:
	std::vector<WdbeQSilFwd1NController*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

