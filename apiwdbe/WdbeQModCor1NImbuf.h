/**
	* \file WdbeQModCor1NImbuf.h
	* API code for table TblWdbeQModCor1NImbuf (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMODCOR1NIMBUF_H
#define WDBEQMODCOR1NIMBUF_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQModCor1NImbuf
	*/
class WdbeQModCor1NImbuf {

public:
	WdbeQModCor1NImbuf(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQModCor1NImbuf
	*/
class ListWdbeQModCor1NImbuf {

public:
	ListWdbeQModCor1NImbuf();
	ListWdbeQModCor1NImbuf(const ListWdbeQModCor1NImbuf& src);
	ListWdbeQModCor1NImbuf& operator=(const ListWdbeQModCor1NImbuf& src);
	~ListWdbeQModCor1NImbuf();

	void clear();

public:
	std::vector<WdbeQModCor1NImbuf*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
