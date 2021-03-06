/**
	* \file WdbeQUsr1NSession.h
	* API code for table TblWdbeQUsr1NSession (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQUSR1NSESSION_H
#define WDBEQUSR1NSESSION_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQUsr1NSession
	*/
class WdbeQUsr1NSession {

public:
	WdbeQUsr1NSession(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQUsr1NSession
	*/
class ListWdbeQUsr1NSession {

public:
	ListWdbeQUsr1NSession();
	ListWdbeQUsr1NSession(const ListWdbeQUsr1NSession& src);
	ListWdbeQUsr1NSession& operator=(const ListWdbeQUsr1NSession& src);
	~ListWdbeQUsr1NSession();

	void clear();

public:
	std::vector<WdbeQUsr1NSession*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
