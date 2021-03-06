/**
	* \file WdbeQModCtrRef1NError.h
	* API code for table TblWdbeQModCtrRef1NError (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMODCTRREF1NERROR_H
#define WDBEQMODCTRREF1NERROR_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQModCtrRef1NError
	*/
class WdbeQModCtrRef1NError {

public:
	WdbeQModCtrRef1NError(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQModCtrRef1NError
	*/
class ListWdbeQModCtrRef1NError {

public:
	ListWdbeQModCtrRef1NError();
	ListWdbeQModCtrRef1NError(const ListWdbeQModCtrRef1NError& src);
	ListWdbeQModCtrRef1NError& operator=(const ListWdbeQModCtrRef1NError& src);
	~ListWdbeQModCtrRef1NError();

	void clear();

public:
	std::vector<WdbeQModCtrRef1NError*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
