/**
	* \file WdbeQCdcMNSignal.h
	* API code for table TblWdbeQCdcMNSignal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#ifndef WDBEQCDCMNSIGNAL_H
#define WDBEQCDCMNSIGNAL_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQCdcMNSignal
	*/
class WdbeQCdcMNSignal {

public:
	WdbeQCdcMNSignal(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string srefIxVDir = "", const std::string titIxVDir = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string srefIxVDir;
	std::string titIxVDir;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQCdcMNSignal
	*/
class ListWdbeQCdcMNSignal {

public:
	ListWdbeQCdcMNSignal();
	ListWdbeQCdcMNSignal(const ListWdbeQCdcMNSignal& src);
	ListWdbeQCdcMNSignal& operator=(const ListWdbeQCdcMNSignal& src);
	~ListWdbeQCdcMNSignal();

	void clear();

public:
	std::vector<WdbeQCdcMNSignal*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
