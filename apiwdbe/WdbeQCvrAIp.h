/**
	* \file WdbeQCvrAIp.h
	* API code for table TblWdbeQCvrAIp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBEQCVRAIP_H
#define WDBEQCVRAIP_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQCvrAIp
	*/
class WdbeQCvrAIp {

public:
	WdbeQCvrAIp(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxVTagtype = "", const std::string titIxVTagtype = "", const std::string Comment = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxVTagtype;
	std::string titIxVTagtype;
	std::string Comment;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQCvrAIp
	*/
class ListWdbeQCvrAIp {

public:
	ListWdbeQCvrAIp();
	ListWdbeQCvrAIp(const ListWdbeQCvrAIp& src);
	ListWdbeQCvrAIp& operator=(const ListWdbeQCvrAIp& src);
	~ListWdbeQCvrAIp();

	void clear();

public:
	std::vector<WdbeQCvrAIp*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

