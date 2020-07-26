/**
	* \file WdbeQModMdl1NGeneric.h
	* API code for table TblWdbeQModMdl1NGeneric (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQMODMDL1NGENERIC_H
#define WDBEQMODMDL1NGENERIC_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQModMdl1NGeneric
	*/
class WdbeQModMdl1NGeneric {

public:
	WdbeQModMdl1NGeneric(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQModMdl1NGeneric
	*/
class ListWdbeQModMdl1NGeneric {

public:
	ListWdbeQModMdl1NGeneric();
	ListWdbeQModMdl1NGeneric(const ListWdbeQModMdl1NGeneric& src);
	ListWdbeQModMdl1NGeneric& operator=(const ListWdbeQModMdl1NGeneric& src);
	~ListWdbeQModMdl1NGeneric();

	void clear();

public:
	std::vector<WdbeQModMdl1NGeneric*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

