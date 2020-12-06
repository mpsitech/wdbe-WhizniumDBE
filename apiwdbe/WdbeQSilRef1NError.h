/**
	* \file WdbeQSilRef1NError.h
	* API code for table TblWdbeQSilRef1NError (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQSILREF1NERROR_H
#define WDBEQSILREF1NERROR_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQSilRef1NError
	*/
class WdbeQSilRef1NError {

public:
	WdbeQSilRef1NError(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQSilRef1NError
	*/
class ListWdbeQSilRef1NError {

public:
	ListWdbeQSilRef1NError();
	ListWdbeQSilRef1NError(const ListWdbeQSilRef1NError& src);
	ListWdbeQSilRef1NError& operator=(const ListWdbeQSilRef1NError& src);
	~ListWdbeQSilRef1NError();

	void clear();

public:
	std::vector<WdbeQSilRef1NError*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
