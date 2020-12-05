/**
	* \file WdbeQSil1NBank.h
	* API code for table TblWdbeQSil1NBank (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQSIL1NBANK_H
#define WDBEQSIL1NBANK_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQSil1NBank
	*/
class WdbeQSil1NBank {

public:
	WdbeQSil1NBank(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQSil1NBank
	*/
class ListWdbeQSil1NBank {

public:
	ListWdbeQSil1NBank();
	ListWdbeQSil1NBank(const ListWdbeQSil1NBank& src);
	ListWdbeQSil1NBank& operator=(const ListWdbeQSil1NBank& src);
	~ListWdbeQSil1NBank();

	void clear();

public:
	std::vector<WdbeQSil1NBank*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

