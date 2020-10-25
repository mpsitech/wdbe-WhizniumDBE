/**
	* \file WdbeQErrList.h
	* API code for table TblWdbeQErrList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQERRLIST_H
#define WDBEQERRLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQErrList
	*/
class WdbeQErrList {

public:
	WdbeQErrList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Fullsref = "", const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const std::string stubRefUref = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Fullsref;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	std::string stubRefUref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQErrList
	*/
class ListWdbeQErrList {

public:
	ListWdbeQErrList();
	ListWdbeQErrList(const ListWdbeQErrList& src);
	ListWdbeQErrList& operator=(const ListWdbeQErrList& src);
	~ListWdbeQErrList();

	void clear();

public:
	std::vector<WdbeQErrList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

