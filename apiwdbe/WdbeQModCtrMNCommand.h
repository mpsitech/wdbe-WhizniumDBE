/**
	* \file WdbeQModCtrMNCommand.h
	* API code for table TblWdbeQModCtrMNCommand (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQMODCTRMNCOMMAND_H
#define WDBEQMODCTRMNCOMMAND_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQModCtrMNCommand
	*/
class WdbeQModCtrMNCommand {

public:
	WdbeQModCtrMNCommand(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string stubIvrRefWdbeMSignal = "", const std::string stubRvrRefWdbeMSignal = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string stubIvrRefWdbeMSignal;
	std::string stubRvrRefWdbeMSignal;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQModCtrMNCommand
	*/
class ListWdbeQModCtrMNCommand {

public:
	ListWdbeQModCtrMNCommand();
	ListWdbeQModCtrMNCommand(const ListWdbeQModCtrMNCommand& src);
	ListWdbeQModCtrMNCommand& operator=(const ListWdbeQModCtrMNCommand& src);
	~ListWdbeQModCtrMNCommand();

	void clear();

public:
	std::vector<WdbeQModCtrMNCommand*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

