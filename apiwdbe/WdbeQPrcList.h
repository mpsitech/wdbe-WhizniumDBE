/**
	* \file WdbeQPrcList.h
	* API code for table TblWdbeQPrcList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQPRCLIST_H
#define WDBEQPRCLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPrcList
	*/
class WdbeQPrcList {

public:
	WdbeQPrcList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string stubRefWdbeMModule = "", const std::string yesnoFalling = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string stubRefWdbeMModule;
	std::string yesnoFalling;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPrcList
	*/
class ListWdbeQPrcList {

public:
	ListWdbeQPrcList();
	ListWdbeQPrcList(const ListWdbeQPrcList& src);
	ListWdbeQPrcList& operator=(const ListWdbeQPrcList& src);
	~ListWdbeQPrcList();

	void clear();

public:
	std::vector<WdbeQPrcList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

