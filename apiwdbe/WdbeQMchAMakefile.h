/**
	* \file WdbeQMchAMakefile.h
	* API code for table TblWdbeQMchAMakefile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQMCHAMAKEFILE_H
#define WDBEQMCHAMAKEFILE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMchAMakefile
	*/
class WdbeQMchAMakefile {

public:
	WdbeQMchAMakefile(const Sbecore::uint jnum = 0, const std::string x1SrefKTag = "", const std::string titX1SrefKTag = "", const std::string Val = "");

public:
	Sbecore::uint jnum;
	std::string x1SrefKTag;
	std::string titX1SrefKTag;
	std::string Val;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQMchAMakefile
	*/
class ListWdbeQMchAMakefile {

public:
	ListWdbeQMchAMakefile();
	ListWdbeQMchAMakefile(const ListWdbeQMchAMakefile& src);
	ListWdbeQMchAMakefile& operator=(const ListWdbeQMchAMakefile& src);
	~ListWdbeQMchAMakefile();

	void clear();

public:
	std::vector<WdbeQMchAMakefile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

