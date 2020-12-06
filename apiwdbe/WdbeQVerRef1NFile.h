/**
	* \file WdbeQVerRef1NFile.h
	* API code for table TblWdbeQVerRef1NFile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQVERREF1NFILE_H
#define WDBEQVERREF1NFILE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQVerRef1NFile
	*/
class WdbeQVerRef1NFile {

public:
	WdbeQVerRef1NFile(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQVerRef1NFile
	*/
class ListWdbeQVerRef1NFile {

public:
	ListWdbeQVerRef1NFile();
	ListWdbeQVerRef1NFile(const ListWdbeQVerRef1NFile& src);
	ListWdbeQVerRef1NFile& operator=(const ListWdbeQVerRef1NFile& src);
	~ListWdbeQVerRef1NFile();

	void clear();

public:
	std::vector<WdbeQVerRef1NFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
