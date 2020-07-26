/**
	* \file WdbeQUsgMNUser.h
	* API code for table TblWdbeQUsgMNUser (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

