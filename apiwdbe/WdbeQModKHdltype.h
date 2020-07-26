/**
	* \file WdbeQModKHdltype.h
	* API code for table TblWdbeQModKHdltype (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQMODKHDLTYPE_H
#define WDBEQMODKHDLTYPE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQModKHdltype
	*/
class WdbeQModKHdltype {

public:
	WdbeQModKHdltype(const Sbecore::uint jnum = 0, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const std::string Title = "", const std::string Comment = "");

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
	* ListWdbeQModKHdltype
	*/
class ListWdbeQModKHdltype {

public:
	ListWdbeQModKHdltype();
	ListWdbeQModKHdltype(const ListWdbeQModKHdltype& src);
	ListWdbeQModKHdltype& operator=(const ListWdbeQModKHdltype& src);
	~ListWdbeQModKHdltype();

	void clear();

public:
	std::vector<WdbeQModKHdltype*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

