/**
	* \file WdbeQMtpRef1NFile.h
	* API code for table TblWdbeQMtpRef1NFile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMTPREF1NFILE_H
#define WDBEQMTPREF1NFILE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMtpRef1NFile
	*/
class WdbeQMtpRef1NFile {

public:
	WdbeQMtpRef1NFile(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQMtpRef1NFile
	*/
class ListWdbeQMtpRef1NFile {

public:
	ListWdbeQMtpRef1NFile();
	ListWdbeQMtpRef1NFile(const ListWdbeQMtpRef1NFile& src);
	ListWdbeQMtpRef1NFile& operator=(const ListWdbeQMtpRef1NFile& src);
	~ListWdbeQMtpRef1NFile();

	void clear();

public:
	std::vector<WdbeQMtpRef1NFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
