/**
	* \file WdbeQMtpTpl1NModule.h
	* API code for table TblWdbeQMtpTpl1NModule (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQMTPTPL1NMODULE_H
#define WDBEQMTPTPL1NMODULE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMtpTpl1NModule
	*/
class WdbeQMtpTpl1NModule {

public:
	WdbeQMtpTpl1NModule(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQMtpTpl1NModule
	*/
class ListWdbeQMtpTpl1NModule {

public:
	ListWdbeQMtpTpl1NModule();
	ListWdbeQMtpTpl1NModule(const ListWdbeQMtpTpl1NModule& src);
	ListWdbeQMtpTpl1NModule& operator=(const ListWdbeQMtpTpl1NModule& src);
	~ListWdbeQMtpTpl1NModule();

	void clear();

public:
	std::vector<WdbeQMtpTpl1NModule*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

