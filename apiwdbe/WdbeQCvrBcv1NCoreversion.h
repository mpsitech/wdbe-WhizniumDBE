/**
	* \file WdbeQCvrBcv1NCoreversion.h
	* API code for table TblWdbeQCvrBcv1NCoreversion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQCVRBCV1NCOREVERSION_H
#define WDBEQCVRBCV1NCOREVERSION_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQCvrBcv1NCoreversion
	*/
class WdbeQCvrBcv1NCoreversion {

public:
	WdbeQCvrBcv1NCoreversion(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQCvrBcv1NCoreversion
	*/
class ListWdbeQCvrBcv1NCoreversion {

public:
	ListWdbeQCvrBcv1NCoreversion();
	ListWdbeQCvrBcv1NCoreversion(const ListWdbeQCvrBcv1NCoreversion& src);
	ListWdbeQCvrBcv1NCoreversion& operator=(const ListWdbeQCvrBcv1NCoreversion& src);
	~ListWdbeQCvrBcv1NCoreversion();

	void clear();

public:
	std::vector<WdbeQCvrBcv1NCoreversion*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
