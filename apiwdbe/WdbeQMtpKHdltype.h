/**
	* \file WdbeQMtpKHdltype.h
	* API code for table TblWdbeQMtpKHdltype (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQMTPKHDLTYPE_H
#define WDBEQMTPKHDLTYPE_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMtpKHdltype
	*/
class WdbeQMtpKHdltype {

public:
	WdbeQMtpKHdltype(const Sbecore::uint jnum = 0, const std::string yesnoFixed = "", const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const std::string Title = "", const std::string Comment = "");

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
	* ListWdbeQMtpKHdltype
	*/
class ListWdbeQMtpKHdltype {

public:
	ListWdbeQMtpKHdltype();
	ListWdbeQMtpKHdltype(const ListWdbeQMtpKHdltype& src);
	ListWdbeQMtpKHdltype& operator=(const ListWdbeQMtpKHdltype& src);
	~ListWdbeQMtpKHdltype();

	void clear();

public:
	std::vector<WdbeQMtpKHdltype*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

