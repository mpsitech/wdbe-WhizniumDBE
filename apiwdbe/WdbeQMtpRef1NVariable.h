/**
	* \file WdbeQMtpRef1NVariable.h
	* API code for table TblWdbeQMtpRef1NVariable (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEQMTPREF1NVARIABLE_H
#define WDBEQMTPREF1NVARIABLE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMtpRef1NVariable
	*/
class WdbeQMtpRef1NVariable {

public:
	WdbeQMtpRef1NVariable(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQMtpRef1NVariable
	*/
class ListWdbeQMtpRef1NVariable {

public:
	ListWdbeQMtpRef1NVariable();
	ListWdbeQMtpRef1NVariable(const ListWdbeQMtpRef1NVariable& src);
	ListWdbeQMtpRef1NVariable& operator=(const ListWdbeQMtpRef1NVariable& src);
	~ListWdbeQMtpRef1NVariable();

	void clear();

public:
	std::vector<WdbeQMtpRef1NVariable*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
