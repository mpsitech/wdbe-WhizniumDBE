/**
	* \file WdbeQUnt1NBank.h
	* API code for table TblWdbeQUnt1NBank (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQUNT1NBANK_H
#define WDBEQUNT1NBANK_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQUnt1NBank
	*/
class WdbeQUnt1NBank {

public:
	WdbeQUnt1NBank(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQUnt1NBank
	*/
class ListWdbeQUnt1NBank {

public:
	ListWdbeQUnt1NBank();
	ListWdbeQUnt1NBank(const ListWdbeQUnt1NBank& src);
	ListWdbeQUnt1NBank& operator=(const ListWdbeQUnt1NBank& src);
	~ListWdbeQUnt1NBank();

	void clear();

public:
	std::vector<WdbeQUnt1NBank*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

