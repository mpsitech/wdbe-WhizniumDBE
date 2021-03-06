/**
	* \file WdbeQMtpKParKey.h
	* API code for table TblWdbeQMtpKParKey (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMTPKPARKEY_H
#define WDBEQMTPKPARKEY_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMtpKParKey
	*/
class WdbeQMtpKParKey {

public:
	WdbeQMtpKParKey(const Sbecore::uint jnum = 0, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::uint jnum;
	std::string yesnoFixed;
	std::string sref;
	std::string Avail;
	std::string Implied;
	std::string Title;
	std::string Comment;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQMtpKParKey
	*/
class ListWdbeQMtpKParKey {

public:
	ListWdbeQMtpKParKey();
	ListWdbeQMtpKParKey(const ListWdbeQMtpKParKey& src);
	ListWdbeQMtpKParKey& operator=(const ListWdbeQMtpKParKey& src);
	~ListWdbeQMtpKParKey();

	void clear();

public:
	std::vector<WdbeQMtpKParKey*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
