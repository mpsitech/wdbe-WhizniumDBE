/**
	* \file WdbeQUsrMNUsergroup.h
	* API code for table TblWdbeQUsrMNUsergroup (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQUSRMNUSERGROUP_H
#define WDBEQUSRMNUSERGROUP_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQUsrMNUsergroup
	*/
class WdbeQUsrMNUsergroup {

public:
	WdbeQUsrMNUsergroup(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string srefIxWdbeVUserlevel = "", const std::string titIxWdbeVUserlevel = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string srefIxWdbeVUserlevel;
	std::string titIxWdbeVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQUsrMNUsergroup
	*/
class ListWdbeQUsrMNUsergroup {

public:
	ListWdbeQUsrMNUsergroup();
	ListWdbeQUsrMNUsergroup(const ListWdbeQUsrMNUsergroup& src);
	ListWdbeQUsrMNUsergroup& operator=(const ListWdbeQUsrMNUsergroup& src);
	~ListWdbeQUsrMNUsergroup();

	void clear();

public:
	std::vector<WdbeQUsrMNUsergroup*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
