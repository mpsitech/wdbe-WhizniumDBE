/**
	* \file WdbeQUsrList.h
	* API code for table TblWdbeQUsrList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQUSRLIST_H
#define WDBEQUSRLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQUsrList
	*/
class WdbeQUsrList {

public:
	WdbeQUsrList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string stubRefWdbeMPerson = "", const std::string sref = "", const std::string stubRefWdbeMUsergroup = "", const std::string srefIxVState = "", const std::string titIxVState = "", const std::string srefIxWdbeVLocale = "", const std::string titIxWdbeVLocale = "", const std::string srefIxWdbeVUserlevel = "", const std::string titIxWdbeVUserlevel = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string stubRefWdbeMPerson;
	std::string sref;
	std::string stubRefWdbeMUsergroup;
	std::string srefIxVState;
	std::string titIxVState;
	std::string srefIxWdbeVLocale;
	std::string titIxWdbeVLocale;
	std::string srefIxWdbeVUserlevel;
	std::string titIxWdbeVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQUsrList
	*/
class ListWdbeQUsrList {

public:
	ListWdbeQUsrList();
	ListWdbeQUsrList(const ListWdbeQUsrList& src);
	ListWdbeQUsrList& operator=(const ListWdbeQUsrList& src);
	~ListWdbeQUsrList();

	void clear();

public:
	std::vector<WdbeQUsrList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

