/**
	* \file WdbeQMod1NCdc.h
	* API code for table TblWdbeQMod1NCdc (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#ifndef WDBEQMOD1NCDC_H
#define WDBEQMOD1NCDC_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMod1NCdc
	*/
class WdbeQMod1NCdc {

public:
	WdbeQMod1NCdc(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQMod1NCdc
	*/
class ListWdbeQMod1NCdc {

public:
	ListWdbeQMod1NCdc();
	ListWdbeQMod1NCdc(const ListWdbeQMod1NCdc& src);
	ListWdbeQMod1NCdc& operator=(const ListWdbeQMod1NCdc& src);
	~ListWdbeQMod1NCdc();

	void clear();

public:
	std::vector<WdbeQMod1NCdc*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
