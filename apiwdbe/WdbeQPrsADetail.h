/**
	* \file WdbeQPrsADetail.h
	* API code for table TblWdbeQPrsADetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQPRSADETAIL_H
#define WDBEQPRSADETAIL_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPrsADetail
	*/
class WdbeQPrsADetail {

public:
	WdbeQPrsADetail(const Sbecore::uint jnum = 0, const std::string x1SrefKType = "", const std::string titX1SrefKType = "", const std::string Val = "");

public:
	Sbecore::uint jnum;
	std::string x1SrefKType;
	std::string titX1SrefKType;
	std::string Val;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPrsADetail
	*/
class ListWdbeQPrsADetail {

public:
	ListWdbeQPrsADetail();
	ListWdbeQPrsADetail(const ListWdbeQPrsADetail& src);
	ListWdbeQPrsADetail& operator=(const ListWdbeQPrsADetail& src);
	~ListWdbeQPrsADetail();

	void clear();

public:
	std::vector<WdbeQPrsADetail*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
