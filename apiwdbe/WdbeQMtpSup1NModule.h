/**
	* \file WdbeQMtpSup1NModule.h
	* API code for table TblWdbeQMtpSup1NModule (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQMTPSUP1NMODULE_H
#define WDBEQMTPSUP1NMODULE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMtpSup1NModule
	*/
class WdbeQMtpSup1NModule {

public:
	WdbeQMtpSup1NModule(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQMtpSup1NModule
	*/
class ListWdbeQMtpSup1NModule {

public:
	ListWdbeQMtpSup1NModule();
	ListWdbeQMtpSup1NModule(const ListWdbeQMtpSup1NModule& src);
	ListWdbeQMtpSup1NModule& operator=(const ListWdbeQMtpSup1NModule& src);
	~ListWdbeQMtpSup1NModule();

	void clear();

public:
	std::vector<WdbeQMtpSup1NModule*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

