/**
	* \file WdbeQMtpAPar.h
	* API code for table TblWdbeQMtpAPar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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

