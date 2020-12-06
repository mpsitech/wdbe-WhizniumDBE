/**
	* \file WdbeQVitList.h
	* API code for table TblWdbeQVitList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQVITLIST_H
#define WDBEQVITLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQVitList
	*/
class WdbeQVitList {

public:
	WdbeQVitList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Title = "", const std::string stubVecRefWdbeMVector = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Title;
	std::string stubVecRefWdbeMVector;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQVitList
	*/
class ListWdbeQVitList {

public:
	ListWdbeQVitList();
	ListWdbeQVitList(const ListWdbeQVitList& src);
	ListWdbeQVitList& operator=(const ListWdbeQVitList& src);
	~ListWdbeQVitList();

	void clear();

public:
	std::vector<WdbeQVitList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
