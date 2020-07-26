/**
	* \file WdbeQMod1NProcess.h
	* API code for table TblWdbeQMod1NProcess (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQMOD1NPROCESS_H
#define WDBEQMOD1NPROCESS_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMod1NProcess
	*/
class WdbeQMod1NProcess {

public:
	WdbeQMod1NProcess(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQMod1NProcess
	*/
class ListWdbeQMod1NProcess {

public:
	ListWdbeQMod1NProcess();
	ListWdbeQMod1NProcess(const ListWdbeQMod1NProcess& src);
	ListWdbeQMod1NProcess& operator=(const ListWdbeQMod1NProcess& src);
	~ListWdbeQMod1NProcess();

	void clear();

public:
	std::vector<WdbeQMod1NProcess*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

