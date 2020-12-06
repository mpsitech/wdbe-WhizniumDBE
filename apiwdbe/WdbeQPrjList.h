/**
	* \file WdbeQPrjList.h
	* API code for table TblWdbeQPrjList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPRJLIST_H
#define WDBEQPRJLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPrjList
	*/
class WdbeQPrjList {

public:
	WdbeQPrjList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string Short = "", const std::string Title = "", const std::string stubRefWdbeMVersion = "", const std::string yesnoEasy = "", const std::string Giturl = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string Short;
	std::string Title;
	std::string stubRefWdbeMVersion;
	std::string yesnoEasy;
	std::string Giturl;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPrjList
	*/
class ListWdbeQPrjList {

public:
	ListWdbeQPrjList();
	ListWdbeQPrjList(const ListWdbeQPrjList& src);
	ListWdbeQPrjList& operator=(const ListWdbeQPrjList& src);
	~ListWdbeQPrjList();

	void clear();

public:
	std::vector<WdbeQPrjList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
