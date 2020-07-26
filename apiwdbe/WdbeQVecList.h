/**
	* \file WdbeQVecList.h
	* API code for table TblWdbeQVecList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQVECLIST_H
#define WDBEQVECLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQVecList
	*/
class WdbeQVecList {

public:
	WdbeQVecList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string srefHkIxVTbl = "", const std::string titHkIxVTbl = "", const std::string stubHkUref = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string srefHkIxVTbl;
	std::string titHkIxVTbl;
	std::string stubHkUref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQVecList
	*/
class ListWdbeQVecList {

public:
	ListWdbeQVecList();
	ListWdbeQVecList(const ListWdbeQVecList& src);
	ListWdbeQVecList& operator=(const ListWdbeQVecList& src);
	~ListWdbeQVecList();

	void clear();

public:
	std::vector<WdbeQVecList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

