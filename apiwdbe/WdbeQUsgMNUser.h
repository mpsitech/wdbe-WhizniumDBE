/**
	* \file WdbeQUsgMNUser.h
	* API code for table TblWdbeQUsgMNUser (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQUSGMNUSER_H
#define WDBEQUSGMNUSER_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQUsgMNUser
	*/
class WdbeQUsgMNUser {

public:
	WdbeQUsgMNUser(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string srefIxWdbeVUserlevel = "", const std::string titIxWdbeVUserlevel = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string srefIxWdbeVUserlevel;
	std::string titIxWdbeVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQUsgMNUser
	*/
class ListWdbeQUsgMNUser {

public:
	ListWdbeQUsgMNUser();
	ListWdbeQUsgMNUser(const ListWdbeQUsgMNUser& src);
	ListWdbeQUsgMNUser& operator=(const ListWdbeQUsgMNUser& src);
	~ListWdbeQUsgMNUser();

	void clear();

public:
	std::vector<WdbeQUsgMNUser*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
