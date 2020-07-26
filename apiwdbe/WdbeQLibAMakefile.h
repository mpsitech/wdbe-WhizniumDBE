/**
	* \file WdbeQLibAMakefile.h
	* API code for table TblWdbeQLibAMakefile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQLIBAMAKEFILE_H
#define WDBEQLIBAMAKEFILE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQLibAMakefile
	*/
class WdbeQLibAMakefile {

public:
	WdbeQLibAMakefile(const Sbecore::uint jnum = 0, const std::string stubX1RefWdbeMMachine = "", const std::string x2SrefKTag = "", const std::string titX2SrefKTag = "", const std::string Val = "");

public:
	Sbecore::uint jnum;
	std::string stubX1RefWdbeMMachine;
	std::string x2SrefKTag;
	std::string titX2SrefKTag;
	std::string Val;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQLibAMakefile
	*/
class ListWdbeQLibAMakefile {

public:
	ListWdbeQLibAMakefile();
	ListWdbeQLibAMakefile(const ListWdbeQLibAMakefile& src);
	ListWdbeQLibAMakefile& operator=(const ListWdbeQLibAMakefile& src);
	~ListWdbeQLibAMakefile();

	void clear();

public:
	std::vector<WdbeQLibAMakefile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

