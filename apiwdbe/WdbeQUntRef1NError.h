/**
	* \file WdbeQUntRef1NError.h
	* API code for table TblWdbeQUntRef1NError (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQUNTREF1NERROR_H
#define WDBEQUNTREF1NERROR_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQUntRef1NError
	*/
class WdbeQUntRef1NError {

public:
	WdbeQUntRef1NError(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQUntRef1NError
	*/
class ListWdbeQUntRef1NError {

public:
	ListWdbeQUntRef1NError();
	ListWdbeQUntRef1NError(const ListWdbeQUntRef1NError& src);
	ListWdbeQUntRef1NError& operator=(const ListWdbeQUntRef1NError& src);
	~ListWdbeQUntRef1NError();

	void clear();

public:
	std::vector<WdbeQUntRef1NError*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

