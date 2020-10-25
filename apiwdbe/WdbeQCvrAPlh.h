/**
	* \file WdbeQCvrAPlh.h
	* API code for table TblWdbeQCvrAPlh (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQCVRAPLH_H
#define WDBEQCVRAPLH_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQCvrAPlh
	*/
class WdbeQCvrAPlh {

public:
	WdbeQCvrAPlh(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Comment = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Comment;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQCvrAPlh
	*/
class ListWdbeQCvrAPlh {

public:
	ListWdbeQCvrAPlh();
	ListWdbeQCvrAPlh(const ListWdbeQCvrAPlh& src);
	ListWdbeQCvrAPlh& operator=(const ListWdbeQCvrAPlh& src);
	~ListWdbeQCvrAPlh();

	void clear();

public:
	std::vector<WdbeQCvrAPlh*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

