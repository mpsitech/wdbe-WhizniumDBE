/**
	* \file WdbeQMtpList.h
	* API code for table TblWdbeQMtpList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEQMTPLIST_H
#define WDBEQMTPLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQMtpList
	*/
class WdbeQMtpList {

public:
	WdbeQMtpList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string srefIxVBasetype = "", const std::string titIxVBasetype = "", const std::string srefHkIxVTbl = "", const std::string titHkIxVTbl = "", const std::string stubHkUref = "", const std::string Srefrule = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string srefIxVBasetype;
	std::string titIxVBasetype;
	std::string srefHkIxVTbl;
	std::string titHkIxVTbl;
	std::string stubHkUref;
	std::string Srefrule;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQMtpList
	*/
class ListWdbeQMtpList {

public:
	ListWdbeQMtpList();
	ListWdbeQMtpList(const ListWdbeQMtpList& src);
	ListWdbeQMtpList& operator=(const ListWdbeQMtpList& src);
	~ListWdbeQMtpList();

	void clear();

public:
	std::vector<WdbeQMtpList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

