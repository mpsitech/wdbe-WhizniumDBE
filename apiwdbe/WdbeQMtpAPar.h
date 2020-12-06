/**
	* \file WdbeQMtpAPar.h
	* API code for table TblWdbeQMtpAPar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMTPAPAR_H
#define WDBEQMTPAPAR_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMtpAPar
	*/
class WdbeQMtpAPar {

public:
	WdbeQMtpAPar(const Sbecore::uint jnum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");

public:
	Sbecore::uint jnum;
	std::string x1SrefKKey;
	std::string titX1SrefKKey;
	std::string Val;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQMtpAPar
	*/
class ListWdbeQMtpAPar {

public:
	ListWdbeQMtpAPar();
	ListWdbeQMtpAPar(const ListWdbeQMtpAPar& src);
	ListWdbeQMtpAPar& operator=(const ListWdbeQMtpAPar& src);
	~ListWdbeQMtpAPar();

	void clear();

public:
	std::vector<WdbeQMtpAPar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
