/**
	* \file WdbeQCvrHk1NModule.h
	* API code for table TblWdbeQCvrHk1NModule (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQCVRHK1NMODULE_H
#define WDBEQCVRHK1NMODULE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQCvrHk1NModule
	*/
class WdbeQCvrHk1NModule {

public:
	WdbeQCvrHk1NModule(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQCvrHk1NModule
	*/
class ListWdbeQCvrHk1NModule {

public:
	ListWdbeQCvrHk1NModule();
	ListWdbeQCvrHk1NModule(const ListWdbeQCvrHk1NModule& src);
	ListWdbeQCvrHk1NModule& operator=(const ListWdbeQCvrHk1NModule& src);
	~ListWdbeQCvrHk1NModule();

	void clear();

public:
	std::vector<WdbeQCvrHk1NModule*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

