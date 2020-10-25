/**
	* \file WdbeQUntRef1NCommand.h
	* API code for table TblWdbeQUntRef1NCommand (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQUNTREF1NCOMMAND_H
#define WDBEQUNTREF1NCOMMAND_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQUntRef1NCommand
	*/
class WdbeQUntRef1NCommand {

public:
	WdbeQUntRef1NCommand(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQUntRef1NCommand
	*/
class ListWdbeQUntRef1NCommand {

public:
	ListWdbeQUntRef1NCommand();
	ListWdbeQUntRef1NCommand(const ListWdbeQUntRef1NCommand& src);
	ListWdbeQUntRef1NCommand& operator=(const ListWdbeQUntRef1NCommand& src);
	~ListWdbeQUntRef1NCommand();

	void clear();

public:
	std::vector<WdbeQUntRef1NCommand*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

