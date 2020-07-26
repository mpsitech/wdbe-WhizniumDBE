/**
	* \file WdbeQModCor1NImbuf.h
	* API code for table TblWdbeQModCor1NImbuf (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

