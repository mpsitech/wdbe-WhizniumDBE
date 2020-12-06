/**
	* \file WdbeQSilRef1NCommand.h
	* API code for table TblWdbeQSilRef1NCommand (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQSILREF1NCOMMAND_H
#define WDBEQSILREF1NCOMMAND_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQSilRef1NCommand
	*/
class WdbeQSilRef1NCommand {

public:
	WdbeQSilRef1NCommand(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQSilRef1NCommand
	*/
class ListWdbeQSilRef1NCommand {

public:
	ListWdbeQSilRef1NCommand();
	ListWdbeQSilRef1NCommand(const ListWdbeQSilRef1NCommand& src);
	ListWdbeQSilRef1NCommand& operator=(const ListWdbeQSilRef1NCommand& src);
	~ListWdbeQSilRef1NCommand();

	void clear();

public:
	std::vector<WdbeQSilRef1NCommand*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
