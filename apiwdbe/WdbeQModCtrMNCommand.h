/**
	* \file WdbeQModCtrMNCommand.h
	* API code for table TblWdbeQModCtrMNCommand (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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

