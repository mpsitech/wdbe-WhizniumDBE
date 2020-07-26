/**
	* \file WdbeQModMdl1NSignal.h
	* API code for table TblWdbeQModMdl1NSignal (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQMODMDL1NSIGNAL_H
#define WDBEQMODMDL1NSIGNAL_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQModMdl1NSignal
	*/
class WdbeQModMdl1NSignal {

public:
	WdbeQModMdl1NSignal(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQModMdl1NSignal
	*/
class ListWdbeQModMdl1NSignal {

public:
	ListWdbeQModMdl1NSignal();
	ListWdbeQModMdl1NSignal(const ListWdbeQModMdl1NSignal& src);
	ListWdbeQModMdl1NSignal& operator=(const ListWdbeQModMdl1NSignal& src);
	~ListWdbeQModMdl1NSignal();

	void clear();

public:
	std::vector<WdbeQModMdl1NSignal*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

