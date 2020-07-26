/**
	* \file WdbeQModCtrRef1NCommand.h
	* API code for table TblWdbeQModCtrRef1NCommand (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQMODCTRREF1NCOMMAND_H
#define WDBEQMODCTRREF1NCOMMAND_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQModCtrRef1NCommand
	*/
class WdbeQModCtrRef1NCommand {

public:
	WdbeQModCtrRef1NCommand(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQModCtrRef1NCommand
	*/
class ListWdbeQModCtrRef1NCommand {

public:
	ListWdbeQModCtrRef1NCommand();
	ListWdbeQModCtrRef1NCommand(const ListWdbeQModCtrRef1NCommand& src);
	ListWdbeQModCtrRef1NCommand& operator=(const ListWdbeQModCtrRef1NCommand& src);
	~ListWdbeQModCtrRef1NCommand();

	void clear();

public:
	std::vector<WdbeQModCtrRef1NCommand*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

