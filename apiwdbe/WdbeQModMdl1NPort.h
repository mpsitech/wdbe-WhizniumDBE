/**
	* \file WdbeQModMdl1NPort.h
	* API code for table TblWdbeQModMdl1NPort (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQMODMDL1NPORT_H
#define WDBEQMODMDL1NPORT_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQModMdl1NPort
	*/
class WdbeQModMdl1NPort {

public:
	WdbeQModMdl1NPort(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQModMdl1NPort
	*/
class ListWdbeQModMdl1NPort {

public:
	ListWdbeQModMdl1NPort();
	ListWdbeQModMdl1NPort(const ListWdbeQModMdl1NPort& src);
	ListWdbeQModMdl1NPort& operator=(const ListWdbeQModMdl1NPort& src);
	~ListWdbeQModMdl1NPort();

	void clear();

public:
	std::vector<WdbeQModMdl1NPort*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

