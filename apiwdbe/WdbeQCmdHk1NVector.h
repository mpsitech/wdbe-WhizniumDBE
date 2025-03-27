/**
	* \file WdbeQCmdHk1NVector.h
	* API code for table TblWdbeQCmdHk1NVector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 8 Jan 2025
  */
// IP header --- ABOVE

#ifndef WDBEQCMDHK1NVECTOR_H
#define WDBEQCMDHK1NVECTOR_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQCmdHk1NVector
	*/
class WdbeQCmdHk1NVector {

public:
	WdbeQCmdHk1NVector(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQCmdHk1NVector
	*/
class ListWdbeQCmdHk1NVector {

public:
	ListWdbeQCmdHk1NVector();
	ListWdbeQCmdHk1NVector(const ListWdbeQCmdHk1NVector& src);
	ListWdbeQCmdHk1NVector& operator=(const ListWdbeQCmdHk1NVector& src);
	~ListWdbeQCmdHk1NVector();

	void clear();

public:
	std::vector<WdbeQCmdHk1NVector*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
