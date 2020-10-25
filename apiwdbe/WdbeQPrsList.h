/**
	* \file WdbeQPrsList.h
	* API code for table TblWdbeQPrsList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEQPRSLIST_H
#define WDBEQPRSLIST_H

#include <sbecore/Xmlio.h>

/**
	* WdbeQPrsList
	*/
class WdbeQPrsList {

public:
	WdbeQPrsList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string Title = "", const std::string Firstname = "", const std::string Lastname = "", const std::string srefIxVSex = "", const std::string titIxVSex = "", const std::string telVal = "", const std::string emlVal = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string Title;
	std::string Firstname;
	std::string Lastname;
	std::string srefIxVSex;
	std::string titIxVSex;
	std::string telVal;
	std::string emlVal;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWdbeQPrsList
	*/
class ListWdbeQPrsList {

public:
	ListWdbeQPrsList();
	ListWdbeQPrsList(const ListWdbeQPrsList& src);
	ListWdbeQPrsList& operator=(const ListWdbeQPrsList& src);
	~ListWdbeQPrsList();

	void clear();

public:
	std::vector<WdbeQPrsList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

