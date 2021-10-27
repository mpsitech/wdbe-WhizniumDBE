/**
	* \file WdbeQSilRef1NSignal.h
	* API code for table TblWdbeQSilRef1NSignal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2021
  */
// IP header --- ABOVE

#ifndef WDBEQSILREF1NSIGNAL_H
#define WDBEQSILREF1NSIGNAL_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQSilRef1NSignal
	*/
class WdbeQSilRef1NSignal {

public:
	WdbeQSilRef1NSignal(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQSilRef1NSignal
	*/
class ListWdbeQSilRef1NSignal {

public:
	ListWdbeQSilRef1NSignal();
	ListWdbeQSilRef1NSignal(const ListWdbeQSilRef1NSignal& src);
	ListWdbeQSilRef1NSignal& operator=(const ListWdbeQSilRef1NSignal& src);
	~ListWdbeQSilRef1NSignal();

	void clear();

public:
	std::vector<WdbeQSilRef1NSignal*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
