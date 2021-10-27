/**
	* \file WdbeQMtpRef1NSensitivity.h
	* API code for table TblWdbeQMtpRef1NSensitivity (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQMTPREF1NSENSITIVITY_H
#define WDBEQMTPREF1NSENSITIVITY_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMtpRef1NSensitivity
	*/
class WdbeQMtpRef1NSensitivity {

public:
	WdbeQMtpRef1NSensitivity(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQMtpRef1NSensitivity
	*/
class ListWdbeQMtpRef1NSensitivity {

public:
	ListWdbeQMtpRef1NSensitivity();
	ListWdbeQMtpRef1NSensitivity(const ListWdbeQMtpRef1NSensitivity& src);
	ListWdbeQMtpRef1NSensitivity& operator=(const ListWdbeQMtpRef1NSensitivity& src);
	~ListWdbeQMtpRef1NSensitivity();

	void clear();

public:
	std::vector<WdbeQMtpRef1NSensitivity*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
