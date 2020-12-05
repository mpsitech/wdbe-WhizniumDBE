/**
	* \file WdbeQCmdMNController.h
	* API code for table TblWdbeQCmdMNController (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQCMDMNCONTROLLER_H
#define WDBEQCMDMNCONTROLLER_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQCmdMNController
	*/
class WdbeQCmdMNController {

public:
	WdbeQCmdMNController(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string stubIvrRefWdbeMSignal = "", const std::string stubRvrRefWdbeMSignal = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string stubIvrRefWdbeMSignal;
	std::string stubRvrRefWdbeMSignal;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQCmdMNController
	*/
class ListWdbeQCmdMNController {

public:
	ListWdbeQCmdMNController();
	ListWdbeQCmdMNController(const ListWdbeQCmdMNController& src);
	ListWdbeQCmdMNController& operator=(const ListWdbeQCmdMNController& src);
	~ListWdbeQCmdMNController();

	void clear();

public:
	std::vector<WdbeQCmdMNController*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

