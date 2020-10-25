/**
	* \file WdbeQPrcKHdltype.h
	* API code for table TblWdbeQPrcKHdltype (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQPRCKHDLTYPE_H
#define WDBEQPRCKHDLTYPE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPrcKHdltype
	*/
class WdbeQPrcKHdltype {

public:
	WdbeQPrcKHdltype(const Sbecore::uint jnum = 0, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::uint jnum;
	std::string yesnoFixed;
	std::string sref;
	std::string Avail;
	std::string Implied;
	std::string Title;
	std::string Comment;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPrcKHdltype
	*/
class ListWdbeQPrcKHdltype {

public:
	ListWdbeQPrcKHdltype();
	ListWdbeQPrcKHdltype(const ListWdbeQPrcKHdltype& src);
	ListWdbeQPrcKHdltype& operator=(const ListWdbeQPrcKHdltype& src);
	~ListWdbeQPrcKHdltype();

	void clear();

public:
	std::vector<WdbeQPrcKHdltype*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

